#include "header.h"
#include "firm_agent_header.h"


/*
 * \fn: int firm_determine_liquidity_need()
 * \brief: The firm computes its liquidity need.
 */

int firm_determine_liquidity_need()
{
    
    /* Flip the coin to determine the need. The outcome is either 0 or 1 */
    LIQUIDITY_NEED = rand() % 2;
    
    printf("Firm ID = %d, Liquidity Need = %d \n", ID, LIQUIDITY_NEED);
    
    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_request_loan()
 * \brief: The firm applies for credit.
 */
int firm_request_loan()
{
    int amount;
    
    /* Determine a random amount */
    amount = rand() % 100 + 1;
    
    printf("Firm ID = %d, Loan Request = %d \n", ID, amount);
    
    add_loan_request_message(ID, BANK_ID, amount, ASSETS, DEBTS);
    
    return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int firm_check_loan_status()
 * \brief: The firm checks result of its loan request.
 */
int firm_check_loan_status()
{
    double amount = 0;
    int bank;
    
    START_LOAN_DECISION_MESSAGE_LOOP
    amount = loan_decision_message->amount;
    bank = loan_decision_message->bank_id;
    FINISH_LOAN_DECISION_MESSAGE_LOOP
    
    if (amount > 0) {
        DEBTS += amount;
        printf("Firm ID = %d has gotten %d amount of loan from Bank ID = %d \n", ID, amount, bank);
    }
    
    return 0; /* Returning zero means the agent is not removed */
}

