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

typedef struct SceNotificationUtilProgressInitParams {
	SceWChar16 notificationText[0x273];
	short separator0; //must be 0
	SceNotificationUtilProgressEventHandler eventHandler;
	int unk_4EC; //can be set to 0
	SceWChar16 cancelDialogText[0x3E];
	short separator1; //must be 0
} SceNotificationUtilProgressInitParams;

typedef struct SceNotificationUtilProgressUpdateParams {
	SceWChar16 notificationText[0x7E];
	short separator0; //must be 0
	float targetProgress;
	char reserved[0x3C];
} SceNotificationUtilProgressUpdateParams;

typedef struct SceNotificationUtilProgressFinishParams {
	SceWChar16 notificationText[0x273];
	short separator0; //must be 0
} SceNotificationUtilProgressFinishParams;

/**
 * Initialize notification util for use with BG application.
 *
 * Does not need to be called for normal applications.
 */
SceInt32 SceNotificationUtilInitializeForBgApp(void); // SceNotificationUtilBgApp_CBE814C1

/**
 * Send notification.
 *
 * Text buffer size must be 0x470.
 */
SceInt32 SceNotificationUtilSendNotification(const SceWChar16* text); // SceNotificationUtil_DE6F33F4

/**
 * Clean notifications for calling app from notification history.
 */
SceInt32 SceNotificationUtilCleanHistory(void); // SceNotificationUtil_B0FFFB7B

/**
 * Start BGDL-type notification.
 */
SceInt32 sceNotificationUtilProgressBegin(SceNotificationUtilProgressInitParams* initParams); // SceNotificationUtilProgress_FD0769B0 

/**
 * Update BGDL-type notification.
 */
SceInt32 sceNotificationUtilProgressUpdate(SceNotificationUtilProgressUpdateParams* updateParams); // SceNotificationUtilProgress_D9890A65

/**
 * Finish BGDL-type notification.
 */
SceInt32 sceNotificationUtilProgressFinish(SceNotificationUtilProgressFinishParams* finishParams); // SceNotificationUtilProgress_8CD688A1

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DOLCESDK_PSP2_NOTIFICATIONUTIL_H_ */
