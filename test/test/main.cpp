#include <iostream>
#include "ref.h"
#include <string>
using string = std::string;
enum PSpeed 
{
	three = 3, four, five
};
class GStat
{
private:
	 mutable int PFPS;
public:
	float PLVL;
	string PNames[3] = { "Elliot; ", "Satoshi, ", "Milka; " };
	GStat()
		:PFPS(60), PLVL(0){}
	GStat(float PLVLRef)
		:PFPS(60), PLVL(PLVLRef){}
	const void PFPSView() const
	{
		PFPS++;
			std::cout<<std::endl<<"FPS = " << PFPS << std::endl;
	}
};
class GSText
{
private:
	const int switcher = 1;
public:
	string GTVar;
	explicit GSText(string GTVRef)
		:GTVar(GTVRef){}
	const void GSTFunc() const
	{
		if (switcher > 0)
		{
			std::cout << GTVar<<std::endl << std::endl;
		}
		else
			text("[ERROR] : something wrong!");
	}
	~GSText()
	{
		GTVar = "";
	}
};  
class IText 
{
	private:
		const string NOICText;
	public:
	IText(const string& NOICTRef)
	:NOICText(NOICTRef){}
	IText()
		:NOICText("No Inventory"){}
	string GText() const { return NOICText; }
};
struct PNTStruct:public GStat
{
	static string PNText;
	PNTStruct()
	{
		PNText = "";
	}
	static const void PNTFun()
 	{
		std::cout <<PNText;
	}
};
class PMove: public GStat
{
public:
	float PLVLRef, xa, ya, result, X, Y;
	float XCoord[10];
	float YCoord[10];
	int PLoop;
	int& IRef = PLoop;
	PMove()
		:XCoord{ 0,0,0,0,0,0,0,0,0,0 }, result(0.0f)
	{
		IRef=0;
		xa = PLVL > 0 && PLVL < 100 ? PLVL == 0 ? 0 : PLVL + 6 : 0;
		ya = PLVL > 0 && PLVL < 100 ? PLVL == 0 ? 0 : PLVL + 6 : 0;
	}
	PMove(float PLVLRef)
		:GStat(PLVLRef), xa(0.0f), ya(0.0f), result(0)
	{
		xa = PLVL > 0 && PLVL < 100 ? PLVL == 0 ? 0 : PLVL + 6 : 0;
		ya = PLVL > 0 && PLVL < 100 ? PLVL == 0 ? 0 : PLVL + 6 : 0;
	}
	PMove(float x,float y)
		:xa(0.0f),ya(0.0f),result(0),X(x),Y(y)
	{
		xa = PLVL > 0 && PLVL < 100 ? PLVL == 0 ? 0 : PLVL + 6 : 0;
		ya = PLVL > 0 && PLVL < 100 ? PLVL == 0 ? 0 : PLVL + 6 : 0;
	}
	PMove summ(PMove& other)
	{
		return PMove(X + other.X, Y + other.Y );
	}
	PMove operator+(PMove& other)
	{
		return summ(other);
	}
	bool operator==(PMove& other)
	{
		return X == other.X && Y == other.Y;
	}
	bool operator!=(PMove& other)
	{
		return !(*this == other);
	}
	void pmFunc()
	{
	}
};
struct PStat :public PMove
{
	const void PName()
	{
		std::cout<<PNames[0]<<std::endl;
	} 
};
class Printable : public GStat
{
public:
	virtual string CName() = 0;
};
	class EText :public Printable
{
public:
	string CName() override { return "side characters names: "; }
};
	class VFun :public Printable
	{
	public:
		string CName() override { return PNames[1]; }
	};
	class Player :public VFun
	{
	public:
		string CName() override { return PNames[2]; }
	};
void print(Printable* CNTag) 
{
	std::cout << CNTag->CName();
}
void PNOICText(const IText& itext)
{
	std::cout<<std::endl<<itext.GText()<<three<<std::endl;
}
string PNTStruct::PNText;		
int main() 
{
	GSText gstext("Game statistics: ");
	//GSText gstext2;
	//gstext.GTVar = "Game statistics: ";
	//gstext2.GTVar= "";
	static int inv = three;
	PNTStruct::PNText = "Player name: ";
	PStat p0;
	GStat gstat;
	IText it("number of inventory cells: ");

	gstext.GSTFunc();
	//gstext2.GSTFunc();
	PNTStruct::PNTFun(); // Player Name Text Function
	p0.PName();
	std::cout << "" << std::endl;
	EText* e;
	{
		EText* et = new EText();
		e = et;
		print(et);
	}
	VFun* v;
	{
		VFun* vf = new VFun();
		v = vf;
		print(vf);
	}
	Player* p;
	{
		Player* p1 = new Player();
		p = p1;
		print(p1);
	}
	std::cout << "" << std::endl;
	PNOICText(it);
	PMove pm;
	PMove position(1.0f, 1.0f);
	PMove pLVL(59.0f);
	PMove speed(pLVL.PLVL, pLVL.PLVL);
	PMove result1 = position.summ(pLVL);
	PMove result2 = position + pLVL;

	std::cout << std::endl << "Player LVL: " << pLVL.PLVL << std::endl;


	for (pm.IRef=0; pm.IRef < 5; pm.IRef++)
	{
			/*position.X += pLVL.xa;
			position.Y += pLVL.ya;*/
			pm.XCoord[pm.IRef] = position.X;
		pm.YCoord[pm.IRef] = position.Y;
		if (result1 == result2)
		{
			if (pm.IRef > 0)
				continue;
			else
				std::cout << std::endl << "speed test: " << std::endl << std::endl;
			std::cout << result2/*pm.XCoord[pm.IRef] << ", " << pm.YCoord[pm.IRef]*/ << std::endl;
		}
	}
	pm.result = (pLVL.xa + pLVL.ya) / 2;
	if (pLVL.xa == 0)
		std::cout << std::endl << "[ERROR]: wrong LVL" << std::endl;
	else if (pLVL.ya == 0)
		std::cout << std::endl << "[ERROR]: wrong LVL" << std::endl;
	if (pm.result < 500)
		std::cout << std::endl << "SLOW SPEED!" << std::endl;
	else
		std::cout << std::endl << "FAST SPEED!" << std::endl;
	std::cout << std::endl << "X speed = " << pLVL.xa << " coord/op" << std::endl;
	std::cout << "Y speed = " << pLVL.ya << " coord/op" << std::endl;
	pm.pmFunc();
	gstat.PFPSView();
std::cin.get();
delete e;
delete v;
delete p;
}