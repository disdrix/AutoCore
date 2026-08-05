// =============================================================================
// FUN_00558f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00558f70
// Address:   0x00558f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00558f70 @ 0x00558f70
// Stable ID: aa_00558f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004e2590, FUN_00558e10, FUN_00558f70.
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

int __thiscall FUN_00558f70(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a47d0;

  local_10 = ExceptionList;

  iVar2 = 0;

  if (*(int *)(param_2 + 4) != 0) {

    iVar2 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x134;

  }

  ExceptionList = &local_10;

  cVar1 = FUN_00558e10(iVar2);

  if (cVar1 != '\0') {

    local_8 = 0;

    uVar3 = FUN_004e2590(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                         *(uint32_t /* width from decompiler */ *)(param_1 + 4),param_1,param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

  }

  ExceptionList = local_10;

  return param_1;

}
