# Dual A/B report — MEGA-138 OWN-ONLY (`0x004166d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-138**  
**Scope:** VA `0x004166d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callers/callees/xrefs + `read_memory` (body + vtbl + COL + type_info). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-138**.  
**Work item:** Mega residual dual seal — scalar shell of dualed **CVOGMenu_CompleteDtor** (`0x0082d540`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004166d0` CVOGMenu_ScalarDeletingDtor | **accept** — CF/ABI/RET4/vtbl[0]/RTTI product name/complete callee sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): vector-deleting / delete-noreturn / cdecl / merge-with-complete / unsealed-name claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004166d0` — sealed facts

1. **Body:** `0x004166d0`–`0x004166ed` inclusive (**30 B** / `0x1E`); pad `CC`.
2. **ABI:** **ECX=this**; stack **flags**; **`RET 4`** (`C2 04 00`); returns **this** in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** (vtbl[0]):
   - Always `FUN_0082d540(this)` / `CVOGMenu_CompleteDtor` (install `PTR_FUN_00a72f6c`, menu hash, chain CNDUIDialog).
   - If `(flags & 1)` → `operator_delete(this)` + `ADD ESP,4`.
   - Return this.
4. **Classification:** worker.
5. **Xrefs:** DATA only — `PTR_FUN_00a72f6c[0]` @ `0x00a72f6c` = `0x004166d0`.
6. **Callers (code):** none.
7. **Callees:** `FUN_0082d540`, `operator_delete` @ `0x00489822`.
8. **RTTI:** COL @ `0x00a72f68` → `0x00ab6214` → type_info `0x00afe39c` → **`.?AVCVOGMenu@@`** → **CVOGMenu**.
9. **Name:** `CVOGMenu_ScalarDeletingDtor` (Ghidra `FUN_004166d0`). Product demangle sealed — no `_Inferred`.
10. **Decompile ≡ raw CF**; RET 4 + return-this + ADD ESP,4 sealed by **bytes**.

### Gaps

- Vtbl slots [1+] English (shared family).  
- Runtime / bit-exact / differential.  
- Hash dual residual under complete `0082ce20` (not this shell).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004166d0_CVOGMenu_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004166d0_CVOGMenu_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004166d0_FUN_004166d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004166d0_FUN_004166d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMenu_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004166d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004166d0_FUN_004166d0.md` |
| Function named | `docs/reconstruction/functions/aa_004166d0_CVOGMenu_ScalarDeletingDtor.md` |

---

## Chain context (not dualled here; evidence only)

```text
PTR_FUN_00a72f6c[0]  →  FUN_004166d0  CVOGMenu_ScalarDeletingDtor  [OWN MEGA-138]
  └─ FUN_0082d540  CVOGMenu_CompleteDtor  [dualed WQ9K-G]
       ├─ *this = &PTR_FUN_00a72f6c
       ├─ FUN_0082ce20  menu hash teardown  [residual]
       └─ FUN_00792c20  CNDUIDialog_CompleteDtor  [dualed WQ9K-G]

Derived complete example (not owned):
FUN_008327f0  CMenuChatlog complete → chains FUN_0082d540
  └─ its own scalar shell FUN_004165f0 (vtbl 00a70524)  [dualed WQ9I-J]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004166d0-mega-138-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004166d0` | Port as **MSVC vtbl[0] scalar-deleting dtor** for **CVOGMenu**. **thiscall RET 4**. Always complete then optional `delete`. Do **not** free inside complete. Keep distinct from derived menu scalars (e.g. chatlog `004165f0`). |
| Pair with | dualed complete `0082d540`; dualed base complete `00792c20`; residual hash `0082ce20`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep:

- `VERIFICATION_MATRIX.md` / coverage ledgers for `aa_004166d0` → **accept**
- Name registry: `CVOGMenu_ScalarDeletingDtor` @ `0x004166d0`
