# Dual A/B report — MEGA-136 OWN-ONLY (`0x00441960`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-136**  
**Scope:** VA `0x00441960` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `disassemble_function` + `read_memory` / `read_memory_bytes` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual seal — nested STL of dualed **gfxUIWindow_CompleteDtor** (`0x00759de0`): **erase-range isnil11 / ShellA4**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00441960` StdTree_EraseRange_Isnil11_Inferred | **accept-with-gaps** — CF/ABI/EDI-map/RET0xC/isnil11/full-clear+partial/2 callers sealed; product map English + single-erase dual open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): gfxUIWindow-method / ECX-thiscall / isnil29-31-merge / full-clear-only / scaffold-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00441960` — sealed facts

1. **Body:** `0x00441960`–`0x00441a11` inclusive (**178 B** / `0xB2`).
2. **ABI:** **EDI** = MapShell*; stack `outIt*`, `first`, `last`; **EAX** = `outIt*`; **`RET 0xC`** ×2 exits.
3. **Semantics:** MSVC `_Tree::erase(first, last)` for isnil@**+0x11**:
   - Full clear: `first==head->left && last==head` → free root via dualed `StdTree_FreeSubtree_Isnil11_Inferred` (`0x00440d20`); reset head left/parent/right to head; size=0; `*outIt=head->left`.
   - Partial: successor (isnil11) then residual `FUN_004477a0(map, &first, node)`.
4. **Callees:** `FUN_00440d20` (dualed MEGA-132 free isnil11); `FUN_004477a0` (residual single erase isnil11).
5. **Callers / xrefs:** **2** UNCONDITIONAL_CALL — `FUN_00440200` @ `0x00440210`; `gfxUIWindow_CompleteDtor` (`0x00759de0`) @ `0x00759fe3` (shell@**+0xA4**, `MOV EDI,EBP`).
6. **Partition alias:** `StdTree_EraseAll_ShellA4` — consumer MapShell at gfxUIWindow **+0xA4**.
7. **Name:** `StdTree_EraseRange_Isnil11_Inferred` (Ghidra `FUN_00441960`). Product map open → `_Inferred`. Scaffold `Named_CalleeOf_Named_gfxUIWindow_00441960` **retired**.
8. **Decompile ≡ raw CF**; ABI/offset sealed via `disassemble_function` + `read_memory_bytes` + call-site context.

### Gaps

- Product demangle of map key/value (isnil11 family).  
- Dual of residual single-erase `FUN_004477a0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00441960_StdTree_EraseRange_Isnil11_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00441960_StdTree_EraseRange_Isnil11_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00441960_FUN_00441960.md` |
| Annotated | `docs/reconstruction/raw/aa_00441960_FUN_00441960.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil11_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00441960.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxUIWindow_00441960.cpp` |
| Function | `docs/reconstruction/functions/aa_00441960_FUN_00441960.md` |
| Function named | `docs/reconstruction/functions/aa_00441960_StdTree_EraseRange_Isnil11_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
gfxUIWindow_CompleteDtor  0x00759de0  [dualed WQ9L-F]
  ├─ shells +0x10 / +0x04 / +0xA4 clear paths
  ├─ early free-subtree isnil11 @ shell+0xA4  via 00440d20  [dualed MEGA-132]
  └─ residual: FUN_00441960(begin,end) then operator_delete(head)  [OWN MEGA-136]
       ├─ full: StdTree_FreeSubtree_Isnil11_Inferred  0x00440d20
       └─ partial: FUN_004477a0  erase+rebalance isnil11  [residual]

FUN_00440200  EH/shell tidy
  └─ FUN_00441960 + operator_delete(head)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00441960-mega-136-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00441960` | Port as **`_Tree::erase(first,last)`** for isnil@**+0x11**. Map in **EDI** (or explicit map arg). Stack outIt/first/last; **RET 0xC**. Pair free **`00440d20`** and residual erase **`004477a0`**. Do **not** merge with isnil29 range `004cbaa0` or isnil31 erase family. |
| Consumer | gfxUIWindow shell@**+0xA4** clear in complete dtor / EH tidy — not a UI method itself. |
| Pair with | dualed free isnil11 `00440d20`; dualed parent dtor `00759de0`; residual `004477a0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers when batch-merging MEGA duals

**Terminal:** **false**
