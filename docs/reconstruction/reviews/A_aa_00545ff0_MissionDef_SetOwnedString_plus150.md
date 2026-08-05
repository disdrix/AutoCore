# Review A (reconstruction fidelity): `aa_00545ff0` MissionDef_SetOwnedString_plus150

| Field | Value |
|---|---|
| **Stable ID** | `aa_00545ff0` |
| **VA** | `0x00545ff0` |
| **Canonical name** | `MissionDef_SetOwnedString_plus150` (offset-sealed; product English open) |
| **Ghidra name** | `FUN_00545ff0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00545ff0_MissionDef_SetOwnedString_plus150.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested from GiveMission → `FUN_00547920` MissionDef_EnsureXmlLoaded |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Owned C-string replace identical to `FUN_00545f10` / `FUN_00545f80`, targeting **`this+0x150`**:

1. Free old `*(this+0x150)` if non-null (`operator_delete[]`).
2. `operator_new[](strlen+1)` + copy including terminator.
3. Store at **`this+0x150`**.

Part of EnsureXml mission-def text field loader cluster (`+0x148`..`+0x158` twins).

```c
void __thiscall MissionDef_SetOwnedString_plus150(MissionDef* this, char* src);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00545ff0_FUN_00545ff0.md` |
| Annotated | `docs/reconstruction/raw/aa_00545ff0_FUN_00545ff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00545ff0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00545ff0_FUN_00545ff0.md` |
| Live decompile | `batch_decompile` `0x00545ff0` ≡ raw |
| Twins | `A/B_aa_00545f10_*`, `A/B_aa_00545f80_*` |
| Parent | `A/B_aa_00547920_MissionDef_EnsureXmlLoaded` |

**Not performed:** exact XML tag binding, Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Owned string at **`+0x150`** | **High** | decompile imm |
| Same free/alloc/copy algorithm as twins | **High** | |
| Nested EnsureXml residual | **High** | parent raw xref |
| Product English | **Open** | Description / OneLine / other tag candidates |

---

## 4. Gaps

1. Which EnsureXml tag writes `+0x150`.
2. Wide-string sibling fields not this unit.

**Verdict:** Mechanics High. **accept-with-gaps.**
