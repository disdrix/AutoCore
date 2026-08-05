// =============================================================================
// UI_OnAttributePointClick_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008f92e0
// Address:   0x008f92e0 – 0x008f96bc  (autoassault.exe, image base 0x400000)
// System:    missions-progression / character sheet UI (client)
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B (wave6-attrpt)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      docs/reconstruction/reviews/A_aa_008f92e0_UI_OnAttributePointClick_Inferred.md
//            docs/reconstruction/reviews/B_aa_008f92e0_UI_OnAttributePointClick_Inferred.md
// =============================================================================

/*
 * Behavioral notes:
 * - UI message handler (data-dispatched via ptr @ 0x00a35a2c).
 * - thiscall: ECX = UI host; eventType @ stack0; controlId @ stack1; ret 8.
 * - Free spendable pool: int16 at localChar+0x6CE via CVOGCharacter_AddSkillPoints (assign).
 * - Four stats: +0x13C / +0x13E / +0x140 / +0x142 (control IDs 0x9C42/41/43/44 — not linear).
 * - Soft get cap 200; setters store get()+1 without write clamp.
 * - Arena block: DAT_00d1b644+0xF6 with product toast string.
 * - Optional sector packet 0x205A (8 bytes: opcode + per-stat flags).
 * - Distinct from skill-train opcodes 0x2059 / 0x2062.
 * - Distinct from CVOGCharacter_AddAttributePoints pool at +0x6CC (not used here).
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw / live decompile.
 */

uint32_t /* width from decompiler */ __thiscall UI_OnAttributePointClick_Inferred(
    int *param_1 /* UiHost* this */,
    int param_2 /* eventType */,
    uint32_t /* width from decompiler */ param_3 /* controlId */)
{
  RE_VehicleCombatPoolFields *pVehicle;
  char cVar1;
  int iVar2;
  uint32_t /* width from decompiler */ uVar3;
  uint32_t /* width from decompiler */ uStack_8; /* packet opcode */
  uint32_t /* width from decompiler */ uStack_4; /* packet flags */

  if (DAT_00d1b6d8 == (int *)0x0) {
    return 0;
  }
  switch(param_3) {
  case 40000: /* 0x9C40 — non-spend */
    if (param_2 == 8) {
      FUN_007fca10();
      return 1;
    }
    break;
  case 0x9c41: /* char+0x13E, flags=1 */
    if (param_2 == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) {
        return 1;
      }
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) {
LAB_008f9342:
        FUN_007fdfb0(&DAT_00d1a840,"You cannot apply attribute points while in an arena!",0xffffffff
                     ,1,0);
        return 1;
      }
      iVar2 = FUN_0040de30(); /* get +0x13E, soft max 200; ECX=localChar elided */
      FUN_004c2ef0(iVar2 + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      Client_RefreshMissionDialogChrome();
      (**(code **)(*param_1 + 0x448))();
      (**(code **)(*param_1 + 0x34c))();
      cVar1 = FUN_00807440(); /* sector-send gate */
      if (cVar1 == '\0') {
        return 1;
      }
      uStack_4 = 1;
LAB_008f9649:
      uStack_8 = 0x205a;
      Client_SendSectorPacket(&DAT_00d1a840,8,&uStack_8);
      return 1;
    }
    break;
  case 0x9c42: /* char+0x13C, flags=0x10000; vehicle combat/heat */
    if (param_2 == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) {
        return 1;
      }
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) goto LAB_008f9342;
      iVar2 = FUN_0040de10(); /* get +0x13C */
      FUN_004c2ee0(iVar2 + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      if ((void *)DAT_00d1b6d8[0x94] != (void *)0x0) { /* char+0x250 vehicle* */
        Vehicle_RecalcCombatPools((void *)DAT_00d1b6d8[0x94]);
      }
      if (DAT_00d1b6d8[0x94] != 0) {
        pVehicle = (RE_VehicleCombatPoolFields *)DAT_00d1b6d8[0x94];
        iVar2 = Vehicle_CalcHeatMaximum(pVehicle);
        pVehicle->nMaxHeat = iVar2;
      }
      Client_RefreshMissionDialogChrome();
      (**(code **)(*param_1 + 0x448))();
      (**(code **)(*param_1 + 0x34c))();
      if ((DAT_00d1b8b8 != (int *)0x0) &&
         (cVar1 = (**(code **)(*DAT_00d1b8b8 + 0x3d8))(), cVar1 != '\0')) {
        FUN_008801b0(DAT_00d1b8b8);
      }
      cVar1 = FUN_00807440();
      if (cVar1 == '\0') {
        return 1;
      }
      uStack_4 = 0x10000;
      goto LAB_008f9649;
    }
    break;
  case 0x9c43: /* char+0x140, flags=0x100; char vtbl+0x5C */
    if (param_2 == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) {
        return 1;
      }
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) goto LAB_008f9342;
      iVar2 = FUN_0040ddf0(); /* get +0x140 */
      FUN_004c2f00(iVar2 + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      (**(code **)(*DAT_00d1b6d8 + 0x5c))();
      Client_RefreshMissionDialogChrome();
      (**(code **)(*param_1 + 0x448))();
      (**(code **)(*param_1 + 0x34c))();
      if ((DAT_00d1b8b8 != (int *)0x0) &&
         (cVar1 = (**(code **)(*DAT_00d1b8b8 + 0x3d8))(), cVar1 != '\0')) {
        FUN_008801b0(DAT_00d1b8b8);
      }
      cVar1 = FUN_00807440();
      if (cVar1 == '\0') {
        return 1;
      }
      uStack_4 = 0x100;
      goto LAB_008f9649;
    }
    break;
  case 0x9c44: /* char+0x142, flags=0x1000000 */
    if (param_2 == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) {
        return 1;
      }
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) {
        FUN_007fdfb0(&DAT_00d1a840,"You cannot apply attribute points while in an arena!",0xffffffff
                     ,1,0);
        return 1;
      }
      iVar2 = FUN_0040ddd0(); /* get +0x142 */
      FUN_004c2f10(iVar2 + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      Client_RefreshMissionDialogChrome();
      (**(code **)(*param_1 + 0x448))();
      (**(code **)(*param_1 + 0x34c))();
      cVar1 = FUN_00807440();
      if (cVar1 == '\0') {
        return 1;
      }
      uStack_4 = 0x1000000;
      goto LAB_008f9649;
    }
  }
  switch(param_2) {
  case 7:
  case 8:
  case 0xd:
  case 0xe:
    return 1;
  default:
    uVar3 = FUN_0087b500(param_2,param_3);
    return uVar3;
  }
}
