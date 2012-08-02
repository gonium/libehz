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
