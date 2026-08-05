# Review A (reconstruction fidelity): `aa_0052a020` CVOGCharacter_IsObjectiveReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052a020` |
| **VA** | `0x0052a020` |
| **Canonical name (proposed)** | `CVOGCharacter_IsObjectiveReady` |
| **Prior names** | `FUN_0052a020`; auto-alias `Named_CalleeOf_Named_CalleeOf_Client_ShowNpcMissionDialogUI_0052a020` |
| **Review date** | `2026-07-29` (dual A/B + artifacts) |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw / dual residual) |
| **Counterpart** | `reviews/B_aa_0052a020_CVOGCharacter_IsObjectiveReady.md` |
| **System** | `missions-progression` (objective readiness / turn-in gate) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`thiscall` on **character**: decide whether an **objective definition** is **ready** (all requirements satisfied / turn-in eligible).

Two modes (stack `char` formal):

| `mode` | Evaluator vcall | Args | Production callers |
|---:|---|---|---|
| **0** | `eval->vtbl[+0xc]` | none beyond eval `this` | `FUN_0052b3b0` (journal path) |
| **1** | `eval->vtbl[+0x8]` | `(character, pendingNode*)` | `FUN_0052b420` (turn-in / ShowNpcMissionDialogUI) |

Semantics:

1. `objective == null` → **false**.
2. If evaluator vector `[obj+0x158, obj+0x15c)` is **non-empty**:
   - Lookup pending runtime node: `CNDHash_LookupByKey(*(char+0x55c), *(obj+0x10))`.
   - **AND** all evaluators: first false → false; all true → true.
3. If vector empty / null begin: ready iff `*(obj+0x138) != 0`.

**Not** the same algebra as `CVOGCharacter_EvaluatePendingObjectives` (CompleteCount threshold + `+0x138==0` auto-complete gate). This unit is pure **all-true** readiness (or static `+0x138` fallback).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052a020_FUN_0052a020.md` |
| Annotated | `docs/reconstruction/raw/aa_0052a020_FUN_0052a020.annotated.md` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_0052a020.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052a020_FUN_0052a020.md` → strengthened |
| Live decompile | Ghidra `decompile_function` / `analyze_function_complete` `0x0052a020` (2026-07-29) |
| Live memory | Ghidra `read_memory` body @ `0x0052a020` (200 B) |
| Callers decompile | `FUN_0052b420` @ `0x0052b420`, `FUN_0052b3b0` @ `0x0052b3b0` |
| Related sealed units | `aa_00534920` EvaluatePendingObjectives; `aa_00531b00` AddActiveObjective; `aa_0059d9c0` MatchTargetEvaluators |
| Upstream usage | `tmp/a_009438f0.md` / ShowNpcMissionDialogUI turn-in via `FUN_0052b420` |

---

## 3. Control flow (authoritative decompile + body hex)

```
bool __thiscall IsObjectiveReady(Character* this /*ECX*/, ObjectiveDef* obj, char mode):
  if obj == 0: return false
  begin = *(obj + 0x158)
  end   = *(obj + 0x15c)
  if begin != 0 && ((end - begin) >> 2) != 0:
    pending = CNDHash_LookupByKey(*(this + 0x55c), *(uint*)(obj + 0x10))
    for i = 0 .. count-1:
      eval = *(Evaluator**)(begin + i*4)
      if mode == 0:
        c = (*(eval->vtbl + 0xc))()          // thiscall eval only
      else:
        c = (*(eval->vtbl + 0x8))(this, pending)
      if c == 0: return false
    return true
  return *(obj + 0x138) != 0
```

### 3.1 Body hex seal (`read_memory` 2026-07-29)

```text
55 56 8b 74 24 0c 85 f6 8b e9 75 07 5e 32 c0 5d c2 08 00
8b 86 58 01 00 00 85 c0 74 77
8b 8e 5c 01 00 00 2b c8 c1 f9 02 89 4c 24 0c 74 66
8b 56 10 8b 8d 5c 05 00 00 53 57 52 e8 c1 68 08 00   ; LookupByKey
…
80 7c 24 18 00 … ff 52 0c … ff 50 08 …              ; mode? +0xc : +0x8
…
5f 5b 5e 32 c0 5d c2 08 00                          ; fail AL=0 RET 8
5f 5b 5e b0 01 5d c2 08 00                          ; all-true AL=1 RET 8
83 be 38 01 00 00 00 5e 0f 95 c0 5d c2 08 00        ; SETNE AL from [obj+0x138]
```

Live decompile ≡ raw capture (2026-07-23). No CF drift.

---

## 4. ABI seal (High)

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = **character** | `MOV EBP,ECX`; loads `EBP+0x55c` pending hash | **High** |
| Two stack formals | All return paths `RET 0x8` (`c2 08 00`) | **High** |
| Stack0 = **objective def\*** | `MOV ESI,[ESP+0xc]` after 2 pushes; reads `+0x158/+0x15c/+0x10/+0x138` | **High** |
| Stack1 = **mode char** | `CMP byte [ESP+…],0` selects vtbl slot | **High** |
| Return **bool in AL** | `XOR AL,AL` / `MOV AL,1` / `SETNE AL`; callers `TEST AL` | **High** |
| Sole direct callees | `CNDHash_LookupByKey` + indirect evaluator vcalls | **High** |
| Static callers (2) | xrefs `0x0052b474` (`FUN_0052b420` mode **1**), `0x0052b404` (`FUN_0052b3b0` mode **0**) | **High** |

