// =============================================================================
// FUN_0091afc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0091afc0
// Address:   0x0091afc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091afc0 @ 0x0091afc0
// Stable ID: aa_0091afc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00720460, FUN_00720d40, FUN_0091afc0.
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

void FUN_0091afc0(void)



{

  int iVar1;

  int *unaff_ESI;

  

  if (unaff_ESI[0x31e] != 0) {

    (**(code **)(*unaff_ESI + 0xb0))(unaff_ESI[0x31e]);

    (**(code **)(*(int *)unaff_ESI[0x31e] + 0x440))();

    if ((uint32_t /* width from decompiler */ *)unaff_ESI[0x31e] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)unaff_ESI[0x31e])(1);

    }

    unaff_ESI[0x31e] = 0;

    FUN_00720d40();

    FUN_00720460();

    (**(code **)(*unaff_ESI + 0x3ec))();

    unaff_ESI[0x1a] = unaff_ESI[0x1a] + -1;

    iVar1 = unaff_ESI[0x1a];

    unaff_ESI[0x1d] = (int)(float)-iVar1;

    if (unaff_ESI[0x1c] < iVar1) {

      unaff_ESI[0x1c] = iVar1;

    }

    (**(code **)(*unaff_ESI + 0x3f4))(0xffffffff);

    *(uint8_t *)((int)unaff_ESI + 0xa36) = 0;

  }

  return;

}
