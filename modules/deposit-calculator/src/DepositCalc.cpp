// Copyright 2020 Mikhail Zakharov

#include "include/DepositCalc.h"
#include <iostream>

const unsigned int max_period_days = 1826;

DepositCalc::DepositCalc(int _depositAmount, int _period, int _rate)
    :depositAmount(_depositAmount), period(_period), rate(_rate) {}

int DepositCalc::getDepositAmount()const {
    return depositAmount;
}

int DepositCalc::getPeriod()const {
    return period;
}

int DepositCalc::getRate()const {
    return rate;
}

int DepositCalc::getDepositWithRate()const {
    return depositWithRate;
}

int DepositCalc::getInterestCharges()const {
    return interestCharges;
}

void DepositCalc::setDepositAmount(const int& depositAmount) {
    this->depositAmount = depositAmount;
}

void DepositCalc::setPeriod(unsigned const int& period) {
    if (period < 0)
        throw "PeriodisNegative";
    if (period == 0)
        throw "PeriodIsZero";
    if (period > max_period_days)
        throw "PeriodMoreThan1826";
    this->period = period;
}

void DepositCalc::setRate(const int& rate) {
    this->rate = rate;
}

void DepositCalc::calc() {
    depositWithRate = depositAmount + ((depositAmount * rate * period)
        / (366 * 100));
    interestCharges = depositWithRate - depositAmount;
}
