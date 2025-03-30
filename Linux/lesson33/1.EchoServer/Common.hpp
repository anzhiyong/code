#define Die(code)   \
    do              \
    {               \
        exit(code); \
    } while (0)

#define CONV(v) (sockaddr *)(v)
