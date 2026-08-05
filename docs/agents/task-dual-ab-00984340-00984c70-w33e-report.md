# Dual A/B report — W33-E OWN `aa_00984340` + `aa_00984c70`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-E  
**Scope:** VAs `0x00984340`, `0x00984c70` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-E).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00984340` Fs_ExpandPathSpecToStringVec_Inferred | **accept-with-gaps** — cdecl/branch-matrix/`@`/glob/dir/separator sealed; 0 external static xrefs + product English open |
| `aa_00984c70` AssPackManager_AddDirectoryTree_Inferred | **accept-with-gaps** — collect-then-add CF + ECX path/stack pack/AssPackManager nested plate sealed; EDI mode + 0 xrefs open |

---

## VA `0x00984340` — sealed facts

1. **Body:** `0x00984340`–`0x009847bb` inclusive (**1148 B** / `0x47C`; pad `CC` then `FUN_009847c0` @ `0x009847c0`).
2. **ABI:** **cdecl** 3 stack formals — **`out_vec*`**, **`const char* path`**, **`char recurse`**; bare **`RET`**; returns **`out_vec*` in EAX**.
3. **Semantics:**
   - **`path[0]=='@'`:** `FUN_009841d0(path+1)` path-list; for each line **self-recurse**; merge string results (stride **0x1c**).
   - **Not dir** (`FUN_0076adc0==0`): regular file (`stat` + **`st_mode>>15&1`**) → push path; else **glob** (split on `/` or `\`, list, `FUN_0076b210`, join **`/`**).
   - **Dir + recurse:** `FUN_009839b0` leaf collect; **dir + !recurse:** one-level children join-push.
   - `FUN_00469d10` assign collector → out; return out.
4. **Classification:** worker (path-spec expansion; ass/pack tool cluster).
5. **Callers:** **self only** @ `0x009843e5` (0 external static xrefs).
6. **Callees:** `FUN_009841d0`, `FUN_0076adc0`, `stat`, `strrchr`, `FUN_0076b3f0`, `FUN_0076b210`, `FUN_00416490`, `FUN_00416410`, `FUN_004301f0`, `FUN_009839b0`, self, `FUN_00431ae0`, `FUN_00469d10`, string ctor/dtor.
7. **Name:** `Fs_ExpandPathSpecToStringVec_Inferred` (Ghidra `FUN_00984340`; **Inferred**).
8. **Decompile ≡ scaffold CF**; separator `DAT_00a2eb5c` = `"/"`. Entry/exit hex: raw W33-E append.

### Gaps

- External invocation path (0 static external xrefs).  
- Product English / nested `FUN_009841d0` plate.  
- Per-site thiscall ECX for every push (collector vs out) — end assign seals result.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00984340_Fs_ExpandPathSpecToStringVec_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00984340_Fs_ExpandPathSpecToStringVec_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00984340_FUN_00984340.md` |
| Annotated | `docs/reconstruction/raw/aa_00984340_FUN_00984340.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_ExpandPathSpecToStringVec_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00984340.cpp` |
| Function | `docs/reconstruction/functions/aa_00984340_FUN_00984340.md` |
| Function named | `docs/reconstruction/functions/aa_00984340_Fs_ExpandPathSpecToStringVec_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00984340.md` |

---

## VA `0x00984c70` — sealed facts

1. **Body:** `0x00984c70`–`0x00984d25` inclusive (**182 B** / `0xB6`; pad `CC` then `FUN_00984d30` @ `0x00984d30`).
2. **ABI (bytes win):** **ECX=`const char* dir_path`**; stack **`AssPackManager* pack`**; **EDI=mode** pushed into add-file but **never written** in body (gap); bare **`RET`**; returns **0**.
3. **Semantics:**
   - `FUN_009839b0(path, &listing)` leaf collect.
   - If `rc >= 0`: for each leaf → **`FUN_00984910`** with ECX=leaf c_str, pack, EDI mode, flags **`1,0,0`**.
   - Destroy listing; return **0**.
4. **Classification:** worker (offline AssPackManager directory ingest).
5. **Callers:** **none static** (0 code/data xrefs).
6. **Callees:** `FUN_009839b0`, `FUN_00984910`, string ctor/dtor, `FUN_00431ae0`.
7. **Name:** `AssPackManager_AddDirectoryTree_Inferred` (Ghidra `FUN_00984c70`; **Inferred** from nested `assPackManager.cpp` plate + CF).
8. **Decompile ≡ scaffold CF**; full body hex: raw W33-E append. Decompiler `__thiscall` conflates path/pack — **bytes win**.

### Gaps

- Zero static xrefs — invocation path open.  
- EDI mode product meaning.  
- Nested `FUN_00984910` full formal plate (unowned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00984c70_AssPackManager_AddDirectoryTree_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00984c70_AssPackManager_AddDirectoryTree_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00984c70_FUN_00984c70.md` |
| Annotated | `docs/reconstruction/raw/aa_00984c70_FUN_00984c70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_AddDirectoryTree_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00984c70.cpp` |
| Function | `docs/reconstruction/functions/aa_00984c70_FUN_00984c70.md` |
| Function named | `docs/reconstruction/functions/aa_00984c70_AssPackManager_AddDirectoryTree_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00984c70.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00984340` | Port as **cdecl** free path-spec expander: out vec, path, recurse flag. Preserve `@` list, glob, one-level vs deep dir, join **`/`**. Not a pack method. Invoker open. |
| `00984c70` | Port as **ECX=path + stack AssPackManager*** directory ingest: leaf collect then add-file with flags **1,0,0**. Preserve **EDI** mode passthrough until add-file dual seals it. **Not** a gameplay-hot path (0 xrefs). |
| Pair with | W32-D `Fs_DirRecurseCollectLeafPaths_Inferred`; W31-H `AssPackManager_OpenPackFile_Inferred`; W32-E `AssPackManager_CompactPackFile_Inferred`; nested `FUN_00984910` / `FUN_009841d0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`void*` / explicit roles).  
- Rejected decompiler thiscall-on-pack for `00984c70` when bytes show ECX=path.
