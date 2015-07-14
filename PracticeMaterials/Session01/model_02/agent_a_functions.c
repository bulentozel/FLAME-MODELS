#include "header.h"
#include "agent_a_agent_header.h"

/*
 * \fn: int send_message()
 * \brief: Send message.
 */
int send_message()
{
	// Send a message of type message_z containing the id of the agent
	add_message_z_message(MY_ID);

	return 0; /* Returning zero means the agent is not removed */
}
