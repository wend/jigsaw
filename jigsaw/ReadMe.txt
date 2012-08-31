Run as
./jigsaw ../jigsaw_data.txt

jigsaw_data.txt是数据文件
第一行数据是r行c列信息
紧接着就是r行数据，每行有c列，都以“，”分隔
由于拼图不一定是规则的矩形，所以不规则的地方用-1补齐

PictureElement则是拼图碎片的结构体信息，其中
	int columeOffset; // 代表矩阵信息的第一行中第一列不是-1值的偏移列
    int rowOffset;    // 代表矩阵信息的第一列中第一行不是-1值的偏移列
    bool isUsed;      // 是否已经用来拼图了
    int rowIndex;     // 如果已经用来拼图了，这个拼图碎片在拼图中的左顶点的行位置
    int columeIndex;  // 如果已经用来拼图了，这个拼图碎片在拼图中的左顶点的列位置

PictureElementSet则是所有的拼图碎片的集合

PicturePuzzle则是拼图板

拼图算法流程
1. 从PictureElementSet中取一个没有使用过的拼图碎片，
	取得成功，跳到第2步;
	取得失败，跳到第5步
2. 把碎片往PicturePuzzle中贴，贴的规则遵循往右上贴一块碎片，再往左下贴一块碎片。
	贴时先检查这个不规则碎片能不能贴进去，能的话再去检查碎片的值是否满足values[i][j]=values[j][i]。
	如果贴图失败则跳到第3步
	如果贴图成功则跳到第
3. 把碎片扔回PictureElementSet中，再跳回到第1步。
4. 把碎片的索引号压栈，
	如果栈中的碎片个数与PictureElementSet个数一样多，则拼图成功，输出拼图，
	再跳回到第1步（继续找有没有其它拼图）。
5. 从PicturePuzzle的碎片栈中弹出一块碎片，记录索引号，
	把这块碎片从拼图中揭下来，跳到第3步

	