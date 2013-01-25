
#ifndef DHCONFIGSDK_H
#define DHCONFIGSDK_H

#ifdef WIN32

#ifdef DHCONFIGSDK_EXPORTS
#define CLIENT_API  __declspec(dllexport) 
#else
#define CLIENT_API  __declspec(dllimport)
#endif

#define CALLBACK __stdcall
#define CALL_METHOD  __stdcall  //__cdecl

#else	//linux

#define CLIENT_API	extern "C"
#define CALL_METHOD
#define CALLBACK


#endif


#ifdef __cplusplus
extern "C" {
#endif


/************************************************************************
 ** ��������
 ***********************************************************************/

#define MAX_CHANNEL_COUNT		8
#define MAX_VIDEO_CHANNEL_NUM	256					// ���ͨ����256
#define MAX_CHANNELNAME_LEN		32					// ���ͨ�����Ƴ���
#define MAX_VIDEOSTREAM_NUM		3					// �����������
#define MAX_VIDEO_COVER_NUM		16					// ����ڵ��������
#define WEEK_DAY_NUM			7					// һ�ܵ�����
#define MAX_REC_TSECT			6					// ¼��ʱ��θ���
#define MAX_WATERMARK_LEN		4096				// ����ˮӡ������󳤶�
#define MAX_MOTION_ROW			32					// ��̬������������
#define MAX_MOTION_COL			32					// ��̬������������
#define MAX_IMAGESIZE_NUM		256					// ���֧�ֵķֱ��ʸ���
#define MAX_FPS_NUM				1024				// ���֧�ֵ�֡�ʸ���
#define MAX_QUALITY_NUM			32					// ���֧�ֵĻ��ʸ���
#define MAX_ADDRESS_LEN			256					// ���ĵ�ַ����
#define MAX_USERNAME_LEN		64					// ����û�������
#define MAX_PASSWORD_LEN		64					// ������볤��
#define MAX_DIRECTORY_LEN		256					// �ļ��������ַ�������
#define MAX_NAS_TIME_SECTION	2					// ����洢ʱ��θ���
#define MAX_NAME_LEN			32					// ͨ�������ַ�������
#define MAX_DECPRO_LIST_SIZE	100					// ������Э���б��������
#define MAX_SCENE_LIST_SIZE		16					// ��Ƶ�����豸֧�ֵĳ��������б��������
#define MAX_OBJECT_LIST_SIZE	16					// ��Ƶ�����豸֧�ֵļ�����������б��������
#define MAX_RULE_LIST_SIZE		16					// ��Ƶ�����豸֧�ֵĹ����б��������
#define MAX_MODULE_NUM			16					// ��Ƶ�����豸�����ģ�����
#define MAX_RULE_NUM			16					// ��Ƶ�����豸���������
#define MAX_POLYGON_NUM			4					// ��Ƶ�����豸���򶥵��������
#define MAX_POLYLINE_NUM		2					// ��Ƶ�����豸���߶����������
#define MAX_VEHICLE_SIZE_LIST	4					// ��Ƶ�����豸������С��������
#define MAX_VEHICLE_TYPE_LIST	4					// ��Ƶ�����豸�������͸�������
#define MAX_PLATE_TYPE_LIST		32					// ��Ƶ�����豸�������͸�������
	
	

/************************************************************************
 ** �������� ��ӦCLIENT_GetNewDevConfig��CLIENT_SetNewDevConfig�ӿ�
 ***********************************************************************/

#define CFG_CMD_ENCODE			"Encode"			// ͼ��ͨ����������(��ӦCFG_ENCODE_INFO)
#define CFG_CMD_RECORD			"Record"			// ��ʱ¼������(��ӦCFG_RECORD_INFO)
#define CFG_CMD_ALARMINPUT		"Alarm"				// �ⲿ���뱨������(��ӦCFG_ALARMIN_INFO)
#define CFG_CMD_NETALARMINPUT	"NetAlarm"			// ���籨������(��ӦCFG_NETALARMIN_INFO)
#define CFG_CMD_MOTIONDETECT	"MotionDetect"		// ��̬��ⱨ������(��ӦCFG_MOTION_INFO)
#define CFG_CMD_VIDEOLOST		"LossDetect"		// ��Ƶ��ʧ��������(��ӦCFG_VIDEOLOST_INFO)
#define CFG_CMD_VIDEOBLIND		"BlindDetect"		// ��Ƶ�ڵ���������(��ӦCFG_SHELTER_INFO)
#define CFG_CMD_STORAGENOEXIST	"StorageNotExist"	// �޴洢�豸��������(��ӦCFG_STORAGENOEXIST_INFO)
#define CFG_CMD_STORAGEFAILURE	"StorageFailure"	// �洢�豸���ʳ���������(��ӦCFG_STORAGEFAILURE_INFO)
#define CFG_CMD_STORAGELOWSAPCE	"StorageLowSpace"	// �洢�豸�ռ䲻�㱨������(��ӦCFG_STORAGELOWSAPCE_INFO)
#define CFG_CMD_NETABORT		"NetAbort"			// ����Ͽ���������(��ӦCFG_NETABORT_INFO)	
#define CFG_CMD_IPCONFLICT		"IPConflict"		// IP��ͻ��������(��ӦCFG_IPCONFLICT_INFO)
#define CFG_CMD_SNAPCAPINFO		"SnapInfo"			// ץͼ������ѯ(��ӦCFG_SNAPCAPINFO_INFO)
#define CFG_CMD_NAS				"NAS"				// ����洢����������(��ӦCFG_NAS_INFO)
#define CFG_CMD_PTZ				"Ptz"				// ��̨����(��ӦCFG_PTZ_INFO)
#define CFG_CMD_WATERMARK		"WaterMark"			// ��Ƶˮӡ����(��ӦCFG_WATERMARK_INFO)
#define CFG_CMD_ANALYSEGLOBAL	"VideoAnalyseGlobal"// ��Ƶ����ȫ������(��ӦCFG_ANALYSEGLOBAL_INFO)
#define CFG_CMD_ANALYSEMODULE	"VideoAnalyseModule"// ����ļ��ģ������(��ӦCFG_ANALYSEMODULES_INFO)
#define CFG_CMD_ANALYSERULE		"VideoAnalyseRule"	// ��Ƶ������������(��ӦCFG_ANALYSERULES_INFO)


/************************************************************************
 ** ���������� 
 ***********************************************************************/

#define CFG_CAP_CMD_VIDEOANALYSE "devVideoAnalyse.getCaps"	// ��Ƶ����������(��ӦCFG_CAP_ANALYSE_INFO)


/************************************************************************
 ** ������Ϣ(ÿ���ṹ�嶼��������Ϣ�������ֲ�ͬ�豸����汾�Ͳ�ͬ�ͺ��豸)
 ***********************************************************************/

//-----------------------------ͼ��ͨ������-------------------------------

// ����
typedef enum tagCFG_IMAGE_QUALITY
{
	IMAGE_QUALITY_Q10 = 1,							// ͼ������10%
	IMAGE_QUALITY_Q30,								// ͼ������30%
	IMAGE_QUALITY_Q50,								// ͼ������50%
	IMAGE_QUALITY_Q60,								// ͼ������60%
	IMAGE_QUALITY_Q80,								// ͼ������80%
	IMAGE_QUALITY_Q100,								// ͼ������100%
} CFG_IMAGE_QUALITY;

// ��Ƶѹ����ʽ
typedef enum tagCFG_VIDEO_COMPRESSION
{
	VIDEO_FORMAT_MPEG4,								// MPEG4
	VIDEO_FORMAT_MS_MPEG4,							// MS-MPEG4
	VIDEO_FORMAT_MPEG2,								// MPEG2
	VIDEO_FORMAT_MPEG1,								// MPEG1
	VIDEO_FORMAT_H263,								// H.263
	VIDEO_FORMAT_MJPG,								// MJPG
	VIDEO_FORMAT_FCC_MPEG4,							// FCC-MPEG4
	VIDEO_FORMAT_H264,								// H.264
} CFG_VIDEO_COMPRESSION;

// ��������ģʽ
typedef enum tagCFG_BITRATE_CONTROL
{
	BITRATE_CBR,									// �̶�����
	BITRATE_VBR,									// �ɱ�����
} CFG_BITRATE_CONTROL;

// �ֱ���ö��
typedef enum tagCFG_CAPTURE_SIZE
{
	IMAGE_SIZE_D1,								// 704*576(PAL)  704*480(NTSC)
	IMAGE_SIZE_HD1,								// 352*576(PAL)  352*480(NTSC)
	IMAGE_SIZE_BCIF,							// 704*288(PAL)  704*240(NTSC)
	IMAGE_SIZE_CIF,								// 352*288(PAL)  352*240(NTSC)
	IMAGE_SIZE_QCIF,							// 176*144(PAL)  176*120(NTSC)
	IMAGE_SIZE_VGA,								// 640*480
	IMAGE_SIZE_QVGA,							// 320*240
	IMAGE_SIZE_SVCD,							// 480*480
	IMAGE_SIZE_QQVGA,							// 160*128
	IMAGE_SIZE_SVGA,							// 800*592
	IMAGE_SIZE_XVGA,							// 1024*768
	IMAGE_SIZE_WXGA,							// 1280*800
	IMAGE_SIZE_SXGA,							// 1280*1024  
	IMAGE_SIZE_WSXGA,							// 1600*1024  
	IMAGE_SIZE_UXGA,							// 1600*1200
	IMAGE_SIZE_WUXGA,							// 1920*1200
	IMAGE_SIZE_LTF,								// 240*192
	IMAGE_SIZE_720,								// 1280*720
	IMAGE_SIZE_1080,							// 1920*1080
	IMAGE_SIZE_1_3M,							// 1280*960
	IMAGE_SIZE_NR  
} CFG_CAPTURE_SIZE;

// ��Ƶ��ʽ
typedef struct tagCFG_VIDEO_FORMAT
{
	// ����
	bool				abCompression;
	bool				abWidth;
	bool				abHeight;
	bool				abBitRateControl;
	bool				abBitRate;
	bool				abFrameRate;
	bool				abIFrameInterval;
	bool				abImageQuality;
	bool				abFrameType;

	// ��Ϣ
	CFG_VIDEO_COMPRESSION emCompression;			// ��Ƶѹ����ʽ
	int					nWidth;						// ��Ƶ���
	int					nHeight;					// ��Ƶ�߶�
	CFG_BITRATE_CONTROL	emBitRateControl;			// ��������ģʽ
	int					nBitRate;					// ��Ƶ����(kbps)
	int					nFrameRate;					// ��Ƶ֡��
	int					nIFrameInterval;			// I֡���(1-100)������50��ʾÿ49��B֡��P֡������һ��I֡��
	CFG_IMAGE_QUALITY	emImageQuality;				// ͼ������
	int					nFrameType;					// ���ģʽ��0��DHAV��1��"PS"
} CFG_VIDEO_FORMAT;

// ��Ƶ�������
typedef struct tagCFG_VIDEOENC_OPT
{
	// ����
	bool				abVideoEnable;
	bool				abAudioEnable;
	bool				abSnapEnable;

	// ��Ϣ
	BOOL				bVideoEnable;				// ��Ƶʹ��
	CFG_VIDEO_FORMAT	stuVideoFormat;				// ��Ƶ��ʽ
	BOOL				bAudioEnable;				// ��Ƶʹ��
	BOOL				bSnapEnable;				// ��ʱץͼʹ��
} CFG_VIDEOENC_OPT;

// RGBA��Ϣ
typedef struct tagCFG_RGBA
{
	int					nRed;
	int					nGreen;
	int					nBlue;
	int					nAlpha;
} CFG_RGBA;

// ������Ϣ
typedef struct tagCFG_RECT
{
	int					nLeft;
	int					nTop;
    int					nRight;
    int					nBottom;				
} CFG_RECT;

// ���򶥵���Ϣ
typedef struct tagCFG_POLYGON
{
	int					nX; //0~8191
	int					nY;		
} CFG_POLYGON;

// ���ߵĶ˵���Ϣ
typedef struct tagCFG_POLYLINE
{
	int					nX; //0~8191
	int					nY;		
} CFG_POLYLINE;

// Size
typedef struct tagCFG_SIZE
{
	union
	{
		int				nWidth;			// ��
		int				nArea;			// ���
	};
	int					nHeight;		// ��
	
} CFG_SIZE;

// �ڵ���Ϣ
typedef struct tagCFG_COVER_INFO
{
	// ����
	bool				abBlockType;
	bool				abEncodeBlend;
	bool				abPreviewBlend;

	// ��Ϣ
	CFG_RECT			stuRect;					// ���ǵ���������
	CFG_RGBA			stuColor;					// ���ǵ���ɫ
	int					nBlockType;					// ���Ƿ�ʽ��0���ڿ飬1��������
	int					nEncodeBlend;				// ���뼶�ڵ���1����Ч��0������Ч
	int					nPreviewBlend;				// Ԥ���ڵ���1����Ч��0������Ч
} CFG_COVER_INFO;

// �������ڵ�����
typedef struct tagCFG_VIDEO_COVER
{
	int                 nTotalBlocks;						// ֧�ֵ��ڵ�����
	int					nCurBlocks;							// �����õĿ���
	CFG_COVER_INFO		stuCoverBlock[MAX_VIDEO_COVER_NUM];	// ���ǵ�����	
} CFG_VIDEO_COVER;

// OSD��Ϣ
typedef struct tagCFG_OSD_INFO
{
	// ����
	bool				abShowEnable;

	// ��Ϣ
	CFG_RGBA			stuFrontColor;				// ǰ����ɫ
	CFG_RGBA			stuBackColor;				// ������ɫ
	CFG_RECT			stuRect;					// ��������
	BOOL				bShowEnable;				// ��ʾʹ��
} CFG_OSD_INFO;

// ������ɫ����
typedef struct tagCFG_COLOR_INFO
{
	int					nBrightness;				// ����(0-100)
	int					nContrast;					// �Աȶ�(0-100)
	int					nSaturation;				// ���Ͷ�(0-100)
	int					nHue;						// ɫ��(0-100)
	int					nGain;						// ����(0-100)
	BOOL				bGainEn;					// ����ʹ��
} CFG_COLOR_INFO;

// ͼ��ͨ��������Ϣ
typedef struct tagCFG_ENCODE_INFO
{
	int                 nChannelID;							// ͨ����(0��ʼ)
	char				szChnName[MAX_CHANNELNAME_LEN];		// ͨ������
	CFG_VIDEOENC_OPT	stuMainStream[MAX_VIDEOSTREAM_NUM];	// ��������0����ͨ¼��1-����¼��2������¼��
	CFG_VIDEOENC_OPT	stuExtraStream[MAX_VIDEOSTREAM_NUM];// ��������0��������1��1��������2��2��������3
	CFG_VIDEOENC_OPT	stuSnapFormat[MAX_VIDEOSTREAM_NUM];	// ץͼ��0����ͨץͼ��1������ץͼ��2������ץͼ
	DWORD				dwCoverAbilityMask;					// �����ڸ��������룬��λ�ֱ��Ǳ���Ԥ����¼���������
	DWORD				dwCoverEnableMask;					// �����ڸ�ʹ�����룬��λ�ֱ��Ǳ���Ԥ����¼���������
	CFG_VIDEO_COVER		stuVideoCover;						// ���򸲸�
	CFG_OSD_INFO		stuChnTitle;						// ͨ������
	CFG_OSD_INFO		stuTimeTitle;						// ʱ�����
	CFG_COLOR_INFO		stuVideoColor;						// ������ɫ
} CFG_ENCODE_INFO;

// ˮӡ����
typedef struct tagCFG_WATERMARK_INFO 
{
	int                 nChannelID;					// ͨ����(0��ʼ)
	BOOL				bEnable;					// ʹ�ܿ���
	int					nStreamType;				// ��������(1��n)��0����������
	int					nDataType;					// �������ͣ�1�����֣�2��ͼƬ
	char				pData[MAX_WATERMARK_LEN];	// �ַ���ˮӡ����
} CFG_WATERMARK_INFO;

//-------------------------------¼������---------------------------------

// ʱ�����Ϣ
typedef struct tagCFG_TIME_SECTION 
{
	DWORD				dwRecordMask;						// ¼�����룬��λ�ֱ�Ϊ��̬���¼�񡢱���¼�񡢶�ʱ¼��Bit3~Bit15������Bit16��̬���ץͼ��Bit17����ץͼ��Bit18��ʱץͼ
	int					nBeginHour;
	int					nBeginMin;
	int					nBeginSec;
	int					nEndHour;
	int					nEndMin;
	int					nEndSec;	
} CFG_TIME_SECTION;

// ��ʱ¼��������Ϣ
typedef struct tagCFG_RECORD_INFO
{
	int                 nChannelID;					// ͨ����(0��ʼ)
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT]; // ʱ���
	int					nPreRecTime;				// Ԥ¼ʱ�䣬Ϊ��ʱ��ʾ�ر�(0~300)
	BOOL				bRedundancyEn;				// ¼�����࿪��
	int					nStreamType;				// 0����������1��������1��2��������2��3��������3
} CFG_RECORD_INFO;

