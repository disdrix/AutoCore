# Dual A/B report — WQ9K-G OWN-ONLY (`0x0082d540`, `0x00792c20`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9K-G**  
**Scope:** VAs `0x0082d540`, `0x00792c20` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + RTTI COL. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-G**.  
**Work item:** WQ-009 depth-8 residual dual seal (UI intermediate + shared base complete dtors).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082d540` CVOGMenu_CompleteDtor | **accept-with-gaps** — complete CF/ABI/SEH/vtbl/RTTI/base chain sealed; hash-helper dual residual |
| `aa_00792c20` CNDUIDialog_CompleteDtor | **accept-with-gaps** — complete CF/ABI/SEH/vtbl/RTTI/offset map/base chain sealed (bytes correct decompiler tail); slot English + deep-base dual residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): scalar-form, host-free-as-noreturn, wrong-vtbl-install, vector-dtor, merge-twins, chatlog-only product all **falsified**; RTTI product names **held**.  
Runtime Confirmed: **not claimed** (no Launcher).

**These two VAs are inheritance-chain related (intermediate → shared base) but distinct product classes** — co-owned by partition as CMenuChatlog intermediate base + shared UI base complete dtors.

---

## VA `0x0082d540` — sealed facts

1. **Body:** `0x0082d540`–`0x0082d58e` inclusive (**79 B** / `0x4F`); pad `CC` then next.
2. **ABI:** **ECX=`this`**; SEH `LAB_009b4443`; EH **0** during hash helper, then **`0xFFFFFFFF`** for base; epilogue **`ADD ESP,0x10; RET`**; void; does **not** free `this`.
3. **Semantics:** MSVC **complete destructor** for **CVOGMenu**:
   - Install `PTR_FUN_00a72f6c` at `*this`.
   - `FUN_0082ce20` menu hash/map teardown (dword `[0x14d]`).
   - Chain shared base complete `FUN_00792c20` (**CNDUIDialog**).
4. **Classification:** wrapper.
5. **Callers:** scalar `FUN_004166d0` (vtbl[0]); derived complete `FUN_008327f0` (CMenuChatlog); other menu completes; Unwind.
6. **Xrefs:** 22 (CALL + Unwind).
7. **RTTI:** COL `0x00ab6214` → type_info `0x00afe39c` → **`.?AVCVOGMenu@@`** → **CVOGMenu**.
8. **Name:** `CVOGMenu_CompleteDtor` (Ghidra `FUN_0082d540`). Product demangle **sealed**.
9. **Decompile ≡ raw CF ≡ disasm**; body hex sealed via `read_memory`.

### Gaps

- Menu hash helper `0082ce20` dual residual.  
- Vtbl slots [1+] English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082d540_CVOGMenu_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082d540_CVOGMenu_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082d540_FUN_0082d540.md` |
| Annotated | `docs/reconstruction/raw/aa_0082d540_FUN_0082d540.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMenu_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082d540.cpp` |
| Function | `docs/reconstruction/functions/aa_0082d540_FUN_0082d540.md` |
| Function named | `docs/reconstruction/functions/aa_0082d540_CVOGMenu_CompleteDtor.md` |

---

## VA `0x00792c20` — sealed facts

1. **Body (true):** `0x00792c20`–`0x00792d12` inclusive (**243 B** / `0xF3`); pad `CC` then peer ctor `FUN_00792d20`.  
   **Ghidra DB body ends at `00792ceb`** — **truncated** after member `operator_delete` (false noreturn).
2. **ABI:** **ECX=`this`**; SEH `LAB_009b4054`; EH **1** during owned teardown, then **`0xFFFFFFFF`** for base; epilogue **`ADD ESP,0x10; RET`**; void; does **not** free host `this`.
3. **Semantics:** MSVC **complete destructor** for **CNDUIDialog**:
   - Install `PTR_FUN_00a98f44` at `*this`.
   - `FUN_007917c0` child-hash teardown at `+0x4c0`.
   - Null-safe scalar-delete owned ptrs at `+0x4c0`, `+0x4c8`…`+0x4d8` (**skip `+0x4c4`**).
   - List clear `FUN_00415e90` with ESI = `this+0x4dc`.
   - **Member** free `operator_delete(*(this+0x4e0))` then zero — **returns**.
   - Chain deeper window complete `FUN_007b5be0`.
