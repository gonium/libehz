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
  tio.c_cflag=CS7|CREAD|CLOCAL;           // 7n1, see termios.h for more information
  tio.c_lflag=0;
  tio.c_cc[VMIN]=1;
  tio.c_cc[VTIME]=5;

  tty_fd=open(argv[1], O_RDWR | O_NONBLOCK);      
  cfsetospeed(&tio,B9600);            // 9600 baud
  cfsetispeed(&tio,B9600);            // 9600 baud

  tcsetattr(tty_fd,TCSANOW,&tio);
  while (true)
  {
    if (read(tty_fd,&c,1)>0) // if new data is available on the serial port, print it out
      std::cout << &c;
  }

  close(tty_fd);
}
