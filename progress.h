#ifndef PROGRESS_H
#define PROGRESS_H

#include <stdbool.h>

#include "generate.h"
#include "debug.h"


#ifdef SDL_PROGRESS
# define SDL_SHORTOPTS
# define SDL_LONGOPTS \
	{"SDL", no_argument, NULL, 'SDL'}, \
	{"wait", required_argument, NULL, 'wait'}, \
	{"pos", required_argument, NULL, 'pos'},
#else // ndef SDL_PROGRESS
# define SDL_SHORTOPTS
# define SDL_LONGOPTS
#endif // def SDL_PROGRESS


#define PROGRESS_SHORTOPTS "P::TM:I:" SDL_SHORTOPTS

#define PROGRESS_LONGOPTS \
	{"progressfile", optional_argument, NULL, 'P'}, \
	{"progresstext", no_argument, NULL, 'T'}, \
	{"noprogress", no_argument, NULL, 'nopr'}, \
	{"progresscount", required_argument, NULL, 'M'}, \
	{"progressinterval", required_argument, NULL, 'I'}, \
	SDL_LONGOPTS



#define PROGRESS_HELP \
	"Progress Options\n" \
	"	-P <file> --progressfile <file>    Output progress images as a multi-image PNM file <file>.\n"\
	"	-P --progresstext                  Output progress on stderr.\n"\
	"	-M <int> --progresscount <int>     Output <int> extra progress images, repeating the complete image.\n"\
	"	-I <int> --progressinterval <int>  Output progress images every <int> pixels.\n"\
	"	--SDL                              Output progress images on an SDL window.\n"\
	"	--wait [seconds]                   Wait [seconds] seconds before closing, if negative, don't close automatically.\n"\
    "	                                        [seconds] defaults to -1 if not given, and 0 if --wait is not given.\n"\
	"	--pos <x>,<y>                      Place the SDL window at <x>,<y>.\n"\
	""

struct progressdata {
	pthread_rwlock_t *datalock;
	pthread_barrier_t *progressbarrier;
	const struct pnmdata *const data;
	const volatile bool *finished;
};

bool progress_option(int c, char *optarg);
void progress_finalize(const char *progname, int dimx, int dimy, unsigned int seed, int depth);
extern void *(*progress)(void *pdata_); // struct progressdata *pdata



#endif // PROGRESS_h