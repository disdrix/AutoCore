# Dual A/B report — MEGA-122 OWN-ONLY (`0x00797530`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-122**  
**Scope:** VA `0x00797530` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `get_function_by_address` / signature. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — **UiTextLayout finalize** (callee of dualed complete dtor `0x00797d70`).  
**Partition hint:** `UiTextLayout_Finalize` / system skills-abilities (UI text layout ownership).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00797530` UiTextLayout_Finalize_Inferred | **accept-with-gaps** — CF/ABI/EBX-this/RET4/flag gate/offset map/finalize-not-dtor sealed; product demangle open → `_Inferred` |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): complete-dtor-merge / ECX-thiscall / bare-RET / packet-RecvBroadcast / always-mode3 / host-free claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00797530` — sealed facts

1. **Body:** `0x00797530`–`0x00797987` inclusive (**1112 B** / `0x458`); Ghidra exclusive end `0x00797988`; `CC` pad before `FUN_00797990` @ `0x00797990`.
2. **ABI:** **EBX** = layout\* (custom register this); stack `char flag`; SEH `LAB_009add2c`; void; **`RET 4`** (`C2 04 00` @ `0x00797985`).
3. **Semantics:** **finalize / flush** of owned text-layout block:
   - Trim trailing `L' '` (0x20) on embedded `wstring` @ `+0x0C`; decrement count @ `+0xB0`.
   - Alignment mode @ `+0xCC`: **1** half via `DAT_00a0f298` (**0.5f**), **2** full, **3** line-height @ `+0x08` only when **flag==0**.
   - Multi-run (`+0x94` stride **0x60**, count>1): build display runs into vector @ `+0x80` (stride **0x80**) via `FUN_004275b0` / `FUN_00427a40`; skip single-run path.
   - Single-run: `FUN_00426ff0` + 8-dword style copy to `+0x60`; cache `+0xC4/+0xC0` → `+0x2C/+0x28`; `FUN_00427050`.
   - Epilogue: `y@+0x04 += (int)float@+0xAC`; `ready@+0xB4 = 1`; `wstring.resize(0)`; `FUN_00427210(0)`.
   - Does **not** free host or run buffers.
4. **RTTI / product demangle:** none on this helper → name **`_Inferred`**.
5. **Callees:** `wstring` end/resize/push_back/ctor/dtor; `FUN_004275b0`; `FUN_00427a40`; `FUN_00426ff0`; `FUN_00427050`; `FUN_00427210`.
6. **Callers (8 functions / 13 xrefs):** `FUN_00797990`, `FUN_007979c0`, `FUN_00797a10`, `FUN_00797a60`, dualed `UiTextLayout_CompleteDtor_Inferred` `FUN_00797d70` (flag **1**), `FUN_00797e20` (flags **1/0/0**), `FUN_007b3880`, `FUN_007b55c0`.
7. **Name:** `UiTextLayout_Finalize_Inferred` (Ghidra `FUN_00797530`). Scaffold `Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00797530` **retired**.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product demangle / exact class English (hence `_Inferred`).  
- Element type English for 0x60/0x80 runs; residual helper duals.  
- Alignment mode product names beyond CF.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00797530_UiTextLayout_Finalize_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00797530_UiTextLayout_Finalize_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00797530_FUN_00797530.md` |
| Annotated | `docs/reconstruction/raw/aa_00797530_FUN_00797530.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiTextLayout_Finalize_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00797530.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00797530.cpp` |
| Function | `docs/reconstruction/functions/aa_00797530_FUN_00797530.md` |
| Function named | `docs/reconstruction/functions/aa_00797530_UiTextLayout_Finalize_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
CNDUIWindow_CompleteDtor  FUN_007b5be0  [dualed WQ9K-F]
  └─ owned text layout @ +0x28C:
        FUN_00797d70  UiTextLayout_CompleteDtor_Inferred  [dualed WQ9L-F]
          ├─ merge float@+0xA4/+0xA8
          ├─ FUN_00797530(1)  UiTextLayout_Finalize_Inferred  [OWN MEGA-122]
          ├─ free vector @+0x94
          ├─ FUN_004271c0 @+0x80
          └─ ~wstring @+0x0C
        operator_delete(p)

Thin wrappers (merge then finalize flag 1):
  FUN_00797990 / FUN_007979c0 / FUN_00797a10
    └─ FUN_00797530(1)

FUN_00797e20  multi-site finalize (flags 1 / 0 / 0)
  └─ flag 0 enables mode-3 line-height write
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00797530-mega-122-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00797530` | Port as **text-layout finalize/flush** only. **EBX=layout\***, stack **flag**, **`RET 4`**. Trim spaces; align by mode@`+0xCC`; materialize runs; set ready@`+0xB4`; clear text. Do **not** free host/vectors. Mode-3 line-height only when **flag==0**. Half-factor constant **0.5f** (`DAT_00a0f298`). |
| Pair with | dualed complete dtor `00797d70`; residual helpers `00426ff0` / `00427050` / `00427210` / `004275b0` / `00427a40`; thin wrappers `00797990`/`007979c0`/`00797a10`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (UI text-layout finalize — not skill combat)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00797530`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed — verdicts **accept-with-gaps**.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI corrections (EBX-this, RET 4, flag gate).  
- Odd behavior preserved: multi-run skips `FUN_00427050`; mode-3 only if flag==0; empty+non-{1,2} leaves x unchanged.  
- `_Inferred` where product demangle unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
