#include "board.h"


int score = 0;
int content[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

static void writeScore(int scoreIndex) {
    int scoreIter = score;
    while (scoreIter != 0) {
        board.boardStr[scoreIndex--] = scoreIter % 10 + 48;
        scoreIter = scoreIter / 10;
    }
}
static void putContent()
{
    writeScore(15);
    int firstNumIndex = 22;
	int x, y;
	for (x = 0; x<= 3; x++)
	{
        int lineFirstIndex = firstNumIndex + 23 * x;
		for (y = 0; y<= 3; y++)
		{
            int numIndex = lineFirstIndex + 5 * y;
            int gridLeftIndex = numIndex - 4;
            int num = content[x][y];
            while (num != 0) {
                board.boardStr[numIndex--] = num % 10 + 48;
                num = num / 10;
            }
            while (numIndex > gridLeftIndex) {
                board.boardStr[numIndex--] = ' ';
            }
		}
	}

    strcpy(board.content, board.boardStr);
    strcat(board.content, board.timeStr);
    text_layer_set_text(textLayer, board.content);
} 

static void change(char action)
{
	int x, y;
	switch (action)
	{
		case 'w':
		case '2': break;
		case 'a':
		case '4':
		{
			for (x = 0; x<= 2; x++)
			{
				for (y = x+1; y<= 3; y++)
				{
					content[x][y] += content[y][x];
					content[y][x] = content[x][y]-content[y][x];
					content[x][y] -= content[y][x];
				}
			}
			break;
		}
		case 'd':
		case '6':
		{
			for (x = 0; x<= 2; x++)
			{
				for (y = 0; y<= 2-x; y++)
				{
					content[x][y] += content[3-y][3-x];
					content[3-y][3-x] = content[x][y]-content[3-y][3-x];
					content[x][y] -= content[3-y][3-x];
				}
			}
			break;
		}
		case 's':
		case '8':
		{
			for (x = 0; x<= 1; x++)
			{
				for (y = 0; y<= 3; y++)
				{
					content[x][y] += content[3-x][y];
					content[3-x][y] = content[x][y]-content[3-x][y];
					content[x][y] -= content[3-x][y];
				}
			}
			break;
		}
		// default: exit(0);
	}
}

static int merge()
{
    int flag = 0;
	int x, y;
	for (y = 0; y<= 3; y++)
	{
        int lastX = -1, i = 0;
		int temp[5] = {0};
		for (x = 0; x <= 3; x++)
		{
			if (content[x][y])
			{
				temp[i] = content[x][y];
				content[x][y] = 0;
				i++;
                lastX = x;
			}
		}
        if (i - 1 != lastX) flag++;
		x = 0;
		for (i = 0; i<= 3; i++)
		{
			if (temp[i])
			{
                if (temp[i] == temp[i+1])
                {
                    temp[i] += temp[i+1];
                    score += temp[i];
                    temp[i+1] = 0;
                    flag++;
                }
				content[x][y] = temp[i];
				x++;
			}
		}
	}
    return flag;
}

static int giveNew()
{
	int x, y, i = 0, *temp[16];
	for (x = 0; x<= 3; x++ )
	{
		for (y = 0; y<= 3; y++)
		{
			if (!content[x][y])
			{
				temp[i] = &content[x][y];
				i++;
			}
		}
	}
	if (i != 0) {
		i = rand()%i;
		*temp[i] = (rand()%2+1)*2;
		return 1;
	} else return 0;
}

static int isOver()
{
	int x;
	for (x = 0; x<= 3; x++)
	{
		if ((content[x][0] == content[x][1])||(content[x][1] == content[x][2])||(content[x][2] == content[x][3]))
		{
			return 0;
		}
	}
	return 1;
}


static void begin()
{
	srand(time(NULL));
	giveNew();
	putContent();
}

static void trigger(char action) {
    change(action);
    if ((!merge() || !giveNew()) && isOver()) {
        strcpy(board.boardStr, "\n\n\n\nScore:       0\n\n=====================\n| G A M E   O V E R |\n=====================\n\nTime: ");
        writeScore(17);
    } else {
        change(action);
        putContent();
    }
}

Board board = {
    "", "",
    "\n\nScore:       0\n\n|    |    |    |    |\n\n|    |    |    |    |\n\n|    |    |    |    |\n\n|    |    |    |    |\n\nTime: ",
    begin, trigger
};
