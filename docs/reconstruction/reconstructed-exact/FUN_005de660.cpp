// =============================================================================
// FUN_005de660
// -----------------------------------------------------------------------------
// Stable ID: aa_005de660
// Address:   0x005de660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005de660 @ 0x005de660
// Stable ID: aa_005de660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, while×2, do×1.
//  - Notable callees: FUN_005de660.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ * __thiscall FUN_005de660(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  int iVar7;

  

  if (0x2000 < param_2) {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(code *)PTR__aligned_malloc_00af3bcc)(param_2,0x40);

    return puVar4;

  }

  if (param_2 < 0x201) {

    iVar7 = (int)*(char *)(param_2 + 0xb0 + param_1);

  }

  else {

    iVar7 = *(int *)(param_1 + 0x2b4 + (param_2 + -1 >> 10) * 4);

  }

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x28 + iVar7 * 4);

  piVar1 = (int *)(param_1 + 0x2ec + iVar7 * 4);

  *piVar1 = *piVar1 + 1;

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    iVar2 = *(int *)(param_1 + 0x6c + iVar7 * 4);

    if (param_2 < 0x201) {

      if (*(uint *)(param_1 + 0x20) < (uint)(*(int *)(param_1 + 0x24) + iVar2)) {

        puVar4 = (uint32_t /* width from decompiler */ *)(*(code *)PTR__aligned_malloc_00af3bcc)(0x2040,0x40);

        *puVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar4;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c) = puVar4 + 0x10;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x24) = puVar4 + 0x10;

        *(int *)(param_1 + 0x2d4) = *(int *)(param_1 + 0x2d4) + 1;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = puVar4 + 0x810;

      }

      puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x24);

      puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar5 + iVar2);

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x24) = puVar4;

      uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2ec + iVar7 * 4);

      iVar6 = iVar2;

      while ((iVar6 < 0x100 && ((uint)((int)puVar4 + iVar2) < *(uint *)(param_1 + 0x20)))) {

        piVar1 = (int *)(param_1 + 0x2ec + iVar7 * 4);

        *piVar1 = *piVar1 + -1;

        *puVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28 + iVar7 * 4);

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x28 + iVar7 * 4) = puVar4;

        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + iVar2;

        iVar6 = iVar6 + iVar2;

        puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x24);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x2ec + iVar7 * 4) = uVar3;

      return puVar5;

    }

    puVar4 = (uint32_t /* width from decompiler */ *)(*(code *)PTR__aligned_malloc_00af3bcc)(0x2040,0x40);

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x18) == (uint32_t /* width from decompiler */ *)0x0) {

      *puVar4 = 0;

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar4;

    }

    else {

      *puVar4 = **(uint32_t /* width from decompiler */ **)(param_1 + 0x18);

      **(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar4;

    }

    *(int *)(param_1 + 0x2d4) = *(int *)(param_1 + 0x2d4) + 1;

    uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2ec + iVar7 * 4);

    puVar4 = puVar4 + 0x10;

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + (int)puVar4);

    if (iVar2 < 0x2000) {

      iVar6 = (int)puVar5 - (int)puVar4;

      do {

        piVar1 = (int *)(param_1 + 0x2ec + iVar7 * 4);

        *piVar1 = *piVar1 + -1;

        *puVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28 + iVar7 * 4);

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x28 + iVar7 * 4) = puVar5;

        iVar6 = iVar6 + iVar2;

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + iVar2);

      } while (iVar6 < 0x2000);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2ec + iVar7 * 4) = uVar3;

    return puVar4;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28 + iVar7 * 4) = *puVar4;

  return puVar4;

}
