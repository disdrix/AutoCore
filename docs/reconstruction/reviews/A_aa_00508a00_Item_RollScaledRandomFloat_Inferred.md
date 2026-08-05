# Review A (reconstruction fidelity): `aa_00508a00` Item_RollScaledRandomFloat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508a00` |
| **VA** | `0x00508a00` |
| **Body end** | epilogue `ret 0x10` @ ~`0x00508ab9` |
| **Canonical name** | `Item_RollScaledRandomFloat_Inferred` |
| **Ghidra name** | `FUN_00508a00` |
| **Prior names** | `FUN_00508a00`; scaffold Named_CalleeOf…CVOGReaction_Dispa |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00508a00_Item_RollScaledRandomFloat_Inferred.md` |
| **System** | inventory-transfer / combat death loot (affix float scaling) |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Scaled random float helper** used heavily inside `Item_RollQualityAndAffixes_Inferred` (`0x00509c70`) when writing type-specific gear floats (armor case 10, etc.).

```c
// stack formals cleaned with ret 0x10 (4 dwords)
// returns float in ST0 / float10
float Item_RollScaledRandomFloat_Inferred(
    float scale,            // param_1
    void *rng_or_unused,    // param_2 — passed into unit path
    char allow_sign_flip,   // param_3
    float unit_or_zero);    // param_4 — 0 → draw unit random; else multiply scale*param_4
```

### Control flow

1. **Magnitude:**
   - If `param_4 == g_flZero` (0.0f):  
     `CVOGReaction_RandomUnitScalar(param_2)` then `scale *= FUN_007a4170(param_2)` (unit draw in [0,1)).
   - Else: `scale *= param_4` (deterministic scale path — caller supplies factor).
2. **Optional sign flip (~50%):**  
   Advance global unit-random table (`CVOGReaction_RandomUnitScalar` → stream at `+8/+0xc`, wrap if cursor `> 0xfffff`):  
   `u16 * (1/65536)`. If `u < 0.5` **and** `allow_sign_flip != 0`: `scale *= -1.0f`.
3. **Dead-zone floor:** if `|scale| < ~0.01f` → `scale = 0`.
4. Return float.

**Sole live caller:** `FUN_00509c70` (quality/affix roller).

**Not** quality-tier selection, not broken roll, not catalog fill.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00508a00_FUN_00508a00.md` |
| Raw / annotated / clean | `aa_00508a00_*` / `FUN_00508a00.cpp` |
| Live decompile | Ghidra `0x00508a00` (2026-07-29) — **≡ clean CF** |
| Epilogue | `read_memory` → `ret 0x10` |
| Caller dual | `A\|B_aa_00509c70_Item_RollQualityAndAffixes_Inferred` |
| Constants | `read_memory` (below) |

---

## 3. Constants (`read_memory`)

| Symbol | Bytes (LE) | Value |
|---|---|---|
| `DAT_00a0f298` | `00 00 00 3f` | **0.50f** (sign-flip threshold) |
| `DAT_00aaa638` | `80 00 80 37` | **1/65536** (~1.5258789e-5) |
| `DAT_00aaa668` | `00 00 80 bf` | **−1.0f** |
| `DAT_00a0f718` | `0a d7 23 3c` | **~0.01f** (abs floor) |
| `g_flZero` | (global) | **0.0f** branch select |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| scale×unit when `param_4==0` else scale×param_4 | **Confirmed** | body |
| 50% sign flip gated by `param_3` | **Confirmed** | `u < 0.5 && param_3` |
| Abs floor ~0.01 → 0 | **Confirmed** | `DAT_00a0f718` |
| ABI `ret 0x10` / 4 stack formals | **Confirmed** | epilogue |
| Clean ≡ raw ≡ live | **Confirmed** | |
| Sole caller `00509c70` | **High** | live callers |
| `param_2` identity (seed stream vs unused) | **Probable** | passed into unit helpers |
| Product name | **Tentative** | `_Inferred` |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Zero-branch unit random vs multiply | **Yes** |
| RNG table advance + 0.5 gate | **Yes** |
| Sign flip × −1 | **Yes** |
| Abs floor | **Yes** |

---

## 6. Gaps / open

1. Exact product semantics of `param_2` (deterministic seed slot vs ignored).
2. Whether `param_4 != 0` path is “fixed unit” from caller or a non-random scale.
3. Runtime histogram of sign-flip / floor rates.

**Verdict:** **accept-with-gaps** — CF + constants **High/Confirmed**; seed formal residual.
