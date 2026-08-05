# Dual A/B report — W34-E OWN `aa_0043bdf0` + `aa_00457ac0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-E  
**Scope:** VAs `0x0043bdf0`, `0x00457ac0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-E).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043bdf0` NestedHash_Ctor_Sentinel0x14_Inferred | **accept-with-gaps** — ABI/layout/9-bucket/0x14 node/RET4 sealed; product English + flags + unwritten head open |
| `aa_00457ac0` NestedHash_Ctor_Sentinel0x10_Inferred | **accept-with-gaps** — ABI/layout/9-bucket/0x10 node/RET4 sealed; multi-caller product plates + flags open |

---

## VA `0x0043bdf0` — sealed facts

1. **Body:** `0x0043bdf0`–`0x0043be51` (**98 B** / `0x62`; pad `CC` then next).
2. **ABI:** stack **`this*`** placement ctor; **`RET 0x4`**; returns **`this` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - `FUN_0043c460()` circular sentinel `new(0x14)` → **`this+0x08`**.
   - Zero **`this+0x0c`**.
   - **`FUN_004646e0(this+0x10, 9, &sentinel)`** — 9-bucket pointer table filled with sentinel.
   - **`this+0x20 = 1`**, **`this+0x24 = 1`**.
4. **Size:** NestedHash span **0x28** (`+0x00`…`+0x27`); head dwords `+0x00/+0x04` unwritten.
5. **Classification:** worker.
6. **Callers (2):** `FUN_0075d470` @ `0x0075d499` (NDResourceCache host / `DAT_00d1f050`); `FUN_0074d750` @ `0x0074d797` (nested `self+0x34`).
7. **Callees:** `FUN_0043c460`, `FUN_004646e0` (`PtrVecShell_InitFill_Inferred`).
8. **Name:** `NestedHash_Ctor_Sentinel0x14_Inferred` (Ghidra `FUN_0043bdf0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*`.
9. **Family:** same CF as W32-D `AssResolverA_NestedHash_Ctor` / W32-E `AssResolverCore_HeadBag_Ctor` with node **0x14** (vs **0x28**). Twin: W34-E `0x00457ac0` (node **0x10**).
10. **Decompile ≡ bytes** for stores and `RET 4`.  
    Full hex: `6aff689bc89b0064a100000000506489250000000051568b742418e85006000089460833c089460c8d4c240451894424148b46086a098d56105289442410e8ad8802008b4c2408b8010000008946208946248bc65e64890d0000000083c410c20400`

### Gaps

- Product/PDB type English for NestedHash / flags.  
- Unwritten `+0x00/+0x04`.  
- Unowned callees’ full product contracts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043bdf0_FUN_0043bdf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043bdf0_FUN_0043bdf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash_Ctor_Sentinel0x14_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043bdf0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043bdf0_FUN_0043bdf0.md` |
| Function named | `docs/reconstruction/functions/aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md` |

---

## VA `0x00457ac0` — sealed facts

1. **Body:** `0x00457ac0`–`0x00457b21` (**98 B** / `0x62`; pad `CC` then sibling `FUN_00457b30`).
2. **ABI:** stack **`this*`** placement ctor; **`RET 0x4`**; returns **`this` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - `FUN_004397f0()` circular sentinel `new(0x10)` → **`this+0x08`**.
   - Zero **`this+0x0c`**.
   - **`FUN_004646e0(this+0x10, 9, &sentinel)`** — 9-bucket fill.
   - **`this+0x20 = 1`**, **`this+0x24 = 1`**.
4. **Size:** NestedHash span **0x28**; head dwords unwritten.
5. **Classification:** worker.
6. **Callers (5):** `FUN_00438c40`, `FUN_00438ca0`, `FUN_0044fee0` (once-flag statics); `FUN_0073c810` (heap `new(0x30)` host); `FUN_0098fef0` (stack-local, gfxDeviceIB path).
7. **Callees:** `FUN_004397f0`, `FUN_004646e0`.
8. **Name:** `NestedHash_Ctor_Sentinel0x10_Inferred` (Ghidra `FUN_00457ac0`; **Inferred**). **Reject** scaffold `Named_gfxDeviceIB_*`.
9. **Twin diff:** body byte-identical to `0043bdf0` except the two `E8` relative call targets (sentinel factory + InitFill).
10. **Decompile ≡ bytes** for stores and `RET 4`.  
    Full hex: `6aff689bc89b0064a100000000506489250000000051568b742418e8101dfeff89460833c089460c8d4c240451894424148b46086a098d56105289442410e8ddcb00008b4c2408b8010000008946208946248bc65e64890d0000000083c410c20400`

### Gaps

- Product English for each static/host.  
- Unwritten head dwords + flag meaning.  
- Unowned callees full contracts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00457ac0_NestedHash_Ctor_Sentinel0x10_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00457ac0_NestedHash_Ctor_Sentinel0x10_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00457ac0_FUN_00457ac0.md` |
| Annotated | `docs/reconstruction/raw/aa_00457ac0_FUN_00457ac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash_Ctor_Sentinel0x10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457ac0.cpp` |
| Function | `docs/reconstruction/functions/aa_00457ac0_FUN_00457ac0.md` |
| Function named | `docs/reconstruction/functions/aa_00457ac0_NestedHash_Ctor_Sentinel0x10_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043bdf0` | Port as **placement ctor** (stack this, RET 4). NestedHash span **0x28**. Sentinel node **0x14** + 9-bucket fill + size0 + flags1. Used as NDResourceCache head (`DAT_00d1f050`) and nested embed. Do **not** mix with Ass NestedHash node **0x28**. |
| `00457ac0` | Same ABI/layout as twin with node **0x10**. Reusable multi-caller bag — do not hard-wire gfxDeviceIB or a single static. Pair with W33-B `PtrVecShell_InitFill`. |
| Shared | Both SEH `LAB_009bc89b`; both call sealed `FUN_004646e0` with **count=9**. Family continuum: node sizes **0x10 / 0x14 / 0x28** share NestedHash shell layout. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (NestedHash family from W32-D/E + W33-B PtrVecShell).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
