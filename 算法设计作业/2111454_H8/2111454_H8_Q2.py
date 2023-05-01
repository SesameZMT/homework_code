def dp1(p : int,na : int,nb : int,t):
    ans1 = [[[0 for _ in range(nb+1)] for _ in range(na+1)] for _ in range(p)]
    for a in range(p):
        temp = [[[float('inf') for _ in range(nb+1)] for _ in range(na+1)] for _ in range(2)]
        temp[0][0][0] = 0
        temp[1][0][0] = 0
        for i in range(na+1):
            for j in range(nb+1):
                for k1 in range(1,i):
                    temp[0][i][j] = min(temp[0][i][j],temp[1][i-k1][j]+t[a][2] * k1 * k1 + t[a][0])
                for k2 in range(1,j):
                    temp[1][i][j] = min(temp[1][i][j],temp[0][i][j-k2]+t[a][3] * k2 * k2 +t[a][1])
                ans1[a][i][j] = min(temp[0][i][j],temp[1][i][j])
                print(temp)
    return ans1

def main():
    file = open("2111454_H8/hpc.in")
    na = 0
    nb = 0
    p = 0
    t = []
    num = 0
    while True:
        line = file.readline()
        if not line:
            break
        if num == 0:
            temp = line.split()
            na = int(temp[0])
            nb = int(temp[1])
            num+=1
        elif num == 1:
            p = int(line)
            num+=1
        else:
            temp = line.split()
            temp1 = []
            temp1.append(int(temp[0]))
            temp1.append(int(temp[1]))
            temp1.append(int(temp[2]))
            temp1.append(int(temp[3]))
            t.append(temp1)
    print(t)
    ans1 = dp1(p,na,nb,t)
    print(ans1)

if __name__ == '__main__':
    main()