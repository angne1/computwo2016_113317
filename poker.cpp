#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<assert.h>

using namespace std;

const int Maxcard = 52;
const int start =11;


class Carddeck{ //���� 52�� ���� �� ī�� ���� Ŭ���� 
	protected:
		vector<int> cards; // ī�� ���͹迭 
		
	public:		
		Carddeck();	
		void CShuffle(); // �����Լ� 
		Carddeck(bool a);
		void Reset(bool a); // ���� ����࿡ ���� �����Լ�  
		void print(); //����� ���� �Լ� 
};

void Carddeck::print(){
	cout<<cards.size()<<endl;
	for(int i=0;i<cards.size();i++)
		cout << cards[i] << ' ';
	cout << endl;
}
/*
Carddeck::Carddeck(bool a){
	if(a){
	
	cout <<"����"<<endl;  
	cout<<cards.size()<<endl;
	for(int j=0; j<4; j++){
		for(int i=1; i<=13; i++){
			cards.push_back(i);
		}
	}
	cout<<cards.size()<<endl;
	CShuffle();
	cout<<cards.size()<<endl;
}
}
*/
		
Carddeck::Carddeck(){
	
		cout <<"����"<<endl; //����Ȯ�� 
		for(int j=0; j<4; j++){
		for(int i=1; i<=13; i++){
			cards.push_back(i); //52���� ���� push 
		}
	}
	CShuffle(); // �����Լ���� 
	
	cout<<cards.size()<<endl;		//���õǾ��ִ��� Ȯ���ϴ� ��¹� 
	for(int i=0;i<cards.size();i++)
		cout << cards[i] << ' ';
	cout << endl;

	
	cout<<cards.size()<<endl; // ī�尳�� Ȯ��2 
}



void Carddeck::CShuffle(){
	//ī�� ���� 
	int nDust,nSour;	
	srand(int(time(NULL)));
		
	for(int i=0; i<100; i++)
	{ 	
		nDust=rand()%52;
		nSour=rand()%52;
		swap(cards[nDust],cards[nSour]);
	}
}








/*
class Game : Carddeck{ //ī�����,   
	public :
		
		void reset();
		Game();
		
		
	private :
		void givecard(bool a);		
	
	protected:
		
		
	
};

Game::Game():Carddeck(true){
	
	}

class Player : Carddeck{
	public :
	int Player1;
	int Player2;
	
	
}; 
*/	
int main(){
 Carddeck A;
 

	return 0;
}						
