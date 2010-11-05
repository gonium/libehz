//============================================================================
// Name        : ehzreader.cpp
// Author      : kleinmat
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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
