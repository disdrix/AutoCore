// =============================================================================
// FUN_00429fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00429fc0
// Address:   0x00429fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00429fc0 @ 0x00429fc0
// Stable ID: aa_00429fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_00429fc0, FUN_005b3300, FUN_00637fc0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00429fc0(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar4 = 0;

  if (0 < param_1[1]) {

    iVar3 = 0;

    do {

      if (*(int *)(*param_1 + 4 + iVar3) == param_2[1]) {

        iVar2 = FUN_00637fc0(*(uint32_t /* width from decompiler */ *)(*param_1 + iVar3),*param_2);

        if (iVar2 == 0) {

          return (uint32_t /* width from decompiler */ *)(*param_1 + 8 + iVar4 * 0xc);

        }

      }

      iVar4 = iVar4 + 1;

      iVar3 = iVar3 + 0xc;

    } while (iVar4 < param_1[1]);

  }

  iVar3 = param_1[1];

  iVar4 = iVar3 + 1;

  if ((int)(param_1[2] & 0x7fffffffU) < iVar4) {

    iVar2 = (param_1[2] & 0x7fffffffU) * 2;

    if (iVar2 <= iVar4) {

      iVar2 = iVar4;

    }

    FUN_005b3300(param_1,iVar2,0xc);

  }

  param_1[1] = iVar4;

  puVar1 = (uint32_t /* width from decompiler */ *)(*param_1 + iVar3 * 0xc);

  *puVar1 = *param_2;

  puVar1[1] = param_2[1];

  return puVar1 + 2;

}
