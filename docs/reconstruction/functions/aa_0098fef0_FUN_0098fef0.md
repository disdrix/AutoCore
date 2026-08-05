# Function record: FUN_0098fef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098fef0` |
| **Canonical name** | `GfxMesh_BuildNonInteriorEdgeIB_Inferred` |
| **Ghidra name** | `FUN_0098fef0` |
| **Address** | `0x0098fef0` (Ghidra body through `0x0099042a`; byte success epilogue ~`0x0099049e`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir graphics / mesh index buffers |
| **Wave** | W35-F OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_0098fef0_GfxMesh_BuildNonInteriorEdgeIB_Inferred.md`, `reviews/B_aa_0098fef0_GfxMesh_BuildNonInteriorEdgeIB_Inferred.md` |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Scaffold (reject as product): `Named_gfxDeviceIB_0098fef0`
- Canonical: `GfxMesh_BuildNonInteriorEdgeIB_Inferred`

## Purpose

Build a type-2 line index buffer clone containing only undirected edges whose NestedHash refcount is **≠ 2** (non-interior: boundary / non-manifold) from a triangle mesh face type ∈ {4,5,6}. Uses gfxDeviceIB lock/unlock around source and dest index data.

## Signature (sealed)

```c
// stack ctx*, mesh*; RET 8; EAX = clone mesh* or 0
uint32_t /*Mesh**/ GfxMesh_BuildNonInteriorEdgeIB_Inferred(void* ctx, Mesh* mesh);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0098fef0_FUN_0098fef0.md` |
| Annotated | `docs/reconstruction/raw/aa_0098fef0_FUN_0098fef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxMesh_BuildNonInteriorEdgeIB_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0098fef0.cpp` |
| Function named | `docs/reconstruction/functions/aa_0098fef0_GfxMesh_BuildNonInteriorEdgeIB_Inferred.md` |

## Callers / callees

| Role | Symbols |
|---|---|
| Callers | **0** static xrefs (vtable / indirect likely) |
| Callees | `FUN_00457ac0` NestedHash0x10 ctor, `FUN_0044b610` GetTriangleVertexSteps, `FUN_00743be0` IB lock, `FUN_0046c1b0` / `FUN_0046bf90` hash find/insert, `FUN_004073a0` vector grow, `FUN_0044b9c0` device IB setup, log/abort, `operator_delete` |

## Confidence

| Claim | Level |
|---|---|
| RET 8 / two stack args / return 0 or ESI clone | **High** (bytes) |
| Face type gate {4,5,6} | **High** |
| Edge pack min/max + refcount != 2 filter | **High** |
| NestedHash 0x10 stack bag | **High** (W34-E) |
| Product English / mesh class name | **Low** |
| Full dest write-loop bound (decompiler unaff_ESI) | **Med** (vector count by CF) |
| Runtime / bit-exact | **Open** |
