# Dual A/B report — R11-003 OWN-ONLY (`0x0055e1e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-003**  
**Scope:** VA `0x0055e1e0` (`aa_0055e1e0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-003**.  
**Work item:** Residual dual seal — soft-cast hit-list **controller fill wrapper** under dualed **Client_InteractWorldClickHub** (`0x00925820`); sole caller of dualed core `SoftCastHitList_CoreFillAndRegister_Inferred` (`0x006ca890`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0055e1e0` SoftCastHitList_ControllerFillWrapper_Inferred | **accept-with-gaps** — CF/ABI/RET0x8/local-entry+vtbl/sole-hub-caller sealed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): free-fn / decompiler-as-truth / merge-with-core / wrong RET / multi-caller / heap-alloc / payload-forward claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0055e1e0` — sealed facts

1. **Body:** `0x0055e1e0`–`0x0055e21f` inclusive (**64 B** / `0x40`); terminal **`C2 08 00`**; next `0x0055e220` = `XOR AX,AX; RET 0x10`.
2. **ABI:** **thiscall** — **ECX=controller***, stack **soft_desc / hit_list_backref**; void; **`RET 0x8`**.
3. **Semantics:** soft-cast hit-list **controller fill wrapper**:
   - 16-byte align + `SUB ESP,0x50` local frame.
   - Stack SoftCastHitEntry: vtbl **`0x009D27A8`**, pre-zero **`+0x44`**.
   - Core call: manager=`*(controller+0xC4)`, soft_desc, related=`*(controller+0xD0)`, payload **0**, backref.
4. **Caller (1):** dualed `Client_InteractWorldClickHub` / `FUN_00925820` @ `0x00925c32` (after ctor `0040c410`, before sort `0048a060`).
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Callees:** `SoftCastHitList_CoreFillAndRegister_Inferred` / `FUN_006ca890` (dualed MEGA-062) @ `0x0055e215`.
7. **Family:** dualed ctor `0040c410`, core `006ca890`, sort `0048a060`, qsort `00489f20`. **Do not merge** with any of them.
8. **Name:** `SoftCastHitList_ControllerFillWrapper_Inferred` (Ghidra `FUN_0055e1e0`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF** for collapsed call shape; **assembly corrects** local-entry this + vtbl (decompiler incomplete, not CF conflict on return path).
10. **Partition parent** `0x006ca890` is the dualed core callee (score parent); **live structural caller** is hub `0x00925820`.

### Gaps

- Product English for controller class / fields `+0xC4` / `+0xD0`.  
- Full vtbl `0x009D27A8` method map.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0055e1e0_SoftCastHitList_ControllerFillWrapper_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0055e1e0_SoftCastHitList_ControllerFillWrapper_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_0055e1e0_FUN_0055e1e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0055e1e0_FUN_0055e1e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_ControllerFillWrapper_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055e1e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0055e1e0_FUN_0055e1e0.md` |
| Function named | `docs/reconstruction/functions/aa_0055e1e0_SoftCastHitList_ControllerFillWrapper_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_InteractWorldClickHub  FUN_00925820  [dualed]
  ├─ SoftCastHitList_CtorInitBuffer_Inferred       0x0040c410  [dualed MEGA-111]
  ├─ SoftCastHitList_ControllerFillWrapper_Inferred 0x0055e1e0  [OWN R11-003]
  │    └─ SoftCastHitList_CoreFillAndRegister_Inferred 0x006ca890  [dualed MEGA-062]
  ├─ SoftCastHitList_SortIfCountGt1_Inferred       0x0048a060  [dualed MEGA-116]
  │    └─ SoftCastHitList_QuickSortRange_KeyFloat14_Inferred 0x00489f20  [dualed]
  └─ walk → FUN_0040afb0  resolve object*  [residual]
```

Partition host "interaction-activation" matches soft-cast world-click hit-list role.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0055e1e0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0055e1e0` | Port as **controller soft-cast fill wrapper**. **thiscall RET 0x8**. Preserve local stack entry + vtbl `0x009D27A8`, manager@+0xC4, related@+0xD0, payload hard 0, 16-byte align. Do **not** merge with core `006ca890`. |
| Distinct from | Core fill+register `006ca890`; sort gate `0048a060`; list ctor `0040c410`. |
| Pair with | dualed hub `00925820`; dualed core `006ca890`; dualed sort `0048a060`; dualed ctor `0040c410`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `SoftCastHitList_ControllerFillWrapper_Inferred` @ `0x0055e1e0` / `aa_0055e1e0`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x0055e1e0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + hub call-site context. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall RET 0x8; local entry + vtbl; decompiler free-call shape rejected).
- Odd behavior preserved: payload always 0; pre-zero entry+0x44; 16-byte align; ECX clobber sequence manager→entry.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
