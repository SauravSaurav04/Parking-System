#include<bits/stdc++.h>
using namespace std;
class Vehical{
    public:
    string bike_info[10]={""};
    string scooty_info[10]={""};
    string car_info[10]={""};

    int bike_size=0;
    int scooty_size=0;
    int car_size=0;
};
class Parking : public Vehical {
    string p_no="";
    string startingTime="";
    string endTime="";
    int stay_hours;
    int money;

    public:
    void bike(){
        system("cls");
        cout<<endl<<endl;
        if(bike_size>10){
            cout<<"Sorry there is no space"<<endl<<endl;
            return;
        }
        cout<<"\t\t\t\t    Be free we are here :)"<<endl<<endl;
        string v_no;
        cout<<"\t\t\t\t   Enter bike no >> ";
        cin>>v_no;
        for(int i=0;i<10;i++){
            if(bike_info[i]==""){
                bike_info[i]=v_no;
                p_no = 'B';
                p_no += (char)(i+48);
                bike_size++;
                break;
            }
        }
        cout<<"\n\t\t\t\tFor how long Bike stay here?"<<endl;
        cout<<"\t\t\t\t  Enter time in Hours >> ";
        cin>>stay_hours;

        time_t my_time = time(NULL);
        startingTime = ctime(&my_time);

        cout<<"\n\t\t\t\t   Your parking no is "<<p_no<<endl<<endl;
        cout<<"\t\t\t\t";
        system("pause");
    }
    void scooty(){
        system("cls");
        cout<<endl<<endl;
        if(scooty_size>10){
            cout<<"Sorry there is no space"<<endl<<endl;
            return;
        }
        cout<<"\t\t\t\t    Be free we are here :)"<<endl<<endl;
        string v_no;
        cout<<"\t\t\t\t   Enter Scooty no >> ";
        cin>>v_no;
        for(int i=0;i<10;i++){
            if(scooty_info[i]==""){
                scooty_info[i]=v_no;
                p_no = 'S';
                p_no += (char)(i+48);
                scooty_size++;
                break;
            }
        }
        cout<<"\n\t\t\t\tFor how long Scooty stay here?"<<endl;
        cout<<"\t\t\t\t  Enter time in Hours >> ";
        cin>>stay_hours;

        time_t my_time = time(NULL);
        startingTime = ctime(&my_time);

        cout<<"\n\t\t\t\t   Your parking no is "<<p_no<<endl<<endl;
        cout<<"\t\t\t\t";
        system("pause");
    }
    void car(){
        system("cls");
        cout<<endl<<endl;
        if(car_size>10){
            cout<<"Sorry there is no space"<<endl<<endl;
            return;
        }
        cout<<"\t\t\t\t    Be free we are here :)"<<endl<<endl;
        string v_no;
        cout<<"\t\t\t\t   Enter car no >> ";
        cin>>v_no;
        for(int i=0;i<10;i++){
            if(car_info[i]==""){
                car_info[i]=v_no;
                p_no = 'C';
                p_no += (char)(i+48);
                car_size++;
                break;
            }
        }
        cout<<"\n\t\t\t\tFor how long car stay here?"<<endl;
        cout<<"\t\t\t\t  Enter time in Hours >> ";
        cin>>stay_hours;

        time_t my_time = time(NULL);
        startingTime = ctime(&my_time);

        cout<<"\n\t\t\t\t   Your parking no is "<<p_no<<endl<<endl;
        cout<<"\t\t\t\t";
        system("pause");
    }

    int calculateMinute(string startingTime, string endTime){
        int h1 = stoi(startingTime.substr(11,2));
        int h2 = stoi(endTime.substr(11,2));
        int m1 = stoi(startingTime.substr(14,2));
        int m2 = stoi(endTime.substr(14,2));
		int h;
		if(h2 < h1){
			h = 24-h1+h2;
		} else {
			h = h2-h1;
		}
        return h*60+(m2-m1);
    }

