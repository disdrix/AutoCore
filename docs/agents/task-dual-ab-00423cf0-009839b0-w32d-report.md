# Dual A/B report — W32-D OWN `aa_00423cf0` + `aa_009839b0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-D  
**Scope:** VAs `0x00423cf0`, `0x009839b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` (no disasm dump). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-D).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00423cf0` AssResolverA_NestedHash_Ctor_Inferred | **accept-with-gaps** — ABI/layout/sentinel+buckets/flags + sole AssResolverA caller sealed; product English + flag meaning + unwritten +0/+4 open |
| `aa_009839b0` Fs_DirRecurseCollectLeafPaths_Inferred | **accept-with-gaps** — ABI/CF/is_dir/list/join/`/`/recurse + out-vector leaf push (bytes win) sealed; caller product plates open |

---

## VA `0x00423cf0` — sealed facts

1. **Body:** `0x00423cf0`–`0x00423d51` (**98 B** / `0x62`; pad `CC` then `FUN_00423d60` @ `0x00423d60`).
2. **ABI:** stack **`this*`** placement ctor; **`RET 0x4`**; returns **`this` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - `FUN_00423d60()` circular sentinel `new(0x28)` → **`this+0x08`**.
   - Zero **`this+0x0c`**.
   - **`FUN_004646e0(this+0x10, 9, &sentinel)`** — 9-bucket pointer table filled with sentinel.
   - **`this+0x20 = 1`**, **`this+0x24 = 1`**.
4. **Size:** nested span **0x28** inside AssResolverA (outer `+0x08` … CS at outer `+0x30`).
5. **Classification:** worker.
6. **Callers (1):** `FUN_00423be0` @ `0x00423c0e`.
7. **Callees:** `FUN_00423d60`, `FUN_004646e0`.
8. **Name:** `AssResolverA_NestedHash_Ctor_Inferred` (Ghidra `FUN_00423cf0`; **Inferred**). Reject scaffold `Named_CalleeOf_*`.
9. **Decompile ≡ bytes** for stores and `RET 4`. Full hex: raw W32-D append.

### Gaps

- Product/PDB type English for nested hash/map.  
- Unwritten `+0x00/+0x04`; meaning of flags `+0x20/+0x24`.  
- Unowned callees’ full product contracts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00423cf0_AssResolverA_NestedHash_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00423cf0_AssResolverA_NestedHash_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00423cf0_FUN_00423cf0.md` |
| Annotated | `docs/reconstruction/raw/aa_00423cf0_FUN_00423cf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssResolverA_NestedHash_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00423cf0.cpp` |
| Function | `docs/reconstruction/functions/aa_00423cf0_FUN_00423cf0.md` |
| Function named | `docs/reconstruction/functions/aa_00423cf0_AssResolverA_NestedHash_Ctor_Inferred.md` |

---

## VA `0x009839b0` — sealed facts

1. **Body:** `0x009839b0`–`0x00983b53` (**420 B** / `0x1A4`; pad `CC` then next @ `0x00983b60`).
2. **ABI:** **cdecl** 2 formals; bare **`RET`**; returns **`0`** success / **`0xFFFFFFFF`** if path is not a directory.
3. **Semantics:**
   - `FUN_0076adc0(path)` is-directory gate; fail → **`-1`**.
   - `FUN_0076b3f0` list entries (string stride **0x1c**).
   - Join with **`DAT_00a2eb5c`** = **`"/"`** (`2f 00 00 00`).
   - Leaf: **thiscall** `FUN_004301f0` push path onto **`param_2` out vector** (**bytes win** over decompiler).
   - Dir: recurse **`FUN_009839b0(child, param_2)`**.
   - Cleanup listing via `FUN_00431ae0`; return **`0`**.
4. **Does not** construct AssResolverCore (adjacent prior unit `0x00983940`).
5. **Classification:** worker.
6. **Callers (3):** self @ `0x00983ada`; `FUN_00984340` @ `0x009844a1`; `FUN_00984c70` @ `0x00984ca6`.
7. **Callees:** `FUN_0076adc0`, `FUN_0076b3f0`, `basic_string` ctor/dtor, `FUN_00416490`, `FUN_00416410`, `FUN_004301f0`, self, `FUN_00431ae0`.
8. **Name:** `Fs_DirRecurseCollectLeafPaths_Inferred` (Ghidra `FUN_009839b0`; **Inferred**).
9. **Decompile ≡ bytes** for CF; **bytes win** on out-vector leaf push.

### Gaps

- Product English for callers `00984340` / `00984c70` / consumer `00984910`.  
- Exact destroy ABI of `FUN_00431ae0` (unowned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009839b0_Fs_DirRecurseCollectLeafPaths_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009839b0_Fs_DirRecurseCollectLeafPaths_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009839b0_FUN_009839b0.md` |
| Annotated | `docs/reconstruction/raw/aa_009839b0_FUN_009839b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_DirRecurseCollectLeafPaths_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009839b0.cpp` |
| Function | `docs/reconstruction/functions/aa_009839b0_FUN_009839b0.md` |
| Function named | `docs/reconstruction/functions/aa_009839b0_Fs_DirRecurseCollectLeafPaths_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00423cf0` | Port as **placement ctor** (stack this, RET 4). Nested at AssResolverA **+0x08**, size **0x28**. Sentinel node + 9-bucket fill + size0 + flags1. Pair with W31-G parent ctor / W29-D release path. Twin shape: `FUN_00469db0`. |
| `009839b0` | Port as **cdecl** free function collecting leaf paths into a string vector. Preserve **`/`** separator and is_dir gate. Leaf push is thiscall into **out** vector. Used by path-expand helpers near effects/ass. |
| Pair with | W31-G `AssManager_ResolverA_Ctor` / `AssResolverCore_Ctor`; W32-E `FUN_00469db0` / `FUN_00985010`; unowned `FUN_0076adc0` / `FUN_004301f0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Rejected scaffold `Named_CalleeOf_*` as product alias.
