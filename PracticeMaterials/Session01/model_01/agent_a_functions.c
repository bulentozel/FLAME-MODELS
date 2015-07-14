#include "header.h"
#include "agent_a_agent_header.h"

/*
 * \fn: int function_1()
 * \brief: Read and write to memory.
 */
int function_1()
{
	// Read from memory
	printf("my_id = %d\n", MY_ID);
	// Write to memory
	MY_ID += 1;
	// Read from memory
	printf("my_id = %d\n", MY_ID);

	return 0; /* Returning zero means the agent is not removed */
}
