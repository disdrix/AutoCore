# Function record: EffTexture_CreateOrAssignSlot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f0e0` |
| **Canonical name** | `EffTexture_CreateOrAssignSlot_Inferred` |
| **Ghidra name** | `FUN_0096f0e0` |
| **Address** | `0x0096f0e0`–`0x0096f15c` exclusive (**124 B** / `0x7C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir graphics Effects — effTexture create/assign |
| **Status** | Dual A/B sealed W37-H 2026-08-04 — **accept-with-gaps** |

## Purpose

Create-or-replace assign for an effect-texture slot:

1. Factory `FUN_0096e9f0` → new instance (or null).
2. Null → log `effTexture.cpp` L87 (`0x57`) `"Failed to create instance of texture."` → return **-1**.
3. Non-null → inc ref @+8; if first, virtual **vtbl[+4]** on subobject **+4**.
4. If prior `*slot` non-null → dec its ref @+8; if zero, virtual **vtbl[+8]** on **+4**.
5. `*slot = neu`; return **0**.

## Signature

```c
// ECX = slot*; six stack formals; RET 0x18
int32_t __thiscall EffTexture_CreateOrAssignSlot_Inferred(
    EffTexturePayload** slot /*ECX*/,
    uint32_t p0, uint32_t p1_dead, uint32_t p2,
    uint32_t p3, uint32_t p4, uint32_t p5);
```

## Related

| VA / name | Relation |
|-----------|----------|
| `0x0096e9f0` FUN_0096e9f0 | Factory (create instance) |
| `0x0096efd0` | Sibling release layout (ref@+8, iface@+4) — clears handle |
| `0x0048ed00` PalantirEnv_InitEffectTextures | Dual full/half dim create via this |
| `0x00a9ed50` / `0x00a9ed24` | path / fail plate strings |
| `0x0096f510` RefCountedPtr3Flags_Dtor | **Different** payload layout — do not merge |

## Artifacts

See `aa_0096f0e0_FUN_0096f0e0.md`.
