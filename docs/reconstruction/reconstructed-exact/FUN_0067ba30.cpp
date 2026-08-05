// =============================================================================
// FUN_0067ba30 — netSocket_GetPeerAddress (inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0067ba30
// Address:   0x0067ba30  (autoassault.exe, image base 0x400000)
// Body:      0x0067ba30 – 0x0067bab8  (ret 4)
// System:    network-nazgul-netSocket
// Generated: 2026-07-29 OWN-ONLY dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Twin:      FUN_0067b9a0 @ 0x0067b9a0 (getsockname form of same shape)
// =============================================================================

// PURPOSE:
//   Fill a 16-byte Address/sockaddr out-buffer with the peer name of the
//   connected OS socket at *param_1 (getpeername). Default-constructs a stack
//   Address, queries peer, dword-copies into out, trivial-dtors the temp.
//
// ABI (sealed from body bytes):
//   __thiscall: ECX = SOCKET* / netSocket* (handle at +0)  → param_1
//   stack arg0: Address* out                               → param_2
//   returns:    param_2 in EAX
//   trailer:    ret 4
//
// Cluster evidence (sibling strings, not this unit):
//   C:\vog\1_code\palantir\platform\library\src\nazgul\net\netSocket.cpp

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; live re-confirmed 2026-07-29.
 * - FUN_0067b070 / FUN_0067b0e0 / FUN_0067b110 remain external residual units.
 * - Runtime / differential verification: OPEN.
 *
 * Readability pass:
 * - Control flow and call order preserved from authoritative raw.
 * - Types: SOCKET* this, Address* out (16B); SEH frame kept as decompiler locals.
 */

typedef unsigned int SOCKET;
struct sockaddr;

// Residual externs (not defined here)
extern void* ExceptionList;
extern unsigned char LAB_009a962c;
void FUN_0067b070(void);
void FUN_0067b0e0(sockaddr* src_as_decomp_arg);
void FUN_0067b110(void);
extern "C" int __stdcall getpeername(SOCKET s, sockaddr* name, int* namelen);

unsigned int /* Address* width from decompiler */ __thiscall
FUN_0067ba30(SOCKET* param_1, unsigned int param_2)
{
  int local_24[2];
  sockaddr local_1c;
  void* local_c;
  unsigned char* puStack_8;
  unsigned int local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a962c;
  local_c = ExceptionList;
  local_24[1] = 0;
  ExceptionList = &local_c;

  FUN_0067b070();
  local_4 = 1;
  local_24[0] = 0x10;
  getpeername(*param_1, &local_1c, local_24);
  FUN_0067b0e0(&local_1c);

  local_24[1] = 1;
  local_4 = local_4 & 0xffffff00;
  FUN_0067b110();

  ExceptionList = local_c;
  return param_2;
}
