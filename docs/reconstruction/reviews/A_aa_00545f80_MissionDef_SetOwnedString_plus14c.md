# Review A (reconstruction fidelity): `aa_00545f80` MissionDef_SetOwnedString_plus14c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00545f80` |
| **VA** | `0x00545f80` |
| **Canonical name** | `MissionDef_SetOwnedString_plus14c` (offset-sealed; **Title / toast name** probable) |
| **Ghidra name** | `FUN_00545f80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00545f80_MissionDef_SetOwnedString_plus14c.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested from GiveMission → `FUN_00547920` EnsureXmlLoaded; GiveMission toast reads **`def+0x14c`** |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Identical owned C-string replace as `FUN_00545f10`, targeting **`this+0x14c`**:

1. Free prior `*(this+0x14c)` if non-null.
2. Allocate/copy `src` including `NUL`.
3. Store pointer at **`this+0x14c`**.

**Cross-unit seal:** GiveMission residual maps **`def+0x14c`** as localized mission title key used when packing the “Received Mission” toast (`sprintf` + `FUN_0040c5c0`). EnsureXml loads title text into this slot via this setter (or equivalent path).

```c
void __thiscall MissionDef_SetOwnedString_plus14c(MissionDef* this, char* src);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00545f80_FUN_00545f80.md` |
| Annotated | `docs/reconstruction/raw/aa_00545f80_FUN_00545f80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00545f80.cpp` |
| Function record | `docs/reconstruction/functions/aa_00545f80_FUN_00545f80.md` |
| Live decompile | ≡ raw; offset imm **`0x14c`** |
| Twin | `A/B_aa_00545f10_*` (+0x148) |
| Consumer | GiveMission toast path (`A_aa_005327c0_*` — `+0x14c` title key) |
| Parent | EnsureXml `A/B_aa_00547920_*` |

**Not performed:** Launcher, live XML tag capture.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Owned string at **`+0x14c`** | **High** | body |
| Same algorithm as +0x148 twin | **High** | decompile diff is offset only |
| GiveMission toast uses `def+0x14c` | **High** | parent dual residual |
| Product English = Title | **Probable** | toast + EnsureXml “Title” tag family |
| Exact XML tag binding in this VA | **Tentative** | needs EnsureXml call-site string |

---

## 4. Gaps

1. Confirm call site from EnsureXml passes Title vs other tag.
2. Wide vs narrow storage (this unit is narrow `char*`).

**Verdict:** Offset + mechanics High; Title English Probable. **accept-with-gaps.**
