#include <iostream>
#include <vector>
#include <algorithm>

void view(std::vector<int> & A)
{
    for (size_t index = 0; index < A.size(); index++)
    {
        std::cout << index << " : " << A[index] << std::endl;
    }
}

int solution(std::vector<int> &A)
{
    if (A.empty())
        return 0;

    std::sort(A.begin(), A.end());

    int previousElement;
    int amplitudeIndex;
    bool foundAmplitude = false;
    int previousLength = 1;
    int length = 0;

    for (size_t index = 0; index < A.size(); index++)
    {
        if(!index)
        {
            length = 0;
            previousElement = A[index];
        }
        //std::cout << "INDEX: "<< index << " ";

        if(previousElement + 2 > A[index])
        {
            length += 1;
            if (previousElement + 1 == A[index] && !foundAmplitude)
            {
                amplitudeIndex = index;
                foundAmplitude = true;
                //std::cout << " FOUND Amplitude: "<< index << " ";
            }
            //std::cout << " LENGTH: " << length << std::endl;
        }else
        {
            //std::cout << " GREATER: " << index << ",";
            if (previousLength < length)
            {
                //std::cout << " LENGTH " << length << " > " << previousLength << " PREV" << std::endl;
                previousLength = length;
            }

            if (foundAmplitude)
            {
                previousElement = A[amplitudeIndex];
                index = amplitudeIndex - 1;
                foundAmplitude = false;
            }else
            {
                previousElement = A[index];
                index -= 1;
            }
            
            length = 0;
        }
    }

    if (previousLength < length)
    {
        //std::cout << "    LENGTH " << length << " > " << previousLength << " PREV" << std::endl;
        return length;
    }
    return previousLength;
}


int main()
{
    std::vector<int> A = {6,10,6,9,7,8};
    std::cout << std::endl << solution(A) << std::endl;
    return 0;
}
