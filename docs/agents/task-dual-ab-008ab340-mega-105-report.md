# Dual A/B report — MEGA-105 OWN-ONLY (`0x008ab340`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-105**  
**Scope:** VA `0x008ab340` (`aa_008ab340`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Role hint:** Select-mission list row helper (partition: destroy/clear of two row-widget vectors).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory` + `get_function_by_address` + parent decompile/disasm. **No** `disassemble_bytes` primary.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008ab340` MissionSelect_ClearRowWidgetVectors_Inferred | **accept-with-gaps** — ESI ABI, 521 B body, dual-vector destroy/clear, ordinals, 3 call sites sealed; product English + bank A/B roles open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): build-rows / fixed-8 / ECX-this / buffer-free / sole-caller / Named_CalleeOf product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008ab340` — sealed facts

1. **Body:** `0x008ab340`–`0x008ab549` exclusive (**521 B** / `0x209`); RET @ `0x008ab548`; pad `CC` before next.
2. **ABI:** **ESI = mission-select host***; no stack args; plain **`RET`**. Frame `PUSH ECX/EBX/EBP/EDI` … `POP EDI/EBP/EBX/ECX`.
3. **Semantics:** destroy-and-clear two `T**` MSVC vectors on the host:
   - Vector A: begin **`+0x72c`**, end **`+0x730`**
   - Vector B: begin **`+0x73c`**, end **`+0x740`**
   - Per non-null widget: **vtbl+0x3d8** (bool) → optional **+0x440**; if `widget+0x2b0≠0` host **vtbl+0xB0**(w); **vtbl[0](1)** dtor; zero slot; then **end = begin**.
4. **Classification:** worker.
5. **Callers (3 UNCONDITIONAL_CALL):**
   - `FUN_008ab550` @ `008ab6c4` (show-path early return)
   - `FUN_008ab550` @ `008ab791` (hide-path fallthrough)
   - `FUN_008ac340` @ `008ac36c` (host dtor, before `operator_delete`)
6. **Callees:** `memmove` (IAT `0x009c652c`); virtuals only otherwise.
7. **Name:** `MissionSelect_ClearRowWidgetVectors_Inferred` (Ghidra `FUN_008ab340`). Product map open → `_Inferred`. Scaffold `Named_CalleeOf_Mission_Select_a_Mission_008ab340` **retired**.
8. **Decompile ≡ raw CF**; ABI/offset sealed via `disassemble_function` + `read_memory` + caller framing (`MOV ESI,ECX`).

### Gaps

- Product/PDB English.  
- Product names for vtbl +0x3d8 / +0x440 / host +0xB0.  
- Semantic split vector A vs B.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008ab340_MissionSelect_ClearRowWidgetVectors_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008ab340_MissionSelect_ClearRowWidgetVectors_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008ab340_FUN_008ab340.md` |
| Annotated | `docs/reconstruction/raw/aa_008ab340_FUN_008ab340.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionSelect_ClearRowWidgetVectors_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008ab340.cpp` |
| Function | `docs/reconstruction/functions/aa_008ab340_FUN_008ab340.md` |
| Function named | `docs/reconstruction/functions/aa_008ab340_MissionSelect_ClearRowWidgetVectors_Inferred.md` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Mission_Select_a_Mission_008ab340.cpp` |

---

## Chain context (not dualled; evidence only)

```text
FUN_008ab550  Mission_Select_a_Mission / multi-mission panel  [residual MEGA-051]
  ├─ "Select a Mission:" plate @ 0xa4aba0
  ├─ mode @ host+0x648 (0/1/2/3)
  ├─ CALL FUN_008ab340 @ 008ab6c4   [OWN MEGA-105]
  └─ CALL FUN_008ab340 @ 008ab791   [OWN MEGA-105]

FUN_008ac340  host dtor  [residual]
  ├─ CALL FUN_008ab340 @ 008ac36c   [OWN MEGA-105]
  ├─ operator_delete(vector B begin +0x73c); zero begin/end/cap
  ├─ operator_delete(vector A begin +0x72c); zero begin/end/cap
  └─ FUN_00792c20 base dtor
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008ab340-mega-105-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008ab340` | Port as **destroy-and-clear** of two host list-row widget `vector<T*>` banks. **ESI = host**, plain RET. Per element: query +0x3d8, optional +0x440, host +0xB0 if +0x2b0, dtor(1), null slot; then end=begin. Do **not** free capacity here. |
| Pair with | residual parent `FUN_008ab550` (Select-a-Mission); residual dtor `FUN_008ac340`; peer clear `MissionDialog_ClearResponseButtonSlots_Inferred` (`008aa560`) is a **different** fixed-8 EBX bank. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers if applicable

**Terminal:** false.
