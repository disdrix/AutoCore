# Review A (reconstruction fidelity): `aa_005e2670` EdRiverHandle_StampPolylineHeightGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e2670` |
| **VA** | `0x005e2670`–`0x005e29c8` (**856 B**) |
| **Canonical name** | `EdRiverHandle_StampPolylineHeightGrid_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_005e2670` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-D) |
| **Counterpart** | `reviews/B_aa_005e2670_EdRiverHandle_StampPolylineHeightGrid_Inferred.md` |
| **System** | Editor river-handle / map height grid |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (856 B) + `get_function_by_address` + `analyze_function_complete` + xrefs + nested decompiles `0043c460`/`006442c0`/`006a3db0`/`004a8d40` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra decompile + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Stamp a river-handle polyline’s segment influence into a map ushort grid, requantize the affected bbox, invalidate tiles, release the handle chain.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005e2670_FUN_005e2670.md` (+ W36-D live seal) |
| Annotated | `docs/reconstruction/raw/aa_005e2670_FUN_005e2670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EdRiverHandle_StampPolylineHeightGrid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005e2670.cpp` |
| Function record | `docs/reconstruction/functions/aa_005e2670_FUN_005e2670.md` |
| Named record | `docs/reconstruction/functions/aa_005e2670_EdRiverHandle_StampPolylineHeightGrid_Inferred.md` |
| Family | `FUN_005e2390` string `ed_riverhandle.geo`; vtable `@ 0x009dc9b8` |
| Nested | W35-B `CircularSentinel_Alloc0x14` |

---

## 3. Signature (sealed)

```c
// ECX=host; stack map*, argA, argB, argC; RET 0x10
void EdRiverHandle_StampPolylineHeightGrid_Inferred(
    void* host, void* map, uint32_t argA, float argB, uint32_t argC);
```

| Slot | Source | Conf |
|---|---|---|
| host | **ECX** | **High** |
| map | Stack0; decompiler `unaff_retaddr` | **High** |
| RET | **`C2 10 00`** | **High** |
| body size | **856 B** exclusive end `005e29c8` | **High** |

Decompiler 3-arg thiscall plate incomplete — **bytes win**.

---

## 4. Control flow (clean ≡ bytes stages)

| Stage | Match | Conf |
|---|---|---|
| SEH + vfunc +0xb8 null gate | **Yes** | **High** |
| Prep +0xb4(1); alloc circular list | **Yes** | **High** |
| cell*2.0 @ `0xa10e74`; fill +0xbc | **Yes** | **High** |
| Segment walk + `006442c0` + bbox union | **Yes** | **High** |
| Chain next via +0x14 / +0x24 | **Yes** | **High** |
| U16 requant clamp/scale constants | **Yes** | **High** |
| `004a8d40` expand ±2 | **Yes** | **High** |
| Release +0x70(1,0); free list; RET 10 | **Yes** | **High** |

---

## 5. Gaps

- Product/PDB class + vfunc English.
- Full formal map of `006442c0` call pack (unowned).
- Influence float buffer origin in requant loop (SSE path denser than decompile).
- Runtime / bit-exact.

---

## Verdict

Structural worker sealed on ABI, size, stages, constants, and callees. **accept-with-gaps**.
