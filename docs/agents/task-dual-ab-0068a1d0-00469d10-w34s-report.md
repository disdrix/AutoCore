# Dual A/B report — W34-S OWN `aa_0068a1d0` + `aa_00469d10`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-S  
**Scope:** VAs `0x0068a1d0`, `0x00469d10` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs/callers (+ nested helper decompiles for type proof only). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-S).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0068a1d0` StdVector_InsertN_Elem28 | **accept-with-gaps** — insert-n ABI/CF/POD-0x1c/max/1.5× sealed; product T + nested helpers open |
| `aa_00469d10` StdVector_AssignFrom_BasicString | **accept-with-gaps** — src-this assign ABI/CF/string-uninit sealed; buy no-free + product demangle open |

---

## VA `0x0068a1d0` — sealed facts

1. **Body:** `0x0068a1d0`–`0x0068a49a` exclusive (**714 B** / `0x2CA`; pad `CC` then next).
2. **ABI:** **ECX=`vector*`**; stack **where\***, **count**, **value\***; **`RET 0x0C`** (`C2 0C 00`); void. SEH `LAB_009aa170`.
3. **Semantics:** MSVC-style **`vector<T>::insert(where, count, value)`** for **POD T size 0x1c**:
   - Local value via **`rep movsd` ×7** (not string IAT copy-ctor).
   - Early-out if `count==0`.
   - Capacity/size via triad begin@`+4` / end@`+8` / capEnd@`+0xC` and `/0x1c` magic `0x92492493`.
   - If `size+count > 0x9249249` → `FUN_00686070` (too long).
   - Grow: 1.5× (`cap+(cap>>1)`), floor `size+count` via `StdVector_Elem28_Size` (`FUN_00469c50`); `operator_new`; relocate prefix/suffix (`FUN_00687d10`); fill-n (`FUN_00688550`); **`operator_delete` old** (cdecl, continues — decompiler false-noreturn).
   - In-place: hole vs mid via `FUN_0068a1a0` / `FUN_00687ce0` / `FUN_006860f0`.
4. **Classification:** worker.
5. **Callers (1):** `FUN_0068a620` @ `0x0068a673` (insert-one rebind, count=`1`).
6. **Callees:** `FUN_00686070`; `FUN_00469c50`; `operator_new`/`delete`; `FUN_00687d10`; `FUN_00688550`; `FUN_0068a1a0`; `FUN_00687ce0`; `FUN_006860f0`.
7. **Name:** `StdVector_InsertN_Elem28` (Ghidra `FUN_0068a1d0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_*`. Algorithm twin of `StdVector_InsertN_BasicString` (`0x004306b0`) but **POD** helpers (not string).
8. **Decompile ≡ bytes** for CF; **bytes win** on delete continue + triple `C2 0C 00`.  
   Full hex: raw W34-S append (714 B).

### Gaps

- Product English for POD `T`.  
- Nested relocate/fill/throw helper plates (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0068a1d0_StdVector_InsertN_Elem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0068a1d0_StdVector_InsertN_Elem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0068a1d0_FUN_0068a1d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0068a1d0_FUN_0068a1d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0068a1d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0068a1d0_FUN_0068a1d0.md` |
| Function named | `docs/reconstruction/functions/aa_0068a1d0_StdVector_InsertN_Elem28.md` |
| Scratch | `docs/reconstruction/tmp/a_0068a1d0.md` |

---

## VA `0x00469d10` — sealed facts

1. **Body:** `0x00469d10`–`0x00469d96` exclusive (**134 B** / `0x86`; no pad — next code immediately).
2. **ABI:** **ECX=`src vector*`**; stack **`dest*`**; **`RET 4`** (`C2 04 00`); returns **dest in EAX**. SEH `LAB_009bdc60`.
3. **Semantics:** **Assign-from-src** into dest for `vector<basic_string<char>>` (elem **0x1c**):
   - `n = src empty ? 0 : (end-begin)/0x1c`.
   - **`FUN_00431b30(dest, n)`** — zeros dest triad (**no free** of prior buffer); if `n≠0` allocates `n*0x1c`, begin=end=buf, capEnd=buf+nbytes; returns 0 iff `n==0`.
   - If ready: **`FUN_0046a2c0`** (`StdUninitCopy_BasicString`, W33-G) copies `[src.begin, src.end)` into dest; store dest.end.
   - Return dest.
4. **Classification:** worker.
5. **Callers (2 / 3 sites):** `FUN_009841d0` @ `0x00984244`; `FUN_00984340` (`Fs_ExpandPathSpecToStringVec_Inferred`) @ `0x009842ed`, `0x00984760`.
6. **Callees:** `FUN_00431b30`; `FUN_0046a2c0`.
7. **Name:** `StdVector_AssignFrom_BasicString` (Ghidra `FUN_00469d10`; **Inferred** structural). Closes W33-G residual “range assign” consumer of uninit_copy; closes W33-E Fs expand assign step.
8. **Decompile ≡ bytes** for CF; **bytes win** on `MOV ECX,EDI` before buy (dest is this for `FUN_00431b30`).  
   Full hex: raw W34-S append (134 B).

### Gaps

- Product/MSVC demangle.  
- Caller dest-empty invariant (buy has no free — leak if dest owned).  
- Nested `FUN_00431b30` plate unowned.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00469d10_StdVector_AssignFrom_BasicString.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00469d10_StdVector_AssignFrom_BasicString.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00469d10_FUN_00469d10.md` |
| Annotated | `docs/reconstruction/raw/aa_00469d10_FUN_00469d10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_AssignFrom_BasicString.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469d10.cpp` |
| Function | `docs/reconstruction/functions/aa_00469d10_FUN_00469d10.md` |
| Function named | `docs/reconstruction/functions/aa_00469d10_StdVector_AssignFrom_BasicString.md` |
| Scratch | `docs/reconstruction/tmp/a_00469d10.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0068a1d0` | Port as **`vector<POD0x1c>::insert(where, count, value)`**. Honor max `0x9249249`, 1.5× grow, **raw 0x1c memcpy** relocate/fill (no string dtors). **`RET 0x0C`**. Do **not** unify with `StdVector_InsertN_BasicString` (`0x004306b0`). Wrapper `FUN_0068a620` is insert-one + iterator rebind. |
| `00469d10` | Port as **assign-from-src**: **ECX=src**, stack dest*, **`RET 4`**, return dest. Blank-buy dest then string uninit_copy. **Do not** free prior dest buffer inside this unit (nested buy zeros only) — callers must pass empty dest. |
| Pair with | W33-J `StdVector_Elem28_Size` (`0x00469c50`); W32-B `StdVector_InsertN_BasicString` (`0x004306b0`); W33-G `StdUninitCopy_BasicString` (`0x0046a2c0`); W33-E `Fs_ExpandPathSpecToStringVec_Inferred` (`0x00984340`); nested buy `FUN_00431b30`; insert-one `FUN_0068a620`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only (`StdVector_InsertN_Elem28` / `StdVector_AssignFrom_BasicString`).  
- Rejected scaffold `Named_CalleeOf_*` for `0068a1d0`.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit POD/string structs).
