# Dual A/B report — W38-AF OWN `aa_00965600` + `aa_004a05c0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-AF  
**Scope:** VAs `0x00965600`, `0x004a05c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-AF).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00965600` Path_MakeFxcInterned_Inferred | **accept-with-gaps** — empty→handle / strip-or-append `.fxc` / intern via `FUN_00989e00`+mgr`0x00d1eac8` / cdecl sealed; product plate + exact out-handle type open |
| `aa_004a05c0` GlobalBasicStringVec_AtShortIndex_Inferred | **accept** — short index into global `basic_string` vector (stride `0x1c`); OOB empty; cdecl `add esp,8`; 106 B sealed |

---

## VA `0x00965600` — sealed facts

1. **Body:** `0x00965600`–`0x00965742` inclusive (**323 B** / `0x143`); pad `CC`×13 then sibling @ `0x00965750`.
2. **ABI:** **`__cdecl`**; stack **`(outHandle*, pathObj*)`**; returns **`outHandle*`** (EAX); callers **`ADD ESP, 0x8`**. SEH frame (`LAB_009af9be`).
3. **Semantics:** Build a **`.fxc`** (compiled effect) path from a source path, then **intern** into the global string manager:
   - `c_str = *(char**)pathObj` (null → `PTR_DAT_00afa2bc` → `""` at `0x00a1419b`).
   - **Empty** (strlen 0): `*out = DAT_00d1ed24` (empty string handle); return out. No intern call.
   - Else construct temporary `std::basic_string` from c_str.
   - **`rfind('.', npos, 1)`** (char `0x2e`):
     - **npos (no dot):** `local += ".fxc"` (`0x00aa42cc`); c_str → **`FUN_00989e00`**.
     - **found:** `substr(0, dotPos)` → temp2; temp2 `+= ".fxc"`; c_str → **`FUN_00989e00`**; dtor temp2.
   - **Intern:** `mov ecx, 0x00d1eac8` (global string mgr); `FUN_00989e00(this=ecx, out, c_str)` — decompiler of this unit **drops ECX** and shows a 2-arg form; **bytes win**.
   - Destroy main temp string; restore SEH; return out.
4. **SSO c_str fixup:** if `capacity < 0x10`, use inline buffer address as c_str (standard MSVC SSO).
5. **Classification:** worker (effect/path → interned `.fxc` string handle).
6. **Callers (2):**
   - `FUN_009701d0` / `EffEffectSlot_BindByPath_Inferred` @ `0x00970236` (W37-Q) — optional debug path when `*(char*)(DAT_00d1f050+0x68) != 0`; result pushed to `FUN_00744ea0` (host notify). Call site `ADD ESP,8`.
   - `FUN_00751da0` @ `0x00751e0a` — same 2-arg cdecl + `ADD ESP,8`.
7. **Callees:** `basic_string` ctor/dtor/`rfind`/`substr`/`operator+=`; **`FUN_00989e00`** (string intern on mgr `0x00d1eac8`).
8. **Name:** `Path_MakeFxcInterned_Inferred` (Ghidra `FUN_00965600`; **Inferred** from `.fxc` + intern + Eff bind caller). **Reject** scaffold `Named_CalleeOf_Named_effDeviceEffect_00965600`.
9. **Decompile pitfalls:** (a) missing this for `FUN_00989e00`; (b) garbled `substr` arg order display; (c) signature `undefined`/void — returns out pointer. CF spine for empty / no-dot / strip-ext **≡ bytes**.

### Gaps

- Product English for path helper / string-manager class at `0x00d1eac8`.  
- Exact type of out handle (`DAT_00d1ed24` vs interned `*node`) vs plain `char*`.  
- Why empty uses `DAT_00d1ed24` while intern-empty path in `FUN_00989e00` uses `DAT_00d1eac0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00965600_Path_MakeFxcInterned_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00965600_Path_MakeFxcInterned_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00965600_FUN_00965600.md` |
| Annotated | `docs/reconstruction/raw/aa_00965600_FUN_00965600.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Path_MakeFxcInterned_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00965600.cpp` |
| Function | `docs/reconstruction/functions/aa_00965600_FUN_00965600.md` |
| Function named | `docs/reconstruction/functions/aa_00965600_Path_MakeFxcInterned_Inferred.md` |

---

## VA `0x004a05c0` — sealed facts

