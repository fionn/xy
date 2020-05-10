#ifndef PARSING_H
#define PARSING_H

#include <argp.h>
#include "arguments.hpp"

void clean();
error_t parse_opt(int, char, struct argp_state);
arguments parser(int, char**);

#endif

