#ifndef MP_CHARSET_CONV_H
#define MP_CHARSET_CONV_H

#include <stdbool.h>
#include "mpvcore/bstr.h"

enum {
    MP_ICONV_VERBOSE = 1,       // print errors instead of failing silently
    MP_ICONV_ALLOW_CUTOFF = 2,  // allow partial input data
};

bool mp_charset_requires_guess(const char *user_cp);
const char *mp_charset_guess(bstr buf, const char *user_cp);
bstr mp_charset_guess_and_conv_to_utf8(bstr buf, const char *user_cp, int flags);
bstr mp_iconv_to_utf8(bstr buf, const char *cp, int flags);

#endif
