#define OLC_PGE_APPLICATION
#include <vector>
#include <random>
#include "olcPixelGameEngine.h"
#include "CVector3.h"

using namespace std;

const int W = 640;
const int H = 480;

// Mersenne Twister
std::mt19937 mt(time(NULL));
std::normal_distribution<float> normal(0.1,0.9);

// klasa pojedynczego dysku
class ball
{
public:
	ball(CVector3 _r, CVector3 _v, float _R) : r(_r), v(_v), R(_R)
	{}
	CVector3 r;
	CVector3 v; 
	float R;		// promien
};
const float DT = 0.04;
const int N = 100;			// ile chcemy kulek
vector<ball> kulki;			// zbiór kulek

void init()
{
	const float D = 0.03;
	for(int i=0; i<N; i++)
	{
		CVector3 r;
		CVector3 v;
		r.x = rand()/(float)RAND_MAX;
		r.y = rand()/(float)RAND_MAX;
		v.x = D*(rand()/(float)RAND_MAX-0.5);
		v.y = D*(rand()/(float)RAND_MAX-0.5);
		//float R = 0.03*(rand()/(float)RAND_MAX);
		float R = 0.01*fabs(normal(mt));		// rozk³ad normalny promieni
		kulki.push_back(ball(r,v,R));
	}
}

void move(float dt)
{
	for(int i=0; i<kulki.size(); i++)
	{
		kulki[i].r = kulki[i].r + dt * kulki[i].v;

		// periodycznoœæ
		if(kulki[i].r.x < 0) kulki[i].r.x = 1+kulki[i].r.x;
		if(kulki[i].r.y < 0) kulki[i].r.y = 1+kulki[i].r.y;
		if(kulki[i].r.x > 1) kulki[i].r.x = kulki[i].r.x-1;
		if(kulki[i].r.y > 1) kulki[i].r.y = kulki[i].r.y-1;
	}
}


class Symulacja : public olc::PixelGameEngine
{
public:
	Symulacja()
	{
		sAppName = "Symulacja";
		t = 0;
		pause = 0;
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		init();

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

		// ruch
		move(DT);

		// rysowanie 
		//for(int i=0; i<kulki.size(); i++)
		//	FillCircle(kulki[i].r.x*W, kulki[i].r.y*H,kulki[i].R*W, olc::WHITE);
		// rysowanie z uwzglêdnieniem periodycznoœci
		for(int i=0; i<kulki.size(); i++)
			FillCircle(kulki[i].r.x*W, kulki[i].r.y*H,kulki[i].R*W, olc::WHITE);
		for(int i=0; i<kulki.size(); i++)
		{
			if(kulki[i].r.x + kulki[i].R > 1)
				FillCircle((kulki[i].r.x-1)*W, kulki[i].r.y*H,kulki[i].R*W, olc::WHITE);
			if(kulki[i].r.y + kulki[i].R > 1)
				FillCircle(kulki[i].r.x*W, (kulki[i].r.y-1)*H,kulki[i].R*W, olc::WHITE);

			if(kulki[i].r.x - kulki[i].R < 0)
				FillCircle((kulki[i].r.x+1)*W, kulki[i].r.y*H,kulki[i].R*W, olc::WHITE);
			if(kulki[i].r.y - kulki[i].R < 0)
				FillCircle(kulki[i].r.x*W, (kulki[i].r.y+1)*H,kulki[i].R*W, olc::WHITE);
		}

		return true;
	}


	float t;
	int pause;
};


int main()
{
	Symulacja demo;
	if (demo.Construct(W, H, 2, 2))
		demo.Start();

	return 0;
}