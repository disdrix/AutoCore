# Review A (reconstruction fidelity): `aa_005460d0` MissionDef_SetOwnedString_OneLineReject

| Field | Value |
|---|---|
| **Stable ID** | `aa_005460d0` |
| **VA** | `0x005460d0` |
| **Canonical name** | `MissionDef_SetOwnedString_OneLineReject` (tag-sealed; offset `+0x158`) |
| **Ghidra name** | `FUN_005460d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005460d0_MissionDef_SetOwnedString_OneLineReject.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested EnsureXml `OneLineReject` tag ← GiveMission / CompleteObjective hydrate |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Identical owned-string replace algorithm as `FUN_00546060`, targeting **`this+0x158`**.

XML product field: **`OneLineReject`**.

```c
void __thiscall MissionDef_SetOwnedString_OneLineReject(MissionDef* this, char* src);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005460d0_FUN_005460d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005460d0_FUN_005460d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005460d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005460d0_FUN_005460d0.md` (if present under FUN_*) |
| Live decompile | `batch_decompile` `0x005460d0` ≡ raw |
| Parent | `A/B_aa_00547920_MissionDef_EnsureXmlLoaded` |
| Twin | `A_aa_00546060_*` (`+0x154`) |

**Not performed:** Launcher / CE / bit-exact / `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Store at **`+0x158`** | **High** | imm in decompile |
| Same free/alloc/copy as twins | **High** | |
| Tag **OneLineReject** | **High** | parent tag chain |
| Sole caller EnsureXml | **High** | |
| clean ≡ raw | **High** | |

---

## 4. Gaps

1. UI reject-line consumers open.

**Verdict:** **accept**.
