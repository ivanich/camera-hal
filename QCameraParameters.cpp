/*
**
** Copyright 2008, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#define ALOG_TAG "QCameraParams"
#include <utils/Log.h>
#include <string.h>
#include <stdlib.h>
#include <camera/CameraParameters.h>

namespace android {
// Parameter keys to communicate between camera application and driver.
const char CameraParameters::KEY_SUPPORTED_HFR_SIZES[] = "hfr-size-values";
const char CameraParameters::KEY_PREVIEW_FRAME_RATE_MODE[] = "preview-frame-rate-mode";
const char CameraParameters::KEY_SUPPORTED_PREVIEW_FRAME_RATE_MODES[] = "preview-frame-rate-modes";
const char CameraParameters::KEY_PREVIEW_FRAME_RATE_AUTO_MODE[] = "frame-rate-auto";
const char CameraParameters::KEY_PREVIEW_FRAME_RATE_FIXED_MODE[] = "frame-rate-fixed";
const char CameraParameters::KEY_TOUCH_AF_AEC[] = "touch-af-aec";
const char CameraParameters::KEY_SUPPORTED_TOUCH_AF_AEC[] = "touch-af-aec-values";
const char CameraParameters::KEY_TOUCH_INDEX_AEC[] = "touch-index-aec";
const char CameraParameters::KEY_TOUCH_INDEX_AF[] = "touch-index-af";
const char CameraParameters::KEY_SCENE_DETECT[] = "scene-detect";
const char CameraParameters::KEY_SUPPORTED_SCENE_DETECT[] = "scene-detect-values";
const char CameraParameters::KEY_ISO_MODE[] = "iso";
const char CameraParameters::KEY_SUPPORTED_ISO_MODES[] = "iso-values";
const char CameraParameters::KEY_LENSSHADE[] = "lensshade";
const char CameraParameters::KEY_SUPPORTED_LENSSHADE_MODES[] = "lensshade-values";
const char CameraParameters::KEY_AUTO_EXPOSURE[] = "auto-exposure";
const char CameraParameters::KEY_SUPPORTED_AUTO_EXPOSURE[] = "auto-exposure-values";
const char CameraParameters::KEY_DENOISE[] = "denoise";
const char CameraParameters::KEY_SUPPORTED_DENOISE[] = "denoise-values";
const char CameraParameters::KEY_SELECTABLE_ZONE_AF[] = "selectable-zone-af";
const char CameraParameters::KEY_SUPPORTED_SELECTABLE_ZONE_AF[] = "selectable-zone-af-values";
const char CameraParameters::KEY_FACE_DETECTION[] = "face-detection";
const char CameraParameters::KEY_SUPPORTED_FACE_DETECTION[] = "face-detection-values";
const char CameraParameters::KEY_MEMORY_COLOR_ENHANCEMENT[] = "mce";
const char CameraParameters::KEY_SUPPORTED_MEM_COLOR_ENHANCE_MODES[] = "mce-values";
const char CameraParameters::KEY_VIDEO_HIGH_FRAME_RATE[] = "video-hfr";
const char CameraParameters::KEY_SUPPORTED_VIDEO_HIGH_FRAME_RATE_MODES[] = "video-hfr-values";
const char CameraParameters::KEY_REDEYE_REDUCTION[] = "redeye-reduction";
const char CameraParameters::KEY_SUPPORTED_REDEYE_REDUCTION[] = "redeye-reduction-values";
const char CameraParameters::KEY_HIGH_DYNAMIC_RANGE_IMAGING[] = "hdr";
const char CameraParameters::KEY_SUPPORTED_HDR_IMAGING_MODES[] = "hdr-values";
const char CameraParameters::KEY_POWER_MODE_SUPPORTED[] = "power-mode-supported";
const char CameraParameters::KEY_ZSL[] = "zsl";
const char CameraParameters::KEY_SUPPORTED_ZSL_MODES[] = "zsl-values";
const char CameraParameters::KEY_CAMERA_MODE[] = "camera-mode";
const char CameraParameters::KEY_AE_BRACKET_HDR[] = "ae-bracket-hdr";
const char CameraParameters::KEY_POWER_MODE[] = "power-mode";
/*only effective when KEY_AE_BRACKET_HDR set to ae_bracketing*/
//const char CameraParameters::KEY_AE_BRACKET_SETTING_KEY[] = "ae-bracket-setting";

