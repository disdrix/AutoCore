# Review B (skeptical / adversarial): `aa_00534920` CVOGCharacter_EvaluatePendingObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_00534920` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen — same day re-pass) |
| **Counterpart** | `reviews/A_aa_00534920_CVOGCharacter_EvaluatePendingObjectives.md` |
| **System** | `missions-progression` |
| **Dual status** | **Residual sealed** |
| **Verdict** | **accept-with-gaps** — spine + CompleteCount + slot + twin + callers sealed; `+0x138` English / flag names open |
| **Scratch** | `tmp/a_00534920.md` |

---

## 1. Claims under attack

| # | Claim | Attack outcome |
|---|---|---|
| 1 | Plate “bail if flags set” for both `+0x7e` and `+0xf6` | **Falsified** — body requires `+0x7e != 0` **and** `+0xf6 == 0` |
| 2 | Precheck failure skips whole objective | **Falsified** — precheck only gates action/LogicUI; eval `+0x8` always runs |
| 3 | `FUN_0059d880` is opaque / only completion rule | **Falsified** — sealed as **CompleteCount** `*(obj+0x164)`; **allTrue** is alternate collect arm |
| 4 | Completes immediately during traverse | **Falsified** — collect ids, unlock, then CompleteObjective |
| 5 | Clean seals full evaluator contracts | **Falsified** — vtable slots known; requirement-class bodies open |
| 6 | Money type 5 is unproven / only plate noise | **Partially falsified** — integer **5** is High from AddCredits body; product enum **name** still open |
| 7 | `def+0x138` is mission “repeatable” | **Falsified as identity** — mission repeatable is **mission** `+0x138`; here gate is on **objective def** after `mov esi,[esi]` |
| 8 | Double `FUN_0059d880` is decompiler noise | **Falsified** — two real CALLs (`0x00534ae2`, `0x00534aed`); 1st zero-test, 2nd compare to successCount |
| 9 | Decompiled `CompleteObjective(id,…)` omits `this` | **Decompiler artifact** — `__thiscall` character remains in ECX; force trailing **0** |
| 10 | `FUN_005307e0` is trivial vector cleanup | **Falsified** — drains `char+0x564` mission-end list; **always** zeros queue + `+0xd6c/+0xd68` even when empty |
| 11 | Pending hash value is same type as active `node+8` def* | **Falsified** — pending value is **slot**; `def = *slot` (asm `mov ecx,[esi]` / `push esi`) |
| 12 | RecvObjectiveState / CompleteMissionObjectives call this VA | **Falsified** — `get_xrefs_to` shows **exactly 7** callers; those two are **not** among them |
| 13 | Kind 6 runs on every CompleteObjective | **Falsified** — only when `pvVar7 == 0` (final mission path, not objective advance) |
| 14 | CompleteCount==0 uses count arm | **Falsified** — `test eax; jz` skips to allTrue only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pending hash + lock protocol | **High** | Crash / skipped eval / HashError stops |
| Pending **slot** vs active def* | **High** | Wrong base for +0x158/+0x164/+0x10 |
| Deferred CompleteObjective list | **High** | Reentrancy / double-complete if mirrored wrong |
| Precheck does not skip eval | **High** | Wrong progress simulation (under-count) |
| CompleteCount @ `obj+0x164` | **High** | Wrong multi-req threshold |
| Collect = (count≠0 ∧ count≤succ) ∨ allTrue | **High** | Never / always complete |
| Twin ≡ CompleteObjective force=0 | **High** | Port mismatch between pending vs force-complete |
| `def+0x138==0` required | **High** (CF); **Tentative** (meaning) | Silent skip of eligible objs |
| 7-caller kind integers | **High** | Miss event path in server sim |
| Context product enum names | **Tentative** | Docs only |
| Flag `+0x7e` / `+0xf6` names | **Tentative** | Eval never runs in wrong world state |

---

## 3. Cross-check against raw + asm (tightened)

```
state = *( *( *(this+4)+4 ) + 0xa8 + this )
if state[+0x7e] != 0 && state[+0xf6] == 0:
  lock pending(this+0x55c).+0x1d
  for each pending node (list via hash+0x14 / node+0x14):
    slot = node[+8]              # NOT bare def*
    def  = *slot
    success = 0; allTrue = 1
    for i in [def+0x158, def+0x15c):
      pre = vcall(eval[i], +0x4)(this, slot, ctx0..ctx3, stack5)
      if pre && (mission(def+0x14c)[+0xf8]==0 || def[+0x14]!=0):
        vcall(+0x20)(this, slot); LogicUI type 4
      ok = vcall(+0x8)(this, slot)
      if ok: success++
      if allTrue: allTrue = ok
    count = CompleteCount(def)     # FUN_0059d880 → def+0x164; dual CALL
    if ((count != 0 && count <= success) || allTrue) && def[+0x138]==0:
      push def[+0x10]              # objective id
  unlock
  for id in collected:
    CompleteObjective(this, id, -1, -1, force=0)
  FUN_005307e0(this)               # drain/zero char+0x564; always touch +0xd6c/+0xd68
  free collected vector
```

**Asm anchors (`read_memory` @ `0x00534ad8+`):**

```
mov  ecx, [esi]          ; def = *slot
call FUN_0059d880
test eax, eax
jz   allTrue_path        ; count==0 → no count arm
mov  ecx, [esi]
call FUN_0059d880
cmp  [esp+10h], eax      ; successCount ? count
jge  collect_gate        ; success >= count
test bl, bl              ; allTrue
jz   skip_collect
collect_gate:
mov  esi, [esi]          ; esi = def
cmp  dword [esi+0x138], 0
jnz  skip_collect
mov  esi, [esi+0x10]     ; objective id
```

**Twin:** `CVOGReaction_CompleteObjective` refuses when  
`((count < 1 || success < count) && !allTrue && !force)` — same CompleteCount field; force path absent here (always force=0); **no** `+0x138` gate on CompleteObjective.

---

## 4. Surviving contract for AutoCore

```
EvaluatePendingObjectives(character, ctx0, ctx1, ctx2, ctx3)
  no-op unless continent[+0x7e] && !continent[+0xf6]
  re-eval ONLY pending hash char+0x55c (not active +0x548 alone)
  pending values are slots: def = *slot; evaluators take (char, slot)
  per objective: run all evaluator evals; actions gated by precheck
  complete when CompleteCount met OR all evals true, and objDef+0x138==0
  CompleteObjective after full traverse (force 0)
  always FUN_005307e0 after (even if nothing collected)
  does not implement requirement math — delegates to evaluator vtables
```

Server port note: client may complete pending locally; authority still needs S2C/create restore for durable state (`missionState.md`).

Do **not**:

- Treat pending `node+8` as active-style bare def* without the extra load.
- Equate objective `+0x138` with mission repeatable.
- Assume RecvObjectiveState (0x2071) calls this function.
- Skip `FUN_005307e0` when the collected id list is empty.

---

## 5. Open questions

1. What sets / clears objective-def `+0x138` (auto-collect inhibit)?
2. Product enum name for context kinds (integer values sealed).
3. Continent flag retail names for `+0x7e` / `+0xf6`.
4. Live: AddCredits / patrol / use-object → pending money/patrol/use complete.
5. Exact LogicUI queue object type (ECX base near continent `+0xe8b8`).
6. Whether any dynamic/indirect call reaches this VA outside the 7 static xrefs.

**Verdict:** Accept traverse / CompleteCount / slot / twin / deferred complete / 7-caller CF. Keep `+0x138` English, flag names, and product kind enum open. **accept-with-gaps.**
