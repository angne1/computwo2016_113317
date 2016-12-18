#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<windows.h>
#include<process.h>

using namespace std;

void textcolor(int color_number);

class Card{  //ī���� ���� Ŭ���� 

private:   
  	string Clover; //��������� private�� �����ϴ°��� �ٶ��� Ŭ�����ܺο��� ���ٺҰ����ϰ�
	string Spade;
  	string Diamond;
	string Hart;   
  	  

  	int number;   


public:  
	int CardPoint(); 
	Card(int number); //ī�忡 ��ȣ �ֱ�   
  	void show(); //ī�� ���� ����.�����ֱ�   
  	
	Card() {	//�����ڴ� public���� �ؼ� �ܺο��� ��ü�� �����ϰ���. 
	     
    Clover ="��";
	Spade = "��";  
    Diamond = "��";
	Hart = "��";  
      
  	}
	  
};

Card::CardPoint(){ //ī�忡 ������ �ο��ϱ����� �Լ� 
	int temp=0;
	temp=number;
	return temp;
}

Card::Card(int number){

	this->number=number; //this������ Ŭ��������Լ��������� ����. 
}

void Card::show(){
  
  int Shape;  
  int CardNumber;  
  
  Shape = number / 4;  
  CardNumber = number;  
  
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

  cout << CardNumber<<" ";
}


class CardDeck{ 
//���� 52�� ���� �� ���� ���� Ŭ���� 	 		
	public:		
		vector<Card> cards; //Ŭ���� ��üCard�� ��ҷ� ���� ���� 
		CardDeck();	 
		void CShuffle(); // �����Լ�   
		Card GetCard(); //ī�带 �����´�. 
		
		
};


	
CardDeck::CardDeck(){

		for(int j=0; j<4; j++){
			for(int i=1; i<=13; i++){
			cards.push_back(i);
			   	  
			}
		}
		
		CShuffle();

} //52�� ���� �ֱ� 		/

Card CardDeck::GetCard(){// ������ ī�带 �̴´�. 
 	
	Card card;
	
	if(cards.empty()){
 		cout<<"ī�带 ���̻� ���� �� �����ϴ�."<<endl;
 		
	}
	
	if(cards.size()>=1){
		if(cards.size()<=0){
			return 0;
		}	
		card = cards[cards.size()-1]; //�ڿ������� 
		cards.pop_back();
		 //ī�带 ������ �̾ұ� ������ ���� ������ �پ���.�� ��Ÿ���� pop 
	}

	return card;
}




void CardDeck::CShuffle(){ //ī�� ���� 
	
	
	int nDust,nSour;	
	srand(int(time(NULL)));
		
	for(int i=0; i<100; i++){ 	
		nDust=rand()%52;
		nSour=rand()%52;
		swap(cards[nDust],cards[nSour]);
	}
	
	
	
}


class Player { //�����ϴ� �÷��̾�  ���� Ŭ���� 
	private:
		vector <Card> player;	//Card�� ������ ������ ���ͺ��� �÷��̾ �������ִ� ī�� 
	public :
		 
		
		Player();
		
		int giveCard(Card); //�÷��̾ ������ ī�带 �޴´�. 
		void ShowPlayerCard(); //�÷��̾ ������ �ִ� ī�� ��� 		    
   		Card PushCard(int PushNum); //ī�带 ����. 
   		int MyCardPoint(); //ī���� ������ ������ 
		
};

Player::Player(){
}


