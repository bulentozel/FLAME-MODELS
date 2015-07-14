#include "header.h"
#include "bank_agent_header.h"

/*
 * \fn: int bank_process_loan_requests()
 * \brief: Bank collects loan requests from the firms.
 */
int bank_collect_loan_requests()
{
    double amount;
    int firm;
    double assets, debts;
    
    START_LOAN_REQUEST_MESSAGE_LOOP
    amount = loan_request_message->amount;
    firm = loan_request_message->firm_id;
    assets = loan_request_message->assets;
    debts = loan_request_message->debts;
    
    /* Add applicant ID to the list. */
    add_int(&ID_LIST, firm);
    /* Add applicant full data to the list. */
    add_customer(&CUSTOMER_LIST, firm, amount, assets, debts);
    
    FINISH_LOAN_REQUEST_MESSAGE_LOOP
    
    printf("Bank ID = %d has recieved %d loan requests. \n", ID, ID_LIST.size);
    
	return 0; /* Returning zero means the agent is not removed */
}


/*
 * \fn: int bank_evaluate_loan_requests()
 * \brief: Bank processes loan requests.
 */
int bank_evaluate_loan_requests()
{
    double amount;
    int firm;
    double assets, debts;
    
    for (int i = 0; i < CUSTOMER_LIST.size; i++) {
        amount = CUSTOMER_LIST.array[i].request;
        firm = CUSTOMER_LIST.array[i].firm_id;
        assets = CUSTOMER_LIST.array[i].assets;
        debts = CUSTOMER_LIST.array[i].debts;
        if (debts / assets < DEBT_THRESHOLD) {
            add_loan_decision_message(ID, firm, amount);
            LOANS += amount;
            LIQUIDITY -= amount;
            printf("Bank ID = %d has given out %f amount of loan to Firm ID = %d\n", ID, amount, firm);
        }
        else {
            amount = 0;
            add_loan_decision_message(ID, firm, amount);
            printf("Bank ID = %d has rejected loan request Firm ID = %d\n", ID, firm);
        }
    }
	return 0; /* Returning zero means the agent is not removed */
}

/*
 * \fn: int bank_reset_requests()
 * \brief: Bank clears the request list.
 */
int bank_reset_requests()
{
    /*
    while (CUSTOMER_LIST.size > 0) {
        remove_customer(&CUSTOMER_LIST, 0);
    }
    
    
    while (ID_LIST.size > 0) {
        remove_int(&ID_LIST, 0);
    }
    */
    printf("Bank ID = %d has finished loan request processing.\n", ID);
    
    
	return 0; /* Returning zero means the agent is not removed */
}



