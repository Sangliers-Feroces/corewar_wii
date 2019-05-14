/*
** EPITECH PROJECT, 2018
** ಠωಠ
** File description:
** headaaaas
*/

int getnbr_c(char *str)
{
    int i = 0;
    long rtn = 0;

    while (str[i] != '\0') {
        if (str[i] == '-' && str[i + 1] <= '9' && str[i + 1] >= '0') {
            rtn = (str[i + 1] - 48) * -1;
            i += 2;
        } else if (str[i] <= '9' && str[i] >= '0') {
            rtn *= 10;
            rtn += str[i] - 48;
        } else
            break;
        i++;
    }
    if (rtn >= 2147483647)
        return 0;
    return (int)rtn;
}
