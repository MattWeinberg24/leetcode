#include <stdio.h>
#include <stdlib.h>
#include "../lib/ListNode.h"

void print(struct ListNode ** nodes) {
    for (int i = 0; i < 4; i++) {
        if (nodes[i] != NULL) {
            printf("%d: %d -> ", i, nodes[i]->val);
            if (nodes[i]->next != NULL) {
                printf("%d\n", nodes[i]->next->val);
            }
            else {
                printf("NULL\n");
            }
        }
        else {
            printf("%d: NULL\n", i);
        }
    }
    printf("\n");
}

/**
 * @brief Given a linked list, swap every two adjacent nodes and return its head.
 * You must solve the problem without modifying the values in the list's nodes 
 * (i.e., only nodes themselves may be changed.)
 * 
 * @param head linked list head
 * @return struct ListNode* resulting linked list head
 */
struct ListNode * swapPairs(struct ListNode * head) {
    struct ListNode * h = head;
    struct ListNode * next0 = NULL;
    struct ListNode * nodes[] = {h, NULL, NULL, NULL};

    //get head
    if (head == NULL || head->next == NULL) {
        return head;
    }
    else {
        head = h->next;
        nodes[1] = h->next;
    }
    
    while (true) {
        printf("START LOOP:\n");
        print(nodes);

        if (nodes[1] != NULL) {
            if (nodes[1]->next != nodes[0]) {
                nodes[2] = nodes[1]->next;
                printf("IDENTIFY NODE 2: VER 1\n");
            }
            else {
                nodes[2] = nodes[0]->next;
                printf("IDENTIFY NODE 2: VER 2\n");
            }
            
            
            print(nodes);
        }
        
        // 1 goes to 0
        if (nodes[0]->next != NULL && nodes[1]->next != nodes[0]) {
            nodes[1]->next = nodes[0];
            printf("1 GOES TO 0\n");
            print(nodes);
        }
        else if (nodes[0]->next == NULL) {
            
            return head;
        }

        // 2 is null case
        if (nodes[2] == NULL) {
            
            printf("2 IS NULL\n");
            // nodes[0]->next = nodes[1];
            nodes[0]->next = NULL;
            print(nodes);
            
            return head;
        }

        nodes[3] = nodes[2]->next;
        printf("NODE 3 IDENTIFIED\n");
        print(nodes);

        //3 is null case
        if (nodes[3] == NULL) {
            nodes[0]->next = nodes[2];
            printf("3 IS NULL\n");
            print(nodes);
            return head;
        }

        next0 = nodes[3]->next;
        // printf("%d\n", next0->val);

        //3 goes to 2 and 0 goes to 3
        nodes[3]->next = nodes[2];
        printf("3 GOES TO 2\n");
        print(nodes);

        nodes[0]->next = nodes[3];
        printf("0 GOES TO 3\n");
        print(nodes);

        nodes[2]->next = next0;

        printf("ASSIGN NEXT TO 2\n");
        print(nodes);

        nodes[0] = nodes[2];
        nodes[1] = nodes[3];
        nodes[2] = NULL;
        nodes[3] = NULL;
    }
    return head;
}
