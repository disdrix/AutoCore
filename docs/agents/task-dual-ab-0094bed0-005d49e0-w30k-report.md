# Dual A/B report — W30-K OWN `aa_0094bed0` + `aa_005d49e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-K  
**Scope:** VAs `0x0094bed0`, `0x005d49e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs/callers/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0094bed0` Object_009d33c4_FactoryRegisterListed_Inferred | **accept-with-gaps** — EDI/host + ret 8 + new(0x210)/ctor/COID/register CF sealed; product English + virtual semantics open |
| `aa_005d49e0` Object_CompositeStopTypeF_MIEntry_Inferred | **accept** — 34 B CF + dual this-adjust + ret 4 + sole 00581500 CALL sealed; product spelling `_Inferred` only |

---

## VA `0x0094bed0` — sealed facts

1. **Body:** `0x0094bed0`–`0x0094bf8d` inclusive (**190 B** / `0xBE`; pad `CC` then next unit).
2. **ABI:** **EDI = host**; stack `(coid_lo, coid_hi)`; epilogue **`ret 8`** both exits; returns `object*` or `NULL`. Decompiler `int* (void)` + `unaff_EDI` is incomplete.
3. **Semantics:** Factory for `Object_009d33c4` family:
   - SEH `LAB_009ab618`; EH `−1` → `0` around ctor → `−1`.
   - `operator_new(0x210)` → `Object_009d33c4_Ctor` (`FUN_00575440`, W29-H) if non-null.
   - `vtbl+8(DAT_00af30f4, *(host+0xe04), 1)`.
   - `Object_SetCoidIdentity` / `FUN_00512160`(obj, coid_lo, coid_hi, 1) — stack formals (not SEH locals).
   - `vtbl+0x218(*(host+0xe04))`.
   - `Object_RegisterListed` (`FUN_004bc180`) on `*(host+0xd34)`; if HRESULT `< 0`: `vtbl[0](1)` scalar-delete → `NULL`; else return obj.
4. **Classification:** worker / factory (4 named callees + 3 virtuals).
5. **Callers (1):** `FUN_008119c0` @ `0x00811a0f` (`edi=ebx` host; push packet COID pair).
6. **Name:** `Object_009d33c4_FactoryRegisterListed_Inferred` (Ghidra `FUN_0094bed0`; **Inferred** from W29-H ctor family + register). Supersedes scaffold string-seed name.
7. **Decompile residuals:** wrong SetCoid args; ExceptionList restore mixup; missing `ret 8`/EDI ABI. **Bytes win.**  
   Full hex: see raw append (190 B).

### Gaps

- Product/PDB type English for object + host.  
- Semantic labels for `vtbl+8` / `+0x218` / host `+0xe04`.  
- Null-new path undefined in image (no early return).  
- Parent `FUN_008119c0` dual not OWN.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0094bed0_Object_009d33c4_FactoryRegisterListed_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0094bed0_Object_009d33c4_FactoryRegisterListed_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0094bed0_FUN_0094bed0.md` |
| Annotated | `docs/reconstruction/raw/aa_0094bed0_FUN_0094bed0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_009d33c4_FactoryRegisterListed_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0094bed0.cpp` |
| Function | `docs/reconstruction/functions/aa_0094bed0_FUN_0094bed0.md` |
| Function named | `docs/reconstruction/functions/aa_0094bed0_Object_009d33c4_FactoryRegisterListed_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0094bed0.md` |

---

## VA `0x005d49e0` — sealed facts

1. **Body:** `0x005d49e0`–`0x005d4a01` inclusive (**34 B** / `0x22`; pad `CC` then sibling stub at `0x005d4a02`).
2. **ABI:** **`__thiscall`** ECX = this_entry; stack `(param)`; epilogue **`ret 4`**; void.
3. **Entry / body:** `push esi/edi; edi=param; esi=this;`  
   - `push param; lea ecx,[esi-0x90]; call FUN_0053d4b0`  
   - `push param; lea ecx,[esi-0x10]; call FUN_00581500`  
   - `pop edi/esi; ret 4`
4. **Callee roles:**
   - `FUN_0053d4b0`: `ecx=*(this-0x48)`; if nonzero `FUN_005070d0`; `ret 4` (with adjust → probe `entry-0xD8`).
   - `FUN_00581500`: `Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred` (W29-O) — sole **CODE CALL** site of that thunk (`0x005d49f8`).
5. **Classification:** wrapper / composite MI public entry (**2** callees).
6. **Xrefs (4):** all MSVC MI **JMP adjustors** (`sub ecx,[ecx-4]; sub ecx,imm; jmp 005d49e0`) at `004cc640`, `00506890`, `0051ec60`, `0053bc70`. **No** direct CALL factories.
7. **Name:** `Object_CompositeStopTypeF_MIEntry_Inferred` (Ghidra `FUN_005d49e0`; **Inferred** structural from adjust + W29-O role).
8. **Decompiler residual:** shows only bare sequential calls — **elides** both LEA adjusts + `ret 4`. Bytes win.  
   Full hex: see raw append (34 B).

### Gaps

- Product/PDB method spelling.  
- Nested English for `0053d4b0` / `005070d0` field.  
- Exhaustive vtable slot catalog for peer adjustors.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d49e0_Object_CompositeStopTypeF_MIEntry_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005d49e0_Object_CompositeStopTypeF_MIEntry_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d49e0_FUN_005d49e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d49e0_FUN_005d49e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CompositeStopTypeF_MIEntry_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d49e0.cpp` |
| Function | `docs/reconstruction/functions/aa_005d49e0_FUN_005d49e0.md` |
| Function named | `docs/reconstruction/functions/aa_005d49e0_Object_CompositeStopTypeF_MIEntry_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005d49e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0094bed0` | Port as **host factory**: EDI host + two COID stack args + **`ret 8`**. Sequence new(0x210) → `Object_009d33c4_Ctor` → vtbl+8 → SetCoidIdentity → vtbl+0x218 → RegisterListed on `host+0xd34`. Fail only on hr&lt;0 (scalar delete). Do **not** trust decompiler SEH-local SetCoid args. |
| `005d49e0` | Port as **MI composite entry**: `this'−0x90` then `this'−0x10` before sealed callees; preserve **`ret 4`**. Do **not** trust decompiler bare-call surface. Entry is JMP-adjustor public method; closes W29-O residual “sole CALL of 00581500”. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00575440` | `Object_009d33c4_Ctor` (W29-H) — factory ctor |
| `0x00575c00` | scalar deleting dtor (fail path vtbl[0]) |
| `0x00512160` | `Object_SetCoidIdentity` |
| `0x004bc180` | `Object_RegisterListed` (W19-E) |
| `0x008119c0` | sole factory caller |
| `0x00581500` | type-0xF MI thunk (W29-O) — second callee |
| `0x00514d80` | type-0xF impl (W28-H) |
| `0x0053d4b0` | optional nested stop gate (first callee) |
| `0x005070d0` | nested stop worker from `0053d4b0` |
| `DAT_00af30f4` | global first arg to factory vtbl+8 |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + complete analysis / xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Avoid bare `undefined4` in clean (used `uint32_t` / `void*`).

---

## This report

`docs/agents/task-dual-ab-0094bed0-005d49e0-w30k-report.md`
