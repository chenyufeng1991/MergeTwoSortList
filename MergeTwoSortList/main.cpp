//
//  main.cpp
//  MergeTwoSortList
//
//  Created by chenyufeng on 8/9/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>

/**
 *  合并两个排序的数组
 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是按照递增排序的
 */

using namespace std;

// 1 3 5 7 9
// 2 4 6 8
// 1 2 3 4 5 6 7 8 9

typedef struct ListNode{

    int element;
    struct ListNode *next;
}Node;

void CreateList(Node **pHead);
void MergeList(Node *pFirstList, Node *pSecondList, Node **pMergedList);
void PrintList(Node *pHead);

int main(int argc, const char * argv[])
{
    Node *pFirstHead;
    Node *pSecondHead;
    CreateList(&pFirstHead);
    PrintList(pFirstHead);

    CreateList(&pSecondHead);
    PrintList(pSecondHead);

    Node *pMergedList;
    MergeList(pFirstHead, pSecondHead, &pMergedList);

    return 0;
}

void CreateList(Node **pHead)
{
    cout << "请输入链表节点值，输入<=0结束" << endl;
    *pHead = new Node;
    memset(*pHead, 0, sizeof(Node));
    (*pHead)->next = NULL;

    Node *listNode = new Node;
    memset(listNode, 0, sizeof(Node));
    listNode->next = NULL;

    Node *pMove = *pHead;

    cin >> listNode->element;
    while (listNode->element > 0)
    {
        pMove->next = listNode;
        pMove = pMove->next;

        listNode = new Node;
        memset(listNode, 0, sizeof(Node));
        listNode->next = NULL;

        cin >> listNode->element;
    }
}

void MergeList(Node *pFirstList, Node *pSecondList, Node **pMergedList)
{
    *pMergedList = new Node;
    memset(pMergedList, 0, sizeof(Node));
    (*pMergedList)->next = NULL;

    Node *pFirstMove = pFirstList->next;
    Node *pSecondMove = pSecondList->next;
    Node *pMergedMove = *pMergedList;

    while (pFirstList != NULL && pSecondList != NULL)
    {
        if (pFirstList->element <= pSecondList->element)
        {
            pMergedMove->next = pFirstMove;
            pFirstList = pFirstList->next;
        }
        else
        {
            pMergedMove->next = pSecondMove;
            pSecondList = pSecondList->next;
        }
        pMergedMove = pMergedMove->next;
    }

    while (pFirstList != NULL)
    {

    }

    while (pSecondList != NULL)
    {

    }





}

void PrintList(Node *pHead)
{
    Node *pMove = pHead->next;
    while (pMove != NULL)
    {
        cout << pMove->element << " ";
        pMove = pMove->next;
    }
    cout << endl;
}











