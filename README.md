# Mastermind

珠玑妙算问题的C++实现  

---

- Ref:  
  - [问题来源：Bangumi帖子](https://bgm.tv/group/topic/373458)  
  - [Wikipedia](https://en.wikipedia.org/wiki/Mastermind_%28board_game%29)  
  - [通解 p <= n+3](https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.1084.9503&rep=rep1&type=pdf)
  - [楼主的编码参考，Python 实现](https://gist.github.com/fireattack/0257bdb5d624e535b49a6556b417c68f)
  
---

- Match() 求得分，朴素版以 vector\<int\> 形式存储，优化版写 struct{vec\<int\> attempt, int score}
- Diff() 求选项差异，实现与Match相同，使用图结构存储所有的答案结点
- Table 类，提供Table，Match，Mark etc.
- 作答集中，每个答案有“得分”属性，和其他选项之间有“得分差异”属性

- 构成
  - Done
    - Table类，基础设施，简化实现
    - Seq类，以vector\<int\>实现，基础设施，与Table配合
  - Working On
    - Random头函数，提供生成RandInt功能
  - SeqGen类，派生Question类、Answer类，出题 & 作答机
  - Seq->Table->Match; 或 Table.Match(Seq); 或
  - 学习 Gtest 和 CMake 的使用