//-------------------------------��������---------------------------------

// ��̨��������
typedef enum tagCFG_LINK_TYPE
{
	LINK_TYPE_NONE,						    		// ������
	LINK_TYPE_PRESET,								// ����Ԥ�õ�
	LINK_TYPE_TOUR,									// ����Ѳ��
	LINK_TYPE_PATTERN,								// �����켣
} CFG_LINK_TYPE;

// ������̨��Ϣ
typedef struct tagCFG_PTZ_LINK
{
	CFG_LINK_TYPE		emType;						// ��������
	int					nValue;						// ����ȡֵ�ֱ��ӦԤ�õ�ţ�Ѳ���ŵȵ�
} CFG_PTZ_LINK;

// ����������Ϣ
typedef struct tagCFG_ALARM_MSG_HANDLE
{
	//����
	bool				abRecordMask;
	bool				abRecordEnable;
	bool				abRecordLatch;
	bool				abAlarmOutMask;
	bool				abAlarmOutEn;
	bool				abAlarmOutLatch;	
	bool				abExAlarmOutMask;
	bool				abExAlarmOutEn;
	bool				abPtzLinkEn;
	bool				abTourMask;
	bool				abTourEnable;
	bool				abSnapshot;
	bool				abSnapshotEn;
	bool				abSnapshotPeriod;
	bool				abSnapshotTimes;
	bool				abTipEnable;
	bool				abMailEnable;
	bool				abMessageEnable;
	bool				abBeepEnable;
	bool				abVoiceEnable;
	bool				abMatrixMask;
	bool				abMatrixEnable;
	bool				abEventLatch;
	bool				abLogEnable;
	bool				abDelay;
	bool				abVideoMessageEn;
	bool				abMMSEnable;
	bool				abMessageToNetEn;
	bool				abTourSplit;
	bool				abSnapshotTitleEn;

	//��Ϣ
	int					nChannelCount;								// �豸����Ƶͨ����
	int					nAlarmOutCount;								// �豸�ı����������
	DWORD				dwRecordMask[MAX_CHANNEL_COUNT];				// ¼��ͨ������(��λ)
	BOOL				bRecordEnable;								// ¼��ʹ��
	int					nRecordLatch;								// ¼����ʱʱ��(��)
	DWORD				dwAlarmOutMask[MAX_CHANNEL_COUNT];			// �������ͨ������
	BOOL				bAlarmOutEn;								// �������ʹ��
	int					nAlarmOutLatch;								// ���������ʱʱ��(��)
	DWORD				dwExAlarmOutMask[MAX_CHANNEL_COUNT];			// ��չ�������ͨ������
	BOOL				bExAlarmOutEn;								// ��չ�������ʹ��
	CFG_PTZ_LINK		stuPtzLink[MAX_VIDEO_CHANNEL_NUM];			// ��̨������
	BOOL				bPtzLinkEn;									// ��̨����ʹ��
	DWORD				dwTourMask[MAX_CHANNEL_COUNT];				// ��ѯͨ������
	BOOL				bTourEnable;								// ��ѯʹ��
	DWORD				dwSnapshot[MAX_CHANNEL_COUNT];				// ����ͨ��������
	BOOL				bSnapshotEn;								// ����ʹ��
	int					nSnapshotPeriod;							// ��������(��)
	int					nSnapshotTimes;								// ���Ĵ���
	BOOL				bTipEnable;									// ������Ϣ����ʾ
	BOOL				bMailEnable;								// �����ʼ��������ͼƬ����Ϊ����
	BOOL				bMessageEnable;								// �ϴ�������������
	BOOL				bBeepEnable;								// ����
	BOOL				bVoiceEnable;								// ������ʾ
	DWORD				dwMatrixMask[MAX_CHANNEL_COUNT];				// ������Ƶ����ͨ������
	BOOL				bMatrixEnable;								// ������Ƶ����
	int					nEventLatch;								// ������ʼ��ʱʱ��(��)��0��15
	BOOL				bLogEnable;									// �Ƿ��¼��־
	int					nDelay;										// ����ʱ����ʱ����Ч����λΪ��
	BOOL				bVideoMessageEn;							// ������ʾ��Ļ����Ƶ�����ӵ���Ļ�����¼����ͣ�ͨ���ţ����ʱ��
	BOOL				bMMSEnable;									// ���Ͳ���ʹ��
	BOOL				bMessageToNetEn;							// ��Ϣ�ϴ�������ʹ��
	int					nTourSplit;									// ��ѵʱ�ķָ�ģʽ 0: 1����; 1: 8����
	BOOL				bSnapshotTitleEn;							// �Ƿ����ͼƬ����
} CFG_ALARM_MSG_HANDLE;

