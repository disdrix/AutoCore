// =============================================================================
// FUN_00669960
// -----------------------------------------------------------------------------
// Stable ID: aa_00669960
// Address:   0x00669960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00669960 @ 0x00669960
// Stable ID: aa_00669960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_005b3300, FUN_00669960.
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

void __thiscall FUN_00669960(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  

  *(uint8_t *)(param_2 + 1) = *(uint8_t *)(param_1 + 0xc);

  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  iVar7 = *(int *)(param_1 + 0x14);

  piVar8 = param_2 + 2;

  if ((int)(param_2[4] & 0x7fffffff) < iVar7) {

    iVar3 = (param_2[4] & 0x7fffffff) * 2;

    if (iVar3 <= iVar7) {

      iVar3 = iVar7;

    }

    FUN_005b3300(piVar8,iVar3,0x10);

  }

  iVar3 = 0;

  param_2[3] = iVar7;

  if (3 < iVar7) {

    param_2 = (uint32_t /* width from decompiler */ *)((iVar7 - 4U >> 2) + 1);

    iVar6 = 0;

    iVar3 = (int)param_2 * 4;

    do {

      iVar1 = *(int *)(param_1 + 0x10);

      iVar2 = *piVar8;

      *(uint32_t /* width from decompiler */ *)(iVar2 + iVar6) = *(uint32_t /* width from decompiler */ *)(iVar1 + iVar6);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 4 + iVar6) = *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar6);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 8 + iVar6) = *(uint32_t /* width from decompiler */ *)(iVar1 + 8 + iVar6);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc + iVar6) = *(uint32_t /* width from decompiler */ *)(iVar1 + iVar6 + 0xc);

      iVar1 = *(int *)(param_1 + 0x10) + 0x10 + iVar6;

      iVar2 = *piVar8;

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x10 + iVar2) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 0x10 + iVar6);

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x14 + iVar2) = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x18 + iVar2) = *(uint32_t /* width from decompiler */ *)(iVar1 + 8);

      *(uint32_t /* width from decompiler */ *)(iVar6 + iVar2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

      puVar5 = (uint32_t /* width from decompiler */ *)(*piVar8 + iVar6 + 0x20);

      puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + iVar6 + 0x20);

      *puVar5 = *puVar4;

      puVar5[1] = puVar4[1];

      puVar5[2] = puVar4[2];

      puVar5[3] = puVar4[3];

      puVar5 = (uint32_t /* width from decompiler */ *)(*piVar8 + iVar6 + 0x30);

      puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + iVar6 + 0x30);

      *puVar5 = *puVar4;

      puVar5[1] = puVar4[1];

      puVar5[2] = puVar4[2];

      iVar6 = iVar6 + 0x40;

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + -1);

      puVar5[3] = puVar4[3];

    } while (param_2 != (uint32_t /* width from decompiler */ *)0x0);

  }

  if (iVar3 < iVar7) {

    iVar6 = iVar3 << 4;

    iVar7 = iVar7 - iVar3;

    do {

      iVar3 = *(int *)(param_1 + 0x10) + iVar6;

      puVar4 = (uint32_t /* width from decompiler */ *)(*piVar8 + iVar6);

      *puVar4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + iVar6);

      puVar4[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

      puVar4[2] = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

      iVar6 = iVar6 + 0x10;

      iVar7 = iVar7 + -1;

      puVar4[3] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc);

    } while (iVar7 != 0);

  }

  return;

}
