#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

const int W = 600;
const int H = 200;

class Gra : public olc::PixelGameEngine
{
public:
	Gra()
	{
		sAppName = "Gra";
		t = 0;

		pause = 0;
		x=0.5;
		y=0.5;
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
		//Draw(W/2, H/2, olc::Pixel(255, 255, 255));
		
		static int punkty = 300;

		float x0=0.35,y0=0.35;

		srand(1000);
		char workbuf[2];
		for(int i=0; i<250; i++)
		{
			float r1=(rand()/float(RAND_MAX)-0.5), r2=(rand()/float(RAND_MAX)-0.5), r3=rand()/float(RAND_MAX);
			y = y0 + (0.352+0.3*r3)*sin(t*(2.4+r1*2)+r2*2);
			x = x0 + (0.252+0.4*r2)*sin(t*(3.42-r2*3)+0.13+r3);
			punkty++;
			int a = 255*r3;
			sprintf_s(workbuf,"%c",a);
			
			DrawString(x*W,y*H,std::string(workbuf),olc::Pixel(r1*255, r2*255, r3*255), int(r3*10+1));
		}

		DrawString(0,0.5*H,"olcPixelGameEngine",olc::WHITE, 4);

		return true;
	}


	float t;
	int pause;
	float x;
	float y;
};


int main()
{
	Gra demo;
	if (demo.Construct(W, H, 3, 3))
		demo.Start();

	return 0;
}