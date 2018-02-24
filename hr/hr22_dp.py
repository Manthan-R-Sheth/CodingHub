fib=[]
def main():
	a,b,n=raw_input().split()
	a,b,n=[int(a),int(b),int(n)]
	fib.append(a)
	fib.append(b)
	for i in range(2,n+1):                # range is [f,l)
		fib.append(fib[i-1]*fib[i-1]+fib[i-2])
		print(fib[i])
	print(fib[n-1])
main()
