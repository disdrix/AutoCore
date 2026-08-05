// =============================================================================
// FUN_0044c9e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044c9e0
// Address:   0x0044c9e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044c9e0 @ 0x0044c9e0
// Stable ID: aa_0044c9e0
// Embedded strings (evidence for future rename):
//   - "%I64u"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0044c9e0, FUN_00767160.
//  - Strings: "%I64u".
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

uint32_t /* width from decompiler */ FUN_0044c9e0(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_8 = *in_EAX;

  if (unaff_ESI[7] == 0) {

    local_4 = in_EAX[1];

    uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&local_8,8);

    unaff_ESI[1] = unaff_ESI[1] | uVar1;

    return unaff_ESI[1];

  }

  uVar1 = FUN_00767160("%I64u",local_8,in_EAX[1]);

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  unaff_ESI[8] = 0;

  uVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))(&DAT_00a97b84,2);

  unaff_ESI[1] = unaff_ESI[1] | uVar1;

  return unaff_ESI[1];

}
