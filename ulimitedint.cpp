/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"

UnlimitedInt::UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz){
	sign = sgn;
	size = sz;
	capacity = cap;
	unlimited_int = ulimited_int;
	
}


UnlimitedInt* comp(UnlimitedInt* num,int size){
	int* arr = num->get_array();
	
	
	int n;
	if(size<=num->get_size()){
		n=num->get_size();
	}


	else{
		n = size;
	}
	int* newarr= new int[n];


	if(size<=num->get_size()){
	
	
		for(int i=0;i<num->get_size();i++){
			newarr[i]= arr[i];
		}
	}
	else{
	

		for(int i=0;i<num->get_size();i++){
			newarr[i]= arr[i];
		}
		for(int i=num->get_size();i<size;i++){
			newarr[i]=0;
		}
	}


	


	for(int i=0;i<n;i++){
		newarr[i] = 9 - newarr[i];
		
	}

	int carry = 1;
	int temp;
	for(int i=0;i<n;i++){
		temp = newarr[i]+carry;
		newarr[i]= temp%10;
		carry= temp/10;
	}
	int ts = n;
	while(newarr[ts-1]==0){
		ts--;
	}
	int* final = new int[ts];
	for(int i=0;i<ts;i++){
		final[i]=newarr[i];
	}

	UnlimitedInt* ans = new UnlimitedInt(final,ts,1,ts);
	
	return ans;
}



UnlimitedInt::UnlimitedInt(int i){
	int s=1;
	if(i>0){
		sign = 1;
	}
	else if(i<0){
		sign = -1;
	}
	else{
		sign = 0;
	}
	

	int x = i*(sign);
	
	
	
	while((x/10)>0){

		
		
		x=x/10;
		s++;

	}
	
	size = s;

	
	int* arr = new int[s];
	

	int q=0;
	x=i*sign;

	while((x/10)>0){
		arr[q]= x%10;
	
	
		x=x/10;
		q++;

	}
	arr[q] = x%10;
	capacity = size;
	
	unlimited_int=arr;
	

	

	
	

	
	
	 
	
		
	
}

UnlimitedInt::UnlimitedInt(string s){
	if(s[0]=='-'){
		sign = -1;
		size = s.size()-1;
	}
	else{
		if(s[0]=='0'){
			sign = 0;
			size = 1;
		}
		else{
			sign = 1;
			size = s.size();
			
		}
	}
	int* arr = new int[size];
	if(sign>-1){
		for(int j=0;j<s.size();j++){
			char c = s[j];
			
			arr[size-1-j]=int(c)-48;

		}
	}
	else{
		for(int j=1;j<s.size();j++){
			char c = s[j];
			
			arr[size-j]=int(c)-48;
		}
	}
	
	capacity = size;
	unlimited_int = arr;
	
	
	
	
}

UnlimitedInt::UnlimitedInt(){
	size = 0;
	sign = 0;
	capacity = 1;
	int arr[capacity];
	unlimited_int=arr;
}

UnlimitedInt::~UnlimitedInt(){
	delete unlimited_int;
	
}


int UnlimitedInt::get_size(){
	return size;
}

int UnlimitedInt::get_sign(){
	return sign;
}

int UnlimitedInt::get_capacity(){
	return capacity;
}

int* UnlimitedInt::get_array(){

	return unlimited_int;
}

