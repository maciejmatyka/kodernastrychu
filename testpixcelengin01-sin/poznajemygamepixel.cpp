#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

const int N = 1000;

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
		t = 0;

		for (int i = 0; i < N; i++)
		{
			sinA[i] = (rand() / float(RAND_MAX));
			sinF[i] = (rand() / float(RAND_MAX))*5.0;
			sinS[i] = (rand() / float(RAND_MAX)-0.5)*10.0;
		}

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
		//for (int x = 0; x < ScreenWidth(); x++)
		//for (int y = 0; y < ScreenHeight(); y++)
		//{
		//}
		//Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
		//Draw(8, 8, olc::Pixel(255, 255, 255));
		//float t = fFrameTimer;

		t += fElapsedTime;

		Clear(olc::Pixel(0, 0, 0));

		int W = ScreenWidth();
		int H = ScreenHeight();

		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < W; i++)
			{
				float x = i / float(W);
				Draw(i, sinA[k] * H * (sin(sinF[k]*t + sinS[k]*2 * 3.141519 * x) + 1) / 2.0, olc::Pixel(k * sinA[N] * 7, k * sinS[N] * 15, k * sinF[N] * 4));
			}
		}
		
		return true;
	}

	float t;
	float sinA[N];
	float sinF[N];
	float sinS[N];

};


int main()
{
	Example demo;
	if (demo.Construct(256, 256, 2, 2))
		demo.Start();

	return 0;
}