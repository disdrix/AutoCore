// =============================================================================
// FUN_005ffa10
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffa10
// Address:   0x005ffa10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ffa10 @ 0x005ffa10
// Stable ID: aa_005ffa10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_00411900×2, CONCAT31, FUN_00402c40, FUN_00518630, FUN_0056cc70, FUN_005ffa10, Weapon_ApplyShotHeatAndPowerCost.
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

uint __fastcall FUN_005ffa10(void *param_1)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uStack_24;

  uint8_t auStack_20 [28];

  

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) + 0x214

                      ))();

  uVar2 = 0;

  if ((((iVar1 != 0) && (uVar2 = Weapon_ApplyShotHeatAndPowerCost(param_1), (char)uVar2 != '\0')) &&

      (uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) +

                           0x214))(),

      (*(byte *)(*(int *)(*(int *)(uVar2 + 4) + 4) + 0xb8 + uVar2) & 0x10) == 0)) &&

     ((uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) +

                           0x214))(),

      (*(byte *)(*(int *)(*(int *)(uVar2 + 4) + 4) + 0xb8 + uVar2) & 2) == 0 &&

      (iVar1 = *(int *)(*(int *)((int)param_1 + 4) + 4), uVar2 = iVar1 + (int)param_1,

      *(int *)(iVar1 + 0x74 + (int)param_1) != 0)))) {

    FUN_00518630(1,1,2);

    uStack_24 = 0;

    FUN_00402c40();

    iVar1 = FUN_00411900(&uStack_24);

    while (iVar1 != 0) {

      if ((*(uint *)(iVar1 + 0x614) & 0x100) == 0) {

        FUN_0056cc70(auStack_20);

        CVOGReaction_CastSkillOnTarget

                  (iVar1,*(uint32_t /* width from decompiler */ *)

                          (*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xb0 + (int)param_1)

                          + 0xac),0,0,0,auStack_20,0,0xffffffff,0,0);

      }

      iVar1 = FUN_00411900(&uStack_24);

    }

    iVar1 = *(int *)((int)param_1 + 4);

    *(uint8_t *)(*(int *)(*(int *)(iVar1 + 4) + 0x74 + (int)param_1) + 0x1d) = 0;

    return CONCAT31((int3)((uint)iVar1 >> 8),1);

  }

  return uVar2 & 0xffffff00;

}
