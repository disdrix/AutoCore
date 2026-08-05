// =============================================================================
// Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d37d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008d37d0
// Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
// Address:   0x008d37d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×11, do×3, while×3, return×1.
//  - Notable callees: CONCAT31×3, FUN_005a6e00×2, FUN_005a6e40×2, FUN_00755db0×2, FUN_00755e80×2, FUN_0076c4d0×2, FUN_004f5c30, FUN_008d37d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
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

void Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d37d0(int param_1)



{

  int iVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint local_18;

  uint local_14;

  

  if (*(int *)(param_1 + 0x590) < *(int *)(param_1 + 0x588)) {

    if (*(int *)(param_1 + 0x590) < 0) {

      *(int *)(param_1 + 0x590) = *(int *)(param_1 + 0x588) + -1;

    }

  }

  else {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x590) = 0;

  }

  iVar1 = *(int *)(*(int *)(param_1 + 0x548) + 600);

  if (((iVar1 != 0) && (*(char *)(iVar1 + 0x11c) != '\0')) &&

     (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x3c) + 0x4ce)

      != '\x04')) {

    local_18 = local_18 & 0xffffff00;

    if ('\0' < *(char *)(iVar1 + 0xb0)) {

      do {

        iVar3 = FUN_005a6e00(local_18);

        if (iVar3 != 0) {

          uVar4 = FUN_005a6e00(local_18);

          iVar3 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

          *(uint8_t *)(iVar3 + 0x48) = 1;

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40);

          FUN_0076c4d0();

          cVar2 = (**(code **)(**(int **)(iVar3 + 8) + 8))(uVar4);

          if (cVar2 != '\0') {

            FUN_00755db0(uVar4);

            FUN_00755e80(uVar4);

          }

        }

        cVar2 = (char)local_18 + '\x01';

        local_18 = CONCAT31(local_18._1_3_,cVar2);

      } while (cVar2 < *(char *)(iVar1 + 0xb0));

    }

    local_14 = local_14 & 0xffffff00;

    if ('\0' < *(char *)(iVar1 + 0xf0)) {

      do {

        local_18 = local_18 & 0xffffff00;

        do {

          iVar3 = FUN_005a6e40(local_14,local_18);

          if (iVar3 != 0) {

            uVar4 = FUN_005a6e40(local_14,local_18);

            iVar3 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

            *(uint8_t *)(iVar3 + 0x48) = 1;

            *(uint32_t /* width from decompiler */ *)(iVar3 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40);

            FUN_0076c4d0();

            cVar2 = (**(code **)(**(int **)(iVar3 + 8) + 8))(uVar4);

            if (cVar2 != '\0') {

              FUN_00755db0(uVar4);

              FUN_00755e80(uVar4);

            }

          }

          cVar2 = (char)local_18 + '\x01';

          local_18 = CONCAT31(local_18._1_3_,cVar2);

        } while (cVar2 < '\x03');

        cVar2 = (char)local_14 + '\x01';

        local_14 = CONCAT31(local_14._1_3_,cVar2);

      } while (cVar2 < *(char *)(iVar1 + 0xf0));

    }

  }

  iVar1 = *(int *)(*(int *)(param_1 + 0x548) + 600);

  if (iVar1 != 0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

  }

  piVar5 = (int *)CVOGReaction_GiveItemByCbid

                            (*(int *)(param_1 + 0x578 + *(int *)(param_1 + 0x590) * 4));

  puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar5 + 0x1f0))();

  if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)(*(int *)(*(int *)(puVar6[1] + 4) + 4 + (int)puVar6) + 8))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x578 + *(int *)(param_1 + 0x590) * 4),

               *(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(*(int *)(param_1 + 0x548) + 4) + 4) + 0xa8 +

                *(int *)(param_1 + 0x548)),1);

    (**(code **)*puVar6)(1,0,0,0,0,0,0,g_flOne,0);

    Vehicle_SetWheelset(puVar6);

    FUN_008d7b10(param_1);

    FUN_004f5c30();

  }

  return;

}
