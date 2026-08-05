// =============================================================================
// FUN_0071faf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071faf0
// Address:   0x0071faf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071faf0 @ 0x0071faf0
// Stable ID: aa_0071faf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_00424830, FUN_0071faf0.
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

uint32_t /* width from decompiler */ __fastcall FUN_0071faf0(uint param_1)



{

  int *piVar1;

  uint uVar2;

  int unaff_EDI;

  uint local_4;

  

  if (*(int *)(unaff_EDI + 0x10) == 0) {

    return 0;

  }

  uVar2 = 0;

  local_4 = param_1;

  if (*(int *)(unaff_EDI + 0x1c) != 0) {

    do {

      if (*(int *)(*(int *)(unaff_EDI + 0x10) + uVar2 * 4) != 0) {

        local_4 = 0;

        piVar1 = *(int **)(*(int *)(unaff_EDI + 0x10) + uVar2 * 4);

        (**(code **)(*piVar1 + 0x24))(piVar1,&local_4);

        if ((local_4 & 1) == 0) break;

      }

      uVar2 = uVar2 + 1;

    } while (uVar2 < *(uint *)(unaff_EDI + 0x1c));

  }

  if (uVar2 != *(uint *)(unaff_EDI + 0x1c)) {

    return *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x10) + uVar2 * 4);

  }

  CVOGReaction_RandomUnitScalar();

  uVar2 = FUN_00424830();

  return *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x10) + (uVar2 % *(uint *)(unaff_EDI + 0x1c)) * 4);

}
