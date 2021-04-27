#include "function.h"

static Node *last = new Node();
static int count;

void Implement::InsertFront(int data)
{
    Node *newNode = new Node(data,NULL);
    if (IsEmpty())
    {
        head = newNode;
        last = newNode;
        count ++;
    }
    else
    {
        newNode -> next = head;
        head = newNode;
        count ++;
    }
}

void Implement::InsertBack(int data)
{
    Node *newNode = new Node(data,NULL);
    if (IsEmpty())
    {
        head = newNode;
        last = newNode;
        count ++;
    }
    else
    {
        last -> next = newNode;
        last = newNode;
        count ++;
    }
}

void Implement::InsertBefore(int data,int data_ref)
{
    if (IsEmpty()!=true)
    {
        if (head -> data == data_ref)
            InsertFront(data);

        else
        {
            Node *pre = new Node();
            pre = head;
            while (pre -> next != NULL)
            {
                if (pre -> next -> data == data_ref)    break;
                else    pre = pre -> next;
            }
            if (pre -> next != NULL)
            {
                Node *newNode = new Node(data,NULL);
                newNode -> next = pre -> next;
                pre -> next = newNode;
                count ++;
            }
        }
    }
}

void Implement::InsertAfter(int data,int data_ref)
{
    if (IsEmpty()!=true)
    {
        if (last -> data == data_ref)
            InsertBack(data);
        else
        {
            Node *temp = new Node();
            temp = head;
            while (temp != NULL)
            {
                if (temp -> data == data_ref)   break;
                else    temp = temp -> next;
            }
            if (temp != NULL)
            {
                Node *newNode = new Node(data,NULL);
                newNode -> next = temp -> next;
                temp -> next = newNode;
                count ++;
            }
        }
    }
}

void Implement::Delete(int data)
{
    if (IsEmpty() != true)
    {
        if (head -> data == data)
        {
            head = head -> next;
            count --;
        }
        else
        {
            Node *pre = new Node();
            pre = head;
            while (pre -> next != NULL)
            {
                if (pre -> next -> data == data)    break;
                else    pre = pre -> next;
            }
            if (pre -> next != NULL)
            {
                if (pre -> next -> data == last -> data)
                {
                    last = pre;
                    pre -> next = NULL;
                    count --;
                }
                else
                {
                    pre -> next = pre -> next -> next;
                    count --;
                }
            }
        }
    }
}

void Implement::DeleteFront()
{
    if (IsEmpty()!=true)
    {
        if (head -> next == NULL)
        {
            head = NULL;
            last = NULL;
            count --;
        }
        else
        {
            head = head -> next;
            count --;
        }
    }
}

void Implement::DeleteBack()
{
    if (IsEmpty()!=true)
    {
        if (head -> next == NULL)
        {
            head = NULL;
            last = NULL;
            count --;
        }
        else
        {
            Node *temp = new Node();
            temp = head;
            while (temp -> next -> next != NULL)
                temp = temp -> next;
            last = temp;
            temp -> next = NULL;
            count --;
        }

    }
}
void Implement::Reverse()
{
    if(IsEmpty()!=true)
    {
        if (head -> next != NULL)
        {
            Node *current = new Node;
            current = head;
            Node *previous = new Node;
            last = head;
            while (current != NULL)
            {
                Node *temp = previous;
                previous = current;
                current = current -> next;
                previous -> next = temp;
            }

            head -> next =NULL;
            head = previous;
        }
    }
}

void Implement::Rotate(int k)
{
    if (IsEmpty()!=true)
    {
        if (head -> next != NULL)
        {
            last -> next = head;
            for (int a=0; a < count -(k%count)-1; a++)
                head = head -> next;
            last = head;
            head = head -> next;
            last -> next = NULL;
        }

    }
}
