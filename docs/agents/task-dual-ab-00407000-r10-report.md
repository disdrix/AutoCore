# Dual A/B report — R10-007 OWN-ONLY (`0x00407000`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-007**  
**Scope:** VA `0x00407000` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-007**.  
**Work item:** Residual dual seal — undualed callee of dualed InsertN / ConstructN elem 0x10.  
**Hint retired:** `Named_CalleeOf_*Cli_00407000` chain plate.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00407000` StdVector_UninitializedFillN_Elem0x10_Inferred | **accept-with-gaps** — customcc EDI/ESI + stack value* / ret 4 / construct-N call / end = dest+count×0x10 sealed; product demangle open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): InsertOne / uninit-copy-range / void-ABI / wrong-stride / thiscall-dest / grow / plain-ret / always-1 / merge-with-construct-N / merge-with-InsertN / input-poll product claims **falsified**; chain-of-caller scaffold **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00407000` — sealed facts

1. **Body:** `0x00407000`–`0x0040701d` exclusive (**29 B** / `0x1d`); terminal **`C2 04 00`**; pad `CC` to `0x00407020`.
2. **ABI:** customcc — **EDI**=dest*, **ESI**=count, stack `const T* value`; **RET 4**; EAX = dest + count×0x10. **Not** thiscall; **not** void.
3. **Semantics:** MSVC-style **uninitialized_fill_n** for **16-byte** POD:
   - Phantom-push wrapper into construct-N (`add esp,0x10` after call).
   - Callee `FUN_00409e20` (`StdVector_ConstructN_Elem0x10_Inferred`, dualed MEGA-044): SEH + loop PodCopy 4 dwords via `FUN_00409f70`, dest += 0x10.
   - Return advanced end pointer only — no grow / free / insert policy.
4. **Caller (1):** dualed InsertN `FUN_00408640` @ `0x00408746` (realloc fill) and `0x0040880c` (in-place hole fill).
5. **Xrefs:** 2 UNCONDITIONAL_CALL.
6. **Callees:** `FUN_00409e20` only (→ residual PodCopy `00409f70`).
7. **Family:** twins Ufill elem0xC `00406ee0`, elem0x28 `00406e50`; construct-N `00409e20`; InsertN `00408640`. **Do not merge** with construct-N or InsertN.
8. **Name:** `StdVector_UninitializedFillN_Elem0x10_Inferred` (Ghidra `FUN_00407000`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; `unaff_ESI/EDI` are register formals sealed via disasm + parent call sites.

### Gaps

- Product / MSVC demangle for 16-byte POD `T`.  
- PodCopy leaf `FUN_00409f70` undualed (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00407000_StdVector_UninitializedFillN_Elem0x10_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00407000_StdVector_UninitializedFillN_Elem0x10_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00407000_FUN_00407000.md` |
| Annotated | `docs/reconstruction/raw/aa_00407000_FUN_00407000.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedFillN_Elem0x10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00407000.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00407000.cpp` |
| Function | `docs/reconstruction/functions/aa_00407000_FUN_00407000.md` |
| Function named | `docs/reconstruction/functions/aa_00407000_StdVector_UninitializedFillN_Elem0x10_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00408640  StdVector_InsertN_Elem0x10_Inferred  [dualed]
  ├─ FUN_00409b60 / FUN_0040a670  uninit-copy relocate  [residual]
  ├─ FUN_00407000  StdVector_UninitializedFillN_Elem0x10_Inferred  [OWN R10-007]
  │     └─ FUN_00409e20  StdVector_ConstructN_Elem0x10_Inferred  [dualed MEGA-044]
  │           └─ FUN_00409f70  PodCopy 4 dwords / +0x10  [residual]
  └─ operator_new / operator_delete  [CRT]

Twin Ufill wrappers (not OWN):
  0x00406ee0  StdVector_UninitializedFillN_Elem12_Inferred  [dualed]
  0x00406e50  StdVector_UninitializedFillN_Elem0x28_Inferred
```

Partition system **interaction-activation** names the **host residual parent score chain**, not this leaf's product role (generic container Ufill).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00407000-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00407000` | Port as **`uninitialized_fill_n`** for **16-byte** POD vector elements. **customcc**: EDI=dest, ESI=count, stack value*; **ret 4**; EAX=end. |
| Pair with | dualed construct-N `00409e20`; dualed InsertN `00408640`; residual PodCopy `00409f70`. |
| Distinct from | construct-N itself (no end return); InsertN (no growth); Ufill 0xC / 0x28 siblings. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `StdVector_UninitializedFillN_Elem0x10_Inferred` @ `0x00407000` / `aa_00407000`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00407000`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + callee/parent decompiles. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (EDI/ESI + stack value*; ret 4; decompiler void/unaff fixed).
- Odd behavior preserved: phantom pushes + `add esp,0x10`; ECX entry value discarded (reloaded from stack).
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
