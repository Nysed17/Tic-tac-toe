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

int check(char mat){ //work in progress function to not make characters overlap

	if (mat == '#'){
		return 1;
	}

	return 0;
}

char* matrix(char* a, char *c){
	
	if (*c == 'x'){  // Char swap
		*c = 'o';
	} else if (*c == 'o'){
		*c = 'x';
	}	
	
	int row;
	int col;
	int checkit;
	printf("Row:");
	scanf("%d", &row);
	printf("Column:");
	scanf("%d", &col);
		
	// Inserting the character into the table

	if (row <= 3 && col <= 3){
		if (row == 1){
			if (col == 1){
				checkit = check(a[0]);
				if (checkit == 1){
					a[0] = *c;
				} else return matrix(a,c);
			} else if (col == 2){
				checkit = check(a[1]);
				if (checkit == 1){
					a[1] = *c;
				} else return matrix(a,c);
			} else if (col == 3){
				checkit = check(a[2]);
				if (checkit == 1){
					a[2] = *c;
				} else return matrix(a,c);
		} else if (row == 2){
				if (col == 1){
				checkit = check(a[3]);
				if (checkit == 1){
					a[3] = *c;
				} else return matrix(a,c);
			} else if (col == 2){
				checkit = check(a[4]);		
				if (checkit == 1){
					a[4] = *c;	
				} else return matrix(a,c);
			} else if (col == 3){
				checkit = check(a[5]);
				if (checkit == 1){
					a[5] = *c;
				} else return matrix(a,c);
		} else if (row == 3){
				if (col == 1){
				checkit = check(a[6]);
				if (checkit == 1){
					a[6] = *c;
				} else return matrix(a,c);
			} else if (col == 2){
				checkit = check(a[7]);
				if (checkit == 1){
					a[7] = *c;
				} else return matrix(a,c);
			} else if (col == 3){
				checkit = check(a[8]);
				if (checkit == 1){
					a[8] = *c;	
				} else return matrix(a,c);
			}
		}
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
