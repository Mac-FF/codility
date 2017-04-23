#include <iostream>

int solution(int N) {
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


int main()
{
    int N = 9;
    std::cout << solution(N) << std::endl;

    return 0;
}
