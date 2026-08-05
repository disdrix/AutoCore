# Dual A/B report — W28-C OWN `aa_0043d300` + `aa_0043c550`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-C  
**Scope:** VAs `0x0043d300`, `0x0043c550` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` only. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave28

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043d300` GuardedVector_RingAssignBackward | **accept** — leaf reverse ring dword assign; 7-arg plain RET + capacity wrap fully sealed (body 142 B) |
| `aa_0043c550` GuardedVector_EraseFirstEqual | **accept-with-gaps** — ESI/stdcall-1 ABI + optional CS + first-equal erase via EraseRange sealed; element-type residual |

---

## VA `0x0043d300` — sealed facts

1. **Body:** `0x0043d300`–`0x0043d38d` (**142 B** / `0x8E`; pad `CC`; next `FUN_0043d390`).
2. **ABI:** stdcall-like formals but **plain `RET`** (caller cleans **7×4**); no register this.
3. **Semantics:** Reverse ring element-assign:  
   - While `(src_container, src_index) != (stop_container, stop_index)`:  
     `--src_index`, `--dst_index`, map each through `block=idx>>2` with wrap when `block >= capacity`, dword `*dst = *src`.  
   - Return out-iterator `{dst_container, final_dst_index}` via `param_1`.
4. **Layout used:** `+0x04` slots, `+0x08` capacity (does **not** touch begin/size).
5. **Classification:** leaf worker — **no callees**. Sibling forward walker: unowned `FUN_0043d390`.
6. **Callers (3):** `FUN_0043c8c0` / `GuardedVector_EraseRange` (shorter-prefix arm @ `0x0043c91e`), `FUN_0043cb00`, `FUN_0043cf40`.
7. **Name:** `GuardedVector_RingAssignBackward` (Ghidra `FUN_0043d300`; **Inferred** structural).
8. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product/PDB class English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043d300_GuardedVector_RingAssignBackward.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043d300_GuardedVector_RingAssignBackward.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d300_FUN_0043d300.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d300_FUN_0043d300.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingAssignBackward.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d300.cpp` |
| Function | `docs/reconstruction/functions/aa_0043d300_FUN_0043d300.md` |
| Function named | `docs/reconstruction/functions/aa_0043d300_GuardedVector_RingAssignBackward.md` |
| Scratch | `docs/reconstruction/tmp/a_0043d300.md` |

---

## VA `0x0043c550` — sealed facts

1. **Body:** `0x0043c550`–`0x0043c5e1` (**146 B** / `0x92`; pad `CC`; next `FUN_0043c5f0` / `GuardedVector_AssignTo`).
2. **ABI:** **ESI=container** (caller-established); stdcall **1** stack formal (`int* key`); frame `SUB/ADD ESP,0x0C`; **`RET 4`**; return **AL** bool.
3. **Semantics:** Optional-CS first-equal erase:  
   - Gate `char +0x2c` → `Enter/LeaveCriticalSection(+0x14)`.  
   - Scan `[begin, begin+size)` with family ring block map.  
   - On first `elem == *key` → `GuardedVector_EraseRange([idx, idx+1))` with **EAX=ESI**; found=1; exit.  
   - Return found.
4. **Layout:** `+0x04` slots, `+0x08` capacity, `+0x0c` begin, `+0x10` size, `+0x14` CS, `+0x2c` lock-enable (same family as AssignTo/EraseRange).
5. **Classification:** worker — callees CS IAT + `FUN_0043c8c0`.
6. **Callers (2):** `FUN_00423e00` (assManager remove; `MOV ESI,ECX; ADD ESI,0x58`), `FUN_007b65d0` — both `assManager.cpp` resolver paths.
7. **Name:** `GuardedVector_EraseFirstEqual` (Ghidra `FUN_0043c550`; **Inferred** structural).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23; ESI sealed via caller bytes).

### Gaps

- Product/PDB class English; element type beyond dword equality.  
- Nested EraseRange free owned by W27-C (not this body).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043c550_GuardedVector_EraseFirstEqual.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043c550_GuardedVector_EraseFirstEqual.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c550_FUN_0043c550.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c550_FUN_0043c550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_EraseFirstEqual.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c550.cpp` |
| Function | `docs/reconstruction/functions/aa_0043c550_FUN_0043c550.md` |
| Function named | `docs/reconstruction/functions/aa_0043c550_GuardedVector_EraseFirstEqual.md` |
| Scratch | `docs/reconstruction/tmp/a_0043c550.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043d300` | Erase shorter-prefix / assign packing must reverse-assign dwords through capacity-wrapped blocks — not a flat `memmove`. Closes nested reverse-move residual called out by W27-C `GuardedVector_EraseRange`. |
| `0043c550` | Resolver/list remove-by-value: optional CS, linear first match, single-slot EraseRange. Callers pass container in **ESI** (e.g. object+`0x58`). Do not invent erase-all or ECX-this without the ESI setup. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` only. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals W25-R / W26-G / W27-C).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
