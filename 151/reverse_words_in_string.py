import re

def reverseWords(s: str) -> str:
    s = re.sub(r'\s+', ' ', s)
    s = re.sub(r'^\s+', '', s)
    s = re.sub(r'\s+$', '', s)
    words = s.split(' ')
    words.reverse()

    result = ""
    for word in words:
        if word != ' ':
            result += word
            result += " "

    return result[:-1]

def main():
    print(reverseWords("the sky is blue"))
    print(reverseWords("  hello world  "))
    print(reverseWords("a good   example"))

if __name__ == '__main__':
    main()