#include <CppUnitTest.h>
#include <simply/assert.h>
#include <simply/com/check.h>
#include <simply/com/com_error.h>
#include <winerror.h>

using namespace std;

namespace simply
{
    TEST_CLASS(com_test)
    {
    public:
        TEST_METHOD(check_throws_com_error_with_failed_hresult)
        {
            auto e = assert::throws<com_error>([] { check(E_INVALIDARG); });
            assert::is_equal(E_INVALIDARG, e.get()->hresult());
        }

        TEST_METHOD(check_doesnt_throw_with_successful_hresult)
        {
            check(S_FALSE);
        }
    };
}