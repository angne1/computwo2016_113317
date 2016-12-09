#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;
 

class CardDeck{ //���� 52�� ���� �� ���� ���� Ŭ���� 
	
	
		 		
	public:		
		vector<int> cards; //52���� ���ڸ� ���� ���� 
		CardDeck();	 
		void CShuffle(); // �����Լ�   
		
};

	
CardDeck::CardDeck(){

		for(int j=0; j<4; j++){
			for(int i=1; i<=13; i++){
			cards.push_back(i);
			   	  
			}
		}
		CShuffle();

} //52�� ���� �ֱ� 		/


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

class PlayerDeck : public CardDeck{ //�÷��̾ ���� �� ����(���� ī�带 �����ش�,�и� �޴´�.(2��,6��) ���ڸ� �������� Carddeck ��� 
	public:
	
	vector<int> Player;	
 	
	void Draw(bool MyTurn){
		cout<<"<������ �ִ� ī��>"<<endl; //�и� �׸���. 
 		for(int i=0; i<Player.size();i++){
			 cout<<Player[i];
			 
			if(MyTurn){ // 
				cout<<"[��]"<<'\t';
				
			}
		 }
		 cout<<endl;
	 }	
	
					
	void GiveNum();	
	void GiveNum2();
	void Sort();	
}; 

void PlayerDeck::GiveNum(){
	
		for(int i=1; i<7;i++){
			 Player.push_back(cards.back()); //vectord�� ���ڻ��� 
			 cards.pop_back();               //cards�� ī�� pop(ī�� �Ѱ���) 
			
		 }
		 cout<<endl;
	 }	

void PlayerDeck::GiveNum2(){
	cout<<endl;
	cout<<"[ī�带 2�� �޾ҽ��ϴ�.]"<<endl;
	
		for(int i=1; i<3;i++){
			 Player.push_back(cards.back());
			cards.pop_back();
			
		 }
	
		 cout<<endl;
	 }	
void PlayerDeck::Sort(){ //����ڰ� ���ڸ� �˾ƺ��� ���� sort�Լ���� 
	sort(Player.begin(),Player.end());
}



class Game : public PlayerDeck{ //������ ������ ����Ǵ� Ŭ���� 
	
	public:
		vector<int>::iterator it; //iterator �� �������  Player�� �ִ� ���� temp�� �ű��  
		vector<int> temp; // player�� ���� ���� �ӽ����� 
		int Score;
		
		void Draw(){
		PlayerDeck::Draw(true);
		}
	
	void CardSelect(); //�÷��̾� ī�� ���� 
	void Reset();
	void ResetTemp(); // temp���� 
	int Sum();
	
};
int Game::Sum(){
	int sum;
	for(it=temp.begin();it<temp.end(); it++){
		sum=sum+*it;
			cout<<"�߰����:"<<sum<<endl; 
	}
	return sum;
}

void Game::ResetTemp(){ //����� temp���� 
	
	for(int i=0;i<temp.size(); i){
		
		temp.pop_back();
	}
}

void Game::CardSelect(){ //�÷��̾ ����� �ڽ��� ���ڼ��� 
	int num=1;
	
	cout<<endl;
	cout<<"[�� ���ڸ� �����ϼ���]"<<endl;
	cout<<"[0�� �Է��ϸ� ���ڼ��� ����]"<<endl;
	while(1){
		cin>>num;
		
		if(num==0){
			if(temp.empty()){
			cout<<"��� 1���̻� �����ؾ��մϴ�."<<endl;
			}
			else
			break;
		}	
		
		if(Player.empty()){
			cout<<"������ �ִ� ���ī�带 �����߽��ϴ�."<<endl;
		}
		
		for(it=Player.begin();it<Player.end(); it++){
			
			if(num==*it){
			temp.push_back(*it);
			Player.erase(it);
			break;
			}
		
		}
			/*
			if(num!=*it){
			cout<<"�������ִ� ���ڿ��� �����ϼ���"<<endl;
			}
			*/			
	}
			
}
	
	
	


		
			
int main(){
	
	PlayerDeck B;
	Game C;	
	
/*
for(int i=0; i<B.cards.size();i++){
 			cout<<B.cards[i]<<'\t';
}
*/
cout<<endl;
		
 	C.GiveNum();
	C.Draw(); 
 	C.GiveNum2();
	C.Draw();
	C.Sort();
	cout<<endl;
	C.Draw();
	C.CardSelect();

	cout<<"�� ī��:"<<endl;
	for(int i=0; i<C.temp.size();i++){
		cout<<C.temp[i]<<endl;
		}
		
	cout<<endl;
	cout<<"��:"<<C.Sum()<<endl;	
/*
	C.ResetTemp();
	
	cout<<"�� ī��:"<<endl;
	for(int i=0; i<C.temp.size();i++){
		cout<<C.temp[i]<<endl;
		}
	C.Draw();
	*/	
}
