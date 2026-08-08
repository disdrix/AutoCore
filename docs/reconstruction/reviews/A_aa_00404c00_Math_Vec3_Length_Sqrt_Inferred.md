# Review A (reconstruction fidelity): `aa_00404c00` Math_Vec3_Length_Sqrt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404c00` |
| **VA** | `0x00404c00`–`0x00404c20` inclusive (**33 B** / `0x21`) |
| **Canonical name** | `Math_Vec3_Length_Sqrt_Inferred` |
| **Ghidra name** | `FUN_00404c00` |
| **Prior scaffold** | `Named_CalleeOf_Mission_Look_in_your_Mission_Inventory_00404c00` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-060 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00404c00_Math_Vec3_Length_Sqrt_Inferred.md` |
| **System** | math / vec3 length |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_function_by_address` + caller decompile samples. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **3-float Euclidean length**:

```text
Math_Vec3_Length_Sqrt_Inferred(v /* ECX */) -> ST0
  return sqrt(v[0]^2 + v[1]^2 + v[2]^2)
```

Partition hint `Mission_Look_in_your_Mission_Inventory` is the **parent consumer** at `0x008a8770` (two call sites), not this VA.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (`SQRT` of three squared components) |
| Full body | `disassemble_function` 16 insns + `read_memory` 33 B |
| Bytes | `d94108…d9fac3` sealed; pad `CC` to `00404c30` |
| Callees | none |
| Callers | 4 functions / 5 `UNCONDITIONAL_CALL` |
| Sibling | `FUN_00404c30` float4 store @+0x90 — unrelated |

---

## 3. Signature (sealed)

```c
// ECX = const float *v; ST0 = length; RET
float10 Math_Vec3_Length_Sqrt_Inferred(const float *v /* ECX */);
```

| Formal | Source | Conf |
|---|---|---|
| v | **ECX** → `[ECX]`,`[ECX+4]`,`[ECX+8]` | **Confirmed** |
| stack args | none | **Confirmed** |
| return | x87 **ST0** | **Confirmed** |
| cleanup | `RET` (`C3`) | **Confirmed** |
| callees | none (`FSQRT`) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Single basic block | 1 BB / complexity 1 | **Confirmed** |
| Load z,y,x from ECX | `FLD`×3 | **Confirmed** |
| Sum of squares | `FMUL` self + `FADDP`×2 | **Confirmed** |
| Sqrt | `FSQRT` | **Confirmed** |
| Stack cleanup + return | `FSTP`×3 + `RET` | **Confirmed** |
| Decompile ≡ raw CF | live re-verify | **Confirmed** |

---

## 5. Callers (evidence)

| Caller | Sites | Usage note |
|---|---|---|
| `FUN_00500560` | `00501257` | length after float3 stack copy |
| `FUN_005a75f0` | `005a77e0` | length of component-wise delta |
| `FUN_005ba440` | `005bace8` | length of object-field delta |
| `FUN_008a8770` | `008a8cd0`, `008a8d5e` | mission UI plate parent; gate vs `g_flZero` + distance |

---

## 6. Naming decision

| Candidate | Decision |
|---|---|
| `Math_Vec3_Length_Sqrt_Inferred` | **accept** — formula + ABI sealed; product symbol open → `_Inferred` |
| `Named_CalleeOf_Mission_…` | **reject/retire** — parent plate only |
| Mission inventory open/list | **reject** — no inventory side effects |

Family consistency: dualed `Math_Vec3NearlyEqual_AbsRel`, `Math_Float3_IsFiniteIEEE_Inferred`.

---

## 7. Gaps

- Product demangle / historical D3DX-style export name.
- Shared engine `Vec3` type plate.
- Runtime / bit-exact / differential (Terminal false).

---

## 8. Verdict

CF/ABI/formula/xrefs sealed by live machine evidence. Residual product English only → **accept-with-gaps**.
