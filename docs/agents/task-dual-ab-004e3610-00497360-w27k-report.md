# Dual A/B report — W27-K OWN `aa_004e3610` + `aa_00497360`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-K  
**Scope:** VAs `0x004e3610`, `0x00497360` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` (callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Parent:** high-mention nested callees of sealed `CVOGSectorMap_Destructor` (`0x004d64d0`, W26-J).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e3610` CNDHash_Remove_009cc1f0 | **accept** — thiscall remove + out-transfer + freelist + RET 8 / E_FAIL sealed |
| `aa_00497360` StdList_Destroy_FreeHead | **accept** — byte-sealed free-loop destroy (decompiler incomplete) |

---

## VA `0x004e3610` — sealed facts

1. **Body:** `0x004e3610`–`0x004e36d7` (**200 B** / `0xC8`).
2. **ABI:** **ECX** = hash `this`; stack `key`, `void **outOpt`; **`RET 8`**; **EAX** = `0` hit / `0x80004005` miss.
3. **Semantics:** CNDHash remove by u32 key; lock `+0x1d` warn-only (`HashError:remove…` / `VOG_DEBUG_STOP`); bucket index + `FUN_004e2ca0`; optional out-value ownership transfer (`node+0x08`); ordered-list unlink; freelist via `PTR_FUN_009cc1f0` then next-link; `count--`.
4. **Classification:** worker; callees `FUN_007a4480`, `FUN_004e2ca0`, `operator_delete`.
5. **Caller (1 xref):** `FUN_004d64d0` @ `0x004d65c8` — sector-map hash drain (remove then delete value).
6. **Name:** `CNDHash_Remove_009cc1f0` (Ghidra `FUN_004e3610`). Prior `Named_VOG_DEBUG_STOP_*` is string-weak.
7. **Decompile ≡ bytes** for CF; bucket index explicit in bytes; early value clear seals transfer.

### Gaps

- Product English beyond CNDHash / HashError family.  
- Runtime / bit-exact differential — open.  
- Null-out payload free path not observed in sole caller.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e3610_CNDHash_Remove_009cc1f0.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004e3610_CNDHash_Remove_009cc1f0.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e3610_FUN_004e3610.md` |
| Annotated | `docs/reconstruction/raw/aa_004e3610_FUN_004e3610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e3610.cpp` |
| Clean named | `docs/reconstruction/reconstructed-exact/CNDHash_Remove_009cc1f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004e3610_FUN_004e3610.md` |
| Function named | `docs/reconstruction/functions/aa_004e3610_CNDHash_Remove_009cc1f0.md` |
| Scratch | `docs/reconstruction/tmp/a_004e3610.md` |

---

## VA `0x00497360` — sealed facts

1. **Body:** `0x00497360`–`0x004973a7` (**72 B** / `0x48`; pad `CC` after RET). Ghidra reported end `0x0049739b` is **incomplete** (mid-CALL).
2. **ABI:** **ECX** = list object (`+4` head/sentinel*, `+8` size); bare **`RET`**; void.
3. **Semantics:** MSVC circular list destroy: self-link head, size=0, free-all-nodes loop, free sentinel, **null head**.
4. **Classification:** worker; sole callee `operator_delete`.
5. **Callers (11 xrefs):** includes `FUN_004d64d0` (multi LEA list members), `FUN_004970b0`, `FUN_00575350`, `FUN_005b3b20`, `FUN_009c3800`.
6. **Name:** `StdList_Destroy_FreeHead` (Ghidra `FUN_00497360`). Sibling `0x00403430` uses clear helper; this **inlines** free-loop.
7. **Decompile incomplete** — bytes are authoritative for loop + null-head epilogue.

### Gaps

- `list+0` field unused.  
- Product English residual.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00497360_StdList_Destroy_FreeHead.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00497360_StdList_Destroy_FreeHead.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00497360_FUN_00497360.md` |
| Annotated | `docs/reconstruction/raw/aa_00497360_FUN_00497360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00497360.cpp` |
| Clean named | `docs/reconstruction/reconstructed-exact/StdList_Destroy_FreeHead_00497360.cpp` |
| Function | `docs/reconstruction/functions/aa_00497360_FUN_00497360.md` |
| Function named | `docs/reconstruction/functions/aa_00497360_StdList_Destroy_FreeHead.md` |
| Scratch | `docs/reconstruction/tmp/a_00497360.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e3610` | Port as hash remove with optional out-value **ownership transfer**. Do not free value when out is set. Preserve warn-only lock, `E_FAIL` miss, freelist reclaim of node shell. Closes nested remove used by sector-map dtor. |
| `00497360` | Port as full list **destructor** (free nodes + sentinel + null head), not clear-only. Do not invent element dtors — nodes are raw `operator_delete`. Safe on empty list. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + call-site assembly context.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Avoided bare `undefined4` in clean C++ (`uint32_t` / `void *`).  
- Corrected Ghidra loop collapse on `00497360` from bytes.
