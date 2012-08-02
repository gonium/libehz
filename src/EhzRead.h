/**
* This file is part of libehz.
*
* (c) Mathias Dalheimer <md@gonium.net>, 2010
* (c) Matthias Klein <name.surename @ itwm.fraunhofer.de>, 2010
*
* libehz is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* libehz is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with libehz. If not, see <http://www.gnu.org/licenses/>.
*
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
