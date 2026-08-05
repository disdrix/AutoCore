# Annotated low-level: CVOGHBAICreatureBase_OnHeartBeat

| Field | Value |
|---|---|
| Stable ID | a_005d0310 |
| VA | 0x005d0310 |
| System | unknown |
| Date | 2026-07-23 |
| Refined | manager-pass industrial |

## Purpose (manager refine)

Creature AI heartbeat.

## Plate / prior RE notes

`
WARNING: Removing unreachable block (ram,0x005d07cd)
`

## Named callees (decompiler)

- CVOGHBAICreatureBase_OnHeartBeat
- FUN_0076cf00
- FUN_0076cef0
- CVOGHBBase_RescheduleAfterFire
- FUN_005cedf0
- CVOGReaction_RandomUnitScalar
- FUN_005cd220
- FUN_005cc680
- FUN_005ccff0
- AI_CheckSlotTimerReady
- FUN_005ccf00
- FUN_00638be0
- FUN_005ce990

## Machine-level notes

- Source: raw capture for a_005d0310.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.
- Manager refine: case table + callees extracted; full dual review still open.

## Pseudocode (annotated copy of raw)

`c
/* WARNING: Removing unreachable block (ram,0x005d07cd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* AI heartbeat tick for creature base behavior. Called every tick from Client_LocalDiscoveryTick.
   
   State machine via owner+0x26c (0=idle/patrol, 1=engage, 2=combat).
   Idle: Returns to normal location via ReturnToNormalLocation.
   Engage: Timed transition to combat with speed check.
   Combat: Random chance to fire weapons and pursue target.
   
   Key offsets on this:
   +0x6: Owner creature pointer
   +0x9: Min combat range
   +0xa: Max combat range
   +0xc: Current distance to target
   +0xd: Timer (compared to DAT_00a0f518 threshold)
   +0xe: Distance offset for combat range check
   +0x14-0x17: Current position (xyz)
   +0x18: State flag 1 (char)
   +0x19: Owner creature struct pointer
   +0x1a: Secondary state flag
   +0x1e-0x26: Timers array (3 entries, step 3)
   +0x2e: Combat counter (byte)
   
   Owner offsets (this+0x19):
   +0x10: Flag (char, 0=active)
   +0x26c: Behavior state (char, 0=idle, 1=engage, 2=combat)
   +0x278: Death state (char, 0=alive, 1=dying, 2=dead, 3=respawn)
   +0x279: At destination flag
   +0x26c: Behavior state
   +0x250: Vehicle reference pointer
   +0x305: Idle flag
   +0x306: Secondary idle flag
   +0x307: Tertiary idle flag */

void __thiscall CVOGHBAICreatureBase_OnHeartBeat(void *this,undefined4 *pResult)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  float *pfVar8;
  undefined4 *puVar9;
  uint uVar10;
  char *pcVar11;
  ushort uVar12;
  uint *pOutNextDelayMs;
  uint *extraout_EDX;
  uint *extraout_EDX_00;
  uint *pOutNextDelayMs_00;
  uint unaff_EDI;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a6fce;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  FUN_0076cf00("CVOGHBAICreatureBase::OnHeartBeat()");
  local_14 = 0;
                    /* // Bail if owner (this+0x6) is null */
  if (*(int *)((int)this + 0x18) == 0) {
    *pResult = DAT_00af41b0;
    local_14 = 0xffffffff;
    FUN_0076cef0();
    ExceptionList = local_1c;
    return;
  }
                    /* // Check timer (this+0xd) against threshold DAT_00a0f518 */
  if (*(float *)((int)this + 0x34) == g_flZero) {
LAB_005d03c1:
                    /* // Timer expired or in combat range: enter main behavior state machine */
    *(undefined1 *)(*(int *)((int)this + 100) + 0x307) = 0;
    iVar6 = *(int *)((int)this + 100);
                    /* // If no active target and no vehicle: set idle state and bail */
    if ((*(int *)(iVar6 + 8) == 0) && (*(int *)(iVar6 + 0x250) == 0)) {
      *(undefined4 *)((int)this + 8) = 0xffffffff;
      CVOGHBBase_RescheduleAfterFire(this,pOutNextDelayMs);
      goto LAB_005d081c;
    }
                    /* // Check distance to target against combat range */
    fVar3 = (float)(int)g_dwClientTickMs;
    if ((int)g_dwClientTickMs < 0) {
      fVar3 = fVar3 + _DAT_00aaa5dc;
    }
    if (*(float *)((int)this + 0x30) < fVar3 * g_flMsToSeconds_Inferred) {
      *(undefined1 *)(iVar6 + 0x305) = 0;
                    /* // Check behavior state at owner+0x26c (0=idle, 1=engage, 2=combat) */
      *(undefined1 *)(*(int *)((int)this + 100) + 0x306) = 0;
    }
    iVar6 = *(int *)((int)this + 100);
    if (*(char *)(iVar6 + 0x207) == '\0') {
      if (*(char *)((int)this + 0x6d) != '\0') {
        if (*(int *)(iVar6 + 0x250) == 0) {
          piVar1 = (int *)(*(int *)(*(int *)((int)this + 0x18) + 0xa4) + 0x20);
          *piVar1 = *piVar1 + -1;
        }
        else {
          piVar1 = (int *)(*(int *)(*(int *)((int)this + 0x18) + 0xa4) + 0x24);
          *piVar1 = *piVar1 + -1;
        }
        *(undefined1 *)((int)this + 0x6d) = 0;
        *(undefined4 *)((int)this + 0x68) = 0;
      }
      iVar2 = *(int *)((int)this + 100);
      iVar6 = *(int *)(*(int *)(iVar2 + 4) + 4) + iVar2;
      if (*(char *)(*(int *)(iVar6 + 0xa8) + 0x7e) == '\0') {
        if ((*(int *)(iVar6 + 0x18) == 0) && (*(char *)(iVar2 + 0x10) == '\0')) {
          FUN_005cedf0();
          if (*(char *)((int)this + 0x60) == '\0') {
            cVar4 = (**(code **)(*(int *)this + 0x54))();
            if (cVar4 == '\0') {
              iVar6 = *(int *)this;
              uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) +
                                            4 + *(int *)((int)this + 100)) + 0x1a0))(0);
              (**(code **)(iVar6 + 0x4c))(uVar7);
            }
          }
          else {
            (**(code **)(*(int *)this + 0x4c))((int)this + 0x40,1);
          }
          iVar6 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar6 + 0xc)) {
            *(undefined4 *)(iVar6 + 0xc) = 0;
          }
          uVar12 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);
          *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
          iVar6 = *(int *)((int)this + 0x24);
        }
        else {
                    /* // Idle state: return to normal patrol location */
          if (*(char *)(iVar2 + 0x279) == '\0') {
            if ((*(char *)(iVar2 + 0x26c) != '\0') ||
               (pfVar8 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 +
                                                       iVar2) + 0x1a0))(),
               (g_flMsToSeconds_Inferred < ABS(*(float *)((int)this + 0x58) - pfVar8[2]) ||
               g_flMsToSeconds_Inferred < ABS(*(float *)((int)this + 0x54) - pfVar8[1])) ||
               g_flMsToSeconds_Inferred < ABS(*(float *)((int)this + 0x50) - *pfVar8))) {
              uVar5 = 0;
            }
            else {
              uVar5 = 1;
            }
            *(undefined1 *)(*(int *)((int)this + 100) + 0x279) = uVar5;
          }
          FUN_005cd220();
          iVar6 = CVOGReaction_RandomUnitScalar();
          if (0xfffff < *(int *)(iVar6 + 0xc)) {
            *(undefined4 *)(iVar6 + 0xc) = 0;
          }
          uVar12 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);
          *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
          iVar6 = *(int *)((int)this + 0x28);
        }
        *(int *)((int)this + 8) = (int)((longlong)(ulonglong)uVar12 % (longlong)iVar6) / 2 + iVar6;
        puVar9 = (undefined4 *)
                 (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                                      *(int *)((int)this + 100)) + 0x1a0))();
        *(undefined4 *)((int)this + 0x50) = *puVar9;
        *(undefined4 *)((int)this + 0x54) = puVar9[1];
        *(undefined4 *)((int)this + 0x58) = puVar9[2];
        pOutNextDelayMs_00 = (uint *)puVar9[3];
        *(uint **)((int)this + 0x5c) = pOutNextDelayMs_00;
        goto LAB_005d0809;
      }
      if (*(char *)(iVar2 + 0x278) == '\x02') {
        (**(code **)(*(int *)this + 0x20))();
      }
      else {
        (**(code **)(*(int *)this + 0x28))();
        FUN_005cc680();
                    /* // Engage state: timer-based transition to combat */
        if ((*(int *)(*(int *)((int)this + 0x18) + 0xa0) == 0) ||
           (*(char *)(*(int *)((int)this + 100) + 0x278) == '\x01')) {
          FUN_005ccff0();
        }
        FUN_005cc680();
      }
      (**(code **)(*(int *)this + 0x50))();
      if (*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 0xa4 +
                  *(int *)((int)this + 100)) != 0) {
        iVar6 = CVOGReaction_RandomUnitScalar();
        if (0xfffff < *(int *)(iVar6 + 0xc)) {
          *(undefined4 *)(iVar6 + 0xc) = 0;
        }
        uVar12 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);
        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
                    /* // Combat state: random chance to fire and pursue */
        *(int *)((int)this + 8) =
             (int)((longlong)(ulonglong)uVar12 % (longlong)*(int *)((int)this + 0x24)) / 2 +
             *(int *)((int)this + 0x24);
      }
      FUN_005cd220();
      puVar9 = (undefined4 *)
               (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                                    *(int *)((int)this + 100)) + 0x1a0))();
      *(undefined4 *)((int)this + 0x50) = *puVar9;
      *(undefined4 *)((int)this + 0x54) = puVar9[1];
      *(undefined4 *)((int)this + 0x58) = puVar9[2];
      *(undefined4 *)((int)this + 0x5c) = puVar9[3];
      uVar10 = AI_CheckSlotTimerReady(this,(void *)0x0,unaff_EDI);
      if ((char)uVar10 != '\0') {
        iVar6 = CVOGReaction_RandomUnitScalar();
        if (0xfffff < *(int *)(iVar6 + 0xc)) {
          *(undefined4 *)(iVar6 + 0xc) = 0;
        }
        uVar12 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);
        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
        if ((uVar12 & 1) == 0) {
          FUN_005ccf00();
        }
      }
      FUN_00638be0();
      pOutNextDelayMs_00 = extraout_EDX_00;
    }
    else {
      if (*(char *)((int)this + 0x6d) == '\0') {
        if (*(int *)(iVar6 + 0x250) == 0) {
          piVar1 = (int *)(*(int *)(*(int *)((int)this + 0x18) + 0xa4) + 0x20);
          *piVar1 = *piVar1 + 1;
        }
        else {
          piVar1 = (int *)(*(int *)(*(int *)((int)this + 0x18) + 0xa4) + 0x24);
          *piVar1 = *piVar1 + 1;
        }
        *(undefined1 *)((int)this + 0x6d) = 1;
        iVar6 = CVOGReaction_RandomUnitScalar();
        if (0xfffff < *(int *)(iVar6 + 0xc)) {
          *(undefined4 *)(iVar6 + 0xc) = 0;
        }
        uVar12 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);
        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
        *(uint *)((int)this + 8) = ((uint)uVar12 % 1000) / 2 + 1000;
      }
      FUN_005ce990();
      pOutNextDelayMs_00 = extraout_EDX;
    }
    pcVar11 = (char *)((int)this + 0x78);
    iVar6 = 3;
    do {
      uVar10 = g_dwClientTickMs;
      if (*pcVar11 != '\0') {
        *(uint *)(pcVar11 + -8) = g_dwClientTickMs;
        *pcVar11 = '\0';
        pOutNextDelayMs_00 = (uint *)uVar10;
      }
      pcVar11 = pcVar11 + 0xc;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  else {
    fVar3 = (float)(int)g_dwClientTickMs;
    if ((int)g_dwClientTickMs < 0) {
      fVar3 = fVar3 + _DAT_00aaa5dc;
    }
    pOutNextDelayMs_00 = pOutNextDelayMs;
    if (*(float *)((int)this + 0x34) <=
        fVar3 * g_flMsToSeconds_Inferred - *(float *)((int)this + 0x38)) goto LAB_005d03c1;
  }
LAB_005d0809:
  CVOGHBBase_RescheduleAfterFire(this,pOutNextDelayMs_00);
LAB_005d081c:
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_1c;
  return;
}
`

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Dual independent reconstruction review for this manager unit.
