# Review A (reconstruction fidelity): `aa_005fe610` hkDefaultAnalogDriverInput_update_candidate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe610` |
| **VA** | `0x005fe610` |
| **Canonical name** | `hkDefaultAnalogDriverInput_update_candidate` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fe610_hkDefaultAnalogDriverInput_update_candidate.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Trivial class-info / type-id getter: returns address of ``DAT_00d02878`` (static type blob). Not the per-frame analog update body — name is candidate/historical. Single-instruction return-pointer pattern shared with other Havok getClass slots.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fe610_hkDefaultAnalogDriverInput_update_candidate.md` |
| Annotated | `docs/reconstruction/raw/aa_005fe610_hkDefaultAnalogDriverInput_update_candidate.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkDefaultAnalogDriverInput_update_candidate.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fe610_hkDefaultAnalogDriverInput_update_candidate.md` |
| Fresh Ghidra | `batch_decompile` @ `0x005fe610` (2026-07-29) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Returns &DAT_00d02878 only` | High | Decompile single return |
| `Not the tick/update force path` | High | Body size |
| `Role = class/type getter` | Probable | Pattern match chassis getClass |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| r | e |
| Y | e |

---

## 5. Gaps / open

1. Confirm DAT_00d02878 layout / class name string.
2. Rename residual if English type name recovered.

**Verdict:** accept-with-gaps
