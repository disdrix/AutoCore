// =============================================================================
// FUN_00522f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00522f70
// Address:   0x00522f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522f70 @ 0x00522f70
// Stable ID: aa_00522f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CVOGReaction_GiveItemByCbid, FUN_004bc180, FUN_004bff90, FUN_004c55e0, FUN_004ca910, FUN_004e9720, FUN_00512160, FUN_005210b0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_00522f70(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  int *piVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *unaff_ESI;

  float10 fVar8;

  float fVar9;

  uint32_t /* width from decompiler */ uVar10;

  TFID_16 *local_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint8_t auStack_2c [40];

  

  local_3c = (TFID_16 *)(param_1 + 0x518);

  pvVar4 = Object_ResolveFromTFID(local_3c);

  if ((pvVar4 == (void *)0x0) ||

     (*(int *)(*(int *)((int)pvVar4 + 0xa8) + 0x34) != *(int *)(param_1 + 0x514))) {

    FUN_005210b0();

    if (*(int *)(param_1 + 0x514) != -1) {

      piVar5 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(param_1 + 0x514));

      if (piVar5 != (int *)0x0) {

        (**(code **)(*piVar5 + 8))

                  (*(uint32_t /* width from decompiler */ *)(param_1 + 0x514),

                   *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1),0);

        iVar6 = (**(code **)(*piVar5 + 0x1d8))();

        if (iVar6 == 0) {

          (**(code **)*piVar5)(1);

        }

        iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

        iVar2 = *(int *)(iVar1 + 0xe6e8);

        iVar3 = *(int *)(iVar1 + 0xe6ec);

        *(int *)(iVar1 + 0xe6e8) = iVar2 + -1;

        *(uint *)(iVar1 + 0xe6ec) = iVar3 - (uint)(iVar2 == 0);

        FUN_00512160(iVar2,iVar3,0);

        FUN_004bc180(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6);

        puVar7 = (uint32_t /* width from decompiler */ *)

                 (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1a0))

                           ();

        local_3c = (TFID_16 *)*puVar7;

        uStack_38 = puVar7[1];

        uStack_34 = puVar7[2];

        uStack_30 = puVar7[3];

        FUN_004e9720(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1),&local_3c

                     ,0x41700000,0x3f800000,auStack_2c,0x14,10,0);

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x218))

                  (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1));

        FUN_004ca910(*(int *)(*(int *)(param_1 + 4) + 4) + 0x164 + param_1,0);

        fVar9 = g_flLevelUpUiBase_Inferred;

        if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xf5) == '\0'

           ) {

          fVar9 = DAT_00a110d8;

        }

        *(float *)(iVar6 + 0x270) = fVar9;

        fVar8 = (float10)FUN_004c55e0();

        uVar10 = DAT_00aaa7a4;

        *(float *)(iVar6 + 0x1f0) = (float)(fVar8 * (float10)_DAT_00a0f69c);

        if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xf5) == '\0'

           ) {

          uVar10 = DAT_00a0f694;

        }

        *(uint32_t /* width from decompiler */ *)(iVar6 + 0x310) = uVar10;

        FUN_004bff90(iVar6 + 0x40,&uStack_30,&DAT_00b045f0,1,0,0);

        puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0x164 + iVar6);

        *unaff_ESI = *puVar7;

        unaff_ESI[1] = puVar7[1];

        unaff_ESI[2] = puVar7[2];

        unaff_ESI[3] = puVar7[3];

      }

    }

  }

  return;

}
