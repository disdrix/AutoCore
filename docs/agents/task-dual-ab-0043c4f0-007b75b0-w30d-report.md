# Dual A/B report — W30-D OWN `aa_0043c4f0` + `aa_007b75b0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-D  
**Scope:** VAs `0x0043c4f0`, `0x007b75b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` + `analyze_function_complete` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md` (W30-D).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043c4f0` GuardedVector_PushBackLocked | **accept** — EDI/stack ABI + optional CS + nested PushBack fully sealed (94 B); product residual only |
| `aa_007b75b0` AssManager_InitPrecompileAndResolvers_Inferred | **accept-with-gaps** — RET 8 bootstrap CF + dual resolver insert sealed; nested helper free + product residual |

---

## VA `0x0043c4f0` — sealed facts

1. **Body:** `0x0043c4f0`–`0x0043c54d` (**94 B** / `0x5E`; pad `CC CC` then `FUN_0043c550` EraseFirstEqual).
2. **ABI:** **EDI=container**; stdcall **1** stack formal (`const uint32_t* value`); **`RET 0x4`**. Decompiler omits EDI (`unaff_EDI`).
3. **Semantics:** Optional CS wrapper around `GuardedVector_PushBack` (`FUN_0043c830`).  
   - If `container+0x2c != 0` → `EnterCriticalSection(container+0x14)`.  
   - `EAX = EDI`; call PushBack(value*).  
   - If locked → LeaveCS. SEH `LAB_009be0c8` (state −1→0 around push).
4. **Layout:** CS `+0x14`, lock-enable `char +0x2c` (family: AssignTo / Resize wrappers).
5. **Classification:** worker — callees EnterCS, `FUN_0043c830`, LeaveCS.
6. **Callers (1):** `FUN_007b75b0` @ `0x007b77ba` — `MOV EDI,[DAT_00d1f058]; ADD EDI,0x58` (resolver GuardedVector).
7. **Name:** `GuardedVector_PushBackLocked` (Ghidra `FUN_0043c4f0`; **Inferred** structural; nested PushBack sealed W29-B).
8. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `6aff68c8e09b0064a100000000506489250000000051807f2c00568d771489742404740756ff15bc619c008b442418508bc7c744241400000000e801030000807e1800740756ff15b8619c008b4c24085e64890d0000000083c410c20400`

### Gaps

- Product/PDB class English.  
- Runtime / bit-exact under contended CS.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043c4f0_GuardedVector_PushBackLocked.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043c4f0_GuardedVector_PushBackLocked.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c4f0_FUN_0043c4f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c4f0_FUN_0043c4f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBackLocked.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c4f0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043c4f0_FUN_0043c4f0.md` |
| Function named | `docs/reconstruction/functions/aa_0043c4f0_GuardedVector_PushBackLocked.md` |
| Scratch | `docs/reconstruction/tmp/a_0043c4f0.md` |

---

## VA `0x007b75b0` — sealed facts

1. **Body:** `0x007b75b0`–`0x007b7b6d` (**~1469 B** / `0x5BD`; pad `CC` after `RET 8`).
2. **ABI:** stdcall **2** formals `(AssManagerClientState* self, char mode)`; **`RET 0x8`**. Epilogue `ADD ESP,0x50; RET 8`.
3. **Semantics:** Client bootstrap:  
   - Ensure `"../effects"` then `"../effects/precompile"` (helpers + `CreateDirectoryA`); mkdir fail → log NDAssetManager.cpp:0x282 + path `"."`.  
   - Publish path to `*DAT_00d1f058+0xb4`; set `+0xd0=1`; `FUN_00969830` / `FUN_00754280` / `FUN_00989ef0(0)`.  
   - **Flag bit0 (`self+0x04`):** `new(0x4c)` + `FUN_00423be0` → `self+0x08`; find `FUN_0043e5b0` on **host+0x58**; miss → `GuardedVector_PushBackLocked`; hit → soft log assManager.cpp:0x26d `"Adding duplicate resolver"`; walk `DAT_00d1e570`..`0xd1e7a0` step `0x1c`.  
   - **Flag bit1:** `new(0x5c)` + vftable/`FUN_00983940` → `self+0x0c`; find same list; miss → **host** CS (`+0x84`/`+0x6c`) + raw `FUN_0043c830`; hit → `FUN_0076d1b0` may `ExitProcess(3)`; then `FUN_00984ee0(1)` ×5 (+28 more if `mode==0`).
4. **Classification:** worker — large fan-out (path FS, resolvers, effect batch).
5. **Callers (2):** `FUN_00948bd0` @ `0x00948c3f` (client init; mode=`1`); `FUN_0094a6a0` @ `0x0094aa2c`.
6. **Name:** `AssManager_InitPrecompileAndResolvers_Inferred` (Ghidra `FUN_007b75b0`; **Inferred** from plates + CF + resolver pair with W29 Remove/Release).
7. **Decompile ≡ bytes** for CF stages (live 2026-07-29 ≡ raw 2026-07-23). Entry/epilogue/call-site/string hex sealed via `read_memory`.

### Gaps

- Product/PDB method English.  
- Resolver class types (0x4c / 0x5c objects).  
- Nested free of `FUN_00984ee0`, path helpers, side-init callees (not OWN).  
- Runtime / bit-exact / live FS.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007b75b0_AssManager_InitPrecompileAndResolvers_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007b75b0_AssManager_InitPrecompileAndResolvers_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007b75b0_FUN_007b75b0.md` |
| Annotated | `docs/reconstruction/raw/aa_007b75b0_FUN_007b75b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_InitPrecompileAndResolvers_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007b75b0.cpp` |
| Legacy clean | `docs/reconstruction/reconstructed-exact/Named_assManager_007b75b0.cpp` |
| Function | `docs/reconstruction/functions/aa_007b75b0_FUN_007b75b0.md` |
| Function named | `docs/reconstruction/functions/aa_007b75b0_AssManager_InitPrecompileAndResolvers_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_007b75b0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043c4f0` | Locked push_back for GuardedVector: **EDI=container**, stack `value*`, **RET 4**. Optional CS at `+0x14` gated by `+0x2c`, then unlocked PushBack (W29-B EAX contract). Do not invent thiscall. Do not substitute host CS (`DAT+0x6c`) for this wrapper. |
| `007b75b0` | Client assManager bootstrap: ensure precompile dir, then flag-gated resolver A/B into **host+0x58**. **A** uses PushBackLocked; **B** uses host CS + raw PushBack — do not unify lock styles. Duplicates: A soft-log, B may hard-abort. Pair with `AssManager_ReleaseOwnedResolvers` for `self+0x08/+0x0c`. Mode gates extra `FUN_00984ee0` batch only on B path. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family; `AssManager_*` from plates + sibling duals W29-C/D).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
