# Review A (reconstruction fidelity): `aa_00525bd0` Client_FindObjectiveMatchingTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_00525bd0` |
| **VA** | `0x00525bd0` |
| **Canonical name** | `Client_FindObjectiveMatchingTarget` |
| **Review date** | `2026-07-29` (dual residual refresh) |
| **Prior dual** | `2026-07-23` accept-with-gaps (thin) |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00525bd0_Client_FindObjectiveMatchingTarget.md` |
| **Scratch** | `reviews/a_00525bd0.md` |
| **System** | `missions-progression` (consumer: `interaction-activation` UseObject) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`thiscall` on **character**: if the character has any **pending** objectives (`*(char+0x55c)+0xc ≥ 1`), walk the **active objectives** hash at `char+0x548` and return the **first objective definition\*** whose evaluators accept the given **target key** via MatchTarget at evaluator **`vtable+0x38`**. No match / empty pending → **0**.

Primary consumer: `Client_SendUseObject` (`0x00916740`, C2S **0x2072**) — uses return as def\* then packs **IDObjective** = `def+0x10` or **−1**. Target key at call site = `*( *(target+0xa8)+0x34 )` (clonebase field).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00525bd0_Client_FindObjectiveMatchingTarget.md` |
| Annotated | `docs/reconstruction/raw/aa_00525bd0_Client_FindObjectiveMatchingTarget.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_FindObjectiveMatchingTarget.cpp` |
| Function record | `docs/reconstruction/functions/aa_00525bd0_Client_FindObjectiveMatchingTarget.md` |
| Caller | `Client_SendUseObject` raw + clean + live decompile |
| Contrast id-finder | `aa_00524520` FindActiveObjectiveIdForInteract (`vtable+0x40` via `0059d9c0`) |
| Contrast helper | `aa_0059d9c0` MatchTargetEvaluators |
| UseItem slot residual | `aa_0060d7f0` JMP → `FUN_0060d460` (object ABI; see gaps) |
| Live decompile | Ghidra `batch_decompile` `0x00525bd0`, `0x00916740`, `0x00524520`, `0x0059d9c0`, `0x0060d7f0`, `0x0060d460` (2026-07-29) |
| Xrefs | `get_function_callers` → **only** `Client_SendUseObject` |
| Thunk bytes | `read_memory` `0x0060d7f0` = `E9 6B FC FF FF` → `0x0060d460` |

---

## 3. Control flow (authoritative raw / live)

```
Client_FindObjectiveMatchingTarget(character this, targetKey param_2):
  if *( *(character + 0x55c) + 0xc ) < 1: return 0          // pending container count
  hash = *(character + 0x548)
  assert/set traversal lock hash+0x1d = 1                     // HashError:TraversalLock / VOG_DEBUG_STOP
  node = 0
  while true:
    hash = *(character + 0x548)
    assert lock still set                                     // HashError:TraverseToNext
    node = (node == 0) ? *(hash + 0x14) : *(node + 0x14)
    def = (node == 0) ? 0 : *(node + 8)                       // payload = objective def*
    if def == 0: break
    // evaluators [def+0x158, def+0x15c) as pointer array (count = (end-begin)>>2)
    for i in 0 .. count-1:
      eval = *( *(def+0x158) + i*4 )
      cMatch = (**eval)->vtable[+0x38](targetKey, character)  // thiscall this=eval
      if cMatch != 0:
        *( *(character+0x548) + 0x1d ) = 0
        return def
  *( *(character+0x548) + 0x1d ) = 0
  return 0
```

