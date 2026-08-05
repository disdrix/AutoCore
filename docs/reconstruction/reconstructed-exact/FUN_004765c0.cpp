// =============================================================================
// FUN_004765c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004765c0
// Address:   0x004765c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004765c0 @ 0x004765c0
// Stable ID: aa_004765c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_004765c0, FUN_00476cc0, FUN_00476d60, malloc.
//  - Return sites: 3.

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

void * FUN_004765c0(int param_1,uint param_2,uint param_3)



{

  uint uVar1;

  void *pvVar2;

  

  uVar1 = *(uint *)(param_1 + 0x6c);

  if ((uint)(0xffffffff / (ulonglong)param_3) < param_2) {

    FUN_00476d60();

    return (void *)0x0;

  }

  *(uint *)(param_1 + 0x6c) = uVar1 | 0x100000;

  if (param_2 * param_3 == 0) {

    pvVar2 = (void *)0x0;

  }

  else {

    if (*(code **)(param_1 + 0x248) == (code *)0x0) {

      pvVar2 = malloc(param_2 * param_3);

    }

    else {

      pvVar2 = (void *)(**(code **)(param_1 + 0x248))(param_1);

    }

    if ((pvVar2 == (void *)0x0) && ((*(byte *)(param_1 + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0(param_1);

    }

  }

  *(uint *)(param_1 + 0x6c) = uVar1;

  return pvVar2;

}
