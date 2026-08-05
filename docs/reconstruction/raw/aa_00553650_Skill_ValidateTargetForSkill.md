# Raw capture: Skill_ValidateTargetForSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553650` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00553650` |
| **Canonical name** | `Skill_ValidateTargetForSkill` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_ValidateTargetForSkill(skill, targetObj)

   

   Calls skill handler vtable+0x44; returns 1 if valid, 0 if rejected.

   On reject may queue a UI/feedback callback (FUN_004e2600). */



int __thiscall Skill_ValidateTargetForSkill(void *this,void *pSkill,void *pTarget)



{

  int iVar1;

  undefined4 uVar2;

  void *pvStack_18;

  

  pvStack_18 = (void *)0x0;

  iVar1 = (**(code **)(**(int **)((int)this + 0x5f0) + 0x44))(pSkill,this);

  if (iVar1 != 1) {

    pvStack_18 = pSkill;

    uVar2 = FUN_004e2600(&LAB_005532e0,&pvStack_18,0);

    return CONCAT31((int3)((uint)uVar2 >> 8),1);

  }

  return 0;

}
```

---

## Version 2026-07-29 — assembly correction pass (append-only)

**Tool:** Ghidra MCP `disassemble_function` @ `0x00553650` + create/decompile callback @ `0x005532e0`.  
**Do not treat the 2026-07-23 decompile as complete ABI** — several facts were lost.

### Assembly body (authoritative CF)

```text
00553650  SUB  ESP,0xC
00553653  PUSH ESI / PUSH EDI
00553655  MOV  EDI,[ESP+0x18]          ; arg0 = target object
00553659  MOV  ESI,ECX                 ; this = skill runtime
0055365b  MOV  ECX,[ESI+0x5F0]         ; handler object
00553661  MOV  EAX,[ECX]               ; vtbl
00553663  PUSH 0                       ; handler arg2 = NULL/0
00553665  PUSH ESI                     ; handler arg1 = skill
00553666  PUSH EDI                     ; handler arg0 = target
00553667  CALL [EAX+0x44]              ; handler->vtbl+0x44(target, skill, 0)
0055366a  CMP  EAX,1
0055366d  JZ   reject                  ; handler==1 → return AL=0
; accept path:
0055366f  MOV  CL,byte [ESP+0x1C]      ; arg1 low byte (notify/HB flag)
00553673  PUSH 0
00553675  LEA  EDX,[ESP+0xC]           ; &ctx
00553679  PUSH EDX
0055367a  … pack ctx: target, skill, resultByte=1, flagByte=arg1 …
0055367e  MOV  ECX,[EDI+0xB0]          ; thiscall this = target+0xB0 list mgr
00553684  PUSH 0x005532E0              ; predicate callback
00553696  CALL FUN_004e2600            ; walk/remove matching list nodes
0055369b  MOV  AL,byte [ctx.result]    ; normally 1 unless listener cleared it
005536a4  RET  8
reject:
005536a8  XOR  AL,AL
005536ae  RET  8
```

### Decompiler vs assembly deltas

| Decompiler (2026-07-23) | Assembly (2026-07-29) |
|---|---|
| Handler args `(pSkill, this)` only | Handler args **`(target, skill, 0)`** — three stack args |
| Formal `pTarget` unused | Formal2 **low byte read** (HB notify flag into ctx) |
| `FUN_004e2600(&LAB, &box, 0)` free-style | **`thiscall`**: `ECX = target+0xB0`, stack `(callback, &ctx, 0)` |
| `LAB_005532e0` opaque | Function created/decomp as **`Skill_ValidateTarget_HBSkillListener`** |
| Return `CONCAT31(...,1)` fixed 1 | Return **ctx result byte** (default 1; listener may set 0) |
| Plate “feedback on reject” | Listener walk runs on **accept** path (`handler != 1`) |

### Callback body summary (`0x005532e0`)

String: `"Skill found with no base class: %d"`. RTTI: `CVOGHBBase` → `CVOGHBSkillBase`.  
Re-invokes `skill+0x5F0` vtbl+0x44 with **`(target, skill, hbSkillBase)`**. Handler returns: **1** → set result byte 0 (reject); **2** → set result byte 1 and optional `hb->vtbl+0x18(1,0)` when flag byte set.

---

## Version 2026-07-29 — dual residual (callers + outFlags; append-only)

**Tool:** Ghidra MCP `get_xrefs_to` / parent decompiles / `read_memory` at call sites.  
**Live `decompile_function(0x00553650)` still incomplete** vs asm appendix (same 2-arg vcall shape) — do not re-author plate from live decomp alone.

### All xrefs (7)

| Site | Parent | notify | Polarity |
|---|---|---:|---|
| `0x005789F3` | `CVOGHBSkillBase_ctor` | 1 | `(char)!=0` |
| `0x0057C976` | `CVOGReaction_Dispatch` case 0xC | 0 | `TEST AL`/`JZ` |
| `0x0057CA3C` | same | 0 | same |
| `0x005D1882` | `NPC_TryCastSkillFromSet` | 0 | `(char)!=0` |
| `0x00606EB6` | `Outpost_CastSkillsForFaction` | 0 | `(char)!=0` |
| `0x00607285` | `Outpost_CastSkillsForBeaconShare` | 0 | `TEST AL`/`JZ` |
| `0x006074F2` | same BeaconShare (next FUN `0x00607550`) | 0 | same |

### outFlags

Unit writes **no** outFlags. NPC: `Skill_ResolveTargetList` may fill resolve flags **before** this bool gate; orthogonal.
