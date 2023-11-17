// writing on a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;
struct Album
{
    string id;
    string name;
};

bool non_cooprimo(int n, int m){

	for(int i = 2 ; i <= n ; i++){
		if (n%i == 0 && m%i == 0){
			return false;
		}
	}
	return true;

}

int get_non_cooprime(int n){

	for(int i = 2 ; i<n; i++){
		bool res = non_cooprimo(i,n);
		cout<<res<<endl;
		if(res){
			return i;
		}
	}
	return 0;
}



int get_D(int e, int T){
	int n;
	for(int i = 1; ((i*e)%T!=1 || i==e); i++){
		n = i;
	}
	return n+1;


}

vector<double> getEncriptedMessage(string message, int e, int N){
	int num;
	double power;
	double res;
	vector<double> encriptedV;
	for(int i = 0; i<message.length(); i++){
		num = message[i]-0;
		power = pow(num,e);
		res = fmod(power,(double)N);
		encriptedV.push_back(res);
	}

	return encriptedV;

}

string getDesencriptedMessage(vector<double> message, int d, int N){

	int num;
	double power;
	double res;
	char letter;
	string desencripted = "";
	for(int i = 0; i<message.size(); i++){
		power = pow((int)message[i],d);
		cout<<power<<endl;
		res = fmod(power,(double)N);
		cout<<res<<endl;
		letter = res;
		cout<<letter<<endl;
		desencripted.insert(desencripted.end(),1,letter);



	}

	return desencripted;


}
void printV(vector<double> vector){
	for(int i = 0; i<vector.size(); i++){

		cout<<vector[i]<<",";
	}
	cout<<endl;

}
void read_prime(int m, int e){
	int p,q,d,T;

	string line;
  	ifstream file ("primos.txt");
	getline (file,line);
	int num = stoi(line);
	int i = 0;
	while(m%num != 0 || i != 500){
		getline (file,line);
		num = stoi(line);
		i++;
	}
	if(m%num != 0){


		p = m/num;
		q = num;
		T = (p-1)*(q-1);
		d = get_D(e,T);
		cout<<"the decripted num is  "<<d<<endl;
		cout<<"take "<<i<<" iterations"<<endl;
	}else{


		cout<<"Exedio el limite de intentos"<<endl;
	}
	file.close();


}
int main () {
	int p,q,N,T,e,d;
	string P,Q;
	cout<<"ingrese p"<<endl;
	cin>>P;
	p = stoi(P);
	cout<<"ingrese q"<<endl;
	cin>>Q;
	q = stoi(Q);

	//p = 2;
	//q= 7;

	N = p*q;
	T = (p-1)*(q-1);

	e = get_non_cooprime(T);
	d = get_D(e,T);
	cout<<"su llave publica es "<<e<<","<<N<<endl;
	cout<<"su llave privada es "<<d<<","<<N<<endl;

	
	string message;
	cout<<"set the message to encript"<<endl;

	cin>>message;

//string encripted_message = 
	
	vector<double> encripted = getEncriptedMessage(message, e, N);
	printV(encripted);

	string desencripted = getDesencriptedMessage(encripted,d, N);
	cout<<desencripted<<endl;


	cout<<"try to get the key by hard work"<<endl;

	read_prime(N,e);



//	cout<<N<<","<<T<<","<<e<<","<<d<<endl;
	//<<T<<e<<d<<endl;

	

	
    return 0;
}
