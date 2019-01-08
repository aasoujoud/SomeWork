#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;   /// I really Did not have ANY IDEA what kind of program I wanted and i looked online but couldnt find any
						// So i decided why not do a mashup of everything that would be similar to a "final exam", nothing compilcated . 
						// ALSO, I DO NOT HAVE ANY USE for a template, I understand it and it is a very easy thing to do but I really couldn't mashup that when i Used other stuff!
class AutoMobile{
	private:
	  string type;
	  string ext;
      string color;
      int cylinder;
      int year;
      int carOrTruck;
      float milage = 0;
      double cost = 0;
      
      
    public:
    	AutoMobile(string type, string ext, string color, int cylinder, int year, float milage){
    		this->type = type;
    		this->ext = ext;
    		this->color = color;
    		this->cylinder = cylinder;
			this->year = year;
			this->milage=milage;  
		}
		AutoMobile(){}
    	
    friend ostream& operator<<(ostream&, AutoMobile&);	
      string getType(){return type;}
	  void setType(string s){type=s;}
	  string getExtension(){return ext;}
	  void setExtension(string e){ext=e;}
	  string getColor(){return color;}
	  void setColor(string c){color=c;}
	  int getCylinder(){return cylinder;}
	  void setCylinder(int y){cylinder=y;}
      int getYear(){return year;}
	  void setYear(int i){year=i;}
	  float getMilage(){return milage;}
	  void setMilage(float m){milage=m;}
	  void setCarOrTruck(int m){carOrTruck=m;}
      int getCarOrTruck(){return carOrTruck;}
	  
	  double getCost(){return cost;}
	  void setCost(double o){cost=o;}
	
	   void autoCostCalculator(){
	  	if((year < 2000 )&& (cylinder <= 6)){
			cost += 1000;
		}
		else if((year < 2000) && (cylinder >= 6)){
			cost += 1200;
		}
		if((year > 2000 )&& (cylinder <= 6)){
  			cost += 1500;
		}
		else if((year > 2000) && (cylinder >= 6)){
			cost += 2000;
		}
		if(milage< 50000){
			cost += 500;
		}	
	  }
};

class Trucks: public AutoMobile{
   private: 
		int seats = 4; // default truck seats , no option for doors because they all come in in 4 doors no less.
		double truckCost = 4000;
   public:
   	  Trucks(string t,string g,string w ,int n, int s, float r, int p):AutoMobile(t,g,w,n,s,r){seats = p;setCarOrTruck(1);setCost(truckCost);};
   	  Trucks():AutoMobile(){};
   	  void setSeats(int s){seats=s;}												
      void autoCostCalculator(){
         if (seats > 6) {
         	setCost(500 + truckCost);
		 }
         AutoMobile::autoCostCalculator();				// So i finally figured out how to call the base(parent) class's functions (overloading)
      }													//looked online everywhere for the creature program but couldnt find it... so i threw that and it worked.. magically.
};

class Cars: public AutoMobile{
	private: 
		int doors = 4; //doors default value, no option for seats because THEY ALL COME in 4 seats.
		double carCost = 3500;
	public: 
	   Cars(string t,string g,string w ,int n, int s, float r, int d):AutoMobile(t,g,w,n,s,r){doors = d;setCarOrTruck(2);setCost(carCost);};
	   Cars():AutoMobile(){};
	   void autoCostCalculator(){
         if ((doors == 2) && (getExtension() == "Convertible")) {
         	setCost(600+ carCost);
		 }
		 else if(doors == 2){
		 	setCost(200+ carCost);
		 }
         AutoMobile::autoCostCalculator();				// So i finally figured out how to call the base(parent) class's functions (overloading)
      }		
};

ostream& operator<<(ostream& x, AutoMobile& a){ // OSTREAM is awesome!
	x<<"Type: "<<a.getType()<<" Extenstion: "<<a.getExtension()<<" Color: "<<a.getColor()<<" Milage: "<<a.getMilage()<<" Cylinders: "<<a.getCylinder()<<
	" Year: "<<a.getYear()<<" Cost: "<<a.getCost()<<endl;
	return x;
}

