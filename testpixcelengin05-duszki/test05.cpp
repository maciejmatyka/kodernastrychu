#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
const int W = 200;
const int H = 200;

class Gra : public olc::PixelGameEngine
{
public:
	Gra()
	{
		sAppName = "Gra";
		t = 0;
		s.LoadFromFile("characterboy.png");
		//s.LoadFromFile("chest2.png");
		pause = 0;
		pos = olc::vi2d(W/2, 0);
		vel = olc::vi2d(0, 0);
		gy = -2.0;
		dt = 0.05;
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
			vel.y = 10.0;
		}

		if (GetKey(olc::Key::ESCAPE).bPressed)
			quick_exit(0);


		
		//rysowanie duszka
		olc::vf2d p2 = pos;
		p2.y =  H/8- p2.y;
		DrawSprite(p2, &s, 1, 0);
		//pos.y += 0.05;

		// fizyka
		// ca³kowanie metod¹ Euler
		vel = vel + olc::vf2d(0, gy) * dt;		// przyspieszenie

		if (pos.y + vel.y * dt < 0)					// czy po przesunieciu wychodzi poza powierzchnie
		{
			vel.y = 0;
		}

		pos = pos + vel * dt;	
		// koniec fizyki tutaj			

		// powierzchnia
		for (int i = 0; i < W; i += 5)
		{

			Draw((abs(int(i+t*20)))%W, H-H / 7.5);
		}


		return true;
	}

	float dt;
	float gy;
	olc::vf2d pos;
	olc::vf2d vel;
	olc::Sprite s;
	float t;
	int pause;
};


int main()
{
	Gra demo;
	if (demo.Construct(W, H, 4, 4))
		demo.Start();

	return 0;
}