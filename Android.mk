LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := anf.c modules.c
LOCAL_SHARED_LIBRARIES := libc
LOCAL_CFLAGS := -I. -Wall -std=c99 -DANF_INTERACTIVE=1
LOCAL_MODULE = anf
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
