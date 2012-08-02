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

#define EXP_DATAGRAMM 			"\\Q/\\E.*\\Q!\\E.*"
#define EXP_ACTIVE_POWER 		"\\Q1-0:1.8.0*255(\\E(\\d+.\\d+)\\Q)\\E.*"  // Zählerstand
#define EXP_L2_CURRENT_WATTS	"\\Q1-0:41.7.0*255(+\\E(\\d+)\\Q*W)\\E.*"
#define EXP_L2_CURRENT_AMPERE 	"\\Q1-0:51.7.0*255(\\E(\\d+.\\d+)\\Q*A)\\E.*"
#define EXP_L2_CURRENT_VOLTAGE	"\\Q1-0:52.7.0*255(\\E(\\d+.\\d+)\\Q*V)\\E.*"

#include "EhzParse.h"
#include "EhzDatagram.h"
#include <pcrecpp.h>
#include <sstream>
#include <iostream>
#include <string>

EhzParse::EhzParse(std::string datagramm) {
	this->datagramm = datagramm;
}
EhzParse::EhzParse() {
	// TODO Auto-generated constructor stub
}
EhzParse::~EhzParse() {
	// TODO Auto-generated destructor stub
}

void EhzParse::printRawDatagramm() {
	std::string token;
	std::istringstream iss(datagramm);
	while (getline(iss, token, '\n')) {
		std::cout << token << std::endl;
	}
}

void EhzParse::setDatagramm(std::string datagramm) {
	this->datagramm = datagramm;
}

std::string EhzParse::parseDatagramm() {
	std::string datagramm;
	return "";
}

double EhzParse::findDouble(std::string exp) {
	double value = -1;
	std::string token;
	std::istringstream iss(datagramm);
	while (getline(iss, token, '\n')) {
		value = -1;
		pcrecpp::RE re(exp);
		re.FullMatch(token, &value);
		if (value == -1) // if not found keep looking for
			continue;
		break; // if found break to save value
	}

	return value;
}

EhzDatagram EhzParse::getDatagramm()
{
	EhzDatagram datagramm;
	datagramm.setActivePower(getActivePower());
	datagramm.setL2CurrentAmpere(getL2CurrentAmpere());
	datagramm.setL2CurrentVoltage(getL2CurrentVoltage());
	datagramm.setL2CurrentWatts(getL2CurrentWatts());
	return datagramm;
}

int EhzParse::findInt(std::string exp) {
	int value = -1;
	std::string token;
	std::istringstream iss(datagramm);
	while (getline(iss, token, '\n')) {
		value = -1;
		pcrecpp::RE re(exp);
		re.FullMatch(token, &value);
		if (value == -1) // if not found keep looking for
			continue;
		break; // if found break to save value
	}

	return value;
}

double EhzParse::getL2CurrentVoltage() {
	return findDouble(EXP_L2_CURRENT_VOLTAGE);
}

double EhzParse::getActivePower() {
	return findDouble(EXP_ACTIVE_POWER);
}

double EhzParse::getL2CurrentAmpere() {
	return findDouble(EXP_L2_CURRENT_AMPERE);
}

int EhzParse::getL2CurrentWatts() {
	return findInt(EXP_L2_CURRENT_WATTS);
}
