#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

const int W = 300;
const int H = 50;
const int LX = W;
const int LY = H;
int stan[2][LX][LY];
int c = 1;

void init(int _c)
{
	float  p = 0.2+0.5*rand() / float(RAND_MAX);

	for (int i = 0; i < LX; i++)
		for (int j = 0; j < LY; j++)
		{
			if (rand() / (float)RAND_MAX < p)
				stan[_c][i][j] = 1;
			else
				stan[_c][i][j] = 0;
		}
}


int suma(int _c, int i, int j)
{
	int ip, im, jp, jm;
	if (i < LX - 1) ip = i + 1; else ip = 0; // warunki cykliczne
	if (i > 0) im = i - 1; else im = LX - 1;
	if (j < LY - 1) jp = j + 1; else jp = 0;
	if (j > 0) jm = j - 1; else jm = LY - 1;

	return stan[_c][ip][j] + stan[_c][im][j] + stan[_c][i][jp] + stan[_c][i][jm] +
		stan[_c][ip][jp] + stan[_c][im][jm] + stan[_c][im][jp] + stan[_c][ip][jm];
}

void gameoflife(int _c)
{
	for (int i = 0; i < LX; i++)
		for (int j = 0; j < LY; j++)
		{
			int s = suma(_c, i, j);
			//1. Any live cell with two or three live neighbours survives.

			if (stan[_c][i][j] && (s == 2 || s == 3))
				stan[1 - _c][i][j] = 1;
			else
				if (!stan[_c][i][j] && (s == 3))
					stan[1 - _c][i][j] = 1;
				else
					stan[1 - _c][i][j] = 0;

			//2. Any dead cell with three live neighbours becomes a live cell.
			//3. All other live cells die in the next generation.Similarly, all other dead cells stay dead.
		}
}


class GOL : public olc::PixelGameEngine
{
public:
	GOL()
	{
		sAppName = "GOL";
		t = 0;

		init(c);
		pause = 0;
	}



public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}



	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		t += fElapsedTime;

		Clear(olc::Pixel(0, 0, 0));

		int W = ScreenWidth();
		int H = ScreenHeight();

		// czy wciœniêta strza³ka w lewo
		if (GetKey(olc::Key::SPACE).bPressed)
		{
			init(c);
		}

		if (GetKey(olc::Key::ESCAPE).bPressed)
			quick_exit(0);


		// obs³uga myszy
		if (GetMouse(0).bPressed)
		{
			for (int i = 0; i < LX; i++)
				for (int j = 0; j < LY; j++)
					stan[0][i][j] = stan[1][i][j] = 0;

			pause = 1;
		}

		if (GetMouse(0).bHeld)
		{
			//std::cout << GetMouseX() << " " << GetMouseY() << std::endl;
			
			stan[c][GetMouseX()][GetMouseY()] = 1;
		}

		if (GetMouse(0).bReleased)
			pause = 0;

		// petla rysujaca
		for (int j = 0; j < H; j++)
		{
			for (int i = 0; i < W; i++)
			{
				int r, g, b;
				//
				r = g = b = stan[c][i][j] * 255;
				Draw(i, j, olc::Pixel(r, g, b));
			}
		}

		// algorytm
		if (!pause)
		{
			gameoflife(c);
			c = 1 - c;
		}

		return true;
	}


	float t;
	int pause;
};


int main()
{
	GOL demo;
	if (demo.Construct(W, H, 8, 8))
		demo.Start();

	return 0;
}