#include"AllInOne.h"
int positionstart[4][4] = {
	{2000,5000,9000,50000},
	{3000,5200,8900,50000},
	{2000,5300,9000,50000},
	{2000,3100,6000,50000}	
};
int lengthhole[4][4]  = {
	{500,800,700,0},
	{500,800,700,0},
	{500,850,750,0},
	{800,900,900,0}
};

int positionobmap1[10] = { 1500+1600,3200 + 1600,4500 + 1600,5900 + 1600,6500 + 1600,7000 + 1600,7700 + 1600,8000 + 10600,8900 + 1600,10500 + 1600,};
int indexobmap1[10] = {10,5,19,5,10,21,19,5,5,18};
int typeobmap1[10] = { TOPMOVE,DOWNMOVE ,DOWN ,DOWN ,TOPMOVE ,TOPMOVE ,DOWNMOVE,DOWN ,DOWNMOVE,DOWN };

int positionobmap2[10] = { 3600,4100,5300,6000,6700,8000,9000,9800,10000,12200 };
int indexobmap2[10] = { 6,8,5,3,5,5,13,8,8,1};
int typeobmap2[10] = { DOWN,TOPMOVE ,DOWNMOVE ,DOWN,DOWNMOVE ,DOWN ,DOWN ,TOPMOVE,TOPMOVE,DOWN };

int positionobmap3[14] = { 3500,4180,5000,5300,6000,6200,7800,8700,9300,9500,9700,11710,11900,12100 };
int indexobmap3[14] = { 12,12,12,2,9,9,12,15,9,9,9,9,9,9};
int typeobmap3[14] = { DOWN,DOWNMOVE ,DOWN ,DOWN ,TOPMOVE ,TOPMOVE ,DOWN ,DOWNMOVE,TOPMOVE,TOPMOVE,TOPMOVE,TOPMOVE,TOPMOVE,TOPMOVE };


int positionobmap4[13] = { 2800,8000,4000,6000,6500,6700,7300,9300,9200,9800,10500,11000,11700 };
int indexobmap4[13] = { 14,14,14,16,13,16,21,5,5,13,10,14,14 };
int typeobmap4[13] = { DOWN,DOWNMOVE ,DOWNMOVE ,TOPMOVE ,DOWN ,DOWN ,TOPMOVE,DOWN,DOWN ,DOWNMOVE,TOPMOVE,DOWN,DOWN };

/*int positionobmap4[10] = { 2800,8000,4000,6000,6500,6700,7300,10500,11000,11700 };
int indexobmap4[10] = { 14,14,14,16,13,16,21,10,14,14 };
int typeobmap4[10] = { DOWN,DOWNMOVE ,DOWNMOVE ,TOPMOVE ,DOWN ,DOWN ,TOPMOVE ,TOPMOVE,DOWN,DOWN };*/
						