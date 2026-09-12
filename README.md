# p1-stats

This project is my implementation of the University of Michigan EECS 280 Project 1: Statistics assignment. The program builds a small C++ statistics library and a command-line tool for comparing two groups in a data set.

## Project Overview

The project focuses on descriptive statistics and two-sample analysis. Given a data file, the program can split observations into two groups based on a selected column, compute summary statistics for each group, and estimate a 95% confidence interval for the difference between the two group means.

The main statistics functions include:

- `count()`
- `sum()`
- `mean()`
- `median()`
- `min()`
- `max()`
- `stdev()`
- `percentile()`
- `filter()`

The two-sample analysis program reports:

- count, sum, mean, standard deviation, median, minimum, and maximum
- 0th, 25th, 50th, 75th, and 100th percentiles
- a bootstrap confidence interval for the difference in means

## Implementation

The project is written in C++ using vectors and procedural abstraction.

The statistics library is implemented in `stats.cpp` based on the function declarations in `stats.hpp`. Basic functions such as `count()` and `sum()` are used as helper functions for higher-level calculations like `mean()`. For functions such as `median()` and `percentile()`, the input data is sorted before selecting or interpolating the correct value.

The sample standard deviation is computed using the corrected sample standard deviation formula:

```text
sqrt(sum((x - mean)^2) / (n - 1))
```

The two-sample analysis is implemented in `two_sample.cpp`. It reads a data file, extracts the relevant columns, filters the data into two groups, prints descriptive statistics for each group, and uses bootstrap resampling to approximate the sampling distribution of the difference in means. The confidence interval is then computed from percentiles of that sampling distribution.

## How to Build

Compile the statistics public tests:

```sh
make stats_public_tests.exe
```

Compile the custom statistics tests:

```sh
make stats_tests.exe
```

Compile the two-sample analysis program:

```sh
make two_sample.exe
```

## How to Run

Run the two-sample program with the default sample data:

```sh
./two_sample.exe
```

Run the program with a custom data file:

```sh
./two_sample.exe <data_file> <filter_column> <group_a_value> <group_b_value> <data_column>
```

Example:

```sh
./two_sample.exe HCMST_ver_3.04.tsv q24_met_online 1 0 ppage
```

This compares the `ppage` column for two groups based on the `q24_met_online` column.

## Testing

Run the public tests:

```sh
./stats_public_tests.exe
```

Run the custom tests:

```sh
./stats_tests.exe
```

Run all available tests:

```sh
make test
```

For the sample two-sample program output, redirect the result and compare it with the expected output:

```sh
./two_sample.exe > cats.out
diff cats.out cats.out.correct
```

If `diff` produces no output, the program output matches the expected result.

## Files

- `stats.hpp`: function declarations for the statistics library
- `stats.cpp`: implementation of the statistics functions
- `stats_public_tests.cpp`: public tests provided for the project
- `stats_tests.cpp`: custom unit tests
- `two_sample.cpp`: command-line two-sample analysis program
- `library.hpp` / `library.cpp`: provided helper functions
- `cats.csv`: small sample data set
- `cats.out.correct`: expected output for the sample data
- `Makefile`: build and test commands

## Note

This repository is intended to document my own learning and implementation process. If this project is being used for an active course, the repository should remain private and should follow the course academic integrity policy.
