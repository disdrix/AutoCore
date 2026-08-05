# Function record: GfxMesh_BuildNonInteriorEdgeIB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098fef0` |
| **Canonical name** | `GfxMesh_BuildNonInteriorEdgeIB_Inferred` |
| **Ghidra name** | `FUN_0098fef0` |
| **Address** | `0x0098fef0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir graphics / mesh index buffers |
| **Wave** | W35-F OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_0098fef0_GfxMesh_BuildNonInteriorEdgeIB_Inferred.md`, `reviews/B_aa_0098fef0_GfxMesh_BuildNonInteriorEdgeIB_Inferred.md` |

## Purpose

From a triangle mesh (face type 4/5/6), count undirected edges in a NestedHash bag and clone a type-2 index buffer holding only edges with refcount ≠ 2 (non-interior).

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `NestedHash_Ctor_Sentinel0x10_Inferred` | `0x00457ac0` | stack bag ctor (W34-E) |
| `FUN_0044b610` | `0x0044b610` | GetTriangleVertexSteps |
| `FUN_00743be0` | `0x00743be0` | gfxDeviceIB::Lock path |

## Signature

```c
uint32_t /*Mesh**/ GfxMesh_BuildNonInteriorEdgeIB_Inferred(void* ctx /*stack*/, Mesh* mesh /*stack*/ /*RET 8*/);
```

## Artifacts

See `aa_0098fef0_FUN_0098fef0.md` for full paths and confidence table.
