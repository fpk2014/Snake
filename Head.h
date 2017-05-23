#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>


#include<stdlib.h>  
#include<conio.h>  

#define SNAKE_Body "¨€" 
#define FOOD  "©ï"
#define WIDE  40
#define HEIGHT 20
#define TRUE 1
#define FALSE 0

typedef struct Snake_Node {
	struct Snake_Node *next;
	int x;
	int y;
} Snake_Node, *Snake_Node_Pointer;

typedef struct Snake {
	Snake_Node_Pointer head;
	Snake_Node_Pointer end;
} Snake, *Snake_Pointer;

typedef struct Food {
	int x;
	int y;
} Food, *Food_Pointer;