# Function record: Math_QuatTransformPoint_Inferred (`FUN_004e8bf0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8bf0` |
| **Canonical name (Ghidra)** | `FUN_004e8bf0` |
| **Proposed name** | `Math_QuatTransformPoint_Inferred` |
| **Address** | `0x004e8bf0` |
| **Body span** | `004e8bf0` – `004e8db8` (457 B; `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | pure math / transform (multi-domain leaf) |
| **Completion status** | **Partial** — dual A/B sealed 2026-07-29 (accept-with-gaps); runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004e8bf0_Math_QuatTransformPoint_Inferred.md` + `reviews/B_aa_004e8bf0_Math_QuatTransformPoint_Inferred.md` |

## Alias

- Prior scaffold: `Named_CalleeOf_Named_SkyBoxParticles_004e8bf0` — **too narrow**; do not use as primary role name.
- Human role: **pos + quat-rotate vector** (world transform point).

## Purpose

Leaf cdecl helper:

```
out.xyz = pos.xyz + R(quat_xyzw) * vec.xyz
```

`R` columns match verified basis extractors `FUN_004e8ad0` (right/+X), `FUN_004e8b60` (up/+Y), `FUN_004e8a40` (forward/+Z). Shared pool constants: `g_flOne` @ `0x00a0f2a0` = **1.0**, `g_flLevelUpUiBase_Inferred` @ `0x00a10e74` = **2.0** (misnomer; quat factor). **out.w is not written.**

Distinct from inverse-delta sibling `FUN_004e8590` (`out = Rᵀ·(p3−p1)`).

## Signature (decompiler-derived + dual-sealed)

```c
// cdecl; leaf
void Math_QuatTransformPoint_Inferred(
    const float *pos,   // param_1 — XYZ used; W unread
    const float *quat,  // param_2 — XYZW unit quat
    const float *vec,   // param_3 — XYZ used; W unread
    float *out);        // param_4 — XYZ written; W untouched
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e8bf0_FUN_004e8bf0.md`
- Annotated: `docs/reconstruction/raw/aa_004e8bf0_FUN_004e8bf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004e8bf0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004e8bf0_Math_QuatTransformPoint_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004e8bf0_Math_QuatTransformPoint_Inferred.md`
- Scratch: `docs/reconstruction/reviews/a_004e8bf0.md`
- Sibling basis set: `docs/reconstruction/physics/verified/fn_004e8ad0_basisExtract.md`

## Callers / callees

**Callees:** none (leaf).

**Callers (16 sites / 13 functions, live 2026-07-29):**

| Function | VA | Notes |
|---|---|---|
| `FUN_0091a5f0` / camera look | `0x0091a5f0` | `world = pos + R*lookVec` → gated apply |
| `FUN_004b75d0` | `0x004b75d0` | 4 call sites |
| `FUN_004b9300` | `0x004b9300` | |
| `FUN_0056c0a0` | `0x0056c0a0` | |
| `FUN_0056ca70` | `0x0056ca70` | |
| `FUN_0058e980` | `0x0058e980` | |
| `FUN_005911b0` | `0x005911b0` | |
| `FUN_005a8650` | `0x005a8650` | |
| `FUN_005bc3c0` | `0x005bc3c0` | skybox/particles parent of scaffold alias |
| `FUN_005cd220` | `0x005cd220` | |
| `FUN_005cedf0` | `0x005cedf0` | |
| `FUN_00615020` | `0x00615020` | |
| `FUN_00620480` | `0x00620480` | |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler / leaf | **High** |
| `out = pos + R(q)·v` closed form | **High** |
| Constants 1.0 / 2.0 | **Confirmed** (`read_memory`) |
| XYZW quat layout (family) | **High** |
| Parameter semantic names | **High** role / **Probable** product labels |
| Product mangled name | **Tentative** (`_Inferred`) |
| Runtime / bit-exact | Open |
