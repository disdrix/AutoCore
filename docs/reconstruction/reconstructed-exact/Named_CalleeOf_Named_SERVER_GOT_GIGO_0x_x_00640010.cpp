// =============================================================================
// Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00640010
// -----------------------------------------------------------------------------
// Stable ID: aa_00640010
// Callee of Named_SERVER_GOT_GIGO_0x_x
// Address:   0x00640010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: FUN_005b3300×2, FUN_0045d900, FUN_00632670, FUN_00638060, FUN_006380a0, FUN_00638180, FUN_006381a0, FUN_0063ff50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_SERVER_GOT_GIGO_0x_x
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00640010(int param_1)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  undefined *puVar8;

  int iVar9;

  uint uVar10;

  int iVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ unaff_retaddr;

  int iStack_24;

  uint32_t /* width from decompiler */ local_20;

  int local_1c;

  uint uStack_18;

  int iStack_14;

  uint uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  piVar2 = *(int **)(param_1 + 0x20);

  local_20 = 0;

  if (piVar2 != (int *)0x0) {

    uVar5 = (**(code **)(*piVar2 + 0xc))();

    uStack_c = 0;

    uStack_8 = 0;

    uStack_4 = 0x80000000;

    FUN_0063ff50(piVar2);

    iVar6 = (**(code **)(*DAT_00b05060 + 0x10))(0x24,6);

    iVar9 = iStack_14;

    *(uint16_t *)(iVar6 + 4) = 0x24;

    if (iStack_14 == 0) {

      DAT_00d02c6c = DAT_00d02c6c + 1;

      puVar8 = &DAT_00d02c70;

    }

    else {

      iVar6 = FUN_00638060(iStack_14);

      iVar7 = FUN_006381a0(iVar6);

      puVar8 = (undefined *)(iVar7 + 0xc);

      FUN_006380a0(puVar8,iVar9,iVar6 + 1);

    }

    iVar9 = FUN_00652bc0(&stack0xffffffd4,uVar5);

    piVar1 = (int *)(puVar8 + -4);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

    }

    local_20 = 0;

    local_1c = 0;

    uStack_18 = 0x80000000;

    iVar6 = FUN_0045d900();

    if ((int)(uStack_18 & 0x7fffffff) < iVar6) {

      iVar7 = (uStack_18 & 0x7fffffff) * 2;

      if (iVar7 <= iVar6) {

        iVar7 = iVar6;

      }

      FUN_005b3300(&local_20,iVar7,1);

    }

    local_1c = iVar6;

    FUN_00632670(piVar2,local_20);

    uVar5 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18);

    *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18) = local_20;

    uVar3 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x1c);

    *(int *)(iVar9 + 0x1c) = local_1c;

    uVar4 = *(uint *)(iVar9 + 0x20);

    *(uint *)(iVar9 + 0x20) = uStack_18;

    iVar7 = *(int *)(iStack_24 + 0x2c);

    iVar6 = iVar7 + 1;

    uVar10 = *(uint *)(iStack_24 + 0x30) & 0x7fffffff;

    local_20 = uVar5;

    local_1c = uVar3;

    uStack_18 = uVar4;

    if ((int)uVar10 < iVar6) {

      iVar11 = uVar10 * 2;

      if (iVar11 <= iVar6) {

        iVar11 = iVar6;

      }

      FUN_005b3300((int *)(iStack_24 + 0x28),iVar11,0x10);

    }

    puVar12 = (uint32_t /* width from decompiler */ *)(iVar7 * 0x10 + *(int *)(iStack_24 + 0x28));

    *(int *)(iStack_24 + 0x2c) = iVar6;

    *puVar12 = uStack_4;

    puVar12[1] = unaff_retaddr;

    puVar12[2] = iVar9;

    if (-1 < (int)uStack_18) {

      (**(code **)(*DAT_00b05060 + 0x14))(local_20,uStack_18 & 0x7fffffff,0x12);

    }

    if (-1 < (int)uStack_c) {

      (**(code **)(*DAT_00b05060 + 0x14))(iStack_14,uStack_c & 0x7fffffff,0x12);

    }

  }

  return;

}
