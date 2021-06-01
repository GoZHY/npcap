/***********************IMPORTANT NPCAP LICENSE TERMS***********************
 *                                                                         *
 * Npcap is a Windows packet sniffing driver and library and is copyright  *
 * (c) 2013-2020 by Insecure.Com LLC ("The Nmap Project").  All rights     *
 * reserved.                                                               *
 *                                                                         *
 * Even though Npcap source code is publicly available for review, it is   *
 * not open source software and may not be redistributed or incorporated   *
 * into other software without special permission from the Nmap Project.   *
 * We fund the Npcap project by selling a commercial license which allows  *
 * companies to redistribute Npcap with their products and also provides   *
 * for support, warranty, and indemnification rights.  For details on      *
 * obtaining such a license, please contact:                               *
 *                                                                         *
 * sales@nmap.com                                                          *
 *                                                                         *
 * Free and open source software producers are also welcome to contact us  *
 * for redistribution requests.  However, we normally recommend that such  *
 * authors instead ask your users to download and install Npcap            *
 * themselves.                                                             *
 *                                                                         *
 * Since the Npcap source code is available for download and review,       *
 * users sometimes contribute code patches to fix bugs or add new          *
 * features.  By sending these changes to the Nmap Project (including      *
 * through direct email or our mailing lists or submitting pull requests   *
 * through our source code repository), it is understood unless you        *
 * specify otherwise that you are offering the Nmap Project the            *
 * unlimited, non-exclusive right to reuse, modify, and relicence your     *
 * code contribution so that we may (but are not obligated to)             *
 * incorporate it into Npcap.  If you wish to specify special license      *
 * conditions or restrictions on your contributions, just say so when you  *
 * send them.                                                              *
 *                                                                         *
 * This software is distributed in the hope that it will be useful, but    *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                    *
 *                                                                         *
 * Other copyright notices and attribution may appear below this license   *
 * header. We have kept those for attribution purposes, but any license    *
 * terms granted by those notices apply only to their original work, and   *
 * not to any changes made by the Nmap Project or to this entire file.     *
 *                                                                         *
 * This header summarizes a few important aspects of the Npcap license,    *
 * but is not a substitute for the full Npcap license agreement, which is  *
 * in the LICENSE file included with Npcap and also available at           *
 * https://github.com/nmap/npcap/blob/master/LICENSE.                      *
 *                                                                         *
 ***************************************************************************/
#ifndef __NPCAP_MEMORY_TAGS_H
#define __NPCAP_MEMORY_TAGS_H


// Npcap doesn't need executable allocations
#if(NTDDI_VERSION >= NTDDI_WIN8)
#define NPF_NONPAGED NonPagedPoolNx
#else
#define NPF_NONPAGED NonPagedPool
#endif

// UNICODE_STRING::Buffer
#define NPF_UNICODE_BUFFER_TAG 'BUpN'
// Things that are freed within the same function they are allocated in.
// This should probably be used for PagedPool only.
#define NPF_SHORT_TERM_TAG 'TSpN'
// BPF filter
#define NPF_BPF_TAG 'FPpN'
// User-submitted OID requests
#define NPF_USER_OID_TAG 'UopN'
// Internally-generated OID requests
#define NPF_INTERNAL_OID_TAG 'IopN'
// Cloned OID requests
#define NPF_CLONE_OID_TAG 'CopN'
// DEVICE_EXTENSION::InternalRequestPool
#define NPF_REQ_POOL_TAG 'PRpN'
// OPEN_INSTANCE
#define NPF_OPEN_TAG 'POpN'
// NPCAP_FILTER_MODULE
#define NPF_FILTMOD_TAG 'MFpN'
// DEVICE_EXTENSION::BufferPool
#define NPF_PACKET_DATA_TAG 'DPpN'
// DEVICE_EXTENSION::NBLCopyPool
#define NPF_NBLC_POOL_TAG 'LNpN'
// DEVICE_EXTENSION::NBCopiesPool
#define NPF_NBC_POOL_TAG 'BNpN'
// DEVICE_EXTENSION::SrcNBPool
#define NPF_SRCNB_POOL_TAG 'NSpN'
// DEVICE_EXTENSION::Dot11HeaderPool
#define NPF_DOT11_POOL_TAG '11pN'
// DEVICE_EXTENSION::CapturePool
#define NPF_CAP_POOL_TAG 'DCpN'
// NPF_BufferedWrite packet data
#define NPF_BUFFERED_WRITE_TAG 'WBpN'
// Loopback capture packet copy
#define NPF_LOOPBACK_COPY_TAG 'LBpN'
// NPCAP_FILTER_MODULE::PacketPool
#define NPF_PACKET_POOL_TAG 'PPpN'
// Kernel dump mode
#ifdef NPCAP_KDUMP
#define NPF_DUMP_TAG 'DcpN'
#endif

#endif
