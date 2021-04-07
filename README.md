# MT-safe datetime transform

Provides thread-safe wrappers of `localtime` and `gmtime` functions.

The functions with security enhancements are used if available, otherwise std::mutex lock protection is used for unsafe `localtime` and `gmtime`.

C++11 required.

# Usage

```cpp
    ...

    using namespace std;

    tm local_tm, utc_tm;
    
    cout << "Local time: "
        << asctime(local_datetime(&local_tm, time(nullptr))) << endl;

    cout << "UTC time: "
        << asctime(utc_datetime(&utc_tm, time(nullptr))) << endl;
    
    ...
```