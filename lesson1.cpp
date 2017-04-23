int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int gapSize = 0;
    int reminder = 0;
    int bufor;
    bool findOne = false;
    while(N)
    {
        bufor = N%2;
        N /= 2;
        if(bufor)
            findOne = true;

        if (!bufor && findOne)
        {
            reminder ++;
        }else
        {
            if (reminder > gapSize)
            {
                gapSize = reminder;
            }
            reminder = 0;
        }
    }
    return gapSize;
}
