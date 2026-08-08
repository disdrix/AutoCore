# Dual A/B report — WQ9L-I OWN-ONLY (`0x007917c0`, `0x0083a860`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9L-I**  
**Scope:** VAs `0x007917c0`, `0x0083a860` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** WQ-009 depth-9 residual dual seal — dialog dtor / shop reindex leaves (partition WQ9L-I).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007917c0` CNDUIDialog_TeardownChildHash_Inferred | **accept-with-gaps** — CF/ABI/ECX-this/bare RET/HashError walk/Recreate-not-free/sole CALL parent sealed; product demangle + vtbl English open |
| `aa_0083a860` ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred | **accept-with-gaps** — full 27 B body/EAX-host/EBX-list_i/AL-bool/+0x508 gate/sole CALL parent sealed; product demangle + finder dual open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): complete-dtor-merge / free-hash / VOG_DEBUG_STOP product-name / thiscall-a860 / EAX=list_i / mutator / full-reindex claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x007917c0` — sealed facts

1. **Body:** `0x007917c0`–`0x007918e1` inclusive (**290 B** / `0x122`); pad `CC` ×14 then next @ `0x007918f0`.
2. **ABI:** **ECX** = this (`MOV EBP,ECX`); void; bare **`C3` RET**.
3. **Semantics:** CNDUIDialog **child-hash teardown leaf**:
   - Gate on `this+0x4c0` (hash*); early return if null.
   - `vtbl[+0x3c0](0)` clear selection; optional helper `+0x4b8` via `vtbl[+0x318]` then zero.
   - Hash traversal lock `@+0x1d` with HashError diagnostics (`TraversalLock` / `TraverseToNext` / `VOG_DEBUG_STOP`).
   - Walk chain `@+0x14`, value `@+8`; nested optional teardown (`+0x34` / `+0x3d8` / `+0x440`); child release `+0x334(0)`; clear child `+0x2b0`; `FUN_00756be0(this, child)`.
   - Unlock; `FUN_004133c0` with ESI=`this+0x4dc`, EAX=0, stack 0; `FUN_004281d0` with EAX=hash, **BL=5** (HashError:**Recreate** empty — **not** free).
   - Set flag `this+0x4c4 = 1`.
   - Does **not** free hash* or `this` — parent complete dtor `FUN_00792c20` scalar-deletes `+0x4c0` after return.
4. **Callers:** sole CALL `FUN_00792c20` @ `0x00792c4d`; 100+ DATA vtbl xrefs.
5. **Callees:** `FUN_007a4480`, `FUN_00756be0`, `FUN_004133c0`, `FUN_004281d0`, dialog/child vtbls.
6. **Name:** `CNDUIDialog_TeardownChildHash_Inferred` (Ghidra `FUN_007917c0`). Scaffold `Named_VOG_DEBUG_STOP_007917c0` **retired**.
7. **Decompile ≡ raw CF**; register ABI for `004133c0` / `004281d0` / `00756be0` recovered from disasm + entry/exit hex.

### Gaps

- English names for vtbl slots `+0x3c0` / `+0x318` / child `+0x34` / `+0x334` / nested `+0x3d8`/`+0x440`.  
- Product demangle of dialog / hash class (hence `_Inferred`).  
- Dual residual of `004133c0` / `004281d0` / `00756be0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007917c0_CNDUIDialog_TeardownChildHash_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007917c0_CNDUIDialog_TeardownChildHash_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007917c0_FUN_007917c0.md` |
| Annotated | `docs/reconstruction/raw/aa_007917c0_FUN_007917c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIDialog_TeardownChildHash_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007917c0.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_007917c0.cpp` |
| Function | `docs/reconstruction/functions/aa_007917c0_FUN_007917c0.md` |
| Function named | `docs/reconstruction/functions/aa_007917c0_CNDUIDialog_TeardownChildHash_Inferred.md` |

---

## VA `0x0083a860` — sealed facts

