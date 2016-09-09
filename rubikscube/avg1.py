from sys import argv

out = open("average1.txt", 'w')
in1 = open("out1.txt", 'r')
in2 = open("out2.txt", 'r') 
in3 = open("out3.txt", 'r')  
in4 = open("out4.txt", 'r') 
in5 = open("out5.txt", 'r')  
in6 = open("out6.txt", 'r') 
in7 = open("out7.txt", 'r')  
in8 = open("out8.txt", 'r')  
in9 = open("out9.txt", 'r') 
in10 = open("out10.txt", 'r') 

for line in in1:
	#maior
	if line == "\n":
		#print "\n "
		out.write("\n")
		b = (in2.readline())
		c = (in3.readline())
		d = (in4.readline())
		e = (in5.readline())
		f = (in6.readline())
		g = (in7.readline())
		h = (in8.readline())
		i = (in9.readline())
		j = (in10.readline())	
		continue;

	a = int(line)
	b = int(in2.readline())
	c = int(in3.readline())
	d = int(in4.readline())
	e = int(in5.readline())
	f = int(in6.readline())
	g = int(in7.readline())
	h = int(in8.readline())
	i = int(in9.readline())
	j = int(in10.readline())
	k = (a+b+c+d+e+f+g+h+i+j)/10
	#print k
	out.write( str(k)+"\n")
	

in1.close() 
in2.close()  
in3.close()  
in4.close() 
in5.close()  
in6.close() 
in7.close()  
in8.close()  
in9.close()  
in10.close() 
out.close()