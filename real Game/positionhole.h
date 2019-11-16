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

int positionobmap1[10] = { 1500+1600,3200 + 1600,4500 + 1600,5900 + 1600,6500 + 1600,7000 + 1600,7700 + 1600,8000 + 1600,8900 + 1600,10500 + 1600,};
int indexobmap1[10] = { 1,17,1,16,17,17,10,14,17,14};
int typeobmap1[10] = { DOWN,DOWNMOVE ,DOWN ,DOWN ,TOP ,DOWNMOVE ,TOP ,DOWN ,DOWN,DOWN };

int positionobmap2[10] = { 3600,4100,5000,5500,6000,6700,7700,8700,9700,11700 };
int indexobmap2[10] = { 4,4,5,3,5,5,13,4,4,1};
int typeobmap2[10] = { DOWN,TOPMOVE ,DOWN ,TOPMOVE ,TOPMOVE ,DOWN ,DOWN ,DOWN,DOWN,DOWN  };

int positionobmap3[10] = { 3600,4100,5000,5500,6000,6700,7700,8700,9700,11100 };
int indexobmap3[10] = { 14,14,14,14,14,14,5,5,11,12};
int typeobmap3[10] = { DOWN,DOWN ,DOWN ,DOWN ,DOWN ,DOWN ,DOWN ,DOWN,TOP,TOP  };

int positionobmap4[10] = { 2800,3600,4000,5500,6000,6700,7700,8700,9700,11100 };
int indexobmap4[10] = { 14,14,14,14,14,14,14,14,14,14 };
int typeobmap4[10] = { DOWN,DOWN ,DOWN ,DOWN ,DOWN ,DOWN ,DOWN ,DOWN,TOP,TOP };
						