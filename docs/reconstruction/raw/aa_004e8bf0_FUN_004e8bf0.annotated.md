# Annotated low-level: Math_QuatTransformPoint_Inferred (`FUN_004e8bf0`)

| Field | Value |
|---|---|
| Stable ID | `aa_004e8bf0` |
| VA | `0x004e8bf0` |
| Body span | `004e8bf0` – `004e8db8` |
| System | pure math / transform |
| Date | 2026-07-29 (dual residual; raw body unchanged) |
| Dual | A/B `Math_QuatTransformPoint_Inferred` accept-with-gaps |

## Machine-level notes

- Source: raw capture for `aa_004e8bf0` + live Ghidra re-decompile 2026-07-29.
- **cdecl leaf** — four stack `float*`; epilogue `pop esi; leave; ret` (no stack pop of args).
- Pool floats: `g_flOne` @ `0x00a0f2a0` = **1.0f**; `g_flLevelUpUiBase_Inferred` @ `0x00a10e74` = **2.0f** (shared quat factor; UI name is a misnomer).
- SSE body (`movss`/`mulss`/`addss`/`subss`); single basic block.
- **Writes only out[0..2]** — W left stale by design of this leaf.

## Role

```
out.xyz = pos.xyz + R(quat_xyzw) * vec.xyz
```

Rotation matrix columns = verified basis extractors:

- col0 right  = `FUN_004e8ad0`
- col1 up     = `FUN_004e8b60`
- col2 forward= `FUN_004e8a40`

Sibling **not** this: `FUN_004e8590` inverse-delta `Rᵀ·(p3−p1)`.

## Pseudocode (annotated)

```c
// cdecl leaf
// param_1 = pos XYZ, param_2 = quat XYZW, param_3 = vec XYZ, param_4 = out XYZ
void FUN_004e8bf0(float *param_1, float *param_2, float *param_3, float *param_4)
{
  float fVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7;

  fVar6 = g_flLevelUpUiBase_Inferred;   // TWO = 2.0f
  fVar5 = g_flOne;                      // ONE = 1.0f

  // --- phase vx: out = pos + col0(q)*vx ---
  fVar1 = param_2[1];                   // y
  fVar2 = param_2[2];                   // z
  fVar3 = param_2[3];                   // w
  fVar4 = *param_2;                     // x
  fVar7 = (fVar2 * fVar3 + *param_2 * fVar1) * g_flLevelUpUiBase_Inferred; // 2(xy+zw)
  *param_4     = *param_3 * (g_flOne - (fVar2 * fVar2 + fVar1 * fVar1) * g_flLevelUpUiBase_Inferred)
                 + *param_1;            // vx*(1-2(y²+z²)) + px
  param_4[1]   = *param_3 * fVar7 + param_1[1];
  param_4[2]   = *param_3 * (fVar2 * fVar4 - fVar3 * fVar1) * fVar6 + param_1[2];

  // --- phase vy: out += col1(q)*vy ---
  fVar1 = param_2[2];                   // z
  fVar2 = *param_2;                     // x
  fVar3 = param_2[1];                   // y
  fVar4 = param_2[3];                   // w
  *param_4     = (fVar3 * fVar2 - fVar1 * param_2[3]) * fVar6 * param_3[1] + *param_4; // 2(xy-zw)*vy
  param_4[1]   = (fVar5 - (fVar1 * fVar1 + fVar2 * fVar2) * fVar6) * param_3[1] + param_4[1];
  param_4[2]   = (fVar1 * fVar3 + fVar2 * fVar4) * fVar6 * param_3[1] + param_4[2];

  // --- phase vz: out += col2(q)*vz ---
  fVar1 = param_2[1];                   // y
  fVar2 = param_2[2];                   // z
  fVar3 = *param_2;                     // x
  fVar4 = param_2[3];                   // w
  *param_4     = param_3[2] * (fVar2 * fVar3 + fVar1 * fVar4) * fVar6 + *param_4; // 2(xz+yw)*vz
  param_4[1]   = param_3[2] * (fVar2 * fVar1 - fVar3 * fVar4) * fVar6 + param_4[1];
  param_4[2]   = param_3[2] * (fVar5 - (fVar1 * fVar1 + fVar3 * fVar3) * fVar6) + param_4[2];
  return;
}
```

## Callers (summary)

16 xrefs / 13 functions. Camera: `FUN_0091a5f0` @ `0091a951` (`world = pos + R*lookVec`). Others: particles/AI/object pose helpers (`004b75d0` ×4, `005bc3c0`, …). Full table in dual A / function record.

## Open questions

- Product / PDB mangled name (keep `_Inferred`).
- Whether any consumer depends on pre-existing `out[3]`.
- Runtime / bit-exact vs SSE association order.
