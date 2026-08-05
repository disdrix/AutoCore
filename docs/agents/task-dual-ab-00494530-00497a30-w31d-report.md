# Dual A/B report — W31-D OWN `aa_00494530` + `aa_00497a30`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-D  
**Scope:** VAs `0x00494530`, `0x00497a30` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + `get_xrefs_to` (+ wrapper site). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-D).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00494530` Host_ClearListTrackedOwnedInRect_Inferred | **accept-with-gaps** — rect CF/ABI/stride/owned dtor+delete/wrapper sealed; product host English open |
| `aa_00497a30` Ctx_ClearListTrackedOwnedAtScaledXY_Inferred | **accept-with-gaps** — host path/scale floats/index/`ret 8`/owned teardown sealed; product ctx English + orphan callers open |

---

## VA `0x00494530` — sealed facts

1. **Body:** `0x00494530`–`0x0049459d` inclusive (**110 B** / `0x6E`); pad `CC`; next fn `FUN_004945a0` @ `0x004945a0`.
2. **ABI:** ECX = host (`8B F1`); Ghidra `__fastcall` (thiscall-equivalent); no stack formals; **void**; bare **`C3`**.
3. **Semantics:** Half-open dirty rect walk on host:
   - `x ∈ [host+0x64, host+0x6C)`, `y ∈ [host+0x68, host+0x70)`.
   - `index = *(host+4) * y + x`; `elem = *(host+0x28) + index*0x28`.
   - If `owned = *(elem+0x24)`: `ListTrackedObj_CompleteDtor` (`FUN_004be2a0`) then `operator_delete(owned)`.
   - **Always** `*(elem+0x24) = 0` (null path included).
4. **Classification:** worker.
5. **Callers / xrefs:** call site `0x0094ecec` inside wrapper `0x0094ece0`:
   - `host = *(*(this+0xE04)+0xE898)`; `call FUN_00494530`; `mov eax,1`; `ret 8`.
   - DATA xref to wrapper from `FUN_00959230` @ `0x009596a5`.
6. **Callees:** `FUN_004be2a0` (`ListTrackedObj_CompleteDtor`, W30-P); `operator_delete` @ `0x00489822`.
7. **Related:** sibling SEH rect walker `FUN_00494700` (W31-C, not owned); element dtor `FUN_005b8000` also clears owned@+0x24 (W29-F).
8. **Name:** `Host_ClearListTrackedOwnedInRect_Inferred` (Ghidra `FUN_00494530`; **Inferred** structural).
9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); false noreturn on delete overridden by body hex.

### Gaps

- Product/PDB host type and rect field English.  
- Who publishes dirty rect before call.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00494530_Host_ClearListTrackedOwnedInRect_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00494530_Host_ClearListTrackedOwnedInRect_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00494530_FUN_00494530.md` |
| Annotated | `docs/reconstruction/raw/aa_00494530_FUN_00494530.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_ClearListTrackedOwnedInRect_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00494530.cpp` |
| Function | `docs/reconstruction/functions/aa_00494530_FUN_00494530.md` |
| Function named | `docs/reconstruction/functions/aa_00494530_Host_ClearListTrackedOwnedInRect_Inferred.md` |

---

## VA `0x00497a30` — sealed facts

1. **Body:** `0x00497a30`–`0x00497ab8` inclusive (**137 B** / `0x89`); pad `CC` @ `0x00497ab9+`.
2. **ABI:** **`__thiscall`**; ECX = ctx; stack `uint xUnits`, `uint yUnits`; epilogue **`C2 08 00`** (`ret 8`); returns **1**.
3. **Semantics:**
   - `host = *(*(ctx+0xC4)+0xE898)`; `arr = *(host+0x28)`; `dimX = *(host+4)`.
   - `div = fistp(DAT_00aefa50 * DAT_00a14000)` once (FPU RC chop via `or ah,0x0C`; decompiler labels `ROUND`).
   - `index = (yUnits/div)*dimX + (xUnits/div)`.
   - Same owned@`elem+0x24` complete-dtor + delete + always-null as rect clearer.
4. **Floats (`read_memory`):**
   - `DAT_00aefa50` @ `0x00aefa50` = dword `0x42000000` = **32.0f** (runtime scale; rebuild peer may set 64/32).
   - `DAT_00a14000` @ `0x00a14000` = dword `0x3d800000` = **0.0625f**.
   - Product **2.0** (scale 32) or **4.0** (scale 64).
5. **Classification:** worker.
6. **Callers / xrefs:** **none** static (orphan).
7. **Callees:** `FUN_004be2a0`; `operator_delete` @ `0x00489822`.
8. **Name:** `Ctx_ClearListTrackedOwnedAtScaledXY_Inferred` (Ghidra `FUN_00497a30`; **Inferred** structural).
9. **Decompile ≡ raw CF**; single FPU product reused (decompiler shows product twice — bytes win).

### Gaps

- Product English for ctx / `+0xC4` / coordinate units.  
- Static call-graph usage (orphan).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00497a30_Ctx_ClearListTrackedOwnedAtScaledXY_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00497a30_Ctx_ClearListTrackedOwnedAtScaledXY_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00497a30_FUN_00497a30.md` |
| Annotated | `docs/reconstruction/raw/aa_00497a30_FUN_00497a30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Ctx_ClearListTrackedOwnedAtScaledXY_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00497a30.cpp` |
| Function | `docs/reconstruction/functions/aa_00497a30_FUN_00497a30.md` |
| Function named | `docs/reconstruction/functions/aa_00497a30_Ctx_ClearListTrackedOwnedAtScaledXY_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00494530` | Port as **host rect owned-clear**: loop half-open rect; per cell `ListTrackedObj_CompleteDtor` + `delete` + null `@+0x24`. Do **not** free the 0x28 elem array. ECX is host. Optional wrapper: load host from `*( *(obj+0xE04)+0xE898 )`, return 1 / ret 8. |
| `00497a30` | Port as **ctx single-cell scaled clear**: host via `+0xC4`→`+0xE898`; `div=trunc(scale*0.0625)`; index `(y/div)*dimX+(x/div)`; same owned teardown; **return 1 / ret 8**. Keep scale as shared global (not hardcode 32). |
| Pair with | `ListTrackedObj_CompleteDtor` (`0x004be2a0`, W30-P); `Elem0x28_CompleteDtor` (`0x005b8000`, W29-F); host rebuild/free (`0x004941b0` / `0x00494170`, W30-Q); host ctor/dtor (`0x00496f70` / `0x004970b0`). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs / wrapper memory). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Pattern: W30-P owned dtor + W30-Q host grid + W29-F elem owned@+0x24.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
