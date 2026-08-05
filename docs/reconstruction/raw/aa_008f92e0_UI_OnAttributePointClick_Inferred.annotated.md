# Annotated low-level: UI_OnAttributePointClick_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008f92e0` |
| VA | `0x008f92e0`–`0x008f96bc` |
| System | missions-progression / character sheet UI |
| Date | 2026-07-29 (dual A/B refresh; prior scaffold 2026-07-23) |

## Machine-level notes

- Source: raw capture + live Ghidra decompile / entry bytes 2026-07-29.
- `__thiscall`: ECX = UI host; stack `eventType`, `controlId`; `ret 8`.
- Local character: `DAT_00d1b6d8`. Free pool: `char+0x6CE` via `CVOGCharacter_AddSkillPoints` (**assign** `pool-1`).
- Product toast: `"You cannot apply attribute points while in an arena!"` when `DAT_00d1b644+0xF6` set.
- Control switch base `0x9C40`; primary spend when `eventType == 8`.
- Sector notify: opcode **`0x205A`**, size 8, flags per stat (see table).
- Single DATA xref `0x00a35a2c` (handler table), not code CALL sites.
- Dual reviews: `reviews/A_aa_008f92e0_*`, `reviews/B_aa_008f92e0_*`.

### Control → offset → flag

| controlId | char offset | flags | extras |
|-----------|-------------|-------|--------|
| `0x9C40` | — | — | `FUN_007fca10` only |
| `0x9C41` | `+0x13E` | `0x1` | — |
| `0x9C42` | `+0x13C` | `0x10000` | vehicle combat pools + max heat; optional `DAT_00d1b8b8` UI |
| `0x9C43` | `+0x140` | `0x100` | char vtbl `+0x5C`; optional `DAT_00d1b8b8` |
| `0x9C44` | `+0x142` | `0x1000000` | — |

Getters soft-cap **200**; setters write without clamp.

## Pseudocode (annotated)

```c
// UI_OnAttributePointClick_Inferred  @ 0x008f92e0
// thiscall (UiHost* this, int eventType, uint controlId) -> uint (0/1), ret 8

undefined4 __thiscall UI_OnAttributePointClick_Inferred(int *uiHost, int eventType, undefined4 controlId)
{
  RE_VehicleCombatPoolFields *pVehicle;
  char onlineOk;
  int cur;
  undefined4 defRet;
  undefined4 pkt_opcode;   // uStack_8
  undefined4 pkt_flags;    // uStack_4

  if (DAT_00d1b6d8 == (int *)0x0) {
    return 0;   // no local character
  }

  // switch (controlId - 0x9C40) cases 0..4
  switch(controlId) {
  case 40000: /* 0x9C40 */
    if (eventType == 8) {
      FUN_007fca10();           // non-spend UI action
      return 1;
    }
    break;

  case 0x9c41: /* +0x13E, flag 1 */
    if (eventType == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) {
        return 1;               // no free points — still "handled"
      }
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) {
LAB_arena:
        FUN_007fdfb0(&DAT_00d1a840,
                     "You cannot apply attribute points while in an arena!",
                     0xffffffff, 1, 0);
        return 1;
      }
      // ECX = local char (elided): get +0x13E soft-capped, set +1
      cur = FUN_0040de30();     // *(i16*)(char+0x13E), max 200
      FUN_004c2ef0(cur + 1);    // store +0x13E
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      Client_RefreshMissionDialogChrome();
      (**(code **)(*uiHost + 0x448))();
      (**(code **)(*uiHost + 0x34c))();
      onlineOk = FUN_00807440();
      if (onlineOk == '\0') {
        return 1;               // local apply only
      }
      pkt_flags = 1;
LAB_send:
      pkt_opcode = 0x205a;
      Client_SendSectorPacket(&DAT_00d1a840, 8, &pkt_opcode);
      return 1;
    }
    break;

  case 0x9c42: /* +0x13C, flag 0x10000 — combat/heat-linked */
    if (eventType == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) return 1;
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) goto LAB_arena;
      cur = FUN_0040de10();     // +0x13C
      FUN_004c2ee0(cur + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      if ((void *)DAT_00d1b6d8[0x94] != (void *)0x0) {          // char+0x250 vehicle*
        Vehicle_RecalcCombatPools((void *)DAT_00d1b6d8[0x94]);
      }
      if (DAT_00d1b6d8[0x94] != 0) {
        pVehicle = (RE_VehicleCombatPoolFields *)DAT_00d1b6d8[0x94];
        cur = Vehicle_CalcHeatMaximum(pVehicle);
        pVehicle->nMaxHeat = cur;
      }
      Client_RefreshMissionDialogChrome();
      (**(code **)(*uiHost + 0x448))();
      (**(code **)(*uiHost + 0x34c))();
      if ((DAT_00d1b8b8 != (int *)0x0) &&
         (onlineOk = (**(code **)(*DAT_00d1b8b8 + 0x3d8))(), onlineOk != '\0')) {
        FUN_008801b0(DAT_00d1b8b8);
      }
      onlineOk = FUN_00807440();
      if (onlineOk == '\0') return 1;
      pkt_flags = 0x10000;
      goto LAB_send;
    }
    break;

  case 0x9c43: /* +0x140, flag 0x100 */
    if (eventType == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) return 1;
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) goto LAB_arena;
      cur = FUN_0040ddf0();     // +0x140
      FUN_004c2f00(cur + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      (**(code **)(*DAT_00d1b6d8 + 0x5c))();   // character post-stat hook
      Client_RefreshMissionDialogChrome();
      (**(code **)(*uiHost + 0x448))();
      (**(code **)(*uiHost + 0x34c))();
      if ((DAT_00d1b8b8 != (int *)0x0) &&
         (onlineOk = (**(code **)(*DAT_00d1b8b8 + 0x3d8))(), onlineOk != '\0')) {
        FUN_008801b0(DAT_00d1b8b8);
      }
      onlineOk = FUN_00807440();
      if (onlineOk == '\0') return 1;
      pkt_flags = 0x100;
      goto LAB_send;
    }
    break;

  case 0x9c44: /* +0x142, flag 0x1000000 */
    if (eventType == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) return 1;
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) {
        FUN_007fdfb0(&DAT_00d1a840,
                     "You cannot apply attribute points while in an arena!",
                     0xffffffff, 1, 0);
        return 1;
      }
      cur = FUN_0040ddd0();     // +0x142
      FUN_004c2f10(cur + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      Client_RefreshMissionDialogChrome();
      (**(code **)(*uiHost + 0x448))();
      (**(code **)(*uiHost + 0x34c))();
      onlineOk = FUN_00807440();
      if (onlineOk == '\0') return 1;
      pkt_flags = 0x1000000;
      goto LAB_send;
    }
  }

  // Unhandled control or non-click event on known controls
  switch(eventType) {
  case 7:
  case 8:
  case 0xd:
  case 0xe:
    return 1;
  default:
    defRet = FUN_0087b500(eventType, controlId);  // this = uiHost
    return defRet;
  }
}
```

## Open

- Product names of four stats; handler-table dialog class; server authority of `0x205A`; glossary `+0x6CE` vs `+0x6CC`.
