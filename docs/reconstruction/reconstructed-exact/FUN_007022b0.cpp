// =============================================================================
// FUN_007022b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007022b0
// Address:   0x007022b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007022b0 @ 0x007022b0
// Stable ID: aa_007022b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_007022b0.
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

void __thiscall FUN_007022b0(int param_1,int *param_2,int param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0xc);

  if (param_3 != 0) {

    do {

      iVar1 = iVar1 + -1;

      if (iVar1 < 0) break;

      *(uint32_t /* width from decompiler */ *)(*param_2 + param_2[1] * 4) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + iVar1 * 4);

      param_2[1] = param_2[1] + 1;

      param_3 = param_3 + -1;

      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

    } while (param_3 != 0);

    if (0 < param_3) {

      do {

        iVar1 = *(int *)(param_1 + 0x1b4);

        *(int *)(param_1 + 0x1b4) = iVar1 + 1;

        *(int *)(*param_2 + param_2[1] * 4) = iVar1 * 0x50 + *(int *)(param_1 + 0x1b0);

        param_3 = param_3 + -1;

        param_2[1] = param_2[1] + 1;

      } while (param_3 != 0);

    }

  }

  return;

}
