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

#ifndef EHZDATAGRAMM_H_
#define EHZDATAGRAMM_H_

#include <string>
#include <time.h>

class EhzDatagram {
public:
	EhzDatagram();
	virtual ~EhzDatagram();

	time_t getTimeStamp() const;
	double getActivePower() const;
    double getL2CurrentAmpere() const;
    double getL2CurrentVoltage() const;
    int getL2CurrentWatts() const;
    void setActivePower(double ActivePower);
    void setL2CurrentAmpere(double L2CurrentAmpere);
    void setL2CurrentVoltage(double L2CurrentVoltage);
    void setL2CurrentWatts(int L2CurrentWatts);

    std::string toString();

protected:
    time_t timestamp;
	double ActivePower;
	double L2CurrentVoltage;
	double L2CurrentAmpere;
	int	L2CurrentWatts;
};

#endif /* EHZDATAGRAMM_H_ */
