# Dual A/B report — WQ9I-J OWN-ONLY (`0x00416590`, `0x004165f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9I-J**  
**Scope:** VAs `0x00416590`, `0x004165f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-J**.  
**Work item:** WQ-009 depth-6 residual dual seal (00416xxx residual neighborhood).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00416590` PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred | **accept-with-gaps** — 0x14 shell default-ctor CF/ABI/SEH/zero-skip/+size sealed; product fields residual |
| `aa_004165f0` Class_00a70524_ScalarDeletingDtor_Inferred | **accept-with-gaps** — MSVC scalar dtor CF/ABI/vtbl[0]/complete sealed; product demangle residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): full-zero object, mission/NDUI product alias, merge-with-neighbor, vector-deleting form, and delete-noreturn all **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

**These two VAs are not twins** — only residual-neighborhood co-owners.

---

## VA `0x00416590` — sealed facts

1. **Body:** `0x00416590`–`0x004165CF` exclusive (**63 B** / `0x3F`); pad `CC`.
2. **ABI:** **ECX=this**; no stack args; **`ret 0`** (`C3`); void; **leaf**.
3. **Semantics:** Default-ctor for **0x14-byte** pointer-vector shell:
   - SEH `LAB_009bcfab`; EH state −1 throughout.
   - Zero `+0`, `+8`, `+0xC`, `+0x10`.
   - **Leave `+4` untouched**.
4. **Elem size:** **0x14** — sealed by `_eh_vector_constructor_iterator_(base, 0x14, 9, this, FUN_00417ee0)` in `FUN_00820830` (array at host+0xEE4) and BSS statics stride 0x14.
5. **Classification:** leaf worker.
6. **Xrefs:** DATA push `@0x0082085d`; CALL `@0x009bf3c5` / `0x009bf5f5` / `0x009bf615` / `0x009bf635` (`ECX` = `0xd218e0` + n×0x14) then `_atexit`.
7. **Callees:** none.
8. **Name:** `PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred` (Ghidra `FUN_00416590`). Reject scaffold mission alias.
9. **Decompile ≡ raw CF** for field zeros; SEH sealed via **bytes**.

### Gaps

- Product English for shell / +0 / +4.  
- Why +4 is not zeroed.  
- Peer dtor `FUN_00417ee0` / static complete `FUN_00414950` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416590_PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416590_PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416590_FUN_00416590.md` |
| Annotated | `docs/reconstruction/raw/aa_00416590_FUN_00416590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416590.cpp` |
| Function | `docs/reconstruction/functions/aa_00416590_FUN_00416590.md` |
| Function named | `docs/reconstruction/functions/aa_00416590_PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred.md` |

---

## VA `0x004165f0` — sealed facts

1. **Body:** `0x004165f0`–`0x0041660E` exclusive (**30 B** / `0x1E`); pad `CC`.
2. **ABI:** **ECX=this**; stack **flags**; **`RET 4`** (`C2 04 00`); returns **this** in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** (vtbl[0]):
   - Always `FUN_008327f0(this)` complete (install `PTR_FUN_00a70524`, chain `FUN_0082d540`).
   - If `(flags & 1)` → `operator_delete(this)`.
   - Return this.
4. **Classification:** worker.
5. **Xrefs:** DATA only — `PTR_FUN_00a70524[0]` @ `0x00a70524` = `0x004165f0`.
6. **Callees:** `FUN_008327f0`, `operator_delete`.
7. **Name:** `Class_00a70524_ScalarDeletingDtor_Inferred` (Ghidra `FUN_004165f0`). Peer ctor `FUN_00832830` loads `"i_m_chatlog.xml"`.
8. **Decompile ≡ raw CF**; RET 4 + return-this sealed by **bytes**.

### Gaps

- Product/MSVC demangle.  
- Complete `008327f0` / base `0082d540` dual residual.  
- Vtbl slots [1+].  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004165f0_Class_00a70524_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004165f0_Class_00a70524_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004165f0_FUN_004165f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004165f0_FUN_004165f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a70524_ScalarDeletingDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004165f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004165f0_FUN_004165f0.md` |
| Function named | `docs/reconstruction/functions/aa_004165f0_Class_00a70524_ScalarDeletingDtor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred (0x00416590)   [OWN WQ9I-J]
  ├─ eh_vector parent FUN_00820830 (audio UI i_o_audio.xml; 9×0x14 @ +0xEE4)
  ├─ peer dtor FUN_00417ee0 (free +8; zero triad)              [residual]
  └─ static atexit path FUN_00414950 / wrappers 009c2f70…     [residual]

Class_00a70524_ScalarDeletingDtor_Inferred (0x004165f0)       [OWN WQ9I-J]
  ├─ vtbl[0] PTR_FUN_00a70524
  ├─ complete FUN_008327f0 → base FUN_0082d540                [residual]
  └─ peer ctor FUN_00832830 ("i_m_chatlog.xml")               [residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00416590-004165f0-wq9ij-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00416590` | Port as **thiscall leaf** default-ctor for **0x14** shell. Zero `+0/+8/+0xC/+0x10` only. **Do not** zero +4. Not mission/skill logic. |
| `004165f0` | Port as **MSVC scalar-deleting dtor** for class `00a70524`. ECX this, flags stack, **RET 4**, return this. Complete then optional `delete`. |
| Pair with | Peer dtor `00417ee0` / complete `008327f0` when dualed. **Do not** merge the two OWN VAs into one type. |
| Naming caution | Reject auto `Named_CalleeOf_…_Mission_createNDUI` for `00416590`. Chatlog English for `004165f0` is peer-ctor only → keep vtbl-based `_Inferred`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems note (util/container shell + UI class dtor — not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00416590`, `0x004165f0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra blank paste).  
- Odd behavior preserved: SEH elided in decompile; +4 skip; delete-noreturn false.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