4. **Classification:** worker (fat complete).
5. **Callers:** **hundreds** — shared base (incl. `FUN_0082d540`, `FUN_0097a8a0` CWndTutorial, inventory grids, many NDUI dialogs) + Unwind.
6. **Xrefs:** 100+ listed; inventory xref_count **304**.
7. **RTTI:** COL `0x00ab7e6c` → type_info `0x00afe1c8` → **`.?AVCNDUIDialog@@`** → **CNDUIDialog**.
8. **Name:** `CNDUIDialog_CompleteDtor` (Ghidra `FUN_00792c20`). Product demangle **sealed**. Prefer over prior ctor dual name `NDUIContainerPanel_*`.
9. **Decompile incomplete at tail**; **bytes authority** for post-delete continuation.

### Gaps

- English roles of owned slots / list / `+0x4e0`.  
- Dual residual of `007917c0` / `00415e90` / `007b5be0`.  
- Ghidra function-body repair residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00792c20_CNDUIDialog_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00792c20_CNDUIDialog_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00792c20_FUN_00792c20.md` |
| Annotated | `docs/reconstruction/raw/aa_00792c20_FUN_00792c20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIDialog_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00792c20.cpp` |
| Function | `docs/reconstruction/functions/aa_00792c20_FUN_00792c20.md` |
| Function named | `docs/reconstruction/functions/aa_00792c20_CNDUIDialog_CompleteDtor.md` |

---

## Chain context (not dualled beyond OWN; evidence only)

```text
CMenuChatlog_CompleteDtor (0x008327f0)                     [dualed WQ9J-C]
  ├─ vtbl PTR_FUN_00a70524  RTTI .?AVCMenuChatlog@@
  └─ intermediate CVOGMenu_CompleteDtor (0x0082d540)       [OWN WQ9K-G]
        ├─ vtbl PTR_FUN_00a72f6c  RTTI .?AVCVOGMenu@@
        ├─ scalar FUN_004166d0
        ├─ FUN_0082ce20 menu hash teardown                  [residual]
        └─ CNDUIDialog_CompleteDtor (0x00792c20)           [OWN WQ9K-G]
              ├─ vtbl PTR_FUN_00a98f44  RTTI .?AVCNDUIDialog@@
              ├─ scalar FUN_004280d0
              ├─ peer ctor FUN_00792d20                     [prior dual]
              ├─ owned teardown +0x4c0..+0x4e0
              └─ deep FUN_007b5be0                          [residual]

CWndTutorial_CompleteDtor (0x0097a8a0)                      [dualed WQ9J-C]
  └─ CNDUIDialog_CompleteDtor (0x00792c20)  direct          [OWN WQ9K-G]
```

Partition labeled these as **CMenuChatlog intermediate base dtor** + **shared UI base complete dtor**; machine CF is CVOGMenu intermediate complete → CNDUIDialog shared complete (RTTI sealed).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082d540-00792c20-wq9kg-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082d540` | Port as **CVOGMenu complete dtor only**: install `00a72f6c`, `0082ce20`, chain `00792c20`. **ECX thiscall**, SEH, **ADD ESP,0x10; RET**. Do **not** free host. Scalar is `004166d0`. |
| `00792c20` | Port as **CNDUIDialog complete dtor**: install `00a98f44`, hash+owned teardown, member free at `+0x4e0` **returns**, chain `007b5be0`. Same ABI shape. Scalar is `004280d0`. **Do not** treat decompiler noreturn as host free. |
| Pair with | Dualed derived completes WQ9J-C; scalars; peer ctor `00792d20`. **Do not** merge CVOGMenu with CNDUIDialog. |
| Naming | Product demangle sealed — prefer `CVOGMenu_*` / `CNDUIDialog_*`. Parent may optionally rename prior `NDUIContainerPanel_Ctor_Inferred` toward CNDUIDialog. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems note (UI/NDUI complete dtors — not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x0082d540`, `0x00792c20`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + RTTI COL. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended**.  
- Clean sources use product RTTI names (not Ghidra blank paste).  
- Odd behavior preserved: decompiler false-noreturn on member delete; Ghidra body truncation; skip `+0x4c4`.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