UnlimitedInt* UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2){
	int carry=0;
	int cap = max(i1->get_size(),i2->get_size())+1;
	
	int* arr1 = i1->get_array();
	int* arr2 = i2->get_array();
	
	


	if(  ((i1->get_sign()>0)&&(i2->get_sign()>=0))  ||  ((i1->get_sign()>0)&&(i2->get_sign()>=0)) || ((i1->get_sign()<0)&&(i2->get_sign()<=0))||((i1->get_sign()<=0)&&(i2->get_sign()<0)) ){
		
		
		int ansarr[cap];


		
		for(int i=0;i<min(i1->get_size(),i2->get_size());i++){
						
			
			if(arr1[i]+arr2[i]+carry<10){
				ansarr[i]=arr1[i]+arr2[i]+carry;

				
				carry=0;
			}
			else{
				ansarr[i]=(arr1[i]+arr2[i]+carry)%10;
				
				carry =1;
			}
		}
		if(i1->get_size()>i2->get_size()){

			for(int i=i2->get_size();i<i1->get_size();i++){
				
				if(arr1[i]+carry>10){
					ansarr[i]=(arr1[i]+carry)%10;
					
					carry=1;
				}
				else{
					ansarr[i]=arr1[i]+carry;
					
					carry=0;
				}

			}
			ansarr[i1->get_size()]=carry;
			carry=0;
			
		}
		else if(i1->get_size()<i2->get_size()){
			for(int i=i1->get_size();i<i2->get_size();i++){
				if(arr1[i]+carry>10){
					ansarr[i]=(arr2[i]+carry)%10;
					
					carry=1;
				}
				else{
					ansarr[i]=arr2[i]+carry;
					
					carry=0;
				}

			}
			ansarr[i2->get_size()]=carry;
			
		}
		else{
			ansarr[i1->get_size()]=carry;

		
		}
		

		

		int truesize=cap;
		for(int i=cap-1;i>=0;i--){
			if(ansarr[i]==0){
				truesize--;
			}
			else{
				break;
			}
		}

		int* truearr= new int[truesize];

		for(int i=truesize-1;i>=0;i--){
			truearr[i]=ansarr[i];
		}

		

		if( ((i1->get_sign()>0)&&(i2->get_sign()>=0))  ||  ((i1->get_sign()>0)&&(i2->get_sign()>=0)) ){
			UnlimitedInt* ans = new UnlimitedInt(truearr,truesize,1,truesize);




		
		return ans;
		}
		else{
			UnlimitedInt* ans = new UnlimitedInt(truearr,truesize,-1,truesize);

		return ans;
		}
		
		


	}
	else if((i1->get_sign()==0)&&(i2->get_sign()==0)){
		int arr[1];
		arr[0]=0;
		int* p = arr;
		UnlimitedInt* ans = new UnlimitedInt(p,1,0,1);
		return ans;

	}

	else{
		if(i1->get_sign()==-1){
			UnlimitedInt* a = comp(i1,i2->get_size());

			UnlimitedInt* b = UnlimitedInt::add(a,i2);
			int* arr = b->get_array();
			int o = arr[b->get_size()-1];



			if(o==1){
				


				
				int trues = b->get_size()-1;
				while((arr[trues-1]==0)&&(trues>=1)){
					trues--;
				}
				if(trues==0){

					UnlimitedInt* h = new UnlimitedInt(0);
					return h;
				}
				int* res = new int[trues];
				for(int i=0;i<trues;i++){
					res[i]=arr[i];
				}

				UnlimitedInt* result = new UnlimitedInt(res,trues,1,trues);
				return result;
			}

			else{
				
				UnlimitedInt* d = comp(b,b->get_size());
				int* t = d->get_array();
				int s = d->get_size();
				UnlimitedInt* result = new UnlimitedInt(t,s,-1,s);
				return result;
			}

		}

		else{
			return(add(i2,i1));
		}

		
	}
}



UnlimitedInt* UnlimitedInt::sub(UnlimitedInt* i1, UnlimitedInt* i2){
	int sin = (i2->get_sign())*(-1);
	int siz= i2->get_size();
	int* arr= i2->get_array();
	int cap = i2->get_capacity();
	UnlimitedInt* pseudo = new UnlimitedInt(arr,cap,sin,siz);
	
	
	UnlimitedInt* ans= UnlimitedInt::add(i1,pseudo);
	
	
	
	return ans;
}

UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2){
	if((i1->get_sign()==0)||(i2->get_sign()==0)){
		int* arr= new int[1];
		arr[0]=0;
		
		UnlimitedInt* ans = new UnlimitedInt(arr,1,0,1);
		return ans;

	}

	int* arr1= i1->get_array();
	int* arr2= i2->get_array();
	int siz = i1->get_size()+i2->get_size();
	int ansarr[siz];
	
	for(int i=0;i<siz;i++){
		ansarr[i]=0;	
	}

	if(i1->get_size()>i2->get_size()){
		int mult;
		for(int i=0;i<i2->get_size();i++){
			mult = arr2[i];
			for(int j=0;j<i1->get_size();j++){
				ansarr[i+j]+=mult*arr1[j];
			}

		}

		int temp=0;
		int carry=0;
		for(int i=0;i<siz;i++){
			temp = (ansarr[i]+carry)%10;
			carry = (ansarr[i]+carry-temp)/10;
			ansarr[i]=temp;
		}
		int truesize=siz;
		while(ansarr[truesize-1]==0){
			truesize--;
		}
		int* truearr= new int[truesize];
		for(int i=0;i<truesize;i++){
			truearr[i]=ansarr[i];
		}

		
		int s = (i1->get_sign())*(i2->get_sign());
		UnlimitedInt* ans = new UnlimitedInt(truearr,truesize,s,truesize);
		return ans;
	}

	else if(i2->get_size()>i1->get_size()){
		int mult;
		for(int i=0;i<i1->get_size();i++){
			mult = arr1[i];
			for(int j=0;j<i2->get_size();j++){
				ansarr[i+j]+=mult*arr2[j];
			}

		}

		int temp=0;
		int carry=0;
		for(int i=0;i<siz;i++){
			temp = (ansarr[i]+carry)%10;
			carry = (ansarr[i]+carry-temp)/10;
			ansarr[i]=temp;
		}
		int truesize=siz;
		while(ansarr[truesize-1]==0){
			truesize--;
		}
		int* truearr = new int[truesize];
		for(int i=0;i<truesize;i++){
			truearr[i]=ansarr[i];
		}

		
		int s = (i1->get_sign())*(i2->get_sign());
		UnlimitedInt* ans = new UnlimitedInt(truearr,truesize,s,truesize);
		return ans;
	}


	else{
		int mult;
		for(int i=0;i<i2->get_size();i++){
			mult = arr2[i];
			for(int j=0;j<i1->get_size();j++){
				ansarr[i+j]+=mult*arr1[j];
			}

		}

		int temp=0;
		int carry=0;
		for(int i=0;i<siz;i++){
			temp = (ansarr[i]+carry)%10;
			carry = (ansarr[i]+carry-temp)/10;
			ansarr[i]=temp;
		}
		int truesize=siz;
		while(ansarr[truesize-1]==0){
			truesize--;
		}
		int* truearr= new int[truesize];
		for(int i=0;i<truesize;i++){
			truearr[i]=ansarr[i];
		}

		
		int s = (i1->get_sign())*(i2->get_sign());
		UnlimitedInt* ans = new UnlimitedInt(truearr,truesize,s,truesize);
		return ans;


	}
}

