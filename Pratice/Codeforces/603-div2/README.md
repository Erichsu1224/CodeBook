# CodeForce#612 2019/11/29

## A
原本用 priority_queue 做 TLE，沒想到是結論題ans = min((a+b+c)/2, min(a+b, min(b+c, a+c)))

## B
用 map 去存東西有沒有出現過，如果出現過去改其中一個 digit

## C
用 set 去存防止重複，並且for(int i = 1; i*i <= n; i++)	防止TLE

## D
用vector 存26個字母分別出現在哪些密碼裡面，然後用disjoin Set 去分群，找有幾群

## E
用Segment tree 作維護，分別有三個tree，sum存加總,ma存最大(用來知道當下所需要的color),mi存最小，當=='('值傳1, ==')'值傳-1,其他則傳0  
sum[n] = sum[n<<1]+sum[n<<1|1];  
ma[n] = max(ma[n<<1], sum[n<<1]+ma[n<<1|1]  
mi[n] = min(mi[n<<1], sum[n<<1]+mi[n<<1|1]  
  
有點DP的味道在裡面

## F   **非常值得做**
此題為DP + DFS的圖論綜合題，要做DP的點在於，當節點之下的所有邊都被選時，結點之上的邊才會被選，因此會有選和不選的問題(有種贏者全拿的感覺)，因此透過DFS紀錄該範圍(minn, maxx)下所可以選到的邊，再透過Loop去取最大值

