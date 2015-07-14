#include "header.h"
#include "agent_a_agent_header.h"

/*
 * \fn: int function_a_1()
 * \brief: Send message.
 */
int function_a_1()
{
	printf("A line from (%f,%f,%f) to ", MY_LINE.start.x, MY_LINE.start.y, MY_LINE.start.z);
	printf("(%f,%f,%f)\n", MY_LINE.end.x, MY_LINE.end.y, MY_LINE.end.z);

	MY_LINE.end.x *= ENV_INT;
	MY_LINE.end.y *= ENV_INT;
	MY_LINE.end.z *= ENV_INT;

	printf("but now to (%f,%f,%f)\n", MY_LINE.end.x, MY_LINE.end.y, MY_LINE.end.z);

	return 0; /* Returning zero means the agent is not removed */
}

int function_a_2()
{
    
	printf("My ID is %d\n", MY_ID);
    
	return 0; /* Returning zero means the agent is not removed */
}

