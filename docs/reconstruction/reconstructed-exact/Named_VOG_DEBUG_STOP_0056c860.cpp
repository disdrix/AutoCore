// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, for×1.
//  - Notable callees: CONCAT31, FUN_004d7e30, FUN_004da2e0, FUN_0056c860, FUN_007a4480, Weapon_ApplyShotHeatAndPowerCost.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_0056c860
// -----------------------------------------------------------------------------
// Stable ID: aa_0056c860
// Address:   0x0056c860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_VOG_DEBUG_STOP_0056c860(int *param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uStack_e2c;

  uint8_t auStack_e28 [16];

  uint32_t /* width from decompiler */ auStack_e18 [96];

  uint8_t auStack_c98 [16];

  uint8_t auStack_c88 [3204];

  

  iVar3 = (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x214))();

  if ((((iVar3 != 0) && (iVar3 = Weapon_ApplyShotHeatAndPowerCost(param_1), (char)iVar3 != '\0')) &&

      (iVar3 = (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x214))(),

      (*(byte *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb8 + iVar3) & 0x10) == 0)) &&

     (iVar3 = (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x214))(),

     (*(byte *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb8 + iVar3) & 2) == 0)) {

    puVar4 = auStack_e18;

    for (iVar3 = 100; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    uStack_e2c = 0;

    if ((param_2 == 0) &&

       (iVar3 = (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x214))(),

       iVar3 != 0)) {

      iVar3 = (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x214))();

      param_2 = *(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xa4 + iVar3);

    }

    iVar3 = (**(code **)(*param_1 + 0x50))(param_2,auStack_e18,&uStack_e2c);

    if ((0 < (int)auStack_c88) || (iVar3 == 0)) {

      if (*(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) == 0) {

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      uStack_e2c = CONCAT31((int3)((uint)uStack_e2c >> 8),1);

      if (auStack_c88 == (uint8_t *)0x0) {

        iVar1 = *(int *)(param_1[1] + 4);

        uVar2 = *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0xb0);

        FUN_004d7e30(0,0,uVar2,uVar2,0,0,0,*(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0x164),

                     *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0x168),

                     *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0x16c),

                     *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0x170),&stack0xfffff1cc);

      }

      else {

        iVar1 = *(int *)(param_1[1] + 4);

        FUN_004da2e0(auStack_c98,auStack_c88,*(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0xb0),0,0,0,

                     *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0x164),

                     *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0x168),

                     *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0x16c),

                     *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0x170),&stack0xfffff1cc);

      }

    }

    if (iVar3 != 0) {

      (**(code **)(*param_1 + 0x48))(iVar3,auStack_e28);

    }

    return 1;

  }

  return 0;

}
