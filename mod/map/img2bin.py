import PIL.Image
import struct
a=PIL.Image.open("/home/cpera/bd/sxc.jpeg")
b=a.resize((128,256),PIL.Image.LANCZOS)
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
for i in range(1):
	for j in range(2):
		writeit(cnt,i*128,j*128)
		cnt=cnt+1
