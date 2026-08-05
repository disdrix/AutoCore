# Dual A/B report — W36-D OWN `aa_005e2670` + `aa_00971030`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-D  
**Scope:** VAs `0x005e2670`, `0x00971030` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-D).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005e2670` EdRiverHandle_StampPolylineHeightGrid_Inferred | **accept-with-gaps** — ECX host / RET 10 / 856 B / chain-stamp-requant-tile CF sealed; product + nested stamp residual |
| `aa_00971030` AssPreloader_PendingRemoveWithSideNotify_Inferred | **accept-with-gaps** — ECX preloader / key* / RET 4 / 30 B / push-flag0 then erase pending+0x1C sealed; flag English residual |

---

## VA `0x005e2670` — sealed facts

1. **Body:** `0x005e2670`–`0x005e29c8` exclusive (**856 B** / `0x358`; pad `CC`). Ghidra plate end `005e29c7` — **bytes win** (epilogue `C2 10 00`).
2. **ABI:** **ECX=handle-host**; stack **map\***, **argA**, **argB (float)**, **argC**; **`RET 0x10`**. Decompiler `unaff_retaddr` is stack **map\*** — **bytes win**.
3. **Semantics:** Editor river-handle family worker (vtable DATA `@ 0x009dc9b8` near `ed_riverhandle.g*`):
   - Seed `host.vt[+0xb8]()`; null → return.
   - Prep `node.vt[+0xb4](1)`; alloc circular sentinel (`0043c460` W35-B).
   - Per chain node: clear list; `cell*2.0` (`0xa10e74`=2.0); fill via `vt[+0xbc]`; walk consecutive list nodes (xyz@`+8/+c/+10`); sample `vt[+0xac]`; stamp `FUN_006442c0(map,…)`; union bbox; advance via `node+0x14` / `vt[+0x24]`.
   - Requant `map+0x3e0` u16 grid in bbox: `*1/65536`, clamp `[0,1]`, `*65535`, round `006a3db0`.
   - Tile invalidate `004a8d40(map, bbox±2)`.
   - Release chain `vt[+0x70](1,0)`; free list.
4. **Classification:** **worker**.
5. **Callers:** no direct CALL; **DATA** vtable `@ 0x009dc9b8`.
6. **Callees:** vfuncs; `0043c460`; `006442c0`; `006a3db0`; `004a8d40`; `operator_delete`.
7. **Name:** `EdRiverHandle_StampPolylineHeightGrid_Inferred` (Ghidra `FUN_005e2670`; **Inferred** structural from family geo + CF). Reject any scaffold `Named_CalleeOf_*`.
8. **Decompile ≡ bytes** for major CF; **bytes win** on 4 stack formals, RET 10, map formal, body size.  
   Full hex: raw W36-D append (856 B).

### Gaps

- Product/PDB host + vfunc English; argA/B/C domain names.  
- Nested `006442c0` / `004a8d40` dual free.  
- Requant SSE micro-order residual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005e2670_EdRiverHandle_StampPolylineHeightGrid_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005e2670_EdRiverHandle_StampPolylineHeightGrid_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005e2670_FUN_005e2670.md` |
| Annotated | `docs/reconstruction/raw/aa_005e2670_FUN_005e2670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EdRiverHandle_StampPolylineHeightGrid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005e2670.cpp` |
| Function | `docs/reconstruction/functions/aa_005e2670_FUN_005e2670.md` |
| Function named | `docs/reconstruction/functions/aa_005e2670_EdRiverHandle_StampPolylineHeightGrid_Inferred.md` |

---

## VA `0x00971030` — sealed facts

1. **Body:** `0x00971030`–`0x0097104e` exclusive (**30 B** / `0x1E`; pad `CC`).
2. **ABI:** **ECX=AssPreloader\***; stack **key\***; **`RET 0x4`**.
3. **Semantics:** Composite pending-side remove:
   - `SideHost_PushKeyFlag0` (`00970b20`, W33-N): ECX=key holder, stack=preloader host → locked push `{*key,0}` at **host+0xAC**.
   - `GuardedVector_EraseFirstEqual_ThiscallRange` (`0043e630`, W35-A): **ESI=preloader+0x1C**, stack key*, RET 4 (AL ignored).
4. **Classification:** **worker** (2 sealed callees).
5. **Callers (1):** `FUN_004ed310` @ `0x004ed3a5` (`AssPreloader_ProcessKeyRingStep_Inferred`, W35-A) on tracked + progress_flag path.
6. **Name:** `AssPreloader_PendingRemoveWithSideNotify_Inferred` (Ghidra `FUN_00971030`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00971030`.
7. **Decompile incomplete** on ECX/ESI split — **bytes win**.  
   Full hex: `56578b7c240c8bf1568bcfe8e0faffff5783c61ce8e7d5acff5f5ec20400`

### Gaps

- Product flag0 event English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00971030_AssPreloader_PendingRemoveWithSideNotify_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00971030_AssPreloader_PendingRemoveWithSideNotify_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00971030_FUN_00971030.md` |
| Annotated | `docs/reconstruction/raw/aa_00971030_FUN_00971030.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_PendingRemoveWithSideNotify_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971030.cpp` |
| Function | `docs/reconstruction/functions/aa_00971030_FUN_00971030.md` |
| Function named | `docs/reconstruction/functions/aa_00971030_AssPreloader_PendingRemoveWithSideNotify_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005e2670` | Port as **editor river-handle polyline stamp** if client editor map tools are in scope: **ECX=host**, stack **map + 3 formals**, **RET 10**. Do **not** treat as level-up UI (float `0xa10e74` is **2.0**, not UI base). Grid is **u16** at `map+0x3e0`, stride `map+0x10`. |
| `00971030` | Port as **AssPreloader pending remove**: **ECX=preloader**, stack **key\***, **RET 4**. Order fixed: **side notify flag0 first**, then erase pending @ **+0x1C**. Do **not** swap with flag1 (`00970b60`) or call EraseFirstEqual alone. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0043c460` | CircularSentinel_Alloc0x14 (W35-B) — list head for stamp |
| `0x006442c0` | segment influence stamp (unowned) |
| `0x004a8d40` | map tile invalidate (unowned) |
| `0x00970b20` | SideHost_PushKeyFlag0 (W33-N) |
| `0x0043e630` | GuardedVector_EraseFirstEqual_ThiscallRange (W35-A) |
| `0x004ed310` | AssPreloader_ProcessKeyRingStep — sole caller of `00971030` |
| `0x005e2390` | family sibling with `"ed_riverhandle.geo"` |

Pair is **co-partition only** (W36-D); subsystems differ (editor map vs AssPreloader).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates beyond family geo evidence (`EdRiverHandle_*`) and AssPreloader nested duals.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
