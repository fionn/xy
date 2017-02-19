#include <argp.h>
#include <iostream>
#include "arguments.h"
#include "parse.h"

error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = (struct arguments *) state -> input;
    switch(key)
    {
        case 'b':
            arguments -> beta = atof(arg);
            if(atof(arg) < 0)
            {
                std::cerr << "β < 0, exiting" << std::endl;
                return 1;
            }
            break;
        case 'c':
            arguments -> correlate = atoi(arg);
            if(atoi(arg) <= 0)
            {
                std::cerr << "c <= 0, exiting" << std::endl;
                return 1;
            }
            break;
        case 'm':
            arguments -> mag = true;
            break;
        case 'n':
            arguments -> size = atoi(arg);
            if(atoi(arg) <= 0)
            {
                std::cerr << "n <= 0, exiting" << std::endl;
                return 1;
            }
            break;
        case 0:
            std::cout << state[0].name  << std::endl;
            std::cout << state[2].flags << std::endl;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

arguments parser(int argc, char *argv[])
{
    static struct argp_option options[] = 
    {
        {"beta", 'b', "b", 0, "Set the value of β for the correlation function"},
        {"correlate", 'c', "c", 0, "Set the iteration number on the correlation function"},
        {"mag", 'm', 0, 0, "Print β,〈|M|²⟩"},
        {"size", 'n', "n", 0, "Set the size of the (square) lattice"},
        {0}
    };

    static char doc[] = "\e[1;36mXY\e[0m\n\e[1F\e[2C simulates a topological phase transition in the O(2) XY model of spin statistics. It uses Markov chain Monte Carlo methods to observe the Kosterlitz-Thouless transition and numerically verify the Mermin-Wagner theorem on a toroidal lattice.";

    static struct argp argp = {options, parse_opt, 0, doc};

    struct arguments arguments;
    arguments.mag       = false;
    arguments.beta      = 1;
    arguments.correlate = 100000;
    arguments.size      = 32;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    return arguments;
}

