# Review A (reconstruction fidelity): `aa_008af180` UI_MissionPanel_SyncSlotVisibilityAndLayout

| Field | Value |
|---|---|
| **Stable ID** | `aa_008af180` |
| **VA** | `0x008af180` |
| **Canonical name** | `UI_MissionPanel_SyncSlotVisibilityAndLayout` |
| **Ghidra name** | `FUN_008af180` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W21-Q) |
| **Counterpart** | `reviews/B_aa_008af180_UI_MissionPanel_SyncSlotVisibilityAndLayout.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mission UI **slot panel** worker:

```text
if !DAT_00d1b6d8: return
if !DAT_00af92d4: Release all child widgets (vtbl+4); return

// sync 3 feature slots + medals slot vs globals / resource key
// forceRelayout OR= any visibility change
if !forceRelayout: return

// count visible among 4 primaries
// layout by count (0 hide chrome / 1 single / 2+ multi)
// host.vtbl+0x34c()
```

Product string on medals path: **"Click to View Your Medals!"** (`0x00a4a27c`); texture suffix **`.dds`**.

---

## 2. Calling convention

| Slot | Role | Evidence |
|------|------|----------|
| ESI | Panel host | Class methods `mov esi,ecx/edi`; RecvComplete `mov esi,[dialog+0x684]` |
| stack | `forceRelayout` char | `push 0` / `push 1` at all call sites |
| Return | void | ends layout + ret |
| Frame | `sub esp, 0x15c` | prologue `read_memory` |

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_008af180_*`, `UI_MissionPanel_SyncSlotVisibilityAndLayout.cpp` |
| Live decompile | Ghidra full body (~24k chars) |
| Prologue bytes | `read_memory` 48 B |
| Call sites | 9 xrefs via `get_assembly_context` |
| Constants | `.dds`, medals string, scale f32s @ `0x00aaa678`–`ac` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null `DAT_00d1b6d8` early out | **Yes** |
| Teardown when `DAT_00af92d4==0` | **Yes** (Release path) |
| Feature pairs 0x155/154/153 | **Yes** |
| Medals `+0x156` + `.dds` + caption | **Yes** |
| force==0 skip layout | **Yes** |
| Visible count 0/1/2+ branches | **Yes** |
| Host `vtbl+0x34c` | **Yes** |
| Pixel-exact multi-slot math | **Partial** (decomp unaff EBP/EDI temps) |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = mission panel slot sync/layout | **High** |
| ESI + force ABI | **Confirmed** |
| Medals string product evidence | **Confirmed** |
| Scale constants | **Confirmed** |
| Feature-flag English | **Open** |
| Geometry bit-exact | **Tentative** |
| Teardown infinite-loop decomp artifact | **Sealed as residual** (not product hang claim) |
| Runtime | **Open** |

---

## 6. Gaps / open

1. Product names for `DAT_00d17928/29/2a` feature flags.
2. Full multi-slot placement math residual (unaff register temps in decomp).
3. Whether `dialog+0x684` child is same class as panel `this` (layout compatible — **yes** by use; RTTI open).
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — ABI, stages, medals string, and scale constants sealed; pixel math + flag English open.
