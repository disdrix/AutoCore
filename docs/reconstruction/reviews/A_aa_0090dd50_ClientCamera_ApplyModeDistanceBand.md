# Review A (reconstruction fidelity): `aa_0090dd50` ClientCamera_ApplyModeDistanceBand

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090dd50` |
| **VA** | `0x0090dd50` |
| **Canonical name** | `ClientCamera_ApplyModeDistanceBand` |
| **Prior names** | `FUN_0090dd50`, `Named_CalleeOf_Client_RecvCreateCharacter_0090dd50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_0090dd50_ClientCamera_ApplyModeDistanceBand.md` |
| **System** | client / camera |
| **Verdict** | **accept** — leaf mode→distance-band table + clamp **sealed** |

---

## 1. Purpose

After callers restore a camera **mode** into `cam+0x60c`, recompute distance **min/max/rate** from that mode and **clamp** current distance fields into the band. No side effects beyond camera float fields and global reads.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0090dd50_FUN_0090dd50.md` |
| Annotated | `docs/reconstruction/raw/aa_0090dd50_FUN_0090dd50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ClientCamera_ApplyModeDistanceBand.cpp` |
| Function record | `docs/reconstruction/functions/aa_0090dd50_ClientCamera_ApplyModeDistanceBand.md` |
| Live decompile | Ghidra `decompile_function` `0x0090dd50` ≡ raw CF |
| Live bytes | `read_memory` entry + epilogue; float pool `@0x00af9150`, `0x00a0f298` |
| Meta | body `0090dd50`–`0090df0f`; callees **none** |
| Caller context | Respawn Update/dtor reviews (`+0x60c` write then call) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

- Object in **EAX** (`in_EAX` in decompiler).
- **No** stack arguments; epilogue plain **`RET`** (`C3`).
- **Leaf** — no callees.

### 3.2 Mode table — **SEALED**

| mode | min | max | rate | extra |
|---:|---:|---:|---|---|
| 0 | 2 | 11 if `DAT_00d1b26c==0` else 16 | (max−min)/16 | if `DAT_00d1b6d8` & flag`+0x6b9`: init `+0x52c/+0x530` from secondary (20/30 − 6) |
| 1 | 6 | 20 or 30 | (max−min)/16 | — |
| else | 12 | 20 | 0.5 | force both currents = 20 |

Float constants confirmed via `read_memory` LE float decode.

### 3.3 Clamp — **SEALED**

Both `+0x530` and `+0x52c` clamped into `[+0x524, +0x528]` after mode setup. Decompiler compare noise ≡ inclusive clamp.

### 3.4 clean ≡ raw CF

| Stage | Match |
|---|---|
| mode==0 / ==1 / else | **Yes** |
| `DAT_00d1b26c` max select | **Yes** |
| mode-0 secondary flag path | **Yes** |
| rate formula | **Yes** |
| dual clamp | **Yes** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf float recompute from mode | **High** | decompile + zero callees |
| Float pool values | **High** | `read_memory` |
| EAX ABI / RET | **High** | bytes + decompiler |
| Field map +0x524..+0x534, +0x60c | **High** | consistent stores |
| Product mode names | **Open** | no strings in unit |
| `DAT_00d1b26c` meaning | **Open** | flag only |
| Canonical name | **Probable** | behavior+callers; not format-string sealed |
| Runtime | **Open** | deferred |

---

## 5. Gaps

1. Product names for modes 0/1/≥2.
2. What `DAT_00d1b26c` selects (UI option / aspect / vehicle).
3. Full camera type size beyond touched fields.
4. Live runtime dump of fields under each mode.
5. Whether mode-0 without flag path intentionally leaves stale currents (yes per CF — only clamps).

**Verdict:** **accept**
