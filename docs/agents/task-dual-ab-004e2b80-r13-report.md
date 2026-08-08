# Dual A/B report — R13-004 OWN-ONLY (`0x004e2b80`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-004**  
**Scope:** VA `0x004e2b80` (`aa_004e2b80`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent insert `004e37e0` re-dual, peer insert `005a3500`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-004**.  
**System:** skills-abilities (partition assignment; unit role is generic MSVC `_Tree` buynode).  
**Parent dual:** `0x004e37e0` `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` (R12-012).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e2b80` StdTree_Buynode_Val16_Isnil21_Inline_Inferred | **accept-with-gaps** — CF/ABI/RET0x14/Val16/isnil21/inline construct sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-return / thiscall-map / Val24-merge / freelist / CVOGReaction-chain / SEH-peer-merge / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004e2b80` — sealed facts

1. **Body:** `0x004e2b80`–`0x004e2bce` inclusive (**79 B** / `0x4F`); pad `CC` @ `0x004e2bcf`.
2. **ABI:** **`__stdcall`** — 5 stack args `(left, parent, right, value4*, color)`; **`RET 0x14`** (`C2 14 00`); **EAX = node\*** | null. **Not** thiscall / pure void.
3. **Semantics:** MSVC-style **`_Tree` buynode** for **isnil@+0x21 / color@+0x20 / Val16@+0x10 / node 0x28**:
   - `operator_new(0x28)`.
   - On success: links left@+0, parent@+4, right@+8; **4 dword** value copy @+0x10..+0x1c from `*value4`; color@+0x20; isnil hard **0** @+0x21.
   - **+0x0C not written**.
   - **No SEH**; construct **inlined** (no NodeCtor helper call).
4. **Callees:** `operator_new` only (`0x00489892`).
5. **Callers (2):** `FUN_004e37e0` @ `0x004e3872` (parent dual; color push **0**); `FUN_005a3500` @ `0x005a3592` (peer insert clone; same push plate). Both `MOV ECX,EAX` after CALL.
6. **Xrefs:** 2 UNCONDITIONAL_CALL (same sites).
7. **Family peers (do not merge):**
   - `0x00408990` `StdTree_Buynode_Val16_Isnil21_Inferred` — same layout; **SEH + ctor `004099b0`**
   - `0x004099b0` `StdTree_NodeCtor_Val16_Isnil21_Inferred` — construct-only
   - `0x004088f0` empty head shell size 0x28
   - Val24/isnil29 `00407e30` / `005a2de0` (size 0x30)
8. **Name:** `StdTree_Buynode_Val16_Isnil21_Inline_Inferred` (Ghidra `FUN_004e2b80`). Product demangle open → `_Inferred`. Retire `Named_CalleeOf_*CVOGReaction*` scaffold.
9. **Decompile ≡ raw CF**; RET 0x14 + EAX return sealed via `disassemble_function` + `read_memory` (decompiler void is display gap, not CF conflict).
10. **Partition parent** `0x004e37e0` is wave score parent and **live structural caller**.

### Gaps

- Product / MSVC demangle for host map value_type.  
- Dual of peer insert clone `FUN_005a3500` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e2b80_StdTree_Buynode_Val16_Isnil21_Inline_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004e2b80_StdTree_Buynode_Val16_Isnil21_Inline_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004e2b80_FUN_004e2b80.md` |
| Annotated | `docs/reconstruction/raw/aa_004e2b80_FUN_004e2b80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val16_Isnil21_Inline_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e2b80.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Updat_004e2b80.cpp` |
| Function | `docs/reconstruction/functions/aa_004e2b80_FUN_004e2b80.md` |
| Function named | `docs/reconstruction/functions/aa_004e2b80_StdTree_Buynode_Val16_Isnil21_Inline_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_004e48b0  insert-or-find shell (residual)
  └─ FUN_004e37e0  StdTree_InsertAndRebalance_Val16_Isnil21_Inferred  [dualed R12-012]
        ├─ FUN_004e2b80  StdTree_Buynode_Val16_Isnil21_Inline_Inferred  [OWN R13-004]
        │     └─ operator_new(0x28)
        ├─ FUN_0050e9f0  Lrotate isnil21  [dualed]
        └─ FUN_005a27f0  Rrotate isnil21  [dualed]

FUN_005a3500  peer always-insert clone (residual)
  └─ FUN_004e2b80  StdTree_Buynode_Val16_Isnil21_Inline_Inferred  [OWN R13-004]

Peer family (do not merge):
  FUN_00407200  StdTree_InsertAndRebalance_Isnil21_Inferred  [dualed]
    └─ FUN_00408990  StdTree_Buynode_Val16_Isnil21_Inferred  [dualed; SEH+ctor]
          └─ FUN_004099b0  StdTree_NodeCtor_Val16_Isnil21_Inferred  [dualed]
```

Partition system **skills-abilities** explains residual queue membership (host proximity), not a skill-specific product name for this unit.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004e2b80-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e2b80` | Port as **shared StdTree buynode** for **isnil@+0x21 / color@+0x20 / Val16@+0x10 / node 0x28**. **`__stdcall`** 5 stack args; **ret 0x14**; EAX = node\*|null. Inline construct (no SEH/ctor helper). Pair with dualed insert `004e37e0` and residual peer insert `005a3500`. |
| Distinct from | Peer buynode `00408990` (SEH + NodeCtor); empty shell `004088f0`; Val24/isnil29 `00407e30`/`005a2de0`. |
| Pair with | dualed insert `004e37e0`; dualed L/R rotate `0050e9f0`/`005a27f0`; residual shell `004e48b0`; residual peer insert `005a3500`. |
| Naming caution | **Not** skill/ability product. **Not** freelist. **Not** identical twin of `00408990` (same family, different CF). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables (generic STL buynode — not skill UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

Name to register: `StdTree_Buynode_Val16_Isnil21_Inline_Inferred` @ `0x004e2b80` / `aa_004e2b80`.  
Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x004e2b80`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (stdcall RET 0x14; EAX return; inline Val16).  
- Odd behavior preserved: +0x0C not written; isnil forced 0 regardless of color; decompiler void display.  
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