// �ⲿ��������
typedef struct tagCFG_ALARMIN_INFO
{
	int					nChannelID;									// ����ͨ����(0��ʼ)
	BOOL				bEnable;									// ʹ�ܿ���
	char				szChnName[MAX_CHANNELNAME_LEN];				// ����ͨ������
	int					nAlarmType;									// ���������ͣ�0�����գ�1������
	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
} CFG_ALARMIN_INFO;

// �������뱨������
typedef struct tagCFG_NETALARMIN_INFO 
{
	int					nChannelID;									// ����ͨ����(0��ʼ)
	BOOL				bEnable;									// ʹ�ܿ���
	char				szChnName[MAX_CHANNELNAME_LEN];				// ����ͨ������
	int					nAlarmType;									// ���������ͣ�0�����գ�1������
	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
} CFG_NETALARMIN_INFO;

// ��̬��ⱨ������
typedef struct tagCFG_MOTION_INFO 
{
	int					nChannelID;									// ����ͨ����(0��ʼ)
	BOOL				bEnable;									// ʹ�ܿ���
	int					nSenseLevel;								// ������1��6
	int					nMotionRow;									// ��̬������������
	int					nMotionCol;									// ��̬������������
	BYTE				byRegion[MAX_MOTION_ROW][MAX_MOTION_COL];	// ����������32*32������
	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
} CFG_MOTION_INFO;

