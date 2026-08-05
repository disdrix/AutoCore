# Review A (reconstruction fidelity): `aa_0064d810` hkAngularVelocityDamper_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064d810` |
| **VA** | `0x0064d810` |
| **Canonical name** | `hkAngularVelocityDamper_update` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064d810_hkAngularVelocityDamper_update.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Per-step AVD: load RB angVel from action context chassis ``param_3+0x30 → +0x3c`` RB; if |w|² ≤ threshold² use normalSpinDamping else collisionSpinDamping; scale = max(0, 1 - d*dt); write scaled angVel via RB vtbl+0x54. Verified physics note ``fn_0064d810_avd.md``.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064d810_hkAngularVelocityDamper_update.md` |
| Annotated | `docs/reconstruction/raw/aa_0064d810_hkAngularVelocityDamper_update.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkAngularVelocityDamper_update.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064d810_hkAngularVelocityDamper_update.md` |
| Fresh Ghidra | `batch_decompile` @ `0x0064d810` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `angVel from RB +0x50/+0x54/+0x58` | High | Body + verified |
| `threshold at this+0x10` | High | ctor pairs |
| `normal +8 / collision +0xc * dt` | High | Branch |
| `clamp scale >= 0 then apply` | High | g_flOne - d*dt |
| `RB setter vtbl+0x54` | High | Indirect call |
| `FUN_005070b0/d0 side path exact` | Medium | Assert/helper residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| l | o |
| Y | e |

---

## 5. Gaps / open

1. Assert helpers 005070b0/d0 English.
2. Runtime |w| threshold capture.

**Verdict:** accept-with-gaps
