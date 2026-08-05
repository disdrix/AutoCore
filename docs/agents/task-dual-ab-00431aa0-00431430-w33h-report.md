# Dual A/B report — W33-H OWN `aa_00431aa0` + `aa_00431430`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-H  
**Scope:** VAs `0x00431aa0`, `0x00431430` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-H).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00431aa0` StdVector_DestroyRange_BasicString | **accept-with-gaps** — destroy-range ABI/CF/0x1c/IAT dtor sealed; product demangle open |
| `aa_00431430` StdVector_UninitializedCopy_BasicString | **accept-with-gaps** — thin Ucopy rebind ABI/RET0C/EAX return sealed; core `FUN_0046a2c0` + product demangle residual |

---

## VA `0x00431aa0` — sealed facts

1. **Body:** `0x00431aa0`–`0x00431ac2` exclusive (**34 B** / `0x22`; pad `CC`).
2. **ABI:** stack **`first*`**, **`last*`**; **`RET 0x08`** (`C2 08 00`); void.
3. **Semantics:** MSVC-style **destroy-range** over `basic_string` storage:
   - Loop `[first, last)` with stride **`0x1c`**.
   - Each elem: IAT **`~basic_string`** via `[0x009c62f4]` → `0x006eace6`.
   - Does **not** free the buffer (parent insert grow calls `operator_delete` after).
4. **Classification:** worker.
5. **Callers:** `FUN_004306b0` / `StdVector_InsertN_BasicString` @ `0x0043084d`; Catch@`0x00430888`; Catch@`0x00430956`.
6. **Callees:** IAT `~basic_string`.
7. **Name:** `StdVector_DestroyRange_BasicString` (Ghidra `FUN_00431aa0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_Named_*`.
8. **Decompile ≡ bytes** for CF/stride/RET.  
   Full hex: raw W33-H append (34 B).

### Gaps

- Product/MSVC demangle (`_Destroy_range` English).  
- IAT dtor full symbol plate.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00431aa0_StdVector_DestroyRange_BasicString.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00431aa0_StdVector_DestroyRange_BasicString.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00431aa0_FUN_00431aa0.md` |
| Annotated | `docs/reconstruction/raw/aa_00431aa0_FUN_00431aa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DestroyRange_BasicString.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00431aa0.cpp` |
| Function | `docs/reconstruction/functions/aa_00431aa0_FUN_00431aa0.md` |
| Function named | `docs/reconstruction/functions/aa_00431aa0_StdVector_DestroyRange_BasicString.md` |
| Scratch | `docs/reconstruction/tmp/a_00431aa0.md` |

---

## VA `0x00431430` — sealed facts

1. **Body:** `0x00431430`–`0x00431450` exclusive (**32 B** / `0x20`); next `FUN_00431450`.
2. **ABI:** **ECX=`vector*`**; stack **`first*`**, **`last*`**, **`dest*`**; **`RET 0x0C`** (`C2 0C 00`).
3. **Return:** **EAX** = end of constructed dest range (propagated from `FUN_0046a2c0`). Decompiler shows `void` — **use-site + bytes win**.
4. **Semantics:** thin **thiscall rebind** of MSVC-style **uninitialized copy** / `_Ucopy` for `basic_string` (stride 0x1c):
   - Entire body: shuffle → `FUN_0046a2c0(first, last, dest, this, dest)` → `ADD ESP,0x14` → `RET 0x0C`.
   - Core placement copy-ctors live in callee (not owned).
5. **Classification:** wrapper.
6. **Callers:** `FUN_004306b0` / `StdVector_InsertN_BasicString` @ `0x004308e2`, `0x00430976` only (in-place arms). Grow path calls `FUN_0046a2c0` directly.
7. **Callees:** `FUN_0046a2c0`.
8. **Name:** `StdVector_UninitializedCopy_BasicString` (Ghidra `FUN_00431430`; **Inferred** structural). Reject scaffold `Named_CalleeOf_Named_*`.
9. **Decompile ≡ forward CF**; return-type corrected by insert use-site.  
   Full hex: raw W33-H append (32 B).

### Gaps

- Product/MSVC demangle (`_Ucopy` / `_Umove`).  
- Nested `FUN_0046a2c0` product English (not owned).  
- Residual 4th/5th forwarded args.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00431430_StdVector_UninitializedCopy_BasicString.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00431430_StdVector_UninitializedCopy_BasicString.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00431430_FUN_00431430.md` |
| Annotated | `docs/reconstruction/raw/aa_00431430_FUN_00431430.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_BasicString.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00431430.cpp` |
| Function | `docs/reconstruction/functions/aa_00431430_FUN_00431430.md` |
| Function named | `docs/reconstruction/functions/aa_00431430_StdVector_UninitializedCopy_BasicString.md` |
| Scratch | `docs/reconstruction/tmp/a_00431430.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00431aa0` | Port as **destroy `[first,last)` of `basic_string`** stride **0x1c**. **Do not** free the buffer here. **`RET 0x08`**. Call after grow relocate, before `operator_delete(old)`. |
| `00431430` | Port as **thiscall Ucopy rebind**: `dest_end = Ucopy(vec, first, last, dest)`. Honor **EAX return** and **`RET 0x0C`**. In-place insert only; grow may call core Ucopy (`FUN_0046a2c0`) directly. |
| Pair with | `StdVector_InsertN_BasicString` (`0x004306b0`, W32-B); siblings `FUN_00431450` (assign-fill), `FUN_00431480` (copy-backward family); core `FUN_0046a2c0` (unowned); fill-n `FUN_00430390` (unowned). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural **Inferred** names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Closes W32-B residual nested helpers `FUN_00431aa0` + `FUN_00431430` named in insert-n dual.
