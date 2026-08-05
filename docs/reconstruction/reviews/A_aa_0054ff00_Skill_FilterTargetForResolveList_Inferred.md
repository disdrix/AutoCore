# Review A (reconstruction fidelity): `aa_0054ff00` Skill_FilterTargetForResolveList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054ff00` |
| **VA** | `0x0054ff00` |
| **Canonical name** | `Skill_FilterTargetForResolveList_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0054ff00_Skill_FilterTargetForResolveList_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** — outFlags writers **machine-sealed** (exact OR VAs); flag English open |
| **Residual scratch** | `tmp/a_0054ff00.md` |

---

## 1. Purpose

First-stage target legality filter inside `Skill_ResolveTargetList`. Takes skill (`this`), candidate, caster, and `outFlags*`; returns accepted object pointer or null. On reject, ORs diagnostic bits into `*outFlags` (**4**, **8**, **0x10** only).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054ff00_FUN_0054ff00.md` |
| Annotated | `docs/reconstruction/raw/aa_0054ff00_Skill_FilterTargetForResolveList_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_FilterTargetForResolveList_Inferred.cpp` |
| Caller | `Skill_ResolveTargetList` @ `0x00550300` (sole) |
| Downstream | `Client_Skill_ResolveCastTarget` consumes outFlags bits |
| Residual | `tmp/a_0054ff00.md` |

**Live re-decompile + sole-caller + `read_memory` on OR sites performed (2026-07-29 dual residual).**

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole caller ResolveTargetList | **Confirmed** | `get_function_callers(0x0054ff00)` |
| `*outFlags \|= 8` @ `0x0054ff72` | **Confirmed** | bytes `83 08 08` after `vtbl+0x198` + `+0x615&4` clear |
| `*outFlags \|= 0x10` @ `0x0055007c` | **Confirmed** | bytes `83 08 10`; type ∉ `{0xe,0x12,0x14}` via SUB chain |
| `*outFlags \|= 4` @ `0x005502c1` | **Confirmed** | bytes `83 08 04`; `LAB_005502bd` fallthrough |
| Exactly 3 outFlags OR stores | **Confirmed** | pcode INT_OR count = 3; no bits 1/2 |
| Exclusive writer of 4/8/0x10 in chain | **Confirmed** | ResolveTargetList only writes 1/2 |
| ABI `__thiscall` + `RET 0x0C` | **Confirmed** | epilogue `C2 0C 00` |
| Closes "who ORs bits 4/8" | **Confirmed** | also seals **0x10** |
| Product original name | Inferred | no string / RTTI |

---

## 4. Control flow vs ResolveTargetList

```
ResolveObjectTarget → Filter (this) → null?
  yes → maybe OR bit1 (no target) in caller
  no  → range Skill_RangeCheck… → may OR bit2 → copy TFID → Gather...
```

Filter does **not** set bits 1 or 2 — those remain in ResolveTargetList / range helper.

### Early exits → bit4 (single store)

| Path | Summary |
|------|---------|
| null candidate | not (flag `+0x614&1` + mode ∈ `{0,1,0xb}`) |
| self-pos mode fail | `+0x614&1` + mode ∉ `{0,1}` |
| remains+ally mismatch | `vtbl+0x198` + Remains + dead-check0 + Ally |
| fallthrough | all accept arms miss |

---

## 5. Gaps (acceptable)

1. Product names of `vtbl+0x198` / `+0x1d4` / `+0x298` (behavior sealed; remains/enemy English Probable).
2. Whether bit `0x10` has dedicated player UX (ResolveCastTarget does not special-case it).
3. Full English of every `skill+0x614/+0x615` flag (tooltip pairing High for used bits).
4. Friendly-fire / faction helper `FUN_005749d0` product name.
5. Runtime / bit-exact.

**Verdict:** **accept** for role + **machine-level** outFlags writer seal under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Sole caller | **Pass** |
| Bits 4/8/0x10 present at exact VAs | **Pass** |
| Clean matches OR sites | **Pass** |
| Exclusive chain writer | **Pass** |
| Verdict | **accept** |
