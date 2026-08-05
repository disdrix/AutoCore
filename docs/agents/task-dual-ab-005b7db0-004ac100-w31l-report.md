# Dual A/B report — W31-L OWN `aa_005b7db0` + `aa_004ac100`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-L  
**Scope:** VAs `0x005b7db0`, `0x004ac100` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-L).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005b7db0` Elem0x28_DefaultCtor | **accept-with-gaps** — element default-ctor CF/ABI/stride 0x28/zero-set/SEH sealed; product demangle open |
| `aa_004ac100` MapChild_RebuildHostElemsAndIntGrid_Inferred | **accept-with-gaps** — orchestrator CF/ABI/`ret 4`/host load/dims/int-grid sealed; product English + follow-ups open |

---

## VA `0x005b7db0` — sealed facts

1. **Body:** `0x005b7db0`–`0x005b7dee` exclusive (**62 B** / `0x3E`); final bare **`C3`**; pad `CC`; next fn `FUN_005b7df0` @ `0x005b7df0`.
2. **ABI:** **`__thiscall`** (Ghidra `__fastcall` + ECX = same); ECX = element; no stack formals; **void**; bare **`RET`**. SEH `LAB_009a6ad8` (install/teardown only).
3. **Semantics:** MSVC **element default constructor** for **0x28-byte** cookie-vector elements:
   - Zero buffer triple @ `+0x4/+0x8/+0xc`
   - Zero list-ptr vector triple @ `+0x14/+0x18/+0x1c`
   - Zero owned @ `+0x24`
   - Does **not** write `+0`, `+0x10`, `+0x20`
4. **Classification:** leaf (element ctor callback).
5. **Xrefs (1 DATA):** `FUN_004941b0` @ `0x004942db` — `_eh_vector_constructor_iterator_(…, 0x28, count, FUN_005b7db0, FUN_005b8000)`.
6. **Callees:** none.
7. **Related:** Peer dtor `Elem0x28_CompleteDtor` (`0x005b8000`, W29-F); host rebuild `Host_RebuildElem0x28ArrayFromMap_Inferred` (`0x004941b0`, W30-Q); free helper `Host_ClearElem0x28Array_Inferred` (`0x00494170`).
8. **Name:** `Elem0x28_DefaultCtor` (Ghidra `FUN_005b7db0`). **Reject** scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_005b7db0`.
9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); SEH sealed by bytes (decomp omits frame).

### Gaps

- Product/PDB demangle for element type.  
- English for untouched `+0` / `+0x10` / `+0x20`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005b7db0_Elem0x28_DefaultCtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005b7db0_Elem0x28_DefaultCtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005b7db0_FUN_005b7db0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b7db0_FUN_005b7db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Elem0x28_DefaultCtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b7db0.cpp` |
| Function | `docs/reconstruction/functions/aa_005b7db0_FUN_005b7db0.md` |
| Function named | `docs/reconstruction/functions/aa_005b7db0_Elem0x28_DefaultCtor.md` |

---

## VA `0x004ac100` — sealed facts

1. **Body:** `0x004ac100`–`0x004ac215` exclusive (**277 B** / `0x115`); all exits **`C2 04 00`** (`RET 4`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map-child; stack formal **unused** (callers push `0` / ebx); cleans **4**; returns **AL** 0/1.
3. **Semantics:**
   - If `*(this+0x3d8)==0` → `FUN_007a4480(0,"VOG_DEBUG_STOP"@0x00a15844)`; return 0.
   - `mapCtx=*(this+0x340)`; `host=*(mapCtx+0xe898)`; `FUN_004941b0(host, mapCtx)` (W30-Q).
   - `dimX = signed_div16(*(this+0x10))` → `+0x384`; `dimY` from `+0x14` → `+0x388`. Formula `(x+(x>>31&0xf))>>4`.
   - `delete[]` old grid @ `+0x38c`; `new[](dimX*dimY*4)`; zero via `rep stosd` + remainder `rep stosb`.
   - `FUN_004abd00(this)`; `FUN_004aa300(this)`; `FUN_004930b0(*(mapCtx+0xe894))`.
   - If `DAT_00b03631`: `FUN_005c0f40(this)` else `FUN_005bf720()`; `DAT_00b03632=DAT_00b03631`; return 1.
4. **Classification:** worker.
5. **Callers:** `FUN_004ac220` @ `0x004ac284` (`push 0`); `FUN_004d9cd0` @ `0x004d9ea1` (ecx = map child @ `+0xe4f8`); code site `0x00952078` (no function envelope).
6. **Callees:** `FUN_004941b0`, `FUN_007a4480`, `operator_delete[]`, `operator_new[]`, `FUN_004abd00`, `FUN_004aa300`, `FUN_004930b0`, `FUN_005c0f40`, `FUN_005bf720`.
7. **Name:** `MapChild_RebuildHostElemsAndIntGrid_Inferred` (Ghidra `FUN_004ac100`). **Reject** scaffold `Named_VOG_DEBUG_STOP_004ac100`.
8. **Decompile ≡ raw CF** for stages; **bytes supersede** host load for `FUN_004941b0`, `ret 4`, grid remainder zero, and offset `0x384` (decomp shows decimal 900).

### Gaps

- Product English for map-child / `+0x3d8` required field.  
- Semantics of follow-up helpers and `DAT_00b03631`/`32` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004ac100_MapChild_RebuildHostElemsAndIntGrid_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004ac100_MapChild_RebuildHostElemsAndIntGrid_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004ac100_FUN_004ac100.md` |
| Annotated | `docs/reconstruction/raw/aa_004ac100_FUN_004ac100.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MapChild_RebuildHostElemsAndIntGrid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004ac100.cpp` |
| Legacy scaffold | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_004ac100.cpp` (**reject** as canonical) |
| Function | `docs/reconstruction/functions/aa_004ac100_FUN_004ac100.md` |
| Function named | `docs/reconstruction/functions/aa_004ac100_MapChild_RebuildHostElemsAndIntGrid_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005b7db0` | Port as **element default ctor** (stride **0x28**): zero buffer triple, list-ptr vector triple, owned@+0x24. Pair exclusively with `Elem0x28_CompleteDtor` for `eh_vector_ctor_iter` / dtor_iter. Do **not** invent VOG plate. Leave +0/+0x10/+0x20 as product-uninitialized unless later evidence. |
| `004ac100` | Port as **map-child orchestrator**: guard +0x3d8; rebuild host elems via `Host_RebuildElem0x28ArrayFromMap` (host from map+0xe898); signed /16 dims; replace zeroed int grid @ +0x38c; follow-ups; **thiscall + ret 4**. Reject VOG_DEBUG_STOP as method name. Do **not** merge with `FUN_004941b0` body. |
| Pair with | `Elem0x28_CompleteDtor` (`0x005b8000`, W29-F); `Host_RebuildElem0x28ArrayFromMap_Inferred` (`0x004941b0`, W30-Q); `Host_ClearElem0x28Array_Inferred` (`0x00494170`); host complete dtor `Class_009c7a1c_CompleteDtor` (`0x004970b0`) for related layout. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs/body bounds). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only where demangle open.  
- Rejected bare `Named_VOG_DEBUG_STOP` / `Named_CalleeOf_*` plates.  
- Pattern: `docs/agents/task-dual-ab-005b8000-004975e0-w29f-report.md` / `docs/agents/task-dual-ab-00494170-004941b0-w30q-report.md`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
