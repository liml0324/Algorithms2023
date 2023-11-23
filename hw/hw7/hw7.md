## Q1
首先，抛弃所有质量大于等于W的物品。显然这些物品绝不会出现在给定的总重量和总价值分别为$W, V$的解中。

对于剩下的物品，取系数$b = \frac{\epsilon W}{n}$，对每一个质量为$w_i$的物品，计算它的一个新的质量$w_i' = \lfloor\frac{w_i}{b}\rfloor$，$\widetilde{w_i} = bw_i'$。

然后使用Algorithm Design中6.4节末尾的动态规划算法，计算用剩余物品填充背包的最优解，但每个物品的质量替换为$w_i'$，且背包的最大容量为$\lceil \frac{W}{b} \rceil$。

在这之后，我们找到求出的最优解中，使得$\Sigma_{i\in S}\widetilde{w_i} \le W$（即$OPT(n, W')中的W' \le W/b$。由于我们取背包的最大容量为$\lceil \frac{W}{b} \rceil$，因此每一个总质量满足条件的最优解都会被求得），且$\Sigma_{i\in S} v_i$最大的集合$S$。由于向下取整，因此对于总质量和总价值等于给定的$W, V$的子集$S^*$，必然有$\Sigma_{i\in S^*}\widetilde{w_i} \le \Sigma_{i\in S^*}w_i \le W$；又由于求出的是最优解，因此最后求得的$S$必然满足$\Sigma_{i\in S} v_i \ge V$（否则至少可以求得$S^*$）。

由于$w_i \le \widetilde{w_i} + b = \widetilde{w_i} + \frac{\epsilon W}{n}$，我们有$\Sigma_{i\in S}w_i \le \Sigma_{i\in S}(\widetilde{w_i} + \frac{\epsilon W}{n}) \le \Sigma_{i\in S}\widetilde{w_i} + \epsilon W \le W +\epsilon W = (\epsilon + 1)W $。因此$S$即为满足条件的近似解。

最后讨论算法的时间复杂度。Algorithm Design中已经给出了6.4节末尾的动态规划算法的时间复杂度为$O(nW)$。这里我们传入的$W$实际为$\lceil \frac{W}{b} \rceil \le \frac{n}{\epsilon} + 1$，因此时间复杂度为$O(n^2/\epsilon)$，这一部分满足题目要求；求出最优解后找到满足条件的集合$S$的时间复杂度为$O(W/b) = O(n/\epsilon)$，满足题目要求。

综上，上面给出的算法就是一个符合题意的多项式时间复杂度算法。

## Q2
算法伪代码如下（采用的是C语言风格，但数组下标范围为1到n而非0到n-1）：
```C
int find_diff(int a[], int l, int r, int n) {//这里不妨设数组元素都为整数，换成浮点数也不影响正确性
    if(l < n && a[l] != a[l+1])  return l;
    else if(l == r) return -1;//-1表示没有找到，根据题设这种情况实际不会出现
    int mid = (l + r) / 2;
    if(a[l] != a[mid])  return find_diff(a, l, mid, n);
    else    return find_diff(a, mid, r, n);
}
```

这个算法类似二分查找，每次递归调用都会使得搜索范围减半，因此时间复杂度为$O(\log n)$。

## Q3
伪代码如下（设向量的下标从1开始）：
```py
def calc_vector(n, v)
    if n == 1:
        return v
    else 
        v11 = calc_vector(n-1, v[1...v.length/2])
        v12 = calc_vector(n-1, v[v.length/2+1...v.length])
        for i from 1 to v.length/2:
            v1[i] = v11[i] + v12[i]
            v2[i] = v11[i] - v12[i]
        return v1 + v2  # 这里的v1+v2是向量的连接
```
设该算法的时间复杂度为$T(n)$。在$n \ge 2$时，由于该算法执行时会递归调用两个规模为$n-1$的子问题，且在递归调用之后会进行代价为$O(n)$的计算，因此有$T(n) = 2T(n-1) + cn$；在$n = 1$时，不妨设$T(0) = 0$，那么$T(1) = O(1)$仍符合上式。

下面证明存在常数$c'$，使$T(n) \le c'n2^n$。首先$n=1$时，显然可取$c' \ge 1$使该式成立。假设对$n-1$时成立，则$T(n) \le 2c'(n-1)2^{n-1} + 2c(n-1) = c'n2^n + 2cn - c'2^n - 2c$，取$c' \ge 2c$，则一定有$T(n) \le c'n2^n$。由归纳法可知，$T(n) = O(n2^n)$。

综上，该算法满足要求。

## Q4

### (a)
先证明一个引理：如果在出错c次后，所有同学的权重和已经小于$\frac{1}{2^{m-1}}$，那么在这之后的每次判断都必然正确。

这是因为此时正确率最高的同学必然已经出错m次，否则他的权值将大于等于$\frac1{2^{m-1}}$，超过总权值。由于正确率最高的同学错误次数已经用完，之后不再出错（权值不变）；而此时他的权值（$\frac{1}{2^m}$）占比已经超过一半，且之后总权值不会增加，因此他占比总是超过一半。即正确答案总是占超过一半的权值。

不妨设每次小牛出错时，错误答案的权值占总权值的比重为$a$，那么出错之后总权值会减少为原来的$1-a/2$。由于$a > \frac12$，因此每次出错后，总权值会减少为原来的$\frac{3}{4}$以下。再结合引理，只需要错误次数$c$满足$n(\frac{3}{4})^c < \frac1{2^{m-1}}$，之后小牛就不再出错。两边取对数容易得到$c = \frac{m+\log_2n}{2-\log_23}$满足条件。因此至多判断错误$\frac{m+\log_2n}{2-\log_23}$次。

### (b)
证明：
设对于第i个问题，判断错误的同学的总权值占全部同学总权值的比例为$\alpha_i$，判断错误的期望次数为$EN$。则$EN = \Sigma\alpha_i$。
那么问了T个问题后，全体同学的总权值为：
$W_T = n \Pi_{i=1}^T(1+(\beta-1)\alpha_i) = n \cdot exp\{T \Sigma_{i=1}^T\frac{1}{T}\ln (1+(\beta-1)\alpha_i)\}$
显然$\ln (1+x)$是上凸函数，因此根据琴生不等式：
$$
\begin{aligned}
W_T &\le n \cdot exp\{T \ln (1+(\beta-1)\Sigma_{i=1}^T\frac{\alpha_i}{T})\} \\
& = n(1+(\beta-1)\Sigma_{i=1}^T\frac{\alpha_i}{T})^T \\
& = n((1+(\beta-1)\Sigma_{i=1}^T\frac{\alpha_i}{T})^{\frac{T}{(\beta-1)\Sigma_{i=1}^T\alpha_i}})^{(\beta-1)\Sigma_{i=1}^T\alpha_i} \\
\end{aligned}
$$
令$T \rightarrow \infin$，$W_T \rightarrow ne^{(\beta-1)EN}$

由于对小牛帮助最大的同学至多错m次，因此他的权值至少为$\beta^m$。$\beta^m \le W_T$

那么$T \rightarrow \infin$时，$\beta^m \le ne^{(\beta-1)EN}$
两边取对数可得$EN \le \frac{m\ln 1/\beta + \ln n}{1-\beta}$