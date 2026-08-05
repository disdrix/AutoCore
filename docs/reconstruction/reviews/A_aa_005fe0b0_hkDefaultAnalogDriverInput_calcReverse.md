# Review A (reconstruction fidelity): `aa_005fe0b0` hkDefaultAnalogDriverInput_calcReverse

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe0b0` |
| **VA** | `0x005fe0b0` |
| **Canonical name** | `hkDefaultAnalogDriverInput_calcReverse` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fe0b0_hkDefaultAnalogDriverInput_calcReverse.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Havok **analog driver input reverse detection**. `__thiscall(this, outChar*)`. Uses chassis transform vs velocity dot-product; if reverse/gear conditions vs `DAT_009dd34c` / `_DAT_009dd380` thresholds and status flags at framework **+0x20+0x14**, writes `*out=1` else leaves. Feeds `calcStatus` reverse bit. WI-MOV driver-input path companion to AA VehicleAction (AA may bypass).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fe0b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005fe0b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultAnalogDriverInput_calcReverse.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fe0b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Writes reverse flag to *param_2 | High | Body |
| Uses chassis basis + velocity dots | High | Body math |
| Thresholds DAT_009dd34c / 009dd380 | High | Body |
| Stock hk path may be unused when AA owns input | Medium | Architecture note |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| read chassis/vel → threshold tests → *out=0/1 | Yes |

---

## 5. Gaps / open

1. read_memory thresholds.
2. Confirm AA still calls stock calcStatus or replaces.

**Verdict:** **accept-with-gaps**
