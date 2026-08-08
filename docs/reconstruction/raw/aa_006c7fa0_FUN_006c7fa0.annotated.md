# Annotated low-level: FUN_006c7fa0 → PhysicsShape_Sphere_CtorFromRadius_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_006c7fa0` |
| VA | `0x006c7fa0`–`0x006c7fbc` (**29 B** / `0x1D`); pad `CC` @ `0x006c7fbd` |
| System | interaction-activation / physics shape (sphere) |
| Date | 2026-08-05 (MEGA-071 dual refresh; scaffold 2026-07-23) |
| Ghidra name | `FUN_006c7fa0` |
| Canonical | `PhysicsShape_Sphere_CtorFromRadius_Inferred` |

## Machine-level notes

- **Leaf thiscall ctor:** installs sphere shape vtbl `PTR_FUN_00a0d610`, refcount@+0x06=1, clear@+0x08=0, radius@+0x0c = stack float; **`RET 4`**.
- Prefer assembly when decompiler conflicts — here decompile ≡ body hex (no conflict).
- Parent allocators request **0x10** bytes, pool/type **0x22**, and pre-tag `word[this+4]=0x10` before CALL.
- Mode-2 of dualed `CVOGPhysicsUtils_GetObjectsInArea` (`0x004ea350` @ `0x004ea6ce`) passes area **radius** as the stack arg — seals float radius role.
- Vtbl methods confirm sphere: AABB inflate (`006c7f20`), support+radius (`006c7c30`), ray-sphere quadratic (`006c7fc0`) all read `float@+0xc`.
- Prior plate `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` is **wrong lineage** (AABB path `VOG_DEBUG_STOP` is a sibling branch of GetObjectsInArea, not a caller of this VA).

## Pseudocode (annotated)

```c
// __thiscall: ECX = shape (0x10-byte buffer); stack = float radius; RET 4; EAX = this
void __thiscall PhysicsShape_Sphere_CtorFromRadius_Inferred(
    PhysicsShape_Sphere *this, float radius)
{
  // u16 refcount @ +0x06
  *(uint16_t *)((uint8_t *)this + 6) = 1;
  // clear dword @ +0x08
  this->field_08 = 0;
  // radius float @ +0x0c
  this->radius = radius;
  // vtbl last (MSVC style after member init)
  this->vtbl = &PTR_FUN_00a0d610;
  return; // RET 4
}
```

## Layout

| Off | Type | Init | Role |
|---|---|---|---|
| +0x00 | void** | `00a0d610` | vtbl |
| +0x04 | u16 | parent `0x10` | size/type tag (not written here) |
| +0x06 | u16 | `1` | refcount |
| +0x08 | u32 | `0` | reserved / unused-by-ctor |
| +0x0c | float | stack arg | sphere radius |

## Call graph (live)

| Role | Value |
|---|---|
| Callers | 17 functions / 18 UNCONDITIONAL_CALL sites |
| Notable | `FUN_004ea350` GetObjectsInArea mode-2; `FUN_004e9720`/`FUN_004e9aa0`/`FUN_004ed470`/`FUN_004ee080` area queries; `FUN_005f*` / `FUN_006ec*` shape setup cluster |
| Callees | none |

## Open questions

1. Product class name (no RTTI string on body).
2. Field @+0x08 English.
3. Full vtbl method English beyond sphere-proof methods.
4. Runtime / bit-exact / differential.
