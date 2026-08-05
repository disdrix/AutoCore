// =============================================================================
// Named_CalleeOf_Client_EncryptAndPrepareAuthRequest_0067ba30
// -----------------------------------------------------------------------------
// Stable ID: aa_0067ba30
// Preferred role name: netSocket_GetPeerAddress (inferred)
// Note: Auto parent-seed alias is incomplete — primary use is Auth TCP peer
//       address capture via getpeername, not EncryptAndPrepareAuthRequest body.
// Address:   0x0067ba30  (autoassault.exe, image base 0x400000)
// System:    network-nazgul-netSocket
// Generated: 2026-07-29 OWN-ONLY dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// See FUN_0067ba30.cpp for full plate / ABI / twin notes.
// Faithful CF twin of FUN_0067ba30 (named alias continuity).

typedef unsigned int SOCKET;
struct sockaddr;

extern void* ExceptionList;
extern unsigned char LAB_009a962c;
void FUN_0067b070(void);
void FUN_0067b0e0(sockaddr* src_as_decomp_arg);
void FUN_0067b110(void);
extern "C" int __stdcall getpeername(SOCKET s, sockaddr* name, int* namelen);

unsigned int /* Address* width from decompiler */ __thiscall
Named_CalleeOf_Client_EncryptAndPrepareAuthRequest_0067ba30(SOCKET* param_1, unsigned int param_2)
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
