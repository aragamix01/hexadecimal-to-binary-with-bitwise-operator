#include<iostream>
using namespace std;

class cFibo{
public:
    cFibo(){
        index = 0;
        generateFibo();
        PointGe();
		//constructor
		//for call every method and set index to 0.
    }
    void generateFibo(){
        while(index<10000){
            if(index == 0||index ==1)                         // for check index is 0 or 1.
                index == 0 ? Ary[index] = 0 : Ary[index] = 1; // for set fibonacci 0 and 1 to address of Ary[0 and 1].
            else                                              // for check index is not 0 or 1.
                Ary[index]=Ary[index-1]+Ary[index-2];
            index++;
        };
    };
    void PointGe(){
        //Every pointer to Ary(array)
        shPoint = Ary;
        lnPoint = (long*)Ary;
        chPoint = (char*)Ary;
    };
    void print(int index,int many,int type,int base){
        int sum = index+many;
          /*
          Multi Print Function
           index = 1 - 10000
           many = How many do u want to print.
           type = Type of pointer
                   1. signed short*
                   2. signed long*
                   3. char
           base = base of value 2 or 10 only.
           */
        for(int i = index ;i<=sum;i++ ){
            if(base == 10){
            cout<<(type == 1 ? "Signed short " : type == 2 ? "Signed long " : "Char ");
            cout<<"<=entry ["<<i<<"]=> : ";
            type == 1 ? cout<<*(shPoint+(i-1)) : type == 2 ? cout<<*(lnPoint+(i-1)) : cout<<*(chPoint+(i-1));
            cout<<endl;
            }
            if(base == 2){
            cout<<(type == 1 ? "Signed short " : type == 2 ? "Signed long " : "Char ");
            cout<<"<=entry ["<<i<<"]=> : ";
            type == 1 ? toBinary(*(shPoint+(i-1))) : type == 2 ? toBinary(*(lnPoint+(i-1))) : toBinary(*(chPoint+(i-1)));
            cout<<endl;
            }//Use short-hand nested for print.
            //It comfortable.
        }
        cout<<"========================================================================="<<endl;
    }
    void toBinary(int value){
        unsigned int bit;
        for(bit = INT_MAX+1 ;bit>0;bit>>=1){
            cout<<(bit & value ? '1':'0');
        }
		/*
			For print parameter(int) in binary
			**use bitwise operator.
		*/
		//cout<<"Max int : " <<bit;
    }
private:
    int index;					//index of array.
    signed short Ary[10000];	//array (signed short) to keep fibonacci.
    signed short *shPoint;		//pointer (signed short*)
    signed long *lnPoint;		//pointer (signed long*)
    char *chPoint;				//pointer (char*)

};

int main(){

cFibo run;
//output start at 1020 and print forward 20 times.
//output base on 10 (hexadecimal)
run.print(1020,20,1,10); //signed short
run.print(1020,20,2,10); //signed long
run.print(1020,20,3,10); //char
//output base on 2 (binary)
run.print(1020,20,1,2); //signed short
run.print(1020,20,2,2); //signed long
run.print(1020,20,3,2); //char

};
