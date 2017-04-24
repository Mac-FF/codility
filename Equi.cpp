#include <iostream>
#include <vector>

long long sumRight(std::vector<int> & A, size_t index)
{
    long long rightSum = 0;
    for(size_t i = index + 1; i < A.size(); i++)
    {
        rightSum += A[i];
    }
    return rightSum;
}

int solution(std::vector<int> &A) {
    if (A.empty())
        return -1;

    long long  sumR = 0;
    long long  sumL = 0;
    for (size_t index = 0; index < A.size(); index++)
    {
        if(!index)
        {
            sumR = sumRight(A, 0);
            sumL = 0;
        }else
        {
            sumR -= A[index];
            sumL += A[index - 1];
        }

        if (sumR == sumL)
        {
            return index;
        }
    }
    return -1;
}


int main()
{
    std::vector<int> A = {-1, 3, -4, 5, 1, -6, 2, 1};
    std::cout << solution(A) << std::endl;

    return 0;
}
