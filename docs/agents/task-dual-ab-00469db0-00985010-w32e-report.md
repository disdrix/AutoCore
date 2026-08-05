# Dual A/B report — W32-E OWN `aa_00469db0` + `aa_00985010`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-E  
**Scope:** VAs `0x00469db0`, `0x00985010` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-E).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00469db0` AssResolverCore_HeadBag_Ctor_Inferred | **accept-with-gaps** — placement ABI/layout/twin/sole caller sealed; nested fill + product English open |
| `aa_00985010` AssPackManager_CompactPackFile_Inferred | **accept-with-gaps** — compact stage/I/O/strings/formals sealed; 0 static xrefs + nested extract/write open |

---

## VA `0x00469db0` — sealed facts

1. **Body:** `0x00469db0`–`0x00469e12` exclusive (**98 B** / `0x62`; pad `CC` then next).
2. **ABI:** stack **`this*`** placement ctor; **`RET 4`**; returns **`this` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - `head = FUN_00423d60()` (`operator_new(0x28)` circular sentinel) → store @ **`+0x08`**; **`+0x0c = 0`**.
   - **`FUN_004646e0(this+0x10, 9, &head)`** — pointer vector reserve/fill **9** slots.
   - **`+0x20 = 1`**, **`+0x24 = 1`**.
4. **Classification:** worker.
5. **Callers (1):** `FUN_00983940` @ `0x0098395d` (`AssResolverCore_Ctor_Inferred`, W31-G).
6. **Callees:** `FUN_00423d60`, `FUN_004646e0`.
7. **Name:** `AssResolverCore_HeadBag_Ctor_Inferred` (Ghidra `FUN_00469db0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_assManager_00469db0`.
8. **Twin:** same CF as `FUN_00423cf0` (Resolver-A member bag).  
   Full hex: raw W32-E append (98 B).

### Gaps

- Product English for list vs ptr-vec roles / +0x20/+0x24.  
- Nested `FUN_00423d60` / `FUN_004646e0` fill product (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00469db0_AssResolverCore_HeadBag_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00469db0_AssResolverCore_HeadBag_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00469db0_FUN_00469db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00469db0_FUN_00469db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssResolverCore_HeadBag_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00469db0.cpp` |
| Function | `docs/reconstruction/functions/aa_00469db0_FUN_00469db0.md` |
| Function named | `docs/reconstruction/functions/aa_00469db0_AssResolverCore_HeadBag_Ctor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00469db0.md` |

---

## VA `0x00985010` — sealed facts

1. **Body:** `0x00985010`–`0x0098538d` exclusive (**893 B** / `0x37D`; pad `CC` then `FUN_00985390`).
2. **ABI:** **ECX=`const char* packPath`**; stack **`int mode`**, **`char quiet`**; bare **`C3`**; returns **0**. ESI=`"glm"` only for path helper.
3. **Semantics:**
   - Path rewrite via **`FUN_0076b190`** + ext `"glm"`.
   - Stack **`FUN_00983940`** packA → **`FUN_00984ee0(..., flag=1)`** open source.
   - Stack packB + `"_pk_"` stage → open **`"_pack_tmp.glm"`** flag **0**.
   - For each list entry: join `"_pk_"+"/"+name`; if **`mode==3`** use `(int16)node[+0x20]`; extract/write; stat/chmod/unlink; optional **`printf("Compacting file %s.\n")`**.
   - Summary **"Packer compacted %d files."**; close helpers; unlink original; **`MoveFileA("_pack_tmp.glm", path)`**; dtor hosts.
4. **Classification:** worker (offline packer tool).
5. **Callers:** **none static** (0 code/data xrefs).
6. **Callees:** open/ctor/dtor pack path (`00983940`, `00984ee0`, `009838a0`, `00983720`, `00984890`), `_pk_` helpers, string join, extract/write residuals, CRT file APIs, `MoveFileA`, `printf`.
7. **Name:** `AssPackManager_CompactPackFile_Inferred` (Ghidra `FUN_00985010`; **Inferred** from packer strings).
8. **Decompile ≡ bytes** for stage order; open sites match W31-H EBX=host/ECX=path.  
   Entry+epilogue hex: raw W32-E append.

### Gaps

- Zero static xrefs — invocation path open.  
- Nested extract/write (`FUN_00984d30`, `FUN_00984910`) product plates.  
- Non-3 `mode` meanings.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00985010_AssPackManager_CompactPackFile_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00985010_AssPackManager_CompactPackFile_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00985010_FUN_00985010.md` |
| Annotated | `docs/reconstruction/raw/aa_00985010_FUN_00985010.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_CompactPackFile_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00985010.cpp` |
| Function | `docs/reconstruction/functions/aa_00985010_FUN_00985010.md` |
| Function named | `docs/reconstruction/functions/aa_00985010_AssPackManager_CompactPackFile_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00985010.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00469db0` | Port as **stack placement ctor** (RET 4). Sentinel list @+0x08, ptr-vec cap **9** @+0x10, flags 1/1 @+0x20/+0x24. Called first by `AssResolverCore_Ctor_Inferred`. Do **not** invent vtbl write. Twin residual `FUN_00423cf0` still open. |
| `00985010` | Port as **offline pack compact** tool: ECX path, mode, quiet; dual open (source flag1 / `_pack_tmp.glm` flag0); per-entry rewrite under `_pk_`; replace via `MoveFileA`. **Not** a gameplay AssManager call site (0 xrefs). Preserve quiet gating on printf. |
| Pair with | W31-G `AssResolverCore_Ctor_Inferred` / `AssManager_ResolverA_Ctor_Inferred`; W31-H `AssPackManager_OpenPackFile_Inferred`; nested `FUN_00423d60` / `FUN_004646e0` / extract-write residuals. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Rejected assManager scaffold alias for `00469db0`.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
