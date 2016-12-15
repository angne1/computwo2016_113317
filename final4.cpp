#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

class Card{  //카드모양 정보 클래스 

private:   
  	string SPADE;// = "♠";  
  	string HART;//  = "♡";  
  	string DIAMOND;// = "◇";  
  	string CLOVER;// ="♣";  

  	int number;  


public:  
 
	 Card(int number); //카드에 번호 넣기   
  
  	void show(); //카드 한장 생성.보여주기   
  
  	Card() {     
    
	SPADE = "♠";  
    HART = "♡";  
    DIAMOND = "◇";  
    CLOVER ="♣";  
  }  
};
Card::Card(int number){
	this->number=number;
}

void Card::show()  
{  
  int Shape;  
  int CardNumber;  
  
  Shape = number / 4;  
  CardNumber = number % 14;  
  
  /* 
    SPADE = "♠"; 
    HART = "♡"; 
    DIAMOND = "◇"; 
    CLOVER ="♣"; 
  */  
  switch(Shape) {  
  case 0:  
    cout << "♠" ;  
    break;  
  case 1:  
    cout <<"◇";  
    break;  
  case 2:  
    cout <<"♣";  
    break;  
  case 3:  
    cout <<"♡";  
    break;  
  default:  
    break;  
  }  
  cout << CardNumber<<" ";
}


class CardDeck{ 
//숫자 52개 삽입 및 숫자 셔플 클래스 	 		
	public:		
		vector<Card> cards; //52개의 숫자를 넣을 벡터 
		CardDeck();	 
		void CShuffle(); // 셔플함수   
		Card GetCard();
		
};


	
CardDeck::CardDeck(){

		for(int j=0; j<4; j++){
			for(int i=1; i<=13; i++){
			cards.push_back(i);
			   	  
			}
		}
		
		CShuffle();

} //52개 숫자 넣기 		/

Card CardDeck::GetCard(){
 	
	Card card;
	
	if(cards.size()>=1){
		card = cards[cards.size()-1]; //-1안해주면 오류남 
		cards.pop_back();
	}
	
	return card;
}

void CardDeck::CShuffle(){
	//카드 셔플 
	cout<<"셔플확인"<<endl;
	int nDust,nSour;	
	srand(int(time(NULL)));
		
	for(int i=0; i<100; i++)
	{ 	
		nDust=rand()%52;
		nSour=rand()%52;
		swap(cards[nDust],cards[nSour]);
	}
	
	
	
}


class Player{ //게임하는 플레이어  정보 클래스 
	private :
		vector <Card> player;
		string name;
	public :
		Player();
	
		int giveCard(Card);
		void ShowPlayerCard();
		
};

				
Player::Player(){
}



int Player::giveCard(Card add){
//	cout<<"giveCard확인"<<endl;
	player.push_back(add);
	
	return 0;
} 

void Player::ShowPlayerCard(){
//	cout<<"ShowPlayerCard확인"<<endl;
	for(int i=0; i<player.size(); i++){
		player[i].show();
		
	}
}

int main(){
	CardDeck deck;
	cout<<"몇명?:";
	
	int PlayerNum;
	cin>>PlayerNum;
	
		
	Player* player = new Player[PlayerNum];
	
	
	for(int j=0;j<6;j++){
	
		for(int i=0; i<PlayerNum; i++){
			Card temp = deck.GetCard(); //카드 한장 받기 
			player[i].giveCard(temp);
			temp.show();			
			cout<<endl;
		
	}
}


	for(int i=0; i<PlayerNum; i++){
	cout<<endl;
	cout<<"Player"<<i+1<<endl;
	player[i].ShowPlayerCard();
}
   for(int i=0; i<5;i++){
   
   cout<<endl;
}
   cout<<"Game 시작";
   
   for(int i=0; i<PlayerNum; i++){	
   		for(int i=0; i<2; i++){   
	   	Card temp = deck.GetCard();
		player[i].giveCard(temp);
	temp.show();
		}
	
	}
	
	
	return 0;
}
