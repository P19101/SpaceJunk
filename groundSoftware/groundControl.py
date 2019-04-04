import serial

main_comm = serial.Serial()
main_comm.baudrate = 19200
main_comm.port = 'COM8'


command_list = {"H" : "Help command: 'H' or 'Help' - Executes the help function which list all the available commands",
                "E" : "Exit command: 'E' or 'Exit' - Exits the program",
                "S" : "Status command: 'S' or 'Status' - Gives the current status of the terminal connection.\r\n\t\t\t\t  If the terminal could not be opened at the start of the program,\r\n\t\t\t\t  then it will have to be opened manually using the 'Open' command"}


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
            main_comm.write(bytes.fromhex('0A')) 
            #main_comm.write(bytes.fromhex())
            #main_comm.write(bytes.fromhex('0f'))
            msg_length = main_comm.read(2)
            if(msg_length != b''):
                opcode = main_comm.read()
                response = main_comm.read(int(msg_length)-3)
                print(msg_length)
                print(opcode)
            else:
                print("no msg returned")
                
            '''Set up the address bit detection stuff and/or send a few characters of "wake" sorta and then send the message length after ACK back
                After ACK of message size, send all the data and look for ACK bytes or ERROR Bytes. Allow the system to brace for all the data to
                keep up because no interrupts. could also use interrupts realistically. 
            '''
        


































if __name__ == "__main__":
    main()