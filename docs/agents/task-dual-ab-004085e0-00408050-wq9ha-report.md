# Dual A/B report — WQ9H-A OWN-ONLY (`0x004085e0`, `0x00408050`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9H-A** (replacement — prior agent stuck)  
**Scope:** VAs `0x004085e0`, `0x00408050` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-A**.  
**Work item:** WQ-009 depth-5 residual dual seal (CNDHash freelist + vector InsertN 0x28).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004085e0` CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred | **accept-with-gaps** — freelist CF/EBX ABI/bare ret/node layout sealed; product residual |
| `aa_00408050` StdVector_InsertN_Elem0x28_Inferred | **accept-with-gaps** — InsertN CF/ECX+EDX/ret8/stride0x28/1.5× grow sealed; POD English residual |

Path A (fidelity): as above.  
Path B (adversarial): destroy-table merge / tree free / skill thiscall / InsertN12 thiscall-3arg / dword-twin / always-grow misreads rejected; scaffold voids closed via bytes.

---

## VA `0x004085e0` — sealed facts

1. **Body:** `0x004085e0`–`0x00408635` exclusive (**85 B** / `0x55`); last `C3`; pad `CC`.
2. **ABI:** **customcc**; **EBX** = CNDHash*; no stack; void; bare ret.
3. **Semantics:** Walk buckets `0..mask` (`mask@+0x08`); for each chain head `*(table[i]+4)`: stamp node vtbl `PTR_FUN_00a2c2bc`, `operator_delete` payload `node[3]`, freelist-push node onto `hash+0x20`, clear head.
4. **Callee:** `operator_delete` (payload only — node recycled).
5. **Caller (1):** `FUN_00406fc0` DestroyBucketTable @ `0x00406fca` (`mov ebx,eax`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred` (Ghidra `FUN_004085e0`). Product demangle open → `_Inferred`.
8. **Twins / parents:** destroy `00406fc0` (sealed WQ9G-J); alloc `00406f20`; **not** tree++ neighbor `00408590`.
9. **Decompile ≡ raw CF**; EBX formal sealed via parent context + entry `mov eax,[ebx+0x10]`.

### Gaps

- Product / MSVC demangle for host CNDHash English type.  
- Typed payload dtor vs scalar delete.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004085e0_CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004085e0_CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004085e0_FUN_004085e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004085e0_FUN_004085e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004085e0.cpp` |
| Function | `docs/reconstruction/functions/aa_004085e0_FUN_004085e0.md` |
| Function named | `docs/reconstruction/functions/aa_004085e0_CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.md` |

---

## VA `0x00408050` — sealed facts

1. **Body:** `0x00408050`–`0x004082ed` exclusive (**669 B** / `0x29D`); last `C2 08 00`; pad `CC`; next InsertN12 `0x004082f0`.
2. **ABI:** **fastcall-ish**; **ECX**=vec*, **EDX**=value*; stack where + count; void; **ret 0x8**.
3. **Semantics:** MSVC-style **insert-n** for **0x28 POD**:
   - snap 10 dwords template
   - max-size `0x06666666` → `FUN_00418130`
   - grow 1.5× then size+count: prefix/Ufill/suffix relocate
   - else in-place near-end vs mid + assign-fill
4. **Stride:** **0x28** (div magic `0x66666667`).
5. **Callees:** Ufill `00406e50` (sealed); uninit_copy `00409ae0`; relocate `0040a520`; `00409b00`/`00409b20`; size `00437d80`; overflow `00418130`; new/delete.
6. **Caller (1):** `FUN_00406de0` InsertOne @ `0x00406e30` (`push 1; push where; mov ecx,edi; edx=value`).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_InsertN_Elem0x28_Inferred` (Ghidra `FUN_00408050`). Product demangle open → `_Inferred`.
9. **Twins (CF):** InsertN 0xC `004082f0` (ret 0xC thiscall); dword InsertN `004073a0`.
10. **Decompile ≡ raw CF**; RET + ECX/EDX formals sealed via `read_memory` + parent context.

### Gaps

- Product / POD English type (0x28 / 10 dwords).  
- Full dual of uninit_copy / mid-insert leaves.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00408050_StdVector_InsertN_Elem0x28_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00408050_StdVector_InsertN_Elem0x28_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00408050_FUN_00408050.md` |
| Annotated | `docs/reconstruction/raw/aa_00408050_FUN_00408050.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408050.cpp` |
| Function | `docs/reconstruction/functions/aa_00408050_FUN_00408050.md` |
| Function named | `docs/reconstruction/functions/aa_00408050_StdVector_InsertN_Elem0x28_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004085e0-00408050-wq9ha-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004085e0` | Port as **CNDHash freelist chain release** for host stamp `00a2c2bc`. **EBX**=hash; bare ret. Nested under destroy `00406fc0` only. Do **not** free table here. |
| `00408050` | Port as **shared vector insert-n** for **elem stride 0x28**. **ECX**=vec, **EDX**=value; **ret 8**. Pair with InsertOne `00406de0` + Ufill `00406e50`. |
| Pair with | sealed destroy/alloc stamp family; InsertN12 `004082f0`; dword InsertN; push_back `00406220`. |
| Naming caution | **Not** tree++ despite VA neighborhood of `00408590`. **Not** InsertN 0xC thiscall-3arg. **Not** skill thiscall freelist. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems residual table (`container` / util — freelist is CNDHash; InsertN is vector helper, not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004085e0`, `0x00408050`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decompiler unaff_EBX = real formal; `operator_delete` "noreturn" is false; freelist overwrites temporary vtbl stamp.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
