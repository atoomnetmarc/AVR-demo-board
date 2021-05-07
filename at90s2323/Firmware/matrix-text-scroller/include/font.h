// HD44780 5x7 pixel font data
// http://eleif.net/HD44780.html
// Array offset from ASCII code is decimal 32 (hex 20), i.e. the first element with index 0 is SPACE (' ').
const __flash unsigned char font[][7] = {
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [ 0] ' '
    {
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000000,
        0b00000000,
        0b00000100,
    }, // [ 1] '!'
    {
        0b00001010,
        0b00001010,
        0b00001010,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [ 2] '"'
    {
        0b00001010,
        0b00001010,
        0b00011111,
        0b00001010,
        0b00011111,
        0b00001010,
        0b00001010,
    }, // [ 3] '#'
    {
        0b00000100,
        0b00001111,
        0b00010100,
        0b00001110,
        0b00000101,
        0b00011110,
        0b00000100,
    }, // [ 4] '$'
    {
        0b00011000,
        0b00011001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010011,
        0b00000011,
    }, // [ 5] '%'
    {
        0b00001100,
        0b00010010,
        0b00010100,
        0b00001000,
        0b00010101,
        0b00010010,
        0b00001101,
    }, // [ 6] '&'
    {
        0b00001100,
        0b00000100,
        0b00001000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [ 7] '''
    {
        0b00000010,
        0b00000100,
        0b00001000,
        0b00001000,
        0b00001000,
        0b00000100,
        0b00000010,
    }, // [ 8] '('
    {
        0b00001000,
        0b00000100,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00000100,
        0b00001000,
    }, // [ 9] ')'
    {
        0b00000000,
        0b00000100,
        0b00010101,
        0b00001110,
        0b00010101,
        0b00000100,
        0b00000000,
    }, // [10] '*'
    {
        0b00000000,
        0b00000100,
        0b00000100,
        0b00011111,
        0b00000100,
        0b00000100,
        0b00000000,
    }, // [11] '+'
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00001100,
        0b00000100,
        0b00001000,
    }, // [12] ','
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00011111,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [13] '-'
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00001100,
        0b00001100,
    }, // [14] '.'
    {
        0b00000000,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00000000,
    }, // [15] '/'
    {
        0b00001110,
        0b00010001,
        0b00010011,
        0b00010101,
        0b00011001,
        0b00010001,
        0b00001110,
    }, // [16] '0'
    {
        0b00000100,
        0b00001100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00001110,
    }, // [17] '1'
    {
        0b00001110,
        0b00010001,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00011111,
    }, // [18] '2'
    {
        0b00011111,
        0b00000010,
        0b00000100,
        0b00000010,
        0b00000001,
        0b00010001,
        0b00001110,
    }, // [19] '3'
    {
        0b00000010,
        0b00000110,
        0b00001010,
        0b00010010,
        0b00011111,
        0b00000010,
        0b00000010,
    }, // [20] '4'
    {
        0b00011111,
        0b00010000,
        0b00011110,
        0b00000001,
        0b00000001,
        0b00010001,
        0b00001110,
    }, // [21] '5'
    {
        0b00000110,
        0b00001000,
        0b00010000,
        0b00011110,
        0b00010001,
        0b00010001,
        0b00001110,
    }, // [22] '6'
    {
        0b00011111,
        0b00010001,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00000100,
        0b00000100,
    }, // [23] '7'
    {
        0b00001110,
        0b00010001,
        0b00010001,
        0b00001110,
        0b00010001,
        0b00010001,
        0b00001110,
    }, // [24] '8'
    {
        0b00001110,
        0b00010001,
        0b00010001,
        0b00001111,
        0b00000001,
        0b00000010,
        0b00001100,
    }, // [25] '9'
    {
        0b00000000,
        0b00001100,
        0b00001100,
        0b00000000,
        0b00001100,
        0b00001100,
        0b00000000,
    }, // [26] ':'
    {
        0b00000000,
        0b00001100,
        0b00001100,
        0b00000000,
        0b00001100,
        0b00000100,
        0b00001000,
    }, // [27] ';'
    {
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00001000,
        0b00000100,
        0b00000010,
    }, // [28] '<'
    {
        0b00000000,
        0b00000000,
        0b00011111,
        0b00000000,
        0b00011111,
        0b00000000,
        0b00000000,
    }, // [29] '='
    {
        0b00001000,
        0b00000100,
        0b00000010,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
    }, // [30] '>'
    {
        0b00001110,
        0b00010001,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00000000,
        0b00000100,
    }, // [31] '?'
    {
        0b00001110,
        0b00010001,
        0b00000001,
        0b00001101,
        0b00010101,
        0b00010101,
        0b00001110,
    }, // [32] '@'
    {
        0b00001110,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00011111,
        0b00010001,
        0b00010001,
    }, // [33] 'A'
    {
        0b00011110,
        0b00010001,
        0b00010001,
        0b00011110,
        0b00010001,
        0b00010001,
        0b00011110,
    }, // [34] 'B'
    {
        0b00001110,
        0b00010001,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010001,
        0b00001110,
    }, // [35] 'C'
    {
        0b00011100,
        0b00010010,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010010,
        0b00011100,
    }, // [36] 'D'
    {
        0b00011111,
        0b00010000,
        0b00010000,
        0b00011110,
        0b00010000,
        0b00010000,
        0b00011111,
    }, // [37] 'E'
    {
        0b00011111,
        0b00010000,
        0b00010000,
        0b00011110,
        0b00010000,
        0b00010000,
        0b00010000,
    }, // [38] 'F'
    {
        0b00001110,
        0b00010001,
        0b00010000,
        0b00010111,
        0b00010001,
        0b00010001,
        0b00001111,
    }, // [39] 'G'
    {
        0b00010001,
        0b00010001,
        0b00010001,
        0b00011111,
        0b00010001,
        0b00010001,
        0b00010001,
    }, // [40] 'H'
    {
        0b00001110,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00001110,
    }, // [41] 'I'
    {
        0b00000111,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00010010,
        0b00001100,
    }, // [42] 'J'
    {
        0b00010001,
        0b00010010,
        0b00010100,
        0b00011000,
        0b00010100,
        0b00010010,
        0b00010001,
    }, // [43] 'K'
    {
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00011111,
    }, // [44] 'L'
    {
        0b00010001,
        0b00011011,
        0b00010101,
        0b00010101,
        0b00010001,
        0b00010001,
        0b00010001,
    }, // [45] 'M'
    {
        0b00010001,
        0b00010001,
        0b00011001,
        0b00010101,
        0b00010011,
        0b00010001,
        0b00010001,
    }, // [46] 'N'
    {
        0b00001110,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001110,
    }, // [47] 'O'
    {
        0b00011110,
        0b00010001,
        0b00010001,
        0b00011110,
        0b00010000,
        0b00010000,
        0b00010000,
    }, // [48] 'P'
    {
        0b00001110,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010101,
        0b00010010,
        0b00001101,
    }, // [49] 'Q'
    {
        0b00011110,
        0b00010001,
        0b00010001,
        0b00011110,
        0b00010100,
        0b00010010,
        0b00010001,
    }, // [50] 'R'
    {
        0b00001111,
        0b00010000,
        0b00010000,
        0b00001110,
        0b00000001,
        0b00000001,
        0b00011110,
    }, // [51] 'S'
    {
        0b00011111,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
    }, // [52] 'T'
    {
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001110,
    }, // [53] 'U'
    {
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001010,
        0b00000100,
    }, // [54] 'V'
    {
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010101,
        0b00010101,
        0b00010101,
        0b00001010,
    }, // [55] 'W'
    {
        0b00010001,
        0b00010001,
        0b00001010,
        0b00000100,
        0b00001010,
        0b00010001,
        0b00010001,
    }, // [56] 'X'
    {
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001010,
        0b00000100,
        0b00000100,
        0b00000100,
    }, // [57] 'Y'
    {
        0b00011111,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00011111,
    }, // [58] 'Z'
    {
        0b00011100,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00011100,
    }, // [59] '['
    {
        0b00010001,
        0b00001010,
        0b00011111,
        0b00000100,
        0b00011111,
        0b00000100,
        0b00000100,
    }, // [60] '\'
    {
        0b00001110,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00001110,
    }, // [61] ']'
    {
        0b00000100,
        0b00001010,
        0b00010001,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [62] '^'
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00011111,
    }, // [63] '_'
    {
        0b00001000,
        0b00000100,
        0b00000010,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [64] '`'
    {
        0b00000000,
        0b00000000,
        0b00001110,
        0b00000001,
        0b00001111,
        0b00010001,
        0b00001111,
    }, // [65] 'a'
    {
        0b00010000,
        0b00010000,
        0b00010110,
        0b00011001,
        0b00010001,
        0b00010001,
        0b00011110,
    }, // [66] 'b'
    {
        0b00000000,
        0b00000000,
        0b00001110,
        0b00010000,
        0b00010000,
        0b00010001,
        0b00001110,
    }, // [67] 'c'
    {
        0b00000001,
        0b00000001,
        0b00001101,
        0b00010011,
        0b00010001,
        0b00010001,
        0b00001111,
    }, // [68] 'd'
    {
        0b00000000,
        0b00000000,
        0b00001110,
        0b00010001,
        0b00011111,
        0b00010000,
        0b00001110,
    }, // [69] 'e'
    {
        0b00000110,
        0b00001001,
        0b00001000,
        0b00011100,
        0b00001000,
        0b00001000,
        0b00001000,
    }, // [70] 'f'
    {
        0b00000000,
        0b00001111,
        0b00010001,
        0b00010001,
        0b00001111,
        0b00000001,
        0b00001110,
    }, // [71] 'g'
    {
        0b00010000,
        0b00010000,
        0b00010110,
        0b00011001,
        0b00010001,
        0b00010001,
        0b00010001,
    }, // [72] 'h'
    {
        0b00000100,
        0b00000000,
        0b00001100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00001110,
    }, // [73] 'i'
    {
        0b00000010,
        0b00000000,
        0b00000110,
        0b00000010,
        0b00000010,
        0b00010010,
        0b00001100,
    }, // [74] 'j'
    {
        0b00010000,
        0b00010000,
        0b00010010,
        0b00010100,
        0b00011000,
        0b00010100,
        0b00010010,
    }, // [75] 'k'
    {
        0b00001100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00001110,
    }, // [76] 'l'
    {
        0b00000000,
        0b00000000,
        0b00011010,
        0b00010101,
        0b00010101,
        0b00010001,
        0b00010001,
    }, // [77] 'm'
    {
        0b00000000,
        0b00000000,
        0b00010110,
        0b00011001,
        0b00010001,
        0b00010001,
        0b00010001,
    }, // [78] 'n'
    {
        0b00000000,
        0b00000000,
        0b00001110,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001110,
    }, // [79] 'o'
    {
        0b00000000,
        0b00000000,
        0b00011110,
        0b00010001,
        0b00011110,
        0b00010000,
        0b00010000,
    }, // [80] 'p'
    {
        0b00000000,
        0b00000000,
        0b00001101,
        0b00010011,
        0b00001111,
        0b00000001,
        0b00000001,
    }, // [81] 'q'
    {
        0b00000000,
        0b00000000,
        0b00010110,
        0b00011001,
        0b00010000,
        0b00010000,
        0b00010000,
    }, // [82] 'r'
    {
        0b00000000,
        0b00000000,
        0b00001110,
        0b00010000,
        0b00001110,
        0b00000001,
        0b00011110,
    }, // [83] 's'
    {
        0b00001000,
        0b00001000,
        0b00011100,
        0b00001000,
        0b00001000,
        0b00001001,
        0b00000110,
    }, // [84] 't'
    {
        0b00000000,
        0b00000000,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010011,
        0b00001101,
    }, // [85] 'u'
    {
        0b00000000,
        0b00000000,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001010,
        0b00000100,
    }, // [86] 'v'
    {
        0b00000000,
        0b00000000,
        0b00010001,
        0b00010101,
        0b00010101,
        0b00010101,
        0b00001010,
    }, // [87] 'w'
    {
        0b00000000,
        0b00000000,
        0b00010001,
        0b00001010,
        0b00000100,
        0b00001010,
        0b00010001,
    }, // [88] 'x'
    {
        0b00000000,
        0b00000000,
        0b00010001,
        0b00010001,
        0b00001111,
        0b00000001,
        0b00001110,
    }, // [89] 'y'
    {
        0b00000000,
        0b00000000,
        0b00011111,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00011111,
    }, // [90] 'z'
    {
        0b00000010,
        0b00000100,
        0b00000100,
        0b00001000,
        0b00000100,
        0b00000100,
        0b00000010,
    }, // [91] '{'
    {
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
    }, // [92] '|'
    {
        0b00001000,
        0b00000100,
        0b00000100,
        0b00000010,
        0b00000100,
        0b00000100,
        0b00001000,
    }, // [93] '}'
    {
        0b00000000,
        0b00000100,
        0b00000010,
        0b00011111,
        0b00000010,
        0b00000100,
        0b00000000,
    }, // [94] '~'
    {
        0b00000000,
        0b00000100,
        0b00001000,
        0b00011111,
        0b00001000,
        0b00000100,
        0b00000000,
    }, // [95] ''
/*
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [96] ''
    {
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000000,
        0b00000000,
        0b00000100,
    }, // [97] ''
    {
        0b00001010,
        0b00001010,
        0b00001010,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [98] ''
    {
        0b00001010,
        0b00001010,
        0b00011111,
        0b00001010,
        0b00011111,
        0b00001010,
        0b00001010,
    }, // [99] ''
    {
        0b00000100,
        0b00001111,
        0b00010100,
        0b00001110,
        0b00000101,
        0b00011110,
        0b00000100,
    }, // [100] ''
    {
        0b00011000,
        0b00011001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010011,
        0b00000011,
    }, // [101] ''
    {
        0b00001100,
        0b00010010,
        0b00010100,
        0b00001000,
        0b00010101,
        0b00010010,
        0b00001101,
    }, // [102] ''
    {
        0b00001100,
        0b00000100,
        0b00001000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [103] ''
    {
        0b00000010,
        0b00000100,
        0b00001000,
        0b00001000,
        0b00001000,
        0b00000100,
        0b00000010,
    }, // [104] ''
    {
        0b00001000,
        0b00000100,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00000100,
        0b00001000,
    }, // [105] ''
    {
        0b00000000,
        0b00000100,
        0b00010101,
        0b00001110,
        0b00010101,
        0b00000100,
        0b00000000,
    }, // [106] ''
    {
        0b00000000,
        0b00000100,
        0b00000100,
        0b00011111,
        0b00000100,
        0b00000100,
        0b00000000,
    }, // [107] ''
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00001100,
        0b00000100,
        0b00001000,
    }, // [108] ''
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00011111,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [109] ''
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00001100,
        0b00001100,
    }, // [110] ''
    {
        0b00000000,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00000000,
    }, // [111] ''
    {
        0b00001110,
        0b00010001,
        0b00010011,
        0b00010101,
        0b00011001,
        0b00010001,
        0b00001110,
    }, // [112] ''
    {
        0b00000100,
        0b00001100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00001110,
    }, // [113] ''
    {
        0b00001110,
        0b00010001,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00011111,
    }, // [114] ''
    {
        0b00011111,
        0b00000010,
        0b00000100,
        0b00000010,
        0b00000001,
        0b00010001,
        0b00001110,
    }, // [115] ''
    {
        0b00000010,
        0b00000110,
        0b00001010,
        0b00010010,
        0b00011111,
        0b00000010,
        0b00000010,
    }, // [116] ''
    {
        0b00011111,
        0b00010000,
        0b00011110,
        0b00000001,
        0b00000001,
        0b00010001,
        0b00001110,
    }, // [117] ''
    {
        0b00000110,
        0b00001000,
        0b00010000,
        0b00011110,
        0b00010001,
        0b00010001,
        0b00001110,
    }, // [118] ''
    {
        0b00011111,
        0b00010001,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00000100,
        0b00000100,
    }, // [119] ''
    {
        0b00001110,
        0b00010001,
        0b00010001,
        0b00001110,
        0b00010001,
        0b00010001,
        0b00001110,
    }, // [120] ''
    {
        0b00001110,
        0b00010001,
        0b00010001,
        0b00001111,
        0b00000001,
        0b00000010,
        0b00001100,
    }, // [121] ''
    {
        0b00000000,
        0b00001100,
        0b00001100,
        0b00000000,
        0b00001100,
        0b00001100,
        0b00000000,
    }, // [122] ''
    {
        0b00000000,
        0b00001100,
        0b00001100,
        0b00000000,
        0b00001100,
        0b00000100,
        0b00001000,
    }, // [123] ''
    {
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00001000,
        0b00000100,
        0b00000010,
    }, // [124] ''
    {
        0b00000000,
        0b00000000,
        0b00011111,
        0b00000000,
        0b00011111,
        0b00000000,
        0b00000000,
    }, // [125] ''
    {
        0b00001000,
        0b00000100,
        0b00000010,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
    }, // [126] ''
    {
        0b00001110,
        0b00010001,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00000000,
        0b00000100,
    }, // [127] ''
    {
        0b00001110,
        0b00010001,
        0b00000001,
        0b00001101,
        0b00010101,
        0b00010101,
        0b00001110,
    }, // [128] ' '
    {
        0b00001110,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00011111,
        0b00010001,
        0b00010001,
    }, // [129] '¡'
    {
        0b00011110,
        0b00010001,
        0b00010001,
        0b00011110,
        0b00010001,
        0b00010001,
        0b00011110,
    }, // [130] '¢'
    {
        0b00001110,
        0b00010001,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010001,
        0b00001110,
    }, // [131] '£'
    {
        0b00011100,
        0b00010010,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010010,
        0b00011100,
    }, // [132] '¤'
    {
        0b00011111,
        0b00010000,
        0b00010000,
        0b00011110,
        0b00010000,
        0b00010000,
        0b00011111,
    }, // [133] '¥'
    {
        0b00011111,
        0b00010000,
        0b00010000,
        0b00011110,
        0b00010000,
        0b00010000,
        0b00010000,
    }, // [134] '¦'
    {
        0b00001110,
        0b00010001,
        0b00010000,
        0b00010111,
        0b00010001,
        0b00010001,
        0b00001111,
    }, // [135] '§'
    {
        0b00010001,
        0b00010001,
        0b00010001,
        0b00011111,
        0b00010001,
        0b00010001,
        0b00010001,
    }, // [136] '¨'
    {
        0b00001110,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00001110,
    }, // [137] '©'
    {
        0b00000111,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00010010,
        0b00001100,
    }, // [138] 'ª'
    {
        0b00010001,
        0b00010010,
        0b00010100,
        0b00011000,
        0b00010100,
        0b00010010,
        0b00010001,
    }, // [139] '«'
    {
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00011111,
    }, // [140] '¬'
    {
        0b00010001,
        0b00011011,
        0b00010101,
        0b00010101,
        0b00010001,
        0b00010001,
        0b00010001,
    }, // [141] '­'
    {
        0b00010001,
        0b00010001,
        0b00011001,
        0b00010101,
        0b00010011,
        0b00010001,
        0b00010001,
    }, // [142] '®'
    {
        0b00001110,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001110,
    }, // [143] '¯'
    {
        0b00011110,
        0b00010001,
        0b00010001,
        0b00011110,
        0b00010000,
        0b00010000,
        0b00010000,
    }, // [144] '°'
    {
        0b00001110,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010101,
        0b00010010,
        0b00001101,
    }, // [145] '±'
    {
        0b00011110,
        0b00010001,
        0b00010001,
        0b00011110,
        0b00010100,
        0b00010010,
        0b00010001,
    }, // [146] '²'
    {
        0b00001111,
        0b00010000,
        0b00010000,
        0b00001110,
        0b00000001,
        0b00000001,
        0b00011110,
    }, // [147] '³'
    {
        0b00011111,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
    }, // [148] '´'
    {
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001110,
    }, // [149] 'µ'
    {
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001010,
        0b00000100,
    }, // [150] '¶'
    {
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010101,
        0b00010101,
        0b00010101,
        0b00001010,
    }, // [151] '·'
    {
        0b00010001,
        0b00010001,
        0b00001010,
        0b00000100,
        0b00001010,
        0b00010001,
        0b00010001,
    }, // [152] '¸'
    {
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001010,
        0b00000100,
        0b00000100,
        0b00000100,
    }, // [153] '¹'
    {
        0b00011111,
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00011111,
    }, // [154] 'º'
    {
        0b00011100,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00010000,
        0b00011100,
    }, // [155] '»'
    {
        0b00010001,
        0b00001010,
        0b00011111,
        0b00000100,
        0b00011111,
        0b00000100,
        0b00000100,
    }, // [156] '¼'
    {
        0b00001110,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00000010,
        0b00001110,
    }, // [157] '½'
    {
        0b00000100,
        0b00001010,
        0b00010001,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [158] '¾'
    {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00011111,
    }, // [159] '¿'
    {
        0b00001000,
        0b00000100,
        0b00000010,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
    }, // [160] 'À'
    {
        0b00000000,
        0b00000000,
        0b00001110,
        0b00000001,
        0b00001111,
        0b00010001,
        0b00001111,
    }, // [161] 'Á'
    {
        0b00010000,
        0b00010000,
        0b00010110,
        0b00011001,
        0b00010001,
        0b00010001,
        0b00011110,
    }, // [162] 'Â'
    {
        0b00000000,
        0b00000000,
        0b00001110,
        0b00010000,
        0b00010000,
        0b00010001,
        0b00001110,
    }, // [163] 'Ã'
    {
        0b00000001,
        0b00000001,
        0b00001101,
        0b00010011,
        0b00010001,
        0b00010001,
        0b00001111,
    }, // [164] 'Ä'
    {
        0b00000000,
        0b00000000,
        0b00001110,
        0b00010001,
        0b00011111,
        0b00010000,
        0b00001110,
    }, // [165] 'Å'
    {
        0b00000110,
        0b00001001,
        0b00001000,
        0b00011100,
        0b00001000,
        0b00001000,
        0b00001000,
    }, // [166] 'Æ'
    {
        0b00000000,
        0b00001111,
        0b00010001,
        0b00010001,
        0b00001111,
        0b00000001,
        0b00001110,
    }, // [167] 'Ç'
    {
        0b00010000,
        0b00010000,
        0b00010110,
        0b00011001,
        0b00010001,
        0b00010001,
        0b00010001,
    }, // [168] 'È'
    {
        0b00000100,
        0b00000000,
        0b00001100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00001110,
    }, // [169] 'É'
    {
        0b00000010,
        0b00000000,
        0b00000110,
        0b00000010,
        0b00000010,
        0b00010010,
        0b00001100,
    }, // [170] 'Ê'
    {
        0b00010000,
        0b00010000,
        0b00010010,
        0b00010100,
        0b00011000,
        0b00010100,
        0b00010010,
    }, // [171] 'Ë'
    {
        0b00001100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00001110,
    }, // [172] 'Ì'
    {
        0b00000000,
        0b00000000,
        0b00011010,
        0b00010101,
        0b00010101,
        0b00010001,
        0b00010001,
    }, // [173] 'Í'
    {
        0b00000000,
        0b00000000,
        0b00010110,
        0b00011001,
        0b00010001,
        0b00010001,
        0b00010001,
    }, // [174] 'Î'
    {
        0b00000000,
        0b00000000,
        0b00001110,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001110,
    }, // [175] 'Ï'
    {
        0b00000000,
        0b00000000,
        0b00011110,
        0b00010001,
        0b00011110,
        0b00010000,
        0b00010000,
    }, // [176] 'Ð'
    {
        0b00000000,
        0b00000000,
        0b00001101,
        0b00010011,
        0b00001111,
        0b00000001,
        0b00000001,
    }, // [177] 'Ñ'
    {
        0b00000000,
        0b00000000,
        0b00010110,
        0b00011001,
        0b00010000,
        0b00010000,
        0b00010000,
    }, // [178] 'Ò'
    {
        0b00000000,
        0b00000000,
        0b00001110,
        0b00010000,
        0b00001110,
        0b00000001,
        0b00011110,
    }, // [179] 'Ó'
    {
        0b00001000,
        0b00001000,
        0b00011100,
        0b00001000,
        0b00001000,
        0b00001001,
        0b00000110,
    }, // [180] 'Ô'
    {
        0b00000000,
        0b00000000,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00010011,
        0b00001101,
    }, // [181] 'Õ'
    {
        0b00000000,
        0b00000000,
        0b00010001,
        0b00010001,
        0b00010001,
        0b00001010,
        0b00000100,
    }, // [182] 'Ö'
    {
        0b00000000,
        0b00000000,
        0b00010001,
        0b00010101,
        0b00010101,
        0b00010101,
        0b00001010,
    }, // [183] '×'
    {
        0b00000000,
        0b00000000,
        0b00010001,
        0b00001010,
        0b00000100,
        0b00001010,
        0b00010001,
    }, // [184] 'Ø'
    {
        0b00000000,
        0b00000000,
        0b00010001,
        0b00010001,
        0b00001111,
        0b00000001,
        0b00001110,
    }, // [185] 'Ù'
    {
        0b00000000,
        0b00000000,
        0b00011111,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00011111,
    }, // [186] 'Ú'
    {
        0b00000010,
        0b00000100,
        0b00000100,
        0b00001000,
        0b00000100,
        0b00000100,
        0b00000010,
    }, // [187] 'Û'
    {
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
        0b00000100,
    }, // [188] 'Ü'
    {
        0b00001000,
        0b00000100,
        0b00000100,
        0b00000010,
        0b00000100,
        0b00000100,
        0b00001000,
    }, // [189] 'Ý'
    {
        0b00000000,
        0b00000100,
        0b00000010,
        0b00011111,
        0b00000010,
        0b00000100,
        0b00000000,
    }, // [190] 'Þ'
    {
        0b00000000,
        0b00000100,
        0b00001000,
        0b00011111,
        0b00001000,
        0b00000100,
        0b00000000,
    }, // [191] 'ß'
*/
};
