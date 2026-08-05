# Dual A/B report — W33-L OWN `aa_0043d940` + `aa_0044e4f0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-L  
**Scope:** VAs `0x0043d940`, `0x0044e4f0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-L).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043d940` GuardedVector_Resize_Thiscall | **accept** — ECX thiscall + stack (new_size, fill) + RET 8 + grow/shrink trichotomy sealed (74 B) |
| `aa_0044e4f0` GuardedVector_AssignLinearRangeAt | **accept** — cdecl leaf linear→ring assign + page map + out iter sealed (100 B); 6th residual only |

---

## VA `0x0043d940` — sealed facts

1. **Body:** `0x0043d940`–`0x0043d989` (**74 B** / `0x4A`; pad `CC` then next).
2. **ABI:** **ECX=container** (`MOV ESI,[ECX+0x10]`); stack **`(new_size, fill)`**; **`RET 0x8`**. Decompiler omits fill formal — **bytes win**.
3. **Semantics:** Resize ring to absolute `new_size`:
   - Grow (`size < n`): `GuardedVector_InsertN_Thiscall` (`0043e080`) at `insert_at = begin+size`, `N = n-size`, fill* → stack fill slot.
   - Shrink (`n < size`): `FUN_0043df90` erase `[begin+n, begin+size)`.
   - Equal: no-op.
4. **Layout:** `+0x0c` begin, `+0x10` size (family pages/capacity unused in this unit).
5. **Classification:** worker — callees InsertN_Thiscall + erase helper.
6. **Callers (1):** `FUN_0043d650` — seeds fill=`0`, passes new_size; ECX preserved.
7. **Name:** `GuardedVector_Resize_Thiscall` (Ghidra `FUN_0043d940`; **Inferred** structural; thiscall twin of W28-D `GuardedVector_Resize`).
8. **Decompile ≡ bytes** for trichotomy CF; **bytes win** on fill/RET 8.  
   Full hex: `8b44240483ec08568b71103bc6761d8b510c578d7c2418572bc65003d65251e81c0700005f5e83c408c2080073158b510c03f2565103d052518d44241450e80d0600005e83c408c20800`

### Gaps

- Product/PDB English.  
- Nested `FUN_0043df90` free (thiscall erase twin of W27-C EraseRange).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043d940_GuardedVector_Resize_Thiscall.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043d940_GuardedVector_Resize_Thiscall.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d940_FUN_0043d940.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d940_FUN_0043d940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_Resize_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d940.cpp` |
| Function | `docs/reconstruction/functions/aa_0043d940_FUN_0043d940.md` |
| Function named | `docs/reconstruction/functions/aa_0043d940_GuardedVector_Resize_Thiscall.md` |

---

## VA `0x0044e4f0` — sealed facts

1. **Body:** `0x0044e4f0`–`0x0044e553` (**100 B** / `0x64`; pad `CC` then next).
2. **ABI:** cdecl **5** live stack formals; plain **`RET`**. Sole parent cleans **`ADD ESP,0x18`** (6 dwords) — 6th formal residual unread.
3. **Semantics:** Linear→ring dword assign starting at absolute `dest_idx`:
   - `page = idx>>2`; if `capacity <= page` then `page -= capacity`; `sub = idx - page*4` (≡ `idx&3`).
   - `slot = pages[page] + sub`; if `slot != src` then `*slot = *src`.
   - Publish out iterator `{container, end_idx}`.
4. **Layout:** `+0x04` pages, `+0x08` capacity (family begin/size unused here).
5. **Classification:** leaf — no callees.
6. **Callers (1×3):** `FUN_0044e1c0` / `GuardedVector_InsertRange` @ `0x0044e2b0`, `0x0044e409`, `0x0044e4d4`.
7. **Name:** `GuardedVector_AssignLinearRangeAt` (Ghidra `FUN_0044e4f0`; **Inferred** structural; closes W32-G assign residual).
8. **Decompile ≡ bytes** for full loop CF (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `8b44240c558b6c2414568b7424103bf0578b7c2420744053eb068d9b000000008bcfc1e9028d148d000000008bda8bd72bd38b5d083bd977022bcb8b5d048b0c8b8d0c913bce74048b16891183c60483c7013bf075ca5b8b4424108978045f5e89285dc3`

### Gaps

- Product/PDB English.  
- Exact product role of 6th stack formal (ABI present at call sites; body unread).  
- Runtime / bit-exact under self-overlap.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044e4f0_GuardedVector_AssignLinearRangeAt.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0044e4f0_GuardedVector_AssignLinearRangeAt.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0044e4f0_FUN_0044e4f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044e4f0_FUN_0044e4f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_AssignLinearRangeAt.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044e4f0.cpp` |
| Function | `docs/reconstruction/functions/aa_0044e4f0_FUN_0044e4f0.md` |
| Function named | `docs/reconstruction/functions/aa_0044e4f0_GuardedVector_AssignLinearRangeAt.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043d940` | Thiscall resize: **ECX=container**, stack `(new_size, fill)`, **RET 8**. Grow uses sealed `GuardedVector_InsertN_Thiscall` end-insert; shrink uses unowned `FUN_0043df90`. Do **not** mix with W28-D `GuardedVector_Resize` (EAX/ECX register ABI + plain RET + internal fill0). |
| `0044e4f0` | InsertRange assign leaf: **cdecl** linear→ring dword copy at abs index; page map `>>2` + wrap; self-assign skip; out `{c, end_idx}`. Closes W32-G nested assign residual. Do not invent thiscall, ring-source walk, or size mutation. |

Shared: both sit on the thiscall GuardedVector ring family (`+0x04/+0x08/+0x0c/+0x10`) sealed across W28–W32. Together they complete the resize-grow chain (Resize_Thiscall → InsertN_Thiscall) and the InsertRange assign fallthrough.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family from parent duals W28-D Resize / W32-F InsertN_Thiscall / W32-G InsertRange).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit header structs).
