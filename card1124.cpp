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
		vector<int> cardset; //  �迭 ��� ���ͻ����. (������ vector ������ �Լ� ������� �ʰ�, ���� ����  �Լ� ����߽��ϴ�.) 
		vector<int> Player1;
		vector<int> Player2;	
		
};

Card::Card(){ 						// ������ �ʱ�ȭ 
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
	

	// ó�� 5�� �ֱ�(2�α���) 
	for(int i=0;i<5;i++){

	Player1[i]=cardset[i];
	Player2[i]=cardset[i+5];
	}
	
	//�� �ʱ�ȭ 
	pcnt1=5;	
	pcnt2=5;
	Ccnt=START;
	
}

int Card::Givecard2(){
	//ī�� 2�徿 ���� �÷��̾�� 

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

//����� ��������Һκ�	

	int demo;
	
	cout<<"�÷��̾�� ī�带 2���ݴϱ�? 1. �� 2. �ƴϿ�"<<endl; 
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
	//ī�� ���� 
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
	
		
	A.SGivecard(); // ī�� ó�� 5�徿 �÷��̾�� �ֱ� 


	cout<< "���� �־��� ī�� " << endl;
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
	
	A.Givecard2(); //ī�� 2�� �����Լ� 
	A.Givecard2();
	A.Givecard2();
	
	return 0;
}
