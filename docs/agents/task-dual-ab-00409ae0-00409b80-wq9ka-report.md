# Dual A/B report — WQ9K-A OWN-ONLY (`0x00409ae0`, `0x00409b80`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9K-A**  
**Scope:** VAs `0x00409ae0`, `0x00409b80` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-A**.  
**Work item:** WQ-009 depth-8 residual dual seal — **uninit_copy trampoline** + **string destroy @+0x0c for free-subtree**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409ae0` StdVector_UninitCopyTrampoline_Elem0x28_Inferred | **accept-with-gaps** — CF/ABI/RET8/EDX dest/target 0040a520/InsertN sites sealed; product T open |
| `aa_00409b80` StdTree_DestroyStringAt0C_Inferred | **accept-with-gaps** — CF/ABI/RET4/string@+0x0c/SEH/shared free-subtree callers sealed; product map open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): real-loop-as-trampoline / thiscall-on-dtor / full-node-dtor / cdecl-RET / merge-with-Elem12 / free-as-destroy claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409ae0` — sealed facts

1. **Body:** `0x00409ae0`–`0x00409afa` inclusive (**27 B** / `0x1b`); pad `CC`.
2. **ABI:** **ECX** = host/this (unused by target); **EDX** = dest; stack `src_begin`, `src_end`; **EAX** = dest_end; **`RET 8`**. Decompiler incomplete (3-param fastcall, no RET 8).
3. **Semantics:** thin trampoline → dualed `StdVector_UninitializedCopy_Elem0x28_Inferred` (`0x0040a520`):
   - Reorder to free-helper layout (`ECX=end`, stack begin+dest).
   - Push 4 dwords + `ADD ESP,0x10` (extras ignored by target).
   - No element loop of its own.
4. **Bytes:** `8B442404 50 8B442408 51 8B4C2410 52 50 E82B0A0000 83C410 C20800`.
5. **Callees:** `FUN_0040a520` only.
6. **Callers (2):** InsertN grow `FUN_00408050` @ `0x00408171` (prefix), `0x00408198` (suffix).
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_UninitCopyTrampoline_Elem0x28_Inferred` (Ghidra `FUN_00409ae0`). Product open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + call-site context + `read_memory`.

### Gaps

- Product / MSVC demangle for 0x28 element type.  
- Full dual of parent InsertN `00408050` (role sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409ae0_StdVector_UninitCopyTrampoline_Elem0x28_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409ae0_StdVector_UninitCopyTrampoline_Elem0x28_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409ae0_FUN_00409ae0.md` |
| Annotated | `docs/reconstruction/raw/aa_00409ae0_FUN_00409ae0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitCopyTrampoline_Elem0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409ae0.cpp` |
| Function | `docs/reconstruction/functions/aa_00409ae0_FUN_00409ae0.md` |
| Function named | `docs/reconstruction/functions/aa_00409ae0_StdVector_UninitCopyTrampoline_Elem0x28_Inferred.md` |

---

## VA `0x00409b80` — sealed facts

1. **Body:** `0x00409b80`–`0x00409bc0` inclusive (**65 B** / `0x41`); pad `CC`.
2. **ABI:** stack `node*`; void; **`RET 4`** (**stdcall**). Decompiler shows cdecl-ish without cleanup.
3. **Semantics:** free-subtree **value destroy**:
   - SEH frame (`LAB_009bc656` / FS:[0]).
   - `ECX = node + 0x0c`; IAT `~std::basic_string` (`[0x009c62f4]`).
   - Unlink SEH; RET 4.
   - Does **not** free node / walk children / touch isnil.
4. **Callers (2):** FreeSubtree isnil131 `FUN_00409920` @ `0x00409942`; FreeSubtree isnil2d `FUN_00409970` @ `0x0040998f` — both dualed WQ9J-I; pattern `PUSH node → this → PUSH node → operator_delete`.
5. **Xrefs:** 2 UNCONDITIONAL_CALL.
6. **Callees:** `~basic_string` IAT only.
7. **Name:** `StdTree_DestroyStringAt0C_Inferred` (Ghidra `FUN_00409b80`). Product map open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/offset sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product map/key RTTI beyond string @+0x0c.  
- Erase-range parents `00407b70` / `00407f90` residual (WQ9K-B OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409b80_StdTree_DestroyStringAt0C_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409b80_StdTree_DestroyStringAt0C_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409b80_FUN_00409b80.md` |
| Annotated | `docs/reconstruction/raw/aa_00409b80_FUN_00409b80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_DestroyStringAt0C_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409b80.cpp` |
| Function | `docs/reconstruction/functions/aa_00409b80_FUN_00409b80.md` |
| Function named | `docs/reconstruction/functions/aa_00409b80_StdTree_DestroyStringAt0C_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00408050  InsertN / reallocate elem 0x28  [residual]
  ├─ FUN_00409ae0  StdVector_UninitCopyTrampoline_Elem0x28_Inferred  [OWN WQ9K-A]
  │     └─ FUN_0040a520  StdVector_UninitializedCopy_Elem0x28_Inferred  [dualed WQ9J-A]
  │           └─ FUN_00409f30  PodCopy 0x28  [dualed WQ9I-B]
  ├─ FUN_00406e50  Ufill  [dualed]
  └─ direct FUN_0040a520 on non-grow paths

FUN_00407b70  erase-range full clear isnil131  [residual WQ9K-B]
  └─ FUN_00409920  FreeSubtree isnil@+0x131  [dualed WQ9J-I]
        ├─ self (right)
        ├─ FUN_00409b80  StdTree_DestroyStringAt0C_Inferred  [OWN WQ9K-A]
        └─ operator_delete

FUN_00407f90  erase-range full clear isnil2d  [residual WQ9K-B]
  └─ FUN_00409970  FreeSubtree isnil@+0x2d  [dualed WQ9J-I]
        ├─ self (right)
        ├─ FUN_00409b80  (shared)  [OWN WQ9K-A]
        └─ operator_delete
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409ae0-00409b80-wq9ka-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409ae0` | Port as **ABI trampoline only** into UninitCopy 0x28. **ECX** host unused, **EDX** dest, stack begin/end, **RET 8**, EAX=dest_end. Do **not** reimplement the 0x28 loop here. Keep distinct from free-helper entry `0040a520` and Elem12 range `0040a590`. |
| `00409b80` | Port as **string-only node value destroy** @ **+0x0c**. **stdcall RET 4**. Pair with free-subtree twins `00409920`/`00409970` (call then `operator_delete`). Not a full node dtor; not free-subtree walk. |
| Pair with | dualed UninitCopy `0040a520` / PodCopy `00409f30` / FreeSubtree isnil twins; residual InsertN `00408050`; residual erase parents `00407b70`/`00407f90` (WQ9K-B). |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (STL vector trampoline + tree string dtor residual — not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00409ae0`, `0x00409b80`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names; machine ABI corrections (RET 8 trampoline; stdcall string dtor).  
- Odd behavior preserved: unused host ECX push; 4-arg glue with 2-arg target; string-only destroy.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
