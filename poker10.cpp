#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<assert.h>

using namespace std;

vector<int> Player1;
vector<int> Player2;

class CardDeck{ //���� 52�� ���� �� ���� ���� Ŭ���� 	
		  //52���� ���ڸ� ���� ���� 		
	public:		
		vector<int> cards;
		CardDeck();	 
		void CShuffle(); // �����Լ�   
		
};
	
CardDeck::CardDeck(){ //52�� ���� �ֱ� 
		
		for(int j=0; j<4; j++){
			for(int i=1; i<=13; i++){
			cards.push_back(i);	  
			}
		}	
	CShuffle();		
}

void CardDeck::CShuffle(){
	//ī�� ���� 
	int nDust,nSour;	
	srand(int(time(NULL)));
		
	for(int i=0; i<100; i++)
	{ 	
		nDust=rand()%52;
		nSour=rand()%52;
		
		swap(cards[nDust],cards[nSour]);
	}
	//cout<<"����"<<endl;
	
}


class Playerpae : public CardDeck{ //�÷��̾ ���� �� ����(���� ī�带 �����ش�,�и� �޴´�.2��,6��) ���ڸ� �������� Carddeck ��� 

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
	

void Playerpae::PopCard(vector<int> &Who){ //�÷��̾�� ���ڵ��� �ִ�  ���ڸ�  �ش�. 
		
				
	
		//ayer1.push_back(cards.back());
		Who.push_back(cards.back());//carddeck�� ī�带 �ڿ������� ī�带 �����ش�.
//		cout<<Player1.size()<<endl;
		//cards.pop_back();                       // ī�带 �����ظ�ŭ pop! 		
	    Pop();
}
		
/*
void Initialize(){
	
	
	//Deck.CShuffle();
	
	for(int j=0; j<6; j++){  //6���� ���� �ֱ� 
		P1.PopCard(Player1);
		P1.PopCard(Player2);	
	}
	for(int i=0; i<Player1.size(); i++){
	cout<<Player1[i]<<'\t'; 
//	cout<<Player2[i]<<'\t';
	}
	cout<<endl;
	for(int j=0; j<2; j++){  //2���� ���� �ֱ� 
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

	for(int j=0; j<6; j++){  //6���� ���� �ֱ� 
		P1.PopCard(Player1);
		P1.PopCard(Player2);	
	}
	for(int i=0; i<Player1.size(); i++){
	cout<<Player1[i]<<'\t'; 
	
	cout<<Player2[i]<<'\t';
	
	}
	cout<<endl;
/*
	for(int j=0; j<2; j++){  //2���� ���� �ֱ� 
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
