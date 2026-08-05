# Review A (reconstruction fidelity): `aa_005fe520` hkDefaultAnalogDriverInput_calcStatus

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe520` |
| **VA** | `0x005fe520` |
| **Canonical name** | `hkDefaultAnalogDriverInput_calcStatus` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fe520_hkDefaultAnalogDriverInput_calcStatus.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Builds hk **vehicle driver input status** from analog pedal. Reads reverse-gate flags at fw **+0x20+0x14** and local **+0x3c** to sign-flip **+0x20** pedal into brake **+0xc** (neg * `DAT_00aaa668`) and accel **+0x10** (pos only). Steer via `FUN_005fdf20` → **+0x14**. Handbrake char **+0x18 ← +0x24**. Calls `calcReverse` for reverse byte at **+0x19**. Stock hkDefaultAnalogDriverInput path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fe520_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005fe520_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultAnalogDriverInput_calcStatus.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fe520_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Brake +0xc from negative pedal * DAT_00aaa668 | High | Body |
| Accel +0x10 from positive pedal | High | Body |
| Steer +0x14 from FUN_005fdf20 | High | Body |
| HB +0x18 from +0x24; reverse via calcReverse | High | Body |
| AA may override with entity thr/steer/HB | Medium | WI-MOV notes |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| pedal → brake/accel → steer → HB → calcReverse | Yes |

---

## 5. Gaps / open

1. read_memory DAT_00aaa668 (likely 0.5 or similar).
2. Confirm wire from entity+0x614/618/61c into +0x20/+0x24.

**Verdict:** **accept-with-gaps**
