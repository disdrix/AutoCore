# Review A (reconstruction fidelity): `aa_007fbd30` UiProgressBar_BindFromRanges (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbd30` |
| **VA** | `0x007fbd30` |
| **Canonical name** | `UiProgressBar_BindFromRanges` (**INFERRED**) |
| **Ghidra symbol** | `FUN_007fbd30` |
| **Review date** | `2026-07-29` |
| **Counterpart** | `reviews/B_aa_007fbd30_UiProgressBar_BindFromRanges_Inferred.md` |
| **System** | UI (AddItem widget refresh nested) |
| **Parent batch** | AddItem → `FUN_0089c6c0` widget path |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bind a progress/slider widget (ESI) from a source control (EAX)** using three virtual getters and range math:

| Vtbl | Role (inferred) |
|-----:|-----------------|
| source `+0x490` | max / high |
| source `+0x494` | low / current floor |
| source `+0x49c` | value |
| dest `+0x460` | set scale / step |
| dest `+0x454` | set fraction pair |
| dest `+0xd4` | set enabled/visible-ish flag |
| dest `+0x34c` | refresh/draw (tail always) |

```c
// EAX = source*; ESI = dest widget*; EDI = float scale register
void UiProgressBar_BindFromRanges(void);
```

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | ≡ raw (3 branches + tail vcall) |
| Live bytes | null checks on EDI/ESI; `call [eax+0x490]` family |
| Xrefs | 15 UI sites including `0x0089c7cd` / `0x0089c7de` (widget dual-pane) |
| Raw | `raw/aa_007fbd30_FUN_007fbd30.md` |

---

## 3. Control flow

| Branch | Condition | Dest updates | Confidence |
|---|---|---|---|
| A | `low < high` | scale `1/(high-low)`; frac `value/EDI`; flag 1 | **High** CF |
| B | else if `value > 0` | scale `1/value`; frac `1-EDI`; flag 1; goto refresh | **High** |
| C | else | scale `1.0f`; frac `(0,1)`; flag 0 | **High** |
| Tail | always | `dest->vtbl+0x34c()` | **High** |
| Null EAX or ESI | early return | **High** |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| UI progress bind helper | **High** |
| Three source getters + dest setters | **High** |
| Product widget class names | **Open** |
| Exact EDI float provenance | **Probable** (register residual) |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — widget math leaf for inventory dual-pane refresh chain.
