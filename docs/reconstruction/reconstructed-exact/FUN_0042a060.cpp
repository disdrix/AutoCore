// =============================================================================
// FUN_0042a060
// -----------------------------------------------------------------------------
// Stable ID: aa_0042a060
// Address:   0x0042a060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042a060 @ 0x0042a060
// Stable ID: aa_0042a060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0042a060, FUN_00637fc0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0042a060(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar4 = param_1[1] + -1;

  if (-1 < iVar4) {

    iVar5 = iVar4 * 0xc;

    do {

      if (*(int *)(*param_1 + 4 + iVar5) == param_2[1]) {

        iVar3 = FUN_00637fc0(*(uint32_t /* width from decompiler */ *)(*param_1 + iVar5),*param_2);

        if (iVar3 == 0) {

          param_1[1] = param_1[1] + -1;

          puVar1 = (uint32_t /* width from decompiler */ *)(*param_1 + param_1[1] * 0xc);

          puVar2 = (uint32_t /* width from decompiler */ *)(*param_1 + iVar4 * 0xc);

          *puVar2 = *puVar1;

          puVar2[1] = puVar1[1];

          puVar2[2] = puVar1[2];

          return 0;

        }

      }

      iVar4 = iVar4 + -1;

      iVar5 = iVar5 + -0xc;

    } while (-1 < iVar4);

  }

  return 1;

}
