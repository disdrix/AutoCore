# Dual A/B report — W34-G OWN `aa_004438c0` + `aa_00457b30`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-G  
**Scope:** VAs `0x004438c0`, `0x00457b30` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-G).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004438c0` NestedHashBag_Ctor_Sentinel0x30_Inferred | **accept-with-gaps** — stack this*/RET4/0x30-sentinel+9-bucket fill+flags sealed; host product English open |
| `aa_00457b30` NestedHashBag_Ctor_Sentinel0x18_Inferred | **accept-with-gaps** — stack this*/RET4/0x18-sentinel+9-bucket fill+flags sealed; host product English open |

---

## VA `0x004438c0` — sealed facts

1. **Body:** `0x004438c0`–`0x00443921` (**98 B** / `0x62`; pad `CC` then next @ `0x00443930`).
2. **ABI:** stack **`this*`** placement ctor; **`RET 0x4`**; returns **`this` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - SEH `LAB_009bed5b`.
   - `FUN_005b43b0()` circular sentinel `new(0x30)` → **`this+0x08`**.
   - Zero **`this+0x0c`**.
   - **`FUN_004646e0(this+0x10, 9, &sentinel)`** — 9-bucket pointer table filled with sentinel.
   - **`this+0x20 = 1`**, **`this+0x24 = 1`**.
4. **Size:** core bag span **0x28** (unwritten `+0x00/+0x04`).
5. **Classification:** worker.
6. **Callers (1):** `FUN_00754ee0` @ `0x00754f3e` — nested at **host +0x44**.
7. **Callees:** `FUN_005b43b0`, `FUN_004646e0` (`PtrVecShell_InitFill_Inferred`, W33-B).
8. **Name:** `NestedHashBag_Ctor_Sentinel0x30_Inferred` (Ghidra `FUN_004438c0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*_gfxFont_*`.
9. **Decompile ≡ raw CF**; **bytes win** on ABI (`RET 4`, stack this*). Full hex: raw W34-G append.

### Gaps

- Product/PDB English for host (`FUN_00754ee0` / vtbl `00a9f584`).  
- Flag meaning `+0x20/+0x24`; unwritten head dwords.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004438c0_NestedHashBag_Ctor_Sentinel0x30_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004438c0_NestedHashBag_Ctor_Sentinel0x30_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004438c0_FUN_004438c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004438c0_FUN_004438c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHashBag_Ctor_Sentinel0x30_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004438c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004438c0_FUN_004438c0.md` |
| Function named | `docs/reconstruction/functions/aa_004438c0_NestedHashBag_Ctor_Sentinel0x30_Inferred.md` |

---

## VA `0x00457b30` — sealed facts

1. **Body:** `0x00457b30`–`0x00457b91` (**98 B** / `0x62`; pad `CC` then next @ `0x00457ba0`).
2. **ABI:** stack **`this*`** placement ctor; **`RET 0x4`**; returns **`this` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - SEH `LAB_009bc89b` (same label family as AssResolverCore HeadBag ctor).
   - `FUN_00457c60()` circular sentinel `new(0x18)` → **`this+0x08`** (W30-E sealed).
   - Zero **`this+0x0c`**.
   - **`FUN_004646e0(this+0x10, 9, &sentinel)`** — 9-bucket pointer table filled with sentinel.
   - **`this+0x20 = 1`**, **`this+0x24 = 1`**.
4. **Size:** core bag **0x28** written here; sole host alloc **0x40** with caller-zeroed **+0x28..+0x3e**.
5. **Classification:** worker.
6. **Callers (1):** `FUN_0073c810` @ `0x0073cae5`.
7. **Callees:** `FUN_00457c60` (`StdList_AllocSentinel_0x18_Inferred`), `FUN_004646e0`.
8. **Name:** `NestedHashBag_Ctor_Sentinel0x18_Inferred` (Ghidra `FUN_00457b30`; **Inferred**).
9. **Decompile ≡ raw CF**; **bytes win** on ABI. Full hex: raw W34-G append.

### Gaps

- Product English for bootstrap host `FUN_0073c810`.  
- Flag meaning; unwritten `+0x00/+0x04`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00457b30_NestedHashBag_Ctor_Sentinel0x18_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00457b30_NestedHashBag_Ctor_Sentinel0x18_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00457b30_FUN_00457b30.md` |
| Annotated | `docs/reconstruction/raw/aa_00457b30_FUN_00457b30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHashBag_Ctor_Sentinel0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457b30.cpp` |
| Function | `docs/reconstruction/functions/aa_00457b30_FUN_00457b30.md` |
| Function named | `docs/reconstruction/functions/aa_00457b30_NestedHashBag_Ctor_Sentinel0x18_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004438c0` | Port as **placement ctor** (stack this, RET 4). Sentinel via **`FUN_005b43b0` (0x30)**, not Ass `FUN_00423d60` (0x28). Bag: +8 head, +0xc size0, +0x10 nine-slot fill, flags1. Host embeds at **+0x44**. |
| `00457b30` | Port as **placement ctor** (stack this, RET 4). Sentinel via **`FUN_00457c60` (0x18)**. Same bag layout. Host **`new(0x40)`** then zero **+0x28..** after return. |
| Pair with | W32-D `AssResolverA_NestedHash_Ctor`; W32-E `AssResolverCore_HeadBag_Ctor`; W33-B `PtrVecShell_InitFill`; W30-E `StdList_AllocSentinel_0x18`; W34-E sibling `FUN_00457ac0` (other sentinel factory). |

Shared family contrast (do **not** collapse):

| Unit | Sentinel factory | Node size | SEH |
|------|------------------|-----------|-----|
| `00423cf0` NestedHash (Ass A) | `00423d60` | 0x28 | `009bcd6b` |
| `00469db0` HeadBag (Ass Core) | `00423d60` | 0x28 | `009bc89b` |
| **`004438c0`** | **`005b43b0`** | **0x30** | **`009bed5b`** |
| **`00457b30`** | **`00457c60`** | **0x18** | **`009bc89b`** |
| `00457ac0` (not owned) | `004397f0` | other | `009bc89b` |

All share: stack this*, RET 4, +8 sentinel, +0xc=0, `FUN_004646e0(+0x10, 9, &fill)`, +0x20/+0x24 = 1.

Closes high-mention NestedHash bag twins under W34-G; residual product English on non-Ass hosts only.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`NestedHashBag_*` family from W32 Ass duals + sentinel size differentiator).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
