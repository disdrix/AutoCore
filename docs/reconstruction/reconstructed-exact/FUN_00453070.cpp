// =============================================================================
// FUN_00453070
// -----------------------------------------------------------------------------
// Stable ID: aa_00453070
// Address:   0x00453070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00453070 @ 0x00453070
// Stable ID: aa_00453070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004523a0, FUN_00453070, FUN_00456130.
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

int __thiscall FUN_00453070(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd3b0;

  local_10 = ExceptionList;

  iVar2 = 0;

  if (*(int *)(param_1 + 4) != 0) {

    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc;

  }

  ExceptionList = &local_10;

  cVar1 = FUN_004523a0(iVar2);

  if (cVar1 != '\0') {

    local_8 = 0;

    uVar3 = FUN_00456130(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

    *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar3;

  }

  ExceptionList = local_10;

  return param_2;

}
