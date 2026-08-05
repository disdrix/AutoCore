// =============================================================================
// FUN_005ea260
// -----------------------------------------------------------------------------
// Stable ID: aa_005ea260
// Address:   0x005ea260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ea260 @ 0x005ea260
// Stable ID: aa_005ea260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_005743e0, FUN_005ea260.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall

FUN_005ea260(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,char *param_4,

            uint32_t /* width from decompiler */ param_5)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a77c0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[7] = param_2;

  local_4 = 0;

  param_1[6] = param_3;

  iVar2 = 0x20 - (int)param_4;

  do {

    cVar1 = *param_4;

    param_4[(int)param_1 + iVar2] = cVar1;

    uVar3 = DAT_00aaa884;

    param_4 = param_4 + 1;

  } while (cVar1 != '\0');

  param_1[5] = param_5;

  *param_1 = uVar3;

  param_1[1] = 0;

  param_1[2] = uVar3;

  param_1[3] = 0;

  FUN_005743e0(0,0,0);

  ExceptionList = local_c;

  return param_1;

}
