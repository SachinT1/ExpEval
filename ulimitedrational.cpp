/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"


int bigger(UnlimitedInt *i1, UnlimitedInt *i2){
    if (i1->get_size() > i2->get_size()){
        return 1;
    }
    if (i1->get_size() < i2->get_size()){
        return -1;
    }

    for (int i = i1->get_size() - 1; i >= 0; i--){
        if (i1->get_array()[i] < i2->get_array()[i])
            return -1;
        if (i1->get_array()[i] > i2->get_array()[i])
            return 1;
    }

    return 0;
}

UnlimitedInt* gcd(UnlimitedInt* i1,UnlimitedInt* i2){
	int u = bigger(i1,i2);
	if(u==0){
		return i1;
	}

	else if(u==1){
		UnlimitedInt* ans;
		UnlimitedInt* temp;
		temp = UnlimitedInt::mod(i1,i2);
		ans = temp;
		while(temp->get_sign()!=0){
			ans = temp;
			temp= UnlimitedInt::mod(i2,temp);


		}
		return ans;
	}
	else{
		return gcd(i2,i1);
	}
}


UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){
	if(den->to_string()=="0"){
		p = den;
		q = den;
	}
	else{
		p= UnlimitedInt::div(num,gcd(num,den));
		q= UnlimitedInt::div(den,gcd(num,den));
	}

}
UnlimitedRational::UnlimitedRational(){
	p=new UnlimitedInt();
	q=new UnlimitedInt();
}
UnlimitedRational::~UnlimitedRational(){
	delete p;
	delete q;
}

UnlimitedInt* UnlimitedRational::get_p(){
	return p;
}

UnlimitedInt* UnlimitedRational::get_q(){
	return q;
}

string UnlimitedRational::get_p_str(){
	return p->UnlimitedInt::to_string();
} 

string UnlimitedRational::get_q_str(){
	return q->UnlimitedInt::to_string();
} 

string UnlimitedRational::get_frac_str(){
	string ans = "";
	ans+=get_p_str();
	ans+="/";
	ans+=get_q_str();
	return ans;
}



UnlimitedRational* UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2){
	if((i1->get_q_str()=="0")||(i2->get_q_str()=="0")){
		UnlimitedInt* zero= new UnlimitedInt(0);
		UnlimitedRational* answer = new UnlimitedRational(zero,zero);
		return answer;
	}

	UnlimitedInt* e = UnlimitedInt::add((UnlimitedInt::mul(i1->get_p(),i2->get_q())),(UnlimitedInt::mul(i1->get_q(),i2->get_p())));
	UnlimitedInt* f = UnlimitedInt::mul(i1->get_q(),i2->get_q());

	UnlimitedInt* g = gcd(e,f);

	UnlimitedInt* numer = UnlimitedInt::div(e,g);
	UnlimitedInt* denom = UnlimitedInt::div(f,g);

	UnlimitedRational* answer= new UnlimitedRational(numer,denom);
	return answer;

}

UnlimitedRational* UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2){
	if((i1->get_q_str()=="0")||(i2->get_q_str()=="0")){
		UnlimitedInt* zero= new UnlimitedInt(0);
		UnlimitedRational* answer = new UnlimitedRational(zero,zero);
		return answer;
	}

	UnlimitedInt* e = UnlimitedInt::sub((UnlimitedInt::mul(i1->get_p(),i2->get_q())),(UnlimitedInt::mul(i1->get_q(),i2->get_p())));
	UnlimitedInt* f = UnlimitedInt::mul(i1->get_q(),i2->get_q());

	UnlimitedInt* g = gcd(e,f);

	UnlimitedInt* numer = UnlimitedInt::div(e,g);
	UnlimitedInt* denom = UnlimitedInt::div(f,g);

	UnlimitedRational* answer =new UnlimitedRational(numer,denom);
	return answer;

}

UnlimitedRational* UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2){
	if((i1->get_q_str()=="0")||(i2->get_q_str()=="0")){
		UnlimitedInt* zero= new UnlimitedInt(0);
		UnlimitedRational* answer = new UnlimitedRational(zero,zero);
		return answer;
	}
	

	UnlimitedInt* e = UnlimitedInt::mul(i1->get_p(),i2->get_p());
	UnlimitedInt* f = UnlimitedInt::mul(i2->get_q(),i2->get_q());

	UnlimitedInt* g = gcd(e,f);

	UnlimitedInt* numer = UnlimitedInt::div(e,g);
	UnlimitedInt* denom = UnlimitedInt::div(f,g);

	UnlimitedRational* answer =new UnlimitedRational(numer,denom);;
	return answer;

}

UnlimitedRational* UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){
	if((i1->get_q_str()=="0")||(i2->get_p_str()=="0")){
		UnlimitedInt* zero= new UnlimitedInt(0);
		UnlimitedRational* a = new UnlimitedRational(zero,zero);
		return a;
	}

	UnlimitedInt* e = UnlimitedInt::mul(i1->get_p(),i2->get_q());
	UnlimitedInt* f = UnlimitedInt::mul(i2->get_q(),i2->get_p());

	UnlimitedInt* g = gcd(e,f);

	UnlimitedInt* numer = UnlimitedInt::div(e,g);
	UnlimitedInt* denom = UnlimitedInt::div(f,g);



	UnlimitedRational* answer =new UnlimitedRational(numer,denom);;
	return answer;

}




