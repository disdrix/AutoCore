# Dual A/B report — R13-028 OWN-ONLY (`0x00507350`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-028**  
**Scope:** VA `0x00507350` (`aa_00507350`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent SubInit `00581190` re-dual, scalar deleting `005073f0`, derived dtors).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-028**.  
**System:** interaction-activation.  
**Parent dual:** `0x00581190` `VOGPhysics_QueryObject_SubInit_Inferred` (R12-027).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00507350` VOGPhysics_QueryObject_Dtor_Inferred | **accept-with-gaps** — CF/ABI/RET0/linked-release/pool-free/flag-clear/vtbl-cycle sealed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): fastcall-not-thiscall / scalar-dtor-merge / always-free / self-refcount / TtPhantom-merge / stack-RET / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00507350` — sealed facts

1. **Body:** `0x00507350`–`0x005073bd` inclusive (**110 B** / `0x6E`); exclusive end `0x005073be`; pad `CC CC`.
2. **ABI:** **`__thiscall`** ECX=self; **no stack args**; **`ret 0`** (`C3` @ `0x005073bd`). Ghidra decompiler labels `__fastcall` for single-ECX thiscall.
3. **Semantics:** query-object / shared base header **body dtor** (provisional vtbl family `009cd99c`):
   - Install provisional vtbl `PTR_FUN_009cd99c`.
   - Release `linked_obj*` @ **`+0x0C`**: dec short refcount @ linked **`+0x06`**; if zero → `vtbl[0](1)`.
   - If capacity @ **`+0x38`** signed ≥ 0: pool-free buffer @ **`+0x30`**, size `(cap & 0x7FFFFFFF)*8`, tag **`0x12`** via `(*DAT_00b05060)[+0x14]`.
   - Install mid vtbl `PTR_FUN_009d81e8`.
   - If flag word @ **`+0x04`** high bit set: clear low 15 bits; `FUN_005ffdb0(this, 0)`.
   - Install base vtbl `PTR_LAB_009cc290`.
4. **Layout pair:** matches dualed SubInit `00581190` (refcount@+6, link@+0x0C, self@+0x2C, empty cap `0x80000000`@+0x38).
5. **Callees:** `FUN_005ffdb0`; linked `vtbl[0](1)`; `(*DAT_00b05060)[+0x14]`.
6. **Callers (3):** `FUN_005073f0` @ `0x005073f3` (scalar deleting); `FUN_005074d0` @ `0x005075b7`; `FUN_006343d0` @ `0x0063443e`.
7. **Xrefs:** 3 UNCONDITIONAL_CALL (same).
8. **Name:** `VOGPhysics_QueryObject_Dtor_Inferred` (Ghidra `FUN_00507350`). Product demangle open → `_Inferred`. Scaffold `Named_CalleeOf_*Cli_00507350` **retired**.
9. **Decompile ≡ raw CF**; free-path AND+*8 and thiscall `FUN_005ffdb0` sealed via `read_memory` + analyze disasm.

### Gaps

- Product / PDB English for class / three vtbl stages.  
- Dual of scalar deleting `FUN_005073f0` and derived chain parents.  
- Exact dual-role of flag word @ +4 (ownership vs size for scalar free).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00507350_VOGPhysics_QueryObject_Dtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00507350_VOGPhysics_QueryObject_Dtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00507350_FUN_00507350.md` |
| Annotated | `docs/reconstruction/raw/aa_00507350_FUN_00507350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_QueryObject_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00507350.cpp` |
| Function | `docs/reconstruction/functions/aa_00507350_FUN_00507350.md` |
| Function named | `docs/reconstruction/functions/aa_00507350_VOGPhysics_QueryObject_Dtor_Inferred.md` |

**Retired scaffold clean (do not promote):**  
`docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00507350.cpp`

---

## Chain context (not dualled here; evidence only)

```text
FUN_005eb210  VOGPhysics_QueryObject_BaseCtor_Inferred  [R11-008 dualed]
  └─ FUN_00581190  VOGPhysics_QueryObject_SubInit_Inferred  [R12-027 dualed — parent]
       └─ provisional vtbl 009cd99c / layout through +0x38

FUN_00507350  VOGPhysics_QueryObject_Dtor_Inferred  [OWN R13-028]
  ├─ release linked @ +0x0C
  ├─ pool free buffer @ +0x30 (tag 0x12)
  └─ FUN_005ffdb0 flag clear

FUN_005073f0  scalar deleting wrapper  [residual]
  └─ FUN_00507350 then optional free self (tag 0x10)

FUN_005074d0 / FUN_006343d0  derived dtors  [residual]
  └─ chain into FUN_00507350

Same-vtbl peer ctor FUN_005f5760  [residual]
```

Partition system **interaction-activation** matches parent query-object / GetObjectsInArea chain (not a product interact packet name for this unit).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00507350-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00507350` | Port as **query-object base body dtor**. **`__thiscall`** ECX=self; **RET 0**. Release linked @ +0x0C only; free buffer when cap@+0x38 signed ≥ 0 with size `(cap&0x7FFFFFFF)*8` tag `0x12`; three-phase vtbl `009cd99c` → `009d81e8` → `009cc290`; flag clear via `FUN_005ffdb0(this,0)`. |
| Pair with | dualed SubInit `00581190`; residual scalar deleting `005073f0`; residual derived dtors `005074d0` / `006343d0`; dualed base ctor `005eb210`. |
| Naming caution | **Not** scalar deleting. **Not** full query base ctor teardown. **Not** TtPhantom. **Not** Runtime Confirmed. Product English open → `_Inferred`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/interaction-activation.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00507350`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (thiscall RET 0; `FUN_005ffdb0` this).  
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
