#include <stdio.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int labber[101][101];
int nRet;
int x, y;

int main()
{
	int t = 0;

	freopen("input.txt", "r", stdin);
	
	for (int k = 0; k < 10; k++)
	{
		scanf("%d", &t);

		for (int i = 0; i < 100; i++){
			for (int j = 0; j < 100; j++){
				scanf("%d", &labber[i][j]);
				if (labber[i][j] == 2){
					x = j; y = i;
				}
			}
		}
		int index = 0;
		while (1){
			
			if (labber[y][x + 1] && x + 1 < 100){
				index = 2;
				while (1){
					if (labber[y][x + index] == 0){
						x = x + (index - 1);
						break;
					}
					index++;
				}
			}
			else if (labber[y][x - 1] && x - 1 >= 0){
				index = 2;
				while (1){
					if (labber[y][x - index] == 0){
						x = x - (index - 1);
						break;
					}
					index++;
				}
			}
			y--;

			if (y == 0){
				nRet = x;
				break;
			}
		}

		printf("#%d %d\n", t, nRet);

	}

	return 0;
}