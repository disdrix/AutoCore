# Raw capture: Skill_FormatFailureMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054fa20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0054fa20` |
| **Canonical name** | `Skill_FormatFailureMessage` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_FormatFailureMessage(eSkillResponse, pOutBuf, pCharacterCtx)
   
   Parameters:
     eSkillResponse - eSkillResponses enum
     pOutBuf        - output C string buffer
     pCharacterCtx  - optional character for summon-level messages
   
   Returns: pOutBuf
   
   VERIFIED all string cases 1-14, 0x12 from decompile switch. */

char * __cdecl Skill_FormatFailureMessage(int eSkillResponse,char *pOutBuf,void *pCharacterCtx)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  if (pOutBuf != (char *)0x0) {
    FUN_007a69d0();
    switch(eSkillResponse) {
    case 1:
      pcVar7 = (char *)FUN_007a6de0("Server checks failed!",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 2:
      pcVar7 = (char *)FUN_007a6de0("Skill failed.",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 3:
      pcVar7 = (char *)FUN_007a6de0("Cannot do that while wrecked!",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 4:
      pcVar7 = (char *)FUN_007a6de0("You don\'t have enough power!",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 5:
      pcVar7 = (char *)FUN_007a6de0("You can\'t do that with your current status.",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 6:
      pcVar7 = (char *)FUN_007a6de0("You\'re already actively using a skill!",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 7:
      pcVar7 = (char *)FUN_007a6de0("This skill is not ready to use again yet!",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 8:
      pcVar7 = (char *)FUN_007a6de0("You have too many of that summon.",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 9:
      pcVar7 = (char *)FUN_007a6de0("You can\'t do that while in the air.",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 10:
      pcVar7 = (char *)FUN_007a6de0("You have an active skill that prevents you from doing that.",
                                    0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 0xb:
      pcVar7 = (char *)FUN_007a6de0("You must be hidden to use this.",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 0xc:
      pcVar7 = (char *)FUN_007a6de0("You can\'t do this while hidden.",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 0xd:
      pcVar7 = (char *)FUN_007a6de0("Target out of range.",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 0xe:
      pcVar7 = (char *)FUN_007a6de0("Wrong target type.",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    default:
      pcVar7 = (char *)FUN_007a6de0("Unhandled reason for skill failure.",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    case 0x10:
      goto switchD_0054fa4a_caseD_10;
    case 0x12:
      pcVar7 = (char *)FUN_007a6de0("Target has just been stunted",0xffffffff);
      pcVar8 = pOutBuf;
      do {
        cVar1 = *pcVar7;
        *pcVar8 = cVar1;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      return pOutBuf;
    }
  }
  return "";
switchD_0054fa4a_caseD_10:
  if ((pCharacterCtx != (void *)0x0) &&
     (iVar2 = (**(code **)(*(int *)pCharacterCtx + 0x210))(0), iVar2 != 0)) {
    uVar10 = 0;
    (**(code **)(*(int *)pCharacterCtx + 0x210))(0,0);
    uVar3 = FUN_004c3f10(uVar10);
    (**(code **)(*(int *)pCharacterCtx + 0x210))(0);
    uVar4 = FUN_004c2e60();
    if (uVar4 <= uVar3) {
      (**(code **)(*(int *)pCharacterCtx + 0x210))(0);
      uVar10 = FUN_004c2e60();
      (**(code **)(*(int *)pCharacterCtx + 0x210))(0);
      iVar2 = FUN_004c2e60();
      uVar9 = 0;
      (**(code **)(*(int *)pCharacterCtx + 0x210))(0,iVar2 + 1);
      iVar2 = FUN_004c2eb0(uVar9);
      if (0x50 < iVar2) {
        uVar9 = FUN_007a6de0("summons at a time",0xffffffff);
        uVar5 = FUN_007a6de0("You can only have",0xffffffff);
        sprintf(pOutBuf,"%s %d %s.",uVar5,uVar10,uVar9);
        return pOutBuf;
      }
      uVar9 = FUN_007a6de0("until Level",0xffffffff);
      uVar5 = FUN_007a6de0("summons at a time",0xffffffff);
      uVar6 = FUN_007a6de0("You can only have",0xffffffff);
      sprintf(pOutBuf,"%s %d %s %s %d.",uVar6,uVar10,uVar5,uVar9,iVar2);
      return pOutBuf;
    }
  }
  pcVar7 = (char *)FUN_007a6de0("You have too many of that summon.",0xffffffff);
  pcVar8 = pOutBuf;
  do {
    cVar1 = *pcVar7;
    *pcVar8 = cVar1;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  return pOutBuf;
}
```

---

## Re-verify 2026-07-29 (append only; body above unchanged)

| Field | Value |
|---|---|
| Tool | Ghidra MCP `decompile_function` @ `0x0054fa20` |
| Function span | `0054fa20`�`0054fdf9` |
| Signature | `char * __cdecl Skill_FormatFailureMessage(int eSkillResponse, char *pOutBuf, void *pCharacterCtx)` |
| Callers | `Client_RecvSkillStatusEffect` `00811170`; `Client_RequestCastSkill` `00941590`; `Client_Skill_ResolveCastTarget` `0093b3a0`; `Client_StanceOrGadgetActivatePath` `0093a3d0`; `FUN_0091f6b0` |

### Sealed eSkillResponses ? English key (switch cases)

| Code | Hex | Dedicated case | English key / path |
|---:|---|---|---|
| 0 | 0x00 | no | falls **default** if formatted |
| 1 | 0x01 | yes | `Server checks failed!` |
| 2 | 0x02 | yes | `Skill failed.` |
| 3 | 0x03 | yes | `Cannot do that while wrecked!` |
| 4 | 0x04 | yes | `You don't have enough power!` |
| 5 | 0x05 | yes | `You can't do that with your current status.` |
| 6 | 0x06 | yes | `You're already actively using a skill!` |
| 7 | 0x07 | yes | `This skill is not ready to use again yet!` |
| 8 | 0x08 | yes | `You have too many of that summon.` |
| 9 | 0x09 | yes | `You can't do that while in the air.` |
| 10 | 0x0A | yes | `You have an active skill that prevents you from doing that.` |
| 11 | 0x0B | yes | `You must be hidden to use this.` |
| 12 | 0x0C | yes | `You can't do this while hidden.` |
| 13 | 0x0D | yes | `Target out of range.` |
| 14 | 0x0E | yes | `Wrong target type.` |
| 15 | 0x0F | no | **default** `Unhandled reason for skill failure.` (LocalRangeTargetCheck accuracy miss returns 0x0F) |
| 16 | 0x10 | yes | summon-cap **sprintf** path (`switchD_�_caseD_10`) |
| 17 | 0x11 | no | **default** unhandled (Recv treats 0x11 as cancel; format rare) |
| 18 | 0x12 | yes | `Target has just been stunted` |

### Case 0x10 sprintf templates (English fragments)

- When required level `> 0x50`: `"%s %d %s."` ? `You can only have` + maxCount + `summons at a time`
- Else (level known): `"%s %d %s %s %d."` ? `You can only have` + maxCount + `summons at a time` + `until Level` + level
- Fallback (no ctx / plant / count gate fail): same string as case 8

### Null / init

- `pOutBuf == null` ? return `""` (no write)
- Else `FUN_007a69d0()` once (locale singleton ensure), then switch; each key via `FUN_007a6de0(key, -1)` then byte-copy to `pOutBuf`

### Correction vs dual A 2026-07-23 summary

Prior dual A mis-labeled mid-table (claimed 9=active-skill, 10=hidden, 11=range, 14=stunted, 0x12=summon). **Authoritative mapping is the table above** (re-decompile 2026-07-29).

---

## Dual residual re-verify 2026-07-29 (append only)

| Field | Value |
|---|---|
| Tool | Ghidra MCP `decompile_function` + `get_function_by_address` + callers/callees @ `0x0054fa20` |
| Body vs frozen raw | **Identical** switch cases / keys / 0x10 path |
| Span | `0054fa20`–`0054fdf9` (confirmed) |
| Dual residual scratch | `docs/reconstruction/reviews/a_0054fa20.md` |
| Enum crosswalk source | `Documentation/PACKET STRUCTURES.md` `eSkillResponses` |

### Residual seals

1. **English keys 1–14 + 0x12 + default + 0x10 templates** remain High.
2. **0x10** = `SUMMONCOUNT_TOTAL` summon sprintf; **0x12** = `TOO_SOON` / stunted — wave2 “0x12 summon” falsified.
3. Default residual set includes **0, 0x0F (`AI_DIDNT_CAST`), 0x11 (`CANCELLED_ACTIVE`), 99 (`DEATHCAST`)**.
4. Name≠UX (CORPSE/wrecked, FACTION/wrong target, TOO_SOON/stunted) documented; UX keys authoritative for AutoCore toasts.
5. Leave-FUN: `FUN_007a69d0`, `FUN_007a6de0`, `FUN_004c3f10`, `FUN_004c2e60`, `FUN_004c2eb0`.
