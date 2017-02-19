#ifndef PARSING_H
#define PARSING_H

void clean();
error_t parse_opt(int, char, struct argp_state);
arguments parser(int, char**);

#endif

