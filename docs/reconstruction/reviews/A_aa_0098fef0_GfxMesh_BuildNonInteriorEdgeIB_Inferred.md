# Review A (reconstruction fidelity): `aa_0098fef0` GfxMesh_BuildNonInteriorEdgeIB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098fef0` |
| **VA** | `0x0098fef0` (success epilogue ~`0x0099049e`) |
| **Canonical name** | `GfxMesh_BuildNonInteriorEdgeIB_Inferred` |
| **Ghidra name** | `FUN_0098fef0` |
| **Review date** | `2026-07-29` (W35-F dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-F) |
| **Counterpart** | `reviews/B_aa_0098fef0_GfxMesh_BuildNonInteriorEdgeIB_Inferred.md` |
| **System** | palantir graphics / mesh index buffers |
| **Evidence pass** | Live `decompile_function` + `read_memory` (prologue/epilogues/edge loop) + `analyze_function_complete` + callee decompile (`00457ac0`, `0044b610`, `00743be0`) |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Triangle-mesh → non-interior edge line IB:

1. Gate face type ∈ {4,5,6}.
2. Stack NestedHash (0x10 sentinel) + GetTriangleVertexSteps.
3. Lock source IB; count undirected edges; unlock.
4. Collect edges with refcount ≠ 2; clone mesh type=2; write dest IB; return clone.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0098fef0_FUN_0098fef0.md` (+ W35-F append) |
| Annotated | `docs/reconstruction/raw/aa_0098fef0_FUN_0098fef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxMesh_BuildNonInteriorEdgeIB_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0098fef0.cpp` |
| Function records | `functions/aa_0098fef0_FUN_0098fef0.md`, `..._GfxMesh_BuildNonInteriorEdgeIB_Inferred.md` |
| Live | RET 8 fail @ `0x0099020f` (`XOR EAX,EAX`); success `MOV EAX,ESI; RET 8`; face type cmp 4/5/6; NestedHash ctor call |

---

## 3. Signature (sealed)

```c
uint32_t /*Mesh**/ GfxMesh_BuildNonInteriorEdgeIB_Inferred(void* ctx /*[EBP+8]*/, Mesh* mesh /*[EBP+0xC]*/);
// RET 8
```

| Slot | Source | Conf |
|---|---|---|
| ctx | Stack `[EBP+8]` | **High** |
| mesh | Stack `[EBP+0xC]` → EDI | **High** |
| fail return | `XOR EAX,EAX` | **High** |
| success return | `MOV EAX,ESI` (clone) | **High** |
| cleanup | `RET 8` | **High** |
| ECX-thiscall | **No** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Face type gate {4,5,6} | **Yes** | **High** |
| NestedHash0x10 stack ctor | **Yes** | **High** |
| Edge pack min/max + refcount++ | **Yes** | **High** |
| Keep refcount != 2 | **Yes** | **High** |
| Clone type=2 flags\|=0x20 | **Yes** (decompile) | **High** |
| IB lock 0x810 / dest 0x800 | **Yes** | **High** |
| Product class English | open | **Low** |
| Write-loop bound | vector size (bytes over unaff_ESI) | **Med** |

---

## 5. Gaps / open

1. Product/PDB mesh class / vtable plate.
2. Ghidra body end vs success-epilogue address mismatch (catalog truncates).
3. Zero static xrefs — dispatch unproven beyond vtable hypothesis.
4. Full dest write-loop register recovery residual.
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
