# Function record: Xform_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00972cc0` |
| **Canonical name** | `Xform_Ctor_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00972cc0` |
| **Address** | `0x00972cc0`–`0x00972d6a` (**171 B** / `0xAB`) |
| **Module** | `autoassault.exe` |
| **System** | gfx-math / shared basis transform |
| **Status** | Dual A/B sealed W37-D 2026-08-04 — **accept-with-gaps** |

## Purpose

Default-construct a 0xC0 transform block to identity matrices, identity rotation, zero translation, unit scale, and clean dirty/version state. Primary ensure/ctor helper for GfxView-owned transforms, EnvironmentReflect matrix subobject, and mass `eh_vector_constructor_iterator` of 0xC0 elements.

## Signature

```c
// Retail: ECX=self; returns this in EAX; plain RET; leaf
XformBlock* Xform_Ctor_Inferred(XformBlock* self /*ECX*/);
```

## Algorithm

1. Load `g_flOne` (1.0f); zero via `XORPS`.
2. `REP MOVSD` ×16 from `DAT_00afdf70` → `self+0x00` (identity mat4).
3. `REP MOVSD` ×16 from same → `self+0x40`.
4. Store quat `(0,0,0,1)` @ `+0x80`.
5. Store translation zeros @ `+0x90` and unit scale/extra @ `+0x9c..+0xb0`.
6. `version=0`, `nonuniform=0`, `dirty=0`.
7. Return `self` (EAX).

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00972cc0_FUN_00972cc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00972cc0_FUN_00972cc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Xform_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00972cc0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00972cc0_FUN_00972cc0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_00972cc0_Xform_Ctor_Inferred.md`, `B_…` |

## Related

- Dirty rebuild: `FUN_00972e50`
- Scale stamp: `FUN_0044b440`
- Local→world point: `FUN_00972fa0` (`Xform_TransformLocalPointToWorld_Inferred`)
- GfxView ctor ensure: `FUN_0075ceb0` (`_aligned_malloc(0xC0,0x10)` + this)