Player::MyCardPoint(){
	
	int point=0;
	for(int i=0; i<player.size();i++){ //�÷��̾ �������ִ� �и�ŭ�� ���ڸ� ����. 
		
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
		cout<<"�а� ���� ���� ī�带 ������ �˴ϴ�!";
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
	
		cout<<"player"<<"�� ī�尡 �����ϴ�."<<endl;
		}
		
 	cout<<endl;		
 	cout<<"���� ī�� ��: "<<temp;
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
//	cout << "���� ���� �˴ϴ�."<<endl;
		cout<<"���� ȭ��         "<<endl;
		cout<<"��������������������������������������������"<<endl;
		cout<<"��                                        ��"<<endl;
		cout<<"��                                        ��"<<endl;
		cout<<"��                                        ��"<<endl;
		cout<<"��                1. ����"<<"                 ��"<<endl;
		cout<<"��                2. ����"<<"                 ��"<<endl;		
		cout<<"��                                        ��"<<endl;
		cout<<"��                                        ��"<<endl;
		cout<<"��                                        �� "<<endl;
		cout<<"��������������������������������������������"<<endl;
	textcolor(7);
	cin>>Select;	

		
	switch(Select){
	
	
	default :
		cout<<"�ٽ��Է�"<<endl;
		cin>>Select;
		break;	
	
	case 2:
		return 0;

	case 1:
		while(1){
			system("cls");	
	
	
			cout<<"����ȭ��         "<<endl;
			cout<<"��������������������������������������������"<<endl;
			cout<<"��                                        ��"<<endl;
			cout<<"��                                        ��"<<endl;
			cout<<"��                                        ��"<<endl;		
			cout<<"��   1. �÷��� �� �ο��� �Է����ּ���."<<"    ��"<<endl;
			cout<<"��  (����ο��� 2���̻� 4�� �����Դϴ�.)"<<"  ��"<<endl;		
			cout<<"��                                        ��"<<endl;
			cout<<"��                                        ��"<<endl;
			cout<<"��                                        �� "<<endl;
			cout<<"��������������������������������������������"<<endl;
	
			cin>>PlayerNum;	
		
			system("cls");
			cout<<"����ȭ��         "<<endl;
			cout<<"��������������������������������������������"<<endl;
			cout<<"��                                        ��"<<endl;
			cout<<"��                                        ��"<<endl;
			cout<<"��                                        ��"<<endl;		
			cout<<"��   2. �¸� ��ǥ���ڸ� �Է����ּ���."<<"     ��"<<endl;
			cout<<"��(15�̻� 150 ���ϸ� �Է��� �����մϴ�.)"<<"  ��"<<endl;		
			cout<<"��                                        ��"<<endl;
			cout<<"��                                        ��"<<endl;
			cout<<"��                                        �� "<<endl;
			cout<<"��������������������������������������������"<<endl;
			cin>>PlayerObject;
			 
				if(PlayerNum>1 && PlayerNum<5 && PlayerObject>=15 && PlayerObject<=150){ //��Ȳ 
					break;	
				}else{
					cout<<"2���̻� 4������"<<endl;
					cout<<"15�̻� 150����"<<endl;
				}
		
	}

		Player* player = new Player[PlayerNum]; //�����޸��Ҵ� 
	
		for(int j=0;j<1;j++){ //ī�� 1�徿 �÷��̾�� ���� 
	
			for(int i=0; i<PlayerNum; i++){
				Card temp = deck.GetCard(); //ī�� ���� �ޱ� 
				player[i].giveCard(temp);
				//temp.show();			
				cout<<endl;
		
			}
		}

    
  	

//ī�� ����///////////////////////////////////////////
		while(1){
		
					
			for(int i=0; i<PlayerNum; i++){ //�÷��̾� ī��,���� ��� 
				system("cls");
				int a=0;
				cout<<"����ȭ��"<<endl;
				cout<<"������������������������������������������������������������"<<endl;		
				cout<<"   ��ǥ:"<<PlayerObject<<"   ��:"<<turn+1<<"   ���� ī��:"<<deck.cards.size();
				textcolor(6);	
				cout<<"   [Player"<<i+1<<"]"; 
				textcolor(7);
				cout<<"�� �����Դϴ�.";
				cout<<endl;	
				
				cout<<"������������������������������������������������������������"<<endl; 
				cout<<"�س������ ī���� ��ȣ�� �Է��ϼ���.[�Է������ 0�� �Է��ϼ���]"<<endl;
				cout<<"��ī��� �� ���� �÷��̾� ����ŭ �ް� �˴ϴ�."<<endl;
				
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
						
							cout<<"Player"<<i+1<<"�¸�!"; 
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

