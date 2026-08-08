# Dual A/B report — WQ8R-E OWN `aa_00573910` + `aa_00607550`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ8R-E  
**Scope:** VAs `0x00573910`, `0x00607550` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + callers/xrefs/callees + `analyze_data_region` / `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq008_residual_partition_map.md` (WQ8R-E).  
**Terminal coverage claim:** **false** (agent reports never claim terminal bar complete).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00573910` InventoryGrid_ScalarDeletingDtor | **accept** — 29 B MSVC scalar-deleting dtor; vtbl[0] of `PTR_FUN_009d3390`; complete+optional free sealed |
| `aa_00607550` Outpost_GetScheduleEntryValueAtCursor_Inferred | **accept-with-gaps** — 88 B schedule bank/cursor lookup returns entry+4 dword; soft OOB→0; product English residual |

---

## VA `0x00573910` — sealed facts

1. **Body:** `0x00573910`–`0x0057392d` exclusive (**29 B** / `0x1D`; epilogue `8B C6 5E C2 04 00`; pad `CC CC`).
2. **ABI:** **ECX=`this`**; stack **`flags`**; returns **`this*`** in **EAX**; **`RET 4`**. Bytes: `56 8B F1` … `C2 04 00`.
3. **Semantics:** MSVC **scalar-deleting destructor** (vtbl[0]):
   - Always call complete dtor **`FUN_005725a0`**.
   - If `(flags & 1)`: `operator_delete(this)` @ `0x00489822`.
   - Return `this`.
   - **Not** complete body; **not** vector-deleting (`operator_delete[]` / array count absent).
4. **Vtbl:** DATA dword @ **`0x009d3390`** (`PTR_FUN_009d3390` slot0) = `0x00573910`. Install sites: complete dtor `0x005725c1`; ctor `InventoryGrid_ctor_Inferred` `0x0057266a`.
5. **Family:** InventoryGrid (ctor `0x00572650`, cargo destroy via `Vehicle_CreateCargoInventoryFromPageCount` `vtbl[0](1)` on vehicle+`0x2b0`, alloc size `0x68`).
6. **Classification:** **worker**.
7. **Callers:** DATA vtbl[0] only (no bulk code CALL sites); virtual destroy from inventory lifecycle.
8. **Name:** `InventoryGrid_ScalarDeletingDtor` (Ghidra `FUN_00573910`; **Inferred** structural family). Peer shape: W31-E `Class_009c7938_ScalarDeletingDtor` (29 B).
9. **Decompile ≡ bytes** for full CF; Ghidra false-noreturn on `operator_delete` ignored (epilogue reached).  
   Full hex: `568bf1e888ecfffff644240801740956e8fd5ef1ff83c4048bc65ec20400`

### Gaps

- Product/MSVC demangle string for host class (naming only).  
- Complete dtor body / member map (`FUN_005725a0`) — not owned.  
- Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00573910_InventoryGrid_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00573910_InventoryGrid_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00573910_FUN_00573910.md` |
| Annotated | `docs/reconstruction/raw/aa_00573910_FUN_00573910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00573910.cpp` |
| Function | `docs/reconstruction/functions/aa_00573910_FUN_00573910.md` |
| Function named | `docs/reconstruction/functions/aa_00573910_InventoryGrid_ScalarDeletingDtor.md` |

---

## VA `0x00607550` — sealed facts

1. **Body:** `0x00607550`–`0x006075a8` exclusive (**88 B** / `0x58`; success/zero epilogues `5E C3`; pad `CC`×7). Next: `Outpost_GetPulseXpPercent` @ `0x006075b0`.
2. **ABI:** **ECX=outpost `this`** (`8B C1`); **no stack formals**; plain **`RET`** (`C3`); returns **EAX dword**.
3. **Semantics:** Pure schedule-table lookup:
   - Bank: `self+0x220 != 0` → `DAT_00d029e0`, else `DAT_00d029f0` (BSS vector headers: begin@`+4`, end@`+8`).
   - Index: signed `self+0x23c` (schedule cursor).
   - If index `< 0` or `index >= size` where `size = (end-begin)>>4` (stride **16**): **return 0**.
   - Else return `*(uint32_t*)(begin + index*0x10 + 4)` (entry field **+4**).
   - Pathological MSVC `operator[]` recheck → `FUN_00608620` (`"invalid vector<T> subscript"` noreturn).
4. **Sole caller:** `Outpost_CaptureOutpost` (`0x006082e0`) @ `0x006085cc`:
   - After `+0x238 = scheduleCount`, `+0x23c = 0`.
   - Result → `timerBlob(+0x248)[+8]`; `GetTickCount` → `timerBlob[+0x14]`.
5. **Twin (not owned):** `Outpost_GetPulseXpPercent` @ `0x006075b0` — same bank/cursor/stride; returns **float at entry+8**.
6. **Classification:** **worker** / pure (no host writes).
7. **Name:** `Outpost_GetScheduleEntryValueAtCursor_Inferred` (Ghidra `FUN_00607550`; **Inferred**).  
   **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00607550` (wrong parent chain).
8. **Decompile ≡ bytes** for full CF.  
   Full hex: `8bc180b82002000000b9e029d0007505b9f029d000568bb03c02000085f67c358b510485d2750433c0eb088b41082bc2c1f8043bf0731e85d2740c8b41082bc2c1f8043bc67705e984100000c1e6048b4416045ec333c05ec3`

### Gaps

- Product English for entry+4 dword (timer-arm use High; duration vs id residual).  
- Population/writers of `DAT_00d029e0` / `DAT_00d029f0`.  
- Entry fields `+0` / `+0xC`.  
- Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00607550_Outpost_GetScheduleEntryValueAtCursor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00607550_Outpost_GetScheduleEntryValueAtCursor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00607550_FUN_00607550.md` |
| Annotated | `docs/reconstruction/raw/aa_00607550_FUN_00607550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Outpost_GetScheduleEntryValueAtCursor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00607550.cpp` |
| Function | `docs/reconstruction/functions/aa_00607550_FUN_00607550.md` |
| Function named | `docs/reconstruction/functions/aa_00607550_Outpost_GetScheduleEntryValueAtCursor_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00573910` | Port as **InventoryGrid scalar-deleting dtor** only: complete dtor then optional `delete` on flags bit0; **RET 4**; return this. **Do not** inline complete body (`FUN_005725a0`). Cargo create: `if (grid) grid->vtbl[0](1); grid=null` before `new`/`ctor`. Preserve vtbl slot0 of `PTR_FUN_009d3390`. |
| `00607550` | Port as **pure schedule lookup**: ECX=outpost, plain RET, EAX=entry+4 dword. Bank via `+0x220` (`DAT_00d029e0`/`f0`), index `+0x23c`, stride 16. **OOB → 0** (not throw). **Do not** merge with `Outpost_GetPulseXpPercent` (float @+8). Capture path arms `timerBlob[+8]` after cursor reset to 0. |

Shared context: co-owned only by WQ-008 residual partition (inventory grid lifecycle destroy vs outpost schedule timer lookup). No shared call graph between the two VAs. Trio (raw/annotated/clean) + dual A/B filed per VA. Parent merge (matrix/registry/systems/ledgers) is **not** agent work.

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00573910-00607550-wq8re-report.md` |
