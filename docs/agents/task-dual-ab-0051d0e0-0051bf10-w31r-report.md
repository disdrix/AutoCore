# Dual A/B report — W31-R OWN `aa_0051d0e0` + `aa_0051bf10`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-R  
**Scope:** VAs `0x0051d0e0`, `0x0051bf10` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-R).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051d0e0` ObjectCsList_CompleteDtor_Inferred | **accept-with-gaps** — dual-vtbl complete CF/ABI/DeleteCS sealed; product English residual |
| `aa_0051bf10` ObjectCsListBase_ScalarDeletingDtor_Inferred | **accept-with-gaps** — base scalar ABI/flags/DeleteCS sealed; product base English residual |

---

## VA `0x0051d0e0` — sealed facts

1. **Body:** `0x0051d0e0`–`0x0051d107` exclusive (**39 B** / `0x27`; pad `CC`).
2. **ABI:** **ECX=`this`**; bare **`RET`** (`C3`); void. Complete dtor — **does not** free `this`.
3. **Semantics:** MSVC complete dtor for Object SharedBase CS helper list (`sizeof 0x2C`, `core+0xB0`):
   - Install derived **`PTR_FUN_009ce154`** @ `+0`.
   - **`FUN_0051bc90`** drain (CS + nodes next@+8; no `node+4=0`).
   - Install base **`PTR_FUN_009ce07c`** @ `+0`.
   - **`FUN_0051bc90`** again.
   - **`DeleteCriticalSection(this+4)`** via IAT `[0x009c61f0]`.
4. **Classification:** worker.
5. **Callers:** CODE only `FUN_0051d0c0` @ `0x0051d0c3` (scalar deleting wrapper; vtbl `009ce154` slot0 = `0x0051d0c0`).
6. **Callees:** `FUN_0051bc90` ×2, `DeleteCriticalSection`.
7. **Name:** `ObjectCsList_CompleteDtor_Inferred` (Ghidra `FUN_0051d0e0`; **Inferred** structural).
8. **Decompile ≡ bytes** for stage order; clean must pass `this` into both clears (ESI/`MOV ECX,ESI`).  
   Full hex: raw W31-R append (39 B).

### Gaps

- Product / MSVC demangle for CS-list class.  
- Whether second clear is pure base-phase boilerplate.  
- Nested `FUN_0051bc90` product plate (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051d0e0_ObjectCsList_CompleteDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051d0e0_ObjectCsList_CompleteDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051d0e0_FUN_0051d0e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051d0e0_FUN_0051d0e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectCsList_CompleteDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051d0e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0051d0e0_FUN_0051d0e0.md` |
| Function named | `docs/reconstruction/functions/aa_0051d0e0_ObjectCsList_CompleteDtor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0051d0e0.md` |

---

## VA `0x0051bf10` — sealed facts

1. **Body:** `0x0051bf10`–`0x0051bf3e` exclusive (**46 B** / `0x2E`; pad `CC`).
2. **ABI:** **ECX=`this`**; stack **`flags`**; **`RET 4`**; returns **`this`** in EAX. MSVC **scalar deleting** dtor.
3. **Semantics:**
   - Install base **`PTR_FUN_009ce07c`** only (no derived `009ce154` phase).
   - **`FUN_0051bc90`** drain.
   - **`DeleteCriticalSection(this+4)`**.
   - If **`flags & 1`**: **`operator_delete(this)`** (cdecl, `ADD ESP,4`).
4. **Classification:** worker.
5. **Callers / xrefs:** DATA only — vtbl `PTR_FUN_009ce07c` @ `0x009ce07c` slot0 → `0x0051bf10`. No CODE callers.
6. **Callees:** `FUN_0051bc90`, `DeleteCriticalSection`, `operator_delete`.
7. **Name:** `ObjectCsListBase_ScalarDeletingDtor_Inferred` (Ghidra `FUN_0051bf10`; **Inferred**).
8. **Decompile ≡ bytes** for CF; **false noreturn** on `operator_delete` ignored (epilogue still runs).  
   Full hex: raw W31-R append (46 B).

### Gaps

- Product base class English for `PTR_FUN_009ce07c`.  
- Array-delete (`flags&2`) not present — scalar-only body.  
- Runtime choice of base vs derived destroy path.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051bf10_ObjectCsListBase_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051bf10_ObjectCsListBase_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051bf10_FUN_0051bf10.md` |
| Annotated | `docs/reconstruction/raw/aa_0051bf10_FUN_0051bf10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectCsListBase_ScalarDeletingDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051bf10.cpp` |
| Function | `docs/reconstruction/functions/aa_0051bf10_FUN_0051bf10.md` |
| Function named | `docs/reconstruction/functions/aa_0051bf10_ObjectCsListBase_ScalarDeletingDtor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0051bf10.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051d0e0` | Port as **complete dtor only**: derived vtbl → clear → base vtbl → clear → `DeleteCriticalSection(+4)`. Do **not** free here. Pair with scalar wrapper `FUN_0051d0c0` when owning. |
| `0051bf10` | Port as **base scalar deleting dtor**: base vtbl → clear → DeleteCS → optional `operator_delete` on `flags&1`. Virtual via `009ce07c[0]`. Ignore Ghidra noreturn on delete. |
| Pair with | W30-F `ObjectCsList_ClearDestroy_Inferred` (`0x0051b8a0`, nodes only + `node+4=0`), drain twin `FUN_0051bc90`, SharedBase ctor/dtor (`0x00518940` / `0x00518ec0`), scalar `FUN_0051d0c0`. Closes dtor residual named in W30-F clear seal. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / Windows CS types).  
- Distinguished complete (`0051d0e0`) vs base scalar (`0051bf10`) vs clear-only (`0051b8a0`).
