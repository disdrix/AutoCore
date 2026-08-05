# Annotated low-level: FUN_005b3fa0 / Obj_PopulateListAt10_ScaledGridFill_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005b3fa0` |
| VA | `0x005b3fa0`–`0x005b4255` exclusive (**693 B** / `0x2B5`) |
| System | host object / list populate worker |
| Date | 2026-08-04 (W37-L dual seal) |

## Machine-level notes

- **Bytes authority:** thiscall populate worker for the **0x30** host whose empty ctor is `Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20` (`0x005b3f60`, W30-O).
- **Gate:** `ESI = [ebp+0x18]` (param_6 context\*). If zero → return **0** (`xor al,al; ret 0x14`).
- **Float store (movss, middle args swapped vs stack order):**
  - `this+0x20 ← [ebp+8]`
  - `this+0x24 ← [ebp+0x10]`
  - `this+0x28 ← [ebp+0xC]`
  - `this+0x2c ← 0` (`xorps`/`movss`)
- **Context acquire:** `FUN_004f1e20(1,1)` with **ECX = param_6** (CS enter / ensure-loaded).
- **Asset path:** stack gfxBody ctor `FUN_00764030` → path string `FUN_004eb1c0` on context → lock `FUN_00764830` (log plate `gfxBody.cpp`). Fail if status **&lt; 0**.
- **Grid math:** extent deltas from locked rect; half-step `* DAT_00a0f298` (**0.5f**); outer/inner counts `ROUND((this+0x20)*scale)` × `ROUND((this+0x28)*scale)`.
- **Insert loop:** list base `this+0x10` (`ADD EBX,0x10`); node buy `FUN_005b4470` (`operator_new(0x30)` + copy 8 dwords payload); size `FUN_005b43d0(1)`; link head/prev.
- **Returns:** success **1** after `FUN_004eb010`; fail **0** after teardown (+ `FUN_00763f60` on load fail).
- Live caller `FUN_004cd8f0`: `new(0x30)` + default ctor → store host`+0xe4fc` → this populate with scale from `*(host+0xe4f8)+0x18`.

## Pseudocode (byte-corrected)

```c
// ECX = this (0x30 host); ret 0x14; returns 1 success / 0 fail
uint8_t __thiscall Obj_PopulateListAt10_ScaledGridFill_Inferred(
    void *self,
    float dim_a,      // → this+0x20
    float dim_b,      // → this+0x28
    float dim_c,      // → this+0x24  (stack arg2)
    float scale,      // multiplies dim_a / dim_b for loop bounds
    void *ctx)        // null → 0; else this for FUN_004f1e20
{
  if (ctx == nullptr)
    return 0;

  // SEH frame (LAB_009a684b)
  *(float *)((uint8_t *)self + 0x20) = dim_a;
  *(float *)((uint8_t *)self + 0x24) = dim_c;
  *(float *)((uint8_t *)self + 0x28) = dim_b;
  *(float *)((uint8_t *)self + 0x2c) = 0.0f;

  // ECX = ctx
  FUN_004f1e20(/*ensure*/1, /*flag*/1);
  // stack-local gfxBody-like object
  FUN_00764030(/*stack body*/);
  path = FUN_004eb1c0(ctx, &path_holder);
  status = FUN_00764830(/*body*/, path);
  if (status < 0) {
    FUN_004eb010();
    FUN_00763f60();
    return 0;
  }

  // extent deltas from locked surface floats; step_x/y ROUND; half * 0.5f
  int nx = (int)ROUND(*(float *)((uint8_t *)self + 0x20) * scale);
  int ny = (int)ROUND(*(float *)((uint8_t *)self + 0x28) * scale);
  // nested loops: build payload, FUN_005b4470, FUN_005b43d0(1) on list at self+0x10, link
  FUN_004eb010();
  return 1;
}
```

## Layout (populate-written)

| Offset | Role |
|---|---|
| +0x10 | embedded list base (insert target) |
| +0x14 | list head\* (read/write during insert) |
| +0x18 | list size (via `FUN_005b43d0`) |
| +0x20 | float dim_a (stack arg0) |
| +0x24 | float dim_c (stack arg2) |
| +0x28 | float dim_b (stack arg1) |
| +0x2c | float 0 |
| size | **0x30** host (from W30-O callers) |

## Open questions

- Product English class name.
- Node payload field names (position vs color/flags from `param_4`).
- Exact type of `ctx` (resource holder used by `FUN_004f1e20` / path builder).
- Runtime / bit-exact — open.
