#include <stdbool.h>

/**
 * @brief Calculate the difference between two teams scores.
 * Uses the following process:
 * Each player alternates, adding scores to their own total from the list.
 * If the score is even, reverse the remaining items in the list.
 * 
 * @param numSeq_count number of scores to total
 * @param numSeq score list
 * @return int first player's score minus second player's score
 */
int getScoreDifference(int numSeq_count, int* numSeq) {
    
    //score totals
    int first = 0;
    int second = 0;
    
    //pointers
    int * p1 = &(numSeq[0]); //advanced when not reversed
    int * p2 = &(numSeq[numSeq_count - 1]); //advanced (backwards) when reversed
    
    printf("%d\n", *p1);
    
    //turn marker
    bool firstTurn = true;
    
    //pointer marker
    bool usingp1 = true;
    
    int n;
    while (p1 != p2) {
        //get next score
        
        if (usingp1) {
            n = *p1;
            p1++;
        }
        else {
            n = *p2;
            p2--;
        }
        
        //add to the current player
        if (firstTurn) {
            printf("P1 + %d\n", n);
            first += n;
            firstTurn = false;
        }
        else {
            printf("P2 + %d\n", n);
            second += n;
            firstTurn = true;
        }
        
        //reverse if necessary
        if (n % 2 == 0) {
            printf("REVERSE\n");
            usingp1 = !usingp1;
        }
    }
    
    //handle last score
    //get score
    if (usingp1) {
            n = *p1;
            p1++;
        }
    else {
        n = *p2;
        p2--;
    }
    //add to the current player
    if (firstTurn) {
        printf("P1 + %d\n", n);
        first += n;
        firstTurn = false;
    }
    else {
        printf("P2 + %d\n", n);
        second += n;
        firstTurn = true;
    }
    
    return first - second;
}
