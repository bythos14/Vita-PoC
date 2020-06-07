﻿/**
 * \usergroup{SceNotificationUtil}
 * \usage{psp2/notificationutil.h,SceNotificationUtil_stub,SCE_SYSMODULE_NOTIFICATION_UTIL}
 */


#ifndef _DOLCESDK_PSP2_NOTIFICATIONUTIL_H_
#define _DOLCESDK_PSP2_NOTIFICATIONUTIL_H_

#include <psp2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Errors
 */
#define SCE_NOTIFICATIONUTIL_ERROR_INTERNAL               0x80106301;

/**
 * BGDL-type notification event handler function
 */
typedef void(*SceNotificationUtilProgressEventHandler)(int eventId);

typedef struct SceNotificationUtilProgressInitParam {
	SceWChar16 notificationText[0x3F];
	SceInt16 separator0;						//must be 0
	SceWChar16 notificationSubText[0x3F];
	SceInt16 separator1;						//must be 0
	SceChar8 unk[0x3E6];
	SceNotificationUtilProgressEventHandler eventHandler;
	SceInt32 unk_4EC;							//can be set to 0
	SceWChar16 cancelDialogText[0x3F];
	SceInt16 separator2;						//must be 0
} SceNotificationUtilProgressInitParam;

typedef struct SceNotificationUtilProgressUpdateParam {
	SceWChar16 notificationText[0x3F];
	SceInt16 separator0;						//must be 0
	SceWChar16 notificationSubText[0x3F];
	SceInt16 separator1;						//must be 0
	SceFloat targetProgress;
	SceChar8 reserved[0x38];
} SceNotificationUtilProgressUpdateParam;

typedef struct SceNotificationUtilProgressFinishParam {
	SceWChar16 notificationText[0x3F];
	SceInt16 separator0;						//must be 0
	SceWChar16 notificationSubText[0x3F];
	SceInt16 separator1;						//must be 0
	SceChar8 path[0x3E8];
} SceNotificationUtilProgressFinishParam;

/**
 * Initialize notification util for use with BG application.
 *
 * Does not need to be called for normal applications.
 */
SceInt32 sceNotificationUtilInitializeForBgApp(void); // SceNotificationUtilBgApp_CBE814C1

/**
 * Send notification.
 *
 * Text buffer size must be 0x470.
 */
SceInt32 sceNotificationUtilSendNotification(const SceWChar16* text); // SceNotificationUtil_DE6F33F4

/**
 * Clean notifications for calling app from notification history.
 */
SceInt32 sceNotificationUtilCleanHistory(void); // SceNotificationUtil_B0FFFB7B

/**
 * Start BGDL-type notification.
 */
SceInt32 sceNotificationUtilProgressBegin(SceNotificationUtilProgressInitParam* initParams); // SceNotificationUtilProgress_FD0769B0 

/**
 * Update BGDL-type notification.
 */
SceInt32 sceNotificationUtilProgressUpdate(SceNotificationUtilProgressUpdateParam* updateParams); // SceNotificationUtilProgress_D9890A65

/**
 * Finish BGDL-type notification.
 */
SceInt32 sceNotificationUtilProgressFinish(SceNotificationUtilProgressFinishParam* finishParams); // SceNotificationUtilProgress_8CD688A1

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DOLCESDK_PSP2_NOTIFICATIONUTIL_H_ */
