#!/usr/bin/python2
import PIL.Image
import struct
import sys
a=PIL.Image.open(sys.argv[1])
SIZE1=int(sys.argv[2]) #width
SIZE2=int(sys.argv[3])
b=a.resize((SIZE1,SIZE2),PIL.Image.LANCZOS)
def writeit(a,woff,hoff):
	res=""
	for i in range(128): #y
		for j in range(128):
			c=b.getpixel((j+woff,i+hoff))
			res+=struct.pack("I",(c[2]<<16)|(c[1]<<8)|c[0]) #b g r
	f=open(str(a)+".bin","wb")
	f.write(res)
	f.close()
cnt=0
for i in range(int(SIZE1/128)):
	for j in range(int(SIZE2/128)):
		writeit(cnt,i*128,j*128)
		cnt=cnt+1
