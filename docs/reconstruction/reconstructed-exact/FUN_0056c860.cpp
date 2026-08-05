// =============================================================================
// FUN_0056c860 / Weapon_TryFireResolveHits_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0056c860
// Address:   0x0056c860  (autoassault.exe, image base 0x400000)
// Body:      0x0056c860 – 0x0056ca6a
// System:    combat / vehicle weapon
// Generated: 2026-07-29 live re-seal (faithful to Ghidra decompile)
// Exactness: Behavior-preserving; not modernization.
// ABI:       __thiscall; 1 stack arg; ret 4 (C2 04 00)
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Weapon fire attempt — owner/heat/flag gates, resolve hits via
//          vtbl+0x50, dispatch damage (FUN_004d7e30 / FUN_004da2e0), optional
//          vtbl+0x48 post-step. Returns 1 on gated path, 0 if any gate fails.
// STRING:  "VOG_DEBUG_STOP" is null-host assert only (not product name).
//
// NOTE: Large stack arrays are decompiler overlays of one hit-resolve buffer.
//       Comparisons on auStack_c88 as both count and pointer are Ghidra artifacts.
//

// External callees (image symbols)
//   Weapon_ApplyShotHeatAndPowerCost @ 0x0056ad00
//   FUN_007a4480  (debug stop / assert)
//   FUN_004d7e30  (damage dispatch, null-list path)
//   FUN_004da2e0  (damage dispatch, list path)

uint32_t __thiscall FUN_0056c860(int *param_1, int param_2)
{
  int iVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t *puVar4;
  uint32_t uStack_e2c;
  uint8_t auStack_e28[16];
  uint32_t auStack_e18[96];
  uint8_t auStack_c98[16];
  uint8_t auStack_c88[3204];

  /* owner via adjustor this + vtbl+0x214 */
  iVar3 = (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x214))();
  if ((((iVar3 != 0) &&
        (iVar3 = Weapon_ApplyShotHeatAndPowerCost(param_1), (char)iVar3 != '\0')) &&
       (iVar3 = (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x214))(),
        (*(uint8_t *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb8 + iVar3) & 0x10) == 0)) &&
      (iVar3 = (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x214))(),
       (*(uint8_t *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb8 + iVar3) & 2) == 0)) {
    /* zero 100 dwords of hit work buffer */
    puVar4 = auStack_e18;
    for (iVar3 = 100; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    uStack_e2c = 0;
    /* default target from owner_adj+0xA4 when param_2 == 0 */
    if ((param_2 == 0) &&
        (iVar3 = (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x214))(),
         iVar3 != 0)) {
      iVar3 = (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x214))();
      param_2 = *(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xa4 + iVar3);
    }
    /* resolve shot: weapon vtbl+0x50 */
    iVar3 = (**(code **)(*param_1 + 0x50))(param_2, auStack_e18, &uStack_e2c);
    /* if hit-count field > 0 OR resolve returned 0 → dispatch damage */
    if ((0 < (int)auStack_c88) || (iVar3 == 0)) {
      if (*(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) == 0) {
        FUN_007a4480(0, "VOG_DEBUG_STOP");
      }
      /* set flags low byte = 1 */
      uStack_e2c = CONCAT31((int3)((uint)uStack_e2c >> 8), 1);
      if (auStack_c88 == (uint8_t *)0x0) {
        iVar1 = *(int *)(param_1[1] + 4);
        uVar2 = *(uint32_t *)((int)param_1 + iVar1 + 0xb0);
        FUN_004d7e30(0, 0, uVar2, uVar2, 0, 0, 0,
                     *(uint32_t *)((int)param_1 + iVar1 + 0x164),
                     *(uint32_t *)((int)param_1 + iVar1 + 0x168),
                     *(uint32_t *)((int)param_1 + iVar1 + 0x16c),
                     *(uint32_t *)((int)param_1 + iVar1 + 0x170),
                     &stack0xfffff1cc);
      } else {
        iVar1 = *(int *)(param_1[1] + 4);
        FUN_004da2e0(auStack_c98, auStack_c88,
                     *(uint32_t *)((int)param_1 + iVar1 + 0xb0), 0, 0, 0,
                     *(uint32_t *)((int)param_1 + iVar1 + 0x164),
                     *(uint32_t *)((int)param_1 + iVar1 + 0x168),
                     *(uint32_t *)((int)param_1 + iVar1 + 0x16c),
                     *(uint32_t *)((int)param_1 + iVar1 + 0x170),
                     &stack0xfffff1cc);
      }
    }
    if (iVar3 != 0) {
      (**(code **)(*param_1 + 0x48))(iVar3, auStack_e28);
    }
    return 1;
  }
  return 0;
}
