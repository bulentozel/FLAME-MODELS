#include "header.h"
#include "agent_a_agent_header.h"

/*
 * \fn: int reset_acts()
 * \brief: Send message.
 */
int reset_acts()
{
	NO_OF_ACTS = 0;

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int increment_act()
 * \brief: Send message.
 */
int increment_act()
{
	NO_OF_ACTS++;

	printf("Act = %d\n", NO_OF_ACTS);

	return 0; /* Returning zero means the agent is not removed */
}
