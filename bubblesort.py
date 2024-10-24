import random as rand

def bubbleSort(nums):
    for i in range(len(nums)):
        for j in range(len(nums) - 1 - i):
            if nums[j] > nums[j+1]:
                temp = nums[j]
                nums[j] = nums[j+1]
                nums[j+1] = temp
                del temp

nums = [rand.randint(0,200) for i in range(20)]
bubbleSort(nums)
print(nums)