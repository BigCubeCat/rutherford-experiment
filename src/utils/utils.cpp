#include "../utils/utils.hpp"
#include <cmath>

int max(int a, int b) { return (a > b) ? a : b; }

int min(int a, int b) { return (a < b) ? a : b; }

int randrange(int a, int b) { return a + rand() % ((b + 1) - a); }
