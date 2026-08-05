// =============================================================================
// FUN_0065ca80
// -----------------------------------------------------------------------------
// Stable ID: aa_0065ca80
// Address:   0x0065ca80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065ca80 @ 0x0065ca80
// Stable ID: aa_0065ca80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×1.
//  - Notable callees: FUN_0065ca80.
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

void __thiscall FUN_0065ca80(int param_1,int *param_2)



{

  short *psVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  

  iVar2 = 0;

  if (0 < param_2[1]) {

    do {

      psVar1 = (short *)(*(int *)(*param_2 + iVar2 * 4) + 6);

      *psVar1 = *psVar1 + 1;

      iVar2 = iVar2 + 1;

    } while (iVar2 < param_2[1]);

  }

  if (0 < *(int *)(param_1 + 0xc)) {

    iVar2 = 0;

    do {

      puVar5 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 8) + iVar2 * 4);

      *(short *)((int)puVar5 + 6) = *(short *)((int)puVar5 + 6) + -1;

      if (*(short *)((int)puVar5 + 6) == 0) {

        (**(code **)*puVar5)(1);

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < *(int *)(param_1 + 0xc));

  }

  uVar3 = *(uint *)(param_1 + 0x10) & 0x7fffffff;

  if ((int)uVar3 < param_2[1]) {

    if (-1 < (int)*(uint *)(param_1 + 0x10)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar3 * 4,0x12);

    }

    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[1] * 4,0x12);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    *(int *)(param_1 + 0x10) = param_2[1];

  }

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  *(int *)(param_1 + 0xc) = param_2[1];

  iVar2 = param_2[1];

  if (0 < iVar2) {

    iVar6 = *param_2 - (int)puVar5;

    do {

      *puVar5 = *(uint32_t /* width from decompiler */ *)(iVar6 + (int)puVar5);

      puVar5 = puVar5 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return;

}
