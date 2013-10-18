float haltonsequence(int index, int base){
    float result=0.0;
    float f=1.0/base;
    int ri=index;
    while(ri>0){
        result += f*(ri%base);
        ri=int(ri/base);
        f/=base;
    }
    return result;
}

vector haltonsequence(int index){
    return vector(haltonsequence(index,2),
                  haltonsequence(index,3),
                  haltonsequence(index,5));
}
