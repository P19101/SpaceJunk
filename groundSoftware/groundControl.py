import serial

main_comm = serial.Serial()
main_comm.baudrate = 9600
main_comm.port = 'COM8'



def main():
    print("hello world")
    print(main_comm)



































if __name__ == "__main__":
    main()