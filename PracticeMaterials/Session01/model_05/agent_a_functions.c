#include "header.h"
#include "agent_a_agent_header.h"

/*
 * \fn: int random_number(int a, int b)
 * \brief: Return a random interger between a and b inclusive.
 */
int random_number(int a, int b)
{
	return (a+(int)(((double)b)*rand()/(RAND_MAX+1.0)));
}

/*
 * \fn: int output()
 * \brief: Send messages.
 */
int output()
{
	int a, id, random;

	// Send 20 messages with random ids and random numbers
	printf("*** output messages ***\n");
	for(a = 0; a < 20; a++)
	{
		id = random_number(1,9);
		random = random_number(1,10);
		printf("output message id=%d r=%d\n", id, random);
		add_m_message(id, random);
	}

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int input_random()
 * \brief: Receive messages in random order.
 */
int input_random()
{
	// Receive messages filtered on if and ascending order on random number
	printf("*** input messages in random order ***\n");
	START_M_MESSAGE_LOOP
		printf("input message  id=%d r=%d\n", m_message->id, m_message->r);
	FINISH_M_MESSAGE_LOOP

	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int input_filtered_sorted()
 * \brief: Receive messages filtered and sorted.
 */
int input_filtered_sorted()
{
	// Receive messages filtered on if and ascending order on random number
	printf("*** input messages filtered and sorted***\n");
	START_M_MESSAGE_LOOP
		printf("input message  id=%d r=%d\n", m_message->id, m_message->r);
	FINISH_M_MESSAGE_LOOP

	return 0; /* Returning zero means the agent is not removed */
}
