// =============================================================================
// FUN_007299e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007299e0
// Address:   0x007299e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007299e0 @ 0x007299e0
// Stable ID: aa_007299e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007293f0, FUN_007299e0.
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

uint32_t /* width from decompiler */ FUN_007299e0(void)



{

  void *pvVar1;

  int iVar2;

  int unaff_ESI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0706;

  local_c = ExceptionList;

  if (*(int *)(unaff_ESI + 4) == 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x50);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007293f0(pvVar1);

    }

    *(int *)(unaff_ESI + 4) = iVar2;

    if (iVar2 != 0) {

      *(int *)(iVar2 + 0x18) = unaff_ESI;

      ExceptionList = local_c;

      return 0;

    }

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
