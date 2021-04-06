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

		/*for (int i = 0; i < N; i++)
		{
			sinA[i] = (rand() / float(RAND_MAX));
			sinF[i] = (rand() / float(RAND_MAX))*5.0;
			sinS[i] = (rand() / float(RAND_MAX)-0.5)*10.0;
		}*/

		randomize();

	}



public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}


	void randomize()
	{
		for (int i = 0; i < 5; i++)
		{
			par[i] = 10 * (rand() / float(RAND_MAX) - 0.5);
			par2[i] = 2.0 * (rand() / float(RAND_MAX) - 0.5);

		}
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		t += fElapsedTime;

		Clear(olc::Pixel(0, 0, 0));

		int W = ScreenWidth();
		int H = ScreenHeight();

		// czy wciœniêta strza³ka w lewo
		if (GetKey(olc::Key::LEFT).bPressed)
		{
			randomize();
		}




		for (int j = 0; j < H; j++)
		{
			for (int i = 0; i < W; i++)
			{
				float x = 2.0 * (i / float(W) - 0.5);
				float y = 2.0 * (j / float(H) - 0.5);
				//int r = 128*(2.0*sin(y * 3.14 * par[0] * sin(t * par2[0]*x+1.0)+ x * 3.14 * par[3] * sin(t * par2[3]*x+5.0) - 3.55)+1);
				//int g = 128*(sin(y * 3.14 * par[1] * sin(t * par2[1]*y)+ x * 3.14 * par[4] * sin(t * par2[4]*x) + 1.53)+1);
				//int b = 128*(3.0*sin(2*y * 3.14 * par[2] * sin(t * par2[2]*x+5.0)+ x * 3.14 * par[5] * sin(t * par2[5]*y) + 2.52)+1);

				int r = 128 * (x*sin(x * 3.14 * 2.0 * par[0] * sin(t * 2.0 * par[1] / 5.0 + y*t * 3.1 * par2[0])) + 1);
				int g = 128 * (sin(x * 3.14 * 2.0 * par[2] * cos(t * 2.0 * par[2] / 5.0 + t * 2.1 * par2[1])) + 1);
				int b = 128 * (sin(x * 3.14 * 2.0 * par[1] * sin(t * 2.0 * par[3] / 5.0 + x*t * 2.1 * par2[2])) + 1);

				Draw(i, j, olc::Pixel(r, g, b));
			}
		}
		
		return true;
	}


	float t;
	float par[5];		// -10;10
	float par2[5];		// -10;10

};


int main()
{
	Example demo;
	if (demo.Construct(256, 256, 4, 4))
		demo.Start();

	return 0;
}