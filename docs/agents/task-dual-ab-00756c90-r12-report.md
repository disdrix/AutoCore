# Dual A/B report — R12-003 OWN-ONLY (`0x00756c90`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-003**  
**Scope:** VA `0x00756c90` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R12 residual dual seal — callee of dualed **UI_Cs2dTabs_SelectTab_Inferred** (parent `0x00888b00`); UI parent-group child-list move-to-front helper.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` row R12-003.  
**System:** inventory-transfer (UI chrome helper; no inventory wire).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00756c90` UI_Widget_MoveToFrontInParentGroup_Inferred | **accept-with-gaps** — EDI ABI / RET / group+vec offsets / size==1 gate / erase+InsertN sealed; product names + front-order policy residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): inventory-wire / thiscall / pure-remove / stack-arg / sole-caller / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00756c90` — sealed facts

1. **Body:** `0x00756c90`–`0x00756d31` inclusive (**162 B** / `0xA2`); epilogue success `33 C0 5E 59 C3`, fail `83 C8 FF 5E 59 C3` (plain **`RET`**).
2. **ABI:** **EDI** = widget*; **no** stack args; **EAX** = `0` ok / `0xFFFFFFFF` no parent; **`RET`**. **Not** ECX thiscall.
3. **Semantics:** Parent-group child-pointer vector **move-to-front**:
   - `group = widget[+0x88]`; null → `-1`.
   - Vector begin/end `@group+0x94/+0x98` (elem size 4).
   - If begin ≠ 0 **and** size == 1 → return `0` (no mutate).
   - Else: linear scan erase self via `memmove` + `end -= 4` if present.
   - Then `FUN_00456960` InsertN(**count=1**) of widget at **begin** into vector base `group+0x90`.
4. **Does not** clear `widget+0x88` (true detach is sibling `FUN_00756be0`).
5. **Callees:** `memmove` (IAT `0x009c652c`); `FUN_00456960` (StdVector InsertN).
6. **Callers:** **28** UNCONDITIONAL_CALL — 12 named (`FUN_00888b00`, `FUN_00889410`, `FUN_00889fb0`, `FUN_00887780`, `FUN_0086b9b0`, `FUN_00878300`, `FUN_00879ea0`, `FUN_0087bc60`, `FUN_008a9630`, `FUN_008b84a0`, `FUN_008e1020`, `FUN_008e6b50`) + `@0090a4ac` / `@0090b62c`.
7. **Call pattern:** after `FUN_00822cb0` with **BL=0** (collapse) on same tab chrome; `MOV EDI, ctrl; CALL 00756c90`.
8. **Name:** `UI_Widget_MoveToFrontInParentGroup_Inferred` (Ghidra `FUN_00756c90`). Product map open → `_Inferred`.
9. **Decompile ≡ raw CF**; InsertN arity sealed via `disassemble_function` (decomp omits ECX/EDX/EAX setup for `FUN_00456960`).

### Gaps

- Product / RTTI English names of widget and group classes.  
- Product policy for why inactive/collapsed tabs are moved to front.  
- Residual dual of `FUN_00456960` / sibling attach-detach helpers (not owned).  
- Anonymous xrefs `@0090a4ac` / `@0090b62c`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00756c90_FUN_00756c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00756c90_FUN_00756c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Widget_MoveToFrontInParentGroup_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00756c90.cpp` |
| Function | `docs/reconstruction/functions/aa_00756c90_FUN_00756c90.md` |
| Function named | `docs/reconstruction/functions/aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Parent dual (R11-031 / partition parent):
  FUN_00888b00  UI_Cs2dTabs_SelectTab_Inferred  [dualed]
    ├─ FUN_00822cb0  tab chrome expand/collapse  [residual R12-002]
    └─ FUN_00756c90  move collapsed tab to front of parent group  [OWN R12-003]

This unit (R12-003):
  FUN_00756c90  UI_Widget_MoveToFrontInParentGroup_Inferred  [OWN]
    ├─ memmove
    └─ FUN_00456960  StdVector InsertN  [residual family]

Siblings (same neighborhood; not dualled):
  FUN_00756be0  true detach (erase + clear widget+0x88)
  FUN_00756d40  rebind/restore group link

Other dualed callers (evidence):
  FUN_00889410  UI_TabsC_SetActiveTab_Inferred
  FUN_00889fb0  (2-tab host selector)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00756c90-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00756c90` | Port as **widget → parent group child-list move-to-front**. **EDI=widget**, no stack args, **`RET`**, EAX status. group@**+0x88**, vec begin/end@**+0x94/+0x98**, InsertN base@**+0x90**. size==1 no-op. |
| Do **not** | Treat as ECX thiscall; invent inventory C2S; merge with true detach `FUN_00756be0`; claim pure-remove without re-insert; claim Runtime Confirmed. |
| Pair with | dualed parent `UI_Cs2dTabs_SelectTab_Inferred` `00888b00`; residual `FUN_00822cb0` / `FUN_00456960`; sibling detach `00756be0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER.md` / progress / WORK_QUEUE as applicable

**Terminal:** false.
