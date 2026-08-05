# Review A (reconstruction fidelity): `aa_00545f10` MissionDef_SetOwnedString_plus148

| Field | Value |
|---|---|
| **Stable ID** | `aa_00545f10` |
| **VA** | `0x00545f10` |
| **Canonical name** | `MissionDef_SetOwnedString_plus148` (offset-sealed; product field English open) |
| **Ghidra name** | `FUN_00545f10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00545f10_MissionDef_SetOwnedString_plus148.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested from GiveMission → `FUN_00547920` MissionDef_EnsureXmlLoaded |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Replace an owned C-string pointer** on a mission definition at **`this+0x148`**:

1. If `*(this+0x148) != NULL` → `operator_delete[]` old buffer.
2. Store null, measure `strlen(src)`, `operator_new[](len+1)`, copy including terminator.
3. Store new pointer at **`this+0x148`**.

Twin family (same body, different offsets) used by EnsureXml text tags:

| VA | Offset | Twin |
|---|---|---|
| `0x00545f10` | `+0x148` | this unit |
| `0x00545f80` | `+0x14c` | Title / toast-name path (GiveMission uses `def+0x14c`) |
| `0x00545ff0` | `+0x150` | sibling |
| `0x00546060` | `+0x154` | sibling |
| `0x005460d0` | `+0x158` | sibling |

**ABI:** `__thiscall(MissionDef* this, char* src)` — stack string, ECX def; typical `RET 4`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00545f10_FUN_00545f10.md` |
| Annotated | `docs/reconstruction/raw/aa_00545f10_FUN_00545f10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00545f10.cpp` |
| Function record | `docs/reconstruction/functions/aa_00545f10_FUN_00545f10.md` |
| Live decompile | ≡ raw |
| Live bytes | `read_memory` — imm `0x148` in loads/stores |
| Parent | `A/B_aa_00547920_MissionDef_EnsureXmlLoaded` |

**Not performed:** which exact XML tag binds to `+0x148` (string match in EnsureXml open), Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Owned string replace at `+0x148` | **High** | body |
| Delete-old then copy | **High** | |
| Twin pattern with +4 offsets | **High** | batch decompile siblings |
| Used from EnsureXml | **High** | nested from parent raw |
| Product field English for `+0x148` | **Open** | not Title (`+0x14c` stronger for toast) |
| Empty-src behavior | **High** | still allocates 1-byte `""` |

---

## 4. Gaps

1. Exact XML tag → `+0x148` binding.
2. Whether any non-mission object reuses this thunk (xrefs not exhaustively classified).

**Verdict:** Mechanical owned-string setter High. **accept-with-gaps.**
