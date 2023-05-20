from typing import List

table : List[List[int]]= [
            [2,10,9,7],
            [15,4,14,8],
            [13,14,16,11],
            [4,15,13,9]
        ]
ans : List[List[int]]= []

def func(lb_now : int,lb_max : int,used_index : List[int],which : int) -> int:
    if which == 3:
        for i in range(4):
            if i not in used_index and lb_now - min(table[which]) + table[which][i] <= lb_max:
                lb_max = lb_now - min(table[which]) + table[which][i]
                used_index.append(i)
                ans.append(used_index)
        return lb_max
    else:
        for i in range(4):
            if i not in used_index:
                lb_now1 = lb_now - min(table[which]) + table[which][i]
                if lb_now1 < lb_max:
                    used_index1 = used_index.copy()
                    used_index1.append(i)
                    lb_max = func(lb_now1,lb_max,used_index1,which+1)
        return lb_max
        
def main() -> None:
    lb = 0
    for i in range(4):
        lb += min(table[i])
    used_index = []
    cost = func(lb,100000,used_index,0)
    lenth = len(ans)
    final_ans : List[int] = ans[lenth-1]
    for i in range(4):
        if final_ans[i] == 0:
            print(chr(ord('A')+i)," -> ","I")
        if final_ans[i] == 1:
            print(chr(ord('A')+i)," -> ","II")
        if final_ans[i] == 2:
            print(chr(ord('A')+i)," -> ","III")
        if final_ans[i] == 3:
            print(chr(ord('A')+i)," -> ","IV")
    print("min time is : ",cost)

if __name__ == '__main__':
    main()