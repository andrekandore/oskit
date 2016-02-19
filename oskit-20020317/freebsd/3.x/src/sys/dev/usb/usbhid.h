/*	$NetBSD: usbhid.h,v 1.3 1998/12/26 12:53:04 augustss Exp $	*/
/*	$FreeBSD: src/sys/dev/usb/usbhid.h,v 1.4.2.1 1999/05/08 23:05:02 n_hibma Exp $	*/

/*
 * Copyright (c) 1998 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Lennart Augustsson (augustss@carlstedt.se) at
 * Carlstedt Research & Technology.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef _USBHID_H_
#define _USBHID_H_

#define UR_GET_HID_DESCRIPTOR	0x06
#define  UDESC_HID		0x21
#define  UDESC_REPORT		0x22
#define  UDESC_PHYSICAL		0x23
#define UR_SET_HID_DESCRIPTOR	0x07
#define UR_GET_REPORT		0x01
#define UR_SET_REPORT		0x09
#define UR_GET_IDLE		0x02
#define UR_SET_IDLE		0x0a
#define UR_GET_PROTOCOL		0x03
#define UR_SET_PROTOCOL		0x0b

typedef struct usb_hid_descriptor {
	uByte		bLength;
	uByte		bDescriptorType;
	uWord		bcdHID;
	uByte		bCountryCode;
	uByte		bNumDescriptors;
	struct {
		uByte		bDescriptorType;
		uWord		wDescriptorLength;
	} descrs[1];
} usb_hid_descriptor_t;
#define USB_HID_DESCRIPTOR_SIZE(n) (9+(n)*3)

/* Usage pages */
#define HUP_GENERIC_DESKTOP	0x0001
#define HUP_SIMULATION		0x0002
#define HUP_LEDS		0x0008
#define HUP_BUTTON		0x0009

/* Usages, generic desktop */
#define HUG_POINTER		0x0001
#define HUG_MOUSE		0x0002
#define HUG_JOYSTICK		0x0004
#define HUG_GAME_PAD		0x0005
#define HUG_KEYBOARD		0x0006
#define HUG_KEYPAD		0x0007
#define HUG_X			0x0030
#define HUG_Y			0x0031
#define HUG_Z			0x0032
#define HUG_RX			0x0033
#define HUG_RY			0x0034
#define HUG_RZ			0x0035
#define HUG_SLIDER		0x0036
#define HUG_DIAL		0x0037
#define HUG_WHEEL		0x0038
#define HUG_HAT_SWITCH		0x0039
#define HUG_COUNTED_BUFFER	0x003a
#define HUG_BYTE_COUNT		0x003b
#define HUG_MOTION_WAKEUP	0x003c
#define HUG_VX			0x0040
#define HUG_VY			0x0041
#define HUG_VZ			0x0042
#define HUG_VBRX		0x0043
#define HUG_VBRY		0x0044
#define HUG_VBRZ		0x0045
#define HUG_VNO			0x0046
#define HUG_SYSTEM_CONTROL	0x0080
#define HUG_SYSTEM_POWER_DOWN	0x0081
#define HUG_SYSTEM_SLEEP	0x0082
#define HUG_SYSTEM_WAKEUP	0x0083
#define HUG_SYSTEM_CONTEXT_MENU	0x0084
#define HUG_SYSTEM_MAIN_MENU	0x0085
#define HUG_SYSTEM_APP_MENU	0x0086
#define HUG_SYSTEM_MENU_HELP	0x0087
#define HUG_SYSTEM_MENU_EXIT	0x0088
#define HUG_SYSTEM_MENU_SELECT	0x0089
#define HUG_SYSTEM_MENU_RIGHT	0x008a
#define HUG_SYSTEM_MENU_LEFT	0x008b
#define HUG_SYSTEM_MENU_UP	0x008c
#define HUG_SYSTEM_MENU_DOWN	0x008d

#define HID_USAGE2(p,u) (((p) << 16) | u)

#define UHID_INPUT_REPORT 0x01
#define UHID_OUTPUT_REPORT 0x02
#define UHID_FEATURE_REPORT 0x03

/* Bits in the input/output/feature items */
#define HIO_CONST	0x001
#define HIO_VARIABLE	0x002
#define HIO_RELATIVE	0x004
#define HIO_WRAP	0x008
#define HIO_NONLINEAR	0x010
#define HIO_NOPREF	0x020
#define HIO_NULLSTATE	0x040
#define HIO_VOLATILE	0x080
#define HIO_BUFBYTES	0x100

#endif /* _USBHID_H_ */