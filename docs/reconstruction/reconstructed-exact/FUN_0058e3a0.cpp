// =============================================================================
// FUN_0058e3a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e3a0
// Address:   0x0058e3a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058e3a0 @ 0x0058e3a0
// Stable ID: aa_0058e3a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0058e3a0.
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

void __fastcall FUN_0058e3a0(int param_1)



{

  int iVar1;

  float *unaff_retaddr;

  

  if (*(int *)(param_1 + 0x914) != 0) {

    iVar1 = (**(code **)(**(int **)(param_1 + 0x914) + 0x10))(3);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc) = 0xffffffff;

    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;

    *(float *)(iVar1 + 0x90) = *(float *)(iVar1 + 0x90) + *unaff_retaddr;

    *(float *)(iVar1 + 0x94) = unaff_retaddr[1] + *(float *)(iVar1 + 0x94);

    *(float *)(iVar1 + 0x98) = *(float *)(iVar1 + 0x98) + unaff_retaddr[2];

    *(float *)(param_1 + 0x818) = *(float *)(param_1 + 0x818) + *unaff_retaddr;

    *(float *)(param_1 + 0x81c) = *(float *)(param_1 + 0x81c) + unaff_retaddr[1];

    *(float *)(param_1 + 0x820) = *(float *)(param_1 + 0x820) + unaff_retaddr[2];

    *(float *)(param_1 + 0x824) = *unaff_retaddr + *(float *)(param_1 + 0x824);

    *(float *)(param_1 + 0x828) = *(float *)(param_1 + 0x828) + unaff_retaddr[1];

    *(float *)(param_1 + 0x82c) = *(float *)(param_1 + 0x82c) + unaff_retaddr[2];

    *(float *)(param_1 + 0x888) = *unaff_retaddr + *(float *)(param_1 + 0x888);

    *(float *)(param_1 + 0x88c) = *(float *)(param_1 + 0x88c) + unaff_retaddr[1];

    *(float *)(param_1 + 0x890) = *(float *)(param_1 + 0x890) + unaff_retaddr[2];

  }

  return;

}
