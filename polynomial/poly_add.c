//POLYNOMIAL ADDITION(PERFECT CODE, SORTED) Renewed

#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    int coeff;
    int pow;
    struct link *next;
} my_poly;

void my_create_poly(my_poly **node);
void my_show_poly(my_poly *node);
void my_add_poly(my_poly **result, my_poly *poly1, my_poly *poly2);
void my_poly_add_ordered_term(my_poly **poly, int coeff, int pow);

int main() {
    int ch;
    my_poly *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

    do {
        while (poly1 != NULL) {
            my_poly* temp = poly1;
            poly1 = poly1->next;
            free(temp);
        }
        while (poly2 != NULL) {
            my_poly* temp = poly2;
            poly2 = poly2->next;
            free(temp);
        }
        while (poly3 != NULL) {
            my_poly* temp = poly3;
            poly3 = poly3->next;
            free(temp);
        }
        
        poly1 = poly2 = poly3 = NULL;

        printf("\nCreate 1st expression\n");
        my_create_poly(&poly1);
        printf("\nStored the 1st expression\n");
        my_show_poly(poly1);

        printf("\n\nCreate 2nd expression\n");
        my_create_poly(&poly2);
        printf("\nStored the 2nd expression\n");
        my_show_poly(poly2);

        my_add_poly(&poly3, poly1, poly2);
        printf("\nResultant expression after addition\n");
        my_show_poly(poly3);

        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch);
    } while (ch);

    while (poly1 != NULL) {
        my_poly* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }
    while (poly2 != NULL) {
        my_poly* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }
    while (poly3 != NULL) {
        my_poly* temp = poly3;
        poly3 = poly3->next;
        free(temp);
    }

    return 0;
}

void my_create_poly(my_poly **node) {
    int flag, coeff, pow;
    printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
    scanf("%d", &flag);
    while (flag) {
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        printf("\nEnter Pow:");
        scanf("%d", &pow);
        my_poly_add_ordered_term(node, coeff, pow);
        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag);
    }
}

void my_poly_add_ordered_term(my_poly **poly, int coeff, int pow) {
    my_poly *current = *poly;
    my_poly *prev = NULL;
    my_poly *new_term = NULL;

    while (current != NULL && current->pow > pow) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->pow == pow) {
        current->coeff += coeff;
    } else {
        new_term = (my_poly *)malloc(sizeof(my_poly));
        new_term->coeff = coeff;
        new_term->pow = pow;
        new_term->next = NULL;

        if (prev == NULL) {
            new_term->next = *poly;
            *poly = new_term;
        } else {
            prev->next = new_term;
            new_term->next = current;
        }
    }
}

void my_show_poly(my_poly * node)
{
printf("\nThe polynomial expression is:\n");
while(node != NULL) 
{ printf("%dx^%d", node->coeff, node->pow);
node = node->next;
if(node != NULL)
printf(" + ");
}
}
void my_add_poly(my_poly ** result, my_poly * poly1, my_poly * poly2) 
{

    my_poly * tmp_node;
    tmp_node = (my_poly *) malloc(sizeof(my_poly));
    tmp_node->next = NULL;
    *result = tmp_node;
    while(poly1 && poly2) 
    {
        if (poly1->pow > poly2->pow) 
          {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;     
          }
        else if (poly1->pow < poly2->pow)
          {
            tmp_node->pow = poly2->pow;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;    
           }
        else 
          {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;        
           }
        if(poly1 && poly2) 
         {
            tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;        
         }    
     }
    while(poly1 || poly2) 
    {
        tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;
         if(poly1)
         {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;        
         }
        if(poly2) 
        {
            tmp_node->pow = poly2->pow;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;        
        }  
     }
     printf("\nAddition Complete");
}