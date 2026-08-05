# Review A (reconstruction fidelity): `aa_00550300` Skill_ResolveTargetList

| Field | Value |
|---|---|
| **Stable ID** | `aa_00550300` |
| **VA** | `0x00550300` |
| **Canonical name** | `Skill_ResolveTargetList` |
| **Review date** | `2026-07-23` (dual residual strengthen `2026-07-29`) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00550300_Skill_ResolveTargetList.md` |
| **Residual scratch** | `reviews/a_00550300.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** on outFlags writer chain + Filter/RangeCheck link; **accept-with-gaps** on `+0x624`/Gather/runtime |

---

## 1. Purpose

Build final skill target list from skill targeting flags (`skill+0x614` / `+0x624`): wipe 100 TFID slots, resolve optional primary object, **filter** via `Skill_FilterTargetForResolveList_Inferred` (`0x0054ff00`), **range-check** via `Skill_RangeCheckTargetForResolveList_Inferred` (`0x0058c0a0`), write primary TFID, optionally top-up / full area gather via `Skill_GatherTargetsInArea`. Returns final target count. Glue between cast and AoE gather. Does **not** return `eSkillResponses` — callers map `*outFlags` bits.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00550300_Skill_ResolveTargetList.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ResolveTargetList.cpp` |
| Function record | `docs/reconstruction/functions/aa_00550300_Skill_ResolveTargetList.md` |
| Fresh re-decompile | Ghidra `0x00550300` (2026-07-29 residual) |
| Filter dual | `reviews/A\|B_aa_0054ff00_Skill_FilterTargetForResolveList_Inferred.md` |
| Range dual | `reviews/A\|B_aa_0058c0a0_Skill_RangeCheckTargetForResolveList_Inferred.md` |
| Consumer | `Client_Skill_ResolveCastTarget` `0x0093b3a0` (bit dispatch) |
| UX table | `Skill_FormatFailureMessage` case **0xd** → `"Target out of range."` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Reads skill+0x614` targeting flags | **High** | body + FormatTargetFilterTooltip |
| `May call GatherTargetsInArea` | **High** | callee path `0x0058d330` |
| `Returns target count` | **High** | `local_32` / count |
| **`*outFlags \|= 1` sole site = this body** | **Confirmed** | no-primary `LAB_005504d7` |
| **`*outFlags \|= 2` sole site = this body** | **Confirmed** | after RangeCheck `== g_flZero` |
| Filter writes **only** 4 / 8 / 0x10 | **Confirmed** | Filter dual accept; re-decompile |
| RangeCheck writes **no** outFlags | **Confirmed** | no outFlags formal |
| Filter sole caller = this | **Confirmed** | `get_function_callers(0x0054ff00)` |
| RangeCheck sole caller = this | **Confirmed** | `get_function_callers(0x0058c0a0)` |
| Bit2 UX = `"Target out of range."` via code **0xd** | **High** | ResolveCastTarget + FormatFailure |
| Bit1 UX = `"Nothing is targeted."` | **High** string; product flag name **Probable** | ResolveCastTarget |
| ResolveCastTarget tests bit2 **before** bit1/4/8 | **Confirmed** | re-decompile consumer |
| Full `+0x624` English enum | Tentative / open | behavior sealed |
| Gather ABI product names | Tentative | open |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Wipe 100 TFID → ResolveObject → Filter → Range → gather → count | **Yes** (2026-07-29 re-decompile) |
| No invented damage / eSkillResponses return | **Yes** |
| Bit1/bit2 writer sites only in this body | **Yes** |

### outFlags writer chain (sealed)

```
ResolveObjectTarget
  → Filter (0x0054ff00)           // may OR 4 / 8 / 0x10; returns object*|null
       null  → LAB_no_primary     // maybe OR bit1
       obj   → (type 0x12/0x14 remap)
             → RangeCheck (0x0058c0a0)
                  g_flZero → OR bit2 → LAB_no_primary (may also OR bit1)
                  nonzero  → write primary TFID slot0 → optional Gather
```

| Bit | Writer site | Condition (exact CF) |
|----:|-------------|----------------------|
| **1** | this body `LAB_005504d7` | primary null **or** post-bit2 fallthrough; `skill+0x614&1==0`; `bHasPrimary`; `skill+0x614&0x20==0` (Ground clear) |
| **2** | this body after RangeCheck | `RangeCheck(...) == g_flZero` |
| **4/8/0x10** | Filter only | reject gates (not this body) |

**Dual-bit interaction:** range-fail path ORs bit2 then `goto LAB_005504d7`, which may also OR bit1. Consumer `Client_Skill_ResolveCastTarget` tests `(flags & 2)` **first**, so OOR toast (**0xd**) wins when both set.

---

## 5. Gaps / open

1. Full `+0x624` English enum (behavior sealed; no string table in this unit).
2. Gather 15-arg ABI product names; live multi-target cast capture.
3. Assembly-level formal packing seal (static formals match callers; live optional).
4. Bit-exact / runtime / binary diff — open by policy.

**Verdict residual 2026-07-29 strengthen:** **accept** on dual residual outFlags bits **1/2** this body + Filter/RangeCheck sole-caller link + consumer priority; **accept-with-gaps** on Gather/`+0x624`/runtime.

---

## Checklist

| Check | Result |
|---|---|
| Bit1 writer in this body only | **Pass** |
| Bit2 writer in this body only (RangeCheck produces zero signal) | **Pass** |
| Filter sole caller + bits 4/8/0x10 | **Pass** |
| RangeCheck sole caller + no outFlags formal | **Pass** |
| Consumer bit2 priority + 0xd / “Nothing is targeted.” | **Pass** |
| Verdict | **accept** (writer chain); **accept-with-gaps** (gather/runtime) |
