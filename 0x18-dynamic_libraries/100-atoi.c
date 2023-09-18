int _atoi(char *s)

{
        int a, b, c, len, x, digit;

        a = 0;
        b = 0;
        c = 0;
        len = 0;
        x = 0;
        digit = 0;

        while (s[len] != '\0')
                len++;

        while (a < len && x == 0)
        {
                if (s[a] == '-')
                        ++b;

                if (s[a] >= '0' && s[a] <= '9')
                {
                        digit = s[a] - '0';
                        if (b % 2)
                                digit = -digit;
                        c = c * 10 + digit;
                        x = 1;
                        if (s[a + 1] < '0' || s[a + 1] > '9')
                                break;
                        x = 0;
                }
                a++;
        }

        if (x == 0)
                return (0);

        return (c);
}