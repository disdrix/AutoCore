# Dual A/B report — W31-C OWN `aa_00763f60` + `aa_00494700`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-C  
**Scope:** VAs `0x00763f60`, `0x00494700` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-C).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00763f60` GfxBody_CompleteDtor_Inferred | **accept-with-gaps** — complete-dtor CF/ABI/vtbl/`00a9da8c`/offsets/epilogue sealed; product class English open |
| `aa_00494700` Host_EnsureRegionCellOwned_Inferred | **accept-with-gaps** — region ensure CF/ABI/0x28 grid/0x5E0 create/evict/RET 4 sealed; host/ctx product English open |

---

## VA `0x00763f60` — sealed facts

1. **Body:** `0x00763f60`–`0x0076402d` inclusive (**206 B** / `0xCE`); pad `CC`; next fn = matching ctor `FUN_00764030` @ `0x00764030`.
2. **ABI:** ECX = this (`8B F1`); Ghidra `__fastcall` (thiscall-equivalent); SEH `LAB_009b0ac6`; EH starts **5**; epilogue **`ADD ESP,0x10; RET`** (`83 C4 10 C3`). **void**; does **not** free `this`.
3. **Semantics:** MSVC **complete destructor** for graphics-body composite:
   - Install class vtbl **`PTR_LAB_00a9da8c`** at entry.
   - `FUN_00763740(this)` nested gfx teardown.
   - `FUN_004380f0` with host `this+0x128` (vector of vtbl-owned pairs; free storage).
   - `FUN_00968110(this+0xDC)` free each pointer then vector triple.
   - Free buffer begin @ `+0xD0`; zero `+0xD0/+0xD4/+0xD8`.
   - Free buffer begin @ `+0xC0`; zero `+0xC0/+0xC4/+0xC8`.
   - `FUN_0096aec0(this+0x98)` aligned free + buffer.
   - `FUN_0096d7a0(this)` base subobject complete dtor.
4. **Classification:** worker (complete dtor body).
5. **Callers:** `ListTrackedObj_CompleteDtor` (`0x004be2a0`) ×3 @ `+0x2C8/+0x17C/+0x30` (W30-P); `FUN_004bd310`; `FUN_004b6ab0`; `FUN_004eb0f0`; `FUN_00581e20`; `FUN_0058e190`; `FUN_005b3fa0`; SEH unwind stubs.
6. **Callees:** `FUN_00763740`, `FUN_004380f0`, `FUN_00968110`, `operator_delete`, `FUN_0096aec0`, `FUN_0096d7a0`.
7. **Related:** Matching ctor `FUN_00764030` (same vtbl); embed stride ~**0x14C** in ListTrackedObj.
8. **Name:** `GfxBody_CompleteDtor_Inferred` (Ghidra `FUN_00763f60`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00763f60`.
9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); false noreturn on `operator_delete` ignored (full hex reaches epilogue).

### Gaps

- Product/MSVC demangle for class / vtbl `00a9da8c`.  
- Nested callee product English (`FUN_00763740`, vector element type, base `FUN_0096d7a0`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00763f60_GfxBody_CompleteDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00763f60_GfxBody_CompleteDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00763f60_FUN_00763f60.md` |
| Annotated | `docs/reconstruction/raw/aa_00763f60_FUN_00763f60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBody_CompleteDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00763f60.cpp` |
| Function | `docs/reconstruction/functions/aa_00763f60_FUN_00763f60.md` |
| Function named | `docs/reconstruction/functions/aa_00763f60_GfxBody_CompleteDtor_Inferred.md` |

---

## VA `0x00494700` — sealed facts

1. **Body:** `0x00494700`–`0x0049484f` exclusive (**335 B** / `0x14F`); next fn @ `0x0049484f`.
2. **ABI:** **`__thiscall`**; ECX = host (`8B F9`); stack formal = context (`param_2`); SEH `LAB_009a0bd0`; epilogue **`ADD ESP,0x18; RET 4`** (`C2 04 00`).
3. **Semantics:** Host **region ensure** (not grid rebuild):
   - Clear busy `host+0x53 = 0`; set `= 1` on exit.
   - Nested loops: x ∈ `[host+0x64, host+0x6c)`, y ∈ `[host+0x68, host+0x70)`.
   - Cell: `*(host+0x28) + (*(host+4)*y + x)*0x28` (same 0x28-stride host grid as W30-Q / W29-F).
   - If `cell+0x24 == 0`: `operator_new(0x5E0)` → `FUN_004becb0` (ListTrackedObj ctor) → store context @ `owned+0x5D4` → `FUN_004bd890(x,y)` → `FUN_004bf690` → store owned @ `cell+0x24`; optional pressure via `FUN_004bd660` may complete-dtor + `operator_delete` another cell’s owned (`ListTrackedObj_CompleteDtor` / W30-P), with optional flag `owned+0x5D0` when `ctx+0x7d==0`.
   - Else: `FUN_004bd6f0` (MRU relink on global list).
4. **Classification:** worker.
5. **Callers (2):** `FUN_004951d0` @ `0x00495240` (static culling — string `"Static culling"`); `FUN_00495130` @ `0x00495139`.
6. **Callees:** `operator_new`, `FUN_004becb0`, `FUN_004bd890`, `FUN_004bf690`, `FUN_004bd660`, `FUN_004be2a0` (`ListTrackedObj_CompleteDtor`), `operator_delete`, `FUN_004bd6f0`.
7. **Name:** `Host_EnsureRegionCellOwned_Inferred` (Ghidra `FUN_00494700`). Do **not** conflate with host rebuild `0x004941b0` (W30-Q).
8. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); false noreturn ignored.

### Gaps

- Product English for host / context types.  
- Pressure policy (`FUN_004bd660` / globals) product meaning.  
- Flag `ctx+0x7d` product meaning.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00494700_Host_EnsureRegionCellOwned_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00494700_Host_EnsureRegionCellOwned_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00494700_FUN_00494700.md` |
| Annotated | `docs/reconstruction/raw/aa_00494700_FUN_00494700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_EnsureRegionCellOwned_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00494700.cpp` |
| Function | `docs/reconstruction/functions/aa_00494700_FUN_00494700.md` |
| Function named | `docs/reconstruction/functions/aa_00494700_Host_EnsureRegionCellOwned_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00763f60` | Port as **complete dtor only** for graphics-body (`PTR_LAB_00a9da8c`). Order: set vtbl → nested teardown → free `+0x128` vector host → free ptr-vec `+0xDC` → free buffers `+0xD0` / `+0xC0` → aligned host `+0x98` → base `FUN_0096d7a0`. Do **not** `delete this`. Reject Mission-audio scaffold plate. Closes nested-member residual named in W30-P. |
| `00494700` | Port as **region ensure**: for AABB cells on 0x28-stride grid, create ListTrackedObj (0x5E0) when `owned@+0x24` null, else MRU-touch; optional pressure eviction via sealed `ListTrackedObj_CompleteDtor` + `delete`. Call with **host + context**; `RET 4`. Not a grid rebuild (use W30-Q for that). |
| Pair with | `ListTrackedObj_CompleteDtor` (`0x004be2a0`, W30-P); `Elem0x28_CompleteDtor` (`0x005b8000`, W29-F); host rebuild `Host_RebuildElem0x28ArrayFromMap` (`0x004941b0`, W30-Q); ctor twin `FUN_00764030`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs/body bounds). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Rejected bare Mission-audio `Named_CalleeOf_*` plate for `00763f60`.  
- Pattern: `docs/agents/task-dual-ab-0040d5b0-004be2a0-w30p-report.md` / W30-Q host grid.
