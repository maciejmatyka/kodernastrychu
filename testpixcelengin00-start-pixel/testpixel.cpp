#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

const int W = 100;
const int H = 100;

class Gra : public olc::PixelGameEngine
{
public:
	Gra()
	{
		sAppName = "Gra";
		t = 0;

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
		}

		if (GetKey(olc::Key::ESCAPE).bPressed)
			quick_exit(0);


		// obs³uga myszy
		if (GetMouse(0).bPressed)
		{

			pause = 1;
		}

		if (GetMouse(0).bHeld)
		{
			//std::cout << GetMouseX() << " " << GetMouseY() << std::endl;	
		}

		if (GetMouse(0).bReleased)
			pause = 0;

		// petla rysujaca
		Draw(W/2, H/2, olc::Pixel(255, 255, 255));
		

		return true;
	}


	float t;
	int pause;
};


int main()
{
	Gra demo;
	if (demo.Construct(W, H, 8, 8))
		demo.Start();

	return 0;
}