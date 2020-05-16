// Copyright 2020 Mikhail Zakharov

#ifndef MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_H_
#define MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_H_
extern const unsigned int max_period_days;
class DepositCalc {
    int depositAmount;
    unsigned int period;
    int rate;
    int depositWithRate;
    int interestCharges;
 public:
     DepositCalc(int _depositAmount, int _period, int _rate);
     void calc();
     void setDepositAmount(const int& depositAmount);
     void setPeriod(unsigned const int& period);
     void setRate(const int& rate);
     int getDepositAmount() const;
     int getPeriod() const;
     int getRate() const;
     int getDepositWithRate() const;
     int getInterestCharges() const;
};

#endif  // MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_H_
