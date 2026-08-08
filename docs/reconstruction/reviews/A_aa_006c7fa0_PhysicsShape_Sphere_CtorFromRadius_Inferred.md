# Review A (reconstruction fidelity): `aa_006c7fa0` PhysicsShape_Sphere_CtorFromRadius_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c7fa0` |
| **VA** | `0x006c7fa0`–`0x006c7fbc` (**29 B** / `0x1D`); pad `CC` @ `0x006c7fbd` |
| **Canonical name** | `PhysicsShape_Sphere_CtorFromRadius_Inferred` |
| **Ghidra name** | `FUN_006c7fa0` |
| **Review date** | `2026-08-05` (MEGA-071 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred.md` |
| **System** | interaction-activation / physics sphere shape setup |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **thiscall constructor** for a **0x10-byte sphere shape**:

1. `refcount@+0x06 = 1`
2. `field@+0x08 = 0`
3. `radius@+0x0c = stack float`
4. `*this = PTR_FUN_00a0d610` (sphere vtbl)
5. **`RET 4`**; **EAX = this**

Primary product path: dualed `CVOGPhysicsUtils_GetObjectsInArea` **mode `param_5 == 2`** (sphere-ish broadphase) @ CALL `0x004ea6ce`. Also used by 16 other query/setup callers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-071 append) | `docs/reconstruction/raw/aa_006c7fa0_FUN_006c7fa0.md` |
| Annotated | `docs/reconstruction/raw/aa_006c7fa0_FUN_006c7fa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysicsShape_Sphere_CtorFromRadius_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006c7fa0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_006c7fa0.cpp` |
| Function record | `docs/reconstruction/functions/aa_006c7fa0_FUN_006c7fa0.md` |
| Named record | `docs/reconstruction/functions/aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred.md` |
| Live | decompile ≡ body hex; vtbl `00a0d610`; 18 CALL xrefs; mode-2 call-site context |
| Parent dual | `A_aa_004ea350_CVOGPhysicsUtils_GetObjectsInArea.md` mode-2 CF |

---

## 3. Signature (sealed)

```c
// ECX = shape*; stack float radius; RET 4; EAX = this
PhysicsShape_Sphere_Inferred *__thiscall
PhysicsShape_Sphere_CtorFromRadius_Inferred(
    PhysicsShape_Sphere_Inferred *self, float radius);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** → `MOV EAX,ECX` | **High** |
| radius | stack `[ESP+4]` | **High** (parent mode-2 passes `param_3` float) |
| cleanup | **`RET 4`** | **High** (`C2 04 00`) |
| return | **EAX = this** | **High** |
| callees | none | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| word[this+6] = 1 | **Yes** | **High** |
| dword[this+8] = 0 | **Yes** | **High** |
| dword[this+0xc] = stack | **Yes** | **High** |
| *this = 0x00a0d610 | **Yes** | **High** |
| RET 4 / leaf | **Yes** | **High** |
| Sphere via vtbl methods | **Yes** | **High** (AABB/support/ray) |
| Product class English | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| External callers | **17** functions / **18** UNCONDITIONAL_CALL |
| Site role | post-alloc sphere shape setup (size `0x10`, pool `0x22`) |
| Callees | none |
| Parent product | `CVOGPhysicsUtils::GetObjectsInArea` mode-2 |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Leaf ctor + vtbl install | **Yes** |
| Radius float @+0x0c from stack | **Yes** |
| Mode-2 sphere path of GetObjectsInArea | **Yes** |
| Vtbl sphere math (AABB/support/ray) | **Yes** |
| Product / PDB demangle | **No** |
| Named_CalleeOf VOG_DEBUG_STOP plate | **Reject** |

**Decision:** promote **`PhysicsShape_Sphere_CtorFromRadius_Inferred`**. Product demangle open → `_Inferred`. Retire `Named_CalleeOf_Named_VOG_DEBUG_STOP_006c7fa0`.

---

## 7. Gaps / open

1. Product class English / RTTI for `PTR_FUN_00a0d610` family.
2. Field @+0x08 meaning (cleared only).
3. Full vtbl method English beyond sphere-proof subset.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/layout/vtbl-sphere role/callers sealed; product demangle open.
