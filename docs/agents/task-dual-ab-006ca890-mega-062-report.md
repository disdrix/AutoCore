# Dual A/B report — MEGA-062 OWN-ONLY (`0x006ca890`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-062**  
**Scope:** VA `0x006ca890` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `disassemble_function` + `get_function_by_address` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — soft-cast hit-list core under dualed **Client_InteractWorldClickHub** (`0x00925820`) via wrapper `FUN_0055e1e0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006ca890` SoftCastHitList_CoreFillAndRegister_Inferred | **accept-with-gaps** — CF/ABI/RET0x14/sole-caller/entry+query math sealed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): free-fn / wrong RET / multi-caller / always-write-+0x40 / sort-merge / parent-decompile-as-truth claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x006ca890` — sealed facts

1. **Body:** `0x006ca890`–`0x006ca93b` inclusive (**172 B** / `0xAC`); pad `CC×3` then undefined code @ `0x006ca940`.
2. **ABI:** **thiscall**; **ECX** = SoftCastHitEntry*; **5** stack formals; void; **`RET 0x14`**.
3. **Semantics:** soft-cast hit-list **core fill + register**:
   - Store soft-desc @ entry+4, backref @ +0xC, zero +0x10.
   - Related null-safe links: +8 ← related+0x14; +0x44 ← related+0x10 when flag set.
   - Flag soft-desc **byte @ +0x20**; field soft-desc **dword @ +0x24** → entry +0x40 when flag ≠ 0 (and +0x40 **not** written when flag clear).
   - Pack aligned query (4×header, ext=desc+0x10, flag=1, size=0x10, payload) → **indirect** `manager->vtbl[+0x30](&query, entry, 0)`.
4. **Callees:** none direct; **1** indirect vcall slot **+0x30**.
5. **Callers:** **1** UNCONDITIONAL_CALL — `FUN_0055e1e0` @ `0x0055e215`.
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Wrapper (evidence only):** `FUN_0055e1e0` builds **local** entry with vtbl `0x009d27a8`, passes `*(controller+0xC4)` manager, hub soft-desc, `*(controller+0xD0)` related, payload **0**, hub SoftCastHitList* backref; `RET 0x8`.
8. **Hub chain (evidence only):** dualed `Client_InteractWorldClickHub` @ `0x00925c32` after `FUN_0040c410`; next sort `SoftCastHitList_SortIfCountGt1` @ `0x00925c3e`.
9. **Name:** `SoftCastHitList_CoreFillAndRegister_Inferred` (Ghidra `FUN_006ca890`). Product map open → `_Inferred`.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context. Parent decompile shape **corrected**.

### Gaps

- Product English for manager vtbl+0x30 / soft-desc fields / entry class.  
- Full vtbl `0x009d27a8` method map.  
- Wrapper `FUN_0055e1e0` residual (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006ca890_SoftCastHitList_CoreFillAndRegister_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006ca890_SoftCastHitList_CoreFillAndRegister_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_006ca890_FUN_006ca890.md` |
| Annotated | `docs/reconstruction/raw/aa_006ca890_FUN_006ca890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_CoreFillAndRegister_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006ca890.cpp` |
| Function | `docs/reconstruction/functions/aa_006ca890_FUN_006ca890.md` |
| Function named | `docs/reconstruction/functions/aa_006ca890_SoftCastHitList_CoreFillAndRegister_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_InteractWorldClickHub  FUN_00925820  [dualed W17-C]
  ├─ FUN_0040c410            hit-list init/clear
  ├─ FUN_0055e1e0            soft-cast fill wrapper  [residual]
  │    └─ FUN_006ca890       SoftCastHitList_CoreFillAndRegister_Inferred  [OWN MEGA-062]
  ├─ FUN_0048a060            SoftCastHitList_SortIfCountGt1_Inferred  [dualed MEGA-116]
  │    └─ FUN_00489f20       qsort core  [MEGA-115]
  └─ walk → FUN_0040afb0     resolve object* from hit  [MEGA-028 residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-006ca890-mega-062-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006ca890` | Port as **soft-cast hit-entry fill + manager register**. **thiscall RET 0x14**. Preserve null-safe related links, flag@+0x20 gating of +0x40/+0x44, query pack `{1, 0x10}`, and indirect vtbl+0x30. Do **not** merge with sort gate `0048a060`. |
| Pair with | dualed hub `00925820`; dualed sort `0048a060`; residual wrapper `0055e1e0`; residual resolve `0040afb0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (interaction-activation soft-cast)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x006ca890`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (RET 0x14; ECX=entry; parent local-entry).  
- Odd behavior preserved: +0x40 not cleared when flag=0; wrapper payload always 0; 16-byte align.  
- No `Named_CalleeOf_*` scaffold existed for this VA. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
