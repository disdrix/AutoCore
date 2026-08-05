// =============================================================================
// FUN_004398d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004398d0
// Address:   0x004398d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004398d0 @ 0x004398d0
// Stable ID: aa_004398d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00436f80, FUN_004398d0, FUN_00767160.
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

uint32_t /* width from decompiler */ FUN_004398d0(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if (unaff_ESI[7] == 0) {

    uVar1 = FUN_00436f80(unaff_ESI,*in_EAX);

    unaff_ESI[1] = unaff_ESI[1] | uVar1;

    return unaff_ESI[1];

  }

  uVar1 = FUN_00767160(&DAT_00a9d6f8,*in_EAX);

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  unaff_ESI[8] = 0;

  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&DAT_00a97b84,2);

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  return unaff_ESI[1];

}
