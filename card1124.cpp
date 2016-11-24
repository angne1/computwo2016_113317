#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector> 

#define START 10
using namespace std;

class Card{
	
	
	public:
		Card();
		static int pcnt1,pcnt2;
		static int Ccnt;
		int Givecard2();
		int CShuffle();
		int SGivecard();
		static int demonum;	
		vector<int> cardset; //  배열 모두 벡터사용함. (지금은 vector 연산자 함수 사용하지 않고, 제가 쓰던  함수 사용했습니다.) 
		vector<int> Player1;
		vector<int> Player2;	
		
};

Card::Card(){ 						// 생성자 초기화 
			for(int j=0; j<4; j++){
			
			for(int i=1; i<=13; i++){
				cardset.push_back(i);
			}
			
			}

			for(int i=1;i<26; i++){
				Player1.push_back(0);
				Player2.push_back(0);
			}
			







}
int Card::pcnt1=0;
int Card::pcnt2=0;
int Card::Ccnt=START;
int Card::demonum=7;	


			
int Card::SGivecard(){
	

	// 처음 5장 주기(2인기준) 
	for(int i=0;i<5;i++){

	Player1[i]=cardset[i];
	Player2[i]=cardset[i+5];
	}
	
	//덱 초기화 
	pcnt1=5;	
	pcnt2=5;
	Ccnt=START;
	
}

int Card::Givecard2(){
	//카드 2장씩 각각 플레이어에게 

	for(int i=0; i<2; i++){
		Player1[pcnt1]=cardset[Ccnt];	
	
	Ccnt++; 
	pcnt1++;
	}
	
	for(int i=0; i<2; i++){
	Player2[pcnt2]=cardset[Ccnt];	
	
	Ccnt++;
	pcnt2++;
	}

//데모로 보여줘야할부분	

	int demo;
	
	cout<<"플레이어에게 카드를 2장줍니까? 1. 네 2. 아니오"<<endl; 
	cin>>demo; 
	
	if(demo==1){
	cout<< "player1 card:  ";
	for(int i=0; i<demonum; i++){ 
	cout<<  Player1[i] <<'\t';
	}
	cout<< endl;
	cout<< "player2 card:  ";
	for(int i=0; i<demonum; i++){ 
	cout<<  Player2[i] <<'\t';
	}
	demonum+=2;
	cout<< endl;
	
				}
	else if(demo==2){
	
		return 0;
	}
}


int Card::CShuffle(){
	//카드 셔플 
	int nDust,nSour,nTemp;	
	srand(int(time(NULL)));
		
	for(int i=0; i<100; i++)
	{ 	
	nDust=rand()%50;
	nSour=rand()%50;
	nTemp = cardset[nDust];
	cardset[nDust] = cardset[nSour];
	cardset[nSour] = nTemp;
	
	}

}


int main(){
	
	Card A;
	A.CShuffle();
	
		
	A.SGivecard(); // 카드 처음 5장씩 플레이어에게 주기 


	cout<< "현재 주어진 카드 " << endl;
	cout<< "player1 card:  ";
	for(int i=0; i<5; i++){ 
	cout<<  A.Player1[i] <<'\t';
	}
	cout<< endl;
	
	cout<< "player2 card:  ";
	for(int i=0; i<5; i++){
	cout<<  A.Player2[i] <<'\t';
	}
	cout <<endl;
	
	A.Givecard2(); //카드 2장 제공함수 
	A.Givecard2();
	A.Givecard2();
	
	return 0;
}
