// =============================================================================
// FUN_00685540
// -----------------------------------------------------------------------------
// Stable ID: aa_00685540
// Address:   0x00685540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00685540 @ 0x00685540
// Stable ID: aa_00685540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_00680c30, FUN_00680c50, FUN_00681020, FUN_00685050, FUN_00685540, thunk_FUN_0076c4d0.
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

/* WARNING: Type propagation algorithm not settling */



void __thiscall FUN_00685540(int param_1,char param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *local_38;

  int local_34 [2];

  byte local_2c;

  uint8_t local_2b;

  uint16_t local_2a;

  uint8_t local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9c4c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00680c30();

  local_4 = 0;

  thunk_FUN_0076c4d0();

  local_2c = param_2 != '\0' | 8;

  local_34[1] = 0;

  local_2b = 0;

  local_2a = 0;

  local_38 = operator_new__(0x3ec);

  puVar3 = local_38;

  for (iVar2 = 0xfb; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  FUN_00681020(&local_38,0x3ec,1);

  cVar1 = FUN_00685050(local_28,local_34 + 1,local_34);

  if ((cVar1 == '\0') && ((local_34[0] == 0 || (local_34[0] == 1)))) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 8;

  }

  local_4 = 0xffffffff;

  FUN_00680c50();

  ExceptionList = local_c;

  return;

}
