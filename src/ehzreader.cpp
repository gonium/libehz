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

#include <iostream>
#include "EhzRead.h"
#include "EhzParse.h"
#include "EhzDatagram.h"
#include <string>

int main(int argc, char** argv) {

	std::cout << "Please start with " << argv[0] << " /dev/ttyS1 (for example)"
			<< std::endl;

	EhzRead ehzreader(argv[1]);
	EhzParse ehzparser;


	EhzDatagram neu;


	ehzparser.setDatagramm(ehzreader.getRawDatagramm());
	neu = ehzparser.getDatagramm();

	std::cout << neu.toString();

	double avg_watts = neu.getL2CurrentWatts();
	u_int64_t count = 1;

	while (true) {


		ehzparser.setDatagramm(ehzreader.getRawDatagramm());
		//ehzparser.printRawDatagramm();

		EhzDatagram alt = neu;
		neu = ehzparser.getDatagramm();

		std::cout << neu.toString();

//		std::cout << "ALT" << std::endl;
//		std::cout << alt.toString();
//
//		std::cout << difftime(neu.getTimeStamp(), alt.getTimeStamp()) << std::endl;


		avg_watts = ((avg_watts*count) + (neu.getL2CurrentWatts()*difftime(neu.getTimeStamp(), alt.getTimeStamp()))) / (count+difftime(neu.getTimeStamp(), alt.getTimeStamp()));
		count = count + difftime(neu.getTimeStamp(), alt.getTimeStamp()) ;
		std::cout << "Avg Watts: " << avg_watts << " W"<<std::endl << std::endl;

		std::cout << "AVG Watts: " << (neu.getL2CurrentVoltage() * neu.getL2CurrentAmpere()) << " W" << std::endl << std::endl;

	}

	return 0;
}