class Inventory{
	private:
		vector<AutoMobile> cars; // making it automobile so it works for both when i call the display operator, sending it an automobile instead of a car or a truck
		vector<AutoMobile> trucks;
		string type,ext,color;
    	int cylinder , year, carOrTruck,seats,doors;
    	float milage ;
    	int OPTION;
    	int seatsOrDoors; // you will know what i will use this for later.... (HINT: Reading from file).
		
	public:
		bool lettersOrSpaces(const std::string& str)  // Check for int input in a string input.
		{
		    for (size_t i = 0; i < str.size(); i++)
		    {
		        if (! std::isalpha(str[i]) && ! std::isspace(str[i]))
		        {
		            return false; 
		        }
		    }
		    return true;  
		}
		
		void addVechile(){
			cin.ignore();
		    cout << "Enter in the type! ";
		    while (getline(cin, type) && !lettersOrSpaces(type))   // DATA validation
		    {
		        cout << "Please enter in a valid input for the type!";
		    }
		    
		    cout << "Enter in the ext! ";
		    while (getline(cin, ext) && !lettersOrSpaces(ext))
		    {
		        cout << "Please enter in a valid input for the ext!";
		    }
		    
		    cout << "Enter in the color! ";
		    while (getline(cin, color) && !lettersOrSpaces(color))
		    {
		        cout << "Please enter in a valid input for the color!";
		    }
			cout<<"Please enter in the Cylinders"<<endl;
			cin>>cylinder;
			while(cylinder< 2 || cylinder> 16){
				cout<<"Please enter in a valid cylinder! "<<endl;
				cin>>cylinder;	
			}
			cout<<"Please enter in a year! "<<endl;
			cin>>year;	
			while(year < 1950 || year > 2018){
				cout<<"Please enter in a valid year! "<<endl;
				cin>>year;	
			}
			cout<<"Please enter in a milage! "<<endl;
			cin>>milage;
			while(milage < 0 || milage > 300000){
				cout<<"Please enter in a valid milage! "<<endl;
				cin>>milage;	
			}
			cout<<"Is this a car or a truck? (1-truck - 2-car) "<<endl;
			cin>>carOrTruck;
			while(carOrTruck < 1 || carOrTruck > 2){
				cout<<"Please enter in a valid option! "<<endl;
				cin>>carOrTruck;	
			}
			if(carOrTruck == 1){
				cout<<"Please enter in the amount of seats! "<<endl;
				cin>>seats;
				while(seats < 4 || seats > 10){
					cout<<"Please enter in a valid number of seats! "<<endl;
					cin>>seats;	
				}
				Trucks truck(type,ext,color,cylinder,year,milage,seats);
				truck.autoCostCalculator();
				addToInventory(truck);
			}
			else {
				cout<<"Please enter in the amount of doors! "<<endl;
				cin>>doors;
				while(doors < 2 || doors > 4){
					cout<<"Please enter in a valid number of doors! "<<endl;
					cin>>doors;	
				}
				Cars car(type,ext,color,cylinder,year,milage,doors);
				car.autoCostCalculator();
				addToInventory(car);
			}
			
		}
		void addToInventory(AutoMobile &autoMobile){
			if(autoMobile.getCarOrTruck() == 1){
				trucks.push_back(autoMobile);
			}
			else {
				cars.push_back(autoMobile);
			}
		}
		
		void removeFromInventory(){    // No two cars will have the same milage, type and ext
			cin.ignore();
		    cout << "Enter in the type! ";
		    while (getline(cin, type) && !lettersOrSpaces(type))
		    {
		        cout << "Please enter in a valid input for the type!";
		    }
		    
		    cout << "Enter in the ext! ";
		    while (getline(cin, ext) && !lettersOrSpaces(ext))
		    {
		        cout << "Please enter in a valid input for the ext!";
		    }
		    
		    cout<<"Please enter in a milage! "<<endl;
			cin>>milage;
			while(milage < 0 || milage > 300000){
				cout<<"Please enter in a valid milage! "<<endl;
				cin>>milage;	
			}
		    
			bool FINDIT= false;
			vector<AutoMobile>::iterator iter = cars.begin();
			for (;iter != cars.end();)
			{
			   if ( (iter->getType() == type) && (iter->getMilage() == milage) && (iter->getExtension() == ext)) // Check if there is a milage,type or extention for such car.
			   {
			      iter = cars.erase(iter);
			      cout<<"-------Car found & removed from Inventory-------"<<endl;
			      FINDIT = true;
			   }
			   else
			   {
			      ++iter;
			   }
			}
			iter = trucks.begin();
			for (;iter != trucks.end();)
			{
			   if ( (iter->getType() == type) && (iter->getMilage() == milage) && (iter->getExtension() == ext))
			   {
			      iter = trucks.erase(iter);
			      cout<<"-------Truck found & removed from Inventory-------"<<endl;
			      FINDIT = true;
			   }
			   else
			   {
			      ++iter;
			   }
			}
			if(FINDIT == false){											// if not found it will be removed!
				cout<<"Sorry Truck or Car was not found in inventory!"<<endl;
			}
		}
		
