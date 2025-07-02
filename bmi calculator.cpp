#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
    double weight ,height;
    cout<<"Enter weight in (kg): "<<endl;
    cin>>weight;
    cout<<"Enter height in (m): "<<endl;
    cin>>height;
    cout<<"choose units (1=kg/m,2lb/in): ";
    int choice;
    cout<<choice;
    if(choice==2){
        weight=height*0.453592;
        height=height*0.0254;
        cout<<"\n convertung metric for bmi calculatioin.....\n";
    }
    double bmi=weight/(height*height);
    cout<<fixed<<setprecision(1);
    cout<<"Your bmi: "<<bmi<<"-category:"<<endl;

    string category_name;
    if(bmi<18.5){
        category_name="underweight";
    }
    else if (bmi<25){
        category_name="normal weight";

    }
    else if(bmi<30){
        category_name="overweight";
    }
    else{
        cout<<"obese( acessive fat)"<<endl;
    }
    cout<<category_name;
    if(category_name=="underweight"){
        cout<<"nutrition tip: increase calories with intake of healthy fat"<<endl;
    }
    else if(category_name=="obese(acessive fat"){
        cout<<"health tip: consulting a nutritionist for a personalised plan"<<endl;
    }
    else if(category_name=="overweight"){
        cout<<"\n Great job maintain your healthy liferstyle!!!";
    }
    else if (category_name=="overweight"){
        cout<<"/nHealth tip: Incorporate more on physical activity and balance diet"<<endl;
    }
}