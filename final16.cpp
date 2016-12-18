#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<windows.h>
#include<process.h>

using namespace std;

void textcolor(int color_number);

class Card{  //카드모양 정보 클래스 

private:   
  	string Clover; //변수멤버는 private로 지정하는것이 바람직 클래스외부에서 접근불가능하게
	string Spade;
  	string Diamond;
	string Hart;   
  	  

  	int number;   


public:  
	int CardPoint(); 
	Card(int number); //카드에 번호 넣기   
  	void show(); //카드 한장 생성.보여주기   
  	
	Card() {	//생성자는 public으로 해서 외부에서 객체를 생성하게함. 
	     
    Clover ="♧";
	Spade = "♤";  
    Diamond = "◇";
	Hart = "♡";  
      
  	}
	  
};

Card::CardPoint(){ //카드에 점수를 부여하기위한 함수 
	int temp=0;
	temp=number;
	return temp;
}

Card::Card(int number){

	this->number=number; //this포인터 클래스멤버함수내에서만 사용됨. 
}

void Card::show(){
  
  int Shape;  
  int CardNumber;  
  
  Shape = number / 4;  
  CardNumber = number;  
  
  switch(Shape) {  
  case 0:  
    cout << "♤" ;  
    break;  
  case 1:  
    cout <<"◇";  
    break;  
  case 2:  
    cout <<"♧";  
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
		vector<Card> cards; //클래스 객체Card를 요소로 가진 벡터 
		CardDeck();	 
		void CShuffle(); // 셔플함수   
		Card GetCard(); //카드를 가져온다. 
		
		
};


	
CardDeck::CardDeck(){

		for(int j=0; j<4; j++){
			for(int i=1; i<=13; i++){
			cards.push_back(i);
			   	  
			}
		}
		
		CShuffle();

} //52개 숫자 넣기 		/

Card CardDeck::GetCard(){// 덱에서 카드를 뽑는다. 
 	
	Card card;
	
	if(cards.empty()){
 		cout<<"카드를 더이상 뽑을 수 없습니다."<<endl;
 		
	}
	
	if(cards.size()>=1){
		if(cards.size()<=0){
			return 0;
		}	
		card = cards[cards.size()-1]; //뒤에서부터 
		cards.pop_back();
		 //카드를 덱에서 뽑았기 때문에 덱에 한장이 줄어든다.를 나타내는 pop 
	}

	return card;
}




void CardDeck::CShuffle(){ //카드 셔플 
	
	
	int nDust,nSour;	
	srand(int(time(NULL)));
		
	for(int i=0; i<100; i++){ 	
		nDust=rand()%52;
		nSour=rand()%52;
		swap(cards[nDust],cards[nSour]);
	}
	
	
	
}


class Player { //게임하는 플레이어  정보 클래스 
	private:
		vector <Card> player;	//Card의 정보를 가지는 벡터변수 플레이어가 가지고있는 카드 
	public :
		 
		
		Player();
		
		int giveCard(Card); //플레이어가 덱에서 카드를 받는다. 
		void ShowPlayerCard(); //플레이어가 가지고 있는 카드 출력 		    
   		Card PushCard(int PushNum); //카드를 낸다. 
   		int MyCardPoint(); //카드의 점수를 보여줌 
		
};

Player::Player(){
}


Player::MyCardPoint(){
	
	int point=0;
	for(int i=0; i<player.size();i++){ //플레이어가 가지고있는 패만큼의 숫자를 합함. 
		
		int temp = player[i].CardPoint();
		point=point+temp;
		}
		
 	return point;
	}
	
	

Card Player::PushCard(int PushNum){
	
	vector<Card>::iterator p;   
	p=player.begin();
	
			
	p += (--PushNum);
	
	player.erase(p);
	return 0; 
}

int Player::giveCard(Card add){
	if(player.size()>9){
		cout<<endl;
		cout<<"패가 가득 차서 카드를 버리게 됩니다!";
		return 0;
	}
	player.push_back(add);
	
	return 0;
} 

void Player::ShowPlayerCard(){
	
	int temp =0;
		if(player.size()>0){		
		
			for(int i=0; i<player.size(); i++){
			textcolor(9);
			cout<<"["<<i+1<<"]";
			textcolor(7);
			player[i].show();
			temp=MyCardPoint();
			}
		
		}else{
	
		cout<<"player"<<"낼 카드가 없습니다."<<endl;
		}
		
 	cout<<endl;		
 	cout<<"현재 카드 합: "<<temp;
}


void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}



