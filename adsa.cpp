#include<cstdio>
#include<cstring>
using namespace std;
const int direction[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
char map[100][101];
int row;
int col;
int bfs(int r,int c)
{
	int counter=0;
	if('p'==map[r][c])
		++counter;
	map[r][c]='#';
	for(int d=0;d<4;++d)
     {
		int dr=r+direction[d][0];
		int dc=c+direction[d][1];
		if(dr>=0 && dr<row && dc>=0 && dc < col && map[dr][dc] != '#')
		{
			counter += bfs(dr,dc);
		}
	}
	return counter;
}

int main()
{
	while(scanf("%d%d",&row,&col),row!=0 && col!=0)
	{
		for(int i=0;i<row;++i)
		{
			scanf("%s",map[i]);
		}
		int counter=0;
		for(int i=0;i<row;++i)
		{
			for(int k=0; k<col; ++k)
			{
				if(map[i][k]=='d')
				{
					counter += bfs(i,k);
				}
			}
		}
		printf("%d\n",counter);
	}
	return 0;
}
