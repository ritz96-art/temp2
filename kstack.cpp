#include<iostream>
#include<stdlib.h>
#include<climits>
using namespace std;
class kstacks{
	int *array;
	int *top;
	int *next;
	int n,k;
	int free;
public:
	kstacks(int n1,int k1){
		n=n1;
		k=k1;
		array=new int[n];
		top=new int[k];
		next=new int[n];
		free=0;
		for( int i=0;i<n-1;i++ ){
			next[i]=i+1;
		}next[n-1]=-1;
		for( int i=0;i<k;i++ ){
			top[i]=-1;
		}
	}
	int peek(int sn){
		return top[sn];
	}
	bool isempty(int sn){
		if(top[sn]==-1)
			return true;
		return false;
	}
	bool isfull(){
		if(free==-1)
			return true;
		return false;
	}
	void push(int data,int sn){
		if(isfull()){
			cout<<"stack is overloaded"<<endl;
			exit(1);
		}
		else{
			int j=free;
			free=next[j];
			next[j]=top[sn];
			top[sn]=j;
			array[j]=data;
		}
	}
	int pop(int sn){
		if(isempty(sn)){
			cout<<"stack is underloaded"<<endl;
			exit(1);
		}
		else{
			int x=array[top[sn]];
			int j=top[sn];
			top[sn]=next[j];
			next[j]=free;
			free=j;
			return x;
		}
	}
};
int main()
{
	kstacks ks(10,3);
	ks.push(15,2);
	ks.push(45,2);
	ks.push(17,1);
	ks.push(49,1);
	ks.push(39,1);
	ks.push(11,0);
	ks.push(9,0);
	ks.push(7,0);
	cout<<"popped from stack 2 is "<<ks.pop(2)<<endl;
	cout<<"popped from stack 1 is "<<ks.pop(1)<<endl;
	cout<<"popped from stack 0 is "<<ks.pop(0)<<endl;
	cout<<"popped from stack 1 is "<<ks.pop(1)<<endl;
	cout<<"popped from stack 1 is "<<ks.pop(1)<<endl;
	cout<<"top of stack 1 is "<<ks.peek(1);
}