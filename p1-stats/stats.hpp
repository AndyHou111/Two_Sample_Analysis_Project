#ifndef STATS_HPP
#define STATS_HPP

#include <vector>

//EFFECTS: returns the count (sample size) of the numbers in v
int count(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the sum of the numbers in v
double sum(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the arithmetic mean of the numbers in v
double mean(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the median of the numbers in v
double median(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the min number in v
double min(std::vector<double> v);

//REQUIRES: v is not empty
//EFFECTS: returns the max number in v
double max(std::vector<double> v);

//REQUIRES: v contains at least 2 elements
//EFFECTS: returns the corrected sample standard deviation of the numbers in v
double stdev(std::vector<double> v);

//REQUIRES: v is not empty
//          p is between 0 and 1, inclusive
//EFFECTS: returns the percentile p of the numbers in v
double percentile(std::vector<double> v, double p);

//REQUIRES: v and criteria have the same number of elements
std::vector<double> filter(std::vector<double> v,
                           std::vector<double> criteria,
                           double target);

#endif