UnlimitedInt* UnlimitedInt::div(UnlimitedInt* i1, UnlimitedInt* i2){
	if(i1->get_size()<i2->get_size()){
		if((i1->get_sign())*i2->get_sign()==1){
			int arr[1];
			arr[0]=0;
			int* p = arr;

			UnlimitedInt* ans = new UnlimitedInt(p,1,0,1);
			return ans;
	}
		else if((i1->get_sign())*(i2->get_sign())==-1){
			
			
			int *p = new int[1];
			p[0]= 1;
			UnlimitedInt* ans = new UnlimitedInt(p,1,-1,1);
			return ans;
		}

		else if((i1->get_sign()==0)&&(i2->get_sign()!=0)){
			int arr[1];
			arr[0]=0;
			int* p = arr;
			UnlimitedInt* ans = new UnlimitedInt(p,1,0,1);
			return ans;

		}

		else{
			return nullptr;
		}
	}


	else{
		if((i1->get_sign()==0)&&(i2->get_sign()!=0)){
			int arr[1];
			arr[0]=0;
			int* p = arr;
			UnlimitedInt* ans = new UnlimitedInt(p,1,0,1);
			return ans;

		}
	
		else if(i2->get_sign()==0){
			return nullptr;
		}

			
		else{
			string ans;
			int n1=i1->get_size();
			int n2=i2->get_size();
			string dividend;
			if(i1->get_sign()==-1){
				
				string a;
				a = i1->to_string();
				for(int i=1;i<a.size();i++){
					dividend+=a[i];
				}

			}

			else{
				dividend=i1->to_string();
			}
			string divid = dividend.substr(0,n2);
			

			string remainder;
			remainder = "";
			UnlimitedInt* divd =  new UnlimitedInt(divid);
			int q = 1;
			UnlimitedInt* itwo = new UnlimitedInt(i2->get_array(),i2->get_size(),1,i2->get_size());

			
			UnlimitedInt* qot = new UnlimitedInt(q);
			int index = n2;
			
			while(index<=n1){
				
				
				

				while(sub(divd,mul(itwo,qot))->get_sign()>=0){
					
					
					q++;
					delete qot;

					UnlimitedInt* qot =new UnlimitedInt(q);
										
					
				}

				
				delete qot;
				q--;
				
				
				
				UnlimitedInt* qot = new UnlimitedInt(q);
				ans+= qot->to_string();
	
				
				remainder = sub(divd,mul(itwo,qot))->to_string();
				
				if(index<n1){

				
				divid = remainder + dividend[index];


				
				delete divd;

				UnlimitedInt* divd = new UnlimitedInt(divid);
				
				q=1;
				delete qot;
				qot = new UnlimitedInt(q);
				index++;

			    }
			    else{
			    	index++;
			    }




			}
			if(ans=="0"){
				
				int sin = (i1->get_sign())*(i2->get_sign());
				if(sin==-1){
					int arr[1];
					arr[0]=1;
					int* p = arr;
					UnlimitedInt* ans = new UnlimitedInt(p,1,-1,1);
				return ans;

				}
				else{
					int arr[1];
					arr[0]=0;
					int* p = arr;
					UnlimitedInt* ans = new UnlimitedInt(p,1,0,1);
				return ans;

				}
			

			}
			int ind=0;
			int trues = ans.size();
			while(ans[ind]=='0'){
				ind++;
				trues--;
			}


			string answ = ans.substr(ind,trues);
			
			
			

			if((i1->get_sign())*(i2->get_sign())==1){
				UnlimitedInt* node = new UnlimitedInt(answ);
				return node;
			}
			else{
				UnlimitedInt* pseudo = new UnlimitedInt(answ);
				int sin = -1;
				int siz= pseudo->get_size();
				int* arr= pseudo->get_array();
				int cap = pseudo->get_capacity();
				UnlimitedInt* real = new UnlimitedInt(arr,cap,sin,siz);
				return UnlimitedInt::add(real,new UnlimitedInt(-1));
			}

		}
}
}

UnlimitedInt* UnlimitedInt::mod(UnlimitedInt* i1, UnlimitedInt* i2){
	UnlimitedInt* c = sub(i1,mul(i2,(div(i1,i2))));


	return c;
}

string UnlimitedInt::to_string(){

	
	
	string ans="";
	if(sign==0){
		return "0";
	}
	else if(sign==-1){
		ans+='-';
	}
	int* p = unlimited_int;
	for(int i=size-1;i>=0;i--){
		int k = *(p+i);

		if(k==0){
			ans+='0';
		}
		else if(k==1){
			ans+="1";
		}
		else if(k==2){
			ans+='2';
		}
		else if(k==3){
			ans+='3';
		}
		else if(k==4){
			ans+='4';
		}
		else if(k==5){
			ans+='5';
		}
		else if(k==6){
			ans+='6';
		}
		else if(k==7){
			ans+='7';
		}
		else if(k==8){
			ans+='8';
		}
		else if(k==9){
			ans+='9';
		}
	}

	return ans;
	
}











