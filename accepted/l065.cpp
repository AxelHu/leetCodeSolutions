// "l65.cpp" -*- C++ -*-
//  Valid Number

bool isNumber(string s) {
        // rules: 1. with only digits(0~9)
        //        2. no more than one '.'
        //        3. scientific notation support
        //        4. '.' & 'e' should not be the first and the 
        //        5. ignore starting and finishing space
        //        6. minus sign, before all digits & after 'e'
        //        7.   .1 is legal, are you kidding me?
        //        8.   3. is legal, ok you win
        //        9.   +.8    .............
        if(s.size() == 0)
            return false;
        const char* ptrToStr = s.c_str();
        int length = s.size();
        int dotCount = 0;
        int sciNotFlag = 0; // scientificNotationFlag
        int headSpace = 0;
        int tailSpace = 0;
        int signFlag = 0; // none: 0000, + :1000, - : 0010, e+: 0100, e-: 0001
        int sciNotPos = -1;
        // pick headSpace first
        for(int i = 0; i < length; i++)
        {
            if(ptrToStr[i] == ' ')
                headSpace++;
            else
                break;
        }
        if(headSpace == length) // all space
            return false;
        for(int i = headSpace; i < length; i++)
        {
            if(ptrToStr[i] >= '0' && ptrToStr[i] <= '9')
            // do nothing
            ;
            else if(ptrToStr[i] == '.' && dotCount == 0)
                dotCount += 1;
            else if(ptrToStr[i] == '.' && dotCount == 1)
                return false;
            else if(ptrToStr[i] == 'e' && sciNotFlag == 0)
            {
                sciNotFlag = 1;
                sciNotPos = i;
                dotCount = 1; // no '.' in the number after 'e'
            }
            else if(ptrToStr[i] == '-' && (signFlag & 0b1010) == 0 && i == headSpace)
                signFlag |= 0b0010;
            else if(ptrToStr[i] == '-' && (signFlag & 0b0101) == 0 && i == (sciNotPos+1))
                signFlag |= 0b0001;
            else if(ptrToStr[i] == '+' && (signFlag & 0b1010) == 0 && i == headSpace)
                signFlag |= 0b1000;
            else if(ptrToStr[i] == '+' && (signFlag & 0b0101) == 0 && i == (sciNotPos+1))
                signFlag |= 0b0100;
            else if(ptrToStr[i] == ' ')
            {
                tailSpace = i; // temporary remember position
                break;
            }
            else 
                return false;
        }
        // pick tailSpace
        for(int i = tailSpace; i < length; i++)
        {
            if(tailSpace == 0) // no tail space
            {
                tailSpace = length; // set tailSpace to end position in order to check later
                break;
            }
            if(ptrToStr[i] != ' ')
                return false;
        }
        // for signs
        if(signFlag != 0)
        {
            if((signFlag & 0b1010) != 0)
              headSpace++;
            if(headSpace >= length)
                return false;
            else if(headSpace >= tailSpace)
                return false;
            else if((signFlag & 0b0101) != 0 && sciNotPos+2 >= length)
                return false;
        }
        // for 'e' and '.'
        if(s[headSpace] == 'e' /*|| s[headSpace] == '.' || s[tailSpace-1] == '.' */|| s[tailSpace-1] == 'e')
            return false;
        else if(s[headSpace] == '.')
        {
            if(headSpace+1 >= length)
                return false;
            else if(!(s[headSpace+1] >= '0' && s[headSpace+1] <= '9'))
                return false;
                
        }
        else if(s[tailSpace-1] == '.')
        {
            // space/nothing after
            if(tailSpace == length)
                return true;
        }
        return true;
    }