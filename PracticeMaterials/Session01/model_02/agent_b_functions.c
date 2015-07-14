#include "header.h"
#include "agent_b_agent_header.h"

/*
 * \fn: int receive_messages()
 * \brief: Read and write to memory.
 */
int receive_messages()
{
	SUM_OF_IDS = 0;

	// Read messages of type message_z
	START_MESSAGE_Z_MESSAGE_LOOP
		SUM_OF_IDS += message_z_message->an_id + MY_ID;
	FINISH_MESSAGE_Z_MESSAGE_LOOP
    printf("My Id is: %d\n", MY_ID);
	printf("The sum of ids received is: %d\n", SUM_OF_IDS);

	return 0; /* Returning zero means the agent is not removed */
}
