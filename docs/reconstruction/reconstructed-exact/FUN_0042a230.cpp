// =============================================================================
// FUN_0042a230
// -----------------------------------------------------------------------------
// Stable ID: aa_0042a230
// Address:   0x0042a230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042a230 @ 0x0042a230
// Stable ID: aa_0042a230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0042a230.
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

uint32_t /* width from decompiler */ __thiscall FUN_0042a230(int *param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  iVar1 = param_1[1] + -1;

  if (-1 < iVar1) {

    iVar2 = *param_1;

    piVar4 = (int *)(iVar2 + iVar1 * 8);

    iVar3 = iVar1;

    do {

      if (*piVar4 == *param_2) {

        param_1[1] = iVar1;

        *(uint32_t /* width from decompiler */ *)(iVar2 + iVar3 * 8) = *(uint32_t /* width from decompiler */ *)(iVar2 + iVar1 * 8);

        *(uint32_t /* width from decompiler */ *)(iVar2 + 4 + iVar3 * 8) = *(uint32_t /* width from decompiler */ *)(iVar2 + 4 + iVar1 * 8);

        return 0;

      }

      iVar3 = iVar3 + -1;

      piVar4 = piVar4 + -2;

    } while (-1 < iVar3);

  }

  return 1;

}
