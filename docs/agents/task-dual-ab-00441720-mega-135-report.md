# Dual A/B report — MEGA-135 OWN-ONLY (`0x00441720`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-135**  
**Scope:** VA `0x00441720` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — skills-abilities residual of dualed **gfxUIWindow_CompleteDtor** (`0x00759de0`): **StdTree_EraseAll_Shell10**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00441720` StdTree_EraseAll_Shell10_Inferred | **accept-with-gaps** — CF/ABI/EDI-tree/RET0xC/isnil@+0x1d/Shell10/2 xrefs sealed; product map English + callee duals open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): single-erase-only / isnil29-31-merge / ECX-thiscall / RET4 / UI-method / merge-with-`0051d700` claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00441720` — sealed facts

1. **Body:** `0x00441720`–`0x004417d1` inclusive (**178 B** / `0xB2`); pad `CC` ×14 then next SEH @ `0x004417e0`.
2. **ABI:** **EDI** = tree/map shell (`+0x04` head, `+0x08` size); stack `(outIt*, first, last)`; **EAX** = outIt; **`RET 0xC`** ×2 exits.
3. **Semantics:** MSVC **`_Tree::erase(first, last)`** for **isnil@+0x1d** / value **Shell10** (0x10 B @ `+0x0c`, color@`+0x1c`):
   - Full clear: `first == head->left && last == head` → `FUN_00440c90(head->parent)` + head reset + size 0.
   - Partial: in-order successor then `FUN_00442000(tree, tmp, victim)`.
4. **Callees:** `FUN_00440c90` (free-subtree isnil1d; ECX=tree); `FUN_00442000` (erase-node isnil1d; throws invalid iterator).
5. **Callers / xrefs:** **2** UNCONDITIONAL_CALL — `FUN_004401d0` @ `0x004401e0` (EH residual); `FUN_00759de0` @ `0x0075a09c` (dualed gfxUIWindow complete).
6. **Name:** `StdTree_EraseAll_Shell10_Inferred` (Ghidra `FUN_00441720`). Product map open → `_Inferred`. No `Named_CalleeOf_*` scaffold for this VA.
7. **Decompile ≡ raw CF**; ABI/offset sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product / English host map type for Shell10 under gfxUIWindow.  
- Callee duals (`00440c90`, `00442000`, value destroy `00442730`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00441720_StdTree_EraseAll_Shell10_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00441720_StdTree_EraseAll_Shell10_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00441720_FUN_00441720.md` |
| Annotated | `docs/reconstruction/raw/aa_00441720_FUN_00441720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAll_Shell10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00441720.cpp` |
| Function | `docs/reconstruction/functions/aa_00441720_FUN_00441720.md` |
| Function named | `docs/reconstruction/functions/aa_00441720_StdTree_EraseAll_Shell10_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
gfxUIWindow_CompleteDtor  FUN_00759de0  [dualed WQ9L-F]
  ├─ tree shells clear @ +0x10 / +0x04 / +0xA4 (parent dual)
  └─ @0x0075a09c
        FUN_00441720  StdTree_EraseAll_Shell10_Inferred  [OWN MEGA-135]
          ├─ full clear → FUN_00440c90 free-subtree isnil@+0x1d  [residual]
          │                 └─ FUN_00442730 value destroy + operator_delete
          └─ partial → FUN_00442000 erase-node isnil@+0x1d  [residual]
                         └─ throw path Std_OutOfRange_CtorFromString 00401bc0 [dualed]

FUN_004401d0  EH residual of same complete dtor
  └─ MOV EDI,tree; FUN_00441720(begin,end); operator_delete(head)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00441720-mega-135-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00441720` | Port as **range erase** for isnil@**+0x1d** / value-shell **0x10**. Retail: **EDI=tree**, stack `(outIt, first, last)`, **`RET 0xC`**. Full-clear uses free-subtree `00440c90`; partial uses erase-node `00442000`. Do **not** treat as ECX-thiscall. Keep distinct from isnil11 twin `00441960`, isnil29 `004cbaa0`, and peer instance `0051d700`. |
| Pair with | dualed `gfxUIWindow_CompleteDtor` `00759de0`; residual free `00440c90` / erase `00442000`; dualed out_of_range ctor `00401bc0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (STL Shell10 erase under gfxUIWindow)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN-ONLY agent **MEGA-135**: exclusive VA `0x00441720`; no parent ledger edits; no Launcher.  
- Live tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed — verdicts **accept-with-gaps** both paths.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name `StdTree_EraseAll_Shell10_Inferred`; Ghidra twin retained.  
- Odd behavior preserved: decompiler `unaff_EDI` / elided `FUN_00442000` args; free-subtree gets ECX=tree at call site; both static callers only exercise full-clear.  
- Product demangle open → `_Inferred`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
