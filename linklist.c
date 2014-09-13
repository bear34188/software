/**************************************************************************************************/
/* Copyright (C) FUSEN, SSE@USTC, 2014-2015							  */
/*												  */
/*  FILE NAME			:  linklist.c							  */
/*  PRINCIPAL AUTHOR		:  FuSen							  */
/*  SUBSYTEM NAME		:  linklist							  */
/*  MODULE NAME			:  linklist							  */
/*  LANGUAGE			:  C								  */
/*  TARGET ENVIRONMENT		:  ANY								  */
/*  DATE OF FIRST REALSE	:  2014/09/11							  */
/*  DESCRIPTION			:  This is a linklist						  */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by FuSen, 2014/09/11
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_NUM 10
#define CMD_LEN 20

typedef struct DataNode
{
    int cmd_num;
    char *cmd;
    char *desc;
    struct DataNode *next;
} tDataNode;


tDataNode* CreateList(tDataNode *head)
{
    tDataNode *p = NULL;
    int i;
    for (i=0;i<CMD_NUM;i++)
    {
        p = (tDataNode*)malloc(sizeof(tDataNode));
        p->cmd_num = i;
        switch(p->cmd_num)
        {
        case 0:
            p->desc = "this is zero cmd!";
            p->cmd = "zero";
            break;
        case 1:
            p->desc = "this is first cmd!";
            p->cmd = "first";
            break;
        case 2:
            p->desc = "this is second cmd!";
            p->cmd = "second";
            break;
        case 3:
            p->desc = "this is third cmd!";
            p->cmd = "third";
            break;
        case 4:
            p->desc = "this is forth cmd!";
            p->cmd = "forth";
            break;
        case 5:
            p->desc = "this is fifth cmd!";
            p->cmd = "fifth";
            break;
        case 6:
            p->desc = "this is sixth cmd!";
            p->cmd = "sixth";
            break;
        case 7:
            p->desc = "this is seventh cmd!";
            p->cmd = "seventh";
            break;
        case 8:
            p->desc = "this is eighth cmd!";
            p->cmd = "eighth";
            break;
        case 9:
            p->desc = "this is ninth cmd!";
            p->cmd = "ninth";
            break;
        }
        p->next = head;
        head = p;
    }
    return head;
}

void ShowList(tDataNode *head)
{
    tDataNode *p = NULL;
    printf("Menu List:\n");
    p = head;
    while (p!=NULL)
    {
        printf(" %s\n",p->desc);
        p = p->next;
    }
}

char* GetString(tDataNode *head)
{
    char* input;
    input = (char *)malloc(sizeof(char));
    printf("Input a cmd code >");
    scanf("%s",input);
    return input;
}

int ShowResult(tDataNode *head,char* string)
{
    tDataNode *p = NULL;
    p=head;
    while(p!=NULL)
    {
        if(!strcmp(p->cmd,string))
        {
            printf("this is %s cmd\n",p->cmd);
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void main()
{
    tDataNode *head = NULL;
    head=CreateList(head);
    ShowList(head);
    char *string;
    string = (char *)malloc(sizeof(char));
    while(1)
    {
        string = GetString(head);
        if(!ShowResult(head,string))
            printf("this is a wrong cmd code,please input'first,second...'\n");
    }
}

