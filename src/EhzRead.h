/*
 * EhzRead.h
 *
 *  Created on: 28.10.2010
 *      Author: kleinmat
 */

#ifndef EHZREAD_H_
#define EHZREAD_H_

#include <termios.h>
#include <string.h>
#include <iostream>

#include <fcntl.h>

class EhzRead {

public:
	std::string getRawDatagramm(void);
	EhzRead(char* device);
	virtual ~EhzRead();
private:
	struct termios tio;
	int tty_fd;

};

#endif /* EHZREAD_H_ */
