# Dual A/B report — R10-008 OWN-ONLY (`0x00409b40`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-008**  
**Scope:** VA `0x00409b40` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; parent ledgers; other VAs; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `disassemble_function` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-008**.  
**Work item:** residual dual seal — uninit_copy **trampoline Elem12** (parent dual `0x0040a590`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409b40` StdVector_UninitCopyTrampoline_Elem12_Inferred | **accept-with-gaps** — CF/ABI/RET8/EDX dest/target 0040a590/InsertN sites sealed; product T open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): real-loop-as-trampoline / thiscall-as-member / void-return / merge-with-0x28 / cdecl-RET claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409b40` — sealed facts

1. **Body:** `0x00409b40`–`0x00409b5a` inclusive (**27 B** / `0x1b`); pad `CC`.
2. **ABI:** **ECX** = host/this (unused by target); **EDX** = dest; stack `src_begin`, `src_end`; **EAX** = dest_end; **`RET 8`**. Decompiler incomplete (3-param fastcall void, no RET 8).
3. **Semantics:** thin trampoline → dualed `StdVector_UninitializedCopy_Elem12_Inferred` (`0x0040a590`):
   - Reorder to free-helper layout (`ECX=end`, stack begin+dest).
   - Push 4 dwords + `ADD ESP,0x10` (extras ignored by target).
   - No element loop of its own.
4. **Bytes:** `8B442404 50 8B442408 51 8B4C2410 52 50 E83B0A0000 83C410 C20800`.
5. **Callees:** `FUN_0040a590` only.
6. **Callers (1 func / 2 sites):** InsertN grow `FUN_004082f0` @ `0x00408413` (prefix), `0x0040843a` (suffix).
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_UninitCopyTrampoline_Elem12_Inferred` (Ghidra `FUN_00409b40`). Product open → `_Inferred`.
9. **Twin:** byte-identical shape to `0x00409ae0` (Elem0x28 trampoline) except CALL relative.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + call-site context + `read_memory`.

### Gaps

- Product / MSVC demangle for 0x0C element type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409b40_StdVector_UninitCopyTrampoline_Elem12_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409b40_StdVector_UninitCopyTrampoline_Elem12_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409b40_FUN_00409b40.md` |
| Annotated | `docs/reconstruction/raw/aa_00409b40_FUN_00409b40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitCopyTrampoline_Elem12_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409b40.cpp` |
| Function | `docs/reconstruction/functions/aa_00409b40_FUN_00409b40.md` |
| Function named | `docs/reconstruction/functions/aa_00409b40_StdVector_UninitCopyTrampoline_Elem12_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00409b40-r10-report.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004082f0  StdVector_InsertN_Elem12_Inferred  [dualed WQ9H-B]
  ├─ FUN_00409b40  StdVector_UninitCopyTrampoline_Elem12_Inferred  [OWN R10-008]
  │     └─ FUN_0040a590  StdVector_UninitializedCopy_Elem12_Inferred  [dualed WQ9K-J / parent dual]
  │           └─ FUN_00409f50  PodCopy Elem12  [dualed]
  ├─ FUN_00406ee0  Ufill  [dualed]
  └─ direct FUN_0040a590 on non-grow paths

Twin family (0x28):
FUN_00408050  InsertN 0x28
  └─ FUN_00409ae0  UninitCopyTrampoline Elem0x28  [dualed WQ9K-A]
        └─ FUN_0040a520  UninitializedCopy Elem0x28
```
