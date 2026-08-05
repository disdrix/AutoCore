# Annotated low-level: FUN_0098fef0 / GfxMesh_BuildNonInteriorEdgeIB_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0098fef0` |
| VA | `0x0098fef0` (byte epilogue through ~`0x0099049e`) |
| System | palantir graphics / mesh index buffers |
| Date | 2026-07-29 (W35-F OWN-ONLY dual) |
| Canonical | `GfxMesh_BuildNonInteriorEdgeIB_Inferred` |

## Machine-level notes

- **ABI:** two stack args, **RET 8**; returns **0** (fail/empty) or **clone mesh\*** in EAX (success).
- **SEH:** `LAB_009b1f0e`.
- **NestedHash:** stack bag via W34-E `NestedHash_Ctor_Sentinel0x10_Inferred` (`FUN_00457ac0`).
- **Face gate:** type dword at `mesh+0xac` (`param_2[0x2b]`) ∈ {4,5,6}.
- **Edge key:** undirected pair of u16 packed as `(min<<16)|max` after signed compare.
- **Interior filter:** NestedHash node refcount at +0x0c; keep edges where count **≠ 2**.
- **IB lock strings:** `gfxDeviceIB.cpp` lock/unlock (lines 0xaa / 0xca) — evidence of device IB, not product name of *this* function.
- Prefer bytes over decompiler for epilogue and write-loop count (`unaff_ESI` is false).

## Control flow (annotated)

```
if (!mesh || faceType∉{4,5,6}) return 0;
NestedHash10 bag = ctor_stack();                 // FUN_00457ac0
GetTriangleVertexSteps(faceType → s0,s1,s2);     // FUN_0044b610
idx = LockIB(mesh->deviceIB, 0x810);             // FUN_00743be0
for face in 0..faceCount:
  read tri u16s via strides (s0,s1,s2)*2 bytes
  for 3 edges: pack key; find-or-insert; refcount++
UnlockIB(mesh->deviceIB)
vec = []
for node in bag where refcount != 2:
  push hi16, lo16 as u32 elements
if vec empty: tidy; return 0
clone = mesh->vtbl[0x7c/4]()
// copy streams/materials; attach ctx resource param_1+0x28
clone->type = 2; clone->flags |= 0x20; clone->count = nIndices
SetupDeviceIB(clone); Lock dest 0x800; write u16s; Unlock
tidy; return clone
```

## Offsets (mesh param_2)

| Off | Role |
|---|---|
| +0x0c | device IB wrapper\* |
| +0xac | face type (4/5/6) |
| +0xa8 | face count |
| vtbl+0x7c | clone factory |
| vtbl+0x28 / +0x2c / +0x80 | material/stream helpers |

## Offsets (ctx param_1)

| Off | Role |
|---|---|
| +0x28 | refcounted resource slot attached to clone+0x20 |
| +0x2c..+0x2e | 3 bytes copied to clone+0x24.. |

## Pseudocode source

See raw capture body + W35-F re-verify append in `aa_0098fef0_FUN_0098fef0.md`.
