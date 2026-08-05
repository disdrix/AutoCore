# Annotated low-level: CVOGMission_AddActiveObjective (`aa_00531b00`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531b00` |
| **VA** | `0x00531b00` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_00531b00_CVOGMission_AddActiveObjective.md` (capture 2026-07-23) |
| **Annotated refresh** | `2026-07-29` dual tighten (asm seals + CF fix) |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// MSVC thiscall: ECX = character (param_1 in decompile is this)
void __thiscall
CVOGMission_AddActiveObjective(CVOGCharacter* this, ObjectiveDef* objective /* param_2 */);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `this` / `param_1` | 32-bit pointer | unsigned | `ECX` | Character receiving the objective |
| `objective` / `param_2` | 32-bit pointer | unsigned | stack | Objective **definition** node |
| return | void | — | — | — |

Callers (asm): GiveMission `0x005328b2` and CompleteObjective `0x005348a2` both `PUSH objective; MOV ECX, character; CALL`.

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `int param_1` / `int param_2` | Character* + ObjectiveDef* | **High** |
| `FUN_0053c460(id, def, 0)` without this | `this = *(char+0x548)`; args `(hash, id, def, 0)` | **High** (asm `0x00531b0d`) |
| `FUN_0053c760(id, node, 0)` without this | `this = *(char+0x55c)`; args `(hash, id, node, 0)` | **High** (asm `0x00531b6f`) |
| `param_2 + 0x10` | Objective id (**u32** key) | **High** |
| `param_2 + 0x158` / `+0x15c` | Evaluator **array begin/end** (count = `(end-begin)>>2`) | **High** |
| `operator_new(0x14)` | Active-objective **runtime node** (5 dwords) | **High** |
| `piVar1[0] = param_2` | Node stores def pointer at `+0` | **High** |
| `FUN_0053c460` / `FUN_0053c760` | Twin **CNDHash insert** thiscalls (distinct node vtables) | **High** role |
| WARNING noreturn on `operator_delete` | **False** — asm falls through to evaluator loop | **High** |
| Vtable call `+0x28` on each evaluator | Activate / bind evaluator to runtime node | **High** CF; **Probable** English |
| `param_1 + 0x634 \|= 0x10` | Mission dirty bit (shared with FailMission) | **High** (value), **Probable** (meaning) |

---

## 3. Field map (objective def / runtime node / character)

| Offset | Width | Role |
|---|---|---|
| objDef `+0x10` | u32 | Objective id (hash key) |
| objDef `+0x158` | ptr | Evaluator pointer array begin |
| objDef `+0x15c` | ptr | Evaluator pointer array end |
| runtime node size | **0x14** bytes | `operator_new(0x14)` |
| runtime `+0` | ptr | Points at objective def |
| runtime `+4..+0x10` | 4× u32/f32 | Zero-init progress slots (later RecvObjectiveState) |
| character `+0x548` | CNDHash* | Active **definitions** hash (def insert this) |
| character `+0x55c` | CNDHash* | **Pending** state-node hash (node insert this) |
| character `+0x634` | u32 flags | `\|= 0x10` after non-empty evaluator path |

Evaluator array length: **u32** count = `(end - begin) >> 2`.

---

## 4. Control flow and branches

```text
// always
hash_insert(char+0x548, objectiveId, objectiveDef, skipIfExists=0)  // return ignored

if objective.evaluators empty (begin==0 or count==0):
  return

node = new 0x14; zero; node->def = objective
rc = hash_insert(char+0x55c, objectiveId, node, 0)
if rc != 0:
  operator_delete(node)
  // FALL THROUGH — do not abort (asm 0x00531b7c–0x00531b8f)

for each evaluator i in [0, count):
  evaluator.vtable[+0x28](character, node)   // node may be freed if rc!=0
character.flags634 |= 0x10
return
```

**Prior annotated bug (fixed 2026-07-29):** nesting setup/dirty under `else` of insert-fail was **wrong**. Raw and asm run the evaluator loop and dirty **after** delete.

---

## 5. Side effects summary

| Effect | When |
|---|---|
| Def registered in active-objectives hash | Always |
| Pending state node allocated + inserted | Evaluators non-empty |
| Evaluator setup vcalls | Evaluators non-empty (even after insert fail) |
| Dirty bit `0x10` | Evaluators non-empty |
| First insert HRESULT | Never checked |
