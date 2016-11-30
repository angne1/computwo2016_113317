#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<assert.h>

using namespace std;

const int Maxcard = 52;
const int start =11;


class Carddeck{ //숫자 52개 삽입 및 카드 셔플 클래스 
	protected:
		vector<int> cards; // 카드 벡터배열 
		
	public:		
		Carddeck();	
		void CShuffle(); // 셔플함수 
		Carddeck(bool a);
		void Reset(bool a); // 게임 재실행에 사용될 리셋함수  
		void print(); //출력을 위한 함수 
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
	
	cout <<"생성"<<endl;  
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
	
		cout <<"생성"<<endl; //생성확인 
		for(int j=0; j<4; j++){
		for(int i=1; i<=13; i++){
			cards.push_back(i); //52개의 숫자 push 
		}
	}
	CShuffle(); // 셔플함수사용 
	
	cout<<cards.size()<<endl;		//셔플되어있는지 확인하는 출력문 
	for(int i=0;i<cards.size();i++)
		cout << cards[i] << ' ';
	cout << endl;

	
	cout<<cards.size()<<endl; // 카드개수 확인2 
}



void Carddeck::CShuffle(){
	//카드 셔플 
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
class Game : Carddeck{ //카드셔플,   
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
