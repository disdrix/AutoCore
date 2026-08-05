# Review A (reconstruction fidelity): `aa_00546220` MissionDef_SetOwnedString_FailText

| Field | Value |
|---|---|
| **Stable ID** | `aa_00546220` |
| **VA** | `0x00546220` |
| **Canonical name** | `MissionDef_SetOwnedString_FailText` (tag-sealed; offset `+0x164`) |
| **Ghidra name** | `FUN_00546220` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00546220_MissionDef_SetOwnedString_FailText.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested EnsureXml `FailText` tag (last text setter in cluster) |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Owned C-string replace at **`this+0x164`**. XML tag: **`FailText`**.

```c
void __thiscall MissionDef_SetOwnedString_FailText(MissionDef* this, char* src);
```

Closes the EnsureXml mission-def text-field twin run:

| Offset | Setter VA | Tag |
|--------|-----------|-----|
| `+0x148` | `0x00545f10` | Internal |
| `+0x14c` | `0x00545f80` | Title |
| `+0x150` | `0x00545ff0` | Description |
| `+0x154` | `0x00546060` | OneLineAccept |
| `+0x158` | `0x005460d0` | OneLineReject |
| `+0x15c` | `0x00546140` | NotCompleteText |
| `+0x160` | `0x005461b0` | CompleteText |
| `+0x164` | `0x00546220` | FailText |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00546220_*`, `reconstructed-exact/FUN_00546220.cpp` |
| Live decompile | `batch_decompile` `0x00546220` ≡ raw |
| Parent dual | `A/B_aa_00547920_MissionDef_EnsureXmlLoaded` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Offset **`+0x164`** | **High** | |
| Tag **FailText** | **High** | parent map |
| End of contiguous string-pointer block | **High** | sequential +4 |
| Not related to Requirements at `0x005462b0` | **High** | adjacent VA only |

**Verdict:** **accept**.
