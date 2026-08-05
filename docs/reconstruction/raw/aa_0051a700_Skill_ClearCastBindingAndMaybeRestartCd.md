# Raw capture: Skill_ClearCastBindingAndMaybeRestartCd

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a700` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051a700` |
| **Canonical name** | `Skill_ClearCastBindingAndMaybeRestartCd` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_ClearCastBindingAndMaybeRestartCd(...)
   
   Clears active-cast binding matching skillId+TFID; if skill+0x61c set,
   Skill_StartCastAgainHeartbeat(skill, 0).
   
   INFERRED: full param order from call sites. */

void __thiscall
Skill_ClearCastBindingAndMaybeRestartCd
          (void *this,void *pSkill,int nSkillId,int nTfidLo,int nTfidHi,char bGlobal)

{
  int iVar1;
  void *pOwnerCtx;
  void **ppvVar2;
  void **ppvVar3;
  void *nChargeDelayMs;
  void *local_4;
  
  ppvVar3 = &pSkill;
  ppvVar2 = &local_4;
  local_4 = this;
  FUN_00518c20(ppvVar2,ppvVar3);
  FUN_0051c150(ppvVar2,ppvVar3);
  iVar1 = FUN_00518c20();
  if ((((local_4 != *(void **)(iVar1 + 4)) && (*(int *)((int)local_4 + 0x18) == nSkillId)) &&
      (*(int *)((int)local_4 + 0x1c) == nTfidLo)) &&
     (*(char *)((int)local_4 + 0x20) == (char)nTfidHi)) {
    FUN_00518c20(&nSkillId,local_4);
    FUN_0051cb40();
  }
  nChargeDelayMs = pSkill;
  pOwnerCtx = (void *)(**(code **)(*(int *)this + 0x234))();
  if ((pOwnerCtx != (void *)0x0) && (*(char *)((int)pOwnerCtx + 0x61c) != '\0')) {
    Skill_StartCastAgainHeartbeat(this,pOwnerCtx,(void *)0x0,(int)nChargeDelayMs);
  }
  return;
}
```

---

## Residual PE body (2026-07-29 — append only)

| Field | Value |
|---|---|
| **Tool** | PE file read (`autoassault.exe` `.text` RVA `0x11a700` / file `0x119b00`) |
| **Ghidra MCP** | Unavailable this session |
| **Authority** | Machine bytes for ABI/CF; original decompile body above retained |

```
51 56 8B F1 8D 44 24 0C 50 8D 4C 24 08 51 8B CE E8 0B E5 FF FF
8B C8 E8 34 1A 00 00 8B CE E8 FD E4 FF FF 8B 4C 24 04 3B 48 04
74 2F 8B 51 18 3B 54 24 10 75 26 8B 41 1C 3B 44 24 14 75 1D 8A 51 20
3A 54 24 18 75 14 51 8D 44 24 14 50 8B CE E8 CC E4 FF FF 8B C8
E8 E5 23 00 00 8B 44 24 0C 8B 16 50 8B CE FF 92 34 02 00 00 85 C0
74 13 80 B8 1C 06 00 00 00 74 0A 6A 00 50 8B CE E8 7F EA FF FF
5E 59 C2 14 00
```

Seals (see dual A/B + `reviews/a_0051a700.md`): `RET 0x14`; partial TFID erase; `vtbl+0x234(skillId)`; `+0x61c != 0` ? StartCastAgain charge 0.
