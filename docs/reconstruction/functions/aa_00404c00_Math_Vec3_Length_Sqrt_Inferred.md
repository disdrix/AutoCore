# Function record: Math_Vec3_Length_Sqrt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404c00` |
| **Canonical name** | `Math_Vec3_Length_Sqrt_Inferred` |
| **Ghidra name** | `FUN_00404c00` |
| **Address** | `0x00404c00`–`0x00404c20` inclusive (**33 B** / `0x21`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | math / vec3 length |
| **Dual** | MEGA-060 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

## Purpose

```text
||v||₂ = sqrt(v.x² + v.y² + v.z²)   // v = (float*)ECX
```

x87 leaf: three loads, three self-products, two adds, `FSQRT`, stack cleanup, `RET`.

## Signature

```c
// thiscall/fastcall register form — pointer in ECX, result in ST0
float Math_Vec3_Length_Sqrt_Inferred(const float v[3] /* ECX */);
```

## Why `_Inferred`

No RTTI/string demangle at this VA; local `.text` helper (not an import). Product may historically match D3DX-style `Vec3Length` naming, but engine-local `Math_*` family is used for similar dualed leaves (`Math_Vec3NearlyEqual_AbsRel`, `Math_Float3_IsFiniteIEEE_Inferred`).

## Retired misname

`Named_CalleeOf_Mission_Look_in_your_Mission_Inventory_00404c00` — parent `@0x008a8770` is a **caller**, not this body.

## Cross-links

- FUN record: `docs/reconstruction/functions/aa_00404c00_FUN_00404c00.md`
- Clean: `docs/reconstruction/reconstructed-exact/Math_Vec3_Length_Sqrt_Inferred.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00404c00_Math_Vec3_Length_Sqrt_Inferred.md`, `B_aa_00404c00_Math_Vec3_Length_Sqrt_Inferred.md`
- Report: `docs/agents/task-dual-ab-00404c00-mega-060-report.md`
