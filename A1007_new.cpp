#include<iostream>
using namespace std;
const int maxn=10010;
int dp[maxn];//dp[i]�����a[i]Ϊ��β���������е�����
int a[maxn];
int s[maxn]={0};

int main(){
	
	int n;
	cin>>n;
	//�������ĳ�bool flag;������ʼ���Ļ������Ե�4����ȥ 
	//���������1->bool flag=false;
	//          2->��main�������涨��bool flag;����flagĬ��Ϊfalse���������������������ֵ 
	bool flag=false;//flag=false��ʾȫΪ����
	
	for(int i=0;i<n;i++){
	  cin>>a[i];
	  if(a[i]>=0)
	    flag=true;
    }
	if(flag==false)//���ȫ�Ǹ���
	{
		cout<<0<<" "<<a[0]<<" "<<a[n-1];
		return 0;
	} 
	//��������к�
    dp[0]=a[0];
	for(int i=1;i<n;i++){
		if(dp[i-1]+a[i]>a[i]){//ѡa[i]
		   dp[i]=dp[i-1]+a[i]; 
		   s[i]=s[i-1];
		}else{//��ѡa[i] 
			dp[i]=a[i];
			s[i]=i; 
		}
	} 
	int k=0;
	for(int i=1;i<n;i++){
		if(dp[i]>dp[k])
		  k=i;
	}
	cout<<dp[k]<<" "<<a[s[k]]<<" "<<a[k];//��������������±� 
	return 0;
} 
//�Ұ������ע����д�����Ե�ȫ���ˣ�˵����ԭ���Ĳ��֣���̬�滮֮ǰ�ģ������� 
//#include<iostream>
//using namespace std;
//const int maxn=10010;
//int a[maxn],dp[maxn];
//int s[maxn]={0};
//
//
//int main(){
//	int n;
//	cin>>n;
//	bool flag=false;
//	for(int i=0;i<n;i++){
//	
//	  cin>>a[i];
//	  if(a[i]>=0)
//	    flag=true;
//    }
//    if(flag==false){
//    	cout<<0<<" "<<a[0]<<" "<<a[n-1];
//    	return 0;
//    }
//    dp[0]=a[0];
//    for(int i=1;i<n;i++){
//    	if(dp[i-1]+a[i]>a[i]){
//    		dp[i]=dp[i-1]+a[i];
//    		s[i]=s[i-1];
//    	}else{
//    		dp[i]=a[i];
//    		s[i]=i;
//    	}
//    }
//    int k=0;
//    for(int i=0;i<n;i++){
//    	if(dp[i] > dp[k])
//    	  k=i;
//    }
//    cout<<dp[k]<<" "<<a[s[k]]<<" "<<a[k];
//}




