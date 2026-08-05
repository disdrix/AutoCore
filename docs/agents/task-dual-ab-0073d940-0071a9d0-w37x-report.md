# Dual A/B report — W37-X OWN `aa_0073d940` + `aa_0071a9d0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-X  
**Scope:** VAs `0x0073d940`, `0x0071a9d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-X).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0073d940` MatRegistry_FindCompatibleMaterial_Inferred | **accept** — ECX registry + stack material lookup, 0x14 buckets, `FUN_00752590` gate, RET 4, **lookup-only** (108 B); product English residual only |
| `aa_0071a9d0` AssPackObject_OpenFromPath_Inferred | **accept-with-gaps** — EAX path / EDI pack / stack manager, glm path, dual-open + footer parse handoff sealed (277 B); unowned parse + product pack English open |

---

## VA `0x0073d940` — sealed facts

1. **Body:** `0x0073d940`–`0x0073d9ab` (**108 B** / `0x6C`; pad `CC` then next @ `0x0073d9b0`).
2. **ABI:** **ECX = MatRegistry\*** host; **stack = Material\*** probe; returns **Material\*** or **0** in EAX; **`RET 4`**.
3. **Semantics:**
   - Reject null probe or null `probe+8` (effect/key).
   - Walk `[host+4, host+8)` stride **0x14**; match `entry[0] == *(probe+8)`.
   - Scan material\* range `[entry+8, entry+0xC)`.
   - Skip **self**; skip where `FUN_00752590(candidate /*EAX*/, probe /*EDX*/)==0`.
   - Return first compatible alternate, else 0.
4. **Host global:** callers load **`MOV ECX, dword ptr [DAT_00d1f61c]`** before CALL.
5. **Classification:** **worker** (pure registry lookup).
6. **Callers (14):** `FUN_0099e6c0`, `FUN_0099f450`, `FUN_00731130`, `FUN_007300c0`, `FUN_0098fd80`, `FUN_0098df00`, `FUN_0099f810`, `FUN_0099e4a0`, `FUN_0099eb60`, `FUN_0096f740`, `FUN_0099d060`, `FUN_0099e0a0`, `FUN_0099e2c0`, `FUN_00759090`. **Xrefs: 17.**
7. **Callees:** `FUN_00752590` only.
8. **Name:** `MatRegistry_FindCompatibleMaterial_Inferred` (Ghidra `FUN_0073d940`; **Inferred** structural).
9. **Correction:** Prior dual notes that called this the “refcount swap” are **caller-side**. Body does **not** AddRef/Release; callers do `+1` @ found+4 / first-use vfunc+4 / dec old / store after non-null return.
10. **Decompile ≡ bytes** for stride/key/range/RET4. Full 108 B hex in raw W37-X append.

### Gaps

- Product/PDB English for registry + material classes.  
- Unused 0x14-entry fields (+4, +0x10).  
- Unowned full dual of `FUN_00752590`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0073d940_MatRegistry_FindCompatibleMaterial_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0073d940_MatRegistry_FindCompatibleMaterial_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0073d940_FUN_0073d940.md` |
| Annotated | `docs/reconstruction/raw/aa_0073d940_FUN_0073d940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MatRegistry_FindCompatibleMaterial_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073d940.cpp` |
| Function | `docs/reconstruction/functions/aa_0073d940_FUN_0073d940.md` |
| Function named | `docs/reconstruction/functions/aa_0073d940_MatRegistry_FindCompatibleMaterial_Inferred.md` |

---

## VA `0x0071a9d0` — sealed facts

1. **Body:** `0x0071a9d0`–`0x0071aae4` (**277 B** / `0x115`; pad `CC` then next).
2. **ABI:** **EAX = path**; **EDI = pack object\*** (0x44); **stack = AssPackManager\*** owner; returns status in EAX; **`RET 4`**. Frame `SUB/ADD ESP,0x130`.
3. **Semantics:**
   - `_strdup(path)` → store at **`pack+0x28`**.
   - Path normalize via `FUN_0076b190` with extension token **`"glm"`** @ `0x00aa61bc`.
   - Open mode: **`pack+0x40 != 0` → 1**, else **3**.
   - `stat`: if ok and **`(st_mode >> 15) & 1`** (MSVC **`_S_IFREG`**):  
     - `FUN_007669d0` open **pack** (mode 1|3, flags `0x10000000`); fail → **−1**.  
     - Second open **`pack+0x14`** same mode.  
     - Else single open mode **6**.
   - On success: vcall **size** (`vtbl+0x1c`); size 0 → return **0**; size −1 → fail;  
     vcall **seek** (`+4`, `size-4`); vcall **read 4** (`+0x14`); **`FUN_0071a4a0`** parse.
4. **Classification:** **worker** (pack open + footer + parse handoff).
5. **Callers (1):** `FUN_00984ee0` @ `0x00984f66` — product **`assPackManager.cpp`** Opening/FAILED/SUCCESS pack file (W31-H dual).
6. **Callees:** `_strdup`, `FUN_0076b190`, `stat`, `FUN_007669d0`, vcalls, `FUN_0071a4a0`.
7. **Name:** `AssPackObject_OpenFromPath_Inferred` (Ghidra `FUN_0071a9d0`; **Inferred**; sole caller plate seals subsystem).
8. **Family:** nested open for `AssPackManager_OpenPackFile_Inferred`; file open helper is `stoFileOSFile` (`FUN_007669d0`, plate path in that callee).
9. **Decompile ≡ bytes** for path/glm/mode/dual-open/vcalls/RET4. Decompiler `void`/`unaff_*` corrected by sole-caller register ABI. Full 277 B hex in raw W37-X append.

### Gaps

- Product English for 0x44 pack class.  
- CreateFile access/disposition map for modes 1/3/6 (owned by `FUN_007669d0` / W37-E).  
- Full `FUN_0071a4a0` TOC contract + exact owner/footer arg binding.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0071a9d0_AssPackObject_OpenFromPath_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0071a9d0_AssPackObject_OpenFromPath_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0071a9d0_FUN_0071a9d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0071a9d0_FUN_0071a9d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackObject_OpenFromPath_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0071a9d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0071a9d0_FUN_0071a9d0.md` |
| Function named | `docs/reconstruction/functions/aa_0071a9d0_AssPackObject_OpenFromPath_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0073d940` | Port as **pure material-registry lookup** on host (usually `*DAT_00d1f61c`): ECX host + stack probe + RET 4. Return alternate or null. **Do not** put AddRef/Release inside this function — keep swap at FX/mesh init call sites. Pair with compatibility predicate `FUN_00752590`. |
| `0071a9d0` | Port as **pack open** with register ABI: EAX path, EDI 0x44 pack, stack AssPackManager\*. strdup @ +0x28, glm path normalize, mode from +0x40, regular-file dual-open into pack and pack+0x14, else mode-6 open, then size/seek/footer/`FUN_0071a4a0`. Treat empty size as success 0. |

Shared: co-owned only by W37-X partition assignment — **different subsystems** (gfx material registry vs ass pack I/O). No shared types.

**Terminal coverage:** false (both). No runtime/diff/bit-exact Confirmed.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + callee/caller decompile + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only (W37-X full hex).  
- No invented product names without evidence; `_Inferred` structural names; caller plate used for pack subsystem.  
- Corrected prior informal “refcount swap” attribution for `0073d940` to lookup-only.  
- Avoided bare `undefined4` as sole clean surface (`uint32_t` / explicit pointers).
