#include "NodeManager.h"

bool bRun = true;
int main(int argc, char **argv)
{
	/// �ڵ���������
	CNodeManager nodeManager;
	nodeManager.Start(8925);
	/// ���ݹ��������
	while(bRun)
	{
		j_sleep(10);
	}
	nodeManager.Stop();

	return 0;
}