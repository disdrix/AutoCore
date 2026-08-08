# Dual A/B report — MEGA-139 OWN-ONLY (`0x00423e50`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-139**  
**Scope:** VA `0x00423e50` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_xrefs` / `get_function_callers` / `get_function_callees` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual partition — scalar peer of dualed **CNDUIWindow_CompleteDtor** (`0x007b5be0`).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` (MEGA-139, P70, skills-abilities).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00423e50` CNDUIWindow_ScalarDeletingDtor | **accept** — CF/ABI/RET4/vtbl[0]/RTTI/scalar-vs-complete sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): complete-body / vector-dtor / cdecl-this / always-free / never-free / noreturn-truncate / wrong-class claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00423e50` — sealed facts

1. **Body:** `0x00423e50`–`0x00423e6d` inclusive (**30 B** / `0x1E`); pad `CC CC` at `0x00423e6e`.
2. **ABI:** **ECX** = this; stack `uint8_t flags`; **EAX** = this; **`RET 4`**.
3. **Semantics:** MSVC **scalar-deleting destructor**:
   - Always `FUN_007b5be0` / `CNDUIWindow_CompleteDtor` (no free-this there).
   - If `(flags & 1)` → `operator_delete(this)` @ `0x00489822` (+ `ADD ESP,4`).
   - Return `this`.
   - Not vector-deleting (no count / no `delete[]`).
4. **RTTI:** `.?AVCNDUIWindow@@` @ `0x00afe1b4`; vtbl `PTR_FUN_00a960ac`.
5. **Callees:** `FUN_007b5be0`, `operator_delete`.
6. **Xrefs:** **1** DATA — dword @ `0x00a960ac` = `0x00423e50` (`vtbl[0]`). No code CALL sites (virtual only).
7. **Vtble install sites:** complete `0x007b5c00`; ctor twin `FUN_007b5dd0` @ `0x007b5dfc`.
8. **Name:** `CNDUIWindow_ScalarDeletingDtor` (Ghidra `FUN_00423e50`). Product class sealed — no `_Inferred`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + full-body `read_memory` (including `ADD ESP,4` omitted from false-noreturn listing).

### Gaps

- Runtime / bit-exact / differential.  
- Complete-dtor member English (owned by dualed parent `aa_007b5be0`).  
- Product demangle of the scalar thunk symbol itself (naming only).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00423e50_CNDUIWindow_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00423e50_CNDUIWindow_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00423e50_FUN_00423e50.md` |
| Annotated | `docs/reconstruction/raw/aa_00423e50_FUN_00423e50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWindow_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00423e50.cpp` |
| Function | `docs/reconstruction/functions/aa_00423e50_FUN_00423e50.md` |
| Function named | `docs/reconstruction/functions/aa_00423e50_CNDUIWindow_ScalarDeletingDtor.md` |

---

## Chain context (not dualled here; evidence only)

```text
PTR_FUN_00a960ac  CNDUIWindow primary vtbl
  vtbl[0] @ 00a960ac = 0x00423e50  CNDUIWindow_ScalarDeletingDtor  [OWN MEGA-139]
    └─ FUN_007b5be0  CNDUIWindow_CompleteDtor  [dualed WQ9K-F]
         ├─ free helpers / nested CS / base FUN_00759de0 …
         └─ does NOT free this
  install sites: complete @ 007b5c00; ctor FUN_007b5dd0 @ 007b5dfc
  RTTI: .?AVCNDUIWindow@@ @ 00afe1b4
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00423e50-mega-139-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00423e50` | Port as **MSVC scalar-deleting dtor** for **CNDUIWindow**. **thiscall RET 4**. Always call complete body first; free host only on `flags&1`. Do **not** inline complete body into this VA. |
| Pair with | dualed complete `007b5be0` `CNDUIWindow_CompleteDtor`; ctor twin `007b5dd0`; vtbl `PTR_FUN_00a960ac`. |
| Virtual delete | `obj->vtbl[0](1)` then null host pointer — matches parent dual pattern notes. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (UI / CNDUIWindow — partition tag skills-abilities is residual ownership only)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00423e50`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs/callees + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name `CNDUIWindow_ScalarDeletingDtor`; machine ABI corrections (thiscall RET 4; false-noreturn ignored).  
- Odd behavior preserved: decompiler marks `operator_delete` noreturn but epilogue still executes; `ADD ESP,4` present in bytes.  
- Product RTTI sealed → no `_Inferred`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
