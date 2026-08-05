// =============================================================================
// FUN_0085e730
// -----------------------------------------------------------------------------
// Stable ID: aa_0085e730
// Address:   0x0085e730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085e730 @ 0x0085e730
// Stable ID: aa_0085e730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0085e590, FUN_0085e730.
//  - Return sites: 2.

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

int * __fastcall FUN_0085e730(int param_1)



{

  void *pvVar1;

  int *piVar2;

  void *unaff_ESI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4a16;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x48c) != 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x514);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      piVar2 = (int *)0x0;

    }

    else {

      piVar2 = (int *)FUN_0085e590(pvVar1);

    }

    local_4 = 0xffffffff;

    (**(code **)(*piVar2 + 0x38))(param_1);

    (**(code **)(*piVar2 + 0x15c))(0,&DAT_00afdadc);

    *(uint8_t *)((int)piVar2 + 0xcd) = 1;

    ExceptionList = unaff_ESI;

    return piVar2;

  }

  return (int *)0x0;

}
