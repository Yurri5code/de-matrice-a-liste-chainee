#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    int data;
    int index;
    node *next;
};

typedef struct element element;
struct element {
    node* first;
};

element* initialisation() {
    element* element = malloc(sizeof(*element));
    node* node = malloc(sizeof(*node));

    if(node==NULL || element==NULL) {
        exit(EXIT_FAILURE);
    }

    node->data = 0;
    node->index = 0;
    node->next = NULL;
    element->first = node;

    return element;
}

void inserValue(element *head,int data,int index) {
    node* nouveau = malloc(sizeof(*nouveau));

    if(nouveau==NULL || head==NULL) {
        exit((EXIT_FAILURE));
    }

    nouveau->data = data;
    nouveau->index = index;
    nouveau->next = head->first;
    head->first = nouveau;
}

void afficheValue(element *head) {
    if(head==NULL) {
        exit(EXIT_FAILURE);
    }
    printf("\n voici la liste des elements de la matrice qui ne sont pas nul suivi de leurs index \n");
    node* current = head->first;
    while(current!=NULL) {
        printf("[%d,%d]->",current->data,current->index);
        current = current->next;
    }
    printf("NULL\n");
}

void suppressionInit(element* head) {
    node* current = head->first;

    while(current!=NULL) {
        current = current->next;
    }
    node* q = current;

    free(q);
}

void suppressionListe(element *head) {
    node* current = head->first;
    node *q = current;

    while(current!=NULL) {
        q = current;
        current = current->next;
        free(q);
    }
}
int main(void) {
    element *liste = initialisation();
    int nbr_l = 0,nbr_c = 0;
    printf("Bonjour et Bienvenue pour transformer votre matrice en listes chainee!\n");
    printf("entrez le nombre de lignes : ");
    scanf("%d",&nbr_l);
    printf("\n entrez le nombre de colonne : ");
    scanf("%d",&nbr_c);

    int matrix[nbr_l][nbr_c];
    printf("\n la matrice a ete creee avec le nombre de lignes : %d et le nombre de colonnes : %d \n",nbr_l,nbr_c);
    printf("\n il est temps d'entrer les elements de la matrice \n");
    printf("\n petit rappel en informatique le comptage commence a partir de 0, n'oubliez pas d'ajouter +1 a chaque tour \n");

    for(int i=0;i<nbr_l;i++) {
        printf("entrez les elements de la ligne numero %d \n",i);
        for(int j=0;j<nbr_c;j++) {
            printf("\n entrez l'element numero %d de la ligne %d  : ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("\n les elements ont etes inserer dans la matrix il est temps de les transferer a la liste tout en supprimant les zeros\n");

    for(int i=0;i<nbr_l;i++) {
        for(int j=0;j<nbr_c;j++) {
            if(matrix[i][j]!=0) {
                inserValue(liste,matrix[i][j],j);
            }
        }
    }
    //suppressionInit(liste);
    afficheValue(liste);
    suppressionListe(liste);

    return 0;
}