// ��Ƶ��ʧ��������
typedef struct tagCFG_VIDEOLOST_INFO 
{
	int					nChannelID;									// ����ͨ����(0��ʼ)
	BOOL				bEnable;									// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
} CFG_VIDEOLOST_INFO;

// ��Ƶ�ڵ���������
typedef struct tagCFG_SHELTER_INFO 
{
	int					nChannelID;									// ����ͨ����(0��ʼ)
	BOOL				bEnable;									// ʹ�ܿ���
	int					nSenseLevel;								// ������
	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
} CFG_SHELTER_INFO;

// �޴洢�豸��������
typedef struct tagCFG_STORAGENOEXIST_INFO 
{
	BOOL				bEnable;						// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;				// ��������
} CFG_STORAGENOEXIST_INFO;

// �洢�豸���ʳ���������
typedef struct tagCFG_STORAGEFAILURE_INFO 
{
	BOOL				bEnable;						// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;				// ��������
} CFG_STORAGEFAILURE_INFO;

// �洢�豸�ռ䲻�㱨������
typedef struct tagCFG_STORAGELOWSAPCE_INFO 
{
	BOOL				bEnable;						// ʹ�ܿ���
	int					nLowerLimit;					// Ӳ��ʣ���������ޣ��ٷ���(0~99)
	CFG_ALARM_MSG_HANDLE stuEventHandler;				// ��������
} CFG_STORAGELOWSAPCE_INFO;

