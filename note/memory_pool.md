直接使用系统调用malloc/free、new/delete进行内存分配和释放，有以下弊端：
	a. 调用malloc/new,系统需要根据“最先匹配”、“最优匹配”或其他算法在内存空闲块表中查找一块空闲内存，调用free/delete,系统可能需要合并空闲内存块，这些会产生额外开销
	b. 频繁使用时会产生大量内存碎片，从而降低程序运行效率
	c. 容易造成内存泄漏


内存池（memory pool)是代替直接调用malloc/free、new/delete进行内存管理的常用方法，当我们申请内存空间时，首先到我们的内存池中查找合适的内存块，而不是直接向操作系统申请，优势在于：
	a. 比malloc/free进行内存申请/释放的方式快
	b. 不会产生或很少产生堆碎片
	c. 可避免内存泄漏