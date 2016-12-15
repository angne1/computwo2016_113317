#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

class Card{  
private:   
  string SPADE;// = "��";  
  string HART;//  = "��";  
  string DIAMOND;// = "��";  
  string CLOVER;// ="��";  

  int number;  

public:  
  Card(int number); //ī�忡 ��ȣ �ֱ�   
  
  void show(); //ī�� �����ֱ�   
  
  Card() {  
    number = 51;  
    SPADE = "��";  
    HART = "��";  
    DIAMOND = "��";  
    CLOVER ="��";  
  }  
};
Card::Card(int number){
	this->number=number;
}

void Card::show()  
{  
  int Shape;  
  int cardnumber;  
  
  Shape = number / 13;  
  cardnumber = number % 13;  
  
  /* 
    SPADE = "��"; 
    HART = "��"; 
    DIAMOND = "��"; 
    CLOVER ="��"; 
  */  
  switch(Shape) {  
  case 0:  
    cout << "��" ;  
    break;  
  case 1:  
    cout <<"��";  
    break;  
  case 2:  
    cout <<"��";  
    break;  
  case 3:  
    cout <<"��";  
    break;  
  default:  
    break;  
  }  
  cout << cardnumber << " ";
}


class CardDeck{ 
//���� 52�� ���� �� ���� ���� Ŭ���� 	 		
	public:		
		vector<Card> cards; //52���� ���ڸ� ���� ���� 
		CardDeck();	 
		void CShuffle(); // �����Լ�   
		Card GetCard();
		
};


	
CardDeck::CardDeck(){

		for(int j=0; j<4; j++){
			for(int i=1; i<=13; i++){
			cards.push_back(i);
			   	  
			}
		}
		CShuffle();

} //52�� ���� �ֱ� 		/

Card CardDeck::GetCard(){
 	
	Card card;
	
	if(cards.size()>=1){
		card = cards[cards.size()-1];
		cards.pop_back();
	}
	return card;
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
	cout<<"����"<<endl;
	
	
}


class Player{ //�����ϴ� �÷��̾�  ���� Ŭ���� 
	private :
		vector <Card> player;

	public :
		Player();
		int giveCard(Card);
		void ShowPlayerCard();

};

				
Player::Player(){
	
}

int Player::giveCard(Card add){
	player.push_back(add);
	return 0;
} 

void Player::ShowPlayerCard(){
	for(int i=0; i<player.size(); i++){
		player[i].show();
	}
}

int main(){
	CardDeck deck;
		
	Player* player = new Player;
	for(int i=0; i<1; i++){
		Card temp = deck.GetCard();
		player[i].giveCard(temp);
		player[i].ShowPlayerCard();
		//cout<<player[i]<<endl;
		
	}
	
	return 0;
}
