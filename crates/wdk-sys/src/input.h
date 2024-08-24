/* Copyright (c) Microsoft Corporation
   License: MIT OR Apache-2.0 */

#if defined(UMDF_VERSION_MAJOR)

#include <windows.h>

#else // !defined(UMDF_VERSION_MAJOR)

#include "ntifs.h"
#include "ntddk.h"

// FIXME: Why is there no definition for this struct? Maybe blocklist this struct in bindgen. 
typedef union _KGDTENTRY64
{
  struct
  {
    unsigned short LimitLow;
    unsigned short BaseLow;
    union
    {
      struct
      {
        unsigned char BaseMiddle;
        unsigned char Flags1;
        unsigned char Flags2;
        unsigned char BaseHigh;
      } Bytes;
      struct
      {
        unsigned long BaseMiddle : 8;
        unsigned long Type : 5;
        unsigned long Dpl : 2;
        unsigned long Present : 1;
        unsigned long LimitHigh : 4;
        unsigned long System : 1;
        unsigned long LongMode : 1;
        unsigned long DefaultBig : 1;
        unsigned long Granularity : 1;
        unsigned long BaseHigh : 8;
      } Bits;
    };
    unsigned long BaseUpper;
    unsigned long MustBeZero;
  };
  unsigned __int64 Alignment;
} KGDTENTRY64, *PKGDTENTRY64;

typedef union _KIDTENTRY64
{
  struct
  {
    unsigned short OffsetLow;
    unsigned short Selector;
    unsigned short IstIndex : 3;
    unsigned short Reserved0 : 5;
    unsigned short Type : 5;
    unsigned short Dpl : 2;
    unsigned short Present : 1;
    unsigned short OffsetMiddle;
    unsigned long OffsetHigh;
    unsigned long Reserved1;
  };
  unsigned __int64 Alignment;
} KIDTENTRY64, *PKIDTENTRY64;
#endif // !defined(UMDF_VERSION_MAJOR)

#if defined(KMDF_VERSION_MAJOR) || defined(UMDF_VERSION_MAJOR)

#include <wdf.h>

#endif // defined(KMDF_VERSION_MAJOR) || defined(UMDF_VERSION_MAJOR)

#include <..\km\hidport.h>
#include <hidclass.h>
#include <winioctl.h>
#include <namedpipeapi.h>

const ULONG FIXED_IOCTL_HID_GET_DEVICE_DESCRIPTOR = IOCTL_HID_GET_DEVICE_DESCRIPTOR;
const ULONG FIXED_IOCTL_HID_GET_DEVICE_ATTRIBUTES = IOCTL_HID_GET_DEVICE_ATTRIBUTES;
const ULONG FIXED_IOCTL_HID_GET_REPORT_DESCRIPTOR = IOCTL_HID_GET_REPORT_DESCRIPTOR;
const ULONG FIXED_IOCTL_HID_READ_REPORT = IOCTL_HID_READ_REPORT;
const ULONG FIXED_IOCTL_HID_WRITE_REPORT = IOCTL_HID_WRITE_REPORT;
const ULONG FIXED_IOCTL_UMDF_HID_GET_FEATURE = IOCTL_UMDF_HID_GET_FEATURE;
const ULONG FIXED_IOCTL_UMDF_HID_SET_FEATURE = IOCTL_UMDF_HID_SET_FEATURE;
const ULONG FIXED_IOCTL_UMDF_HID_GET_INPUT_REPORT = IOCTL_UMDF_HID_GET_INPUT_REPORT;
const ULONG FIXED_IOCTL_UMDF_HID_SET_OUTPUT_REPORT = IOCTL_UMDF_HID_SET_OUTPUT_REPORT;
const ULONG FIXED_IOCTL_HID_GET_STRING = IOCTL_HID_GET_STRING;
const ULONG FIXED_IOCTL_HID_GET_INDEXED_STRING = IOCTL_HID_GET_INDEXED_STRING;
const ULONG FIXED_IOCTL_HID_SEND_IDLE_NOTIFICATION_REQUEST = IOCTL_HID_SEND_IDLE_NOTIFICATION_REQUEST;
const ULONG FIXED_IOCTL_HID_ACTIVATE_DEVICE = IOCTL_HID_ACTIVATE_DEVICE;
const ULONG FIXED_IOCTL_HID_DEACTIVATE_DEVICE = IOCTL_HID_DEACTIVATE_DEVICE;
const ULONG FIXED_IOCTL_GET_PHYSICAL_DESCRIPTOR = IOCTL_GET_PHYSICAL_DESCRIPTOR;