# Why to revisit series example again?

I see several issues with the first implementation of series I.

Your motivation should be stronger/clearer

While you may have a very good motivation for having this functionality, it is not apparent from your post hear nor from your GitHub repo. At compile time there are typically very few values I'd need the sine or cosine of; is it really clearer to write

```cpp
printf("%f", apply_my_complicated_TMP_construct(PI/4, 8) )
```
than
```cpp
auto sine_of_quarter_pi = 0,707106781187f;
printf("%f", sine_of_quarter_pi);
```
? I don't know that it is. Plus, the second way the reader doesn't need to think about iterations, the taylor series etc. It will also reduce compilation time.

Now, you could say "Ah, but I have a lot of these values to apply sin() or cos()" - but honestly, I doubt it. If that's the case you should just do that offline and independently of developing your C++ code.

In your repository, you list the following advantages:

- All the work is done a compile-time.
- The compile-time efficiency is actually going to be better than run-time efficiency compared to "normal,"

But, again, there isn't really any work; and there's no "efficiency" issue if you just use the value you need. Even if you had to calculate a sine or cosine a couple dozen times - that's really negligible.

## Don't reinvent the wheel I

There's an M_PI constant available in POSIX-compliant system's <math.h> header (and thus, effectively, in most <cmath> headers, including MSVC's with a bit of work, see here). In case you want to be more portable, you might do:
```cpp
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
```
... but, in fact, these days you can even get a better accuracy constant, M_PIl, on some systems. So you would have actually gained from not reinventing the wheel.

... and there's more. Remember my sqrt(2)/2 from the example above? That's often predefined too. Have a look at your system's <math.h>.

## Don't reinvent the wheel II

Someone has already provided what looks like a more robust implementation of the same functionality - here on the site:

## constexpr Sin Function C++ 14

Now, granted, I haven't scrutinized that code. Maybe it's buggy or has other problems. But I'll bet you 100 reputation you haven't read that implementation before writing yours... although you could have, if you'd have looked. I didn't know about it before I was writing this review.

Drop most template recursion in favor of C++14 constexpr functions

You use recursive template instantiation when you could just put a for loop in your function - and sometimes not even need a template:

```cpp
constexpr long long factorial(int n)
{
    return (n <= 1) ? 1L : (n * factorial(n - 1));
}
```
(taken from here). Also, when you can't just "go constexpr", you can still iterate over multiple template arguments with for_each_argument and so on.