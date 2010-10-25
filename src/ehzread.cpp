/**
 * This file is part of libehz.
 *
 * (c) Mathias Dalheimer <md@gonium.net>, 2010
 *
 * libehz is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libehz is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libehz. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <termios.h>

int main(int argc,char** argv) {
  struct termios tio;
  int tty_fd;
  fd_set rdset;

  unsigned char c='X';

  std::cout << "Please start with " << argv[0] << 
    " /dev/ttyS1 (for example)" << std::endl;

  memset(&tio,0,sizeof(tio));
  tio.c_iflag=0;
  tio.c_oflag=0;
  tio.c_cflag=CS7|CREAD|CLOCAL;			// 7n1, see termios.h for more information
  tio.c_lflag=0;
  tio.c_cc[VMIN]=1;
  tio.c_cc[VTIME]=5;

  tty_fd=open(argv[1], O_RDWR);			//  | O_NONBLOCK);
  cfsetospeed(&tio,B9600);			// 9600 baud
  cfsetispeed(&tio,B9600);			// 9600 baud

  tcsetattr(tty_fd,TCSANOW,&tio);
  while (true) {
    if (read(tty_fd,&c,1)>0) 
      // if new data is available on the serial port, print it out
      std::cout << &c;
  }

  close(tty_fd);
}