1. **Body:** `0x004a05c0`–`0x004a0629` inclusive (**106 B** / `0x6A`); pad `CC`×6 then sibling `FUN_004a0630` @ `0x004a0630`.
2. **ABI:** **`__cdecl`**; stack **`(out_basic_string*, int16 index)`**; returns **`out*`** (EAX); both exits **`pop esi; pop ecx; ret`**; callers **`ADD ESP, 0x8`**.
3. **Semantics:** Index into a **global vector of MSVC `basic_string`** (element stride **`0x1c`**):
   - `begin = DAT_00b0360c`, `end = DAT_00b03610` (image BSS zero; filled at runtime).
   - `count = (begin == 0) ? 0 : (end - begin) / 0x1c` (magic-multiply signed div in bytes).
   - Index loaded **`MOVSX`** from stack short (`0f bf 4c 24 10` after two pushes).
   - If **`count <= (uint)index`** (OOB / negative short as large unsigned): construct **empty** `basic_string(out, "")` — literal `""` @ `0x00a1419b`.
   - Else: **copy-construct** `basic_string(out, &begin[index])` where element address = `begin + index * 0x1c`.
4. **Classification:** worker (global string-table / string-vector lookup).
5. **Callers (3 funcs / 6 sites):**
   - `FUN_004b88e0` / `MissionHost_CollectMediaPreloads_Inferred` @ `0x004b8b92`, `0x004b8bf5` — resource word ids at list node `+0x1de` / `+0x1dc` → string names for media preload.
   - `FUN_00491480` @ `0x0049152b`, `0x00491790` — short fields `this+0xa8` / `+0xb0`.
   - `FUN_00491a00` @ `0x00491aae`, `0x00491c68` — short fields `this+0x98` / `+0xa0`.
6. **Callees:** `basic_string` ctor from `const char*` (empty); `basic_string` copy-ctor from peer string.
7. **Name:** `GlobalBasicStringVec_AtShortIndex_Inferred` (Ghidra `FUN_004a05c0`; **Inferred** from stride/`MOVSX`/global begin-end). **Reject** scaffold `Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_004a05c0`.
8. **Decompile ≡ bytes** for CF/ABI/bounds/stride. Full hex sealed below / in raw W38-AF append.

### Gaps

- Product name / owner of `DAT_00b0360c`/`DAT_00b03610` table (asset string table vs mission resource names).  
- Whether index is dense id or sparse resource key (callers pass raw shorts from object fields).  
- Runtime fill path for the vector.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a05c0_GlobalBasicStringVec_AtShortIndex_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004a05c0_GlobalBasicStringVec_AtShortIndex_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a05c0_FUN_004a05c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a05c0_FUN_004a05c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GlobalBasicStringVec_AtShortIndex_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a05c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004a05c0_FUN_004a05c0.md` |
| Function named | `docs/reconstruction/functions/aa_004a05c0_GlobalBasicStringVec_AtShortIndex_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00965600` | Port as **path → interned `.fxc` handle**: read c_str from path object; empty → shared empty handle `DAT_00d1ed24`; else strip last extension (or append if none) with `.fxc`, then intern via string manager at `0x00d1eac8` (`FUN_00989e00`). Used by effect-slot bind debug notify path. Prefer **bytes** for intern `this`. |
| `004a05c0` | Port as **`vector<string>::operator[]`-style copy-out by int16 index** on globals `DAT_00b0360c`/`DAT_00b03610`, element size **28** (`0x1c`). OOB → empty string. Callers feed short resource/asset ids. |
| Shared | Unrelated domains (FX path intern vs global string-vector lookup). Co-owned only by W38-AF partition pair. |

Shared context (not owned):

| VA / symbol | Role |
|---|---|
| `0x00989e00` | String intern on mgr (`this` + out + c_str) |
| `0x00d1eac8` | Global string manager object |
| `DAT_00d1ed24` | Empty string handle (early empty path) |
| `0x00aa42cc` | `".fxc"` literal |
| `0x009701d0` | `EffEffectSlot_BindByPath_Inferred` (W37-Q) — primary consumer of path helper |
| `0x00744ea0` | Host notify after fxc path intern (debug flag) |
| `DAT_00b0360c` / `DAT_00b03610` | Global basic_string vector begin/end |
| `0x004b88e0` | `MissionHost_CollectMediaPreloads_Inferred` (W32-H) — media name lookup |

Closes W38-AF OWN pair: effect-path `.fxc` intern helper + global short-indexed string-vector copy-out.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Clean avoids bare `undefined4` (`uint32_t` / explicit structs / `std::string`).
