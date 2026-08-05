# Raw capture: CVOGCharacter_CheckMissionPrerequisites

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536540` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00536540` |
| **Canonical name** | `CVOGCharacter_CheckMissionPrerequisites` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGCharacter_CheckMissionPrerequisites
   
   Gate award: not active, not completed, race/faction/level/prereq missions.
   May GiveMission + optional CompleteMissionObjectives.
   Used by auto-missions and offer eligibility paths. */

char __thiscall
CVOGCharacter_CheckMissionPrerequisites
          (void *this,uint uMissionID,char bAutoComplete,char bCheckLevel)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  undefined1 uStack_4;
  
                    /* // Check if mission already active (hash at this+0x540) */
  iVar4 = *(int *)(*(int *)(*(int *)(*(int *)((int)this + 0x540) + 0x10) +
                           (*(uint *)(*(int *)((int)this + 0x540) + 8) & uMissionID) * 4) + 4);
  do {
    if (iVar4 == 0) {
LAB_0053656f:
                    /* // Look up mission definition in hash table */
      puVar1 = (undefined4 *)FUN_0053fff0();
                    /* // bCheckLevel!=0 path: verify race/faction eligibility */
      if ((((void *)*puVar1 != (void *)0x0) &&
          (pvVar2 = CNDHash_LookupByKey((void *)*puVar1,uMissionID), pvVar2 != (void *)0x0)) &&
         ((bCheckLevel == '\0' ||
          ((iVar4 = *(int *)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xac + (int)this) +
                            0x3c),
           *(ushort *)((int)pvVar2 + 0x90) == (ushort)*(byte *)(iVar4 + 0x532) &&
           ((*(ushort *)((int)pvVar2 + 0x92) == 0xffff ||
            (*(ushort *)((int)pvVar2 + 0x92) == (ushort)*(byte *)(iVar4 + 0x531))))))))) {
                    /* // Direct award path: check prereqs, level, then award */
        if (*(int *)((int)pvVar2 + 0x124) == 0) {
          puVar5 = (uint *)((int)pvVar2 + 0x9c);
          iVar4 = 4;
          do {
                    /* // Recursively check up to 4 prerequisite missions (at mission +0x9c) */
            if (*puVar5 != 0xffffffff) {
              CVOGCharacter_CheckMissionPrerequisites(this,*puVar5,'\x01',bCheckLevel);
            }
            puVar5 = puVar5 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        iVar4 = *(int *)((int)pvVar2 + 0x94);
                    /* // Get character level (vtable +0x27c) and compare to mission min level
                       (+0x94) */
        iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this) + 0x27c
                            ))();
        if (iVar3 < iVar4) {
          iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this) +
                              0x27c))();
                    /* // Award XP to bridge level gap */
          iVar4 = Experience_XpToReachRelativeLevel(this,iVar4 - iVar3);
          (**(code **)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this) + 0x27c))();
          CVOGReaction_AddExperience(this,iVar4,PacketOrNonKill);
        }
        uStack_10 = *(undefined4 *)((int)pvVar2 + 0x88);
        uStack_c = *(undefined4 *)((int)pvVar2 + 0xfc);
        uStack_8 = uMissionID;
        uStack_4 = 0;
        uStack_30 = 0xffffffff;
        uStack_2c = 0xffffffff;
        uStack_28 = 0xffffffff;
        uStack_24 = 0xffffffff;
        uStack_20 = 0xffffffff;
        uStack_1c = 0xffffffff;
        uStack_18 = 0xffffffff;
        uStack_14 = 0xffffffff;
        FUN_0052c700(uMissionID,&uStack_30);
                    /* // Award mission to character */
        CVOGReaction_GiveMission(uMissionID);
        if (bAutoComplete != '\0') {
                    /* // Auto-complete all mission objectives */
          CVOGCharacter_CompleteMissionObjectives(uMissionID,1);
        }
        return '\x01';
      }
      return '\0';
    }
    if (uMissionID == *(uint *)(iVar4 + 0x10)) {
      if ((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) {
        if (bAutoComplete != '\0') {
          CVOGCharacter_CompleteMissionObjectives(uMissionID,1);
          return '\x01';
        }
        return '\0';
      }
      goto LAB_0053656f;
    }
    iVar4 = *(int *)(iVar4 + 0xc);
  } while( true );
}
```

---

## Versioned append: fresh decompile 2026-07-29

| Field | Value |
|---|---|
| **Timestamp** | `2026-07-29` |
| **Tool** | Ghidra MCP `decompile_function` @ `0x00536540` |
| **Result** | **CF identical** to 2026-07-23 body (plate comments, active-hash walk, `LAB_0053656f` award path, recursive prereq with `autoComplete=1`, XP bridge, `FUN_0052c700` / `GiveMission` / `CompleteMissionObjectives`, returns `'\x01'` / `'\0'`) |
| **Caller evidence (superseded by edges append below)** | Ghidra callers list then showed `FUN_00536740` only; xrefs also include client sites `0x00950915` / `0x00954575` (see edges append) |

No rewrite of the authoritative section above; this records re-decompile confirmation only. Fresh body matches the 2026-07-23 listing line-for-line in control flow and callees (Ghidra plate comments retained).

---

## Versioned append: dual residual edges 2026-07-29

| Field | Value |
|---|---|
| **Timestamp** | `2026-07-29` |
| **Tools** | Ghidra `get_xrefs_to` / `get_assembly_context` / `decompile_function` / `read_memory` (no `disassemble_bytes`) |
| **OWN** | dual residual edges only — no WORK_QUEUE / RESUME / CHANGE_LOG |

### Call sites to `0x00536540` (complete)

| Site VA | Container | autoComplete | checkLevel | Evidence |
|---|---|---|---|---|
| `0x00536631` | self recurse | `1` | parent (`PUSH EDX`) | asm before CALL |
| `0x005368ef` | `FUN_00536740` | `1` | `1` | decompile + asm `PUSH 1; PUSH 1` |
| `0x00950915` | client cmd (Ghidra unnamed body; near GiveMission `0x005327c0`) | `1` | `0` | asm `PUSH 0; PUSH 1; PUSH EAX`; ECX=`[EDI+0xe98]` |
| `0x00954575` | debug force-add entry `0x00954510` | `0` | `0` | asm `PUSH 0; PUSH 0; PUSH EDI`; string `Forced add mission (%i)` @ `0x00a28af4` |

### Helper / field seals (this unit)

| Item | Seal | Conf |
|---|---|---|
| `def+0x124` | product **`RequirementsNegative`** (`Mission.Read`); recurse award only when `==0` | **High** |
| `def+0x88` prep | product **NPC** | **High** |
| `def+0xfc` prep | product **AutoAssign** (i16 in WAD) | **High** |
| `FUN_0052c700` | character thiscall; copy 12 dwords of prep into map near `char+0x50c`, key=missionId | **High** shape |
| `FUN_0053fff0` | returns lazy table pointer at object `+0xf18` | **High** shape |

Dual A/B + function record updated; authoritative raw body above unchanged.
