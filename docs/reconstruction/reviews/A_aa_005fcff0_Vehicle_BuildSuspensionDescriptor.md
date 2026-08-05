# Review A (reconstruction fidelity): `aa_005fcff0` Vehicle_BuildSuspensionDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fcff0` |
| **VA** | `0x005fcff0` |
| **Canonical name** | `Vehicle_BuildSuspensionDescriptor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fcff0_Vehicle_BuildSuspensionDescriptor.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill suspension descriptor blob for `hkDefaultSuspension_ctor` (size **0x68**), called only from `Vehicle_buildHavokVehicleFramework`. Pulls wheel count (`FUN_004f5560`), per-wheel suspension params from clonebase/chassis (including tank wheel count path via chassis **+0x258 / +0x4cc** family), grows arrays via `FUN_005b3300`. Large body (~183 lines, if×14) — primary suspension setup for retail vehicle feel.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fcff0_Vehicle_BuildSuspensionDescriptor.md` (or `aa_005fcff0_FUN_005fcff0.md`) |
| Annotated | `docs/reconstruction/raw/aa_005fcff0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_BuildSuspensionDescriptor.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fcff0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Sole suspension desc for framework` | High | Caller buildHavokVehicleFramework |
| `Wheel count via FUN_004f5560` | High | Shared with steering desc |
| `Array grow FUN_005b3300` | High | Callees |
| `Feeds hkDefaultSuspension 0x68` | High | Framework plate |
| `Exact per-wheel float field map` | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Query wheels → fill desc arrays → return | Yes |
| No invented engine torque | Yes |

---

## 5. Gaps / open

1. Seal per-wheel suspension field offsets.
2. Document tank vs car differences.

**Verdict:** **accept-with-gaps**
