// =============================================================================
// FUN_008a79b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a79b0
// Address:   0x008a79b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a79b0 @ 0x008a79b0
// Stable ID: aa_008a79b0
// Embedded strings (evidence for future rename):
//   - "(Current Status)"
//   - "- In progress"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, for×1, do×1, while×1.
//  - Notable callees: CNDHash_LookupByKey×2, FUN_00791f30×2, FUN_007a6de0×2, FUN_004024b0, FUN_007a69d0, FUN_008a79b0.
//  - Strings: "(Current Status)"; "- In progress".
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

void __thiscall FUN_008a79b0(int *param_1,float param_2)



{

  float fVar1;

  int *piVar2;

  char cVar3;

  void *pvVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint uVar8;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ auStack_214 [2];

  uint16_t uStack_20c;

  uint32_t /* width from decompiler */ auStack_20a [129];

  

  fVar1 = (float)param_1[0x149];

  param_1[0x149] = (int)(fVar1 - param_2);

  if (fVar1 - param_2 <= 0.0) {

    param_1[0x149] = DAT_00a0f298;

    *(uint8_t *)(param_1 + 0x148) = 1;

  }

  piVar2 = (int *)param_1[0x14a];

  if ((((piVar2 != (int *)0x0) && (DAT_00d1b6d8 != 0)) &&

      (iVar7 = *(int *)(DAT_00d1ad10 + 0x10), iVar7 != -1)) &&

     ((iVar7 != param_1[0x143] || ((char)param_1[0x148] != '\0')))) {

    param_1[0x143] = iVar7;

    pvVar4 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x548),*(uint *)(DAT_00d1ad10 + 0x10));

    param_1[0x144] = (int)pvVar4;

    if (pvVar4 == (void *)0x0) {

      param_1[0x145] = 0;

    }

    else {

      pvVar4 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x55c),*(uint *)((int)pvVar4 + 0x10));

      param_1[0x145] = (int)pvVar4;

    }

    (**(code **)(*piVar2 + 0x268))();

    (**(code **)(*(int *)param_1[0x14a] + 0x34c))();

    (**(code **)(*(int *)param_1[0x14a] + 0x130))(param_1 + 0x146);

    if (DAT_00d1a8dd != '\0') {

      *(uint8_t *)(param_1 + 0x148) = 0;

      FUN_00791f30(param_2);

      return;

    }

    if (param_1[0x144] != 0) {

      uStack_20c = 0;

      puVar9 = auStack_20a;

      for (iVar7 = 0x7f; iVar7 != 0; iVar7 = iVar7 + -1) {

        *puVar9 = 0;

        puVar9 = puVar9 + 1;

      }

      *(uint16_t *)puVar9 = 0;

      uVar5 = FUN_004024b0();

      FUN_007a69d0();

      iVar7 = *(int *)param_1[0x14a];

      uVar10 = 0xdff59623;

      uVar6 = FUN_007a6de0("(Current Status)",0xffffffff);

      (**(code **)(iVar7 + 0x224))(uVar6,uVar10);

      (**(code **)(*(int *)param_1[0x14a] + 0x250))(&DAT_00a15104);

      if ((param_1[0x145] == 0) || (uVar5 == 0)) {

        iVar7 = *(int *)param_1[0x14a];

        uVar10 = 0xdfdddddd;

        uVar6 = FUN_007a6de0("- In progress",0xffffffff);

        (**(code **)(iVar7 + 0x224))(uVar6,uVar10);

        (**(code **)(*(int *)param_1[0x14a] + 0x250))(&DAT_00a15104);

      }

      else if (uVar5 != 0) {

        uVar8 = 0;

        do {

          uStack_20c = DAT_00a4bc1c;

          auStack_20a[0]._0_1_ = DAT_00a4bc1e;

          piVar2 = *(int **)(*(int *)(param_1[0x144] + 0x158) + uVar8 * 4);

          if ((piVar2 != (int *)0x0) &&

             (iVar7 = (**(code **)(*piVar2 + 0x1c))(DAT_00d1b6d8,param_1[0x145],&uStack_20c,0x1fd),

             iVar7 != 0)) {

            auStack_214[0] = *(uint32_t /* width from decompiler */ *)param_1[0x14a];

            cVar3 = (**(code **)(*piVar2 + 8))(DAT_00d1b6d8,param_1[0x145]);

            (**(code **)(unaff_ESI + 0x224))

                      (auStack_214,(-(uint)(cVar3 != '\0') & 0x222222) + 0xdfdddddd);

            if (uVar8 < uVar5 - 1) {

              (**(code **)(*(int *)param_1[0x14a] + 0x250))(&DAT_00a15104);

            }

          }

          uVar8 = uVar8 + 1;

        } while (uVar8 < uVar5);

      }

    }

    (**(code **)(*(int *)param_1[0x14a] + 0x13c))();

    iVar7 = *param_1;

    uVar6 = (**(code **)(*(int *)param_1[0x14a] + 0x140))(auStack_214,1);

    (**(code **)(iVar7 + 0x138))(uVar6);

    *(uint8_t *)(param_1 + 0x148) = 0;

  }

  FUN_00791f30(param_2);

  return;

}
