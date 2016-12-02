#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<assert.h>

using namespace std;

const int Maxcard = 52;


class Carddeck{ //숫자 52개 삽입 및 숫자 셔플 클래스 
		
	protected:
		vector<int> cards;  //52개의 숫자를 넣을 벡터 
		int Num;
	public:		
		
		Carddeck();
			 
		void CShuffle(); // 셔플함수   
		
};

	
Carddeck::Carddeck(){ //52개 숫자 넣기 
		Num=0;
		
		for(int j=0; j<4; j++){
			for(int i=1; i<=13; i++){
			cards.push_back(i);
			Num++;   // 현재 카드의 갯수를 표시하는 인트형 Num 
			  
			}
		}
			for(int i=0;i<cards.size();i++)
		cout << cards[i] << ' ';
	  //출력용 생성 확인  
	cout << endl;
		
		
		CShuffle(); // 셔플함수사용 
		for(int i=0;i<cards.size();i++)
		cout << cards[i] << ' ';
	  //출력용 생성확인 
	cout << endl;
		
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
	cout<<"셔플"<<endl;
}



class Playerdeck : public Carddeck{ //플레이어가 먹은 패 관리(가진 카드를 보여준다,패를 받는다.2개,6개) 숫자를 쓰기위해 Carddeck 상속 
	public :
		Playerdeck();
		Playerdeck(int num);
		void playerdeck(int num);
		void Draw();
		void Givecard(bool s);			
}; 
	
Playerdeck::Playerdeck(int num){
	cout<<"플레이어의 수는:"<<num<<"명입니다."<<endl;
	playerdeck(num);
}


void Playerdeck::playerdeck(int num){ //인원체크 
	if(num==2){
		for(int i=0;i<2; i++){
		
		}
	}
	Draw();
}


void Playerdeck::Draw(){ //플레이어에게 숫자를  6개 주고 숫자를 보여준다. 
 	
	 
	cout<<"플레이어가 처음 받는 카드: ";
	for(int j=1; j<7; j++){
	cout<<cards[Num-j]<<'\t';       //뒤에서부터 카드를 나눠준다. 
	cards.pop_back();               // 카드를 나눠준만큼 pop! 
	}
	cout<<endl;
	for(int i=0;i<cards.size();i++){
	
	cout << cards[i] << ' ';
	}
	cout<<endl;  //생성확인 
	
	Num=Num-6;                    // Num
	cout<<Num<<endl;
	cout<<cards.size()<<endl;
	Givecard(1);
	Givecard(1);
}
		

void Playerdeck::Givecard(bool s) {
	cout<<"플레이어가 2장 받는 카드: ";
	if(s){
	                  
	for(int j=1; j<3; j++){
	cout<<cards[Num-j]<<'\t';
	cards.pop_back();
	}
	cout<<endl;
	for(int i=0;i<cards.size();i++)
	cout << cards[i] << ' ';
	  //생성확인 
	cout << endl;
	
	Num=Num-2;
	cout<<cards.size()<<endl;
	cout<<Num<<endl;
}
	if(false){
		cout<<"나의 차례입니다."<<endl; 
	}
		

}


class Game : public Playerdeck{ //실제로 게임이 진행되는 곳.  
								//여기서 플레이어 카드를 직접적으로 사용하진 않는다. 
	public :
	void Draw(){
		Game::playerdeck(false);//플레이어 카드 출력을 위해 playerdeck에서 상속받아 사용 
	
	} //추가할것 :플레이어가  카드를 냈을 때 카드의 값을 합산하여 카운트  ,카드 게임의목표치 표시 
};






	
int main(){
 Playerdeck test1(1);
	return 0;
}						
