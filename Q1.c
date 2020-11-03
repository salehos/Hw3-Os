#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int n = 0;
	int m = 0;
	scanf("%d" , &n);
	scanf("%d" , &m);
	int centers[n][n];
	int dots[m][m];
	int i = 0;
	for(i = 0; i < n ; i++){
		scanf("%d %d" , &centers[i][0], &centers[i][1]);
	}
	for(i = 0 ; i < m; i++){
		scanf("%d %d" , &dots[i][0], &dots[i][1]);
	}
	int min_dots[2];
	for(i = 0 ; i< n; i++){
		int f = fork();
		if(f == 0){
			int min_distance = 9999999;
			int j = 0;
			for (j = 0; j<m; j++){
				if(pow(dots[j][0] - centers[i][0] , 2) + pow(dots[j][1] - centers[i][1] , 2) < min_distance){
					min_distance = pow(dots[j][0] - centers[i][0], 2) + pow(dots[j][1] - centers[i][1] , 2);
					min_dots[0] = dots[j][0];
					min_dots[1] = dots[j][1];
				}
			}
			printf("%d %d : %d %d", min_dots[0], min_dots[1] , centers[i][0] , centers[i][1]);
			printf("\n");
			exit(0);
		}
	}
	for(i=0;i<n;i++)
		wait(NULL);
}