// ����Ͽ���������
typedef struct tagCFG_NETABORT_INFO 
{
	BOOL				bEnable;						// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;				// ��������
} CFG_NETABORT_INFO;

// IP��ͻ��������
typedef struct tagCFG_IPCONFLICT_INFO 
{
	BOOL				bEnable;						// ʹ�ܿ���
	CFG_ALARM_MSG_HANDLE stuEventHandler;				// ��������
} CFG_IPCONFLICT_INFO;

//-------------------------------ץͼ��������---------------------------------
// ץͼ��������
typedef struct tagCFG_SNAPCAPINFO_INFO  
{
	int					nChannelID;						// ץͼͨ����(0��ʼ)
	DWORD				dwIMageSizeNum;					// ֧�ֵķֱ�����Ϣ
	CFG_CAPTURE_SIZE	emIMageSizeList[MAX_IMAGESIZE_NUM];
	DWORD				dwFramesPerSecNum;				// ֧�ֵ�֡����Ϣ
	int					nFramesPerSecList[MAX_FPS_NUM];
	DWORD				dwQualityMun;					// ֧�ֵĻ�����Ϣ
	CFG_IMAGE_QUALITY	emQualityList[MAX_QUALITY_NUM];

	DWORD               dwMode;							// ģʽ,��λ����һλ����ʱ���ڶ�λ���ֶ���
	DWORD               dwFormat;						// ͼƬ��ʽģʽ,��λ����һλ��bmp���ڶ�λ��jpg��
} CFG_SNAPCAPINFO_INFO;


//-------------------------------����洢����������---------------------------------
// ����洢����������
typedef struct tagCFG_CHANNEL_TIME_SECTION 
{
	CFG_TIME_SECTION stuTimeSection[WEEK_DAY_NUM][MAX_NAS_TIME_SECTION];//�洢ʱ���
} CFG_CHANNEL_TIME_SECTION;

typedef struct tagCFG_NAS_INFO
{
	BOOL						bEnable;									// ʹ�ܿ���
	int							nVersion;									// ����洢�������汾0=�ϵ�FTP��1=NAS�洢
	int							nProtocol;									// Э������0=FTP 1=SMB
	char						szAddress[MAX_ADDRESS_LEN];					// IP��ַ��������
	int							nPort;										// �˿ں�
	char						szUserName[MAX_USERNAME_LEN];				// �ʻ���
	char						szPassword[MAX_PASSWORD_LEN];				// ����
	char						szDirectory[MAX_DIRECTORY_LEN];				// �����Ŀ¼��
	int							nFileLen;									// �ļ�����
	int							nInterval;									// �����ļ�ʱ����
	CFG_CHANNEL_TIME_SECTION	stuChnTime[MAX_VIDEO_CHANNEL_NUM];			// �洢ʱ���
} CFG_NAS_INFO;

