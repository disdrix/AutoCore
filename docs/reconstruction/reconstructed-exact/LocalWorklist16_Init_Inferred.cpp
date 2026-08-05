// =============================================================================
// LocalWorklist16_Init_Inferred  (Ghidra: FUN_0055f520)
// -----------------------------------------------------------------------------
// Stable ID: aa_0055f520
// Address:   0x0055f520 – 0x0055f588  (autoassault.exe, image base 0x400000)
// Size:      105 bytes (0x69); epilogue ret 4
// System:    allocator / local worklist init (element stride 0x10)
// Dual:      W28-R 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving; size uses machine align16 of count*0x10.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Initialize a stack/local worklist descriptor for element stride 0x10 against
//   DAT_00b05060: allocate or bump a slab of align16(count*16) bytes, stamp
//   desc fields, and set high bit on desc[+8] so release skips tagged free.
//   Paired with LocalWorklist16_Release_Inferred; used by Phys_CommitPairListStorage.
//
// ABI (machine):
//   thiscall; ECX = desc; stack = count; ret 4; returns desc (EAX)
// =============================================================================

#include <cstdint>

extern int *DAT_00b05060;

// Ghidra name: FUN_0055f520
int *__thiscall LocalWorklist16_Init_Inferred(int *param_1 /*ECX*/, unsigned param_2)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;

  // Machine: SHL 4; ADD 0xF; AND AL,0xF0  (align16 of count*16)
  iVar3 = static_cast<int>((param_2 * 0x10u + 0xfu) & 0xfffffff0u);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = static_cast<int>(0x80000000u);
  piVar2 = DAT_00b05060;
  piVar1 = DAT_00b05060 + 3;
  if (*piVar1 < iVar3) {
    iVar4 = (**(int (***)(int))(*DAT_00b05060 + 0x24))(iVar3);
  } else {
    iVar4 = DAT_00b05060[2];
    DAT_00b05060[2] = iVar4 + iVar3;
    piVar2[3] = *piVar1 - iVar3;
  }
  *param_1 = iVar4;
  param_1[3] = iVar4;
  param_1[4] = static_cast<int>(param_2);
  param_1[2] = static_cast<int>(param_2 | 0x80000000u);
  return param_1;
}

// Scaffold twin entry (Ghidra name)
extern "C" int *__thiscall FUN_0055f520(int *param_1, unsigned param_2)
{
  return LocalWorklist16_Init_Inferred(param_1, param_2);
}
