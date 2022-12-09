// Maze game using tree data structure
#include <stdio.h>
#include <stdlib.h>
    //      A
    //     / \
    //    B   C
    //   /   / \
    //  D   E   H
    //     / \
    //    F   G

// Creating a structure
struct node {
  char item;
  struct node* left;
  struct node* right;
};

// Create a new Node
struct node* createNode(char value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%c", root->item);
  inorderTraversal(root->right);
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, char value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, char value) {
  root->right = createNode(value);
  return root->right;
}

//main function
int main() {
  int k1 = 0;
  FILE*fp; // File Handling
  fp=fopen("game.txt","w");
  int steps=0;
  int score[100];
  int choice;
  int flag=0;
  char final='B';
  struct node* root = createNode('A'); // Creating tree and assigning its value
  struct node*prev = createNode('q');
  struct node*temp1 = createNode('l');
  prev = root;
  temp1 = root;
  insertLeft(root, 'B');
  insertRight(root, 'C');
  insertLeft(root->left, 'D');
  insertLeft(root->right,'E');
  insertLeft(root->right->left,'F');
  insertRight(root->right->left,'G');
  insertRight(root->right,'H');

//players input
int t = 1;
int p;
int  u =0 ;
int player[100];
k1 = 0;
printf("You have to reach at E to win the game \n");
printf("Enter the number of players - \n");
scanf("%d",&p);
int y4 =1;
for(int q2 = p;q2>0;q2--){
    t = 1;
  prev = root;
  root->item = 'A';
  insertLeft(root, 'B');
  insertRight(root, 'C');
  insertLeft(root->left, 'D');
  insertLeft(root->right,'E');
  insertLeft(root->right->left,'F');
  insertRight(root->right->left,'G');
  insertRight(root->right,'H');
    steps = 0;
    
    printf("\nyou are player %d\n",y4);
    

while(t==1){
    // choices to navigate the game
    
    printf("You are at %c",root->item);
    printf("\npress 1 for left and 0 for right and 2 to undo(NOTE- you can use undo once per move) -  ");
    scanf("%d",&choice);
    if(root->left==NULL&& choice==1){
        printf("You lose\n");
        u-=1;
        printf("There is no left of %c\n",root->item);
        t = 0;
        
    }
    else if(root->right==NULL&& choice == 0){
        u-=1;
        printf("You lose\n");
        printf("There is no right of %c\n",root->item);
        t = 0;
       
    }
    else if(choice==1){
        prev = root;
        root = root->left;
        steps+=1;
    }
    else if(choice == 0 ){
        prev = root;
        root=root->right;
        steps+=1;
    }
    else if(root == prev){
        if(root->item=='A'){
            printf("You cannot go back\n");
        }
        else{
        printf("you can use undo once per move\n");
        }
    }
    else if(choice == 2){
        
        root = prev;
        steps+=1;
    }
    if(root->item=='E'){
        printf("you are at E\n");
        printf("you won");
        t =0;
        player[k1] = y4;
        k1+=1;
    }
    
    }
    score[u]=steps;
u+=1;
y4++;

}
int k = 0;
int r = 0;
for(int l = 0;l<u;l++){
    fprintf(fp,"Winner's Scores:"); // Ending scores of players
    fprintf(fp,"\nplayer %d has score %d\n",player[l],score[l]);
    if(r>score[l]){
        r = score[l];
        k = l;
    }
}
// original maze
    fprintf(fp,"This was the maze\n");
    fprintf(fp,"        A\n");
    fprintf(fp,"       / \\ \n");
    fprintf(fp,"      B   C \n");
    fprintf(fp,"     /   / \\ \n");
    fprintf(fp,"    D   E   H \n");
    fprintf(fp,"       / \\  \n");
    fprintf(fp,"      F   G  \n");


//printf("\nplayer %d - with the least number of steps %d",k+1,score[k]); 
}

/*Contributors
Akshat Miglani
Khush Patel
Margesh Modi
Preet Chandak
Nisargi Shah
*/