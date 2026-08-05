# Dual A/B report — W37-O OWN `aa_00788db0` + `aa_0051d0c0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-O  
**Scope:** VAs `0x00788db0`, `0x0051d0c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-O).  
**Accuracy note:** `0x0051d0c0` flagged skill-adjacent in partition — **sealed as object CS-list scalar deleting dtor, not skill.**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00788db0` MemZero_DestSize_ReturnOne_Inferred | **accept** — cdecl leaf zero-fill; body/ABI/return-1/callers sealed |
| `aa_0051d0c0` ObjectCsList_ScalarDeletingDtor_Inferred | **accept-with-gaps** — derived scalar CF/ABI/vtbl/flags sealed; product English residual; **not skill** |

---

## VA `0x00788db0` — sealed facts

1. **Body:** `0x00788db0`–`0x00788dfc` exclusive (**76 B** / `0x4C`; pad `CC` then next @ `0x00788e00`).
2. **ABI:** **cdecl** — stack **`dest*`**, stack **`size`** (signed compares); bare **`RET`** (`C3`); returns **`1`** in EAX.
3. **Semantics:** Zero-fill buffer:
   - If signed size **> 4**: bulk **`REP STOSD`** of `floor((size-1)/4)` dwords (`((size-5)>>2)+1`); advance dest; remaining.
   - If signed size/remaining **> 0**: **`REP STOSD`** (`size>>2`) + **`REP STOSB`** (`size&3`).
   - size ≤ 0: no stores; still return 1.
   - **Not** CRT `memset` (no fill-value arg; returns 1 not dest).
4. **Classification:** leaf — 0 callees.
5. **Callers (3 CODE):**
   - `FUN_00497920` (`ListTrackedCtx_Ctor_Inferred`, W32-P) @ `0x0049796b` — `(this+0x14, 0xA0)`.
   - `FUN_00497c80` (`ListTrackedCtx_ClearDestroyAndReset_Inferred`, W33-R) @ `0x00497cbf` — same; `ADD ESP,8`.
   - `FUN_00498380` @ `0x004985c4` — zeros `operator_new__(0x52000)` block stored at `this+0xB4`.
6. **Callees:** none.
7. **Name:** `MemZero_DestSize_ReturnOne_Inferred` (Ghidra `FUN_00788db0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_*Drive_NDRiver_fx_00788db0`.
8. **Decompile vs bytes:** CF matches full zero of `size` bytes; **bytes win** on `REP STOS*` (decompiler expands dword/byte stores). Full hex: raw W37-O append.

### Gaps

- Product/MSVC helper demangle English.  
- Whether return-1 is consumed (sites appear fire-and-forget).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00788db0_MemZero_DestSize_ReturnOne_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00788db0_MemZero_DestSize_ReturnOne_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00788db0_FUN_00788db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00788db0_FUN_00788db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MemZero_DestSize_ReturnOne_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00788db0.cpp` |
| Function | `docs/reconstruction/functions/aa_00788db0_FUN_00788db0.md` |
| Function named | `docs/reconstruction/functions/aa_00788db0_MemZero_DestSize_ReturnOne_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00788db0.md` |

---

## VA `0x0051d0c0` — sealed facts

1. **Body:** `0x0051d0c0`–`0x0051d0de` exclusive (**30 B** / `0x1E`; pad `CC` then complete dtor @ `0x0051d0e0`).
2. **ABI:** **ECX=`this`**; stack **`flags`**; **`RET 4`** (`C2 04 00`); returns **`this`** in EAX. MSVC **scalar deleting** dtor.
3. **Semantics:**
   - `CALL FUN_0051d0e0` (complete dtor: derived `009ce154` → clear → base `009ce07c` → clear → `DeleteCriticalSection(+4)`; **no free**).
   - If **`flags & 1`**: **`operator_delete(this)`** (cdecl, `ADD ESP,4`).
   - Return `this`.
4. **Classification:** worker.
5. **Callers / xrefs:** **DATA only** — vtbl `PTR_FUN_009ce154` @ `0x009ce154` slot0 → `0x0051d0c0` (dword `c0 d0 51 00`). No CODE callers.
6. **Callees:** `FUN_0051d0e0`, `operator_delete`.
7. **Name:** `ObjectCsList_ScalarDeletingDtor_Inferred` (Ghidra `FUN_0051d0c0`; **Inferred** structural). Closes residual named in W31-R for scalar wrapper of complete dtor.
8. **Accuracy (skill-adjacent):** **Not skill.** Object-core CS-list derived scalar deleting dtor only. No skill IDs, tables, or cast paths. Nearby `CVOGClonedObject` string is object system. Do **not** invent skill semantics from partition adjacency.
9. **Decompile ≡ bytes** for CF; **false noreturn** on `operator_delete` ignored (epilogue still runs). Full hex: raw W37-O append (30 B).

### Gaps

- Product / MSVC demangle English for derived CS-list class.  
- Array-delete (`flags&2`) not present — scalar-only body.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051d0c0_ObjectCsList_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051d0c0_ObjectCsList_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051d0c0_FUN_0051d0c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051d0c0_FUN_0051d0c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectCsList_ScalarDeletingDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051d0c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0051d0c0_FUN_0051d0c0.md` |
| Function named | `docs/reconstruction/functions/aa_0051d0c0_ObjectCsList_ScalarDeletingDtor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0051d0c0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00788db0` | Port as **cdecl zero-fill returning 1**: `(void* dest, int size)` bare RET. Zero `size` bytes when size > 0; always return 1. May use `memset(dest,0,size)` or bit-exact bulk/tail `REP STOS*`. Do **not** invent fill-value param, return-dest CRT shape, or thiscall. Do **not** keep `Named_CalleeOf_*` alias. |
| `0051d0c0` | Port as **derived ObjectCsList scalar deleting dtor**: thiscall + flags, `RET 4`. Call complete dtor (`0051d0e0`) then optional `operator_delete` on `flags&1`. Virtual via `009ce154[0]`. **Not skill.** Ignore Ghidra noreturn on delete. Do **not** substitute for base scalar `0051bf10` or complete-only `0051d0e0`. |
| Shared | Closes W37-O OWN pair: **util zero leaf** used by ListTrackedCtx/flair rebuild + **object CS-list derived scalar dtor** residual named since W31-R. Not algorithmically related beyond wave co-ownership. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00497920` | `ListTrackedCtx_Ctor_Inferred` (W32-P) — caller of `00788db0` |
| `0x00497c80` | `ListTrackedCtx_ClearDestroyAndReset_Inferred` (W33-R) — caller |
| `0x00498380` | flair/table rebuild — large buffer zero via `00788db0` |
| `0x0051d0e0` | `ObjectCsList_CompleteDtor_Inferred` (W31-R) — complete body wrapped by `0051d0c0` |
| `0x0051bf10` | `ObjectCsListBase_ScalarDeletingDtor_Inferred` (W31-R) — base vtbl scalar |
| `0x0051bc90` | CS drain (from complete) |
| `0x0051b8a0` | `ObjectCsList_ClearDestroy_Inferred` (W30-F) |
| `0x009ce154` | derived vtbl; slot0 → `0x0051d0c0` |
| `0x009ce07c` | base vtbl; slot0 → `0x0051bf10` |

Closes W37-O OWN pair: MemZero return-1 leaf + ObjectCsList derived scalar deleting dtor (not skill).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf / demangle-guess aliases.  
- **Skill-adjacent accuracy:** explicitly rejected skill labeling for `0051d0c0` with vtbl + complete-dtor evidence.  
- Avoided bare `undefined4` in clean (`uint32_t` / `void*` / `uint8_t`).
