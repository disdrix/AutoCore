# Dual A/B report — R12-010 OWN-ONLY (`0x004130d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-010**  
**Scope:** VA `0x004130d0` (`aa_004130d0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-010**.  
**Work item:** Residual dual seal — missions-progression; CVOGDialog scalar-deleting destructor (parent dual `0x0087b890` ctor).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004130d0` CVOGDialog_ScalarDeletingDtor | **accept** — scalar-dtor CF/ABI/vtbl[0]/RTTI CVOGDialog/`RET 4`/false-noreturn sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): complete-body / vector-dtor / always-free / cdecl-this / mission-mutator / scaffold-only-name claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004130d0` — sealed facts

1. **Body:** `0x004130d0`–`0x004130ee` exclusive (**30 B** / `0x1E`); terminal **`C2 04 00`**; pad `CC CC`.
2. **ABI:** **`__thiscall`** — **ECX=`this`**; stack **flags**; **`RET 4`**; returns **`this`** in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** for **CVOGDialog**:
   - Always call complete dtor **`FUN_0087b7d0`** (thiscall; installs `PTR_FUN_00a58c6c`, chains `CNDUIDialog_CompleteDtor` `0x00792c20`).
   - If `(flags & 1)`: `operator_delete(this)` @ `0x00489822`.
   - Return `this`.
4. **Classification:** worker.
5. **Callers:** DATA only — dword @ `0x00a58c6c` = `0x004130d0` (`PTR_FUN_00a58c6c[0]`). No code CALL sites.
6. **Callees:** `FUN_0087b7d0`, `operator_delete`.
7. **RTTI:** Parent dual R11-030 — COL @ `0x00ab4984` → type_info `0x00af8e50` → **`.?AVCVOGDialog@@`**. Ctor `FUN_0087b890` installs same vtbl.
8. **Name:** `CVOGDialog_ScalarDeletingDtor` (Ghidra `FUN_004130d0`). Product demangle **sealed** by RTTI (no `_Inferred`).
9. **Decompile ≡ raw CF**; Ghidra false-noreturn on `operator_delete` ignored (epilogue present).  
   Full hex: `568bf1e8f8864600f644240801740956e83d67070083c4048bc65ec20400`.
10. **Partition parent** `0x0087b890` is dualed ctor twin; **live structural complete** is `0x0087b7d0` (not dualed here).

### Gaps

- Complete dtor `FUN_0087b7d0` member map / dual not owned.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004130d0_CVOGDialog_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004130d0_CVOGDialog_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004130d0_FUN_004130d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004130d0_FUN_004130d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGDialog_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004130d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004130d0_FUN_004130d0.md` |
| Function named | `docs/reconstruction/functions/aa_004130d0_CVOGDialog_ScalarDeletingDtor.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGDialog_Ctor (0x0087b890)                    [parent dual R11-030]
  └─ installs PTR_FUN_00a58c6c
       ├─ [0] FUN_004130d0  CVOGDialog_ScalarDeletingDtor  [OWN R12-010]
       │      └─ FUN_0087b7d0  complete dtor  [not dualed]
       │           ├─ *this = PTR_FUN_00a58c6c
       │           └─ FUN_00792c20  CNDUIDialog_CompleteDtor  [dualed]
       └─ … other virtuals …

Subclasses (NpcMissionDialogHost, CDlgFirstTime, …)
  └─ call CVOGDialog_Ctor then overwrite *this with derived vtbl
```

Partition host "missions-progression" names the **host chain** (mission dialog subclasses); this leaf is the shared **CVOGDialog** scalar-delete thunk.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004130d0-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004130d0` | Port as **MSVC scalar-deleting destructor** for `CVOGDialog`: call complete `FUN_0087b7d0`, optional `operator_delete` on bit0, return this, **RET 4**. |
| Distinct from | Complete dtor `0087b7d0` (do not merge); ctor `0087b890`; base complete `00792c20`. |
| Pair with | dualed ctor `0087b890`; dualed `CNDUIDialog_CompleteDtor` `00792c20`; residual complete `0087b7d0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGDialog_ScalarDeletingDtor` @ `0x004130d0` / `aa_004130d0`.
- Verdict: **accept**; Terminal **false**.

---

## Process

- OWN VA only (`0x004130d0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful product name; machine ABI corrections (thiscall RET 4; false-noreturn ignored).
- Odd behavior preserved: Ghidra marks delete noreturn but epilogue always runs; bit0-only free.
- Product RTTI sealed → no `_Inferred`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
