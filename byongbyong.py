print('뿅뿅')
print('헤으응 우준이옵빠')

weight = input('최뿅뿅의 몸무게는?: ')
print('최뿅뿅의 몸무게는 ' + weight + 'kg 입니다.')

weight = int(weight)

if weight < 50:
    print('멸치새끼 ㅉㅉㅉ')
elif weight >= 50 and weight < 100:
    print('정상이군요')
else:
    print('돼지새끼 ㅉㅉㅉ')

height = input('최뿅뿅의 키는? :')
print('최뿅뿅의 키는 ' + height + 'cm입니다.')

height = int(height)

if height <= 165:
    print('땅딸이자식')
    print('난쟁이쉑 ㅉㅉㅉ')
    
    if height < 130:
        print('미생물보다 작네요')
elif height > 165 and height < 175:
    print('앵간하네요')
else: 
    print('키가 크시네요 부럽다')
