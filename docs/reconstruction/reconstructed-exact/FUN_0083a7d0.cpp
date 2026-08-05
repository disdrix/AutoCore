// =============================================================================
// FUN_0083a7d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083a7d0
// Address:   0x0083a7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083a7d0 @ 0x0083a7d0
// Stable ID: aa_0083a7d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0083a7d0.
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

uint32_t /* width from decompiler */ FUN_0083a7d0(int param_1)



{

  int iVar1;

  int unaff_EBX;

  int *piVar2;

  int iVar3;

  

  iVar3 = 0;

  piVar2 = (int *)(param_1 + 0x50c);

  do {

    if (*piVar2 != 0) {

      iVar1 = (**(code **)(*(int *)*piVar2 + 0x78))();

      if (iVar1 + -0x9ca4 == unaff_EBX) {

        return *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c + iVar3 * 4);

      }

    }

    iVar3 = iVar3 + 1;

    piVar2 = piVar2 + 1;

  } while (iVar3 < 5);

  return 0;

}
