# 冒泡排序
# 1.比较相邻元素，如果第二个比第一个小，就叫交换两者。
# 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，第一的元素会是最小的数。
# 针对所有的元素重复以上的步骤，除了最后一个。
# 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

sort_data = [2,4,6,8,9,0,12,13,,24,44,55,6,34,2,4,12,3,45,6,6,3,22,12,13,2,1,22,11,2,1,43,34,45]

def bubble_sort(sort_data):
    length = len(sort_data)
    for i in range(length):
        for j in range(0, length - i):
            if sort_data[i] < sort_data[length - i - j]:
                
                
                
                
def tmp(a, b):
    a = a^b
    b = a^b
    c = a^b

    return a,b
    
    
if __name__ == '__main__':
    a = 3
    b = 4
    print(tmp(a, b))