import serial

# Configure the serial port
arduino_port = 'COM3'  # Replace with the correct serial port of your Arduino
baud_rate = 9600

# Open the serial connection
ser = serial.Serial(arduino_port, baud_rate, timeout=1)

# Wait for user input
while True:

    user_input = input("Enter 'y' to blink fast or 'n' to blink slow: ")

    # Send command to the Arduino
    if user_input == 'y':
        ser.write(b'1')  # Send '1' to the Arduino to indicate fast blinking
    elif user_input == 'n':
        ser.write(b'2')  # Send '2' to the Arduino to indicate slow blinking
    elif user_input == 'q':
        break

# Close the serial connection
ser.close()
