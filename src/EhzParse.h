/*
 * EhzParse.h
 *
 *  Created on: 28.10.2010
 *      Author: kleinmat
 */

#ifndef EHZPARSE_H_
#define EHZPARSE_H_

#include <string>
#include "EhzDatagram.h"

class EhzParse {
public:
	EhzParse();
	EhzParse(std::string datagramm);
	virtual ~EhzParse();
	void printRawDatagramm();
	std::string parseDatagramm();
	void setDatagramm(std::string datagramm);

	double getActivePower();
	int getL2CurrentWatts();
	double getL2CurrentAmpere();
	double getL2CurrentVoltage();
	EhzDatagram getDatagramm();

private:
	std::string datagramm;
	double findDouble(std::string exp);
	int findInt(std::string exp);
};

#endif /* EHZPARSE_H_ */
