#include <CppUnitTest.h>
#include <simply/assert.h>
#include <simply/com/com_error.h>
#include <winerror.h>

using namespace std;

namespace simply
{
    TEST_CLASS(com_error_test)
    {
    public:
        TEST_METHOD(hresult_returns_value_specified_in_constructor)
        {
            HRESULT expected = E_FAIL;
            com_error sut { expected };
            assert::is_equal(expected, sut.hresult());
        }

        TEST_METHOD(what_returns_system_message_describing_hresult)
        {
            com_error sut { E_NOINTERFACE };
            assert::find("No such interface supported", sut.what());
        }
    };
}