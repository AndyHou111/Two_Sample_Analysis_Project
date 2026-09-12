
// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath> // sqrt, modf

using namespace std;

//EFFECTS: returns the count (sample size) of the numbers in v
int count(std::vector<double> v){
    int a = 0;
    for (size_t i=0; i < v.size(); ++i)
    {
        a++;
    }
    return a;
};

//REQUIRES: v is not empty
//EFFECTS: returns the sum of the numbers in v
double sum(std::vector<double> v){
    assert(v.size() != 0);
    double total = 0;
    for (size_t i=0; i<v.size(); ++i) {
        total += v[i];
    }
    return total;
};

//REQUIRES: v is not empty
//EFFECTS: returns the arithmetic mean of the numbers in v
//  http://en.wikipedia.org/wiki/Aritmetic_mean
double mean(std::vector<double> v){
    assert(v.size() != 0);
    double total = sum(v); //used to find the sum of the values in the vector
    int c = count(v); //the numbers of values in the vector
    return total/c; 
};

//REQUIRES: v is not empty
//EFFECTS: returns the median of the numbers in v
//  https://en.wikipedia.org/wiki/Median#Finite_data_set_of_numbers
double median(std::vector<double> v){
    assert(v.size() != 0);
    sort(v.begin(), v.end());
    int n = count(v);
    if (v.size()%2 == 1){
        return v[n/2];
    }
    else
    {
        return (v[n/2 - 1] + v[n/2])/2.0;
    }
};

//REQUIRES: v is not empty
//EFFECTS: returns the min number in v
double min(std::vector<double> v){
    assert(v.size() != 0);
    sort(v.begin(), v.end());
    return v[0];
};

//REQUIRES: v is not empty
//EFFECTS: returns the max number in v
double max(std::vector<double> v){
    assert(v.size() != 0);
    sort(v.begin(), v.end());
    return v[v.size()-1];
};

//REQUIRES: v contains at least 2 elements
//EFFECTS: returns the corrected sample standard deviation of the numbers in v
//  http://en.wikipedia.org/wiki/Standard_deviation#Corrected_sample_standard_deviation
double stdev(std::vector<double> v){
   assert(v.size() >= 2);
   double m = mean(v);              
   int c = count(v);
   double sum = 0.0;
   for (size_t i = 0; i < v.size(); i++)
   {
        sum += (v[i]-m)*(v[i]-m)/(c-1);
   }
   return sqrt(sum);


};

//REQUIRES: v is not empty
//          p is between 0 and 1, inclusive
//EFFECTS: returns the percentile p of the numbers in v like Microsoft Excel.
//  Refer to the project spec for the formula to use.
//  NOTE: the definition in the spec uses indexing from 1.  You will need to
//  adapt it to use indexing from 0.
double percentile(std::vector<double> v, double p){
    assert((v.size() != 0) && 0 <= p && p <= 1);
    sort(v.begin(), v.end());
    if (p == 1){                //consider the edge case that p == 1
        return v[v.size()-1];
    }
    int n = count(v);
    double rank = p*(n-1) + 1;
    double k = 0;
    double d = 0;
    d = modf(rank, &k);
    double v_k = v[k-1];
    double v_k_1 = v[k];
    double v_p = v_k + d*(v_k_1 - v_k);
    return v_p;
};

//REQUIRES: v and criteria have the same number of elements
//EFFECTS: returns a new, filtered version of v containing the elements (and
//         only those elements) at v[x] where criteria[x] is equal to target,
//         in the same order as they originally appear in v.
//         Note: For this function, compare values to the criteria using ==.
std::vector<double> filter(std::vector<double> v,
                           std::vector<double> criteria,
                           double target){
    assert(v.size()==criteria.size());
    vector<double> ans = {};
    for (size_t i = 0; i < criteria.size(); i++)
    {
        if (criteria[i] == target)
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
};
