# Review A (reconstruction fidelity): `aa_00501420` Vehicle_TryActivatePhysics

| Field | Value |
|---|---|
| **Stable ID** | `aa_00501420` |
| **VA** | `0x00501420` |
| **Canonical name** | `Vehicle_TryActivatePhysics` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00501420_Vehicle_TryActivatePhysics.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Attempt to activate vehicle physics body / enter simulation (`__thiscall`, large stack workspace ~0x160). Gates on vehicle state, builds/activates Havok rigid body path, may call into createVehicleAction / framework wiring when activation succeeds. High-value enter-world physics gate paired with `Vehicle_ActivateEnterWorld`. Body ~268 lines with multiple early-outs; residual: exact param_2–4 roles and every failure path not fully named.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00501420_Vehicle_TryActivatePhysics.md` (or `aa_00501420_FUN_00501420.md`) |
| Annotated | `docs/reconstruction/raw/aa_00501420_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_TryActivatePhysics.cpp` |
| Function record | `docs/reconstruction/functions/aa_00501420_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Physics activation entry for vehicle` | High | Name + call graph role |
| `Large local workspace for transform/body` | High | Stack frame size |
| `Multiple early-out failure paths` | High | if×8 CF |
| `Pairs ActivateEnterWorld / createVehicleAction` | High | Lifecycle graph |
| `Exact param_2–4 semantics` | Medium | Decompiler names weak |
| `Full success path RB activate sequence` | Medium | FUN_* residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Gate → prepare → activate or fail | Yes |
| No invented thr/steer writes | Yes |

---

## 5. Gaps / open

1. Name every FUN_* on success path.
2. Seal param_2–4 (likely pose/flags).
3. Document failure return codes.

**Verdict:** **accept-with-gaps**
