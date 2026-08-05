// =============================================================================
// Net_SockaddrIn_InitZero
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b070
// Address:   0x0067b070  (autoassault.exe, image base 0x400000)
// System:    network / sockaddr fill
// Generated: 2026-07-29 W25-O dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Zero-initialize a 16-byte IPv4 sockaddr_in-shaped buffer in place:
//     family = 0
//     port   = htons(0)
//     addr   = 0
//     +8..+F = 0
//   Returns the buffer pointer.
//
// ABI: __fastcall / thiscall — ECX = out buffer; plain ret; EAX = this.
//
// SIBLINGS:
//   Net_SockaddrIn_Init        0x0067b0a0  (AF_INET + addr + htons(port); ret 8)
//   Net_SockaddrIn_InitInvalid 0x0046e280  (Init(-1,-1) wrapper)
//
// CALLERS: 12 symbols (ctor fields, getsockname/getpeername prep, login net).
// SEALED: 37-byte body; htons IAT 0x009c6830; no htonl.
// =============================================================================

#include <cstdint>

// Winsock htons (IAT @ 0x009c6830 in autoassault.exe)
extern "C" uint16_t __stdcall htons(uint16_t hostshort);

// 16-byte buffer treated as sockaddr_in-like (product type name Open).
// Shared layout with Net_SockaddrIn_Init.
struct SockaddrIn16 {
  uint16_t family;   // +0
  uint16_t port;     // +2  network order after init
  uint32_t addr;     // +4
  uint32_t pad0;     // +8
  uint32_t pad1;     // +C
};

// MSVC thiscall/fastcall: ECX = out buffer.
SockaddrIn16* __fastcall Net_SockaddrIn_InitZero(SockaddrIn16* sa)
{
  // Zero 16 bytes as four dwords (xor eax,eax + four mov [ecx+*], eax)
  *reinterpret_cast<uint32_t*>(sa) = 0;
  reinterpret_cast<uint32_t*>(sa)[1] = 0;
  reinterpret_cast<uint32_t*>(sa)[2] = 0;
  reinterpret_cast<uint32_t*>(sa)[3] = 0;

  sa->family = 0;            // AF_UNSPEC — not AF_INET
  sa->addr = 0;
  sa->port = htons(0);

  return sa;
}
