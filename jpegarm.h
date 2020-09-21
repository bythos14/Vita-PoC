/**
 * \usergroup{SceJpegArm}
 * \usage{psp2/jpegarm.h,SceJpegArm_stub,SCE_SYSMODULE_INTERNAL_JPEG_ARM}
 */

#ifndef _PSP2_JPEGARM_H_
#define _PSP2_JPEGARM_H_

#include <psp2/types.h>
#include <psp2/jpeg.h>

#define SCE_JPEG_ARM_OK                         0

/**
 * Error Codes
 */
typedef enum SceJpegArmErrorCode 
{
	SCE_JPEG_ARM_ERROR_IMAGE_EMPTY              = 0x80650103
    SCE_JPEG_ARM_ERROR_BAD_MARKER_LENGTH        = 0x80650104
    SCE_JPEG_ARM_ERROR_BAD_DHT_COUNTS           = 0x80650105
    SCE_JPEG_ARM_ERROR_BAD_DHT_INDEX            = 0x80650106
    SCE_JPEG_ARM_ERROR_BAD_DQT_INDEX            = 0x80650107
    SCE_JPEG_ARM_ERROR_DECODE_ERROR             = 0x80650109
    SCE_JPEG_ARM_ERROR_INVALID_POINTER          = 0x80650110
    SCE_JPEG_ARM_ERROR_BAD_COMPONENT_ID	        = 0x80650111
    SCE_JPEG_ARM_ERROR_UNSUPPORT_COLORSPACE     = 0x80650113
    SCE_JPEG_ARM_ERROR_BAD_MCU_SIZE             = 0x80650114
    SCE_JPEG_ARM_ERROR_BAD_PRECISION            = 0x80650115
    SCE_JPEG_ARM_ERROR_UNSUPPORT_SAMPLING       = 0x80650116
    SCE_JPEG_ARM_ERROR_COMPONENT_COUNT          = 0x80650117
    SCE_JPEG_ARM_ERROR_EOI_EXPECTED	            = 0x80650119
    SCE_JPEG_ARM_ERROR_UNSUPPORT_IMAGE_SIZE     = 0x80650120
    SCE_JPEG_ARM_ERROR_NO_HUFF_TABLE            = 0x80650121
    SCE_JPEG_ARM_ERROR_NO_QUANT_TABLE           = 0x80650122
    SCE_JPEG_ARM_ERROR_NO_SOI                   = 0x80650123
    SCE_JPEG_ARM_ERROR_BAD_DHT_MARKER           = 0x80650125
    SCE_JPEG_ARM_ERROR_BAD_DRI_MARKER           = 0x80650126
    SCE_JPEG_ARM_ERROR_BAD_SOF_MARKER           = 0x80650127
    SCE_JPEG_ARM_ERROR_BAD_SOS_MARKER           = 0x80650128
    SCE_JPEG_ARM_ERROR_SOF_DUPLICATE            = 0x80650129
    SCE_JPEG_ARM_ERROR_NO_LOSSLESS_SUPPORT      = 0x80650131
    SCE_JPEG_ARM_ERROR_NO_ARITH_SUPPORT         = 0x80650132
    SCE_JPEG_ARM_ERROR_UNKNOWN_MARKER           = 0x80650131
    SCE_JPEG_ARM_ERROR_BAD_RESTART_MARKER       = 0x80650136
    SCE_JPEG_ARM_ERROR_UNEXPECTED_MARKER        = 0x80650137
    SCE_JPEG_ARM_ERROR_INVALID_REGION           = 0x80650138
    SCE_JPEG_ARM_ERROR_INVALID_STATE            = 0x80650139
    SCE_JPEG_ARM_ERROR_CANNOT_CONTINUE          = 0x80650140
    SCE_JPEG_ARM_ERROR_MEMORY_SIZE              = 0x80650141
    SCE_JPEG_ARM_ERROR_INVALID_COLOR_FORMAT     = 0x80650150
    SCE_JPEG_ARM_ERROR_INVALID_DECODE_MODE      = 0x80650160
    SCE_JPEG_ARM_ERROR_BAD_PROGRESSIVE_PARAM    = 0x80650161
    SCE_JPEG_ARM_ERROR_INIT_DONE                = 0x80650163
    SCE_JPEG_ARM_ERROR_INPUT_SUSPENDED          = 0x80650164
    SCE_JPEG_ARM_ERROR_INPUT_DATA_TOO_BIG       = 0x80650165
    SCE_JPEG_ARM_ERROR_INVALID_DATA_SIZE        = 0x80650166

    SCE_JPEG_ARM_ERROR_UNSUPPORT_DOWNSCALE      = SCE_JPEG_ARM_ERROR_INVALID_DECODE_MODE
    SCE_JPEG_ARM_ERROR_OUT_OF_MEMORY            = SCE_JPEG_ARM_ERROR_MEMORY_SIZE
};

int sceJpegArmDecodeMJpeg(												// SceJpegArm_A4ABFCE3
		const unsigned char *pJpeg,
		SceSize isize,
		int decodeMode,
		void *pRGBA,
		SceSize osize,
		void *pCoefBuffer,
		SceSize coefBufferSize);

int sceJpegArmDecodeMJpegYCbCr(											// SceJpegArm_E9B1B86F
		const unsigned char *pJpeg,
		SceSize isize,
		int decodeMode,
		unsigned char *pYCbCr,
		SceSize osize,
		void *pCoefBuffer,
		SceSize coefBufferSize);

int sceJpegArmGetOutputInfo(											// 	SceJpegArm_23AE3BEA
		const unsigned char *pJpeg,
		SceSize isize,
		int decodeMode,
		int outputFormat,
		SceJpegOutputInfo *pOutputInfo);


/* split decoder (control struct is different from sceJpeg, no reference anywhere in the apps) *//*
int sceJpegArmCreateSplitDecoder(void *pCtrl);                          // SceJpegArm_9DA48DB6
int sceJpegArmDeleteSplitDecoder(void *pCtrl);                          // SceJpegArm_E9CB3DFD
int sceJpegArmSplitDecodeMJpeg(void *pCtrl);                            // SceJpegArm_5D83C606*/

#endif /* _PSP2_JPEGARM_H_
