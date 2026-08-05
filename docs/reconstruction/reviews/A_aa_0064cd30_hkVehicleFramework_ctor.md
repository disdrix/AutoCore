# Review A (reconstruction fidelity): `aa_0064cd30` hkVehicleFramework_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064cd30` |
| **VA** | `0x0064cd30` |
| **Canonical name** | `hkVehicleFramework_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0064cd30_hkVehicleFramework_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Constructs hkVehicleFramework from setup/descriptor param: vtable install, zero/init fields, calls **initFromDescriptor**, wires component linkage path used by `Vehicle_buildHavokVehicleFramework`. Thin-mid ctor (~119 lines) with residual FUN_* for base hk classes.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0064cd30_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0064cd30_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkVehicleFramework_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_0064cd30_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Ctor → initFromDescriptor` | High | Callee |
| `Framework object lifetime start` | High | Name + callers |
| `Full field zero map` | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| base init → initFromDescriptor → return this | Yes |

---

## 5. Gaps / open

1. List all zeroed offsets.

**Verdict:** accept-with-gaps
