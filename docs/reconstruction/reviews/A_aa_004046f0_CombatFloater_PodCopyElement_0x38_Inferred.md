# Review A (reconstruction fidelity): `aa_004046f0` CombatFloater_PodCopyElement_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004046f0` |
| **VA** | `0x004046f0` |
| **Canonical name** | `CombatFloater_PodCopyElement_0x38_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004046f0_CombatFloater_PodCopyElement_0x38_Inferred.md` |
| **System** | `missions-progression` / combat floater UI |
| **Verdict** | **accept** |

---

## 1. Purpose

POD copy of one combat-floater element: if `dst != null`, copy **14 dwords** (`0xe` iterations) from `src` to `dst` = **0x38 bytes**. Leaf helper for `ConstructN` and (transitively) grow/insert paths.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Ghidra decompile | `0x004046f0` |
| Raw | `docs/reconstruction/raw/aa_004046f0_FUN_004046f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004046f0.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 14× dword copy | **High** | `for (i=0xe; i; --i)` |
| Null dst skips | **High** | Guard |
| No callees | **High** | Leaf |
| Element size **0x38** | **High** | 14×4 |

---

## 4. Gaps

1. Field-level floater layout (type at which offset for XP=3).

**Verdict:** **accept**
