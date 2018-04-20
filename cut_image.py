from PIL import Image

im = Image.open('heroe.png').convert('L') #open in black and white     
photo = im.load() 

m, n = im.size

last_cnt = 1e9
for i in range(n-1, -1, -1):
    cnt_white = 0;
    for j in range(m):
	cnt_white += 1 if photo[j, i] > 250 else 0

    if cnt_white > last_cnt:
	break
    else:
	for j in range(m):
	    photo[j, i] = 0
    last_cnt = cnt_white


for i in range(n):
    sum = 0;
    for j in range(m):
	sum += photo[j, i]

    if sum > m * 200:
	for j in range(m):
	    photo[(j, i)] = 0
    else:
	break


for j in range(m):
    sum = 0;
    for i in range(n):
	sum += photo[j, i]

    if sum > n * 150:
	for i in range(n):
	    photo[j, i] = 0
    else:
	break

for j in range(m-1, -1, -1):
    sum = 0
    for i in range(n):
	sum += photo[j, i]

    if sum > n*150:
	for i in range(n):
	    photo[j, i] = 0
    else:
	break


im.save('out.png', optimize=True)
