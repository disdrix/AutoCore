# Review A (reconstruction fidelity): `aa_00546140` MissionDef_SetOwnedString_NotCompleteText

| Field | Value |
|---|---|
| **Stable ID** | `aa_00546140` |
| **VA** | `0x00546140` |
| **Canonical name** | `MissionDef_SetOwnedString_NotCompleteText` (tag-sealed; offset `+0x15c`) |
| **Ghidra name** | `FUN_00546140` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00546140_MissionDef_SetOwnedString_NotCompleteText.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested EnsureXml `NotCompleteText` tag |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Owned C-string replace at **`this+0x15c`**. XML tag: **`NotCompleteText`**.

```c
void __thiscall MissionDef_SetOwnedString_NotCompleteText(MissionDef* this, char* src);
```

Algorithm: free-old → null → `new[](len+1)` → copy → store (identical to `0x00546060` cluster).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00546140_*`, `reconstructed-exact/FUN_00546140.cpp` |
| Live decompile | `batch_decompile` `0x00546140` ≡ raw |
| Parent dual | `A/B_aa_00547920_MissionDef_EnsureXmlLoaded` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Offset **`+0x15c`** | **High** | |
| Tag **NotCompleteText** | **High** | parent map |
| Twin algorithm | **High** | |
| Sole EnsureXml caller | **High** | |

**Verdict:** **accept**.
