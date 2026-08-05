// =============================================================================
// FUN_00638a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00638a60
// Address:   0x00638a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00638a60 @ 0x00638a60
// Stable ID: aa_00638a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00638a60, NetObject_SetMaskBits.
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

void __thiscall FUN_00638a60(int param_1,uint8_t param_2)



{

  int iVar1;

  void *this;

  

  iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x1d8))();

  if (*(char *)(*(int *)(*(int *)(param_1 + 0x18) + 0xa4) + 0x7e) != '\0') {

    iVar1 = *(int *)(iVar1 + 0x250);

    this = *(void **)(*(int *)(param_1 + 0x18) + 0x14);

    if (iVar1 != 0) {

      this = *(void **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x18 + iVar1);

    }

    if (this != (void *)0x0) {

      NetObject_SetMaskBits(this,0x80000000,0);

    }

  }

  iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x1d8))();

  *(uint8_t *)(iVar1 + 0x26c) = param_2;

  return;

}
