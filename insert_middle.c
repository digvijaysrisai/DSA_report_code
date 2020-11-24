void insertMiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    if (head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i = 1;

        while (i < position - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (position == 1)
        {
            insertAtBeginning(data);
        }
        else if (temp == last)
        {
            insertAtEnd(data);
        }
        else if (temp != NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}