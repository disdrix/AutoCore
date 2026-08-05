# Dual A/B report — W34-A OWN `aa_0076ba10` + `aa_005b7250`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-A  
**Scope:** VAs `0x0076ba10`, `0x005b7250` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` + `get_function_xrefs`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-A).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0076ba10` Fs_DeleteDirTreeRecursive_Inferred | **accept-with-gaps** — cdecl path+flag, recursive list/join/rmdir CF, plates, `"/" join` sealed; product English + `FUN_00431ae0` layout open |
| `aa_005b7250` SpeedTreeRT_ComputeTree_Inferred | **accept-with-gaps** — thiscall RET 0x14, first-compute vs refresh gate, SpeedTreeRT plates, `.dds`/5.0f sealed; nested RT method English open |

---

## VA `0x0076ba10` — sealed facts

1. **Body:** `0x0076ba10`–`0x0076bbff` exclusive (**495 B** / `0x1EF`). Next: `FUN_0076bc00` @ `0x0076bc00`.
2. **ABI:** **cdecl** `(const char* path, char recursive_force)`; SEH `LAB_009adcab`; `ADD ESP,0x70; RET`; returns **AL** (`_rmdir==0`).
3. **Semantics:**
   - **Flag == 0:** `_rmdir(path)` only (no content walk).
   - **Flag != 0:** `FUN_0076b3f0(path, &listing)` basenames; for each (stride **0x1c**): `full = path + "/" + name` (`DAT_00a2eb5c`); if `FUN_0076adc0(full)` recurse self; else `FUN_0076b080(force)` with **ESI=full**; fail → `printf` + continue; then `_rmdir(path)` + `FUN_00431ae0` tidy.
   - File-fail plate uses **basename**; dir-fail plate uses **full path**.
4. **Classification:** worker (filesystem).
5. **Callers (4 xrefs):** self `@0x0076bb3c`; `FUN_0076bc00` `@0x0076bc1f`; `FUN_007b75b0` `@0x007b762e`; `FUN_00985010` `@0x0098531f`.
6. **Callees:** `FUN_0076b3f0`, `FUN_0076adc0`, `FUN_0076b080`, self, `FUN_00416490`, `_rmdir`, `_errno`, `printf`, `FUN_00431ae0`, `basic_string`.
7. **Name:** `Fs_DeleteDirTreeRecursive_Inferred` (Ghidra `FUN_0076ba10`; **Inferred**). **Reject** call-graph scaffold aliases as product names.
8. **Peers:** W33-C `Fs_ListDirBasenames` / `Fs_PathIsDirectory_Stat`.

### Gaps

- Product English plate.  
- Exact vector object layout into `FUN_00431ae0`.  
- Nested `FUN_0076b080` product plate (ESI path sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0076ba10_Fs_DeleteDirTreeRecursive_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0076ba10_Fs_DeleteDirTreeRecursive_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0076ba10_FUN_0076ba10.md` |
| Annotated | `docs/reconstruction/raw/aa_0076ba10_FUN_0076ba10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_DeleteDirTreeRecursive_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076ba10.cpp` |
| Function | `docs/reconstruction/functions/aa_0076ba10_FUN_0076ba10.md` |
| Function named | `docs/reconstruction/functions/aa_0076ba10_Fs_DeleteDirTreeRecursive_Inferred.md` |

---

## VA `0x005b7250` — sealed facts

1. **Body:** `0x005b7250`–`0x005b76e5` exclusive (**1173 B** / `0x495`); pad `CC` after `RET 0x14`.
2. **ABI:** **thiscall** ECX=`this`; **5 stack formals**; **`RET 0x14`**; returns **AL**.
3. **Semantics:**
   - `this+0x174 = asset_cfg`; null → **0**.
   - Ensure `this+0x30` SpeedTree object (`operator_new(0x9c)` + `FUN_0068a690`).
   - `FUN_00685ed0(1)`.
   - If `*(asset_cfg+0x128) >= 1`: `FUN_005b71a0(1)` → **1** (refresh).
   - Else first compute: resource `FUN_007b6a20`/`FUN_007b7420`; load `FUN_0068b360`; on fail plate `"SpeedTreeRT Error: %s\n"`; configure; `FUN_00688680(0, param_4, 1)`; on fail plate `"\nFatal Error, cannot compute tree [%s]\n\n"`; bounds + three `FUN_005b7770`; LOD `dx * 5.0f` (`DAT_00aaa688`); material `0x1c`; optional `.dds` (`DAT_00a2c53c`) textures at `+0x170` / `+0x24`; `FUN_005b71a0(0)` → **1**.
4. **Classification:** worker (SpeedTreeRT / graphics).
5. **Callers (2):** `FUN_00582090` @ `0x00582222` and `0x00582265` (builds `"%s.spt"`).
6. **Name:** `SpeedTreeRT_ComputeTree_Inferred` (Ghidra `FUN_005b7250`; **Inferred** from plates + caller). **Reject** call-graph scaffold as product name.
7. **Constants:** `.dds` @ `0x00a2c53c`; **5.0f** @ `0x00aaa688`; axis imms `1.0f / -1.0f`.

### Gaps

- Nested SpeedTree SDK method English for `FUN_00686xxx` / `FUN_00688680`.  
- Exact C++ types for `resource_key` / `asset_cfg` / `compute_arg`.  
- `local_c0` vs `this+0x30` load-target aliasing nuance.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005b7250_SpeedTreeRT_ComputeTree_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005b7250_SpeedTreeRT_ComputeTree_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005b7250_FUN_005b7250.md` |
| Annotated | `docs/reconstruction/raw/aa_005b7250_FUN_005b7250.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SpeedTreeRT_ComputeTree_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b7250.cpp` |
| Function | `docs/reconstruction/functions/aa_005b7250_FUN_005b7250.md` |
| Function named | `docs/reconstruction/functions/aa_005b7250_SpeedTreeRT_ComputeTree_Inferred.md` |

---

## Tooling compliance

| Rule | Status |
|------|--------|
| `decompile_function` + `read_memory` only for body RE | **Yes** |
| No `disassemble_bytes` | **Yes** |
| No Launcher | **Yes** |
| No parent ledger edits | **Yes** |
| No cross-agent VA writes | **Yes** (only `0076ba10`, `005b7250`) |
| No invented product names without evidence | **Yes** (`SpeedTreeRT` from plate; FS name structural `_Inferred`) |
| Avoid bare `undefined4` in clean | **Yes** (`uint32_t` / typed pointers) |

---

## Summary

Both W34-A owned VAs dual-sealed at **accept-with-gaps**. `0x0076ba10` is the recursive directory purge used by pack/cleanup paths; `0x005b7250` is the SpeedTreeRT first-compute / refresh worker behind `.spt` load in `FUN_00582090`.
