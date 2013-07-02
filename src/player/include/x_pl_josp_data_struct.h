#pragma once
#pragma pack(show)		//��ʾ��ǰpacking aligment���ֽ���
#pragma pack(push)		//�������״̬
#pragma pack(4)			//�趨Ϊ4�ֽڶ���	

//cmd
#define JOSP_OPEN_STREAM				0x07        //��ʼԤ��
#define JOSP_OPEN_STREAM_RET			0x08        //Ԥ��Ӧ��

#define JOSP_OPEN_FILE						0x0F        //��ʼ�ط�
#define JOSP_OPEN_FILE_RET				0x10        //�ط�Ӧ��
#define JOSP_REQ_DATA						0x11		//��������
#define	JOSP_REQ_DATA_RET				0x12		//Ӧ��

//JOSP ����Э��ͷ 
struct JOSP_CtrlHead 
{ 
	unsigned char start_code[4];    //ħ���ֶ� JOSP
	unsigned char version:4;        //�汾��
	unsigned char type:2;           //Э������ 0-tcp, 1-udp
	unsigned char flag:2;           //�ְ���־ 0-δ�ְ�, 1-��ʼ, 2-�м�, 3-������
	unsigned char cmd;              //����
	unsigned short sq_num;          //�����
	unsigned char ret;              //������ͷ 0-�޴���
	unsigned char reserved;
	unsigned short ex_length;       //��չ���ݳ���
	unsigned char user_id[32];      //�û�ID
	unsigned char crc[4];           //У����(ѭ������У��)
};

//JOSP ��ʵʱ��Ƶ  
struct JOSP_OpenData 
{ 
	char res_id[32];		//��ԴID
	int stream_type;		//�������� 0-������,1-������
}; 

//JOSP ��ʵʱ��Ƶ���� 
struct JOSP_OpenRetData 
{ 
	unsigned char media_code[4];	//ý������ JOMS
	//��Ƶ��Ϣ
	unsigned char iframe_interval;	//I֡���
	unsigned char fps;				//֡��
	unsigned short width;
	unsigned short height;

	//��Ƶ��Ϣ
}; 

//JOSP ����ʷ��Ƶ
struct JOSP_OpenVod
{
	char res_id[32];						//��ԴID
	unsigned int begin_time;		//��ʼʱ��
	unsigned int end_time;			//����ʱ��
};

//JOSP ����ʷ��Ƶ���� 
struct JOSP_OpenVodRet 
{ 
	unsigned char media_code[4];	//ý������ JOMS
	//��Ƶ��Ϣ
	unsigned char iframe_interval;	//I֡���
	unsigned char fps;				//֡��
	unsigned short width;
	unsigned short height;

	//��Ƶ��Ϣ
}; 

//JOSP ����ý������ 
struct JOSP_RequestData 
{ 
	char res_id[32];						//��ԴID
	unsigned int time_stamp;		//��ʼʱ��(0-��Ч)
	int time_interval;					//ʱ����(ms),��Ƶ�ж೤
}; 

//JOSP ����ý������Ӧ�� 
struct JOSP_RequestRetData
{ 
	int ret;					//������(0-�ɹ�)
}; 


//JOSP ����ͷ��ʽ 
struct JOSP_DataHead 
{ 
	unsigned char start_code[4];	//ħ���ֶ� JOAV
	unsigned int data_len;			//���ݳ���(������ͷ)
	unsigned int frame_type;		//3-I֡,4-B֡,5-P֡,6-��Ƶ֡
	unsigned long frame_seq;		//֡���к�
	int b_last_frame;					//BOOL����,������־
	int reserve;							//Ԥ��
	long long time_stamp;			//ʱ���
}; 

#pragma pack(pop)				//�ָ�����״̬