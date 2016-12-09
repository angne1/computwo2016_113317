#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;
 

class CardDeck{ //숫자 52개 삽입 및 숫자 셔플 클래스 
	
	
		 		
	public:		
		vector<int> cards; //52개의 숫자를 넣을 벡터 
		CardDeck();	 
		void CShuffle(); // 셔플함수   
		
};

	
CardDeck::CardDeck(){

		for(int j=0; j<4; j++){
			for(int i=1; i<=13; i++){
			cards.push_back(i);
			   	  
			}
		}
		CShuffle();

} //52개 숫자 넣기 		/


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

class PlayerDeck : public CardDeck{ //플레이어가 먹은 패 관리(가진 카드를 보여준다,패를 받는다.(2개,6개) 숫자를 쓰기위해 Carddeck 상속 
	public:
	
	vector<int> Player;	
 	
	void Draw(bool MyTurn){
		cout<<"<가지고 있는 카드>"<<endl; //패를 그린다. 
 		for(int i=0; i<Player.size();i++){
			 cout<<Player[i];
			 
			if(MyTurn){ // 
				cout<<"[♧]"<<'\t';
				
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
			 Player.push_back(cards.back()); //vectord에 숫자삽입 
			 cards.pop_back();               //cards의 카드 pop(카드 총개수) 
			
		 }
		 cout<<endl;
	 }	

void PlayerDeck::GiveNum2(){
	cout<<endl;
	cout<<"[카드를 2장 받았습니다.]"<<endl;
	
		for(int i=1; i<3;i++){
			 Player.push_back(cards.back());
			cards.pop_back();
			
		 }
	
		 cout<<endl;
	 }	
void PlayerDeck::Sort(){ //사용자가 숫자를 알아보기 쉽게 sort함수사용 
	sort(Player.begin(),Player.end());
}



class Game : public PlayerDeck{ //실제로 게임이 진행되는 클래스 
	
	public:
		vector<int>::iterator it; //iterator 의 사용으로  Player에 있는 숫자 temp로 옮기기  
		vector<int> temp; // player에 넣은 숫자 임시저장 
		int Score;
		
		void Draw(){
		PlayerDeck::Draw(true);
		}
	
	void CardSelect(); //플레이어 카드 선택 
	void Reset();
	void ResetTemp(); // temp비우기 
	int Sum();
	
};
int Game::Sum(){
	int sum;
	for(it=temp.begin();it<temp.end(); it++){
		sum=sum+*it;
			cout<<"중간결과:"<<sum<<endl; 
	}
	return sum;
}

void Game::ResetTemp(){ //사용한 temp비우기 
	
	for(int i=0;i<temp.size(); i){
		
		temp.pop_back();
	}
}

void Game::CardSelect(){ //플레이어가 사용할 자신의 숫자선택 
	int num=1;
	
	cout<<endl;
	cout<<"[낼 숫자를 선택하세요]"<<endl;
	cout<<"[0을 입력하면 숫자선택 종료]"<<endl;
	while(1){
		cin>>num;
		
		if(num==0){
			if(temp.empty()){
			cout<<"적어도 1개이상 선택해야합니다."<<endl;
			}
			else
			break;
		}	
		
		if(Player.empty()){
			cout<<"가지고 있는 모든카드를 선택했습니다."<<endl;
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
			cout<<"가지고있는 숫자에서 선택하세요"<<endl;
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

	cout<<"낸 카드:"<<endl;
	for(int i=0; i<C.temp.size();i++){
		cout<<C.temp[i]<<endl;
		}
		
	cout<<endl;
	cout<<"합:"<<C.Sum()<<endl;	
/*
	C.ResetTemp();
	
	cout<<"낸 카드:"<<endl;
	for(int i=0; i<C.temp.size();i++){
		cout<<C.temp[i]<<endl;
		}
	C.Draw();
	*/	
}
