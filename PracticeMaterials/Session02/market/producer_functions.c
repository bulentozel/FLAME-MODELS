#include "header.h"
#include "producer_agent_header.h"

/*
 * \fn: int produce_goods
 * \brief:
 */
int producer_produce_goods()
{
    printf("Producer ID = %d produces goods. \n", ID);
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int go_to_market_to_sell
 * \brief:
 */
int producer_go_to_market_to_sell()
{
     printf("Producer ID = %d wants to sell. \n", ID);
    
	return 0; /* Returning zero means the agent is not removed */
}

