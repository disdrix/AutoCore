# Dual A/B report — WQ9L-D2 OWN-ONLY (`0x0078c3d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9L-D2**  
**Scope:** VA `0x0078c3d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers. Sibling `0x0076c4d0` duals **not rewritten** (already dual-sealed as `RdtscTimer_StampAndArm_Inferred`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** WQ-009 depth-9 residual dual seal — WQ9L-D residual helper under dualed **CNDUIWndBuffered_CompleteDtor** (`0x0078ca80`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0078c3d0` CNDUIWndBuffered_TeardownBufferedOwned_Inferred | **accept-with-gaps** — CF/ABI/RET/offsets/unregister thiscall/scalar-delete/HostBase-aux release/owner class sealed; product child-type English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): complete-dtor-merge / HostBase-free / cdecl / stack-this / always-teardown-49c / wrong-gate claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0078c3d0` — sealed facts

1. **Body:** `0x0078c3d0`–`0x0078c47e` inclusive (**175 B** / `0xAF`); terminal **`C3`**.
2. **ABI:** **ECX** = `CNDUIWndBuffered*` this; no stack formals; void; bare **`RET`**.
3. **Semantics:** buffered-owned teardown helper (gate `+0x2A4`):
   - Unregister + scalar-delete owned at **`+0x2AC`** via `FUN_0074e260(*(HostBase+4), *(child+0x8C))` + `vtbl[0](1)`.
   - Optional same for **`+0x49C`**.
   - Scalar-delete primary owned at **`+0x2A4`**.
   - Refcount-release COM-like at `(*(HostBase@+0x2A8)+4)+0x3C` (`--` @ `+4`; if 0 `vtbl[+8]`); null slot.
   - Does **not** free HostBase `@+0x2A8` (parent complete dtor does after return).
4. **Callees:** `FUN_0074e260` ×2; scalar `vtbl[0](1)` ×≤3; `vtbl[+8]` ×0–1.
5. **Callers (code):** `CNDUIWndBuffered_CompleteDtor` `FUN_0078ca80` @ `0x0078cab2` (`MOV ECX,ESI`).
6. **Xrefs:** 5 total (1 UNCONDITIONAL_CALL + 4 DATA vtable slots: `00a9a32c`, `00a6ff84`, `00a6755c`, `00a66d24`).
7. **Owner class:** **CNDUIWndBuffered** — sealed via dualed parent complete dtor + RTTI `.?AVCNDUIWndBuffered@@` (COL through `PTR_FUN_00a99f74`).
8. **Name:** `CNDUIWndBuffered_TeardownBufferedOwned_Inferred` (Ghidra `FUN_0078c3d0`). Method English open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + full-body `read_memory` (175 B). Unregister **thiscall this** corrected vs decompiler single-arg display.

### Gaps

- Product English / RTTI for owned types at `+0x2A4` / `+0x2AC` / `+0x49C`.  
- Dual of `FUN_0074e260` (unregister helper).  
- Product meaning of HostBase-aux `+0x3C` COM-like object.  
- Vtable method indices for 4 DATA slots.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0078c3d0_CNDUIWndBuffered_TeardownBufferedOwned_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0078c3d0_CNDUIWndBuffered_TeardownBufferedOwned_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0078c3d0_FUN_0078c3d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0078c3d0_FUN_0078c3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_TeardownBufferedOwned_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0078c3d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0078c3d0_FUN_0078c3d0.md` |
| Function named | `docs/reconstruction/functions/aa_0078c3d0_CNDUIWndBuffered_TeardownBufferedOwned_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
CWndVehicle_CompleteDtor  0x00834520  [dualed]
  └─ CNDUIWndBuffered_CompleteDtor  FUN_0078ca80  [dualed WQ9K-F]
        ├─ FUN_007a8580                 shared UI teardown  [residual / other OWN]
        ├─ FUN_0078c3d0                 TeardownBufferedOwned  [OWN WQ9L-D2]
        │     ├─ FUN_0074e260 ×2        unregister  [scaffold]
        │     ├─ vtbl[0](1) ×≤3         scalar-delete owned
        │     └─ vtbl[+8]               refcount destroy
        ├─ scalar-delete HostBase @ +0x2A8
        └─ FUN_007b5be0                 CNDUIWindow_CompleteDtor  [dualed]

Sibling WQ9L-D pair: RdtscTimer_StampAndArm_Inferred 0x0076c4d0  [dual-sealed; not rewritten]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0078c3d0-wq9ld2-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0078c3d0` | Port as **CNDUIWndBuffered complete-dtor helper**, not the complete dtor itself. **thiscall bare RET**. Gate on **`+0x2A4`**. Unregister children via HostBase aux (`*(+0x2A8)+4`) + key at child `+0x8C`. Scalar-delete with flag **1**. Refcount-release aux `+0x3C`. **Do not** free HostBase `+0x2A8` here — parent complete dtor owns that step. |
| Pair with | dualed `CNDUIWndBuffered_CompleteDtor` `0078ca80`; ctor `0078caf0`; HostBase `007560d0`; residual `FUN_0074e260`; dualed base `CNDUIWindow_CompleteDtor` `007b5be0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (UI complete-dtor chain — not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN residual).

---

## Process

- OWN VA only (`0x0078c3d0`); sibling `0x0076c4d0` duals read-only for format; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI corrections (unregister thiscall this; interleaved null stores).  
- Odd behavior preserved: gate-only entry; interleaved null of `+0x2AC`; HostBase free deferred to parent.  
- `_Inferred` where method English unproven; class name sealed via parent RTTI. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
