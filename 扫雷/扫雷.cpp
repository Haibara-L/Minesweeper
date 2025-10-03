#include<graphics.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<set>
using namespace std;

void expand(int x, int y, int axis[20][20], IMAGE img[16],int isChoose[20][20])
{
	
	if (x < 0 || y < 0 || x >= 20 || y >= 20)
	{
		return;
	}
	if (isChoose[x][y] != 0)
	{
		return;
	}
	isChoose[x][y] = 1;
	putimage(25 * x, 25 * y, &img[axis[x][y]]);
	if (axis[x][y] == 0)
	{
		expand(x - 1, y, axis, img, isChoose);
		expand(x + 1, y, axis, img, isChoose);
		expand(x, y - 1, axis, img, isChoose);
		expand(x, y + 1, axis, img, isChoose);
		expand(x - 1, y - 1, axis, img, isChoose);
		expand(x - 1, y + 1, axis, img, isChoose);
		expand(x + 1, y - 1, axis, img, isChoose);
		expand(x + 1, y + 1, axis, img, isChoose);
	}
}
int main()
{
	initgraph(500, 500);
	IMAGE img[16];
	loadimage(&img[0], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\0.gif");
	loadimage(&img[1], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\1.gif");
	loadimage(&img[2], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\2.gif");
	loadimage(&img[3], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\3.gif");
	loadimage(&img[4], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\4.gif");
	loadimage(&img[5], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\5.gif");
	loadimage(&img[6], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\6.gif");
	loadimage(&img[7], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\7.gif");
	loadimage(&img[8], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\8.gif");
	loadimage(&img[9], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\9.gif");
	loadimage(&img[10], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\10.gif");
	loadimage(&img[11], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\11.gif");
	loadimage(&img[12], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\12.gif");
	loadimage(&img[13], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\13.gif");
	loadimage(&img[14], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\14.gif");
	loadimage(&img[15], "D:\\����\\vs cpp\\ɨ��\\ɨ��\\ɨ��ͼƬ�ز�\\image\\win.jpg",240,200);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			
			putimage(25 * i, 25 * j, &img[9]);
		}
	}
	int axis[20][20] = { 0 };
	int n;
	cout << "������ը������Ŀ" << endl;
	cin >> n;
	srand((unsigned int)time(NULL));
	int x, y;
	int count = 0;
	do
	{
		x = (rand() % 20);
		y = (rand() % 20);
		if (axis[x][y] == 0)
		{
			axis[x][y] = -1;
			count++;
		}
	} while (count <n&&count<400);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (axis[i][j] != -1)
			{
				int count = 0;
				if (i - 1 >= 0)
				{
					if (axis[i - 1][j] == -1)
					{
						count++;
					}
					if (j - 1 >= 0)
					{
						if (axis[i - 1][j - 1] == -1)
						{
							count++;
						}
					}
					if (j + 1 < 20)
					{
						if (axis[i - 1][j + 1] == -1)
						{
							count++;
						}
					}
				}
				if (j - 1 >= 0)
				{
					if (axis[i][j - 1] == -1)
					{
						count++;
					}
				}
				if (i + 1 < 20)
				{
					if (axis[i + 1][j] == -1)
					{
						count++;
					}
					if (j - 1 >= 0)
					{
						if (axis[i + 1][j - 1] == -1)
						{
							count++;
						}
					}
					if (j + 1 < 20)
					{
						if (axis[i + 1][j + 1] == -1)
						{
							count++;
						}
					}
				}
				if (j + 1 < 20)
				{
					if (axis[i][j + 1] == -1)
					{
						count++;
					}
				}
				axis[i][j] = count;
			}
			
		}
	}
	int isChoose[20][20] = { 0 };
	ExMessage msg = { 0 };
	bool gameover = false;
	while (!gameover)
	{
		int count = 0;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (isChoose[i][j] == 1)
				{
					count++;
				}
			}
		}
		if (count + n == 400)
		{
			break;
		}
		if (peekmessage(&msg, EX_MOUSE))
		{
			
			int x = msg.x / 25;
			int y = msg.y / 25; 
			if (x >= 0 && x < 20 && y >= 0 && y < 20)
			{
				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
				{
					if (isChoose[x][y] == 0)
					{
						if (axis[x][y] == -1)
						{
							gameover = true;
							isChoose[x][y] = 1;
							for (int i = 0; i < 20; i++)
							{
								for (int j = 0; j < 20; j++)
								{
									if (axis[i][j] == -1)
									{
										putimage(25 * i, 25 * j, &img[13]);
									}
									else
									{
										putimage(25 * i, 25 * j, &img[axis[i][j]]);
									}
								}
							}
							break;
						}
						else
						{
							if (axis[x][y] == 0)
							{
								expand(x, y, axis, img, isChoose);
							}
							else
							{
								isChoose[x][y] = 1;
								putimage(25 * x, 25 * y, &img[axis[x][y]]);
							}
						}
					}
					break;
				}
				case WM_RBUTTONDOWN:
				{
					if (isChoose[x][y] == 0)
					{
						putimage(25 * x, 25 * y, &img[10]);
						isChoose[x][y] =2;
					}
					else if (isChoose[x][y] == 2)
					{
						putimage(25 * x, 25 * y, &img[9]);
						isChoose[x][y] =0;
					}
					break;
				}
				case WM_MBUTTONDOWN:
				{
					if (isChoose[x][y] == 0)
					{
						putimage(25 * x, 25 * y, &img[12]);
						isChoose[x][y] = 3;
					}
					else if (isChoose[x][y] == 3)
					{
						putimage(25 * x, 25 * y, &img[9]);
						isChoose[x][y] = 0;
					}
					break;
				}
				}
			}
	    }
	}
	if (gameover)
	{
		cout << "GAME OVER" << endl;
	}
	else
	{
		putimage(130, 150, &img[15]);
	}
	system("pause");
	return 0;
}