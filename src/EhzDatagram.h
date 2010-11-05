/*
 * EhzDatagramm.h
 *
 *  Created on: 28.10.2010
 *      Author: kleinmat
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