    void arriving(){
        system("cls");
        cout<<endl<<endl;
        cout<<"\t\t\t\t\t    You have come by"<<endl<<endl;
        cout<<"\t\t\t\t\t   1) Bike"<<endl;
        cout<<"\t\t\t\t\t   2) Scooty"<<endl;
        cout<<"\t\t\t\t\t   3) Car"<<endl;

        cout<<"\n\t\t\t\t\t   Enter here >> ";
        int choice;
        cin>>choice;

        switch(choice){
            case 1:
                bike();
                break;
            case 2:
                scooty();
                break;
            case 3:
                car();
                break;
            default:
                cout<<"Enter valid key"<<endl;
        }
    }
    bool checkPno(int in){
        for(int i=0;i<10;i++){
            if(i==in){
                return true;
            }
        }
        return false;
    }
    float getCharge(int min){
        if(min <= stay_hours*60 || min<=120){
            return (float)min/2;
        }
        return min;
    }
    void departing(){
        system("cls");
        string pno;
        cout<<"\n\n\t\t\t\t     Enter Parking no >> ";
        cin>>pno;
        int n = stoi(pno.substr(1));
        if(pno[0]=='B' && checkPno(n)){
            if(bike_info[n]!=""){
                cout<<"\n\t\t\t\t     Enter Bike no >> ";
                string g;
                cin>>g;
                if(bike_info[n]==g){
                    time_t my_time = time(NULL);
                    endTime = ctime(&my_time);
                    int min = calculateMinute(startingTime, endTime);
                    cout<<"\n\t\t\t\tYour Bike stay here for "<<min<<" minutes"<<endl<<endl;
                    cout<<"\t\t\t\t      You have to pay "<<getCharge(min)<<endl<<endl;
                    cout<<"\t\t\t\t    Please pay your bill >> ";
                    cin>>money;
                    if(money<getCharge(min)){
                        cout<<"\n\t\t\t\t\tInvalid amount";
                        cout<<"\n\n\t\t\t\t    ";
                        system("pause");
                    } else {
                        cout<<"\n\t\t\t\t     Thank you for visiting...\n\n";
                        bike_info[n]="";
                        bike_size--;
                        exit(0);
                    }
             
                } else {
                    cout<<"\n\t\t\t\t Sorry this bike is not there."<<endl;
                    cout<<"\n\n\t\t\t\t    ";
                    system("pause");
                }
            } else {
                cout<<"\n\n\t\t\t\t Sorry No bike is there at this place."<<endl;
                cout<<"\n\n\t\t\t\t    ";
                system("pause");
            }
        } else if(pno[0]=='S' && checkPno(n)){
            if(scooty_info[n]!=""){
                cout<<"\n\t\t\t\t     Enter Scooty no >> ";
                string g;
                cin>>g;
                if(scooty_info[n]==g){
                    time_t my_time = time(NULL);
                    endTime = ctime(&my_time);
                    int min = calculateMinute(startingTime, endTime);
                    cout<<"\n\t\t\t\tYour Scooty stay here for "<<min<<" minutes"<<endl<<endl;
                    cout<<"\t\t\t\t      You have to pay "<<getCharge(min)<<endl<<endl;
                    cout<<"\t\t\t\t    Please pay your bill >> ";
                    cin>>money;
                    if(money<getCharge(min)){
                        cout<<"\n\t\t\t\t\tInvalid amount";
                        cout<<"\n\n\t\t\t\t    ";
                        system("pause");
                    } else {
                        cout<<"\n\t\t\t\t     Thank you for visiting...\n\n";
                        scooty_info[n]="";
                        scooty_size--;
                        exit(0);
                    }
             
                } else {
                    cout<<"\n\t\t\t\t Sorry this scooty is not there."<<endl;
                    cout<<"\n\n\t\t\t\t    ";
                    system("pause");
                }
            } else {
                cout<<"\n\n\t\t\t\t Sorry No scooty is there at this place."<<endl;
                cout<<"\n\n\t\t\t\t    ";
                system("pause");
            }

        } else if(pno[0]=='C' && checkPno(n)){
            if(car_info[n]!=""){
                cout<<"\n\t\t\t\t     Enter car no >> ";
                string g;
                cin>>g;
                if(car_info[n]==g){
                    time_t my_time = time(NULL);
                    endTime = ctime(&my_time);
                    int min = calculateMinute(startingTime, endTime);
                    cout<<"\n\t\t\t\tYour car stay here for "<<min<<" minutes"<<endl<<endl;
                    cout<<"\t\t\t\t      You have to pay "<<getCharge(min)<<endl<<endl;
                    cout<<"\t\t\t\t    Please pay your bill >> ";
                    cin>>money;
                    if(money<getCharge(min)){
                        cout<<"\n\t\t\t\t\tInvalid amount";
                        cout<<"\n\n\t\t\t\t    ";
                        system("pause");
                    } else {
                        cout<<"\n\t\t\t\t     Thank you for visiting...\n\n";
                        car_info[n]="";
                        car_size--;
                        exit(0);
                    }
             
                } else {
                    cout<<"\n\t\t\t\t Sorry this car is not there."<<endl;
                    cout<<"\n\n\t\t\t\t    ";
                    system("pause");
                }
            } else {
                cout<<"\n\n\t\t\t\t Sorry No car is there at this place."<<endl;
                cout<<"\n\n\t\t\t\t    ";
                system("pause");
            }
        } else {
            cout<<"\n\t\t\t\tThis parking number is not there";
            cout<<"\n\n\t\t\t\t  ";
            system("pause");
        }
    }
};
int main(){
    Parking p;
    while(1){
        system("cls");
        system("color 90");
        cout<<"\n\n";
        cout<<"\t\t\t\t\t\t Welcome"<<endl<<endl;
        cout<<"\t\t\t\t\tPark Your Vehical here!!"<<endl<<endl;
    
        cout<<"\t\t\t\t    You are Arriving or Departing ?"<<endl<<endl;

        cout<<"\t\t\t\t\t1) Arriving\n";
        cout<<"\t\t\t\t\t2) Departing\n";
        cout<<"\n\t\t\t\t\t   Enter here >> ";
        int c;
        cin>>c;
        if(c==1){
            p.arriving();
        } else if(c==2){
            p.departing();
        } else {
            cout<<"Enter valid key..."<<endl<<endl;
        }
    }
}