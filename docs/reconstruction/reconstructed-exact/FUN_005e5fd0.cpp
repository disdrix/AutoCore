// =============================================================================
// FUN_005e5fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e5fd0
// Address:   0x005e5fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e5fd0 @ 0x005e5fd0
// Stable ID: aa_005e5fd0
// Embedded strings (evidence for future rename):
//   - "obj_gen_n_mov_barrel_01_blueandwhite.geo"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_004cd220, FUN_005e5fd0, FUN_00764030, FUN_00989e00.
//  - Strings: "obj_gen_n_mov_barrel_01_blueandwhite.geo".
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

void __fastcall FUN_005e5fd0(int *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint8_t *puVar5;

  void *pvVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ uStack_20;

  uint8_t local_18 [12];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a75eb;

  pvStack_c = ExceptionList;

  pvVar6 = (void *)0x0;

  ExceptionList = &pvStack_c;

  do {

    if (*(char *)((int)(param_1 + 0x69) + (int)pvVar6) != '\0') {

      puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_1 + 0x44))(local_18,pvVar6);

      uVar1 = puVar3[2];

      uVar2 = *puVar3;

      FUN_004cd220(uVar2,uVar1);

      if (*(int *)(param_1[0x55] + (int)pvVar6 * 4) == 0) {

        pvVar6 = operator_new(0x14c);

        piVar7 = (int *)0x0;

        pvStack_c = (void *)0x0;

        if (pvVar6 != (void *)0x0) {

          piVar7 = (int *)FUN_00764030();

        }

        pvStack_c = (void *)0xffffffff;

        FUN_00989e00(&stack0xffffffcc,"obj_gen_n_mov_barrel_01_blueandwhite.geo");

        (**(code **)(*piVar7 + 0x5c))(&stack0xffffffcc);

        iVar4 = (**(code **)(*piVar7 + 0x10))(3);

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xbc) = 0xffffffff;

        *(int *)(iVar4 + 0xb4) = *(int *)(iVar4 + 0xb4) + 1;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x90) = uVar2;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x94) = uStack_20;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x98) = uVar1;

        puVar5 = operator_new(0xc);

        *(void **)(puVar5 + 8) = pvVar6;

        *puVar5 = 2;

        *(int **)(puVar5 + 4) = param_1;

        piVar7[0x1e] = (int)puVar5;

        *(int **)(param_1[0x55] + (int)pvVar6 * 4) = piVar7;

      }

      else {

        iVar4 = (**(code **)(**(int **)(param_1[0x55] + (int)pvVar6 * 4) + 0x10))(3);

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xbc) = 0xffffffff;

        *(int *)(iVar4 + 0xb4) = *(int *)(iVar4 + 0xb4) + 1;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x90) = uVar2;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x94) = uStack_20;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x98) = uVar1;

      }

    }

    pvVar6 = (void *)((int)pvVar6 + 1);

  } while ((int)pvVar6 < 6);

  ExceptionList = pvStack_c;

  return;

}
