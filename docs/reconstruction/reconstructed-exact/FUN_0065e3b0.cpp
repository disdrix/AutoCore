// =============================================================================
// FUN_0065e3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065e3b0
// Address:   0x0065e3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065e3b0 @ 0x0065e3b0
// Stable ID: aa_0065e3b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_0065e3b0.
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

void __thiscall FUN_0065e3b0(int param_1,char *param_2)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar5 = (int)*param_2;

  piVar1 = (int *)(param_1 + 0x20);

  *(int *)(param_1 + 0xc) = iVar5;

  iVar4 = *(int *)(param_1 + 0x24);

  if (iVar4 < iVar5) {

    uVar2 = *(uint *)(param_1 + 0x28) & 0x7fffffff;

    if ((int)uVar2 < iVar5) {

      iVar3 = uVar2 * 2;

      if (iVar3 <= iVar5) {

        iVar3 = iVar5;

      }

      FUN_005b3300(piVar1,iVar3,4);

    }

    if (3 < iVar5 - iVar4) {

      do {

        *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(*piVar1 + 4 + iVar4 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(*piVar1 + 8 + iVar4 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(*piVar1 + 0xc + iVar4 * 4) = 0;

        iVar4 = iVar4 + 4;

      } while (iVar4 < iVar5 + -3);

    }

    for (; iVar4 < iVar5; iVar4 = iVar4 + 1) {

      *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = 0;

    }

  }

  *(int *)(param_1 + 0x24) = iVar5;

  return;

}
