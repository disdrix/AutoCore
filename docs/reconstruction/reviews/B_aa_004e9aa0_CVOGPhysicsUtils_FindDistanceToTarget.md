# Review B (skeptical / adversarial): `aa_004e9aa0` CVOGPhysicsUtils_FindDistanceToTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e9aa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e9aa0_CVOGPhysicsUtils_FindDistanceToTarget.md` |
| **Verdict** | **accept** on product name + measure role; **accept-with-gaps** on simple-path return / full geometry |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Name is only inferred from callers | **Falsified** — string `"CVOGPhysicsUtils::FindDistanceToTarget"` DATA xref `004e9aca` |
| 2 | Always pure Euclidean 3D | **Falsified** — simple path is XZ via `FUN_004e8930`; complex path is sample-ring + PhysX residual |
| 3 | Always returns true world distance | **Overstated** — fail returns 0; complex success can return hit residual `fStack_4e0 - param_2`; simple-path decomp returns `phys+0x34` (suspicious) |
| 4 | Skill-only | **Falsified** — weapon/UI callers (`FUN_0056*`, `FUN_00955eb0`) |
| 5 | Same as RangeCheck body | **Falsified** — RangeCheck is consumer; this is the measure helper |
| 6 | String is dead/coincident | **Falsified** — live DATA xref from prologue region of **this** function |
| 7 | `param_7` simple path is the RangeCheck path | **Unproven** — RangeCheck arity incomplete in decomp; which path RangeCheck hits is **Partial** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Product name | **Confirmed** | Cosmetic only if wrong (won't be) |
| Role = distance/range measure | **High** | Wrong skill range port |
| Fail → 0 | **High** | False range OK |
| Simple vs complex CF | **High** | Miss obstruction path |
| Simple-path ST0 value | **Low–Partial** | Range band wrong if decomp lies |
| Exact PhysX query type | Partial | LOS vs clearance bug in port |
| Full formal list | Partial | ABI mismatch |

---

## 3. Surviving contract

```
FindDistanceToTarget(...phys host required...):
  if !phys: return 0
  if simple: horizontal gap helper (FUN_004e8930); return measure (decomp residual)
  if complex: angular samples + collision query;
              on hit in outer band return residual (>= tiny epsilon);
              else 0
Consumers: RangeCheck (band), GatherTargets (distance), combat/UI.
```

Do **not** claim pure LOS product English without further PhysX dual.

---

## 4. Residual uncertainty

| # | Item | Blocks name/role seal? |
|---|---|---|
| R1 | Simple-path return ST0 | **No** for name; **Yes** for bit-exact port of simple path |
| R2 | Formal arity | No for role |
| R3 | Complex PhysX English | No for skill zero/nonzero gate if complex returns 0/positive correctly |
| R4 | Whether RangeCheck always uses simple | Mild |

---

## 5. Concrete checks

1. `list_strings` / `read_memory` name string. **Pass**
2. `get_xrefs_to 0x009ccbc0` → `004e9aca`. **Pass**
3. Callers include RangeCheck + GatherTargets. **Pass**
4. Terminal `return g_flZero`. **Pass**
5. `FUN_004e8930` XZ-minus-radii. **Pass** (callee)

---

## 6. Verdict

**accept** on **CVOGPhysicsUtils::FindDistanceToTarget** name + measure role; **accept-with-gaps** until simple-path return and complex geometry are image-proven.
