## 🌉 最小生成樹（Minimum Spanning Tree, MST）

**圖論**，在一個連通圖中選出若干邊，連接所有節點，且總權重最小、不能形成環

---

### 定義
**無向連通圖** -> **最小生成樹(Minimum Spanning Tree, MST)**：
- 包含 **所有節點(node)**
- 邊的總權重(weight) **最小**
- 沒有 **環（cycle）**
- 恰好有 **V - 1邊**（V 為頂點數）

---

## 常見算法

### 1️⃣ Kruskal’s Algorithm
- **流程**：

  - 將邊依照權重**從小到大排序**

  - 依序選邊**若不形成環**則加入MST, 使用 **Union-Find（並查集）**

- **時間複雜度**：O(E log E)
- **適用情況**：邊少的稀疏圖

### 2️⃣ Prim’s Algorithm
- **流程**：

  - 選一個起點

  - 每次選擇**當前能連到 MST 的最小權重邊** 使用 **priority_queue(最小堆)**

  - 重複直到所有節點都被納入

- **時間複雜度**：
  - O(E log V)（使用最小堆 + adjacency list）
  - O(V²)（使用矩陣）
- **適用情況**：節點少但邊多的稠密圖


### 3️⃣ Borůvka's Algorithm：適合分布式環境但較少使用

---

### 📚 相關題目

| 題號 | 解題提示 |
|------|----------------------------------------------------|
| [10034](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=978) | 先計算所有點間歐氏距離，建完整圖後用 Kruskal 求 MST |
| [10147](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1090) | 題目已經給部分連通邊，建圖時一開始就 union 起來 |
| [10369](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1300) | Kruskal 排序邊後，去掉最大的 S−1 條邊，模擬分群 |
| [10457](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1398) | 路徑中速度變化會耗能，Prim 建 MST 後加上能量計算邏輯 |
| [11228](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2175) | 邊長小於 R 計為道路，大於 R 計為鐵路，建 MST 同時計算分類 |
| [11631](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2688) | 輸出節省成本：總邊權重總和 - MST 權重 |
| [11710](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2755) | 輸入是字串節點名，要建 map，圖若不連通則輸出 "Impossible" |
| [11857](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2999) | 回答最大權重邊，Prim 實作後記錄每次選擇的最大邊即可 |



### MST 變形題目（Variants）
| 題號 | 備註 |
|------|------------------------------|
| 10457 | Energy-limited MST：MST 結合額外限制條件 :contentReference[oaicite:8]{index=8} |
| 00534 / 00544 / 01013… | Minimax / Maximin / second-best MST 等變形題 :contentReference[oaicite:9]{index=9} |
| 01234 / 01235 / 01265… | 最大生成樹（Max ST）或特定 MST 變種 :contentReference[oaicite:10]{index=10} |
| 木屋、Treehouses、Landline、Inventing… | 涉及 MST 加上附加條件的特殊題型 :contentReference[oaicite:11]{index=11} |

---

## 摘要整理 📋

- **標準 MST」題型**：如 Freckles（10034）、Transportation System（11228）、Expensive subway（11710）、Driving Range（11857）等，主要考核 MST 基本演算法與 union-find／Kruskal 或 Prim 應用 :contentReference[oaicite:12]{index=12}。
- **變形 MST 題型**：如 Arctic Network（10369，MST 模擬 forest）、Energy-limited MST（10457）、第二生成樹、最大生成樹等進階主題，經常在 CP 4 的 4.3b 章節出現 :contentReference[oaicite:13]{index=13}。

| 題型                  | 說明                         | 代表題目（UVa Online Judge）      | 題號    | 備註             |
| ------------------- | -------------------------- | --------------------------- | ----- | -------------- |
| Arctic Network      | MST 模擬森林（多群組連通）            | Arctic Network              | 10369 | 模擬森林，多群 MST 問題 |
| Energy-limited MST  | 限制能量條件下的 MST               | Energy-limited MST          | 10457 | 加入能量限制的最短生成樹   |
| 第二生成樹 (Second MST)  | 除了 MST 以外的次優生成樹            | Is There A Second Way Left? | 10462 | 求次優 MST        |
| 最大生成樹 (Maximum MST) | 最大權重生成樹（改 Kruskal）         | -                           | -     | Kruskal 反向排序權重 |
| Bottleneck MST      | 最小瓶頸生成樹（Minimize max edge） | Freckles                    | 10034 | 瓶頸邊最小化問題       |
| MST 的變形題型           | 如道路網路連通限制、叢林連接等            | Transportation system       | 11228 | 限制不同種類邊的連通問題   |

---

## 🧠 性質
1. **唯一性**：
   - 如果邊的權重都不相同，則 MST 是唯一的。
2. **邊的交換性質（Cut Property）**：
   - 對任意一個將圖分成兩部分的切割（cut），**橫跨這個切割的最小權重邊必定在 MST 中**。
3. **Cycle Property（環屬性）**：
   - 在任意一個環中，若一條邊的權重是**最大值**，則它不會出現在任何 MST 中。


