// =============================================================================
// FUN_00787810
// -----------------------------------------------------------------------------
// Stable ID: aa_00787810
// Address:   0x00787810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00787810 @ 0x00787810
// Stable ID: aa_00787810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007b6a20×2, FUN_0075e2d0, FUN_00787530, FUN_00787810, FUN_0079ce60, FUN_007b7420, FUN_00989e00.
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

uint8_t FUN_00787810(uint32_t /* width from decompiler */ param_1)



{

  uint8_t uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t auStack_6a8 [4];

  undefined **local_6a4;

  uint8_t local_69f;

  uint8_t local_69e;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1387;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  uVar3 = param_1;

  FUN_007b6a20(param_1);

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_007b7420(uVar3);

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = 0;

  }

  else {

    FUN_0079ce60();

    local_6a4 = &PTR_FUN_009cc008;

    local_69f = 1;

    local_69e = 0;

    local_4 = 0;

    local_10 = puVar2;

    uVar1 = FUN_00787530(&local_6a4);

    (**(code **)*puVar2)(1);

    FUN_007b6a20();

    FUN_00989e00(auStack_6a8,param_1);

    FUN_0075e2d0(auStack_6a8);

  }

  ExceptionList = local_c;

  return uVar1;

}