// Values for effect settings.
const char CameraParameters::EFFECT_EMBOSS[] = "emboss";
const char CameraParameters::EFFECT_SKETCH[] = "sketch";
const char CameraParameters::EFFECT_NEON[] = "neon";

// Values for auto exposure settings.
const char CameraParameters::TOUCH_AF_AEC_OFF[] = "touch-off";
const char CameraParameters::TOUCH_AF_AEC_ON[] = "touch-on";

// Values for scene mode settings.
const char CameraParameters::SCENE_MODE_ASD[] = "asd";   // corresponds to CAMERA_BESTSHOT_AUTO in HAL
const char CameraParameters::SCENE_MODE_BACKLIGHT[] = "backlight";
const char CameraParameters::SCENE_MODE_FLOWERS[] = "flowers";
const char CameraParameters::SCENE_MODE_AR[] = "AR";

// Values for auto scene detection settings.
const char CameraParameters::SCENE_DETECT_OFF[] = "off";
const char CameraParameters::SCENE_DETECT_ON[] = "on";

// Formats for setPreviewFormat and setPictureFormat.
const char CameraParameters::PIXEL_FORMAT_YUV420SP_ADRENO[] = "yuv420sp-adreno";
const char CameraParameters::PIXEL_FORMAT_RAW[] = "raw";
const char CameraParameters::PIXEL_FORMAT_YV12[] = "yuv420p";
const char CameraParameters::PIXEL_FORMAT_NV12[] = "nv12";

// Values for focus mode settings.
const char CameraParameters::FOCUS_MODE_NORMAL[] = "normal";
const char CameraParameters::KEY_SKIN_TONE_ENHANCEMENT[] = "skinToneEnhancement";
const char CameraParameters::KEY_SUPPORTED_SKIN_TONE_ENHANCEMENT_MODES[] = "skinToneEnhancement-values";

// Values for ISO Settings
const char CameraParameters::ISO_AUTO[] = "auto";
const char CameraParameters::ISO_HJR[] = "ISO_HJR";
const char CameraParameters::ISO_100[] = "ISO100";
const char CameraParameters::ISO_200[] = "ISO200";
const char CameraParameters::ISO_400[] = "ISO400";
const char CameraParameters::ISO_800[] = "ISO800";
const char CameraParameters::ISO_1600[] = "ISO1600";

 //Values for Lens Shading
const char CameraParameters::LENSSHADE_ENABLE[] = "enable";
const char CameraParameters::LENSSHADE_DISABLE[] = "disable";

// Values for auto exposure settings.
const char CameraParameters::AUTO_EXPOSURE_FRAME_AVG[] = "frame-average";
const char CameraParameters::AUTO_EXPOSURE_CENTER_WEIGHTED[] = "center-weighted";
const char CameraParameters::AUTO_EXPOSURE_SPOT_METERING[] = "spot-metering";

const char CameraParameters::KEY_GPS_LATITUDE_REF[] = "gps-latitude-ref";
const char CameraParameters::KEY_GPS_LONGITUDE_REF[] = "gps-longitude-ref";
const char CameraParameters::KEY_GPS_ALTITUDE_REF[] = "gps-altitude-ref";
const char CameraParameters::KEY_GPS_STATUS[] = "gps-status";
const char CameraParameters::KEY_EXIF_DATETIME[] = "exif-datetime";

const char CameraParameters::KEY_HISTOGRAM[] = "histogram";
const char CameraParameters::KEY_SUPPORTED_HISTOGRAM_MODES[] = "histogram-values";

//Values for Histogram Shading
const char CameraParameters::HISTOGRAM_ENABLE[] = "enable";
const char CameraParameters::HISTOGRAM_DISABLE[] = "disable";

//Values for Skin Tone Enhancement Modes
const char CameraParameters::SKIN_TONE_ENHANCEMENT_ENABLE[] = "enable";
const char CameraParameters::SKIN_TONE_ENHANCEMENT_DISABLE[] = "disable";

const char CameraParameters::KEY_SHARPNESS[] = "sharpness";
const char CameraParameters::KEY_MAX_SHARPNESS[] = "max-sharpness";
const char CameraParameters::KEY_CONTRAST[] = "contrast";
const char CameraParameters::KEY_MAX_CONTRAST[] = "max-contrast";
const char CameraParameters::KEY_SATURATION[] = "saturation";
const char CameraParameters::KEY_MAX_SATURATION[] = "max-saturation";

