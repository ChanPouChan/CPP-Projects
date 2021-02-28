#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int numOfPacksPerStore[10];
long curNumOfPacksPerStore[10];
int numOfPacksInTruck;
long numOfPacketsCreated;

int myRand(){
	int i=log(rand());
}

struct dema{
	int id;
	int idKatastnmatos;
	int	xwros;
};

void printPacketsOfStore(int idKat,dema *demataToPrint,int size){
	cout << "Stores' " << idKat<< " packets are: \n";
	for (int i=0;i<size;i++){
		cout <<  i << ". {"<< demataToPrint[i].id << "," <<demataToPrint[i].idKatastnmatos<<"," <<demataToPrint[i].xwros<<"}\t";
	}
	cout << "\n";
}

void printPacketsOfTruck(dema *demataToTruck,int size){
	cout << "Truck has the following packets: \n";
	for (int i=0;i<size;i++){
		cout <<  i << ". {"<< demataToTruck[i].id << "," <<demataToTruck[i].idKatastnmatos<<"," <<demataToTruck[i].xwros<<"}\t";
	}
	cout << "\n";
}

void printPacketsInStores(int *sizes){
	cout << "Each store has the following number of packets in: \n";
	for (int i=0;i<10;i++){
		cout <<  i << ". "<<sizes[i]<<"\t";
	}
	cout << "\n";
}

dema *getDemata(int idKat, int _id){
	int numOfDemata=myRand();
	numOfPacksPerStore[idKat]+=numOfDemata;
	curNumOfPacksPerStore[idKat]=numOfDemata;
	dema *demata=new dema[numOfDemata];
	for (int i=0;i<numOfDemata;i++){
		demata[i].id=numOfPacketsCreated++;
		demata[i].idKatastnmatos=idKat;
		demata[i].xwros=myRand();
	}
	return demata;
}

int sumOfPacketsInAllStores(int *sizes){
	int sum=0;
	for (int i=0;i<10;i++)
		sum+=sizes[i];
	return sum;
}

dema *demataToTruck(dema * (&_demataToTruck)[10], int *sizes,int space){
	int spaceRequired=0;
	//int numOfPackets=0;
	numOfPacksInTruck=0;
	dema *demata,*tmpArray;//=new dema[numOfPacksInTruck+1];
	int currentPacketSpace=0;
	while (spaceRequired+currentPacketSpace<=space && sumOfPacketsInAllStores(sizes))
		for (int i=0;i<10;i++){
			if (sizes[i]){
				currentPacketSpace=_demataToTruck[i][0].xwros;
				if (currentPacketSpace+spaceRequired>space)
					i++;//break;
				else{
					//put first dema from i store in truck
						if (numOfPacksInTruck){
							tmpArray=new dema[numOfPacksInTruck+1];							
							for (int j=0;j<numOfPacksInTruck;j++)
								tmpArray[j]=demata[j];
							delete [] demata;	
							demata=tmpArray;
						}else{
							demata=new dema[numOfPacksInTruck+1];
						}
						demata[numOfPacksInTruck++]=_demataToTruck[i][0];
					//Au3nse tov xwro pou exei katalnf8ei sto fortngo
						spaceRequired+=currentPacketSpace;
					//delete dema from i store
						if (sizes[i]>1){
							tmpArray=new dema[--sizes[i]];
							for (int j=1;j<sizes[i]+1;j++)
								tmpArray[j-1]=_demataToTruck[i][j];
							delete [] _demataToTruck[i];	
							_demataToTruck[i]=tmpArray;
						}else{
							sizes[i]--;
							delete [] _demataToTruck[i];
						}
					}
				}
		}
	return demata;
}

int main(){
	dema *packets[10];	
	dema *tmpPackets;	
	dema *tmpPackets2;//numPacksPerStore
	numOfPacketsCreated=0;
	for (int i=0;i<10;i++)
		numOfPacksPerStore[i]=0;
	for (int r=0;r<300;r++){
		numOfPacksInTruck=0;
		for (int store=0;store<10;store++){
			//Dnmiourgnse ta demata gia ka8e katastnma
				tmpPackets=getDemata(store,numOfPacksPerStore[store]);
				if(numOfPacksPerStore[store]!=curNumOfPacksPerStore[store]){
					tmpPackets2=new dema[numOfPacksPerStore[store]];
					for (int i=0;i<numOfPacksPerStore[store]-curNumOfPacksPerStore[store];i++)
						tmpPackets2[i]=packets[store][i];
					for (int i=numOfPacksPerStore[store]-curNumOfPacksPerStore[store];i<numOfPacksPerStore[store];i++)
						tmpPackets2[i]=tmpPackets[i-numOfPacksPerStore[store]+curNumOfPacksPerStore[store]];
					if (numOfPacksPerStore[store]-curNumOfPacksPerStore[store]>1)
						delete [] packets[store];
					packets[store]=new dema[numOfPacksPerStore[store]];
					packets[store]=tmpPackets2;
				}else{//{3, 9, 9, 5, 8, 9, 8, 10, 10, 9}
					packets[store]=tmpPackets;
				}
		}
		//Gemise to fortngo
			tmpPackets=demataToTruck(packets, numOfPacksPerStore,715);
			printPacketsOfTruck(tmpPackets,numOfPacksInTruck);
			printPacketsInStores(numOfPacksPerStore);
	}
	return 0;
}
