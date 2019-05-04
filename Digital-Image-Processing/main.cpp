#include <stdio.h>
#include <iostream>
#include "Bitmap.h"
using namespace std;
//Test
int main()
{
	char *inFileName = (char*)malloc(100*sizeof(char));
	const char *outFileName= "out.bmp";
	Bitmap bmp, outbmp;
	printf("Enter file path:");
	scanf("%s", inFileName);
	int option;
	char next = 'Y';
	if(LoadBitmap(inFileName, bmp))
	{
		printf("Image Size: %dx%d\n", bmp.width, bmp.height);
		while (next == 'Y' || next == 'y')
		{
			printf("Choose an option:\n1.Black White\n2.AdjustBrightess\n3.reverse.\n4.Zoomimage\n");
			scanf("%d", &option);
			switch (option)
			{
			case 1:
				
				BlackWhite(bmp);
				break;
			case 2:
				AdjustBrightness(bmp, 2);
				break;
			case 3:
				int k;
				printf("1.Dao nguoc theo be doc.\n2.dao nguoc theo be ngang\n");
				scanf("%d", &k);
				reverse_image(bmp,k);
				break;
			case 4:
				int m;
				printf("Nhap do zoom: ");
				scanf("%d", &m);
				zoomimage(bmp, outbmp, m);
				break;
			default:
				printf("Wrong command!");
				break;
			}
			if (!SaveBitmap(outFileName, bmp))
				printf("Can not save the bitmap file!!!\n");
			#ifdef _WIN32
				system("start out.bmp");
			#else
				system("open out.bmp");
			#endif
			printf("Would you like to continue?(Y/N)");
			scanf("\n%c", &next);
			#ifdef _WIN32
				system("cls");
			#else
				system("clear");
			#endif
		}
		DisposeBitmap(bmp);
	}
	else
		printf("Can not load the bitmap file!!!\n");
	
	printf("Bye!\n");
	
	return 0;
}
