# Dual A/B report — W33-J OWN `aa_00469c50` + `aa_0043ec50`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-J  
**Scope:** VAs `0x00469c50`, `0x0043ec50` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `get_function_by_address` + `analyze_function_complete` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-J).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00469c50` StdVector_Elem28_Size | **accept** — ECX null-safe `(end-begin)/0x1c` size leaf sealed (33 B) |
| `aa_0043ec50` GuardedVector_RingAssignForward | **accept** — 7-arg plain-RET forward ring dword assign sealed (140 B) |

---

## VA `0x00469c50` — sealed facts

1. **Body:** `0x00469c50`–`0x00469c70` (**33 B** / `0x21`; pad `CC` then next ~`0x00469c80`).
2. **ABI:** **ECX=vec** (`__fastcall` / thiscall host); bare **`RET`**. Size in **EAX**.
3. **Semantics:** If begin `@+4` is null → `0`; else `(end@+8 − begin) / 0x1c`. Capacity not read. Division via signed magic `0x92492493` (MSVC ÷28).
4. **Classification:** leaf worker — multi-domain size helper for **elem stride 0x1c**.
5. **Callers (9):** `FUN_004306b0`, `FUN_004501d0`, `FUN_0045cd30`, `FUN_004617a0`, `FUN_00466ea0`, `FUN_00469f50`, `FUN_004a7ad0`, `FUN_0055be00`, `FUN_0068a1d0`.
6. **Name:** `StdVector_Elem28_Size` (Ghidra `FUN_00469c50`; **Inferred** structural; sibling of `StdVector_DwordSize` @ `0x004024b0`).
7. **Decompile ≡ raw CF**; **bytes win** on magic multiply detail. Full hex: raw W33-J append.

### Gaps

- Product/PDB host English (multi-domain).  
- Runtime / bit-exact.  
- Non-vector hosts sharing +4/+8 layout (caller-contract residual).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00469c50_StdVector_Elem28_Size.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00469c50_StdVector_Elem28_Size.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00469c50_FUN_00469c50.md` |
| Annotated | `docs/reconstruction/raw/aa_00469c50_FUN_00469c50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Elem28_Size.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469c50.cpp` |
| Function | `docs/reconstruction/functions/aa_00469c50_FUN_00469c50.md` |
| Function named | `docs/reconstruction/functions/aa_00469c50_StdVector_Elem28_Size.md` |
| Scratch | `docs/reconstruction/tmp/a_00469c50.md` |

---

## VA `0x0043ec50` — sealed facts

1. **Body:** `0x0043ec50`–`0x0043ecdc` (**140 B** / `0x8C`; pad `CC` then `FUN_0043ece0` W32-M).
2. **ABI:** **7 stack args** cdecl; plain **`RET`** (caller cleans **0x1C**). No register this.
3. **Semantics:** Forward ring dword assign: while `(src_cont,src_idx) != (end_cont,end_idx)`, map both indices through block map (`idx>>2`, wrap if `block >= capacity@+8`, lane via slots@+4), store if pointers differ, `++src`, `++dst`. Write `out_pair = {dst_cont, final_dst_idx}`.
4. **Classification:** leaf worker — thiscall insert family forward assign.
5. **Callers (4 / 7 sites):** `FUN_0043df90`, `FUN_0043e080` (`GuardedVector_InsertN_Thiscall`), `FUN_0044e1c0` (`GuardedVector_InsertRange`), `FUN_005441d0` (`GuardedVector_InsertRange_Thiscall`, 4 sites).
6. **Name:** `GuardedVector_RingAssignForward` (Ghidra `FUN_0043ec50`; **Inferred** structural; parent dual language “ring assign forward”). Older-family forward: `GuardedVector_RingCopyElements` (`0x0043d390`). Reverse twins: `FUN_0043ebb0` (thiscall family), `GuardedVector_RingAssignBackward` (`0x0043d300`).
7. **Decompile ≡ raw CF**; **bytes win** on plain RET + self-pointer skip. Full hex: raw W33-J append.

### Gaps

- Product/PDB class English.  
- Byte-level delta vs `0043d390` residual.  
- Twin reverse `0043ebb0` free (unowned).  
- Runtime / bit-exact on wrap edges.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043ec50_GuardedVector_RingAssignForward.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043ec50_GuardedVector_RingAssignForward.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ec50_FUN_0043ec50.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ec50_FUN_0043ec50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingAssignForward.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ec50.cpp` |
| Function | `docs/reconstruction/functions/aa_0043ec50_FUN_0043ec50.md` |
| Function named | `docs/reconstruction/functions/aa_0043ec50_GuardedVector_RingAssignForward.md` |
| Scratch | `docs/reconstruction/tmp/a_0043ec50.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00469c50` | Port as **elem-28 size**: **ECX=vec**, bare **RET**, `begin==0 ? 0 : (end-begin)/0x1c`. Do **not** use dword `SAR 2` (`004024b0`) for these hosts. |
| `0043ec50` | Port as **forward ring dword assign**: **7 stack args**, plain **RET** (caller cleans `0x1C`). Block map `>>2` + capacity wrap; skip self-pointer stores. Do **not** unify with reverse `0043ebb0` / `0043d300`. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004024b0` | `StdVector_DwordSize` — stride-4 sibling of `00469c50` |
| `0x0043d390` | `GuardedVector_RingCopyElements` — older-family forward |
| `0x0043d300` | `GuardedVector_RingAssignBackward` — older reverse |
| `0x0043ebb0` | thiscall-family reverse (unowned) |
| `0x0043e080` / `0x0044e1c0` / `0x005441d0` | insert parents calling forward assign |

Closes parent dual residuals naming `0043ec50` as nested free; seals size helper used by basic_string / 0x1c vector insert paths.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`StdVector_Elem28_*` / `GuardedVector_RingAssign*` family).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit POD structs).
