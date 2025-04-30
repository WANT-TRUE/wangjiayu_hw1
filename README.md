# **wangjiayu-hw1**  
## 1.代码思路  
    （1）矩阵的秩  
        使用高斯消元法将矩阵转换为行阶梯形，通过行变换将矩阵化简，
        过程中记录  非零行的数量，这个数量就是矩阵的秩。具体来说， 
        依次处理每一列，寻找当  前列的主元（绝对值最大的元素），  
        找到后将主元所在的行移到当前处理行的位置，然后消去主元下方  
        的所有元素  。每完成一列的处理，秩增加1，直到所有列处理完毕。
    （2）矩阵的行列式
        对于1×1和2×2矩阵，直接使用公式计算行列式。对于更大的矩阵， 
        先将矩阵数据复制到临时矩阵中，然后通过高斯消元法进行行变换， 
        将矩阵转换为上三角矩阵，过程中记录行交换次数以确定行列式的符号，
        最后计算主对角线元素乘积并乘以符号得到行列式值。
## 2.代码功能实现
    （1）矩阵加法  
![](https://picturebucket-1357412479.cos.ap-nanjing.myqcloud.com/%E5%9B%BE%E7%89%87/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE(11).png)  

    (2)矩阵减法
![](https://picturebucket-1357412479.cos.ap-nanjing.myqcloud.com/%E5%9B%BE%E7%89%87/20250501025634.png)  

    （3）矩阵乘法
![](https://picturebucket-1357412479.cos.ap-nanjing.myqcloud.com/%E5%9B%BE%E7%89%87/20250501025703.png)  

    （4）矩阵数乘
![](https://picturebucket-1357412479.cos.ap-nanjing.myqcloud.com/%E5%9B%BE%E7%89%87/20250501025721.png)  

    （5）矩阵转置
![](https://picturebucket-1357412479.cos.ap-nanjing.myqcloud.com/%E5%9B%BE%E7%89%87/20250501025741.png)  

    （6）矩阵的行列式
![](https://picturebucket-1357412479.cos.ap-nanjing.myqcloud.com/%E5%9B%BE%E7%89%87/20250501025932.png)  

    （7）矩阵的秩
![](https://picturebucket-1357412479.cos.ap-nanjing.myqcloud.com/%E5%9B%BE%E7%89%87/20250501025953.png)  

    （8）矩阵的迹
![](https://picturebucket-1357412479.cos.ap-nanjing.myqcloud.com/%E5%9B%BE%E7%89%87/20250501030006.png)  

## 3.自学过程作业
    camke和makefile的实现
![](https://picturebucket-1357412479.cos.ap-nanjing.myqcloud.com/%E5%9B%BE%E7%89%87/20250501033644.png)