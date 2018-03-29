for n in range(13, 101):
    m = 1
    while True:
        nums = [x+1 for x in range(n)]
        i = 0
        #print('M:', m)
        while len(nums)>1:
            #print(nums, end='')
            nums.pop(i)
            i = (i+m-1)%(len(nums))
        #print(nums)
        if nums[0] == 13:
            print(m, ',', sep='', end=' ')
            break
        m+=1