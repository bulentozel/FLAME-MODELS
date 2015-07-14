#include "header.h"
#include "bank_agent_header.h"

/*
 * \fn: int bank_process_loan_requests()
 * \brief: Bank collects loan requests from the firms and processes them.
 */
int bank_process_loan_requests()
{
    double amount = 0;
    int firm;
    double assets, debts;
    
    START_LOAN_REQUEST_MESSAGE_LOOP
    amount = loan_request_message->amount;
    firm = loan_request_message->firm_id;
    assets = loan_request_message->assets;
    debts = loan_request_message->debts;
    if (debts / assets < DEBT_THRESHOLD) {
        add_loan_decision_message(ID, firm, amount);
        LOANS += amount;
        LIQUIDITY -= amount;
        printf("Bank ID = %d has given out %f amount of loan to Firm ID = %d\n", ID, amount, firm);
    }
    else {
        printf("Bank ID = %d has rejected loan request Firm ID = %d\n", ID, firm);
    }
    FINISH_LOAN_REQUEST_MESSAGE_LOOP
    
	return 0; /* Returning zero means the agent is not removed */
}




