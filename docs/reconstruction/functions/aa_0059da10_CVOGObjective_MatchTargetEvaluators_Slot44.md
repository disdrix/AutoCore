# Function record: CVOGObjective_MatchTargetEvaluators_Slot44

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059da10` |
| **Canonical name** | `CVOGObjective_MatchTargetEvaluators_Slot44` |
| **Prior** | `FUN_0059da10` |
| **Address** | `0x0059da10` |
| **Body** | `0x0059da10` – `0x0059da59` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation / missions-progression |
| **Completion status** | **Human-refined helper** — three-rep + dual A/B strengthened; dual residual vs `0x0059d9c0` sealed static (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Static dual sealed (memory); runtime suite open |
| **Ghidra name** | `CVOGObjective_MatchTargetEvaluators_Slot44` |

## Purpose

Walk objective evaluator array half-open `[this+0x158, this+0x15c)`. Return **1** if any evaluator’s **vtable+0x44** predicate succeeds on `(argA, argB)`, else **0**.

Sibling of `CVOGObjective_MatchTargetEvaluators` (`aa_0059d9c0` / `0x0059d9c0`) which uses **vtable+0x40**. Bodies are **byte-identical** except the slot immediate (`ff 50 44` vs `ff 50 40`).

## Signature (refined)

```c
std::uint32_t __thiscall CVOGObjective_MatchTargetEvaluators_Slot44(
    int objective, unsigned argA, unsigned argB);
// returns 0 or 1; ret 8 (two stack args + thiscall ECX)
```

## Dual residual vs `aa_0059d9c0` (sealed)

| Dimension | `0x0059d9c0` (+0x40) | `0x0059da10` (+0x44) |
|---|---|---|
| Range | `[+0x158, +0x15c)` | same |
| Loop / first-true / empty→0 | same | same |
| `ret 8` | same | same |
| **Vtbl call** | **`ff 50 40`** | **`ff 50 44`** |
| Sole caller | ForInteract `0x00524520` | ForPick `0x005245d0` |

**Pair residual = only the vtable slot.** Do not merge ports.

## Call graph

| Direction | Target | Notes |
|---|---|---|
| Caller (sole) | `CVOGCharacter_FindActiveObjectiveIdForPick` @ `0x005245d0` | xref `0x0052465a` UNCONDITIONAL_CALL; ECX=objInst |
| Callees | eval vtbl **+0x44** only | indirect; no direct FUN_* |

Parent walkers contrast:

| Walker | Helper | Slot | Return |
|---|---|---|---|
| ForInteract `0x00524520` | `0x0059d9c0` | +0x40 | objective id `@+0x10` |
| ForPick `0x005245d0` | **this** | **+0x44** | objective id `@+0x10` |
| FindObjectiveMatchingTarget `0x00525bd0` | inline | +0x38 | def\* (+ pending gate) |

## Artifacts

| Layer | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0059da10_FUN_0059da10.md` |
| Annotated | `docs/reconstruction/raw/aa_0059da10_FUN_0059da10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjective_MatchTargetEvaluators_Slot44.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0059da10_CVOGObjective_MatchTargetEvaluators_Slot44.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0059da10_CVOGObjective_MatchTargetEvaluators_Slot44.md` |
| Sibling helper | `docs/reconstruction/functions/aa_0059d9c0_CVOGObjective_MatchTargetEvaluators.md` |
| Parent walker | `docs/reconstruction/functions/aa_005245d0_CVOGCharacter_FindActiveObjectiveIdForPick.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + memory | **High** |
| Slot **+0x44** | **High** |
| Dual residual = only slot vs `0059d9c0` | **High** |
| Sole caller ForPick | **High** |
| Parameter semantic names (char, world) | **Probable** (from sole caller) |
| Product name of +0x44 method | **Tentative** |
| Per-type implementer semantics | **Open** |

## Open (out of sealed CF)

1. Requirement-type implementers of **vtable+0x44**.
2. Product semantic difference **+0x44** vs **+0x40** vs **+0x38**.
3. Runtime multi-evaluator first-wins order on pick/hover.
