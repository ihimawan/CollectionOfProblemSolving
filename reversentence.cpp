class Solution {
public:
    void reverseWords(string &s)
    {
        int len = s.length();
        if (len == 0)
            return;

        // Firstly, reverse the entire string.
        char str[len + 1];
        strcpy(str, s.c_str());
        for (int i = 0 ; i < len >> 1 ; ++i) {
            char temp = str[i];
            str[i] = str[len - i - 1];
            str[len - i - 1] = temp;
        }

        // Secondly, reverse each words.
        int bgn = 0, end = 0;
        while (end < len) {
            while ((end < len) && str[end] != ' ')
                ++end;
            for (int i = 0 ; i < (end - bgn) >> 1 ; ++i) {
                char temp = str[bgn + i];
                str[bgn + i] = str[end - i - 1];
                str[end - i - 1] = temp;
            }
            ++end;
            bgn = end;
        }

        // Remove the redundant white-space between words.
        int base = 0;
        bgn = 0;
        while (base < len) {
            while ((bgn < len) && (str[bgn] == ' '))
                ++bgn;
            end = bgn;
            while ((end < len) && (str[end] != ' '))
                ++end;

            if (bgn == len)
                break;
            int idx_front = bgn;
            int idx_base = base;
            if (bgn != base) {
                while (idx_front < end) {
                    str[idx_base] = str[idx_front];
                    str[idx_front] = ' ';
                    ++idx_base;
                    ++idx_front;
                }
                base = idx_base + 1;
            } else
                base = end + 1;
            bgn = base;
        }

        // Remove the trailing white-space.
        bgn = len - 1;
        while ((bgn >= 0) && (str[bgn] == ' '))
            --bgn;
        ++bgn;

        s.assign(str, bgn);
    }
};