// =============================================================================
// Net_SockaddrIn_Init
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b0a0
// Address:   0x0067b0a0  (autoassault.exe, image base 0x400000)
// System:    network / sockaddr fill
// Generated: 2026-07-29 W17-C dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Initialize a 16-byte IPv4 sockaddr_in-shaped buffer in place:
//     family = AF_INET (2)
//     port   = htons(hostPort)
//     addr   = ipv4Addr dword as-is (no htonl)
//     +8..+F zero
//   Returns the buffer pointer.
//
// ABI: thiscall — ECX = out buffer; stack (addr, port); ret 8.
//
// CALLERS (2 direct):
//   Net_SockaddrIn_InitInvalid 0x0046e280  (addr=port=-1)
//   FUN_00681950               0x00681950  (addr=0, port=arg)
//
// SEALED: 49-byte body through ret 8; layout; htons IAT; no htonl on addr.
// =============================================================================

#include <cstdint>

// Winsock htons (IAT @ 0x009c6830 in autoassault.exe)
extern "C" uint16_t __stdcall htons(uint16_t hostshort);

// 16-byte buffer treated as sockaddr_in-like (product type name Open).
struct SockaddrIn16 {
  uint16_t family;   // +0
  uint16_t port;     // +2  network order after init
  uint32_t addr;     // +4  raw dword (no htonl in this unit)
  uint32_t pad0;     // +8
  uint32_t pad1;     // +C
};

// MSVC thiscall: ECX = this/out, callee cleans stack args via ret 8.
SockaddrIn16* __thiscall Net_SockaddrIn_Init(SockaddrIn16* sa,
                                             uint32_t ipv4Addr,
                                             uint16_t hostPort)
{
  // Zero 16 bytes as four dwords (matches four mov [ecx+*], eax after xor eax,eax)
  *reinterpret_cast<uint32_t*>(sa) = 0;
  reinterpret_cast<uint32_t*>(sa)[1] = 0;
  reinterpret_cast<uint32_t*>(sa)[2] = 0;
  reinterpret_cast<uint32_t*>(sa)[3] = 0;

  sa->family = 2;            // AF_INET
  sa->addr = ipv4Addr;       // no htonl
  sa->port = htons(hostPort);

  return sa;
}
