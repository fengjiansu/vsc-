int findMaxConsecutiveOnes(int tmp[], int len) {
    int Max = 0, Count = 0;
    for(int i=0;i<len;++i){
        if(tmp[i]==1) Count++;  // 连续计数
        else Count = 0;  // 一旦不连续计数就会清零
        if(Max<Count) Max = Count;  // 找出最大的值
    }
    return Max;
}