//------------------------------��̨����--------------------------------------------
// Э����
typedef struct tagCFG_PRONAME
{
	char				name[MAX_NAME_LEN];			// Э����
} CFG_PRONAME;

// ���ڻ�������
typedef struct tagCFG_COMM_PROP
{
	BYTE				byDataBit;					// ����λ��0��5��1��6��2��7��3��8
	BYTE				byStopBit;					// ֹͣλ��0��1λ��1��1.5λ��2��2λ
	BYTE				byParity;					// У��λ��0����У�飬1����У�飻2��żУ��
	BYTE				byBaudRate;					// �����ʣ�0��300��1��600��2��1200��3��2400��4��4800��													
	                                                // 5��9600��6��19200��7��38400��8��57600��9��115200
} CFG_COMM_PROP;

// ��̨����
typedef struct tagCFG_PTZ_INFO
{
	// ����
	bool				abMartixID;
	bool				abCamID;
	bool				abPTZType;

	// ��Ϣ
	int					nChannelID;								// ͨ����(0��ʼ)	
	CFG_PRONAME         stuDecProName[MAX_DECPRO_LIST_SIZE];	// Э�����б�(ֻ��)
	int					nProName;								// Э�����ͣ���Ӧ"Э�����б�"�±�
	int					nDecoderAddress;						// ��������ַ��0 - 255
	CFG_COMM_PROP		struComm;
	int					nMartixID;								// �����
	int					nPTZType;								// ��̨����0-���ݣ�������̨ 1-Զ��������̨
	int					nCamID;									// ����ͷID
} CFG_PTZ_INFO;
  

//----------------------------------��Ƶ�����豸����------------------------------------------
// ��Ƶ����������
typedef struct tagCFG_CAP_ANALYSE_INFO
{
	int					nSupportedSceneNum;									// ֧�ֵĳ�������
	char				szSceneName[MAX_SCENE_LIST_SIZE][MAX_NAME_LEN];		// ֧�ֵĳ����б�
	int					nMaxMoudles;										// ÿͨ��֧��������ģ����
	int					nSupportedObjectTypeNum;							// ֧�ֵļ���������͸���
	char				szObjectTypeName[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];	// ֧�ֵļ�����������б�
	int					nMaxRules;											// ÿͨ��֧������������
	int					nSupportedRulesNum;									// ֧�ֵĹ������͸���
	char				szRulesName[MAX_RULE_LIST_SIZE][MAX_NAME_LEN];		// ֧�ֵĹ��������б�
	int					nMaxStaffs;											// ֧�ֵ�����߸���
	int					nMaxPointOfLine;									// ������󶥵���
	int					nMaxPointOfRegion;									// ������󶥵���

} CFG_CAP_ANALYSE_INFO;


// ��Ƶ����ȫ������
typedef struct tagCFG_ANALYSEGLOBAL_INFO
{
	// ����
	bool				abCameraHeight;
	bool				abCameraDistance;

	// ��Ϣ
	char				szSceneType[MAX_NAME_LEN];				// Ӧ�ó���,���"֧�ֵĳ����б�"
	double				CameraHeight;							// ����ͷ��ظ߶�	��λ����
	double				CameraDistance;							// ����ͷ��������������ĵ�ˮƽ����	��λ����

} CFG_ANALYSEGLOBAL_INFO;

// ��ͬ���������������ļ��ģ������
typedef struct tagCFG_MODULE_INFO
{
	// ��Ϣ
	char				szObjectType[MAX_NAME_LEN];				// ��������,���"֧�ֵļ�����������б�"
	bool				bSnapShot;								// �Ƿ��ʶ������ץͼ
	int					nDetectRegionPoint;						// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];		// �������
	int					nTrackRegionPoint;						// �������򶥵���
	CFG_POLYGON			stuTrackRegion[MAX_POLYGON_NUM];		// ��������
	int					nFilterType;							// ��������:0:"ByLength",1:"ByArea"
	CFG_SIZE			stuFilterMinSize;						// ������С�ߴ� "ByLength"ģʽ�±�ʾ��ߵĳߴ磬"ByArea"ģʽ�¿��ʾ���������Ч��
	CFG_SIZE			stuFilterMaxSize;						// �������ߴ� "ByLength"ģʽ�±�ʾ��ߵĳߴ磬"ByArea"ģʽ�¿��ʾ���������Ч��

} CFG_MODULE_INFO;

typedef struct tagCFG_ANALYSEMODULES_INFO
{
	int					nMoudlesNum;							// ���ģ����
	CFG_MODULE_INFO     stuModuleInfo[MAX_MODULE_NUM];			// ÿ����Ƶ����ͨ����Ӧ�ĸ�����������ļ��ģ������

} CFG_ANALYSEMODULES_INFO;

// ��Ƶ������������
// ��������Ϊ"CrossLineDetection"��Ӧ�ľ����߹�������
typedef struct tagCFG_CROSSLINE_INFO
{
	// ��Ϣ
	int					nDirection;								// ��ⷽ��:0:��������;1:��������;2:���߶�����
	int					nDetectLinePoint;						// �����߶�����
	CFG_POLYLINE		stuDetectLine[MAX_POLYLINE_NUM];		// ������
		
} CFG_CROSSLINE_INFO;

