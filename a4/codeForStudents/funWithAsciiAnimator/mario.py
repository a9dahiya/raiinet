# =============== CONSTANTS ===============
FILENAME = "Mario.png" # Filename to read in
WIDTH = 50 # Max width of the output file - needs to be small or otherwise will generate tens or thousands of commands
AVAILABLE=[(255,0,0), (0,255,0), (0,0,255), (255,255,255), (0,0,0)] # Colors to choose from - must include black
OUTPUT=['a', 'A', '1', ' ', '!'] # Letter assignment to color
# =========================================
from PIL import Image
from math import sqrt

im = Image.open(FILENAME)
im = im.convert('RGBA')
width_scale = (WIDTH/float(im.size[0]))
height = int((float(im.size[1])*float(width_scale)))
im = im.resize((WIDTH,height), Image.ANTIALIAS)
im.save('scaled.png')
f = open("output", "w")
f.write(f"addgraphics 0 {height-1} 0 {WIDTH-1}\n")

pix = im.load()
for row in range(im.size[0]):
    for col in range(im.size[1]):
        lst = []
        for avail in AVAILABLE:
            diff = sqrt((avail[0]-pix[row,col][0])**2+(avail[1]-pix[row,col][1])**2+(avail[2]-pix[row,col][2])**2)
            lst.append(diff/sqrt((255)**2+(255)**2+(255)**2))
        if pix[row,col] == 0:
            pix[row,col]=0
        elif pix[row,col][3] == 0:
            pix[row,col]=(255,255,255)
        else:
            pix[row,col]=AVAILABLE[lst.index(min(lst))]
            if lst.index(min(lst)) != 3:
                f.write(f"filledbox {col} {col} {row} {row} {OUTPUT[lst.index(min(lst))]}\n")

f.write("render\n")
f.close()
im.save('output.png')