		void readFromFile(){ // in progress 
			ifstream file( "Vechiles.txt", ios::in );
		    string part1, part2;
		    int num1, num2;
		
		    if( !file )
		        cerr << "Cannot open file! " << endl;
		
		    while( file >> type >> ext >> color >> cylinder>> year >> milage>> seatsOrDoors >>carOrTruck) // so it speaks for itself...
		    {
		        if(carOrTruck == 1){
		        	Trucks truck(type,ext,color,cylinder,year,milage,seatsOrDoors);
					truck.autoCostCalculator();
					addToInventory(truck);
				}
				else{
					Cars car(type,ext,color,cylinder,year,milage,seatsOrDoors);
					car.autoCostCalculator();
					addToInventory(car);
				}
		    }
		    cout<<"-------------------Vechiles loaded from file --------------------"<<endl;
		
		    file.close();
		}
		
		void displayInventory(){
			cout<<"--------------Cars--------------"<<endl;
			for( AutoMobile x : cars){
    	 		cout<<x; // this is awesome, I can use it anywhere!
			}
			cout<<"--------------Trucks--------------"<<endl;
			for( AutoMobile x : trucks){
    	 		cout<<x;
			}
			if (cars.empty() && trucks.empty()){
					cout<<".... they are Empty, add some vechiles first!"<<endl;
				}
		}
};

int main(void) {
	Inventory Inven; // have different companies, make an array that will contain all of them.
    int OPTION = 10;
    Trucks truck("Ford equinex","SUV","white",6,2013,130000,8); // loading inventory with some new vechiles!!
    Trucks truck1("Honda","crv-7","Chrome",8,1990,30000,6);
    truck.autoCostCalculator();									// I could have had this done automatically when const is called but its fine, it looks cool.
    truck1.autoCostCalculator();								// Also I could have had an array and load all of them into one since they are all "AutomobileS", but again its cool.
    Cars car("Toyota","Convertible","Red",6,2000,13000,2);
    Cars car1("Honda","Corola","Blue",6,2016,190000,6);
    car.autoCostCalculator();
    car1.autoCostCalculator();
    
    Inven.addToInventory(car);
	Inven.addToInventory(car1);
	Inven.addToInventory(truck);
	Inven.addToInventory(truck1);
    while(OPTION != 4){
    	try{
		cout<<"\nWhat would you like to do? \n(0- Remove from Inventory)\n(1- Add Vechiles to inventory)\n(2- Display Vechiles in inventory)\n(3- Load Vechiles from a file into inventory!)\n(4-Just exit....?))"<<endl;
		cin>>OPTION;			// I WANt to load from file but i dont know if i have time, i will try!
		
		if (OPTION < 0 || OPTION > 4)
			throw 1000;
		}	
		catch(int x)
		   {
		       cout<<"\nOption must be between 0 and 4."<<"Error:"<<x<<endl;
		   }
		   
		while(OPTION < 0 || OPTION > 4){
			cout<<"Enter a number 1 through 4! "<<endl;
			cin>>OPTION;	
		}
		if(OPTION == 0){
			Inven.removeFromInventory();  
		}
		if(OPTION == 1) {
			Inven.addVechile();
		}
		else if(OPTION == 2) {
			Inven.displayInventory();
		}
		else if(OPTION == 3) {
			Inven.readFromFile();
		}
	}
   return 0;
}
