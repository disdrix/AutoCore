# Review B (skeptical / adversarial): `aa_0052a020` CVOGCharacter_IsObjectiveReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052a020` |
| **VA** | `0x0052a020` |
| **Review type** | Skeptical / adversarial dual residual |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0052a020_CVOGCharacter_IsObjectiveReady.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `this` is objective (like MatchTarget helpers) | Body uses ECX as `EBP`, loads **`[EBP+0x55c]`** (character pending hash); objective is ESI from stack | **Falsified** — **this = character** |
| 2 | OR / first-true like MatchTarget | Loop breaks on **false** and returns 0; only returns 1 after exhausting range | **Falsified** — **AND-all** |
| 3 | Uses CompleteCount `+0x164` / `FUN_0059d880` | No call to getter; no `+0x164` load in body hex | **Falsified** — pure all-true or `+0x138` |
| 4 | Empty evaluators always ready | Fallback is `SETNE AL` from **`[obj+0x138]`**, not constant 1 | **Falsified** — depends on `+0x138` |
| 5 | Empty evaluators always not ready | Same — nonzero `+0x138` → true | **Falsified as absolute** |
| 6 | Mode flag selects CompleteCount vs allTrue | Mode only picks **vtbl+0xc vs +0x8**; same AND loop | **Falsified** |
| 7 | Mode 1 ignores pending hash | Always `CNDHash_LookupByKey(char+0x55c, obj+0x10)` before loop when evaluators present | **Falsified** — lookup always; mode only changes call shape |
| 8 | Same function as EvaluatePendingObjectives | Different VA, different threshold, inverted `+0x138` gate vs auto-complete | **Falsified** — sibling role only |
| 9 | `+0x138` is proven “Repeatable” | MISSION_SYSTEM labels it Repeatable; EvaluatePending **skips auto-complete when nonzero**; this unit treats nonzero as **ready** without evals — labels conflict | **Survives only as Tentative English** — CF High, name **not sealed** |
| 10 | Multiple / unknown callers | Exact xrefs: **2** (`0052b404`, `0052b474`) | **Falsified as unknown** — sealed dual callers |
| 11 | Stack arity is one formal (thiscall obj only) | All epilogues `RET 8`; mode byte compared on stack | **Falsified** — **two** stack formals |
| 12 | Return is full meaningful EAX | Success `MOV AL,1`; fail `XOR AL,AL`; fallback `SETNE AL` | **Falsified as wide int** — **bool AL** |
| 13 | Mode 0 passes (char, pending) like mode 1 | Mode 0 path: `CALL [EDX+0xC]` with **no** stack args pushed for those formals (eval thiscall only) | **Falsified** — slots differ |
| 14 | Null objective crashes | Early `TEST ESI,ESI` → `XOR AL,AL; RET 8` | **Falsified** — safe false |
| 15 | Name must remain FUN_ only | Role is stable (readiness AND-walk); symbol still open | **Survives as Probable name** — `IsObjectiveReady` OK as proposed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Character this + RET 8 + two stack args | **High** | Stack smash / wrong hash base |
| AND-all over `[+0x158,+0x15c)` | **High** | Turn-in chrome false positives |
| Mode 0 → `+0xc`, mode 1 → `+0x8` | **High** | Journal vs turn-in diverge wrongly |
| Pending lookup `char+0x55c` / key `obj+0x10` | **High** | Stale progress / always-fail eval |
| Empty path `obj+0x138 != 0` | **High CF** | Silent never-ready / always-ready static objs |
| `+0x138` product English | **Tentative** | Mis-document mission vs objective flags |
| Distinct from CompleteCount auto-complete | **High** | Server/client port wrong gate |
| Eval implementer coverage for +0x8/+0xc | **Open** | Type-specific readiness wrong |
| Runtime turn-in dual | **Open** | UI chrome mismatch |
| Proposed symbol name | **Probable** | Naming only |

---

## 3. Cross-check against raw / live

Live decompile 2026-07-29 matches raw `aa_0052a020_FUN_0052a020.md` body line-for-line on control flow:

* null obj → false  
* nonempty evaluator span → lookup pending → AND loop with mode branch  
* else → `*(obj+0x138) != 0`

Live **body hex** strengthens decompiler presentation:

* **`c2 08 00`** on every exit (including early null and `+0x138` path)  
* Mode branch is **`ff 52 0c`** vs **`ff 50 08`** (not inferred offsets only)  
* Fallback is **`0f 95 c0`** (`SETNE AL`) after `CMP dword [ESI+0x138], 0`

Caller decompiles seal mode constants:

* `FUN_0052b420`: `FUN_0052a020(iVar1, 1)`  
* `FUN_0052b3b0`: `FUN_0052a020(iVar1, 0)`

Shared layout cross-checks with sealed mission units (`aa_00531b00`, `aa_00534920`) for `+0x55c` / `+0x158..+0x15c` / `+0x10`.

---

## 4. Surviving contract for AutoCore

```
// DO
bool ready = IsObjectiveReady(character, objectiveDef, /*mode*/ usePending ? 1 : 0);

// DO NOT
// - Use CompleteCount / FUN_0059d880 inside this helper
// - Treat empty evaluators as true without reading +0x138
// - Swap mode 0/1 (journal vs turn-in)
// - Call with ECX = objective
// - Equate to MatchTarget first-hit helpers
// - Trust "Repeatable" as sealed English for +0x138

// Caller map (static):
//   mode 1: FUN_0052b420 → ShowNpcMissionDialogUI turn-in
//   mode 0: FUN_0052b3b0 → journal/UI readiness
```

---

## 5. What would overturn this dual

1. Second production call site with different ECX role or mode encoding.  
2. Body hex showing `call [vtbl+…]` imm not `08`/`0c`.  
3. Proof evaluator range is not `+0x158/+0x15c` on live objective defs.  
4. Evidence `+0x138` is not a readiness-related field (would invert empty-path seal).  
5. Runtime showing CompleteCount is applied inside this VA (would contradict body).  

---

## 6. Gaps acknowledged (not failures of CF)

* Product name of function and of `+0x138`.  
* Full vtable matrix for `+0x8` / `+0xc` per requirement type.  
* Null-pending behavior of mode-1 implementers.  
* Bit-diff / live harness.
