#include <stdio.h>
#include <stdlib.h>

short int grid[9][9];

void scangrid()
{
	short int row, col;
	for(row = 0; row < 9; row++)
		for(col = 0; col < 9; col++)
			scanf("%hd", &grid[row][col]);
}

void printgrid()
{
	register short int row, col;
	for(row = 0; row < 9; row++)
	{
		for(col = 0; col < 9; col++)
			printf("%hd ", grid[row][col]);
		printf("\n");
	}	
}

int check(short int row, short int col, short int n)
{
	register short int r;
	for(r = 0; r < 9; r++)
	{
		if(grid[row][r] == n)
			return 0;
		if(grid[r][col] == n)
			return 0;
	}
	register short int c;
	row = (row/3)*3;
	col = (col/3)*3;
	for(r = row; r < row + 3; r++)
		for(c = col; c < col + 3; c++)
			if(grid[r][c] == n)
				return 0;
	return 1;
}

void solve(short int row, short int col)
{
	if(grid[row][col])
		(col < 8)? 	solve(row, col + 1) : solve(row + 1, 0);
	else if(row < 9)
	{
		register int n;
		for(n = 1; n < 10; n++)
		{
			if(check(row, col, n))
			{
				grid[row][col] = n;		
				(col < 8)? 	solve(row, col + 1) : solve(row + 1, 0);				
			}
		}
		grid[row][col] = 0;
	}
	else
	{
		printgrid();
		exit(0);		
	}
}

int main()
{
	scangrid();
	solve(0, 0);
	return 0;
}