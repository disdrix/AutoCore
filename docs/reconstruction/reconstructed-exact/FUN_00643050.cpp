// =============================================================================
// FUN_00643050
// -----------------------------------------------------------------------------
// Stable ID: aa_00643050
// Address:   0x00643050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00643050 @ 0x00643050
// Stable ID: aa_00643050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_00643050.
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

int __fastcall FUN_00643050(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (*(int *)(param_1 + 8) == 0) {

    return 0;

  }

  iVar1 = *(int *)(param_1 + 0x10);

  iVar3 = 0;

  if (0 < iVar1) {

    do {

      iVar2 = (**(code **)(**(int **)(param_1 + 8) + 8))

                        (*(int *)(param_1 + 0xc) + iVar3,iVar1 - iVar3);

      iVar3 = iVar3 + iVar2;

      if (iVar2 == 0) {

        return iVar3;

      }

    } while (iVar3 < iVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  return iVar3;

}
