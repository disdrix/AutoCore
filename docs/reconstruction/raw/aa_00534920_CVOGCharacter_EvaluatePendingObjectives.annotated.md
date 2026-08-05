# Annotated low-level: CVOGCharacter_EvaluatePendingObjectives (`aa_00534920`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00534920` |
| **VA** | `0x00534920` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_00534920_CVOGCharacter_EvaluatePendingObjectives.md` (capture 2026-07-23) |
| **Dual residual** | `2026-07-29` — CompleteCount + pending-slot + twin + 7-caller set sealed |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
void __thiscall CVOGCharacter_EvaluatePendingObjectives(
    CVOGCharacter* this,
    uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4
    /* + 5th stack arg in_stack_00000014 → precheck only */);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `this` | 32-bit pointer | unsigned | `ECX` | Character |
| `p1` | **u32** | opaque | stack | Context **kind** integers: 5=Money, 6=post-final-complete, 7=combat, 9/10/0xb (product enum name open) |
| `p2`–`p4` (+5th) | **u32** each | opaque | stack | Event payload (often float bits: delta, elapsed, cbid, …) |
| return | void | — | — | — |

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| Continent/state `+0xa8` chain | Same character→world link as other mission funcs | **High** |
| Flags `state+0x7e` / `state+0xf6` | Gate: enter only if `+0x7e != 0` **and** `+0xf6 == 0` | **High** |
| Raw plate “bail if set” | **Wrong** for `+0x7e` (must be set to enter) | **High** |
| Raw plate “skip objective if precheck fails” | **Wrong** — precheck only gates action/LogicUI | **High** |
| `this+0x55c` | Pending-objectives CNDHash | **High** |
| Hash lock `+0x1d` | Traversal lock | **High** |
| Pending `node+8` as bare def* | **Wrong** — value is **slot**; `def = *slot` (asm) | **High** |
| Objective def evaluators `+0x158/+0x15c` | Pointer array of evaluator objects on **def** | **High** |
| Vtable `+0x4` | Pre-condition check → **char/bool** + context; 2nd arg = **slot** | **High** |
| Vtable `+0x20` | Action / UI refresh callback | **High** |
| Vtable `+0x8` | Evaluation “is satisfied?” → **char/bool**; 2nd arg = **slot** | **High** |
| `FUN_0059d880` | **`*(def+0x164)` = CompleteCount** | **High** |
| Double call sites | Real dual CALL `0x00534ae2` / `0x00534aed` — zero-test then compare | **High** |
| Collect predicate | `(count!=0 && count<=success) \|\| allTrue`, then `+0x138==0` | **High** |
| Collect `*(def+0x10)` | Objective id **u32** into growable array | **High** |
| `CompleteObjective(...)` missing this | `__thiscall` character in ECX; force **0** | **High** |
| Gate `*(def+0x138)==0` | Must be zero to collect; field on **objective def** not mission | **High** (CF); **Tentative** (English) |
| `FUN_005307e0()` no args | `__fastcall` character; drains/zeros `char+0x564`; always zeros `+0xd6c/+0xd68` | **High** (layout); name Tentative |

### CompleteCount evidence

- `FUN_0059d880`: `return *(param_1 + 0x164)`.
- `FUN_005468c0` objective XML: `fprintf(..., "<CompleteCount>%i</CompleteCount>", FUN_0059d880())`.
- Twin gate in `CVOGReaction_CompleteObjective` uses the same getter (with force path).
- Asm: dual CALL with `jz` (count==0 → allTrue only) then `cmp success,count; jge`.

### Pending-slot evidence

```
mov ecx, [esi]       ; def = *slot  (ESI=slot throughout eval loop)
mov edx, [ecx+0x158]
… push esi; push ebp; call [eax+8]   ; eval(this, slot)
…
mov esi, [esi]       ; promote to def for +0x138 / +0x10
cmp dword [esi+0x138], 0
mov esi, [esi+0x10]  ; objective id
```

Active hash `+0x548` stores bare **def*** at `node+8` — different layout.

---

## 3. Control flow

```text
state = continent/world via +0xa8 chain
if !(state+0x7e != 0 && state+0xf6 == 0): return

lock pending hash this+0x55c
for each pending node:
  slot = node[+8]
  def  = *slot
  successCount = 0; allTrue = 1
  for each evaluator in [def+0x158, def+0x15c):
    pre = vtable+0x4(this, slot, p1..p4, stack5)
    if pre and (mission[+0xf8]==0 or def[+0x14]!=0):
      vtable+0x20(action); Client_SendLogicUiPacket(type=4)
    ok = vtable+0x8(eval)(this, slot)   # always
    if ok: successCount++
    if allTrue: allTrue = ok            # sticky AND
  count = CompleteCount(def)            # *(def+0x164), dual CALL
  if ((count != 0 && count <= successCount) || allTrue) && def[+0x138]==0:
    push def[+0x10]
unlock hash

for each collected id:
  CompleteObjective(this, id, 0xFFFFFFFF, 0xFFFFFFFF, force=0)
FUN_005307e0(this)   # always
free vector
```

| Branch | Effect |
|---|---|
| State flags fail | No work |
| Evaluator pre fails | Skip action/UI for that evaluator; still runs eval `+0x8` |
| CompleteCount==0 | Count arm disabled; allTrue only |
| Empty evaluator list | allTrue stays 1 → collect if `+0x138==0` |
| Collect condition fail | Objective not completed this pass |
| After unlock | Completions applied **outside** traversal |

---

## 4. Side-effect order

1. State flag reads.
2. Hash lock + walk with evaluator **callbacks** (may mutate UI/state via action).
3. Unlock.
4. `CompleteObjective` for each collected id (heavy side effects; force 0).
5. `FUN_005307e0(this)` — always (empty queue still zeros fields) + `operator_delete` on id vector.

**Important:** Completions are deferred until after unlock — intentional to keep hash traversal safe.

---

## 5. Static callers (exactly 7)

| kind | Caller VA | Symbol |
|---:|---|---|
| 5 | `0x005355a0` | `CVOGCharacter_AddCredits` |
| 6 | `0x00533f90` | `CVOGReaction_CompleteObjective` (final only) |
| 7 | `0x005355e0` | `Character_MaybeRefreshCombatState_Inferred` |
| 9 | `0x00535c60` | `FUN_00535c60` |
| 10 | `0x00535ed0` | `FUN_00535ed0` |
| 0xb | `0x00650de0` / `0x00650e50` | Patrol Fn6 / Fn3 |

---

## 6. Open questions

- English meaning of objective-def `+0x138` when non-zero (auto-collect inhibit).
- Product context-kind enum names (integer values sealed).
- Continent `+0x7e` / `+0xf6` retail names.
- LogicUI queue object exact base type.
- Runtime money/kill/patrol → pending complete end-to-end.
