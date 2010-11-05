/*
 * EhzRead.cpp
 *
 *  Created on: 28.10.2010
 *      Author: kleinmat
 */

#include "EhzRead.h"
#include <stdio.h>

EhzRead::EhzRead(char* device) {

	memset(&tio, 0, sizeof(tio));
	tio.c_iflag = 0;
	tio.c_oflag = 0;
	tio.c_cflag = CS7 | PARENB | CREAD | CLOCAL; // 7n1, see termios.h for more information
	tio.c_lflag = 0;
	tio.c_cc[VMIN] = 1;
	tio.c_cc[VTIME] = 5;

	tty_fd = open(device, O_RDWR | O_NOCTTY); 		//O_NONBLOCK);

	//tty_fd = open(device, O_RDONLY);
	cfsetospeed(&tio, B9600); // 9600 baud
	cfsetispeed(&tio, B9600); // 9600 baud

	tcsetattr(tty_fd, TCSANOW, &tio);

}

EhzRead::~EhzRead() {
	close(tty_fd);
}

std::string EhzRead::getRawDatagramm(void) {

	std::string datagramm = "";
	char c = 'X';

	bool slash = false;
	bool exclamation = false;

	while (!slash || !exclamation) {
		if (read(tty_fd, &c, 1) > 0) {
			// if new data is available on the serial port do sth with it

			if (c == '/') // check for beginning
				slash = true;
			if (slash) { // safe only when beginning sing was already seen
				datagramm += c;
			}
			if ((slash == true) && (c == '!')) { // check for ending
				exclamation = true;
				datagramm += "\n";
				//std::cout << text << std::endl;
			}
		}
	}

	return datagramm;
}
