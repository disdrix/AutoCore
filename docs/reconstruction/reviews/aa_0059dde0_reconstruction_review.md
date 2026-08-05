# Reconstruction review: `aa_0059dde0` Mission_ComputeObjectiveXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dde0` |
| **VA** | `0x0059dde0` |
| **Canonical name** | `Mission_ComputeObjectiveXp` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_0059dde0_Mission_ComputeObjectiveXp.md` | Authoritative Ghidra decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_0059dde0_Mission_ComputeObjectiveXp.annotated.md` | Machine notes; System missions-progression |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Mission_ComputeObjectiveXp.cpp` | Human-refined rewrite |
| Function record | `docs/reconstruction/functions/aa_0059dde0_Mission_ComputeObjectiveXp.md` | Human-refined status |
| Prior art | `docs/XP.md` Mission XP section | Formula narrative |
| Caller | `raw/aa_00533f90_*` / clean CompleteObjective | Bias + AddExperience packaging |
| Sibling threshold | `Experience_GetCumulativeThreshold` exact | Same level-map row+0x10 pattern |

**Primary claims under review (clean must match low-level):**

1. Null mission def → 0
2. Quest XP lookup by `obj+0x13c`; frac at row `+0x10`
3. `spanMult = BalanceScaler * frac * XPScaler` (product order)
4. Experience level lookup by `mission+0x11c`; span subtract when TargetLevel > 1
5. Return `(int)((float)span * spanMult)` — trunc toward zero; **no** bias here
6. Lazy ensure-load double-checks after each lower_bound

**Not re-authored.** No live re-decompile.

---

## 2. Evidence used

| Evidence | Source | Use |
|---|---|---|
| Authoritative pseudocode | Raw § “Raw pseudocode” | Ground truth CF, offsets, casts |
| Annotated body | Annotated | Confirm CF parity vs raw |
| Clean body | `Mission_ComputeObjectiveXp.cpp` | Fidelity + naming |
| XP.md formula | Prior art | Cross-check algorithm prose |
| CompleteObjective final path | Caller raw | Bias is caller-side |

No runtime / CE / differential. No instruction-byte body seal.

---

## 3. Confirmed points

### 3.1 Control flow: clean ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Null `obj+0x14c` → 0 | Present | Present | **Yes** |
| XPIndex key `+0x13c` | Present | Present | **Yes** |
| Quest map ensure + lower_bound | Present | Present (Map_ 4-arg) | **Yes** |
| End sentinel → fallthrough 0 | Present | Present | **Yes** |
| spanMult product order | Balance * frac * Scaler | Same | **Yes** |
| TargetLevel re-key + level map | Present | Present (StdMap_ 3-arg) | **Yes** |
| L>1 subtract prev cum | Present | Present | **Yes** |
| Trunc int cast of float product | Present | Present | **Yes** |
| Final return 0 | Present | Present | **Yes** |

### 3.2 Offsets and constants preserved

| Element | Raw | Clean |
|---|---|---|
| Mission def | `+0x14c` | Same |
| XPIndex | `+0x13c` short | Same |
| XPScaler / Balance | `+0x140` / `+0x144` | Same |
| TargetLevel | mission `+0x11c` | Same |
| Row payload | `+0x10` | Same |
| No bias global in this body | Absent | Absent |

### 3.3 Typing / naming delta only

Clean renames `pvVar1` / `extraout_EAX*` to `pRow` / `pIter`, documents that map lower_bound leaves iterator* in EAX, and preserves the dual helper names (`Map_LowerBoundFindByIntKey` vs `StdMap_LowerBoundByIntKey_INFERRED`) as decompiled.

Does **not** invent bias, ceil, or character mutation.

### 3.4 Function record honesty

Record labels **Human-refined clean**, bit-for-bit/runtime **Open**, residual map-iterator questions listed. Does not claim sealed retail port.

### 3.5 Absences

Clean does not invent: server-side formula, personal XP scalar, kill-path logic, or static `MissionObjective.XP` fallback (XP.md notes client prefers calculator).

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| `unaff_EDI` modeled as null residual | Cosmetic | Same as raw unknown; not used for CF |
| L-1 path: `*iter` used as node* without second load | Residual | Matches raw; not “fixed” into `**iter` |
| Scratch reuse of `flSpanMult` for first lower_bound | Cosmetic | Stack scratch; clean preserves |

**No revision required** for clean-vs-raw control-flow fidelity.

---

## 5. Residual uncertainty

1. Exact MSVC map iterator vs node layout on L-1 path.
2. Whether 4-arg vs 3-arg map helpers are truly different symbols or decompiler variance.
3. No runtime validation of worked example (TargetLevel=5 → span 3200 × 0.10 = 320).
4. WAD field name `rlLevelXP` is semantic label for row+0x10 float.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:**

- Clean C++ is a faithful, commented rewrite of raw control flow, offsets, product order, return casts, and ensure-load re-checks.
- Naming improves readability without changing behavior.
- Function record status matches refined quality without overclaiming completion.
- Caller-side bias correctly excluded from this unit.

**Gaps (do not block acceptance of clean≡raw):**

- Map iterator residual.
- No runtime / bit-for-bit verification.
- Table payload values unread from image this pass.

**Not needs-revision:** Clean does not diverge from raw in a way that requires CF rewrite.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Offsets / return codes match | **Pass** |
| No invented logic (bias, ceil, char mutate) | **Pass** |
| Function record does not overclaim | **Pass** |
| Runtime / table values complete | **Open** |
| Verdict | **accept-with-gaps** |
