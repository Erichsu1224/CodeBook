# Codeforces #614 div2

## A
水題，字元處理

## B
水題，對他的idx做sorting  
從左邊開始搜，不斷更新當下最大和最小的idx  
如果 maxx-minn = i 則輸出1，反之則0

## C
水題，簡單的條件判斷

## D
用deque做，一開始放最多的那個，能放就放Greedy

## E

## F
一開始用 dfs 枚舉TLE  
看了別人的 code 才知道是DP
有四種情況：  
	1. str[i] != '('
		dp[i][j] = (dp[i][j] + dp[i+1][j])%mod  
		由於i不是'('所以狀態直接向內繼承
	2. str[j] != ')'
		dp[i][j] = (dp[i][j] + dp[i][j-1])%mod  
		由於j不是')'所以狀態直接向內繼承
	3. str[i] != '(' && str[j] != ')
		dp[i][j] = (dp[i][j] - dp[i+1][j-1] +mod )%mod  
		如果同時滿足，前兩項會多加 應此要扣回去  
		並且注意，由於是相減，有可能<0因此先加mod再去%保證他為正
	4. str[i] != ')' && str[j] != '('
		dp[i][j] = ((dp[i][j] + dp[i+1][j-1])%mod + poww(2, ques[j-1]-ques[i]))%mod  
		重新計算

