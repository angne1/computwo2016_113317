#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<assert.h>

using namespace std;

vector<int> Player1;
vector<int> Player2;

class CardDeck{ //숫자 52개 삽입 및 숫자 셔플 클래스 	
		  //52개의 숫자를 넣을 벡터 		
	public:		
		vector<int> cards;
		CardDeck();	 
		void CShuffle(); // 셔플함수   
		
};
	
CardDeck::CardDeck(){ //52개 숫자 넣기 
		
		for(int j=0; j<4; j++){
			for(int i=1; i<=13; i++){
			cards.push_back(i);	  
			}
		}	
	CShuffle();		
}

void CardDeck::CShuffle(){
	//카드 셔플 
	int nDust,nSour;	
	srand(int(time(NULL)));
		
	for(int i=0; i<100; i++)
	{ 	
		nDust=rand()%52;
		nSour=rand()%52;
		
		swap(cards[nDust],cards[nSour]);
	}
	//cout<<"셔플"<<endl;
	
}


class Playerpae : public CardDeck{ //플레이어가 먹은 패 관리(가진 카드를 보여준다,패를 받는다.2개,6개) 숫자를 쓰기위해 Carddeck 상속 

	public :

		Playerpae();
		void PopCard(vector<int>& Who);
		void Showcard(bool MyTurn);			
		void Pop();	
			
}; 




Playerpae::Playerpae(){
 		
}

void Playerpae::Pop(){
	cards.pop_back();
}
	

void Playerpae::PopCard(vector<int> &Who){ //플레이어에게 숫자덱에 있는  숫자를  준다. 
		
				
	
		//ayer1.push_back(cards.back());
		Who.push_back(cards.back());//carddeck의 카드를 뒤에서부터 카드를 나눠준다.
//		cout<<Player1.size()<<endl;
		//cards.pop_back();                       // 카드를 나눠준만큼 pop! 		
	    Pop();
}
		
/*
void Initialize(){
	
	
	//Deck.CShuffle();
	
	for(int j=0; j<6; j++){  //6개의 숫자 주기 
		P1.PopCard(Player1);
		P1.PopCard(Player2);	
	}
	for(int i=0; i<Player1.size(); i++){
	cout<<Player1[i]<<'\t'; 
//	cout<<Player2[i]<<'\t';
	}
	cout<<endl;
	for(int j=0; j<2; j++){  //2개의 숫자 주기 
		P1.PopCard(Player1);
		P1.PopCard(Player2);	
	}	
	for(int i=0; i<Player1.size(); i++){
	cout<<Player1[i]<<'\t'; 
//	cout<<Player2[i]<<'\t';
	}
}
*/

CardDeck Deck;
Playerpae P1;

	
int main(){
		
		
	cout<<Deck.cards.size()<<endl;
//	Initialize();

	for(int i=0;i<Deck.cards.size();i++)
	cout << Deck.cards[i] << ' ';
	cout<<endl;

	for(int j=0; j<6; j++){  //6개의 숫자 주기 
		P1.PopCard(Player1);
		P1.PopCard(Player2);	
	}
	for(int i=0; i<Player1.size(); i++){
	cout<<Player1[i]<<'\t'; 
	
	cout<<Player2[i]<<'\t';
	
	}
	cout<<endl;
/*
	for(int j=0; j<2; j++){  //2개의 숫자 주기 
		P1.PopCard(Player1);
		P1.PopCard(Player2);	
	}	
	for(int i=0; i<Player1.size(); i++){
	cout<<Player1[i]<<'\t'; 
//	cout<<Player2[i]<<'\t';
	}
*/



	cout<<endl;
	cout<<Deck.cards.size()<<endl;
	cout<<Player1.size()<<endl;
	cout<<endl;

	
 	return 0;
}						
