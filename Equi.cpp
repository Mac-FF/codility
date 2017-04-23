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

long long sumLeft(std::vector<int> & A, size_t index)
{
    long long leftSum = 0;
    for(size_t i = index; i > 0; i--)
    {
        leftSum += A[i - 1];
    }
    return leftSum;
}

int solution(std::vector<int> &A) {
    if (A.empty())
        return -1;

    for (size_t index = 0; index < A.size(); index++)
    {

        long long  sumR = sumRight(A, index);
        long long  sumL = sumLeft(A, index);
        std::cout << "P indeks : " << index << " suma: "<< sumR << std::endl;
        std::cout << "L indeks : " << index << " suma: "<< sumL << std::endl << std::endl;
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
