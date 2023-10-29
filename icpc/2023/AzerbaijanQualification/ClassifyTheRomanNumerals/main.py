from dataclasses import dataclass


@dataclass
class RomanNumerals:
    value: int
    notation: str
    is_horizontally_symmetric: bool


numerals = [RomanNumerals(1000, 'M', False), RomanNumerals(900, 'CM', False), RomanNumerals(500, 'D', True), 
            RomanNumerals(400, 'CD', True), RomanNumerals(100, 'C', True),  RomanNumerals(90, 'XC', True), 
            RomanNumerals(50, 'L', False), RomanNumerals(40, 'XL', False), RomanNumerals(10, 'X', True), 
            RomanNumerals(9, 'IX', True), RomanNumerals(5, 'V', False), RomanNumerals(4, 'IV', False), RomanNumerals(1, 'I', True)]

vertically_symmetric = ('I', 'V', 'X', 'M')


def convert_to_roman_notation(num: int):
    roman_notation = ""
    is_horiz_symmetric = True
    
    for numeral in numerals:
        while num >= numeral.value:
            roman_notation += numeral.notation
            is_horiz_symmetric &= numeral.is_horizontally_symmetric

            num -= numeral.value

    return roman_notation, is_horiz_symmetric

def get_symmetry(num: int):

    roman_notation, horizontal = convert_to_roman_notation(num)
    vertical = True

    length = len(roman_notation)
    l: int
    r: int

    if length % 2 == 1:  # odd length
        if roman_notation[length // 2] not in vertically_symmetric:
            vertical = False
        else:
            l = length // 2 - 1
            r = length // 2 + 1
    else:
        l = length // 2 - 1
        r = l + 1


    while vertical and l >= 0 and r < length:
        if roman_notation[l] != roman_notation[r] or roman_notation[l] not in vertically_symmetric:
            vertical = False
        
        l -= 1
        r += 1

    if horizontal and vertical:
        return '+'
    elif horizontal:
        return '-'
    elif vertical:
        return '|'
    
    return '?'


# Main program
t = int(input())

while t > 0:

    num = int(input())
    print(get_symmetry(num))
    t -= 1
