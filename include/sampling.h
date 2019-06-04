#ifndef RANDOM_NUMBERS_H
#define RANDOM_NUMBERS_H

#include <map>

double PDF(double x);
double InverseCDF(double x);
std::map<double, int> RejectionSampling(int size);
std::map<double, int> InversionSampling(int size);

#endif /* RANDOM_NUMBERS_H */
