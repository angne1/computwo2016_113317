#include<iostream>
#include<time.h>
#include<cstdlib>
#include<vector>
#include<assert.h>

using namespace std;

const int Maxcard = 52;


class Carddeck{ //���� 52�� ���� �� ���� ���� Ŭ���� 
		
	protected:
		vector<int> cards;  //52���� ���ڸ� ���� ���� 
		
	public:		
		
		Carddeck();
			 
		void CShuffle(); // �����Լ�   
		
};

	
Carddeck::Carddeck(){ //52�� ���� �ֱ� 
		
		
		for(int j=0; j<4; j++){
			for(int i=1; i<=13; i++){
			cards.push_back(i);
			  // ���� ī���� ������ ǥ���ϴ� ��Ʈ�� Num 
			  
			}
		}
			for(int i=0;i<cards.size();i++)
		cout << cards[i] << ' ';
	  //��¿� ���� Ȯ��  
	cout << endl;
		
		
		CShuffle(); // �����Լ���� 
		for(int i=0;i<cards.size();i++)
		cout << cards[i] << ' ';
	  //��¿� ����Ȯ�� 
	
		
}

void Carddeck::CShuffle(){
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



class Playerdeck : public Carddeck{ //�÷��̾ ���� �� ����(���� ī�带 �����ش�,�и� �޴´�.2��,6��) ���ڸ� �������� Carddeck ��� 
	public :
		Playerdeck();
		Playerdeck(int num);
		void playerdeck(int num);
		void Draw();
		void Givecard(bool s);			
		void Showcard();
}; 
	
Playerdeck::Playerdeck(int num){
	cout<<"�÷��̾��� ����:"<<num<<"���Դϴ�."<<endl;
	playerdeck(num);
}

void Playerdeck::Showcard(){
	
}
void Playerdeck::playerdeck(int num){ //�ο�üũ 
	if(num==2){
		for(int i=0;i<2; i++){
		
		}
	}
	Draw();
}


void Playerdeck::Draw(){ //�÷��̾�� ���ڸ�  6�� �ְ� ���ڸ� �����ش�. 
 	
	 
	cout<<"�÷��̾ ó�� �޴� ī��: ";
	for(int j=1; j<7; j++){
	cout<<cards[cards.size()-1]<<'\t';       //�ڿ������� ī�带 �����ش�. 
	cards.pop_back();               // ī�带 �����ظ�ŭ pop! 
	}
	cout<<endl;
	for(int i=0;i<cards.size();i++){
	
	cout << cards[i] << ' ';
	}
	cout<<endl;  //����Ȯ�� 
	
	
	
	cout<<cards.size()<<endl;
	Givecard(1);
	Givecard(1);
}
		

void Playerdeck::Givecard(bool s) {
	cout<<"�÷��̾ 2�� �޴� ī��: ";
	if(s){
	                  
	for(int j=1; j<3; j++){
	cout<<cards[cards.size()-1]<<'\t';
	cards.pop_back();
	}
	cout<<endl;
	for(int i=0;i<cards.size();i++)
	cout << cards[i] << ' ';
	  //����Ȯ�� 
	cout << endl;
	
	
	cout<<cards.size()<<endl;
	\
}
	if(false){
		cout<<"���� �����Դϴ�."<<endl; 
	}
		

}


class Game : public Playerdeck{ //������ ������ ����Ǵ� ��.  
								//���⼭ �÷��̾� ī�带 ���������� ������� �ʴ´�. 
	public :
	void Draw(){
		Game::playerdeck(false);//�÷��̾� ī�� ����� ���� playerdeck���� ��ӹ޾� ��� 
	
	} //�߰��Ұ� :�÷��̾  ī�带 ���� �� ī���� ���� �ջ��Ͽ� ī��Ʈ  ,ī�� �����Ǹ�ǥġ ǥ�� 
};






	
int main(){
 Playerdeck test1(1);
	return 0;
}						
