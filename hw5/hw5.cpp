#include <iostream>
#include <string>

using namespace std;


class Car
{
	string name;
	string body;
	int engine;
	int wheels;
	string kpp;
public:
	void SetName(string name)
	{
		this->name = name;
	}
	string GetName()
	{
		return this->name;
	}
	void SetBody(string body)
	{
		this->body = body;
	}
	string GetBody()
	{
		return this->body;
	}
	void SetEngine(int engine)
	{
		this->engine = engine;
	}
	int GetEngine()
	{
		return this->engine;
	}
	void SetWheels(int wheels)
	{
		this->wheels = wheels;
	}
	int GetWheels()
	{
		return this->wheels;
	}
	void SetKPP(string kpp)
	{
		this->kpp = kpp;
	}
	string GetKPP()
	{
		return this->kpp;
	}
	void ShowCar()
	{
		cout << "Car name: " << name << "\nFrame: " << body << "\nEngine (l. s): " << engine << "\nWheels (R): " << wheels << "\nKpp: " << kpp << "\n\n";
	}
};

class CarBuilder abstract
{
protected:
	Car car;
public:
	Car GetCar()
	{
		return car;
	}
	virtual void BuildName() abstract;
	virtual void BuildBody() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildWheels() abstract;
	virtual void BuildKPP() abstract;
};


class DaewooLanosCar : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Daewoo Lanos");
	}
	void BuildBody() override
	{
		car.SetBody("Sedan");
	}
	void BuildEngine() override
	{
		car.SetEngine(98);
	}
	void BuildWheels() override
	{
		car.SetWheels(13);
	}
	void BuildKPP() override
	{
		car.SetKPP("5 Manual");
	}
};
class FordProbeCar : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Ford Probe");
	}
	void BuildBody() override
	{
		car.SetBody("Coupe");
	}
	void BuildEngine() override
	{
		car.SetEngine(160);
	}
	void BuildWheels() override
	{
		car.SetWheels(14);
	}
	void BuildKPP() override
	{
		car.SetKPP("4 Auto");
	}
};
class UAZPatriotCar : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("UAZ Patriot");
	}
	void BuildBody() override
	{
		car.SetBody("Station wagon");
	}
	void BuildEngine() override
	{
		car.SetEngine(120);
	}
	void BuildWheels() override
	{
		car.SetWheels(16);
	}
	void BuildKPP() override
	{
		car.SetKPP("4 Manual");
	}
};
class HyundaiGetzCar : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Hyundai Getz");
	}
	void BuildBody() override
	{
		car.SetBody("Hatchback");
	}
	void BuildEngine() override
	{
		car.SetEngine(66);
	}
	void BuildWheels() override
	{
		car.SetWheels(13);
	}
	void BuildKPP() override
	{
		car.SetKPP("4 auto");
	}
};

class Shop
{
	CarBuilder* carBuilder;
public:
	void SetCarBuilder(CarBuilder* cb)
	{
		carBuilder = cb;
	}
	Car GetCar()
	{
		return carBuilder->GetCar();
	}
	void ConstructCar()
	{
		carBuilder->BuildName();
		carBuilder->BuildBody();
		carBuilder->BuildEngine();
		carBuilder->BuildWheels();
		carBuilder->BuildKPP();
	}
};

void client(CarBuilder* builder)
{
	Shop shop;
	shop.SetCarBuilder(builder);
	shop.ConstructCar();
	Car car = shop.GetCar();
	car.ShowCar();
}

void main()
{
	CarBuilder* builder = new DaewooLanosCar();
	client(builder);
	delete builder;

	builder = new FordProbeCar();
	client(builder);
	delete builder;

	builder = new UAZPatriotCar();
	client(builder);
	delete builder;

	builder = new HyundaiGetzCar();
	client(builder);
	delete builder;

	system("pause");
}