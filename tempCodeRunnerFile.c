
struct Node
{
    int data;
    int position;
    struct Node *next;
};
struct Node *insertAtPosition(struct Node *head, int data, int postion)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (position == 1)
    {
        newNode->next = head;
        return newNode;
    }
    else
    {
        struct Node *temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Position is out of range\n");
            return head;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
    }
};
void display(struct Node *node)
{
    printf("The element are ");
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
    }
}
int main()
{
    struct Node *head ;