import serial
import time
import struct

main_comm = serial.Serial()
main_comm.baudrate = 19200
main_comm.port = 'COM8'
main_comm.timeout = 2



command_list = {"H" : "Help command: 'H' or 'Help' - Executes the help function which list all the available commands",
                "E" : "Exit command: 'E' or 'Exit' - Exits the program",
                "S" : "Status command: 'S' or 'Status' - Gives the current status of the terminal connection.\r\n\t\t\t\t  If the terminal could not be opened at the start of the program,\r\n\t\t\t\t  then it will have to be opened manually using the 'Open' command",
                "O" : "Open command: 'O' or 'Open' - Opens the main comm port with default settings currently.",
                "T" : "Test command: 'T' or 'Test' - Sends a test message to the sattilte and reads back a response to test the comms.",
                "R" : "Read sensor command: 'R' or 'Read' - Read one of the deployment sensors to test the connection with it."}
                
message_lengths = {"TEST_LENGTH" : 0x03,
                   "READ_LENGTH" : 0x04}
                   
opcodes = {"TEST_OPCODE" : '00',
           "READ_OPCODE" : '02'}

'''
'''
def send_cmd(opcode='00', size=0x03, payload=b''):
    #send the wake byte
    main_comm.write(bytes.fromhex('AA'))
    #read back ACK
    ack_byte = main_comm.read() 
    #print(ack_byte)
    msg_length = struct.pack('<H',(size))
    op_hex = bytes.fromhex(opcode)
    try:
        if(ack_byte.hex() != 'aa'):
            print(ack_byte.hex())
            print("BAD ACK")
            return -1
        else:
            print("ACK returned")
            #write the message length
            main_comm.write(msg_length)
            #write the opcode
            main_comm.write(op_hex)
            #write the payload bytes
            main_comm.write(payload)
    except:
        print("Failure to send message.")
        
    


def read_rsp():    
    main_comm.timeout = 3
    msg_length = struct.unpack('H', main_comm.read(2))
    return main_comm.read(msg_length[0])
    
    
    
def main():
    exit_check = 'n'
    comm_open = False
    while(exit_check == 'n'):
        answer = input("Enter a Command>")
        if(answer.upper() == 'E' or answer.upper() == "EXIT"):
            exit_check = 'y'
        elif(answer.upper() == 'H' or answer.upper() == "HELP"):
            print("List of all commands currently available:\r\n")
            for key in command_list.keys():
                print(command_list[key])
        elif(answer.upper() == 'S' or answer.upper() == "STATUS"):
            print(main_comm)
        elif(answer.upper() == 'O' or answer.upper() == "OPEN"):
            try:
                main_comm.open()
                comm_open = True
                print("comm port successfully opened")
            except:
                print("comm port failed to open")
                comm_open = False
        elif(answer.upper() == 'T' or answer.upper() == "TEST"):
            if(comm_open == True):
                send_cmd(opcodes["TEST_OPCODE"], message_lengths["TEST_LENGTH"])
                payload = read_rsp()
                print(struct.unpack('<HB',payload))
            else:   
                print("Please open the communication port before sending commands.")           
        elif(answer.upper() == 'R' or answer.upper() == "READ"):
            if(comm_open == True):
                # TODO: make a function which creates and pack payloads according to predefined argumnets for each command. 
                sens_num = input("Enter the number of the sensor to read:")
                if(sens_num == '1' or sens_num == '2' or sens_num == '3' or sens_num == '4'):
                    send_cmd(opcodes["READ_OPCODE"], message_lengths["READ_LENGTH"], struct.pack("<B", int(sens_num)))
                    payload = read_rsp()
                    decoder = struct.unpack('HBB',payload)         
                    print("messageLength: ", decoder[0],", opcode: ", decoder[1],", sensorStatus: ", "OFF" if decoder[2] == 0 else "ON")
                else:
                    print("Sensor num must be between 1 and 4.")
            else:
                print("Please open the communication port before sending commands.")           
           
        







if __name__ == "__main__":
    main()