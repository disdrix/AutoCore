# Function record: CVOGCharacter_EvaluatePendingObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_00534920` |
| **Canonical name** | `CVOGCharacter_EvaluatePendingObjectives` |
| **Address** | `0x00534920` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` + 4 context dwords (+ decompiler 5th stack into precheck) |
| **Completion status** | **Human-refined + dual residual sealed (2026-07-29)** — CompleteCount, pending-slot, twin predicate, 7-caller set High; `+0x138` English / flag names open |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual reviews** | `A_aa_00534920_*` / `B_aa_00534920_*` — **accept-with-gaps** (residual sealed) |

## Purpose

Walk pending objectives (`char+0x55c`), run evaluator precheck/action/eval vcalls on each **slot**, collect objective ids that meet **CompleteCount** (or all-eval-true) with `def+0x138==0`, then `CompleteObjective` each (force 0) and post-cleanup via `FUN_005307e0`.

## Signature

```c
void __thiscall CVOGCharacter_EvaluatePendingObjectives(
    void* this, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4);
```

## Behavioral summary

1. Gate: continent via vbase `+0xa8` — `+0x7e != 0` and `+0xf6 == 0`.
2. Lock pending hash `+0x55c` (byte `+0x1d`).
3. Per pending **slot** (`node+8`): `def = *slot`; evaluators `[def+0x158, def+0x15c)`:
   - `+0x4` precheck `(char, slot, ctx…)` — does **not** skip eval
   - optional `+0x20` + LogicUI type **4**
   - `+0x8` eval `(char, slot)`
4. Threshold: `FUN_0059d880(def)` → **`*(def+0x164)` CompleteCount** (dual CALL; XML dump evidence). Collect if `(count != 0 && count <= success) || allTrue`, and `def+0x138==0`.
5. Unlock; `CompleteObjective(this, id, -1, -1, 0)`; `FUN_005307e0(this)` (always; zeros empty `+0x564` + `+0xd6c/+0xd68`); free id vector.

## Twin

`CVOGReaction_CompleteObjective` force=0 success condition is the **same** CompleteCount/allTrue algebra (no `+0x138` gate; has force bypass).

## Static callers (7)

| kind | Caller |
|---:|---|
| 5 | `CVOGCharacter_AddCredits` |
| 6 | `CVOGReaction_CompleteObjective` (final only) |
| 7 | `Character_MaybeRefreshCombatState_Inferred` |
| 9 | `FUN_00535c60` |
| 10 | `FUN_00535ed0` |
| 0xb | `CVOGHBMissionPatrol_Fn3` / `Fn6` |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Named plate; 7 CODE xrefs |
| Control flow | High | Labels `LAB_005349b0` / `005349ff`; clean ≡ raw |
| Pending **slot** indirection | **High** | Asm `mov ecx,[esi]` / `push esi` residual |
| Evaluator vtable slots 4/8/0x20 | High | Matches objective family |
| Pending hash `+0x55c` | High | missionState.md + HashError strings |
| CompleteCount `FUN_0059d880` / `+0x164` | **High** | Getter body + `<CompleteCount>` + dual CALL asm |
| Twin predicate force=0 | **High** | Algebra + shared getter |
| Precheck does not skip eval | High | Loop structure |
| Deferred complete after unlock | High | Post-loop for |
| 7-caller kind integers | **High** | Bodies + xrefs |
| `def+0x138` English | Tentative | Gate CF High on objective def |
| Context product enum names | Tentative | Integer kinds High |
| Overall | **High (static residual)** | Dual residual 2026-07-29 |

## Open questions

- English meaning of objective-def `+0x138` when non-zero.
- Product context-kind enum names (values sealed).
- Continent `+0x7e` / `+0xf6` retail names.
- Runtime pending complete from money/kill/patrol events.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00534920_CVOGCharacter_EvaluatePendingObjectives.md` |
| Annotated | `raw/aa_00534920_CVOGCharacter_EvaluatePendingObjectives.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_EvaluatePendingObjectives.cpp` |
| Review A | `reviews/A_aa_00534920_CVOGCharacter_EvaluatePendingObjectives.md` |
| Review B | `reviews/B_aa_00534920_CVOGCharacter_EvaluatePendingObjectives.md` |
| Scratch | `tmp/a_00534920.md` |