Live decompile **≡** raw capture (2026-07-23) byte-for-byte control flow.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `__thiscall (Character*, uint32 targetKey) → objective def*` | **High** | Ghidra thiscall; sole caller packs def`+0x10` |
| Pending-count gate `*(char+0x55c)+0xc < 1 → 0` | **High** | First branch; does **not** walk `+0x55c` |
| Walk hash root `char+0x548` = active objectives | **High** | Shared with AddActiveObjective / FindActiveObjectiveIdForInteract |
| Traversal lock byte `hash+0x1d` | **High** | Same HashError / VOG_DEBUG_STOP pattern |
| Chain: first `hash+0x14`, next `node+0x14`, payload `node+8` | **High** | Identical family as `00524520` / `005245d0` |
| Evaluator range `[def+0x158, def+0x15c)` pointer array | **High** | `(end-begin)>>2` count; null begin short-circuits |
| Match slot **vtable+0x38** with args **(targetKey, character)** | **High** | Explicit call site in body |
| Returns **def\*** (node+8), not id | **High** | Caller `SendUseObject` reads `+0x10` or stores −1 |
| Unlock on match **and** on exhaust | **High** | Both paths write lock 0 |
| First hash-order match wins | **High** | Immediate unlock+return |
| Sole production caller = SendUseObject | **High** | `get_function_callers` |
| Target key often `clonebase+0x34` from use target | **High** | SendUseObject live body |
| Miss / no def → caller IDObjective **−1** (not 0) | **High** | SendUseObject branch (caller, not this body) |
| Pending gate vs active walk (both required by CF) | **High** | Gate empty progress; walk active defs |
| Clean ≡ raw CF | **High** | Spot-check all stages |
| Character ECX provenance at SendUseObject | **Probable / Open** | Call decompiles as one stack arg; this residual |
| UseItem `FUN_0060d460` is the key-match implementation | **Tentative / overstated** | Helper ABI is (char, worldObj); see §6 |
| Full catalog of `+0x38` implementers (Kill/Patrol/…) | **Open** | Outside this unit body |
| Runtime / wire | **Open** | Static only |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Pending count gate | **Yes** |
| Lock / traverse / unlock | **Yes** |
| Payload `node+8` as def\* | **Yes** |
| Per-eval MatchTarget `+0x38`(key, char) | **Yes** |
| First hit unlock+return def | **Yes** |
| Exhaust unlock+return 0 | **Yes** |
| No invented world-object / id return | **Yes** |

---

## 6. Contrast with related matchers (fidelity)

| Unit | Hash | Extra gate | Match | Returns | Primary consumer |
|---|---|---|---|---|---|
| **This** `0x00525bd0` | `+0x548` | pending count `+0x55c` | eval **`+0x38`(key, char)** | **def\*** | `SendUseObject` → id or **−1** |
| `0x00524520` | `+0x548` | none | `0059d9c0` → eval **`+0x40`** | **id** `@+0x10` | `SendUseObject_IfInteractable` → id or **0** |
| `0x005245d0` | `+0x548` | none | `0059da10` → eval **`+0x44`** | **id** | pick/hover family |

**Do not merge** these three in ports: different eval slots, different return shapes, different miss sentinels at callers, only this unit has the pending-count gate.

### UseItem MatchTarget residual (documented, not sealed here)

- `CVOGObjectiveRequirement_UseItem_MatchTarget` `0x0060d7f0` is a **5-byte JMP** to `FUN_0060d460`.
- `FUN_0060d460` (live): null-check both stack args; match TFID pair on **world object** `+0x160/+0x164` **or** `clone+0x34 == req+0x18`; requires character inventory path `char+0x250→+0x2b0` + `FUN_00571010`; optional continent/`FUN_005710c0` gates.
- Proven direct call shape from `FUN_0060df70`: `FUN_0060d460(character, worldObject)` — **object-event** UseItem path, not a bare key.
- This walker’s dispatch is `(targetKey, character)`. Treating UseItem helper as fully sealed **key** MatchTarget for this unit would **overstate** evidence. Catalog which requirement types implement true key MatchTarget at `+0x38` remains open.

---

## 7. Gaps / open

1. Character `this` load at `SendUseObject` call site (thiscall ECX residual).
2. Which objective-requirement classes implement `vtable+0x38` under the **(key, character)** ABI (UseItem object helper is a poor fit).
3. Whether pending count can be stale relative to active hash (false-negative early-out) — static cannot prove.
4. Runtime C2S `0x2072` capture of IDObjective for use-item / deliver / facility.
5. Hash iteration order stability when multiple objectives would match.

**Verdict:** Walker hub for SendUseObject objective binding is **High** static fidelity. **accept-with-gaps** (MatchTarget implementer catalog + runtime + ECX residual).
