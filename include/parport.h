
#include "items.h"
#include "query.h"

typedef struct parport {
	char *	pp_name;
	int	pp_fd;
} ParPort;

#define NO_PARPORT ((ParPort *)NULL)

ITEM_INTERFACE_PROTOTYPES(ParPort,parport)

extern ParPort *	open_parport(QSP_ARG_DECL  const char *name);
extern int		read_parport_status(ParPort *ppp);
extern int		read_til_transition(ParPort *ppp, int mask);

