// READABILITY (auto CF):
//  - Body size: ~128 non-empty decompiler lines.
//  - Control keywords: if×11, return×3.
//  - Notable callees: FUN_00989e00×3, FUN_0096f3e0×2, FUN_00970140×2, CVOGTacArc_InitializeMesh, FUN_00414c20, FUN_007478c0, FUN_00748960, FUN_00764030.
//  - Strings: "NDTacArc.fx"; "veh_tacarc.dds"; "veh_tacarc_effect.dds"; "TacArcTextureBase".
//  - Return sites: 3.

// =============================================================================
// CVOGTacArc_InitializeMesh
// -----------------------------------------------------------------------------
// Stable ID: aa_00633180
// Address:   0x00633180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

int __fastcall CVOGTacArc_InitializeMesh(int param_1)



{

  int *piVar1;

  uint *puVar2;

  int *piVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *pvVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  int *piVar9;

  void *local_38 [4];

  uint8_t auStack_28 [4];

  void *pvStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a8c11;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {

    ExceptionList = &pvStack_c;

    operator_delete__(*(void **)(param_1 + 0x2c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x18) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x18))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  FUN_00989e00(local_38,"NDTacArc.fx");

  FUN_009701d0(local_38);

  FUN_00989e00(local_38,"veh_tacarc.dds");

  FUN_0096f3e0(local_38,0);

  FUN_00989e00(local_38,"veh_tacarc_effect.dds");

  FUN_0096f3e0(local_38,0);

  pvVar6 = operator_new__(*(int *)(param_1 + 0x28) * 0x60);

  *(void **)(param_1 + 0x2c) = pvVar6;

  local_38[0] = operator_new(0x14c);

  uStack_4 = 0;

  if (local_38[0] == (void *)0x0) {

    uVar7 = 0;

  }

  else {

    uVar7 = FUN_00764030();

  }

  uStack_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = uVar7;

  local_38[0] = operator_new(0xc4);

  uStack_4 = 1;

  if (local_38[0] == (void *)0x0) {

    uVar7 = 0;

  }

  else {

    uVar7 = FUN_00748960();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = uVar7;

  uStack_4 = 0xffffffff;

  uVar7 = (**(code **)(**(int **)(param_1 + 0x18) + 0xc))();

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c) + 100) = uVar7;

  iVar8 = **(int **)(param_1 + 0x1c);

  uVar7 = (**(code **)(**(int **)(param_1 + 0x18) + 100))();

  (**(code **)(iVar8 + 0x34))(uVar7);

  piVar3 = *(int **)(param_1 + 0x5c);

  piVar9 = (int *)(*(int *)(param_1 + 0x1c) + 0x20);

  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar4 = (int *)*piVar9;

  if (piVar4 != (int *)0x0) {

    piVar1 = piVar4 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar4 + 8))();

    }

  }

  *piVar9 = (int)piVar3;

  FUN_00970140("TacArcTextureBase",*(uint32_t /* width from decompiler */ *)(param_1 + 0x54));

  FUN_00970140("TacArcTextureEffect",*(uint32_t /* width from decompiler */ *)(param_1 + 0x58));

  FUN_009733d0(param_1 + 0x34);

  FUN_009700f0("MatZFailColor",local_38);

  puVar2 = (uint *)(*(int *)(param_1 + 0x1c) + 0xbc);

  *puVar2 = *puVar2 | 1;

  pvStack_24 = (void *)0x0;

  uStack_20 = 0;

  uStack_1c = 0;

  puStack_8 = (uint8_t *)0x2;

  uStack_18 = 0;

  uStack_14 = 0;

  FUN_007478c0(0x242);

  puStack_8 = (uint8_t *)0x3;

  iVar8 = FUN_00414c20(*(int *)(param_1 + 0x28) * 3,auStack_28,3,0);

  puStack_8 = (uint8_t *)0xffffffff;

  uStack_18 = 0;

  uStack_14 = 0;

  if (pvStack_24 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvStack_24);

  }

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c);

  pvStack_24 = (void *)0x0;

  uStack_20 = 0;

  uStack_1c = 0;

  if (iVar8 < 0) {

    if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar5)(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x18) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x18))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    ExceptionList = pvStack_10;

    return iVar8;

  }

  puVar5[0x2a] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c) + 0xac) = 4;

  puVar2 = (uint *)(*(int *)(param_1 + 0x1c) + 0xbc);

  *puVar2 = *puVar2 & 0xfffffffe;

  FUN_007647c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c));

  ExceptionList = pvStack_10;

  return iVar8;

}
