
#include <iostream>
#include <math.h>
#include <time.h>
#include "windows.h"
using namespace std;
char Map[90][90] = {
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
	"$                                               $",
	"$                        % %                    $",
	"$                        % %                    $",
	"$               % % % % % % % % % % %           $",
	"$            % % % % % % % % % % % % % %        $",
	"$                   % %     % %                 $",
	"$                                               $",
	"$                                               $",
	"$   %           %        %       %         %    $",
	"$                      %   %                    $",
	"$                                               $",
	"$   %            %       ?      %           %   $",
	"$ %   %        %   %          %   %       %  %  $",
	"$                                               $",
	"$                                               $",
	"$                                               $",
	"$     #######        #######        #######     $",
	"$                       X                       $",
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
};

bool endgame = false;
int gamespeed = 5;
int randnum;
int maxhealth = 100;
int yourhealth = maxhealth;
int maxbosshealth = 1000;
int bosshealth = maxbosshealth;



int main()
{
	srand(time(0));
	system("color 02");
	while (!endgame)
	{
		srand(time(0));
		system("cls");
		for (int y = 0; y<21; y++)
		{
			cout << Map[y] << endl;
		}
		cout << "Player Health:\n" << yourhealth << "/" << maxhealth << endl;
		cout << "BOSS Health:" << bosshealth << "/" << maxbosshealth << endl;
		for (int y = 0; y<21; y++)
		{
			for (int x = 0; x< 51; x++)
			{
				switch (Map[y][x])
				{
				case 'X':
					if (GetAsyncKeyState(VK_LEFT) != 0)
					{
						int newPosX = x - 1;
						switch (Map[y][newPosX])
						{
						case ' ':
							Map[y][x] = ' ';
							x--;
							Map[y][newPosX] = 'X';

							break;
						}

					}

					if (GetAsyncKeyState(VK_RIGHT) != 0)
					{
						int newPosX = x + 1;
						switch (Map[y][newPosX])
						{
						case ' ':
							Map[y][x] = ' ';
							x++;
							Map[y][x] = 'X';

							break;
						}

					}
					if (GetAsyncKeyState(VK_SPACE) != 0)
					{
						y--;
						Map[y][x] = '^';
					}
					break;

				case '^':

					Map[y][x] = ' ';
					y--;

					if (Map[y][x] != '$' && Map[y][x] != '%' && Map[y][x] != '?')
					{
						Map[y][x] = '^';
					}
					else if (Map[y][x] == '%')
					{
						Map[y][x] = ' ';
					}
					else if (Map[y][x] == '?')
					{
						bosshealth -= 25;
						if (bosshealth <= 0)
						{
							Map[y][x] = ' ';

						}
					}
					break;

				case '%':

					randnum = rand() % 25 + 1;

					if (randnum == 1)
					{
						y++;
						Map[y][x] = '*';
					}
					break;

				case '?':


					randnum = rand() % 25 + 1;

					if (randnum == 0.2)
					{
						y++;
						Map[y][x] = '0';
					}
					break;

				case '*':

					Map[y][x] = ' ';
					y++;

					if (Map[y][x] != '$' && Map[y][x] != 'X' && Map[y][x] != '?')
					{
						Map[y][x] = '*';
					}
					else if (Map[y][x] == 'X')
					{
						yourhealth -= 25;
					}
				
				case'0':

					Map[y][x] = ' ';
					y++;

					if (Map[y][x] != '$' && Map[y][x] != 'X' && Map[y][x] != '?')
					{
						Map[y][x] = '0';
					}


					break;
				}
			}
			if (yourhealth <= 0)
			{
				endgame = true;
			}
			Sleep(gamespeed);
		}

	}
	cout << "\n Game Over" << endl;
	system("pause");
}



