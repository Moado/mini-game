#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

struct point {
	int x = -1;
	int y = -1;
};

// Override base class with your custom functionality
class Example : public olc::PixelGameEngine
{
private:
	std::vector<point> points;

public:
	Example()
	{
		// Name your application
		sAppName = "Example";

		point p1 = { 24, 65 };
		point p2 = { 125, 175 };
		points.push_back(p1);
		points.push_back(p2);
		for (int i = 0; i < 20; i++)
		{
			point p = { rand() % 256, rand() % 256 };
			points.push_back(p);
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
		// Called once per frame, draws random coloured pixels		
		for (auto p : points) {
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					Draw(p.x+i, p.y+j, olc::Pixel(olc::RED));
		}

		return true;
	}
};

int main()
{
    Example demo;
    if (demo.Construct(256, 240, 4, 4))
        demo.Start();
    return 0;
}