Canonical signature:

```c
// AL 0/1; callee cleans 8
bool __thiscall CVOGCharacter_IsObjectiveReady(
    void* character,     /* ECX */
    void* objectiveDef,  /* stack */
    char  mode);         /* stack: 0 = vtbl+0xc, 1 = vtbl+0x8 + pending */
```

---

## 5. Offset / slot map (High unless noted)

| Symbol | Offset / slot | Role | Conf |
|---|---|---|---|
| `char+0x55c` | pending objectives hash | Lookup key = objective id | **High** (shared AddActive / EvaluatePending) |
| `obj+0x10` | objective id | Hash key | **High** |
| `obj+0x158` / `+0x15c` | evaluator** half-open | Same family as MatchTarget / EvaluatePending | **High** |
| `obj+0x138` | fallback readiness flag | Nonzero → ready when **no** evaluators | **High CF** / **Tentative English** |
| Eval `vtbl+0x8` | mode 1 | Progress eval `(char, pending*)` — same slot family as EvaluatePending | **High** |
| Eval `vtbl+0xc` | mode 0 | Lightweight readiness (no pending args) | **High CF** / product name open |
| Eval stride | +4 | pointer array | **High** |

---

## 6. Caller contracts

### 6.1 `FUN_0052b420` @ `0x0052b420` (turn-in ready)

- Resolves mission’s **last** objective via `def+0x130` / `+0x13c`.
- Requires that objective **active** in `char+0x548` with non-null node payload `node+8`.
- Calls `FUN_0052a020(lastObj, 1)` — **mode 1** (pending-aware).
- Optional NPC evaluator type-**3** gate after readiness true.
- Upstream: `Client_ShowNpcMissionDialogUI` drives chrome `+0x64c` / state-1 turn-in.

### 6.2 `FUN_0052b3b0` @ `0x0052b3b0` (journal / lighter check)

- Same last-objective + active-hash preamble.
- Calls `FUN_0052a020(lastObj, 0)` — **mode 0** (vtbl+0xc only).
- Callers: `FUN_00829b20`, `FUN_0082a050`, `FUN_008a2020` (journal/UI family; product names open).

---

## 7. Contrast seals (do not conflate)

| Unit | Algebra | Notes |
|---|---|---|
| **This** `0x0052a020` | **ALL** evals true (AND); empty → `+0x138!=0` | Readiness / turn-in |
| `EvaluatePendingObjectives` `0x00534920` | CompleteCount **or** allTrue, and `+0x138==0` | Auto-complete collector |
| MatchTarget `+0x40/+0x44/+0x38` | **FIRST** true wins | Interact / pick / use-object match |
| Deliver cargo readiness helpers | Type-3 inventory predicates | Separate paths |

---

## 8. Confidence table

| Area | Level | Rationale |
|---|---|---|
| Function boundary / CF | **High** | Decompile ≡ raw ≡ body hex |
| ABI thiscall + RET 8 | **High** | All epilogues |
| AND-all evaluators | **High** | Break on false; fall-through true |
| Mode 0/1 slot select | **High** | `ff 52 0c` / `ff 50 08` + callers pass 0/1 |
| Pending hash `+0x55c` + id key | **High** | Shared mission machinery |
| Empty-eval `+0x138` fallback | **High CF** | `SETNE` from dword |
| `+0x138` English name | **Tentative** | Docs say “Repeatable”; EvaluatePending treats as auto-complete exclude — **conflict** |
| Mode-0 vtbl+0xc product name | **Open** | Not fully typed across eval classes |
| Runtime / bit-diff | **Open** | Not run |
| Proposed name `IsObjectiveReady` | **Probable** | Role sealed; symbol open |

---

## 9. Gaps (owned residual)

1. Product English for `obj+0x138` (not “Repeatable” without stronger evidence).
2. Full implementer matrix for eval `vtbl+0x8` vs `+0xc` across Collect/Kill/Deliver/UseItem/…
3. Pending node layout when Lookup returns null — mode 1 still invokes eval with null second arg (behavior per type).
4. Product names for callers `FUN_0052b3b0` / `FUN_0052b420` (out of scope except call-site contracts).
5. Runtime dual against live journal + turn-in chrome.

---

## 10. Surviving contract for AutoCore

```
// Character-side objective readiness (turn-in / journal)
bool IsObjectiveReady(Character* ch, ObjectiveDef* obj, bool usePendingEval) {
  if (!obj) return false;
  auto* begin = obj->evaluators_begin; // +0x158
  auto* end   = obj->evaluators_end;   // +0x15c
  if (begin && (end - begin) > 0) {
    void* pending = CNDHash_LookupByKey(ch->pendingObjectives /*+0x55c*/, obj->id /*+0x10*/);
    for (auto* e : range(begin, end)) {
      bool ok = usePendingEval
        ? e->vtbl->Eval_Plus8(ch, pending)
        : e->vtbl->Ready_PlusC();
      if (!ok) return false;
    }
    return true; // AND-all
  }
  return obj->field_0x138 != 0; // static fallback — English open
}

// Port rules:
//  - Do NOT apply CompleteCount here (that is EvaluatePendingObjectives).
//  - Do NOT use MatchTarget slots +0x38/+0x40/+0x44.
//  - Mode 1 required for turn-in (FUN_0052b420); mode 0 for journal lightweight.
//  - Empty evaluator list is not "always ready" — depends on +0x138.
```
