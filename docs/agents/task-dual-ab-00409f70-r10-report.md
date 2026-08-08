# Dual A/B report — R10-023 OWN-ONLY (`0x00409f70`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-023**  
**Scope:** VA `0x00409f70` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `read_memory` + `analyze_control_flow`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — PodCopy 4 dwords / 0x10 leaf (partition interaction-activation; parent ConstructN `0x00409e20`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409f70` StdVector_PodCopyElement_0x10_Inferred | **accept-with-gaps** — leaf CF/ABI/4-dword/0x10/null-dst/2 callers sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): EAX/EDX-merge-on-0x28 / thiscall / ConstructN-as-leaf / PollBound-product / 3-or-10-dword / non-POD / `ret N` claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409f70` — sealed facts

1. **Body:** `0x00409f70`–`0x00409f8a` inclusive (**27 B** / `0x1B`); pad `CC` after.
2. **ABI:** **EAX** = dest `T*`; **ECX** = src `const T*`; plain **`ret`** (`C3`). No stack args.
3. **Semantics:** Null-dst no-op; else copy **4 dwords** (16 B / **0x10**) at offsets 0/4/8/0xC.
4. **Bytes:** `85 C0 74 16 8B 11 89 10 8B 51 04 89 50 04 8B 51 08 89 50 08 8B 49 0C 89 48 0C C3`.
5. **Callees:** none (leaf).
6. **Callers (2):** UNCONDITIONAL_CALL
   - `FUN_00409e20` ConstructN Elem0x10 @ `0x00409e58` (`MOV ECX,EBX` template; `MOV EAX,ESI` dest; dest `+0x10`)
   - `FUN_0040a670` uninit_copy Elem0x10 @ `0x0040a6a8` (`MOV ECX,ESI` src; `MOV EAX,EDI` dest; both `+0x10`; returns end dest)
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_PodCopyElement_0x10_Inferred` (Ghidra `FUN_00409f70`). Product demangle open → `_Inferred`. Scaffold `Named_CalleeOf_*Cli_00409f70` **retired**.
9. **Twins (CF):** ConstructN parent `00409e20` (MEGA-044 dualed); peer PodCopy 0x28 `00409f30` (**EAX/EDX**); peer PodCopy Elem12 `00409f50` (**EAX/ECX**, 3 dwords).
10. **Decompile ≡ raw CF**; register ABI sealed via `read_memory` + call-site disassembly (ECX src, not EDX).

### Gaps

- Product / MSVC demangle for 0x10 POD element type.  
- Full dual of range worker `FUN_0040a670` (role sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409f70_StdVector_PodCopyElement_0x10_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409f70_StdVector_PodCopyElement_0x10_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409f70_FUN_00409f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00409f70_FUN_00409f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PodCopyElement_0x10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409f70.cpp` |
| Scaffold retired | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00409f70.cpp` |
| Function | `docs/reconstruction/functions/aa_00409f70_FUN_00409f70.md` |
| Function named | `docs/reconstruction/functions/aa_00409f70_StdVector_PodCopyElement_0x10_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00408640  StdVector_InsertN_Elem0x10_Inferred  [dualed prior]
  └─ FUN_00407000  construct-N wrapper → end = dest+count*0x10  [residual R10-007]
       └─ FUN_00409e20  StdVector_ConstructN_Elem0x10_Inferred  [MEGA-044 dualed]
            └─ FUN_00409f70  StdVector_PodCopyElement_0x10_Inferred  [OWN R10-023]

FUN_0040a670  uninit_copy / range step +0x10  [residual]
  └─ FUN_00409f70  StdVector_PodCopyElement_0x10_Inferred  [OWN R10-023]
       (callers of range: FUN_00408640 InsertN; FUN_00409b60)
```

Partition map row: R10-023 | `0x00409f70` | interaction-activation | parent `0x00409e20`.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409f70-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409f70` | Port as **shared POD element copy** for **0x10-byte** elements. **EAX=dest**, **ECX=src**, plain **RET**. Null dest → no-op. Four dword stores (or `memcpy` 0x10). |
| Pair with | dualed ConstructN `00409e20`; dualed InsertN `00408640`; residual range `0040a670`; residual wrapper `00407000`. |
| Do **not** | merge ABI with PodCopy 0x28 `00409f30` (EDX src / 10 dwords); merge size with Elem12 PodCopy `00409f50` (3 dwords); treat as PollBound / input leaf; invent product English type. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable
- progress inventory entry for R10-023 **accept-with-gaps**
