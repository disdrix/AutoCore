# Dual A/B report — W30-N OWN-ONLY (`0x008c2f50`, `0x005b44d0`)

**Date:** 2026-07-29  
**Agent:** W30-N OWN-ONLY  
**Scope:** OWN ONLY VAs `0x008c2f50`, `0x005b44d0`. Dual A/B + artifacts.  
**Partition:** wave30 (OWN-ONLY dual W30-N).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_008c2f50` Client_TryInventoryAutoMergePartialStacks_Notify | **accept-with-gaps** — busy/host/grid gates + merge callee + 0x204a notify sealed; product/table/opcode meaning open |
| `aa_005b44d0` Obj_009d95b4_ScalarDeletingDtor | **accept** — vtbl[0] scalar shell; body twin W28-N; full 30 B + false-noreturn sealed |

---

## `aa_008c2f50` — Client_TryInventoryAutoMergePartialStacks_Notify

### Sealed facts

1. **Body:** `0x008c2f50`–`0x008c2fdf` exclusive (**143** B / `0x8F`). Success `C3` @ `0x008c2fd8`; fail `C3` @ `0x008c2fde`; pad `CC`.

2. **ABI:** **EDI** = host (not ECX thiscall); bare **`RET`**; return **bool in AL**.

3. **Algorithm:**
   ```
   if DAT_00d1a8f6 != 0: return 0
   host = *(EDI+0x580); if !host: return 0
   grid = *(host+0x56c); if !grid: return 0
   if !InventoryGrid_AutoMergePartialStacks_Inferred(grid): return 0
   *(host+0x564) = DAT_00d17768[*(EDI+0x50c)]   // *4 scale
   FUN_00860700()  // ESI = host
   send sector {0x204a, u8(EDI+0x50c), 0xFF, 0} size 8
   return 1
   ```

4. **Callees:** `FUN_00572ab0` (W29-E accept-with-gaps), `FUN_00860700` (out of ownership), `Client_SendSectorPacket`.

5. **Callers (1):** `FUN_008c3ca0` @ `0x008c3da5` — UI `(param_3-40000)==4` & `param_2==8`; return discarded.

6. **Name:** `Client_TryInventoryAutoMergePartialStacks_Notify` (inferred).

### Gaps

1. Product English for host / inventory host.  
2. Sector `0x204a` product meaning.  
3. `DAT_00d17768` / field `+0x564` semantics.  
4. Full `FUN_00860700` contract (caller-owned helper).  
5. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_008c2f50_Client_TryInventoryAutoMergePartialStacks_Notify.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_008c2f50_Client_TryInventoryAutoMergePartialStacks_Notify.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_008c2f50_Client_TryInventoryAutoMergePartialStacks_Notify.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008c2f50_Client_TryInventoryAutoMergePartialStacks_Notify.md` |
| Function record | `docs/reconstruction/functions/aa_008c2f50_Client_TryInventoryAutoMergePartialStacks_Notify.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_008c2f50_FUN_008c2f50.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_TryInventoryAutoMergePartialStacks_Notify.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_008c2f50.cpp` |
| Raw | `docs/reconstruction/raw/aa_008c2f50_FUN_008c2f50.md` |
| Annotated | `docs/reconstruction/raw/aa_008c2f50_FUN_008c2f50.annotated.md` |

---

## `aa_005b44d0` — Obj_009d95b4_ScalarDeletingDtor

### Sealed facts

1. **Body:** `0x005b44d0`–`0x005b44ee` exclusive (**30** B / `0x1E`). Final **`C2 04 00`**; pad `CC`.

2. **ABI:** `__thiscall` ECX=`this`; stack `flags`; **`RET 4`**; returns `this` in EAX.

3. **Algorithm:**
   ```
   ESI = this
   call Obj_BodyDtor_SetVtbl_DestroyStdListAt10   // FUN_005b3b20
   if (flags & 1): operator_delete(this)
   return this
   ```

4. **Vtbl:** `0x009d95b4[0]` = `0x005b44d0`. Adjacent rdata is shader text, not class name.

5. **Callers:** none code; DATA from vtbl only. Body twin `FUN_005b3b20` (W28-N accept-with-gaps). Ctors `FUN_005b3f60` / `FUN_005b4260` install same vtbl.

6. **Name:** structural `Obj_009d95b4_ScalarDeletingDtor`. No product plate.

7. **False noreturn:** Ghidra marks `operator_delete` noreturn; bytes fall through to return.

### Gaps

1. Product English class name (naming only).  
2. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005b44d0_Obj_009d95b4_ScalarDeletingDtor.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005b44d0_Obj_009d95b4_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005b44d0_Obj_009d95b4_ScalarDeletingDtor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005b44d0_Obj_009d95b4_ScalarDeletingDtor.md` |
| Function record | `docs/reconstruction/functions/aa_005b44d0_Obj_009d95b4_ScalarDeletingDtor.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005b44d0_FUN_005b44d0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Obj_009d95b4_ScalarDeletingDtor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005b44d0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005b44d0_FUN_005b44d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b44d0_FUN_005b44d0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Client_TryInventoryAutoMergePartialStacks_Notify (`0x008c2f50`)

- Port as **thin client wrapper** only — do not reimplement merge math (reuse sealed `InventoryGrid_AutoMergePartialStacks_Inferred`).
- Preserve busy gate `DAT_00d1a8f6` and double-indirection host `+0x580` → grid `+0x56c`.
- Preserve EDI host convention (or explicit host* arg with matching field map).
- On dirty only: stamp `host+0x564`, refresh helper, send **`0x204a`** size **8** with index / `0xFF` / `0`.
- Do not invent product meaning of `0x204a` without a server-handler map.

### Obj_009d95b4_ScalarDeletingDtor (`0x005b44d0`)

- Port as **scalar shell only**: body dtor then optional `operator_delete` on flags bit0; `ret 4`.
- Reuse sealed `Obj_BodyDtor_SetVtbl_DestroyStdListAt10` for member teardown (vtbl + list at `+0x10`).
- Install as **vtbl[0]** of `PTR_FUN_009d95b4`; do not invent product class from shader-adjacent rdata.
- Ignore Ghidra noreturn on `operator_delete` — fall-through return is required.

---

## Notes

- Tools used: `decompile_function`, `batch_decompile`, `analyze_function_complete`, `read_memory`, `get_function_by_address`, `get_bulk_xrefs`, `get_assembly_context`. **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits.
- Partition ownership: W30-N only for these two VAs.
- Did not write artifacts for non-owned helpers (`00572ab0` dualed W29-E; `005b3b20` W28-N; `00860700` / `008c3ca0` / `Client_SendSectorPacket` out of ownership).
