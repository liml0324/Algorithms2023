# hw4

## Q1
一个满足该性质的长度为n的正整数序列，其中的最大值至多为n。这一点由数学归纳法很容易证得。
那么设长度为n，最大值为k(k <= n)的限制增序列的个数为f(n, k)。那么长度为n的限制增序列的数目为$\Sigma_{k=1}^{n}f(n, k)$
f满足如下递归关系：
$$
\left\{ 
    \begin{aligned}
    &f(n, 1)=1,&&n \ge 1&  \cr 
    &f(n, k)=f(n-1, k-1) + kf(n-1, k),&&n \ge 2,& k \le n-1& \cr
    &f(n, n)=f(n-1, n-1),&& n\ge 2
    \end{aligned}
\right.
$$
算法如下：
```python {.line-numbers}
Calculate_array_num(n)
let f[1..n, 1..n] be new table.
for i = 1 to n:
    f[i, 1] = 1
for i = 2 to n:
    for j = 2 to i-1:
        f[i, j] = f[i-1, j-1] + j*f[i-1, j]
    f[i, i] = f[i-1, i-1]
sum = 0
for i = 1 to n:
    sum += f[n, i]
return sum
```
算法中第4行执行了n次，第7行执行了$\Sigma_{i=2}^{n-1}(i-2)$次，第8行执行了$n-1$次，第11行执行了n次，其余语句均只执行常数次。因此时间复杂度为$O(n^2)$。

## Q2
假设x[i..j]表示由字符串中第i到第j个字符构成的一个子串。那么设f[i,j]表示x[i..j]的最高质量分值，f[i,j]满足如下递归关系：
$$
\left\{ 
    \begin{aligned}
    &f[i,i] = q(x[i..i])&&1 \le i \le n\cr
    &f[i,j] = max\{q(x[i..j]), max\{f[i,k] + f[k+1,j]\}\},&&i \le k \le j-1&\cr
    \end{aligned}
\right.
$$
算法如下：
```python {.line-numbers}
Calculate_max_score(x, n)
let f[1..n, 1..n] be new table.
for i = 1 to n:
    f[i, i] = q(x[i..i])
for i = 1 to n:
    for j = i+1 to n:
        f[i, j] = q(x[i..j])
        for k = i to j-1:
            if f[i, j] < f[i, k] + f[k+1, j]:
                f[i, j] = f[i, k] + f[k+1, j]
return f[1, n]
```
第4行的语句会执行n次，第7行会执行$O(n^2)$次，第9到10行的if语句会执行$O(n^3)$次，其余语句均只执行常数次。因此时间复杂度为$O(n^3)$。

## Q3
设s[m]表示m年后小牛的最大收益，t[m]表示m年后使小牛收益最大的副业方案中，最后一种副业。那么s[m]和t[m]满足如下递归关系：
$$
\left\{ 
    \begin{aligned}
    &s[1] = p_1&\cr
    &s[m] = max\{mp_1, max\{s[k]-c_j+(m-k-1)p_j\}\},&&m \ge 2, k \le m-1, \cr
    &&&1 \le j \le n, j \neq t[k], \cr
    &&&c_j \le s[k]&\cr
    &t[1] = 1&\cr
    &t[m] = \left\{
        \begin{aligned}
        &1, &若s[m]取mp_1\cr
        &j, &若s[m]取s[k]-c_j+(m-k-1)p_j
        \end{aligned}
        \right.
    \end{aligned}
\right.
$$
算法如下：
```python {.line-numbers}
Calculate_max_profit(p, c, m, n)
let s[1..m] and t[1..m] be new arrays.
s[1] = p[1]
t[1] = 1
for i = 2 to m:
    s[i] = i*p[1]
    t[i] = 1
    for k = 1 to i-1:
        for j = 1 to n:
            if j != t[k] and c[j] <= s[k] and s[i] < s[k] - c[j] + (i-k-1)*p[j]:
                s[i] = s[k] - c[j] + (i-k-1)*p[j]
                t[i] = j
return s[n]
```
算法中第6、7行会执行m-1次，第10到12行的if语句块会执行$O(nm^2)$次，其余语句均只执行常数次。因此时间复杂度为$O(nm^2)$。

## Q4
设当最后一个摊位的位置为i时，小牛开夜宵摊的每晚最大收益为s[i]。那么s[i]满足如下递归关系（为方便起见，设$s[0]=0, m_0=-\infin$）：
$$
\left\{ 
    \begin{aligned}
    &s[0] = 0, s[1] = p_1&\cr
    &s[i] = max\{s[l]+p_i\},&&i \ge 2, 0 \le l \le i-1, m_i-m_l \ge k\cr
    \end{aligned}
\right.
$$
算法如下：
```python {.line-numbers}
Calculate_max_profit(p, m, n, k)
let s[0..n] be new array.
s[0] = 0
s[1] = p[1]
for i = 2 to n:
    s[i] = s[0] + p[i]
    for l = 1 to i-1:
        if m[i] - m[l] < k:
            s[i] = max{s[i], s[l] + p[i]}
res = s[1]
for i = 2 to n:
    if res < s[i]:
        res = s[i]
return res
```
算法中第6行会执行n-1次，第7到9行的if语句块会执行$O(n^2)$次，第12到13行的if语句块会执行n-1次，其余语句均只执行常数次。因此时间复杂度为$O(n^2)$。