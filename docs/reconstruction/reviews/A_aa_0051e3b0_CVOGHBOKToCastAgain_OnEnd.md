# Review A (reconstruction fidelity): `aa_0051e3b0` CVOGHBOKToCastAgain_OnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e3b0` |
| **VA** | `0x0051e3b0` |
| **Canonical name** | `CVOGHBOKToCastAgain_OnEnd` |
| **Review date** | `2026-07-23` (strengthened `2026-07-29`) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051e3b0_CVOGHBOKToCastAgain_OnEnd.md` |
| **Residual** | `reviews/a_0051e3b0.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** (CF + ABI sealed; product English for empty stub open) |

---

## 1. Purpose

Type-8 cast-again HB **OnEnd** (`vtbl+0x14`): if owner object at `HB+0x18` non-null, `Skill_SetIsCastingFlag(skill@HB+0x24, 0)` (writes `skill+0x628=0` only). Tail-jumps empty stub `FUN_005081f0` (`ret`). Companion to OnStart (sets 1 + stamp) and ctor (duration / category map insert — **not** erased here).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Residual | `docs/reconstruction/reviews/a_0051e3b0.md` |
| Raw | `docs/reconstruction/raw/aa_0051e3b0_CVOGHBOKToCastAgain_OnEnd.md` |
| Annotated | `docs/reconstruction/raw/aa_0051e3b0_CVOGHBOKToCastAgain_OnEnd.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBOKToCastAgain_OnEnd.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051e3b0_CVOGHBOKToCastAgain_OnEnd.md` |
| Evidence | Ghidra decompile + `read_memory` body / vtbl / `FUN_005081f0` / `Skill_SetIsCastingFlag` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gate `HB+0x18` (owner object) | **High** | `cmp [esi+0x18],0`; AttachOwner stores owner |
| `Skill_SetIsCastingFlag(skill@+0x24, 0)` | **High** | `mov ecx,[esi+0x24]; push 0; call 0x005502d0` |
| Flag write `skill+0x628=0`; no tick clear on false | **High** | SetIsCastingFlag `ret 4` body |
| `FUN_005081f0` = empty `ret` (no-op) | **High** | `C3` @ `0x005081f0` |
| Tail-call, not `call` | **High** | `jmp` after restore ESI |
| Vtbl slot `+0x14` @ `0x009ce1d8` | **High** | DATA xref only |
| No category-map erase in this unit | **High** | body has no map ops |
| `unaff_SI` real arg | **Falsified** | decomp phantom |
| Zero stack formals on OnEnd | **High** | `__thiscall` ECX only |

---

## 4. Control flow: clean ≡ raw ≡ machine

| Stage | Match |
|---|---|
| Owner gate + clear flag + empty tail | **Yes** |
| Symmetric flag polarity vs OnStart | **Yes** (1 vs 0) |
| Trailing work vs OnStart | **Asymmetric** (stamp vs empty stub) — sealed |

---

## 5. Gaps / open

1. Product English name for shared empty stub `FUN_005081f0` (behavior sealed as no-op).
2. Full caller matrix of sites that **vcall** `vtbl+0x14` (list remove / base helper `0x005083f0` / abort) — not direct CALLs into this VA.
3. Runtime / bit-exact / image diff.

**Verdict:** **accept** (residual sealed 2026-07-29)
