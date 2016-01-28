//------------------------------------------------------------------------------
// Copyright (c) Jonas Sundberg <jsund@jsund.com>.
// This software has been released under the terms of the ISC license,
// compatible with the MIT license in LICENSE.txt
//------------------------------------------------------------------------------

extern "C"
{
    HRESULT PALAPI
    StringCchVPrintfExW(
            LPWSTR pszDest,
            size_t cchDest,
            LPWSTR * ppszDestEnd,
            size_t * pcchRemaining,
            DWORD dwFlags,
            LPCWSTR pszFormat,
            va_list argList) {
        /* This function has a generic implementation in
         * vprintf_generic.h. */
        #define STRSAFE_GENERIC_WIDE_CHAR 1
        #include "vprintf_generic.hpp"
        #undef STRSAFE_GENERIC_WIDE_CHAR
    }

    HRESULT PALAPI
    StringCchVPrintfW(
            LPWSTR pszDest,
            size_t cchDest,
            LPCWSTR pszFormat,
            va_list argList) {
        return StringCchVPrintfExW(pszDest, cchDest, NULL, NULL, 0,
                pszFormat, argList);
    }

    HRESULT PALAPI
    StringCchPrintfW(
            LPWSTR pszDest,
            size_t cchDest,
            LPCWSTR pszFormat,
            ...) {
        va_list argList;
        HRESULT result;

        va_start(argList, pszFormat);
        result = StringCchVPrintfW(pszDest, cchDest, pszFormat, argList);
        va_end(argList);

        return result;
    }
}
