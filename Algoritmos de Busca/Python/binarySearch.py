import random as rand

def binarySearch(nums, n):
    l, r = 0, len(nums)-1
    while l <= r:
        mid = int((l + r)/2)
        if nums[mid] == n:
            return mid
        elif nums[mid] > n:
            r = mid - 1
        else:
            l = mid + 1
    return -1

nums = [rand.randint(0,20)+(i*20) for i in range(20)]
print(nums)
n = int(input())
result = binarySearch(nums, n)
print(result) if n != -1 else print("Não foi encontrado.")
