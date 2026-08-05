# Review B (skeptical): `aa_0059da10` CVOGObjective_MatchTargetEvaluators_Slot44

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059da10` |
| **VA** | `0x0059da10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial / residual dual vs sibling |
| **Counterpart** | `reviews/A_aa_0059da10_CVOGObjective_MatchTargetEvaluators_Slot44.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks

| # | Attack | Outcome |
|---|---|---|
| 1 | Body is the same slot as sibling `0059d9c0` (`+0x40`) | **Falsified** — live decompile uses **`+0x44`**; memory `ff 50 44` vs sibling `ff 50 40` |
| 2 | Same as SendUseObject / FindObjectiveMatchingTarget MatchTarget (`+0x38`) | **Falsified** — slot is **`+0x44`**, not `+0x38`; different return chain (id helper, not def*) |
| 3 | Dual residual has other CF differences (range, ret arity, OR-all) | **Falsified** — 80-byte dual: **only** imm8 differs (`40`/`44`); both `ret 8`; first-true |
| 4 | `this` is character | **Falsified** — reads objective evaluator range `+0x158..+0x15c`; sole caller sets ECX = objInst |
| 5 | OR-all evaluators / accumulate score | **Falsified** — first true wins; returns bool 0/1 in AL |
| 6 | Empty range is error / assert | **Falsified** — falls through to `xor al,al; ret 8` |
| 7 | Multiple production callers | **Falsified (static)** — `get_function_callers` / `get_xrefs_to` → only `0x005245d0` |
| 8 | Can safely merge with `aa_0059d9c0` in a port | **Falsified** — different slot; different sole caller family (ForPick vs ForInteract) |
| 9 | Call-site arity is literally 2 formals only | **Survives as decompiler presentation** — Ghidra often shows `(char, world)`; thiscall ECX carries objective; body is `ret 8` |
| 10 | Name “MatchTarget…_Slot44” is retail | **Survives as role label only** — Probable parallel naming; product word for +0x44 open |
| 11 | All objective types implement +0x44 usefully | **Open** — may no-op / always false for some reqs |
| 12 | +0x44 is product synonym of +0x40 (same predicate, two slots) | **Open** — callers differ; per-type bodies not dualed this unit |
| 13 | argA/argB are always (character, worldObject) for every eval type | **Open (Probable at sole call site)** — only proven at ForPick push site |

---

## Surviving contract

```
// aa_0059da10 / 0x0059da10
// Dual residual vs aa_0059d9c0 / 0x0059d9c0: ONLY vtbl slot +0x44 vs +0x40
bool MatchTargetEvaluators_Slot44(Objective* o, A a, B b):
  for e in o->evaluators[begin=+0x158, end=+0x15c):   // half-open, ptr stride
    if e->vtbl[+0x44](a, b): return true
  return false

// Sole caller ForPick (0x005245d0):
//   ECX = objective instance; a ≈ character; b ≈ worldObject
//   parent returns *(obj+0x10) id on first true, else 0
```

### Port rules (hard)

1. **Do not** implement this as `+0x40` or `+0x38`.
2. **Do not** merge source with `aa_0059d9c0` into one function with a slot parameter unless both call sites are preserved.
3. **Do not** treat return as score / count / object pointer — it is **0/1**.
4. Seal individual evaluator **`+0x44`** bodies before trusting exotic objectives on pick/hover.

---

## Residual ledger (what remains after dual)

| Residual | Owner | Status |
|---|---|---|
| Helper CF / layout / slot | **this unit** | **Sealed High** |
| Dual vs `0059d9c0` byte identity | **this unit** | **Sealed High** (1-byte imm) |
| Sole caller identity | **this unit** | **Sealed High** |
| Product name of +0x44 method | eval / naming | **Open** |
| Per-type +0x44 implementers | separate units | **Open** |
| +0x44 vs +0x40 semantic delta | separate units | **Open** |
| Runtime multi-eval first-wins | runtime | **Open** |

**Verdict:** CF and dual residual **High**. Product slot semantics **Tentative**. **accept-with-gaps.**
