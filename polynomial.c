#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int co_eff;
    int power;
    struct node *next;
} nodetype;

void insert1(int x, int y, nodetype **temp) {
    nodetype *r, *z;
    z = *temp;

    if (z == NULL) {
        r = (nodetype *)malloc(sizeof(nodetype));
        r->co_eff = x;
        r->power = y;
        *temp = r;
        r->next = (nodetype *)malloc(sizeof(nodetype));
        r = r->next;
        r->next = NULL;
    } else {
        r->co_eff = x;
        r->power = y;
        r->next = (nodetype *)malloc(sizeof(nodetype));
        r = r->next;
        r->next = NULL;
    }
}

void polyadd(struct node* poly1, struct node* poly2, struct node* poly)
{
    nodetype* temp;
    temp = poly;

    while (poly1->next!=NULL && poly2->next!=NULL) {
        if (poly1->power > poly2->power) {
            temp->power = poly1->power;
            temp->co_eff = poly1->co_eff;
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            temp->power = poly2->power;
            temp->co_eff = poly2->co_eff;
            poly2 = poly2->next;
        } else {
            temp->power = poly1->power;
            temp->co_eff = poly1->co_eff + poly2->co_eff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        temp->next = (struct node*)malloc(sizeof(struct node));
        temp = temp->next;
        temp->next = NULL;
    }

    while (poly1->next) {
        temp->power = poly1->power;
        temp->co_eff = poly1->co_eff;
        poly1 = poly1->next;
        if (poly1->next) {
            temp->next = (struct node*)malloc(sizeof(struct node));
            temp = temp->next;
            temp->next = NULL;
        }
    }

    while (poly2->next) {
        temp->power = poly2->power;
        temp->co_eff = poly2->co_eff;
        poly2 = poly2->next;
        if (poly2->next) {
            temp->next = (struct node*)malloc(sizeof(struct node));
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

void show(nodetype * node) {
    while (node->next != NULL) {
        printf("%dx^%d", node->co_eff, node->power);
        node = node->next;
        if (node->co_eff >= 0) {
            if (node->next != NULL)
                printf("+");
        }
    }
}

int main() {

    nodetype *head = NULL;
    nodetype *head1 = NULL;
    nodetype *head2 = NULL;

    int a, b, c, x, y, z;
    printf("Enter value of 1st Eqn ax^2+bx^1+cx^0:\n");
    printf("Enter Co-Efficients:");
    scanf("%d%d%d", &a, &b, &c);
    printf("Enter powers:");
    scanf("%d%d%d", &x, &y, &z);

    insert1(a, x, &head1);
    insert1(b, y, &head1);
    insert1(c, z, &head1);

    int a1, b1, c1, x1, y1, z1;
    printf("Enter value of 2nd Eqn ax^2+bx^1+cx^0:\n");
    printf("Enter Co-Efficients:");
    scanf("%d%d%d", &a1, &b1, &c1);
    printf("Enter powers:");
    scanf("%d%d%d", &x1, &y1, &z1);

    insert1(a1, x1, &head2);
    insert1(b1, y1, &head2);
    insert1(c1, z1, &head2);

    printf("1st Number: ");
    show(head1);

    printf("\n2nd Number: ");
    show(head2);
    polyadd(head1,head2,head); 

    printf("\nAdded polynomial: "); 
    show(head); 
  
    return 0;
}
