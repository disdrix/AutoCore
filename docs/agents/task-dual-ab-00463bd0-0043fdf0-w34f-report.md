# Dual A/B report — W34-F OWN `aa_00463bd0` + `aa_0043fdf0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-F  
**Scope:** VAs `0x00463bd0`, `0x0043fdf0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + callee/caller decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-F).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00463bd0` NestedHash_Ctor_Sentinel0x30_Inferred | **accept-with-gaps** — ABI/layout/0x30-sentinel+9-buckets/flags + sole caller sealed; product English open |
| `aa_0043fdf0` NestedHash_Ctor_Sentinel0xC_Inferred | **accept-with-gaps** — ABI/layout/0x0C-sentinel+9-buckets/flags + 3 callers sealed; product English open |

---

## VA `0x00463bd0` — sealed facts

1. **Body:** `0x00463bd0`–`0x00463c31` (**98 B** / `0x62`; pad `CC` then next).
2. **ABI:** stack **`self*`** placement ctor; **`RET 0x4`**; returns **`self` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - `FUN_005b43b0()` circular sentinel `new(0x30)` → **`this+0x08`**.
   - Zero **`this+0x0c`**.
   - **`FUN_004646e0(this+0x10, 9, &sentinel)`** — 9-bucket pointer table filled with sentinel.
   - **`this+0x20 = 1`**, **`this+0x24 = 1`**.
4. **Size:** nested span **0x28** (sole caller `operator_new(0x28)`).
5. **Classification:** worker.
6. **Callers (1):** `FUN_0075f7f0` @ `0x0075fa63` — stores host `param_2[0x1d6]` / `DAT_00d1f628`.
7. **Callees:** `FUN_005b43b0`, `FUN_004646e0` (`PtrVecShell_InitFill_Inferred`, W33-B).
8. **Name:** `NestedHash_Ctor_Sentinel0x30_Inferred` (Ghidra `FUN_00463bd0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*`.
9. **Family:** 98 B twin of `AssResolverA_NestedHash_Ctor_Inferred` (`0x00423cf0`) / `FUN_00469db0` with sentinel node **0x30** instead of **0x28**.
10. **Decompile ≡ bytes** for stores and `RET 4`.  
    Full hex: `6aff681bd39b0064a100000000506489250000000051568b742418e8c007150089460833c089460c8d4c240451894424148b46086a098d56105289442410e8cd0a00008b4c2408b8010000008946208946248bc65e64890d0000000083c410c20400`

### Gaps

- Product/PDB type English for nested hash/map.  
- Unwritten `+0x00/+0x04`; meaning of flags `+0x20/+0x24`.  
- Host `FUN_0075f7f0` product role.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00463bd0_NestedHash_Ctor_Sentinel0x30_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00463bd0_NestedHash_Ctor_Sentinel0x30_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00463bd0_FUN_00463bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00463bd0_FUN_00463bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash_Ctor_Sentinel0x30_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00463bd0.cpp` |
| Function | `docs/reconstruction/functions/aa_00463bd0_FUN_00463bd0.md` |
| Function named | `docs/reconstruction/functions/aa_00463bd0_NestedHash_Ctor_Sentinel0x30_Inferred.md` |

---

## VA `0x0043fdf0` — sealed facts

1. **Body:** `0x0043fdf0`–`0x0043fe51` (**98 B** / `0x62`; pad `CC` then next).
2. **ABI:** stack **`self*`** placement ctor; **`RET 0x4`**; returns **`self` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - `FUN_004933f0()` / `StdList_AllocSentinel_0xC` → circular sentinel `new(0x0C)` → **`this+0x08`**.
   - Zero **`this+0x0c`**.
   - **`FUN_004646e0(this+0x10, 9, &sentinel)`** — 9-bucket pointer table filled with sentinel.
   - **`this+0x20 = 1`**, **`this+0x24 = 1`**.
4. **Size:** nested span **0x28** (writes through `+0x24`; family twin sealed).
5. **Classification:** worker.
6. **Callers (3):** `FUN_0074e380` @ `0x0074e3ba` (nested **+0x14** in 0x40 outer); `FUN_0096eec0` @ `0x0096eeea` (object base); `FUN_00996bc0` @ `0x00996c02` (nested **+0x28**).
7. **Callees:** `FUN_004933f0` (`StdList_AllocSentinel_0xC_Inferred`, W32-P), `FUN_004646e0` (`PtrVecShell_InitFill_Inferred`, W33-B).
8. **Name:** `NestedHash_Ctor_Sentinel0xC_Inferred` (Ghidra `FUN_0043fdf0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*`.
9. **Family:** 98 B twin of Ass NestedHash ctors with sentinel node **0x0C**; SEH plate `LAB_009bc89b` matches `FUN_00469db0`.
10. **Decompile ≡ bytes** for stores and `RET 4`.  
    Full hex: `6aff689bc89b0064a100000000506489250000000051568b742418e8e035050089460833c089460c8d4c240451894424148b46086a098d56105289442410e8ad4802008b4c2408b8010000008946208946248bc65e64890d0000000083c410c20400`

### Gaps

- Product/PDB type English across three hosts.  
- Unwritten `+0x00/+0x04`; meaning of flags `+0x20/+0x24`.  
- Sentinel-size policy across family (0x0C vs 0x28 vs 0x30).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043fdf0_NestedHash_Ctor_Sentinel0xC_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043fdf0_NestedHash_Ctor_Sentinel0xC_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043fdf0_FUN_0043fdf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043fdf0_FUN_0043fdf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash_Ctor_Sentinel0xC_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043fdf0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043fdf0_FUN_0043fdf0.md` |
| Function named | `docs/reconstruction/functions/aa_0043fdf0_NestedHash_Ctor_Sentinel0xC_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00463bd0` | Port as **placement ctor** (stack this, **RET 4**). Nested span **0x28**. Sentinel factory **`FUN_005b43b0` (node 0x30)** + 9-bucket fill + size0 + flags1. Sole host allocs 0x28. |
| `0043fdf0` | Same shell CF; sentinel factory **`StdList_AllocSentinel_0xC`**. Embed at host **+0x00 / +0x14 / +0x28** depending on outer. |
| Pair with | W32-D `AssResolverA_NestedHash_Ctor_Inferred` (sentinel 0x28); W33-B `PtrVecShell_InitFill_Inferred`; W32-P `StdList_AllocSentinel_0xC`; unowned `FUN_005b43b0` / `FUN_00469db0`. |

Shared: both are **98-byte** structural twins of the Ass NestedHash placement-ctor family. Difference is **only** the circular-sentinel node size (**0x30** vs **0x0C**). Do **not** invent ECX-thiscall, product plate names, or mix sentinel factories across twins.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + related decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`NestedHash_Ctor_Sentinel*` family from Ass twin + sealed InitFill/sentinel callees).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
