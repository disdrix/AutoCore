// =============================================================================
// stoChunkWriter_WriteFormatted  (FUN_00767160)
// -----------------------------------------------------------------------------
// Stable ID: aa_00767160
// Address:   0x00767160  (autoassault.exe, image base 0x400000)
// System:    storage / arda2.stoChunk (text mode)
// Generated: 2026-07-29 W16-K dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// ABI: EAX = stoChunkWriter* (not ECX); stack = format, varargs; ret = status @ +0x04
// DAT: 0x00a97b84 = "\r\n" (2); 0x00a2a000 = " " (1); wrap threshold 0x78; buf 0x400
// =============================================================================

#include <cstdint>
#include <cstdio>

extern char DAT_00a97b84[]; // "\r\n"
extern char DAT_00a2a000[]; // " "
extern uint32_t FUN_00767070(void);

// Retail register ABI: writer pointer arrives in EAX (decompiler: in_EAX).
uint32_t FUN_00767160(char *param_1 /* format */)
{
  uint32_t *in_EAX; // writer* — set by caller in EAX before call
  int iVar1;
  uint uVar2;
  char local_400[1024];

  iVar1 = _vsnprintf(local_400, 0x400, param_1, &stack0x00000008);

  if ((0 < (int)in_EAX[8]) && (0x78 < in_EAX[8] + 1 + iVar1)) {
    in_EAX[8] = 0;
    uVar2 = (**(code **)(*(int *)*in_EAX + 0x18))(&DAT_00a97b84, 2);
    in_EAX[1] = in_EAX[1] | uVar2;
  }

  if (in_EAX[8] == 0) {
    uVar2 = FUN_00767070();
    in_EAX[1] = in_EAX[1] | uVar2;
  } else {
    uVar2 = (**(code **)(*(int *)*in_EAX + 0x18))(&DAT_00a2a000, 1);
    in_EAX[1] = in_EAX[1] | uVar2;
    in_EAX[8] = in_EAX[8] + 1;
  }

  uVar2 = (**(code **)(*(int *)*in_EAX + 0x18))(local_400, iVar1);
  in_EAX[1] = in_EAX[1] | uVar2;
  in_EAX[8] = in_EAX[8] + iVar1;
  return in_EAX[1];
}
