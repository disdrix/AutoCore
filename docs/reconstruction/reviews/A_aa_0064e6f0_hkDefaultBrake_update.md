# Review A (reconstruction fidelity): `aa_0064e6f0` hkDefaultBrake_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064e6f0` |
| **VA** | `0x0064e6f0` |
| **Canonical name** | `hkDefaultBrake_update` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064e6f0_hkDefaultBrake_update.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Havok **default brake component update** (WI-MOV-005). Reads framework status **fw+0x14**: brake pedal **+0x10**, handbrake **+0x18**. Per wheel: lock candidate `doesBrake && HB` → **brake+0x1c[i]**; torque to **brake+0x10[i]** from wheel spin / min(maxTorque*pedal). Uses dt `param_2[0]` and wheel data stride **0xC0**. Wheel-spin ≤ pedal gate sets lock pass; uses **+0x50** timer vs **+0x4c** reset. Live coast when pedal≈0 and HB off (torque ~0).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064e6f0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0064e6f0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultBrake_update.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064e6f0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Pedal fw+0x14+0x10; HB +0x18 | High | WI-MOV-005 + body |
| Per-wheel torque @ brake+0x10; locks +0x1c | High | Body |
| Wheel info stride 0xC0 in spin term | High | iVar9 += 0xC0 |
| Timer +0x50 for lock engagement | High | Body tail |
| Service brake vs AA handbrake entity+0x61c | Medium | Dual systems |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| read pedal/HB → per-wheel torque/lock → maybe timer lock pass | Yes |

---

## 5. Gaps / open

1. Confirm AA still runs hkDefaultBrake_update via tickSubsystems.
2. Map maxTorque tables at +0x28/+0x34.

**Verdict:** **accept-with-gaps**
