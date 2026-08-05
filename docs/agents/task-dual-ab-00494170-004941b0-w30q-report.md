# Dual A/B report — W30-Q OWN `aa_00494170` + `aa_004941b0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-Q  
**Scope:** VAs `0x00494170`, `0x004941b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md` (W30-Q).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00494170` Host_ClearElem0x28Array_Inferred | **accept-with-gaps** — free CF/ABI/stride 0x28/zero triple sealed; no static callers; product host English open |
| `aa_004941b0` Host_RebuildElem0x28ArrayFromMap_Inferred | **accept-with-gaps** — free+rebuild CF/formula/64·32 scales/caller ABI sealed; product map English open |

---

## VA `0x00494170` — sealed facts

1. **Body:** `0x00494170`–`0x004941af` inclusive (**64 B** / `0x40`); next fn @ `0x004941b0` (no pad).
2. **ABI:** ECX = host (`8B F1`); Ghidra `__fastcall` (thiscall-equivalent); no stack formals; **void**; bare **`C3`**.
3. **Semantics:** MSVC cookie-vector free @ `host+0x28`:
   - if arr: `_eh_vector_destructor_iterator_(arr, 0x28, *(arr-4), FUN_005b8000)` then `operator_delete[](arr-4)`
   - zero `+0x28`, `+4`, `+8`
4. **Classification:** worker (standalone free helper).
5. **Callers / xrefs:** **none** static (code or DATA; absolute `70 41 49 00` absent).
6. **Callees:** `_eh_vector_destructor_iterator_` @ `0x004899e4`; `operator_delete[]` @ `0x0048981c`; DATA dtor `FUN_005b8000` (W29-F `Elem0x28_CompleteDtor`).
7. **Related:** Same free fragment **inlined** in `Class_009c7a1c_CompleteDtor` (`0x004970b0`, W28-M); rebuild peer `0x004941b0`.
8. **Name:** `Host_ClearElem0x28Array_Inferred` (Ghidra `FUN_00494170`; **Inferred** structural).
9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product/PDB host type English.  
- Static call-graph usage (orphan).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00494170_Host_ClearElem0x28Array_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00494170_Host_ClearElem0x28Array_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00494170_FUN_00494170.md` |
| Annotated | `docs/reconstruction/raw/aa_00494170_FUN_00494170.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_ClearElem0x28Array_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00494170.cpp` |
| Function | `docs/reconstruction/functions/aa_00494170_FUN_00494170.md` |
| Function named | `docs/reconstruction/functions/aa_00494170_Host_ClearElem0x28Array_Inferred.md` |

---

## VA `0x004941b0` — sealed facts

1. **Body:** `0x004941b0`–`0x00494304` inclusive (**341 B** / `0x155`); pad `CC` @ `0x00494305+`.
2. **ABI:** **`__thiscall`**; ECX = host; stack formal = mapCtx; epilogue **`C2 04 00`** (`RET 4`) on both paths; SEH `LAB_009a0bbb`.
3. **Semantics:**
   - Free old cookie-vec @ `host+0x28` (stride **0x28**, dtor `FUN_005b8000`); zero `+0x28`.
   - If `*(mapCtx+0xe4f8)==0` → `FUN_007a4480(0,"VOG_DEBUG_STOP")` @ `0x00a15844`; return (dims `+4/+8` **not** zeroed on this path).
   - Scale: `DAT_00aefa50 = DAT_00a11088` (**64.0f**, dword `0x42800000`); if `*(char*)(mapCtx+0xf5)==0` then `DAT_00aaa8a4` (**32.0f**, dword `0x42000000`).
   - `dimX = ROUND((float)map[+0x10]/scale * map[+0x18]) + 1` → `host+4`
   - `dimY = ROUND((float)map[+0x14]/scale * map[+0x18]) + 1` → `host+8`
   - `count = dimX * dimY`; `new[](count*0x28+4)`; cookie count; ctor-iter `FUN_005b7db0` / dtor `FUN_005b8000`; store storage @ `host+0x28`.
4. **Classification:** worker.
5. **Callers (1):** `FUN_004ac100` @ `0x004ac12e` — `eax=[esi+0x340]`; `ecx=[eax+0xe898]`; `push eax`; `call`.
6. **Callees:** `FUN_007a4480`; `operator_delete[]`; `operator_new[]`; `_eh_vector_destructor_iterator_`; `_eh_vector_constructor_iterator_`.
7. **Name:** `Host_RebuildElem0x28ArrayFromMap_Inferred` (Ghidra `FUN_004941b0`). **Reject** scaffold `Named_VOG_DEBUG_STOP_004941b0`.
8. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); floats sealed via `read_memory`.

### Gaps

- Product English for host / mapCtx / map-row @ `+0xe4f8`.  
- Flag `+0xf5` product meaning beyond scale select.  
- Map field semantics (`+0x10/+0x14` ints, `+0x18` float).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004941b0_Host_RebuildElem0x28ArrayFromMap_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004941b0_Host_RebuildElem0x28ArrayFromMap_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004941b0_FUN_004941b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004941b0_FUN_004941b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_RebuildElem0x28ArrayFromMap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004941b0.cpp` |
| Legacy scaffold | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_004941b0.cpp` (**reject** as canonical) |
| Function | `docs/reconstruction/functions/aa_004941b0_FUN_004941b0.md` |
| Function named | `docs/reconstruction/functions/aa_004941b0_Host_RebuildElem0x28ArrayFromMap_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00494170` | Port as **free-only** host helper: destroy cookie-vector @ `+0x28` (elem stride **0x28**, dtor `Elem0x28_CompleteDtor`); zero `+0x28/+4/+8`. Do **not** merge with full `Class_009c7a1c_CompleteDtor`. No proven static callers — use only when ownership path needs explicit free. |
| `004941b0` | Port as **free+rebuild**: clear old array; if map ptr @ `mapCtx+0xe4f8` null → debug-stop return; else dims from map extents with scale **64** (default) or **32** (`mapCtx+0xf5==0`); `count=dimX*dimY` elements; default-ctor each. Call with **host + mapCtx** (caller loads host from `*(map+0xe898)`). Reject VOG_DEBUG_STOP as method name. |
| Pair with | `Elem0x28_CompleteDtor` (`0x005b8000`, W29-F); element ctor `FUN_005b7db0`; host complete dtor `Class_009c7a1c_CompleteDtor` (`0x004970b0`) for related layout. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs/body bounds). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Rejected bare `Named_VOG_DEBUG_STOP` plate for rebuild.  
- Pattern: `docs/agents/task-dual-ab-005b8000-004975e0-w29f-report.md` / W28-M host complete dtor.