const char CameraParameters::KEY_SINGLE_ISP_OUTPUT_ENABLED[] = "single-isp-output-enabled";

//Values for DENOISE
const char CameraParameters::DENOISE_OFF[] = "denoise-off";
const char CameraParameters::DENOISE_ON[] = "denoise-on";

// Values for selectable zone af Settings
const char CameraParameters::SELECTABLE_ZONE_AF_AUTO[] = "auto";
const char CameraParameters::SELECTABLE_ZONE_AF_SPOT_METERING[] = "spot-metering";
const char CameraParameters::SELECTABLE_ZONE_AF_CENTER_WEIGHTED[] = "center-weighted";
const char CameraParameters::SELECTABLE_ZONE_AF_FRAME_AVERAGE[] = "frame-average";

// Values for Face Detection settings.
const char CameraParameters::FACE_DETECTION_OFF[] = "off";
const char CameraParameters::FACE_DETECTION_ON[] = "on";

// Values for MCE settings.
const char CameraParameters::MCE_ENABLE[] = "enable";
const char CameraParameters::MCE_DISABLE[] = "disable";

// Values for HFR settings.
const char CameraParameters::VIDEO_HFR_OFF[] = "off";
const char CameraParameters::VIDEO_HFR_2X[] = "60";
const char CameraParameters::VIDEO_HFR_3X[] = "90";
const char CameraParameters::VIDEO_HFR_4X[] = "120";

// Values for Redeye Reduction settings.
const char CameraParameters::REDEYE_REDUCTION_ENABLE[] = "enable";
const char CameraParameters::REDEYE_REDUCTION_DISABLE[] = "disable";

// Values for HDR settings.
const char CameraParameters::HDR_ENABLE[] = "enable";
const char CameraParameters::HDR_DISABLE[] = "disable";

// Values for ZSL settings.
const char CameraParameters::ZSL_OFF[] = "off";
const char CameraParameters::ZSL_ON[] = "on";

// Values for HDR Bracketing settings.
const char CameraParameters::AE_BRACKET_HDR_OFF[] = "Off";
const char CameraParameters::AE_BRACKET_HDR[] = "HDR";
const char CameraParameters::AE_BRACKET[] = "AE-Bracket";

const char CameraParameters::LOW_POWER[] = "Low_Power";
const char CameraParameters::NORMAL_POWER[] = "Normal_Power";

static const char* portrait = "portrait";
static const char* landscape = "landscape";

//CameraParameters::CameraParameters()
//                : mMap()
//{
//}

CameraParameters::~CameraParameters()
{
}

int CameraParameters::getOrientation() const
{
    const char* orientation = get("orientation");
    if (orientation && !strcmp(orientation, portrait))
        return CAMERA_ORIENTATION_PORTRAIT;
    return CAMERA_ORIENTATION_LANDSCAPE;
}
void CameraParameters::setOrientation(int orientation)
{
    if (orientation == CAMERA_ORIENTATION_PORTRAIT) {
        set("orientation", portrait);
    } else {
         set("orientation", landscape);
    }
}

        //XXX ALOGE("Key \"%s\"contains invalid character (= or ;)", key);
        //XXX ALOGE("Value \"%s\"contains invalid character (= or ;)", value);
    //snprintf(str, sizeof(str), "%d", value);
        //ALOGE("Cannot find delimeter (%c) in str=%s", delim, str);
		
		
// Parse string like "(1, 2, 3, 4, ..., N)"
// num is pointer to an allocated array of size N
static int parseNDimVector(const char *str, int *num, int N, char delim = ',')
{
    char *start, *end;
    if(num == NULL) {
        ALOGE("Invalid output array (num == NULL)");
        return -1;
    }
    //check if string starts and ends with parantheses
    if(str[0] != '(' || str[strlen(str)-1] != ')') {
        ALOGE("Invalid format of string %s, valid format is (n1, n2, n3, n4 ...)", str);
        return -1;
    }
    start = (char*) str;
    start++;
    for(int i=0; i<N; i++) {
        *(num+i) = (int) strtol(start, &end, 10);
        if(*end != delim && i < N-1) {
            ALOGE("Cannot find delimeter '%c' in string \"%s\". end = %c", delim, str, *end);
            return -1;
        }
        start = end+1;
    }
    return 0;
}


            //ALOGE("Picture sizes string \"%s\" contains invalid character.", sizesStr);
    //snprintf(str, sizeof(str), "%dx%d", width, height);
	
	
	
