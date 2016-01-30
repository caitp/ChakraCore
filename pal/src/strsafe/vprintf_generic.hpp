//------------------------------------------------------------------------------
// Copyright (c) Jonas Sundberg <jsund@jsund.com>.
// This software has been released under the terms of the ISC license,
// compatible with the MIT license in LICENSE.txt
//------------------------------------------------------------------------------

#ifndef STRSAFE_GENERIC_WIDE_CHAR
#error "STRSAFE_GENERIC_WIDE_CHAR must be defined."
#elif STRSAFE_GENERIC_WIDE_CHAR == 0
#define STRSAFE_VPRINTF vsnprintf
#define STRSAFE_CHAR char
#define STRSAFE_TEXT(c) c
#else
#define STRSAFE_VPRINTF vswprintf
#define STRSAFE_CHAR WCHAR
#define STRSAFE_TEXT(c) L##c
#endif

size_t length;
HRESULT result = S_OK;

if(cchDest == 0 || cchDest > STRSAFE_MAX_CCH){
    /* Invalid value for cchDest. */
    return STRSAFE_E_INVALID_PARAMETER;
}

if((dwFlags & STRSAFE_IGNORE_NULLS) && pszFormat == NULL){
    length = 0;
    if(pszDest != NULL){
        *pszDest = STRSAFE_TEXT('\0');
    }
} else {
    int requiredLength =
            STRSAFE_VPRINTF(pszDest, cchDest, pszFormat, argList);
    length = (size_t)requiredLength;
    if(requiredLength < 0 || length >= cchDest){
        /* Data did not fit in pszDest. */
        if(dwFlags & (STRSAFE_NULL_ON_FAILURE | STRSAFE_NO_TRUNCATION)){
            /* pszDest should be set to the empty string. */
            length = 0;
        } else if(dwFlags & STRSAFE_FILL_ON_FAILURE){
            /* pszDest should be filled with the lower byte of dwFlags
             * and null terminated. */
            memset(pszDest, dwFlags & 0xff,
                    (cchDest - 1) * sizeof(STRSAFE_CHAR));
            length = cchDest - 1;
        } else {
            length = cchDest - 1;
        }
        pszDest[length] = STRSAFE_TEXT('\0');
        result = STRSAFE_E_INSUFFICIENT_BUFFER;
    }
}

if(ppszDestEnd != NULL){
    *ppszDestEnd = pszDest + length;
}
if(pcchRemaining != NULL){
    *pcchRemaining = cchDest - length;
}
if((dwFlags & STRSAFE_FILL_BEHIND_NULL) && length + 1 < cchDest){
    memset(pszDest + length + 1, dwFlags & 0xff,
            (cchDest - length - 1) * sizeof(STRSAFE_CHAR));
}

return result;

#undef STRSAFE_VPRINTF
#undef STRSAFE_CHAR
#undef STRSAFE_TEXT
