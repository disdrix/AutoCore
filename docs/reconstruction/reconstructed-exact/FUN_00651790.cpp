// =============================================================================
// FUN_00651790
// -----------------------------------------------------------------------------
// Stable ID: aa_00651790
// Address:   0x00651790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00651790 @ 0x00651790
// Stable ID: aa_00651790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, for×1, while×1, return×1.
//  - Notable callees: FUN_005b3300×2, FUN_00651730, FUN_00651790.
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

void __fastcall FUN_00651790(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint32_t /* width from decompiler */ *unaff_retaddr;

  int local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  iVar3 = *(int *)(param_1 + 0x94);

  local_10 = iVar3 * 0x30 + 0xb0;

  local_c = 0;

  local_8 = 0;

  if (iVar3 == 1) {

    local_8 = 4;

    local_c = 0x20;

  }

  local_c = local_c + 0x30;

  local_8 = local_8 + 4;

  local_4 = (int *)((iVar3 == 1) + 1);

  (**(code **)(**(int **)(param_1 + 0x14) + 8))(param_1,&local_10);

  *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) | 6;

  iVar4 = *(int *)(param_1 + 0x38);

  iVar5 = *(int *)(param_1 + 0x38);

  iVar3 = iVar4 + 1;

  uVar7 = *(uint *)(param_1 + 0x3c) & 0x7fffffff;

  if ((int)uVar7 < iVar3) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar3) {

      iVar8 = iVar3;

    }

    FUN_005b3300((int *)(param_1 + 0x34),iVar8,0x20);

  }

  iVar6 = *(int *)(param_1 + 0x34);

  *(int *)(param_1 + 0x38) = iVar3;

  piVar2 = (int *)(param_1 + 0x90);

  iVar3 = *(int *)(param_1 + 0x94) + 1;

  iVar8 = *(int *)(param_1 + 0x94) - iVar5;

  uVar7 = *(uint *)(param_1 + 0x98) & 0x7fffffff;

  if ((int)uVar7 < iVar3) {

    iVar9 = uVar7 * 2;

    if (iVar9 <= iVar3) {

      iVar9 = iVar3;

    }

    FUN_005b3300(piVar2,iVar9,0x1c);

  }

  iVar9 = *piVar2 + iVar5 * 0x1c;

  if (-1 < iVar8 + -1) {

    iVar1 = iVar9 + 0x1c;

    puVar11 = (uint32_t /* width from decompiler */ *)(iVar1 + (iVar8 + -1) * 0x1c);

    do {

      iVar8 = iVar8 + -1;

      puVar12 = (uint32_t /* width from decompiler */ *)((iVar9 - iVar1) + (int)puVar11);

      puVar13 = puVar11;

      for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {

        *puVar13 = *puVar12;

        puVar12 = puVar12 + 1;

        puVar13 = puVar13 + 1;

      }

      puVar11 = puVar11 + -7;

    } while (iVar8 != 0);

  }

  *(int *)(param_1 + 0x94) = iVar3;

  puVar11 = (uint32_t /* width from decompiler */ *)(*piVar2 + iVar5 * 0x1c);

  *puVar11 = 0;

  puVar11[1] = 0;

  *(uint16_t *)(puVar11 + 6) = 0;

  if ((0 < iVar5) && (*(short *)(puVar11 + -1) == 0)) {

    *(uint16_t *)(puVar11 + 6) = 1;

  }

  *local_4 = iVar4 * 0x20 + iVar6;

  *unaff_retaddr = puVar11;

  FUN_00651730(iVar5);

  return;

}
