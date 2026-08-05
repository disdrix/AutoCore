# Dual A/B report — W22-C OWN `aa_00571e10` + `aa_0044b5c0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W22-C  
**Scope:** VAs `0x00571e10`, `0x0044b5c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00571e10` InventoryGrid_CommitPlacementMap_Inferred | **accept-with-gaps** — ABI ret 8, related RemoveItem gate, restamp, map clear sealed; product English residual |
| `aa_0044b5c0` Object_WriteComposedMatrix | **accept-with-gaps** — ECX+EDI+out ABI, flag bits, 3-arg compose sealed; multiply-order + product English residual |

---

## VA `0x00571e10` — sealed facts

1. **Body:** `0x00571e10`–`0x00571fae` (415 B; **`RET 8`**).
2. **ABI:** ECX=`InventoryGrid*`; stack0=`relatedGrid*` (nullable); stack1=`char doRemoveFromRelated`.
3. **Semantics:** walk placement map `@+0x60`; optional `InventoryGrid_RemoveItem` on **related**; set origin + bind owner; restamp cells if type≠4; free map (shell `@+0x5c`); count `@+0x64=0`.
4. **Callees:** `FUN_00571b80` RemoveItem; `FUN_005731c0`; `operator_delete`; item vtbl `+0x25c/+0x24c/+0x158`.
5. **Callers:** RePlaceItems `(related,1)` ×2 sites; SortAndRepack fail `(0,0)`.
6. **Name:** `InventoryGrid_CommitPlacementMap_Inferred` (Ghidra `FUN_00571e10`).
7. **Decompile ≡ bytes** for CF; non-returning-delete WARNING rejected.

### Gaps

- Product/PDB English.  
- relatedGrid exact class.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00571e10_InventoryGrid_CommitPlacementMap_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00571e10_InventoryGrid_CommitPlacementMap_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00571e10_FUN_00571e10.md` |
| Annotated | `docs/reconstruction/raw/aa_00571e10_FUN_00571e10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_CommitPlacementMap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00571e10.cpp` |
| Function | `docs/reconstruction/functions/aa_00571e10_FUN_00571e10.md` |
| Function named | `docs/reconstruction/functions/aa_00571e10_InventoryGrid_CommitPlacementMap_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00571e10.md` |

---

## VA `0x0044b5c0` — sealed facts

1. **Body:** `0x0044b5c0`–`0x0044b60f` (80 B; leaf-scale; dual **`ret`**).
2. **ABI:** **ECX**=primary object; **EDI**=companion; stack0=`float* out` (16); **EAX**=out; **cdecl**.
3. **Flags `@+0xbc`:** bit1 → rebuild primary matrix via `FUN_009730e0` else use `@+0x40`; bit0 → `FUN_00972e50` then compose.
4. **Compose:** `FUN_00412d40(out, companionOrRefreshed, matA)` — always 3 args (`add esp,0x0C`).
5. **Caller (1):** `Bounds_AccumulateTransformedLocal` @ `0x0074c9eb`.
6. **Name:** `Object_WriteComposedMatrix` (Ghidra `FUN_0044b5c0`).
7. **Decompile ≡ bytes** for CF; `unaff_EDI` + 1-arg compose phantoms filled.

### Gaps

- Product English.  
- `FUN_00412d80` multiply order (not owned).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044b5c0_Object_WriteComposedMatrix.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0044b5c0_Object_WriteComposedMatrix.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0044b5c0_FUN_0044b5c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044b5c0_FUN_0044b5c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_WriteComposedMatrix.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044b5c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0044b5c0_FUN_0044b5c0.md` |
| Function named | `docs/reconstruction/functions/aa_0044b5c0_Object_WriteComposedMatrix.md` |
| Scratch | `docs/reconstruction/tmp/a_0044b5c0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00571e10` | Inventory placement-map commit — preserve related RemoveItem gate; do not treat as pure clear; type-4 skips restamp; map shell is `this+0x5c`. |
| `0044b5c0` | Bounds matrix producer — require companion in EDI; honor dirty bits 0/1 at `+0xbc`; out is 16-float buffer returned in EAX. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.
