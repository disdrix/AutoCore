# Review A (reconstruction fidelity): `aa_00989030` gfxIndexBufferImpl_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00989030` |
| **VA** | `0x00989030` |
| **Canonical name** | `gfxIndexBufferImpl_Unserialize` |
| **System** | `graphics / gfx` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00989030_gfxIndexBufferImpl_Unserialize.md` |
| **Verdict** | **accept-with-gaps** |
| **Evidence** | Ghidra MCP `batch_decompile` 2026-07-29; raw/annotated/clean three-rep present |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00989030_gfxIndexBufferImpl_Unserialize.md` |
| Raw | `docs/reconstruction/raw/aa_00989030_gfxIndexBufferImpl_Unserialize.md` |
| Annotated | `docs/reconstruction/raw/aa_00989030_gfxIndexBufferImpl_Unserialize.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxIndexBufferImpl_Unserialize.cpp` |

---

## 2. Purpose (from unit)

Unserialize **INDX** (`0x494e4458` / XDNI) from a chunk reader. Accepts versions **1–2**:

- **v1:** after enter-scope, falls through to body read (plate: `u32 count` + u16 index data; index size always 2).
- **v2:** optional id/size path via `FUN_00734690` + `FUN_0044c370` / `FUN_0044c340` (returns **`0xfffffffe`** on id mismatch); then same body path.

Creates/fills device IB via `FUN_00988f20` with usage flags **`0x20`** or **`0x18`** (depends on `*param_3` context flags). Locks IB (`vtbl+0x2c`, flags **`0x800`**), reads data (`FUN_0044ed70`), unlocks via `FUN_0044b8b0`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Tag must be `0x494e4458` else −1 + invalid-tag log | **High** | Literal compare |
| Version ≠1 and ≠2 → invalid version log + −1 | **High** | CF |
| Version 2 id path can return `0xfffffffe` | **High** | Explicit early return |
| Usage flag 0x20 default; 0x18 if context+0x14 flag | **High** | Ternary on `*param_3` |
| Device Lock vtbl+0x2c, flags 0x800; lockCount++ | **High** | Symmetric to Serialize unlock |
| Enter/leave chunk scope + SEH | **High** | stoChunkReader_EnterChunkScope / FUN_00769e40 |
| Clean ≡ raw CF | **High** | Scaffold |
| Exact v1 vs v2 header field widths in FUN_* | **Medium** | Plate comments; callees not owned |
| Runtime / bit-exact | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| EnterChunkScope(reader) | **Yes** |
| tag ≠ INDX → log + leave + −1 | **Yes** |
| version 1 → body path | **Yes** |
| version 2 → id helpers; fail → −2 (`0xfffffffe`); else body | **Yes** |
| other version → log + −1 | **Yes** |
| Read count (two paths on reader+0x4044); create IB; lock; read; unlock | **Yes** |
| return uVar7 status | **Yes** |

---

## 5. Gaps

1. Name `FUN_00988f20` (create IB from count + usage).
2. Seal `FUN_00437050` / `FUN_00768760` as count/string readers vs reader mode.
3. Full v1/v2 header layout against retail .geo (plate is strong but not re-verified here).

**Verdict:** **accept-with-gaps**
