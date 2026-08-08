# Dual A/B report — WQ9J-C OWN-ONLY (`0x008327f0`, `0x0097a8a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9J-C**  
**Scope:** VAs `0x008327f0`, `0x0097a8a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + RTTI COL. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-C**.  
**Work item:** WQ-009 depth-7 residual dual seal (UI complete dtors).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008327f0` CMenuChatlog_CompleteDtor | **accept-with-gaps** — complete CF/ABI/SEH/vtbl/RTTI/base chain sealed; intermediate base dual residual |
| `aa_0097a8a0` CWndTutorial_CompleteDtor | **accept-with-gaps** — complete CF/ABI/SEH/vtbl/RTTI/base chain sealed; deep base dual residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): scalar-form, always-free, wrong-vtbl-install, vector-dtor, merge-twins, string-only-product all **falsified**; RTTI product names **held**.  
Runtime Confirmed: **not claimed** (no Launcher).

**These two VAs are structural twins (thin complete + SEH) but distinct product classes** — co-owned by partition assignment as UI complete-dtor residual.

---

## VA `0x008327f0` — sealed facts

1. **Body:** `0x008327f0`–`0x0083282a` inclusive (**59 B** / `0x3B`); pad `CC` then ctor `FUN_00832830`.
2. **ABI:** **ECX=`this`**; SEH `LAB_009b453f`; EH state **`0xFFFFFFFF`**; epilogue **`ADD ESP,0x10; RET`**; void; does **not** free `this`.
3. **Semantics:** MSVC **complete destructor** for **CMenuChatlog**:
   - Install `PTR_FUN_00a70524` at `*this`.
   - Chain intermediate base complete `FUN_0082d540` (installs `00a72f6c`, `FUN_0082ce20`, then deep base `FUN_00792c20`).
4. **Classification:** wrapper.
5. **Callers (1 CALL):** `FUN_004165f0` @ `0x004165f3` — scalar-deleting dualed WQ9I-J (`Class_00a70524_ScalarDeletingDtor_Inferred`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL (from scalar only).
7. **RTTI:** COL `0x00ab5e54` → type_info `0x00affb04` → **`.?AVCMenuChatlog@@`** → **CMenuChatlog**.
8. **Name:** `CMenuChatlog_CompleteDtor` (Ghidra `FUN_008327f0`). Product demangle **sealed**.
9. **Decompile ≡ raw CF ≡ disasm**; body hex sealed via `read_memory`.

### Gaps

- Intermediate base `0082d540` / deep base `00792c20` dual residual.  
- Vtbl slots [1+] English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008327f0_CMenuChatlog_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008327f0_CMenuChatlog_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008327f0_FUN_008327f0.md` |
| Annotated | `docs/reconstruction/raw/aa_008327f0_FUN_008327f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CMenuChatlog_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008327f0.cpp` |
| Function | `docs/reconstruction/functions/aa_008327f0_FUN_008327f0.md` |
| Function named | `docs/reconstruction/functions/aa_008327f0_CMenuChatlog_CompleteDtor.md` |

---

## VA `0x0097a8a0` — sealed facts

1. **Body:** `0x0097a8a0`–`0x0097a8da` inclusive (**59 B** / `0x3B`); pad `CC` then ctor `FUN_0097a8e0`.
2. **ABI:** **ECX=`this`**; SEH `LAB_009b4587`; EH state **`0xFFFFFFFF`**; epilogue **`ADD ESP,0x10; RET`**; void; does **not** free `this`.
3. **Semantics:** MSVC **complete destructor** for **CWndTutorial**:
   - Install `PTR_FUN_00a6f61c` at `*this`.
   - Chain deep UI base complete `FUN_00792c20` **directly** (no intermediate `0082d540`).
4. **Classification:** wrapper.
5. **Callers (1 CALL):** `FUN_004160b0` @ `0x004160b3` — scalar-deleting dualed WQ9I-E (`Class_00a6f61c_ScalarDeletingDtor`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL (from scalar only).
7. **RTTI:** COL `0x00ab5cec` → type_info `0x00affaa4` → **`.?AVCWndTutorial@@`** → **CWndTutorial**.
8. **Name:** `CWndTutorial_CompleteDtor` (Ghidra `FUN_0097a8a0`). Product demangle **sealed**.
9. **Decompile ≡ raw CF ≡ disasm**; body hex sealed via `read_memory`.

### Gaps

- Deep base `00792c20` dual residual.  
- Vtbl slots [1+] English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0097a8a0_CWndTutorial_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0097a8a0_CWndTutorial_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0097a8a0_FUN_0097a8a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0097a8a0_FUN_0097a8a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWndTutorial_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0097a8a0.cpp` |
| Function | `docs/reconstruction/functions/aa_0097a8a0_FUN_0097a8a0.md` |
| Function named | `docs/reconstruction/functions/aa_0097a8a0_CWndTutorial_CompleteDtor.md` |

---

## Chain context (not dualled; evidence only)

```text
CMenuChatlog_CompleteDtor (0x008327f0)                    [OWN WQ9J-C]
  ├─ vtbl PTR_FUN_00a70524  RTTI .?AVCMenuChatlog@@
  ├─ scalar FUN_004165f0 (WQ9I-J dual)
  ├─ intermediate FUN_0082d540 → PTR_FUN_00a72f6c + 0082ce20
  │     └─ deep FUN_00792c20                                 [residual]
  └─ peer ctor FUN_00832830 ("i_m_chatlog.xml")              [residual]

CWndTutorial_CompleteDtor (0x0097a8a0)                     [OWN WQ9J-C]
  ├─ vtbl PTR_FUN_00a6f61c  RTTI .?AVCWndTutorial@@
  ├─ scalar FUN_004160b0 (WQ9I-E dual)
  ├─ deep FUN_00792c20 (direct)                              [residual]
  └─ peer ctor FUN_0097a8e0 ("i_w_tut_2d_wnd_highlight.dds") [residual]
```

Partition labeled these as **UI complete dtors** residual; machine CF is two thin MSVC complete wrappers for distinct NDUI classes sharing the same deep base family.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008327f0-0097a8a0-wq9jc-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008327f0` | Port as **CMenuChatlog complete dtor only**: install `00a70524`, chain `0082d540`. **ECX thiscall**, SEH, **ADD ESP,0x10; RET**. Do **not** free host. Scalar is `004165f0`. |
| `0097a8a0` | Port as **CWndTutorial complete dtor only**: install `00a6f61c`, chain `00792c20` directly. Same ABI shape. Scalar is `004160b0`. |
| Pair with | Dualed scalars WQ9I-J / WQ9I-E; base duals when owned. **Do not** merge the two classes — different RTTI and base depth. |
| Naming | Product demangle sealed — prefer `CMenuChatlog_*` / `CWndTutorial_*` over prior vtbl-hex `_Inferred` plates for these completes. Parent may optionally rename scalar twins. |

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

- OWN VAs only (`0x008327f0`, `0x0097a8a0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + RTTI COL. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- New raw bodies (no prior scaffold); re-verify sections included at capture.  
- Clean sources use product RTTI names (not Ghidra blank paste).  
- Odd behavior preserved: thin complete only; chatlog uses intermediate base, tutorial does not.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
