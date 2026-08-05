// =============================================================================
// FUN_00429f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00429f60
// Address:   0x00429f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00429f60 @ 0x00429f60
// Stable ID: aa_00429f60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00429f60, FUN_00637fc0.
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

int __thiscall FUN_00429f60(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  if (0 < param_1[1]) {

    iVar2 = 0;

    do {

      if (*(int *)(*param_1 + 4 + iVar2) == param_2[1]) {

        iVar1 = FUN_00637fc0(*(uint32_t /* width from decompiler */ *)(*param_1 + iVar2),*param_2);

        if (iVar1 == 0) {

          return *param_1 + 8 + iVar3 * 0xc;

        }

      }

      iVar3 = iVar3 + 1;

      iVar2 = iVar2 + 0xc;

    } while (iVar3 < param_1[1]);

  }

  return 0;

}
