// =============================================================================
// FUN_007ac5d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ac5d0
// Address:   0x007ac5d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ac5d0 @ 0x007ac5d0
// Stable ID: aa_007ac5d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×1.
//  - Notable callees: block×30, SysFreeString×2, FUN_007ac5d0.
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

/* WARNING: Removing unreachable block (ram,0x007ac687) */

/* WARNING: Removing unreachable block (ram,0x007ac695) */

/* WARNING: Removing unreachable block (ram,0x007ac6b1) */

/* WARNING: Removing unreachable block (ram,0x007ac6d9) */

/* WARNING: Removing unreachable block (ram,0x007ac751) */

/* WARNING: Removing unreachable block (ram,0x007ac7cd) */

/* WARNING: Removing unreachable block (ram,0x007ac846) */

/* WARNING: Removing unreachable block (ram,0x007ac859) */

/* WARNING: Removing unreachable block (ram,0x007ac88d) */

/* WARNING: Removing unreachable block (ram,0x007ac89d) */

/* WARNING: Removing unreachable block (ram,0x007ac8ab) */

/* WARNING: Removing unreachable block (ram,0x007ac8a5) */

/* WARNING: Removing unreachable block (ram,0x007ac7e0) */

/* WARNING: Removing unreachable block (ram,0x007ac814) */

/* WARNING: Removing unreachable block (ram,0x007ac824) */

/* WARNING: Removing unreachable block (ram,0x007ac835) */

/* WARNING: Removing unreachable block (ram,0x007ac82c) */

/* WARNING: Removing unreachable block (ram,0x007ac764) */

/* WARNING: Removing unreachable block (ram,0x007ac798) */

/* WARNING: Removing unreachable block (ram,0x007ac7a8) */

/* WARNING: Removing unreachable block (ram,0x007ac7b9) */

/* WARNING: Removing unreachable block (ram,0x007ac7b0) */

/* WARNING: Removing unreachable block (ram,0x007ac6e8) */

/* WARNING: Removing unreachable block (ram,0x007ac71c) */

/* WARNING: Removing unreachable block (ram,0x007ac72c) */

/* WARNING: Removing unreachable block (ram,0x007ac73d) */

/* WARNING: Removing unreachable block (ram,0x007ac734) */

/* WARNING: Removing unreachable block (ram,0x007ac8ba) */

/* WARNING: Removing unreachable block (ram,0x007ac8c4) */

/* WARNING: Removing unreachable block (ram,0x007ac8d9) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_007ac5d0(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  BSTR unaff_retaddr;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uStack_3c;

  int *piStack_24;

  int *piStack_1c;

  void *local_14;

  int *piStack_10;

  BSTR pOStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac3e9;

  pOStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pOStack_c;

  (**(code **)(*param_2 + 0x30))();

  if (piStack_1c == (int *)0x0) {

    uStack_3c = 0x7ac62b;

    SysFreeString(unaff_retaddr);

    ExceptionList = local_14;

    return;

  }

  (**(code **)(*piStack_1c + 0x20))();

  (**(code **)(*piStack_24 + 8))(piStack_24);

  if (puStack_8 == (uint8_t *)0x0) {

    uVar1 = 0;

  }

  else if (puStack_8 == (uint8_t *)0x1) {

    uVar1 = 1;

  }

  else {

    if (puStack_8 != (uint8_t *)0x2) goto LAB_007ac91b;

    uVar1 = 2;

  }

  (**(code **)(*piStack_10 + 0x15c))(uVar1,&uStack_3c);

LAB_007ac91b:

  SysFreeString(pOStack_c);

  ExceptionList = (void *)0x0;

  return;

}
