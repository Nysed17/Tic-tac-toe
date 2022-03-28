#include <stdio.h>
#include <stdlib.h>

void print_mat(char a[3][3]){ // Print of the table
	for (int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}

void logic(char* a, char *c, int *gameover){
	
	// Horizontal win
	if (a[0] == *c && a[1] == *c && a[2] == *c){
		*gameover = 1;
	} else if (a[3] == *c && a[4] == *c && a[5] == *c){
		*gameover = 1;
	} else if (a[6] == *c && a[7] == *c && a[8] == *c){
		*gameover = 1;
	}

	// Vertical win
	if (a[0] == *c && a[3] == *c && a[6] == *c){
		*gameover = 1;
	} else if (a[1] == *c && a[4] == *c && a[7] == *c){
		*gameover = 1;
	} else if (a[2] == *c && a[5] == *c && a[8] == *c){
		*gameover = 1;
	}

	// Diagonal win
	if (a[0] == *c && a[4] == *c && a[8] == *c){
		*gameover = 1;
	} else if (a[2] == *c && a[4] == *c && a[6] == *c){
		*gameover = 1;
	}
} 

char* matrix(char* a, char *c){
	
	if (*c == 'x'){  // Char swap
		*c = 'o';
	} else if (*c == 'o'){
		*c = 'x';
	}	
	
	int row;
	int col;
	printf("Row:");
	scanf("%d", &row);
	printf("Column:");
	scanf("%d", &col);
		
	// Inserting the character into the table

	if (row <= 3 && col <= 3){
	if (row == 1){
		if (col == 1){
			a[0] = *c;
		} else if (col == 2){
			a[1] = *c;
		} else if (col == 3){
			a[2] = *c;
		}
	} else if (row == 2){
		if (col == 1){
			a[3] = *c;
		} else if (col == 2){
			a[4] = *c;
		} else if (col == 3){
			a[5] = *c;
		}
	} else if (row == 3){
		if (col == 1){
			a[6] = *c;
		} else if (col == 2){
			a[7] = *c;
		} else if (col == 3){
			a[8] = *c;
		}
	}
	} else matrix(a,c);

	return a;
}

int main(){
	system("clear");
	char mat[3][3] = {{'#','#','#'},
										{'#','#','#'},
										{'#','#','#'}}; // Blank tab
	char c = 'o';
	char g = 'x';
	int gameover = 0;
		
	while (gameover != 1){
		printf("\nTocca a: %c\n", g);
		if (gameover == 1){
			printf("The winner is: %c", c);
			exit(0);
		}
		matrix(&mat[0][0], &c);
		if (g == 'x'){
			g = 'o';
		} else g = 'x';
		print_mat(mat);	
		logic(&mat[0][0], &c, &gameover);
	}
	if (gameover == 1){
		printf("The winner is: %c", c);
	}
	return 0;
}
