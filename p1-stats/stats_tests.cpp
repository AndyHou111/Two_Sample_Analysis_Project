/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Statistics Project
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */

#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void test_mean_normal();
void test_mean_negative();
void test_median_even_data_set();
void test_median_odd_data_set();
void test_min_normal();
void test_min_smallest_to_biggest();
void test_min_biggest_to_smallest();
void test_max_normal();
void test_max_smallest_to_biggest();
void test_max_biggest_to_smallest();
void test_stdev_small_data();
void test_stdev_big_data();
void test_percentile_normal_case();
void test_percentile_edge_case();
void test_filter();
// Add prototypes for you test functions here.

const double epsilon = 0.00001;

static bool almost_equal(double x, double y) {
  return abs(x - y) < epsilon;
}

int main() {
  test_sum_small_data_set();
  test_mean_normal();
  test_mean_negative();
  test_median_even_data_set();
  test_median_odd_data_set();
  test_min_normal();
  test_min_smallest_to_biggest();
  test_min_biggest_to_smallest();
  test_max_normal();
  test_max_smallest_to_biggest();
  test_max_biggest_to_smallest();
  // Call your test functions here

  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(almost_equal(sum(data), 6));

  cout << "PASS!" << endl;
}

void test_mean_normal(){
    cout << "test_mean_normal" << endl;

    vector<double> data;
    data.push_back(1.5);
    data.push_back(2.6);
    data.push_back(3.4);
    data.push_back(2.5);

    assert(almost_equal(mean(data),2.5));

    cout << "PASS!" << endl;
}

void test_mean_negative(){
    cout << "test_mean_negative" << endl;

    vector<double> data;
    data.push_back(-1.5);
    data.push_back(-2.6);
    data.push_back(-3.4);
    data.push_back(-2.5);

    assert(almost_equal(mean(data),-2.5));

    cout << "PASS!" << endl;
}

void test_median_even_data_set(){
    cout << "test_median_even_data_set" << endl;
    vector<double> data;
    data.push_back(1.5);
    data.push_back(2.5);
    data.push_back(3.5);
    data.push_back(4.5);

    assert(almost_equal(median(data), 3.0));

    cout << "PASS!" << endl;
}

void test_median_odd_data_set(){
    cout << "test_median_odd_data_set" << endl;
    vector<double> data;
    data.push_back(1.0);
    data.push_back(2.5);
    data.push_back(3.0);

    assert(almost_equal(median(data), 2.5));

    cout << "PASS!" << endl;
}

void test_min_normal(){
    cout << "test_min_normal" << endl;
    vector<double> data;
    data.push_back(1.5);
    data.push_back(2.4);
    data.push_back(-1.3);
    data.push_back(7.7);
    data.push_back(3.6);
    data.push_back(0.1);

    assert(almost_equal(min(data),-1.3));

    cout << "PASS!" << endl;
}

void test_min_smallest_to_biggest(){
    cout << "test_min_smallest_to_biggest" << endl;
    vector<double> data;
    data.push_back(-1.3);
    data.push_back(2.4);
    data.push_back(3.4);
    data.push_back(5.6);
    data.push_back(7.8);
    data.push_back(10);

    assert(almost_equal(min(data),-1.3));

    cout << "PASS!" << endl;
}

void test_min_biggest_to_smallest(){
    cout << "test_min_biggest_to_smallest" << endl;
    vector<double> data;
    data.push_back(10);
    data.push_back(8.9);
    data.push_back(5.7);
    data.push_back(4.4);
    data.push_back(3.2);
    data.push_back(1.2);

    assert(almost_equal(min(data),1.2));

    cout << "PASS!" << endl;
}

void test_max_normal(){
    cout << "test_max_normal" << endl;
    vector<double> data;
    data.push_back(1.5);
    data.push_back(2.4);
    data.push_back(-1.3);
    data.push_back(7.7);
    data.push_back(3.6);
    data.push_back(0.1);

    assert(almost_equal(max(data),7.7));

    cout << "PASS!" << endl;
}

void test_max_smallest_to_biggest(){
    cout << "test_min_smallest_to_biggest" << endl;
    vector<double> data;
    data.push_back(-1.3);
    data.push_back(2.4);
    data.push_back(3.4);
    data.push_back(5.6);
    data.push_back(7.8);
    data.push_back(10);

    assert(almost_equal(max(data),10));

    cout << "PASS!" << endl;
}

void test_max_biggest_to_smallest(){
    cout << "test_max_biggest_to_smallest" << endl;
    vector<double> data;
    data.push_back(9.7);
    data.push_back(8.9);
    data.push_back(5.7);
    data.push_back(4.4);
    data.push_back(3.2);
    data.push_back(1.2);

    assert(almost_equal(max(data),9.7));

    cout << "PASS!" << endl;
}

void test_stdev_small_data(){
    cout << "test_stdev_small_data" << endl;
    vector<double> data;
    data.push_back(9.7);
    data.push_back(5.7);

    assert(almost_equal(stdev(data),2.82843));

    cout << "PASS!" << endl;
}

void test_stdev_big_data(){
    cout << "test_stdev_big_data" << endl;
    vector<double> data;
    data.push_back(9.7);
    data.push_back(8.9);
    data.push_back(5.7);
    data.push_back(4.4);
    data.push_back(3.2);
    data.push_back(1.2);

    assert(almost_equal(stdev(data),3.29328));

    cout << "PASS!" << endl;
}

void test_percentile_edge_case(){
    cout << "test_percentile_edge_case" << endl;
    vector<double> data;
    data.push_back(9.7);
    data.push_back(8.9);
    data.push_back(5.7);
    data.push_back(4.4);
    data.push_back(3.2);
    data.push_back(1.2);

    assert(almost_equal(percentile(data,1),9.7));

    cout << "PASS!" << endl;
}

void test_percentile_normal_case(){
    cout << "test_percentile_edge_case" << endl;
    vector<double> data;
    data.push_back(15);
    data.push_back(20);
    data.push_back(35);
    data.push_back(40);
    data.push_back(50);
    
    assert(almost_equal(percentile(data,0.4),29));

    cout << "PASS!" << endl;
}

void test_filter(){
    cout << "test_filter" << endl;
    vector<double> locations = {0, 1, 0, 1, 1, 2, 2, 0, 1};
    vector<double> temps = {15.5, 23.1, 7.8, 19.2, 22.6, 4.6, 1.9, 14.3, 18.0};
    vector<double> temps_1 = filter(temps, locations, 1);
    vector<double> expected_temps_1 = {23.1, 19.2, 22.6, 18.0};
    
    assert(temps_1 == expected_temps_1);

    cout << "PASS!" << endl;
}

// Add the test function implementations here.