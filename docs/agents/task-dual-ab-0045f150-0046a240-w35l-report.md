# Dual A/B report — W35-L OWN `aa_0045f150` + `aa_0046a240`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-L  
**Scope:** VAs `0x0045f150`, `0x0046a240` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-L).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0045f150` StdUninitFillN_Elem28_CountEax_Inferred | **accept** — 73 B leaf fill-n; EAX count / ECX template / EDX dest; stride 0x1c; null gate sealed |
| `aa_0046a240` StdCopyBackward_Elem28_Inferred | **accept** — 30 B leaf copy_backward; EAX dest_end / EDX src_end / EBX src_begin; stride 0x1c sealed |

---

## VA `0x0045f150` — sealed facts

1. **Body:** `0x0045f150`–`0x0045f198` inclusive (**73 B** / `0x49`; pad `CC`×7 then next @ `0x0045f1a0`).
2. **ABI:** **EAX=`count`**, **ECX=`template*`**, **EDX=`dest*`**; bare **`RET`**. Decompiler omits count formal — **bytes + callers win**.
3. **Semantics:** MSVC-style uninit fill-n for POD T size **0x1c**:
   - Early-out if count==0 (`TEST/JBE` unsigned).
   - Loop: if dest non-null, copy 7 dwords from template; always `dest += 0x1c`; count--.
   - Template pointer not advanced (same value written N times).
4. **Classification:** leaf worker — 0 callees.
5. **Callers (1 func / 2 sites):** `FUN_0045cd30` (`StdVector_InsertN_Pod28`, W34-P) @ `0x0045ceae`, `0x0045cfb7`.
6. **Callees:** none.
7. **Name:** `StdUninitFillN_Elem28_CountEax_Inferred` (Ghidra `FUN_0045f150`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_…anmTrackMast_0045f150`.
8. **Decompile vs bytes:** CF matches fill-n; **bytes win** on EAX count formal. Full hex: raw W35-L append.

### Gaps

- Product/MSVC demangle English.  
- Concrete POD T identity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0045f150_StdUninitFillN_Elem28_CountEax_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0045f150_StdUninitFillN_Elem28_CountEax_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0045f150_FUN_0045f150.md` |
| Annotated | `docs/reconstruction/raw/aa_0045f150_FUN_0045f150.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_Elem28_CountEax_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0045f150.cpp` |
| Function | `docs/reconstruction/functions/aa_0045f150_FUN_0045f150.md` |
| Function named | `docs/reconstruction/functions/aa_0045f150_StdUninitFillN_Elem28_CountEax_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0045f150.md` |

---

## VA `0x0046a240` — sealed facts

1. **Body:** `0x0046a240`–`0x0046a25d` inclusive (**30 B** / `0x1E`; pad `CC`×2 then `FUN_0046a260` @ `0x0046a260`).
2. **ABI:** **EAX=`dest_end*`**, **EDX=`src_end*`**, **EBX=`src_begin*`**; bare **`RET`**. ECX clobbered (`MOV ECX,7` for `REP MOVSD`). Decompiler phantom `param_1` is **not** a formal.
3. **Semantics:** MSVC-style **`copy_backward`** for POD T size **0x1c**:
   - Empty range: `EBX == EDX` → return.
   - Loop: `src_end -= 0x1c`; `dest_end -= 0x1c`; copy 7 dwords via `REP MOVSD`; until src_end reaches src_begin.
   - Required for overlap-safe mid-insert tail shift.
4. **Classification:** leaf worker — 0 callees.
5. **Callers (3):** `FUN_00469f50` @ `0x0046a1dc`; `FUN_00466ea0` @ `0x00467150`; `FUN_0045cd30` @ `0x0045cff4` (all elem-28 insert-n mid arms; unowned here).
6. **Callees:** none.
7. **Name:** `StdCopyBackward_Elem28_Inferred` (Ghidra `FUN_0046a240`; **Inferred**). **Reject** scaffold `Named_CalleeOf_…anmTrackMast_0046a240`.
8. **Decompile vs bytes:** CF ≡ reverse element move; **bytes win** on three-register formals. Full hex: raw W35-L append.

### Gaps

- Product/MSVC demangle English.  
- Concrete POD T identity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0046a240_StdCopyBackward_Elem28_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0046a240_StdCopyBackward_Elem28_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0046a240_FUN_0046a240.md` |
| Annotated | `docs/reconstruction/raw/aa_0046a240_FUN_0046a240.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdCopyBackward_Elem28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0046a240.cpp` |
| Function | `docs/reconstruction/functions/aa_0046a240_FUN_0046a240.md` |
| Function named | `docs/reconstruction/functions/aa_0046a240_StdCopyBackward_Elem28_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0046a240.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0045f150` | Port as **elem-28 uninit fill-n**: **EAX=count**, **ECX=template***, **EDX=dest***, bare RET. Null-safe store + always advance 0x1c. Do **not** invent stack formals or conflate with `FUN_0046a260` (different ABI) or string fill-assign (`00431450`). |
| `0046a240` | Port as **elem-28 copy_backward**: **EAX=dest_end**, **EDX=src_end**, **EBX=src_begin**, bare RET. Mid-insert **must** reverse-walk for overlap safety; do not use forward copy for the middle shift. |
| Shared | Both close W34-P/Q insert-n helper residuals for POD stride 0x1c. Server needs one correct fill + reverse-move for 28-byte POD — retail register ABIs are compile artifacts. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0045cd30` | `StdVector_InsertN_Pod28` (W34-P) — sole parent of `0045f150`; also calls `0046a240` |
| `0x00466ea0` | `StdVector_InsertN_Elem28_CountEcx_Inferred` (W34-Q) — calls `0046a240` |
| `0x00469f50` | `StdVector_InsertN_Elem28_ValueEdx_Inferred` (W34-Q) — calls `0046a240` |
| `0x0046a260` | sibling fill-n next symbol (unowned; different ABI) |
| `0x0045efe0` | assign-fill hole after reverse-move (unowned) |
| `0x0045f360` | uninit copy range peer under Pod28 insert (unowned) |
| `0x00436ef0` | `Mem_FillDwordN_FromSrc_EaxEcxEdx` — dword-stride null-safe fill cousin |
| `0x00431480` | `BasicString_CopyBackward_Thunk_0x1c` — string-aware sibling family |

Closes W35-L OWN pair of elem-28 STL helpers (fill-n + copy_backward) under the insert-n chain.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit `Elem28`).