// ��������Ϊ"CrossRegionDetection"��Ӧ�ľ�������������
typedef struct tagCFG_CROSSREGION_INFO
{
	// ��Ϣ
	int					nDirection;								// ��ⷽ��:0:Enter;1:Leave;2:Both
	int					nDetectRegionPoint;						// ������������
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];		// ������
		
} CFG_CROSSREGION_INFO;


// ͨ�ù�������,��������Ϊ��������ʱʹ��
// "PasteDetection" ATM����
// "LeftDetection" ��Ʒ����
// "Preservation" ��Ʒ��ȫ
// "StayDetection" ͣ��
// "WanderDetection" �ǻ�
// "MoveDetection" �˶�
// "TailDetection" β��
// "RioterDetection" ���ڱ���
// "FightDetection" ���
// "FireDetection" ����
// "SmokeDetection" ����
typedef struct tagCFG_GENERAL_INFO
{
	// ��Ϣ
	int					nMinDuration;							// ��̳���ʱ��	��λ���룬0~65535
	int					nDetectRegionPoint;						// ������򶥵���
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];		// �������
		
} CFG_GENERAL_INFO;

// ��������Ϊ"FlowStat"��Ӧ������ͳ�ƹ�������
typedef struct tagCFG_FLOWSTAT_INFO
{
	// ��Ϣ
	int					nUpperLimit;							// ��������	��λ����/�룬1~65535
	int					nPeriod;								// �ϱ�����	��λ���룬1~65535
	int					nDetectLinePoint;						// ����߶�����
	CFG_POLYLINE		stuDetectLine[MAX_POLYLINE_NUM];		// �����
		
} CFG_FLOWSTAT_INFO;

// ��������Ϊ"NumberStat"��Ӧ������ͳ�ƹ�������
typedef struct tagCFG_NUMBERSTAT_INFO
{
	// ��Ϣ
	int					nUpperLimit;							// �������� ��λ������1~65535
	int					nPeriod;								// �ϱ�����	��λ���룬1~65535
	int					nDetectRegionPoint;						// �����������
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];		// �����
			
} CFG_NUMBERSTAT_INFO;

// ��������Ϊ"TrafficControl"��Ӧ�Ľ�ͨ���ƹ�������
typedef struct tagCFG_TRAFFICCONTROL_INFO 
{
	int					nDetectLinePoint;							            	// ����߶�����
	CFG_POLYLINE		stuDetectLine[MAX_POLYLINE_NUM];			            	// �����
	CFG_TIME_SECTION	stuTimeSchedule[WEEK_DAY_NUM][MAX_REC_TSECT];           	// ����ʱ���
	int					nVehicleSizeNum;							            	// ������С���͸���
	char				szVehicleSizeList[MAX_VEHICLE_SIZE_LIST][MAX_NAME_LEN];		// ������С�����б�"Light-duty":С�ͳ�;	"Medium":���ͳ�; "Oversize":���ͳ�
	int					nPlateTypeNum;												// �������͸���
	char				szPlateTypesList[MAX_PLATE_TYPE_LIST][MAX_NAME_LEN];		// ���������б�"Unknown" δ֪; "Normal" ���ƺ���; "Yellow" ����; "DoubleYellow" ˫���β��
																					// "Police" ����; "Armed" �侯��; "Military" ���Ӻ���; "DoubleMilitary" ����˫��
																					// "SAR" �۰���������; "Trainning" ����������; "Personal" ���Ժ���; "Agri" ũ����
																					// "Embassy" ʹ�ݺ���; "Moto" Ħ�г�����; "Tractor" ����������; "Other" ��������
	int					nPlateNumber;												// ���Ƶ�˫�� 0:����; 1:˫��; 2:��˫��;
	
} CFG_TRAFFICCONTROL_INFO;

// ��������Ϊ"TrafficAccident"��Ӧ�Ľ�ͨ�¹ʹ�������
typedef struct tagCFG_TRAACCIDENT_INFO
{
	// ��Ϣ
	int					nDetectRegionPoint;							// �����������
	CFG_POLYGON			stuDetectRegion[MAX_POLYGON_NUM];			// �����
	
} CFG_TRAACCIDENT_INFO;


// ��������Ϊ"TrafficJunction"��Ӧ��·�ڹ�������
typedef struct tagCFG_TRAJUNCTION_INFO
{
	// ��Ϣ
	int					nLane;									// �������
	int					nStopLinePoint;							// ֹͣ�߶�����
	CFG_POLYLINE		stuStopLine[MAX_POLYLINE_NUM];			// ֹͣ��
	int					nPreLinePoint;							// ǰ���߶�����
	CFG_POLYLINE		stuPreLine[MAX_POLYLINE_NUM];			// ǰ����
	int					nPostLinePoint;							// �����߶�����
	CFG_POLYLINE		stuPostLine[MAX_POLYLINE_NUM];			// ������
	int					nLeftLinePoint;							// �󳵵��߶�����
	CFG_POLYLINE		stuLeftLine[MAX_POLYLINE_NUM];			// �󳵵���
	int					nRightLinePoint;						// �ҳ����߶�����
	CFG_POLYLINE		stuRightLine[MAX_POLYLINE_NUM];			// �ҳ�����
	int					nStopLightRegionPoint;					// ������򶥵���
	CFG_POLYGON			stuStopLightRegion[MAX_POLYGON_NUM];	// �������
	int					nDirection;								// �������� 0:ֱ��,1: ��ת 2:��תֱ�� 3:��ת 4:��תֱ��
	bool				bTurnEn;								// �Ƿ������ͷ
	int					nVehicleSizeNum;						// ������С���͸���
	char				szVehicleSizeList[MAX_VEHICLE_SIZE_LIST][MAX_NAME_LEN];		// ������С�����б�"Light-duty":С�ͳ�;	"Medium":���ͳ�; "Oversize":���ͳ�
	int					nVehicleTypeNum;						// �������͸���
	char				szVehicleTypesList[MAX_VEHICLE_TYPE_LIST][MAX_NAME_LEN];	// ���������б�"Bicycle":���г�; "Non-Motor":�ǻ�����; "Bus":��������; "Motor":������
		
} CFG_TRAJUNCTION_INFO;

