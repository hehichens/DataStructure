2.双向冒泡算法，正反两个方向扫描。

```c
void Double_Bubble_Sort(Elemtype *A, int n){ 
    int low = 1, high = n;
    while(low < high){
        for(int i = low+1; i <= high; ++i)
            if(A[i] < A[i-1])
                Swap(A+i, A+i-1);
        high--;
        for(int j = high; j >= low+1; --j)
            if(A[j] < A[j-1])
                Swap(A+j, A+j-1);
        low++;
    }
}
```



3.把数组中奇数都移动到偶数前面。

> - 采用快排的思想
> - low从前向后，遇到偶数停止
> - high从后向前，遇到奇数停止

```c
void Fast_Move(Elemtype *A, int n){
    int low = 1, high = n;
    while(low < high){
        while(A[low]%2 == 1 && low < high) low++;
        while(A[high]%2 == 0 && low < high) high--;
        Swap(A+low, A+high);
        low++;
        high--;
    }
}
```



5.找出数组中第k小的元素

方法一

> 构建小顶堆，依次取k个元素。

方法二

> 使用计数排序的思想，但是不需要计数排序这么多的空间

方法三

> 基于快排的划分思想 L[1...n]被划分为L[1...m], L[m+1...n], L[m] = pivot
>
> - m = k； 返回pivot即为所求值
> - m < k； 所找元素在L[1...m]中
> - m > k； 所找元素在L[m+1...n]中

