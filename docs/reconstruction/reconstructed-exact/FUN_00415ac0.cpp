// =============================================================================
// FUN_00415ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00415ac0
// Address:   0x00415ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00415ac0 @ 0x00415ac0
// Stable ID: aa_00415ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_00415ac0.
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

uint32_t /* width from decompiler */ __fastcall FUN_00415ac0(uint param_1)



{

  int in_EAX;

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(*(int *)(in_EAX + 0x10) + (*(uint *)(in_EAX + 8) & param_1) * 4) + 4);

  if (iVar1 != 0) {

    while (param_1 != *(uint *)(iVar1 + 0x10)) {

      iVar1 = *(int *)(iVar1 + 0xc);

      if (iVar1 == 0) {

        return 0;

      }

    }

    if (iVar1 != 0) {

      return *(uint32_t /* width from decompiler */ *)(iVar1 + 8);

    }

  }

  return 0;

}
