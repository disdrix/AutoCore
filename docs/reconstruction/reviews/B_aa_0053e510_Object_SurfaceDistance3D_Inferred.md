# Review B (skeptical / adversarial): `aa_0053e510` Object_SurfaceDistance3D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053e510` |
| **VA** | `0x0053e510` |
| **Canonical name** | `Object_SurfaceDistance3D_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B — OWN-ONLY W25-H) |
| **Counterpart** | `reviews/A_aa_0053e510_Object_SurfaceDistance3D_Inferred.md` |
| **System** | shared-object-pose / AI-range |
| **Live tools** | Independent decompile + `read_memory` entry/tail; contrast `00404c90` and XZ helper notes from `004e8930` family |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | XZ-only / horizontal gap (like `FUN_004e8930`) | **Falsified** — three components in decomp; dy included |
| 2 | Returns center-center distance (no radii) | **Falsified** — tail `fsub [ecx+0x34]` and `[edx+0x34]` |
| 3 | Only one object uses physics path | **Falsified** — both A and B independently gated on `+8` |
| 4 | Calls `FUN_00404c90` | **Falsified** — paths inlined; no CALL callees |
| 5 | Same as `CVOGPhysicsUtils::FindDistanceToTarget` | **Falsified** — that util is multi-path physics/profiled; this is pure leaf math |
| 6 | Parent-seed name is product identity | **Overclaim** — FireWeapons is one consumer of many |
| 7 | `+0x34` proven “collision radius” product term | **Partial** — role is radius-like subtract; English open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3D Euclidean − rA − rB | **High** | Wrong range gates in AI/interact ports |
| Dual world-pos resolve | **High** | Wrong pos when unmounted vs phys |
| Separation from FindDistanceToTarget | **High** | Over-engineer or wrong fail-zero semantics |
| Product name | **None** | — |
| Exact radius English | **Partial** | Mislabel UI vs collision |

---

## 3. CF challenge of Review A

- Dual pos + 3D + both radii: **agree High**
- thiscall ret 4: **agree High**
- accept-with-gaps: **agree**

### Residual

Ghidra labels `__thiscall` with both formals — correct for MSVC this + 1 stack arg. Clean plate using `std::sqrt` is **behavior plate**, not bit-exact x87; bit-exact open (declared).

---

## 4. Safe vs unsafe

| Safe | Unsafe |
|---|---|
| Surface gap = center dist − rA − rB (3D) | “LOS” or “path distance” |
| Inlined GetWorldPositionPtr dual | Requires PhysX / FindDistanceToTarget |
| Used by AI pursue / fire / interact | Only FireWeapons helper |

**Verdict:** **accept-with-gaps** — reject XZ-only / product-name claims; accept sealed math leaf.
