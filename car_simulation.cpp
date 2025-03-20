//Heba


#include <iostream>
#include <chrono>
#include <thread>

class Car

{
	private:
		
	int year;
	
	std::string make;
	
	std::string model;
	
	int speed;
	
	bool carOn;
	
	
	float gallons;
	
	public:
		
		Car(int year,std::string make,std::string model )
		{
			speed =0;
			
			gallons = 10.00;
		}
	
	int getYear(){return year;}
	
	std::string getMake(){return make;} 
	std::string getModel(){return model;} 

	int getSpeed(){return speed;}
	float getGallons(){return  gallons;}
	
	void accelerate()
	{
		speed +=5;
		
		gallons-=0.5;
		
	}
	
	void brake()
	{
		speed-=5;
		gallons-=0.2;
	}
	
	void fillUp()
	{
		gallons +=5;
		
		if(gallons >=22)
		{
			gallons=22;
			
			std::cout<<"\nCar is now full of gas";
			
		}		
		
	}
	
	void startCar()
	{
		 carOn = true;
	}
	
	void shutOff()
	{		 
		 if (speed ==0)
		 {
		 	carOn=false;
		 }
	}
	
	
};


int main()
{
	int option;
	
	struct Car myCar(2020,"Ford","Escape");
	
do 
{
	std::cout<<"\nMenu: \n 1) Start Car\n 2) Accelerate\n 3) Brake\n 4) Shutoff Car\n 5) Fill Up\n";
	std::cout<<"\n Choose 0 to quit.";
	std::cout<<"\n Please choose an option from the menu: ";
	
	std::cin>>option;
	
	while (option !=5 && option !=4 && option !=3  && option !=2 && option !=1 && option !=0)
	{
		std::cout<<"\nError, enter a number between 1-5 from the menu.";
		std::cout<<"\nMenu: \n 1) Start Car\n 2) Accelerate\n 3) Brake\n 4) Shutoff Car\n 5) Fill Up\n";
		std::cout<<"\n Choose 0 to quit.";
		std::cout<<"\n Please choose an option from the menu: ";
		
		std::cin>>option;
		
	}
	
	if (option ==1)
	{
		
		 
		
			myCar.startCar();
			
		
		
	}
	
	if (option ==2)
	{
		if (myCar.getGallons() == 0)
		{
			std::cout<<"\nCan not accelerate without gas";
			myCar.shutOff();
		}
		else 
		{
				myCar.accelerate();

		}
		
	}
	
	if (option ==3)
	{
		
		
		if (myCar.getSpeed() == 0)
		{
			std::cout<<"\nCar is already stopped, cannot brake anymore";
		}
		
		else 
		{
			myCar.brake();
		}
		
	}
	if (option ==4)
	{
		myCar.shutOff();
		
	}
	if (option ==5)
	{
		if (myCar.getSpeed() > 0)
		{
			std::cout<<"\nMust be fully shut off before filling up for gas";
		}
		else 
		{
		myCar.fillUp();
		
		}
		
		
	}
	
	
	
 std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 

        std::cout << "\nSpeed: " << myCar.getSpeed() << " mph";
        std::cout << "\nGas: " << myCar.getGallons() << " gallons";

    } while (option != 0);

    return 0;
}
