maxlevel=18
allways={}
ways=[1]*(maxlevel+1)

for i in range(maxlevel+1):
    ways[i]={}

ways[1][60]=60

for i in range(1,maxlevel+1):
    for j in range(1,i//2+1):
        for x in ways[j].keys():
            for y in ways[i-j].keys():
                ways[i][x+y]=1 
                ways[i][1.0*x*y/(x+y)]=1 
    for x in ways[i].keys():
        allways[round(x,9)]=x

print(len(allways.keys()))
