#ifndef OUTPUT_H
#define OUTPUT_H


#include <vector>

#include "difference.h"


bool compareDiffs(Difference a, Difference b);

void printAsTable(std::vector<Difference> &diff);


#endif
