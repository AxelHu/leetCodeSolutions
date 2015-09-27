// "l3.cpp" -*- C++ -*-
// Longest substring without repeating characters

#define ASCIINUM 256

int lengthOfLongestSubstring(string s)
{
  int alphaSet[ASCIINUM] = {0};
  int currentHead = 1;
  int currentTail = 1;
  int maxLength = 0;
  int currentLength = 0;
  int temp = 0;
  int totalLength = s.size();
  const char* ptrToStr = s.c_str();
  for(int i = 0; i < totalLength; i++)
    {
      //  if a~z & A~Z allowed only
      //  temp = *ptrToStr > 'Z'? *ptrToStr - 'a': *ptrToStr - 'A' + 26 ;
      temp = *ptrToStr - 0;
      ptrToStr++;
      if(alphaSet[temp] < currentTail)
	{
	  alphaSet[temp] = currentHead;
	  currentLength ++;
	}
      else
	{
	  currentTail = alphaSet[temp] + 1;
	  alphaSet[temp] = currentHead;
	  if(currentLength > maxLength)
	    maxLength = currentLength;
	  currentLength = currentHead - currentTail + 1;
	}
      currentHead ++;
    }
  if(currentLength > maxLength)
    maxLength = currentLength;
  return maxLength;
}
