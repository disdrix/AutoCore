# Dual A/B report — MEGA-082 OWN-ONLY (`0x00401c30`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-082**  
**Scope:** VA `0x00401c30` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — Drive vehicle-name invalid plate nested leaf (input-drive-control partition seed).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00401c30` StdVector_DwordSize_EaxVec_Inferred | **accept** — CF/ABI/EAX-vec/RET/null-begin/SAR2/leaf/11 xrefs sealed; plate Named_CalleeOf retired |

Path A (fidelity): **accept**.  
Path B (adversarial): vehicle-name-only / ECX-thiscall-merge / capacity / non-4-stride / SkillSet-merge claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00401c30` — sealed facts

1. **Body:** `0x00401c30`–`0x00401c42` inclusive (**19 B** / `0x13`); pad `CC` after.
2. **ABI:** **EAX** = vector/container; bare **`RET`** (`C3`) ×2 exits; size in **EAX**.
3. **Semantics:** null-safe dword-vector size:
   - `begin = *(vec+4)`; if 0 → return 0.
   - `end = *(vec+8)`; return `(end - begin) >> 2`.
   - Capacity not read; leaf (no callees).
4. **Bytes:** `8B 48 04 85 C9 75 03 33 C0 C3 8B 40 08 2B C1 C1 F8 02 C3`.
5. **Callees:** none.
6. **Callers / xrefs:** **11** UNCONDITIONAL_CALL:
   - `FUN_008b6eb0` @ `008b6f5e` / `008b6f7b`
   - `FUN_008d4910` @ `008d516f` / `008d518a` (plate parent of `"Your Vehicle Name Is Invalid!  Please Choose Another!"` @ `0x00a3fba4`, case `0x9c45`)
   - orphan sites `0090593e` / `009059de` / `00905a2b`, `008a463c` / `008a4674` / `008a4781` / `008a47b4` (assembly context sealed; all `MOV EAX,<vec>` before CALL)
7. **Twin:** dualed `StdVector_DwordSize` `0x004024b0` (same formula; **ECX** = vec).
8. **Name:** `StdVector_DwordSize_EaxVec_Inferred` (Ghidra `FUN_00401c30`). Product element English open → `_Inferred`. Retire Named_CalleeOf plate scaffold.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product host/element English (structural name only).  
- Orphan xref enclosing-function recovery.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00401c30_StdVector_DwordSize_EaxVec_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00401c30_StdVector_DwordSize_EaxVec_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00401c30_FUN_00401c30.md` |
| Annotated | `docs/reconstruction/raw/aa_00401c30_FUN_00401c30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DwordSize_EaxVec_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00401c30.cpp` |
| Function | `docs/reconstruction/functions/aa_00401c30_FUN_00401c30.md` |
| Function named | `docs/reconstruction/functions/aa_00401c30_StdVector_DwordSize_EaxVec_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_008d4910  Drive_Your_Vehicle_Name_Is_Invalid plate parent  [scaffold seed]
  └─ case 0x9c45:
        LEA ESI, [host+0x8dc]
        FUN_00401c30  StdVector_DwordSize_EaxVec_Inferred  [OWN MEGA-082]
        if size > 1: random + FUN_008d2650 + FUN_008d19f0 …

FUN_008b6eb0  UI list host  [residual]
  └─ FUN_00401c30 ×2  (size vs scroll index @ +0x520)

Twin (dualed earlier):
  FUN_004024b0  StdVector_DwordSize  [ECX ABI]  — do not merge
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00401c30-mega-082-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00401c30` | Port as **null-safe dword-vector size** helper. **EAX = vec**, bare **RET**, size in **EAX**. Formula `(end-begin)/4` with begin@+4 / end@+8. Keep **distinct** from ECX twin `004024b0`. Do **not** bind ownership to vehicle-name plate English. |
| Pair with | dualed `StdVector_DwordSize` `004024b0`; residual plate parent `008d4910`; residual UI host `008b6eb0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (containers / input-drive-control seed context)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00401c30`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + parent plate decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name; machine ABI correction (EAX not ECX; bare RET).  
- Odd behavior preserved: null begin → 0; decompiler phantom `in_EAX` corrected via assembly.  
- `_Inferred` where product element English unproven. Named_CalleeOf scaffold retired. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
