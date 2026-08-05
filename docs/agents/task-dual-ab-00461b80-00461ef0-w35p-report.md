# Dual A/B report — W35-P OWN `aa_00461b80` + `aa_00461ef0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-P  
**Scope:** VAs `0x00461b80`, `0x00461ef0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-P).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00461b80` RcElem28_AssignFillRange | **accept-with-gaps** — EAX=dest_first / EDI=value / stack dest_last / plain RET / 125 B / RC@+0x10 sealed; product English open |
| `aa_00461ef0` RcElem28_AssignBackward | **accept-with-gaps** — EAX=dest_end / stack first+last / returns dest / 138 B / reverse RC assign sealed; product + parent bound math open |

---

## VA `0x00461b80` — sealed facts

1. **Body:** `0x00461b80`–`0x00461bfd` exclusive (**125 B** / `0x7D`; pad `CC`×3 then `00461c00`).
2. **ABI:** **EAX=dest_first\***, **EDI=value\*** (fixed source), stack **dest_last\***, plain **`RET`** (`C3`).
3. **Semantics:** MSVC-style **range fill by assign** on live **RcElem28** (stride **0x1c**):
   - Copy dwords +0x00..+0x0C; AddRef source resource `@+0x10` (vtbl+4 if refcount becomes 1); Release dest resource (vtbl+8 if 0); store; copy +0x14..+0x16 and +0x18.
   - Empty range no-op. **Not** uninit-fill (`FUN_00461c90`).
4. **Classification:** leaf.
5. **Callers (1 func / 2 sites):** `FUN_004617a0` @ `0x00461a2a` (hole), `0x00461a89` (mid fill).
6. **Name:** `RcElem28_AssignFillRange` (Ghidra `FUN_00461b80`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
7. **Decompile ≡ bytes** for CF/RC; **bytes win** on EAX/EDI live-in formals.  
   Full hex: raw W35-P append (125 B).

### Gaps

- Product/PDB T English (gfx residual only).  
- Exact AddRef-when-becomes-1 semantics residual (shared with W34-P family).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00461b80_RcElem28_AssignFillRange.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00461b80_RcElem28_AssignFillRange.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00461b80_FUN_00461b80.md` |
| Annotated | `docs/reconstruction/raw/aa_00461b80_FUN_00461b80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_AssignFillRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00461b80.cpp` |
| Function | `docs/reconstruction/functions/aa_00461b80_FUN_00461b80.md` |
| Function named | `docs/reconstruction/functions/aa_00461b80_RcElem28_AssignFillRange.md` |

---

## VA `0x00461ef0` — sealed facts

1. **Body:** `0x00461ef0`–`0x00461f7a` exclusive (**138 B** / `0x8A`; pad `CC`×6 then `00461f80`).
2. **ABI:** **EAX=dest_end\***, stack **(first\*, last\*)**, plain **`RET`**, returns final dest\* in **EAX**.
3. **Semantics:** MSVC-style **assign-backward / copy_backward** on live **RcElem28**:
   - Walk `[first, last)` onto `[dest_end−n, dest_end)` reverse with same RC assign as fill helper.
   - Empty `first==last` returns dest_end. Mid-insert overlap-safe shift only.
4. **Classification:** leaf.
5. **Callers (1):** `FUN_004617a0` @ `0x00461a7c` (mid path).
6. **Name:** `RcElem28_AssignBackward` (Ghidra `FUN_00461ef0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
7. **Decompile ≡ bytes** for reverse CF/return; **bytes win** on EAX=dest_end (decompiler 3-arg call site = 2 stack + EAX).  
   Full hex: raw W35-P append (138 B).

### Gaps

- Product/PDB class English.  
- Parent mid-path exact `last` / dest_end arithmetic (parent not dual-owned here).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00461ef0_RcElem28_AssignBackward.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00461ef0_RcElem28_AssignBackward.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00461ef0_FUN_00461ef0.md` |
| Annotated | `docs/reconstruction/raw/aa_00461ef0_FUN_00461ef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_AssignBackward.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00461ef0.cpp` |
| Function | `docs/reconstruction/functions/aa_00461ef0_FUN_00461ef0.md` |
| Function named | `docs/reconstruction/functions/aa_00461ef0_RcElem28_AssignBackward.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00461b80` | Port as **RC fill-assign** stride **0x1c**: **EAX=dest_first**, **EDI=value\***, stack **dest_last**, plain RET. Honor AddRef-before-Release on `@+0x10`. Do **not** memmove; do **not** use uninit-fill. |
| `00461ef0` | Port as **RC assign-backward**: **EAX=dest_end**, stack **first+last**, return final dest. Required for mid-insert overlap. Do **not** forward-assign overlapping ranges. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P) — sole parent of both |
| `0x00461c90` | uninit fill-n (W35-O) — different lifetime |
| `0x004620b0` | uninit-copy (W35-N) |
| `0x00431450` / `0x00431790` | BasicString fill / copy_backward siblings (operator=) |

Together they close the **in-place assign** half of RcElem28 insert-n (fill + backward) called out as nested residuals in W34-P.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (`RcElem28_*` family tied to W34-P).  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