int main(){
	
	CardDeck deck;
	Player point;
	
	int PlayerNum=0;
	int PlayerObject=0;
	int turn=0;
	 
	int Select = 0;	
	
	//textcolor(1);
//	cout << "색이 변경 됩니다."<<endl;
		cout<<"시작 화면         "<<endl;
		cout<<"┏━━━━━━━━━━━━━━━━━━━━┓"<<endl;
		cout<<"┃                                        ┃"<<endl;
		cout<<"┃                                        ┃"<<endl;
		cout<<"┃                                        ┃"<<endl;
		cout<<"┃                1. 시작"<<"                 ┃"<<endl;
		cout<<"┃                2. 종료"<<"                 ┃"<<endl;		
		cout<<"┃                                        ┃"<<endl;
		cout<<"┃                                        ┃"<<endl;
		cout<<"┃                                        ┃ "<<endl;
		cout<<"┗━━━━━━━━━━━━━━━━━━━━┛"<<endl;
	textcolor(7);
	cin>>Select;	

		
	switch(Select){
	
	
	default :
		cout<<"다시입력"<<endl;
		cin>>Select;
		break;	
	
	case 2:
		return 0;

	case 1:
		while(1){
			system("cls");	
	
	
			cout<<"세팅화면         "<<endl;
			cout<<"┏━━━━━━━━━━━━━━━━━━━━┓"<<endl;
			cout<<"┃                                        ┃"<<endl;
			cout<<"┃                                        ┃"<<endl;
			cout<<"┃                                        ┃"<<endl;		
			cout<<"┃   1. 플레이 할 인원을 입력해주세요."<<"    ┃"<<endl;
			cout<<"┃  (사용인원은 2명이상 4명 이하입니다.)"<<"  ┃"<<endl;		
			cout<<"┃                                        ┃"<<endl;
			cout<<"┃                                        ┃"<<endl;
			cout<<"┃                                        ┃ "<<endl;
			cout<<"┗━━━━━━━━━━━━━━━━━━━━┛"<<endl;
	
			cin>>PlayerNum;	
		
			system("cls");
			cout<<"세팅화면         "<<endl;
			cout<<"┏━━━━━━━━━━━━━━━━━━━━┓"<<endl;
			cout<<"┃                                        ┃"<<endl;
			cout<<"┃                                        ┃"<<endl;
			cout<<"┃                                        ┃"<<endl;		
			cout<<"┃   2. 승리 목표숫자를 입력해주세요."<<"     ┃"<<endl;
			cout<<"┃(15이상 150 이하만 입력이 가능합니다.)"<<"  ┃"<<endl;		
			cout<<"┃                                        ┃"<<endl;
			cout<<"┃                                        ┃"<<endl;
			cout<<"┃                                        ┃ "<<endl;
			cout<<"┗━━━━━━━━━━━━━━━━━━━━┛"<<endl;
			cin>>PlayerObject;
			 
				if(PlayerNum>1 && PlayerNum<5 && PlayerObject>=15 && PlayerObject<=150){ //상황 
					break;	
				}else{
					cout<<"2명이상 4명이하"<<endl;
					cout<<"15이상 150이하"<<endl;
				}
		
	}

		Player* player = new Player[PlayerNum]; //동적메모리할당 
	
		for(int j=0;j<1;j++){ //카드 1장씩 플레이어에게 제공 
	
			for(int i=0; i<PlayerNum; i++){
				Card temp = deck.GetCard(); //카드 한장 받기 
				player[i].giveCard(temp);
				//temp.show();			
				cout<<endl;
		
			}
		}

    
  	

//카드 선택///////////////////////////////////////////
		while(1){
		
					
			for(int i=0; i<PlayerNum; i++){ //플레이어 카드,순서 출력 
				system("cls");
				int a=0;
				cout<<"게임화면"<<endl;
				cout<<"┏━━━━┳━━━┳━━━━━━┳━━━━━━━━━━━━┓"<<endl;		
				cout<<"   목표:"<<PlayerObject<<"   턴:"<<turn+1<<"   남은 카드:"<<deck.cards.size();
				textcolor(6);	
				cout<<"   [Player"<<i+1<<"]"; 
				textcolor(7);
				cout<<"의 차례입니다.";
				cout<<endl;	
				
				cout<<"┗━━━━┻━━━┻━━━━━━┻━━━━━━━━━━━━┛"<<endl; 
				cout<<"※내고싶은 카드의 번호를 입력하세요.[입력종료는 0을 입력하세요]"<<endl;
				cout<<"※카드는 턴 마다 플레이어 수만큼 받게 됩니다."<<endl;
				
				for(int j=0; j<PlayerNum; j++){	
					   	
	   					Card temp = deck.GetCard();
						player[i].giveCard(temp);
						cout<<endl; 	
				}
					
				while(1){
				//	system("cls");
					player[i].ShowPlayerCard();
					cout<<endl;
						if(PlayerObject==player[i].MyCardPoint()){
						
							cout<<"Player"<<i+1<<"승리!"; 
							return 0;
						
						}	
			
				
						cin>>a;
				
							if(a==0) {
								break;
							}
						player[i].PushCard(a);		
					}	
				}
				turn++;
		}
///////////////////////////////////////////////////////////////

break;


		
}
	return 0;
}

