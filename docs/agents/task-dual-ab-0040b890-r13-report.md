# Dual A/B report — R13-019 OWN-ONLY (`0x0040b890`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-019**  
**Scope:** VA `0x0040b890` (`aa_0040b890`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent `0x0092b2a0` re-dual, siblings `0040b3b0`/`0040b440`/`0040bc10`, insert helper `0040bcd0`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-019**.  
**System:** inventory-transfer (partition assignment; unit role is generic MSVC tree always-insert).  
**Parent dual:** `0x0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred (R12-008).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040b890` StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred | **accept-with-gaps** — always-insert CF/ABI/RET4/EAX+EBX/isnil19/signed key/sole caller sealed; product map English + insert-helper dual open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): inventory-product / thiscall / InsertOrFind / unsigned-key / isnil29-31-merge / multi-caller / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0040b890` — sealed facts

1. **Body:** `0x0040b890`–`0x0040b8eb` inclusive (**92 B** / `0x5C`); pad `CC CC` @ `0x0040b8ec`–`0x0040b8ed`; next `FUN_0040b8f0`.
2. **ABI:** **EAX** = map shell; **EBX** = value* (`key = *(int32*)EBX`); stack out `{Node* it, u8 inserted@+4}`; **EAX** returns out; **`RET 4`**. **Not** ECX-thiscall.
3. **Semantics — always-insert (not InsertOrFind):**
   - root = `head->parent`; goLeft = true.
   - Walk while `!isnil@+0x19`; signed compare key vs `node+0x0C` (`SETL`); left/right; ECX tracks where-parent.
   - Empty tree: skip walk; ECX stays head.
   - Always `CALL FUN_0040bcd0` (EDI=map, ECX=where, stack tmpOut/goLeft/value*).
   - `out.it = *tmp; out.inserted = 1` — **unconditional** (no equal-key arm).
4. **Layout:** left@+0, parent@+4, right@+8, key@**+0x0C** (signed), value@+0x10 (8 B), color@**+0x18**, isnil@**+0x19**; node **0x1C** (`operator_new` in `FUN_0040c060`); shell head@+4, size@+8.
5. **Callees:** `FUN_0040bcd0` only (insert+RB; buy `0040c060`, Lrot `0040b910`, Rrot `00446b10` — unOWN).
6. **Callers (1):** `FUN_0092b2a0` @ `0x0092b4fc` (MissionTracker secondary fill; stack temp ranking map).
7. **Xrefs:** 1 UNCONDITIONAL_CALL (same).
8. **Name:** `StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred` (Ghidra `FUN_0040b890`). Product map open → `_Inferred`.
9. **Family peers (do not merge):** InsertOrFind isnil31 EaxEbx `00402b30`; parent siblings construct `0040b3b0` / erase `0040b440` / erase-range `0040bc10` (R13-017/018/020).
10. **Decompile ≡ raw CF** for walk/insert; ABI/epilogue sealed via `read_memory` + `disassemble_function`; call-site EAX/EBX sealed via `get_assembly_context`.

### Gaps

- Product / English host temp-map T in MissionTracker ranking arm.  
- Dual of insert `FUN_0040bcd0` / buynode `FUN_0040c060` / ctor `FUN_0040c210`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040b890_StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040b890_StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R13-019 re-verify append) | `docs/reconstruction/raw/aa_0040b890_FUN_0040b890.md` |
| Annotated | `docs/reconstruction/raw/aa_0040b890_FUN_0040b890.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040b890.cpp` |
| Function | `docs/reconstruction/functions/aa_0040b890_FUN_0040b890.md` |
| Function named | `docs/reconstruction/functions/aa_0040b890_StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
MissionTracker_RefreshTrackedTargets_Inferred  0x0092bf60  [dualed R11]
  └─ secondary CALL 0x0092b2a0  MissionTracker_FillTrackedTargetSlots_Inferred  [dualed R12-008 / parent]
        ├─ FUN_0040b3b0  map construct empty isnil19  [R13-017 residual]
        ├─ FUN_0040b890  StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred  [OWN R13-019]
        │     └─ FUN_0040bcd0  insert+RB isnil19  [residual unOWN]
        │           ├─ FUN_0040c060  buynode 0x1C
        │           ├─ FUN_0040b910  Lrotate isnil19
        │           └─ FUN_00446b10  Rrotate isnil19
        ├─ FUN_0040b440  erase+rebalance isnil19  [R13-018 residual]
        └─ FUN_0040bc10  erase-range isnil19  [R13-020 residual]
```

Partition system **inventory-transfer** explains why this VA was queued under that residual set (parent dual residual wave), not an inventory-grid product name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040b890-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040b890` | Port as **shared tree always-insert** for **isnil@+0x19 / color@+0x18 / key@+0x0C signed / node 0x1C**. **EAX=map, EBX=value*, stack out, RET 4**. Always `{it, inserted=true}` — **not** InsertOrFind. Pair with residual insert helper `0040bcd0` and parent siblings construct/erase/erase-range. Do not merge with isnil31 InsertOrFind `00402b30` or inventory product handlers. |
| Pair with | parent dual `0092b2a0`; residual insert `0040bcd0`; residual R13-017/018/020 siblings. |
| Naming caution | **Not** inventory grab/drop/grid. **Not** InsertOrFind. **Not** thiscall. **Not** unsigned-key / isnil29/31 plate. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer.md` residual tables (generic STL insert — not inventory UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0040b890`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (EAX map / EBX value / RET 4 / signed / always-insert).  
- Odd behavior preserved: decompiler phantom regs; out.inserted forced 1 even if helper shape varies.  
- `_Inferred` where English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
