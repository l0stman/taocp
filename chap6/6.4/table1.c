#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(x)	((sizeof(x))/(sizeof((x)[0])))

static struct {
        const char *w;
        int hash;
} words[] = {
        {"A    ", 0},
        {"AND  ", 0},
        {"ARE  ", 0},
        {"AS   ", 0},
        {"AT   ", 0},
        {"BE   ", 0},
        {"BUT  ", 0},
        {"BY   ", 0},
        {"FOR  ", 0},
        {"FROM ", 0},
        {"HAD  ", 0},
        {"HAVE ", 0},
        {"HE   ", 0},
        {"HER  ", 0},
        {"HIS  ", 0},
        {"I    ", 0},
        {"IN   ", 0},
        {"IS   ", 0},
        {"IT   ", 0},
        {"NOT  ", 0},
        {"OF   ", 0},
        {"ON   ", 0},
        {"OR   ", 0},
        {"THAT ", 0},
        {"THE  ", 0},
        {"THIS ", 0},
        {"TO   ", 0},
        {"WAS  ", 0},
        {"WHICH", 0},
        {"WITH ", 0},
        {"YOU  ", 0}
};

static int
num(char c)
{
        int n;

        if (c == ' ')
                return 0;
        n = c - 'A' + 1;
        if (n > 9)
                n++;
        if (n > 19)
                n += 2;
        return n;
}

int
hash(const char *s)
{
        int h, c;

        h = -num(*s);
        c = num(*(s+1));
        h += -8 + c;
        if (h <= 0)
                h += 16 + c;
        if (!(c = num(*(s+2))))
                return h;
        h += -28 + c;
        if (h > 0)
                return h;
        h += 11 + c;
        if (!num(*(s+3)))
                return h;
        h += 5 - c;
        if (h < 0)
                return h;
        h += 10;
        return h;
}

int
main(int argc, char *argv[])
{
        FILE *fp;
        char w[6];
        int i, h;

        if (argc == 1)
                fp = stdin;
        else if ((fp = fopen(argv[1], "r")) == NULL)
                err(EXIT_FAILURE, "Can't open file %s", argv[1]);

        for (i=0; i<NELEMS(words); i++)
                words[i].hash = hash(words[i].w);

        while (fread(w, sizeof(*w), sizeof(w), fp) > 0) {
                h = hash(w);
                for (i=0; i<NELEMS(words); i++)
                        if (words[i].hash == h)
                                break;
                if (i == NELEMS(words))
                        printf("%.*s: %d\n", sizeof(w)-1, w, h);
        }

        return 0;
}
