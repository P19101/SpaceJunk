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
                "T" : "Test command: 'T' or 'Test' - Sends a test message to the sattilte and reads back a response to test the comms."}

'''
'''
def send_cmd(opcode='00', size=0x03, payload=b''):
    #send the wake byte
    main_comm.write(bytes.fromhex('AA'))
    #read back ACK
    ack_byte = main_comm.read() 
    #print(ack_byte)
    if(ack_byte.hex() != 'aa'):
        print("BAD ACK")
        return -1
    else:
        print("ACK returned")
    #write the message length
    main_comm.write(struct.pack('<H',size))
    #write the opcode
    main_comm.write(bytes.fromhex(opcode))
    #write the payload bytes
    main_comm.write(payload)


def read_rsp():    
    main_comm.timeout = 3
    msg_length = struct.unpack('H', main_comm.read(2))
    return main_comm.read(msg_length[0])
    
    
    
def main():
    exit_check = 'n'
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
                print("comm port successfully opened")
            except:
                print("comm port failed to open")
        elif(answer.upper() == 'T' or answer.upper() == "TEST"):
            send_cmd('00', 0x03)
            payload = read_rsp()
            print(struct.unpack('<HB',payload))
        elif(answer.upper() == 'R' or answer.upper() == "READ"):
            # TODO: make a function which creates and pack payloads according to predefined argumnets for each command. 
            send_cmd('02', 0x04, b'\x03')
            payload = read_rsp()
            decoder = struct.unpack('HBB',payload)         
            print("messageLength: ", decoder[0],", opcode: ", decoder[1],", sensorStatus: ", "OFF" if decoder[2] == 0 else "ON")
            
           
        







if __name__ == "__main__":
    main()