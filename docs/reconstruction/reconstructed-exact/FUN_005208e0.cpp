// =============================================================================
// FUN_005208e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005208e0
// Address:   0x005208e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005208e0 @ 0x005208e0
// Stable ID: aa_005208e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: NetObject_SetMaskBits×2, FUN_005208e0.
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

void __thiscall FUN_005208e0(int param_1,char param_2)



{

  void *this;

  int iVar1;

  

  if (*(char *)(param_1 + 0x529) != param_2) {

    *(char *)(param_1 + 0x529) = param_2;

    this = *(void **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x18 + param_1);

    if (this != (void *)0x0) {

      NetObject_SetMaskBits(this,0x100,0);

    }

    iVar1 = *(int *)(param_1 + 0x250);

    if ((iVar1 != 0) && (*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x18 + iVar1) != 0)) {

      NetObject_SetMaskBits(*(void **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x18 + iVar1),0x100,0);

    }

  }

  return;

}
