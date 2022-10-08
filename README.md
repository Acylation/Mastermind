# Mastermind

珠玑妙算问题的C++实现  

---

- Ref:  
  - [问题来源：Bangumi帖子](https://bgm.tv/group/topic/373458)  
  - [Wikipedia](https://en.wikipedia.org/wiki/Mastermind_%28board_game%29)  
  - [通解 p <= n+3](https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.1084.9503&rep=rep1&type=pdf)
  - [楼主的编码参考，Python 实现](https://gist.github.com/fireattack/0257bdb5d624e535b49a6556b417c68f)
  
---

- 随机序列生成类，以 Vector\<int\> 形式存储
- Match() 求得分，朴素版以 Vector\<int\> 形式存储，优化版写 struct{vec\<int\> attempt, int score}
- Diff() 求选项差异，实现与Match相同，使用图结构存储所有的答案结点
- Table 类，派生一个Quiz类，新增linear2table方法
- Table 类
- 作答集中，每个答案有“得分”属性，和其他选项之间有“得分差异”属性
