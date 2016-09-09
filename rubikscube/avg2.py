from sys import argv

inp = open("average1.txt", 'r')
out = open("final.txt", 'w')

melhor = 0
pior = 0 
media = 0
iguais = 0
numger = 0

while True:
    line = inp.readline()
    if not line:
        break;

    line2 = inp.readline()
    line3 = inp.readline()
    line4 = inp.readline()
    inp.readline()
   
    melhor = melhor + int(line)
    pior = pior + int(line2)
    media = media + int(line3)
    iguais = iguais + int(line4)
    numger = numger + 1
    
    
out.write("5000\t"+str(melhor/numger)+"\t"+str(pior/numger)+"\t"+str(media/numger)+"\t"+str(iguais/numger))

inp.close()
out.close()