// ��������Ϊ"TrafficGate"��Ӧ�Ŀ��ڹ�������
typedef struct tagCFG_TRAFFICGATE_INFO
{
	// ��Ϣ
	int					nLane;									// �������
	int					nDetectLinePoint1;						// �����1������
	CFG_POLYLINE		stuDetectLine1[MAX_POLYLINE_NUM];		// �����1
	int					nDetectLinePoint2;						// �����2������
	CFG_POLYLINE		stuDetectLine2[MAX_POLYLINE_NUM];		// �����2
	int					nLeftLinePoint;							// �󳵵��߶�����
	CFG_POLYLINE		stuLeftLine[MAX_POLYLINE_NUM];			// �󳵵���
	int					nRightLinePoint;						// �ҳ����߶�����
	CFG_POLYLINE		stuRightLine[MAX_POLYLINE_NUM];			// �ҳ�����
	int					nSpeedWeight;							// �ٶ�Ȩ��ϵ��(���ճ���=��������*Ȩ��ϵ��)
	double				MetricDistance;							// ���������ʵ�ʾ���,��λ����
	int					nSpeedUpperLimit;						// �ٶ����� 0��ʾ�������� ��λ��km/h
	int					nSpeedLowerLimit;						// �ٶ����� 0��ʾ�������� ��λ��km/h
	
} CFG_TRAFFICGATE_INFO;


typedef struct tagCFG_RULE_INFO
{
	// ��Ϣ
	char				szRuleName[MAX_NAME_LEN];				// ��������,��ͬ����������
	bool				bRuleEnable;							// ����ʹ��
	int					nObjectTypeNum;							// ��Ӧ�������͸���
	char				szObjectTypes[MAX_OBJECT_LIST_SIZE][MAX_NAME_LEN];		// ��Ӧ���������б�
	char				szRuleType[MAX_NAME_LEN];				// ��������,���"֧�ֵĹ��������б�"
	CFG_CROSSLINE_INFO  stuCrossLineCfg;						// �����߹�������,��������Ϊ"CrossLineDetection"ʱ��Ч
	CFG_CROSSREGION_INFO stuCrossRegionCfg;						// ��������������,��������Ϊ"CrossRegionDetection"ʱ��Ч
	CFG_GENERAL_INFO	stuGeneralCfg;							// ��������Ϊ"PasteDetection","LeftDetection","Preservation",
																// "StayDetection","WanderDetection","MoveDetection","TailDetection",
																// "RioterDetection","FightDetection","FireDetection","SmokeDetection"ʱ��Ч
	CFG_FLOWSTAT_INFO stuFlowStatCfg;							// ����ͳ�ƹ�������, ��������Ϊ"FlowStat"ʱ��Ч
	CFG_NUMBERSTAT_INFO stuNumberStatCfg;						// ����ͳ�ƹ�������,��������Ϊ"NumberStat"ʱ��Ч
	CFG_TRAFFICCONTROL_INFO stuTraControlCfg;					// ��ͨ���ƹ�������,��������Ϊ"TrafficControl"ʱ��Ч
	CFG_TRAACCIDENT_INFO stuAccidentCfg;						// ��ͨ�¹ʹ�������,��������Ϊ"TrafficAccident"ʱ��Ч
	CFG_TRAJUNCTION_INFO stuJunctionCfg;						// ·�ڹ�������,��������Ϊ"TrafficJunction"ʱ��Ч
	CFG_TRAFFICGATE_INFO stuTrafficGateCfg;						// ���ڹ�������,��������Ϊ"TrafficGate"ʱ��Ч

	CFG_ALARM_MSG_HANDLE stuEventHandler;							// ��������
	CFG_TIME_SECTION	stuTimeSection[WEEK_DAY_NUM][MAX_REC_TSECT];// �¼���Ӧʱ���
	
} CFG_RULE_INFO;

typedef struct tagCFG_ANALYSERULES_INFO
{
	int					nRulesNum;								// ��Ƶ����������
	CFG_RULE_INFO		stuRuleInfo[MAX_RULE_NUM];				// ÿ����Ƶ����ͨ����Ӧ����Ƶ������������

} CFG_ANALYSERULES_INFO;

/************************************************************************
 ** �ӿڶ���
 ***********************************************************************/

// ������ѯ����������Ϣ
CLIENT_API BOOL  CALL_METHOD CLIENT_ParseData(char* szCommand, char* szInBuffer, LPVOID lpOutBuffer, DWORD dwOutBufferSize, void* pReserved);

// ���Ҫ���õ�������Ϣ
CLIENT_API BOOL  CALL_METHOD CLIENT_PacketData(char* szCommand, LPVOID lpInBuffer, DWORD dwInBufferSize, char* szOutBuffer, DWORD dwOutBufferSize);


#ifdef __cplusplus
}
#endif

#endif // DHCONFIGSDK_H

