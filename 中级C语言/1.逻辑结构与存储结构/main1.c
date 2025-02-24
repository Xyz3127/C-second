一、逻辑结构
	1.集合结构---------------------------无关系
	2.线性结构(前驱、后继)---------------一对一
	3.树形结构---------------------------一对多
	4.图形结构---------------------------多对多
二、存储结构
	顺序存储（数组）----------------可以实现随机存取
									每个元素占用最小空间
									只能使用整块存储单元，会产生很多的碎片
									插入和删除操作需要移动大量的元素
									线性表变化比较大是，难以确定存储空间的大小
									
	链式存储（结构体实现）----------充分利用所有存储单元，不会产生碎片
									只能顺序存取
		 							需要额外的空间来存放下一节点的指针

	索引存储
	散列存储
三、算法----------------------------对特定问题求解步骤的描述
	有穷
	确定
	可行
	输入
	输出
四、时间复杂度(求极限)
	（运行次数去表示时间复杂度。时间和运行次数正相关）
	时间复杂度指算法中所有语句的频度之和
		T(n)=O(f(n))
	n是问题的规模，f（n）是问题规模的某个函数
	1 < log2n < n < nlog2n < n^2 < n^3 < 2^n < n!
五、空间复杂度
	算法运行过程中所使用的辅助空间的大小
		S(n) = O(f(n))
 