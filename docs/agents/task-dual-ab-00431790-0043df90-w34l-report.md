# Dual A/B report — W34-L OWN `aa_00431790` + `aa_0043df90`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-L  
**Scope:** VAs `0x00431790`, `0x0043df90` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-L).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00431790` BasicString_CopyBackward_0x1c | **accept** — cdecl reverse string assign + stride 0x1c + IAT operator= sealed (51 B) |
| `aa_0043df90` GuardedVector_EraseRange_Thiscall | **accept** — ECX thiscall + RET 0x14 + shorter-side erase CF sealed (238 B); callees dual-owned |

---

## VA `0x00431790` — sealed facts

1. **Body:** `0x00431790`–`0x004317c2` (**51 B** / `0x33`; pad `CC` then next).
2. **ABI:** **cdecl** stack **`(first*, last*, dest_end*)`**; plain **`RET`**; returns final **dest** in **EAX**.
3. **Semantics:** MSVC-style **`copy_backward`** on live `basic_string<char>` slots (elem **0x1c**):
   - Empty (`first == last`) → return `dest_end` (no stores).
   - Else walk `last`/`dest_end` backward by `0x1c` and `operator=` each pair until `last == first`.
   - Return final dest pointer.
4. **Classification:** worker leaf (IAT only).
5. **Callers (1):** `FUN_00431480` / `BasicString_CopyBackward_Thunk_0x1c` @ `0x00431494`.
6. **Callees:** IAT `basic_string::operator=` via `[0x009c63c4]` → `0x006ec244`.
7. **Name:** `BasicString_CopyBackward_0x1c` (Ghidra `FUN_00431790`; **Inferred** structural; closes W33-I nested free residual).
8. **Decompile ≡ bytes** for CF; full hex in raw W34-L append.

### Gaps

- Product/MSVC demangle English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00431790_BasicString_CopyBackward_0x1c.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00431790_BasicString_CopyBackward_0x1c.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00431790_FUN_00431790.md` |
| Annotated | `docs/reconstruction/raw/aa_00431790_FUN_00431790.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicString_CopyBackward_0x1c.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00431790.cpp` |
| Function | `docs/reconstruction/functions/aa_00431790_FUN_00431790.md` |
| Function named | `docs/reconstruction/functions/aa_00431790_BasicString_CopyBackward_0x1c.md` |

---

## VA `0x0043df90` — sealed facts

1. **Body:** `0x0043df90`–`0x0043e07d` (**238 B** / `0xEE`; pad `CC` then `FUN_0043e080` / InsertN_Thiscall).
2. **ABI:** **ECX=container** thiscall; stdcall **5** stack formals `(out, erase_from_c, erase_from_i, erase_to_c, erase_to_i)`; frame `SUB/ADD ESP,0x10`; **`RET 0x14`**.
3. **Semantics:** Erase absolute ring range `[erase_from, erase_to)`:
   - `prefix = from_i - begin`; `erase_cnt = to_i - from_i`; `suffix = (size+begin) - to_i`.
   - If `prefix < suffix` → `GuardedVector_RingAssignBackwardChecked` (`0043ebb0`) then advance `begin` (wrap at `capacity*4`) and shrink `size` per erased slot.
   - Else → `GuardedVector_RingAssignForward` (`0043ec50`) then size-only shrink (`begin=0` when emptied).
   - Write out-iterator `{this, begin+prefix}`.
4. **Layout:** `+0x08` capacity, `+0x0c` begin, `+0x10` size (same GuardedVector ring family; slots unused here).
5. **Classification:** worker — callees sealed W33-K / W33-J.
6. **Callers (5):** `FUN_0043d940` Resize_Thiscall @ `0x0043d97e`; `FUN_0043e630` @ `0x0043e69f`; `FUN_004ed310` @ `0x004ed3ba`; `FUN_00971820` @ `0x00971881`; `FUN_00971700` @ `0x00971756`.
7. **Name:** `GuardedVector_EraseRange_Thiscall` (Ghidra `FUN_0043df90`; **Inferred** structural; thiscall twin of W27-C `GuardedVector_EraseRange`; closes W33-L Resize shrink residual).
8. **Decompile ≡ bytes** for CF; **bytes win** on ECX/RET 0x14. Full hex in raw W34-L append.

### Gaps

- Product/PDB class English.  
- Runtime / bit-exact under wrap edges.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043df90_GuardedVector_EraseRange_Thiscall.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043df90_GuardedVector_EraseRange_Thiscall.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043df90_FUN_0043df90.md` |
| Annotated | `docs/reconstruction/raw/aa_0043df90_FUN_0043df90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_EraseRange_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043df90.cpp` |
| Function | `docs/reconstruction/functions/aa_0043df90_FUN_0043df90.md` |
| Function named | `docs/reconstruction/functions/aa_0043df90_GuardedVector_EraseRange_Thiscall.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00431790` | Port as **copy_backward** on `basic_string` (stride **0x1c**). cdecl 3-arg; reverse `operator=` walk; returns final dest. Mid-insert **must** reverse-walk (not forward). Do not substitute POD memmove. Closes nested free of W33-I thunk. |
| `0043df90` | Port as **thiscall erase-range**: **ECX=container**, stack `(out, from_c, from_i, to_c, to_i)`, **RET 0x14**. Shorter-prefix → reverse pack + begin advance/wrap; else forward pack + size-only shrink. Out `{c, begin+prefix}`. Do **not** mix with W27-C `GuardedVector_EraseRange` (**EAX** container + older callees `0043d300`/`0043d390`). |

Shared: both close high-mention nested residuals from prior duals (W33-I string insert chain; W33-L / W32-K / W33-M GuardedVector shrink/clear paths). No invented product plates — structural `_Inferred` names only.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only (raw rewritten with original body + W34-L append section).  
- No invented product names without evidence; reject scaffold `Named_CalleeOf_*` aliases.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