// Parse string like "640x480" or "10000,20000"
static int parse_pair(const char *str, int *first, int *second, char delim,
                      char **endptr = NULL)
{
    // Find the first integer.
    char *end;
    int w = (int)strtol(str, &end, 10);
    // If a delimeter does not immediately follow, give up.
    if (*end != delim) {
        ALOGE("Cannot find delimeter (%c) in str=%s", delim, str);
        return -1;
    }

    // Find the second integer, immediately after the delimeter.
    int h = (int)strtol(end+1, &end, 10);

    *first = w;
    *second = h;

    if (endptr) {
        *endptr = end;
    }

    return 0;
}

static void parseSizesList(const char *sizesStr, Vector<Size> &sizes)
{
    if (sizesStr == 0) {
        return;
    }

    char *sizeStartPtr = (char *)sizesStr;

    while (true) {
        int width, height;
        int success = parse_pair(sizeStartPtr, &width, &height, 'x',
                                 &sizeStartPtr);
        if (success == -1 || (*sizeStartPtr != ',' && *sizeStartPtr != '\0')) {
            ALOGE("Picture sizes string \"%s\" contains invalid character.", sizesStr);
            return;
        }
        sizes.push(Size(width, height));

        if (*sizeStartPtr == '\0') {
            return;
        }
        sizeStartPtr++;
    }
}


void CameraParameters::getSupportedHfrSizes(Vector<Size> &sizes) const
{
    const char *hfrSizesStr = get(KEY_SUPPORTED_HFR_SIZES);
    parseSizesList(hfrSizesStr, sizes);
}

void CameraParameters::setPreviewFpsRange(int minFPS, int maxFPS)
{
    char str[32];
    snprintf(str, sizeof(str), "%d,%d",minFPS,maxFPS);
    set(KEY_PREVIEW_FPS_RANGE,str);
}

void CameraParameters::setPreviewFrameRateMode(const char *mode)
{
    set(KEY_PREVIEW_FRAME_RATE_MODE, mode);
}

const char *CameraParameters::getPreviewFrameRateMode() const
{
    return get(KEY_PREVIEW_FRAME_RATE_MODE);
}

    //ALOGD("dump: mMap.size = %d", mMap.size());
        //ALOGD("%s: %s\n", k.string(), v.string());
void CameraParameters::setTouchIndexAec(int x, int y)
{
    char str[32];
    snprintf(str, sizeof(str), "%dx%d", x, y);
    set(KEY_TOUCH_INDEX_AEC, str);
}

void CameraParameters::getTouchIndexAec(int *x, int *y) const
{
    *x = -1;
    *y = -1;

    // Get the current string, if it doesn't exist, leave the -1x-1
    const char *p = get(KEY_TOUCH_INDEX_AEC);
    if (p == 0)
        return;

    int tempX, tempY;
    if (parse_pair(p, &tempX, &tempY, 'x') == 0) {
        *x = tempX;
        *y = tempY;
    }
}

void CameraParameters::setTouchIndexAf(int x, int y)
{
    char str[32];
    snprintf(str, sizeof(str), "%dx%d", x, y);
    set(KEY_TOUCH_INDEX_AF, str);
}

void CameraParameters::getTouchIndexAf(int *x, int *y) const
{
    *x = -1;
    *y = -1;

    // Get the current string, if it doesn't exist, leave the -1x-1
    const char *p = get(KEY_TOUCH_INDEX_AF);
    if (p == 0)
        return;

    int tempX, tempY;
    if (parse_pair(p, &tempX, &tempY, 'x') == 0) {
        *x = tempX;
        *y = tempY;
	}
}

void CameraParameters::getMeteringAreaCenter(int *x, int *y) const
{
    //Default invalid values
    *x = -2000;
    *y = -2000;

    const char *p = get(KEY_METERING_AREAS);
    if(p != NULL) {
        int arr[5] = {-2000, -2000, -2000, -2000, 0};
        parseNDimVector(p, arr, 5); //p = "(x1, y1, x2, y2, weight)"
        *x = (arr[0] + arr[2])/2; //center_x = (x1+x2)/2
        *y = (arr[1] + arr[3])/2; //center_y = (y1+y2)/2
    }
}


}; // namespace android

