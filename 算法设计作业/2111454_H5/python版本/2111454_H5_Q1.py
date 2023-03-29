def which(k,cache,time,pls):
    ta = -1
    a = -1
    b = -1
    c = [0 for x in range(k)]

    for i in range(k):
        if cache[i] not in pls and time[i] > ta: #当cache中的值不在pls中且对应未使用时间比原先的大时，将此时cache的下标赋值给a
            a = i
            ta = time[i]
        elif cache[i] in pls and c[i] == 0 and b < pls.index(cache[i]): 
            """当cache中的值在pls中且此时cache的值未被记录,
               同时b小于当前cache元素在pls中对应的下标时,
               将pls的下标赋值给b"""
            c[i] = 1
            b = pls.index(cache[i])
    
    if a != -1:
        return a , False
    else:
        return b , True

def timeadd(k,time):
    for i in range(k):
        time[i] += 1
    return time

if __name__ == '__main__':
    k , n , s = map(int, input().split()) #cache的总个数
    no = input()
    cache = []
    time = [0 for x in range(k)] #存储多长时间未使用对应cache
    ans = [] #存储答案
    
    pls1 = input()
    pls2 = pls1.replace(' ', '')
    pls = list(pls2)
    
    t = len(pls)
    while t != 0:
        if s - t < k: #将请求序列pls的前k个元素依次赋值给k个cache
            add = pls[0]
            cache.append(add)
            pls.remove(add)
            t -= 1
        else:
            target,flag = which(k,cache,time,pls)
            if pls[0] in cache: #当pls[0]在cache中时
                temp = pls[0]
                time[cache.index(temp)] = 0
                t -= 1
                pls.remove(temp)
                time = timeadd(k,time)
                continue
            if flag: #cache中的元素都可以在pls中找到,且pls不在cache时
                temp = pls[target] #将请求序列pls中的目标元素值赋值给temp
                temp2 = pls[0] #将将要插入的请求序列pls的值赋值给temp2
                re_index = cache.index(temp) #记录下需要替换的cache的下标
                time[re_index] = 0 #重置time计数器的值
                ans.append(cache[re_index])
                cache[re_index] = temp2 #替换cache的值
                pls.remove(temp2)
                t -= 1
                time = timeadd(k,time)
            else: #cache中的元素出现了不能在pls中找到
                temp = pls[0] #将将要插入的请求序列pls的值赋值给temp
                time[target] = 0 #重置time计时器的值
                ans.append(cache[target]) 
                cache[target] = temp#替换cache的值
                pls.remove(temp)
                t -= 1
                time = timeadd(k,time)

    for i in range(0,len(ans)):
        print(ans[i], end=" ")