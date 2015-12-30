# simply::com

A small C++ library for working with COM. Clean, modern C++; exception-based error reporting; no ATL or macros.

## use 

Add the [simply.com](http://www.nuget.org/packages/simply.com) NuGet package to your Visual C++ 
project using the [Package Manager Dialog](http://docs.nuget.org/consume/Package-Manager-Dialog) or 
the [Package Manager Console](http://docs.nuget.org/consume/package-manager-console).
``` PowerShell
Install-Package simply.com
```

Include the library header and use its namespace.
``` C++
#include <simply/com.h>
using namespace simply;
```

Use `com_ptr` to safely manage COM interface pointers and `check` to convert `HRESULT` codes to `com_error` exceptions.
``` C++
try 
{
    com_ptr<IMetaDataDispenserEx> dispenser;
    check(CoCreateInstance(CLSID_CorMetaDataDispenser, 0, CLSCTX_INPROC_SERVER, IID_IMetaDataDispenserEx, dispenser));
}
catch (const com_error& error)
{
    cout << error.what() << error.hresult();
}
```

## build

[![Build status](https://ci.appveyor.com/api/projects/status/github/olegsych/simply.com?branch=master)](https://ci.appveyor.com/project/olegsych/simply-com/branch/master)

From [Visual Studio 2015](https://www.visualstudio.com/downloads):
- Open `simply.com.sln`
- Select _Build Solution_ from the _Build_ menu
- To switch build between `x86` and `x64` platforms, select _Configuration Manager_ from the _Build_ menu and change the _Active Solution Configuration_

From [Developer Command Prompt for VS2015](https://msdn.microsoft.com/en-us/library/ms229859.aspx):
``` PowerShell
msbuild simply.com.sln /p:Platform=x86
msbuild simply.com.sln /p:Platform=x64
```

## test

From Visual Studio 2015:
- Select _Run_ / _All Tests_ from the _Test_ menu
- To switch test execution between `x86` and `x64` platform, select _Test Settings_ from the _Test_ menu and change the _Default Processor Architecture_.

From Developer Command Prompt for VS2015:
``` PowerShell
vstest.console bin\Win32\test.dll /Platform:x86
vstest.console bin\x64\test.dll /Platform:x64 /inIsolation
```