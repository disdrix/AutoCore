# Dual A/B report — W35-B OWN `aa_0043c460` + `aa_0075d470`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-B  
**Scope:** VAs `0x0043c460`, `0x0075d470` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `get_function_by_address` + `analyze_function_complete` (+ callers/xrefs + outer caller decompile). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-B).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043c460` CircularSentinel_Alloc0x14_Inferred | **accept-with-gaps** — 0x14/links/EAX/26 B sealed; product payload English open |
| `aa_0075d470` NDResourceCache_Ctor_Inferred | **accept-with-gaps** — RET4/layout/DAT_00d1f050/embed+0x0c/tree/ensure sealed; product English + aux fields open |

---

## VA `0x0043c460` — sealed facts

1. **Body:** `0x0043c460`–`0x0043c479` (**26 B** / `0x1A`; pad `CC` then next factory-shaped body).
2. **ABI:** no formals; bare **`RET`** (`C3`); returns **node* in EAX**. Decompiler `void` is wrong.
3. **Semantics:** `operator_new(0x14)`; if non-null `next@+0 = self`; `prev@+4 = self` (MSVC `lea/test` gate); return node. Payload `+0x08..+0x13` unwritten.
4. **Classification:** wrapper / factory — sole callee `operator_new`.
5. **Callers (4):**  
   - `FUN_0043bdf0` @ `0x0043be0b` — NestedHash_Ctor_Sentinel0x14 (W34-E)  
   - `FUN_004642d0` @ `0x004642eb` — HeadBag_Ctor_Sentinel0x14 (W34-H)  
   - `FUN_005e2670` @ `0x005e26b4` — ad-hoc circular list head  
   - `FUN_007c77b0` @ `0x007c77fb` — ad-hoc circular list head (loot weights path)
6. **Name:** `CircularSentinel_Alloc0x14_Inferred` (Ghidra `FUN_0043c460`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*VOG_DEBUG*`.
7. **Family:** same 26 B CF as `CircularSentinel_Alloc0x28` (`0x00423d60`) / `StdList_AllocSentinel_0xC` (`0x004933f0`) with size **0x14**.
8. **Decompile ≡ bytes** for size/links/RET.  
   Full hex: `6a14e82bd4040083c40485c0740289008d480485c974028901c3`

### Gaps

- Product payload English for remaining 0x0C node bytes.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043c460_CircularSentinel_Alloc0x14_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043c460_CircularSentinel_Alloc0x14_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c460_FUN_0043c460.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c460_FUN_0043c460.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CircularSentinel_Alloc0x14_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c460.cpp` |
| Function | `docs/reconstruction/functions/aa_0043c460_FUN_0043c460.md` |
| Function named | `docs/reconstruction/functions/aa_0043c460_CircularSentinel_Alloc0x14_Inferred.md` |

---

## VA `0x0075d470` — sealed facts

1. **Body:** `0x0075d470`–`0x0075d506` (**151 B** / `0x97`; pad `CC` after `RET 4`). SEH `LAB_009acd33`.
2. **ABI:** stack **`self*`** placement ctor; **`RET 0x4`**; returns **`self` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - Publish **`DAT_00d1f050 = self`**.
   - **`FUN_0043bdf0(self)`** — NestedHash_Ctor_Sentinel0x14 @ **+0** (uses this dual’s peer `FUN_0043c460`).
   - Zero **`+0x2c..+0x38`**.
   - **`InitializeCriticalSection(self+0x3c)`**; **`*(u8*)(self+0x54) = 1`** (byte after 0x18 CS).
   - **`FUN_005ae2b0()`** → **`self+0x5c`** tree head; isnil `@+0x19=1`; L/P/R self; **`self+0x60 = 0`**.
   - Zero **`+0x64`**, **`+0x68`**, **`+0x6c`**; **`FUN_0075d3c0(self)`** EnsureAssPreloader (W33-O).
4. **Size:** host span ≥ **0x70**; NestedHash span 0x28 at head; unwritten gap `+0x28..+0x2b`.
5. **Classification:** worker / placement ctor.
6. **Callers (1):** `FUN_007543b0` @ `0x00754425` — AssManager client ctor (`DAT_00d1f058 = outer`); **`FUN_0075d470(outer+0x0c)`**.
7. **Callees:** `FUN_0043bdf0`, `InitializeCriticalSection`, `FUN_005ae2b0`, `FUN_0075d3c0`.
8. **Name:** `NDResourceCache_Ctor_Inferred` (Ghidra `FUN_0075d470`; **Inferred** from DAT plate + layout + embed). **Reject** scaffold `Named_CalleeOf_*Client_InitI*`.
9. **Decompile ≡ bytes** for stores and `RET 4`. Full 151 B hex in raw W35-B append.

### Gaps

- Product/PDB host English.  
- Aux field meaning `+0x2c..+0x38`, `+0x64`, `+0x68`.  
- Nested free of NestedHash/tree/preloader product contracts (dualed separately).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075d470_NDResourceCache_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0075d470_NDResourceCache_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075d470_FUN_0075d470.md` |
| Annotated | `docs/reconstruction/raw/aa_0075d470_FUN_0075d470.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResourceCache_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075d470.cpp` |
| Function | `docs/reconstruction/functions/aa_0075d470_FUN_0075d470.md` |
| Function named | `docs/reconstruction/functions/aa_0075d470_NDResourceCache_Ctor_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043c460` | Free-function factory: **`new(0x14)`**, circular next/prev, **EAX** return. Family twin of 0xC/0x28 sentinel allocs — do **not** unify sizes. Used by NestedHash/HeadBag 0x14 bags and ad-hoc lists. |
| `0075d470` | Placement ctor for **DAT_00d1f050** host (stack this, RET 4). Order: NestedHash → aux zeros → CS+flag → tree head → ensure preloader. Embed at **AssManager+0x0c**; do **not** treat as `DAT_00d1f058` outer. Pair with W34-E NestedHash, W16-G tree node, W33-O EnsureAssPreloader. |

### Lifecycle (relative)

```
FUN_007543b0  AssManager client ctor
  DAT_00d1f058 = outer
  NDResourceCache_Ctor(outer+0x0c)     // this dual 0075d470
    DAT_00d1f050 = embed
    NestedHash_Ctor (uses CircularSentinel_Alloc0x14)  // peer 0043c460
    CS + tree + EnsureAssPreloader
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`CircularSentinel_Alloc0x14`; `NDResourceCache_Ctor` from DAT + dual family).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).
