// =============================================================================
// FUN_007a3d20
// -----------------------------------------------------------------------------
// Stable ID: aa_007a3d20
// Address:   0x007a3d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a3d20 @ 0x007a3d20
// Stable ID: aa_007a3d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_00753860×3, FUN_0073fe60, FUN_00740b10, FUN_007424e0, FUN_00753bc0, FUN_00753e60, FUN_007a3d20.
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

void FUN_007a3d20(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b40e0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (((char)param_1 != '\0') && (ExceptionList = &local_c, *(int *)(unaff_ESI + 0x128) == 0)) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x118);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_00753e60(pvVar1);

    }

    local_4 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x128) = uVar2;

    FUN_00753bc0(1);

    pvVar1 = operator_new(0x90);

    local_4 = 1;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_007424e0(pvVar1);

    }

    local_4 = 0xffffffff;

    FUN_00753860(uVar2);

    pvVar1 = operator_new(0x10);

    local_4 = 2;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_00740b10(pvVar1);

    }

    local_4 = 0xffffffff;

    FUN_00753860(uVar2);

    pvVar1 = operator_new(0x68);

    local_4 = 3;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_0073fe60(pvVar1);

    }

    local_4 = 0xffffffff;

    FUN_00753860(uVar2);

  }

  if (*(int **)(unaff_ESI + 0x128) != (int *)0x0) {

    (**(code **)(**(int **)(unaff_ESI + 0x128) + 4))(param_1);

  }

  ExceptionList = local_c;

  return;

}
