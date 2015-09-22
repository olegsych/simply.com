#pragma once

#include <winerror.h>
#include <simply/com/com_error.h>

namespace simply
{
    inline void check(HRESULT hresult)
    {
        if (FAILED(hresult))
        {
            throw com_error { hresult };
        }
    }
}