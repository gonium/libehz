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

#include "EhzDatagram.h"
#include <sstream>
#include <iostream>
#include <time.h>

EhzDatagram::EhzDatagram() {
	timestamp = time(NULL);
	//std::cout << ctime(&timestamp) << std::endl;
	//sleep(2);
	ActivePower = -1;
	L2CurrentAmpere = -1;
	L2CurrentVoltage = -1;
	L2CurrentWatts = -1;
}

EhzDatagram::~EhzDatagram() {
	// TODO Auto-generated destructor stub
}

time_t EhzDatagram::getTimeStamp() const {
	return timestamp;
}

double EhzDatagram::getActivePower() const {
	return ActivePower;
}

double EhzDatagram::getL2CurrentAmpere() const {
	return L2CurrentAmpere;
}

double EhzDatagram::getL2CurrentVoltage() const {
	return L2CurrentVoltage;
}

int EhzDatagram::getL2CurrentWatts() const {
	return L2CurrentWatts;
}

void EhzDatagram::setActivePower(double ActivePower) {
	this->ActivePower = ActivePower;
}

void EhzDatagram::setL2CurrentAmpere(double L2CurrentAmpere) {
	this->L2CurrentAmpere = L2CurrentAmpere;
}

void EhzDatagram::setL2CurrentVoltage(double L2CurrentVoltage) {
	this->L2CurrentVoltage = L2CurrentVoltage;
}

void EhzDatagram::setL2CurrentWatts(int L2CurrentWatts) {
	this->L2CurrentWatts = L2CurrentWatts;
}

std::string EhzDatagram::toString() {
	std::ostringstream sdatagramm;

	sdatagramm << ctime(&timestamp) << std::endl;
	sdatagramm << "Active Power:  " << getActivePower() << " kWh" << std::endl << std::endl;
	sdatagramm << "L2 Watts:      " << getL2CurrentWatts() << " W" << std::endl;
	sdatagramm << "L2 Volts:      " << getL2CurrentVoltage() << " V" << std::endl;
	sdatagramm << "L2 Ampere:     " << getL2CurrentAmpere() << " A" << std::endl << std::endl;

	return sdatagramm.str();
}
