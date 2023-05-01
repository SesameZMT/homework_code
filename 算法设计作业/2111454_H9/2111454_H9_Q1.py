from typing import List
import copy

ans = []

def func(temp : List[str],ans1 : str):
     if len(temp) == 1:
          ans1 += temp[0]
          ans.append(ans1)
          return
     else:
          for i in range(len(temp)):
               temp1 = copy.deepcopy(temp)
               ans11 = copy.deepcopy(ans1)
               ans11 += temp[i]
               temp1.remove(temp[i])
               func(temp1,ans11)

def main() -> None :
     n = int(input())
     source = []
     ans1 = ""
     for i in range(1,n+1):
          source.append(str(i))
     func(source,ans1)
     print(len(ans))
     for i in range(len(ans)):
          print(ans[i])

if __name__ == '__main__':
     main()