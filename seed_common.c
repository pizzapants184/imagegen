#include "seed.h"

#include <stdbool.h>

#include "setup.h"
#include "generate_common.h"
#include "color.h"
#include "safelib.h"
#include "pnmlib.h"
#include "randint.h"
#include "debug.h"

struct floodplane *floodplanes = NULL;
int floodplanecount = 0;