1. **Body:** `0x0083a860`–`0x0083a87a` inclusive (**27 B** / `0x1B`); pad `CC` ×5 then soft-refresh peer `FUN_0083a880`.
2. **ABI:** **EAX** = host*; **EBX** = list_i; **AL** = bool; bare **`C3` RET** ×2 (found / miss).
3. **Semantics:** pure **predicate**:
   - `PUSH EAX; CALL FUN_0083a7d0` (finder: stack host, live EBX=list_i, RET 4) → slot* or 0.
   - If null: `XOR AL,AL; RET`.
   - Else: `CMP [EAX+0x508],0; SETNZ AL; RET`.
   - Does **not** mutate host or slots.
4. **Parent use:** sole CALL from dualed `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` (`0x0083ac90`) @ `0x0083adc2` on id-match path:
   - `MOV EBX,EDI; MOV EAX,EBP; CALL a860; TEST AL` → true soft `a880(0)` / false reload `abf0`.
5. **Callees:** `FUN_0083a7d0` only (undualed finder; scans `host+0x50c[5]`, match `GetId - 0x9ca4 == EBX`).
6. **Name:** `ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred` (Ghidra `FUN_0083a860`). Scaffold `Named_CalleeOf_…_0083a860` **retired**.
7. **Decompile** shows `in_EAX` phantom / no formals — **bytes + sole caller seal register ABI**.

### Gaps

- Product English for host / slot class (shopveh inferred from parent dual + drive xml).  
- Finder `0083a7d0` undualed (WQ9L-J residual chain).  
- Exact type behind `slot+0x508`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0083a860_ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0083a860_ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0083a860_FUN_0083a860.md` |
| Annotated | `docs/reconstruction/raw/aa_0083a860_FUN_0083a860.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0083a860.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0083a860.cpp` |
| Function | `docs/reconstruction/functions/aa_0083a860_FUN_0083a860.md` |
| Function named | `docs/reconstruction/functions/aa_0083a860_ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
// Dialog dtor leaf
FUN_00792c20  CNDUIDialog_CompleteDtor  [evidence]
  ├─ FUN_007917c0  CNDUIDialog_TeardownChildHash_Inferred  [OWN WQ9L-I]
  ├─ scalar-delete this+0x4c0 (hash*) after leaf
  ├─ scalar-delete +0x4c8..+0x136 shells
  └─ FUN_00415e90 + operator_delete host residual

// Shop reindex predicate
FUN_0083ac90  ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred  [dualed WQ9K-H]
  ├─ id-match:
  │     FUN_0083a860  HasSlotBoundObjAtListIndex  [OWN WQ9L-I]
  │       └─ FUN_0083a7d0  FindSlotByListIndex  [undualed]
  │     true  → FUN_0083a880(0)   [residual WQ9L-J]
  │     false → FUN_0083abf0     [residual WQ9L-J]
  └─ mismatch → FUN_00833160 swap (dualed) / abf0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-007917c0-0083a860-wq9li-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007917c0` | Port as **dialog child-hash teardown leaf** (not complete dtor). **ECX=this**, bare RET. Recreate hash (BL=5) after walk; **do not** free hash* or host. Preserve HashError lock diagnostics. Pair with complete dtor `00792c20` which scalar-deletes `+0x4c0` after. |
| `0083a860` | Port as **pure occupancy probe**. **EAX=host*, EBX=list_i, AL=bool**, bare RET. `slot = find(host,list_i); return slot && slot[+0x508]`. Do **not** treat as thiscall or pass list_i in EAX. Parent: true→soft a880 / false→reload abf0. |
| Pair with | dualed parent reindex `0083ac90`; residual soft/reload `0083a880`/`0083abf0` (WQ9L-J); residual finder `0083a7d0`; dialog complete dtor `00792c20`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (dialog dtor + shopveh reindex depth-9)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x007917c0`, `0x0083a860`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names; Named_CalleeOf_ / Named_VOG_DEBUG_STOP scaffolds **retired** to thin aliases.  
- Odd behavior preserved: decompiler-hidden register ABIs (`004133c0` ESI/`004281d0` BL/`0083a860` EAX+EBX); Recreate-not-free; pure predicate dual RET.  
- `_Inferred` where product demangle unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
