// =============================================================================
// FUN_0073b330
// -----------------------------------------------------------------------------
// Stable ID: aa_0073b330
// Address:   0x0073b330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073b330 @ 0x0073b330
// Stable ID: aa_0073b330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00456960, FUN_004641d0, FUN_0073b330.
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

void FUN_0073b330(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  

  iVar5 = param_1;

  iVar7 = 0;

  if (*(int *)(param_1 + 0x14) == 0) {

    param_1 = 0;

  }

  else {

    param_1 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 3;

  }

  if (0 < param_1) {

    do {

      uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0x14) + iVar7 * 8);

      piVar6 = (int *)FUN_004641d0();

      iVar2 = *piVar6;

      iVar3 = *(int *)(iVar2 + 4);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(iVar2 + 0xc) - iVar3 >> 2) <= (uint)(*(int *)(iVar2 + 8) - iVar3 >> 2))) {

        FUN_00456960(*(uint32_t /* width from decompiler */ *)(iVar2 + 8));

      }

      else {

        puVar4 = *(uint32_t /* width from decompiler */ **)(iVar2 + 8);

        *puVar4 = uVar1;

        *(uint32_t /* width from decompiler */ **)(iVar2 + 8) = puVar4 + 1;

      }

      iVar7 = iVar7 + 1;

    } while (iVar7 < param_1);

  }

  return;

}
