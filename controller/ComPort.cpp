//
// Created by Alex Kotov on 08/04/2024.
//

#include "ComPort.h"

ComPort::ComPort(char *port) {
    this->port = port;
}

int ComPort::init() {
    this->fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        std::cerr << "Failed to open COM port" << std::endl;
        return 1;
    }

    struct termios options;
    tcgetattr(fd, &options);
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_cflag = CS8 | CLOCAL | CREAD;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 0;
    options.c_cc[VTIME] = 10;

    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);

    if (tcsetattr(fd, TCSANOW, &options) != 0) {
        std::cerr << "Failed to set COM port options" << std::endl;
        close(this->fd);
        return 1;
    }
}

int ComPort::write_message(char *message) {
    ssize_t bytesWritten;
    bytesWritten = write(this->fd, message, strlen(message));
    if (bytesWritten == -1) {
        std::cerr << "Failed to write to COM port" << std::endl;
        close(fd);
        return 1;
    }
    std::cout << "Message sended";
    return 0;
}

char* ComPort::read_message() {
    char *buffer = (char*) malloc(256);
    ssize_t bytesRead;
    bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        std::cerr << "Failed to read from COM port" << std::endl;
        close(fd);
    } else{
        std::cout << "Ok!";
        return buffer;
    }

}