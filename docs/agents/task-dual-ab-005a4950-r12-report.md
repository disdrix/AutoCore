# Dual A/B report — R12-033 OWN-ONLY (`0x005a4950`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-033** (dual start **2646**)  
**Scope:** VA `0x005a4950` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including buynode `005a4870`, caller `005a4b70`, peer always-insert `00407200` re-dual).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-033**.  
**Parent dual:** `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007).  
**System:** skills-abilities.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005a4950` StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred | **accept-with-gaps** — always-insert CF/ABI/RET0x10/isnil21/node0x24/buynode sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): InsertOrFind-merge / Val16-0x28-merge / isnil29-merge / freelist / wrong RET / wrong size gate / cdecl all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005a4950` — sealed facts

1. **Body:** `0x005a4950`–`0x005a4b3a` inclusive (**491 B** / `0x1EB`); pad `CC`.
2. **ABI:** **`__thiscall`** ECX=map; stack `Node** out`, `char addLeft`, `Node* where`, `const void* value`; **`ret 0x10`** (`C2 10 00`).
3. **Semantics:** MSVC-style **always-insert + RB rebalance** for **isnil@+0x21 / node 0x24**:
   - Size gate: `size >= 0x0CCCCCCB` → `"map/set<T> too long"` / length_error / throw.
   - Buynode residual `FUN_005a4870` `(head, where, head, value*, color=0)` → `operator_new(0x24)`.
   - `size++`; link empty / left / right + extremum update.
   - While parent color red: uncle recolor or Lrotate `0050e9f0` / Rrotate `005a27f0` (one L path inlined with isnil@+0x21).
   - Root black @+0x20; `*out = node`.
4. **Layout:** node **0x24**; color@**+0x20**; isnil@**+0x21**; u32 key @+0x0C; vector-like payload @+0x10 (buynode + `005a42d0`).
5. **Callees:** `005a4870` buynode (residual); `0050e9f0` L (dualed); `005a27f0` R (dualed parent); length_error path.
6. **Callers (1):** `FUN_005a4b70` (2 sites @ `005a4bc9`, `005a4c00`) — InsertOrFind-style u32 key.
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred` (Ghidra `FUN_005a4950`). Product demangle open → `_Inferred`.
9. **Twins (CF):** peer always-insert isnil21 Val16/0x28 `00407200` (WQ9I-B dualed); shared L/R rotates isnil21 dualed.
10. **Decompile ≡ raw CF**; RET + size imm + isnil imm `0x21` + color@+0x20 sealed via `read_memory`; caller `MOV ECX,EDI` seals thiscall.

### Gaps

- Product / MSVC demangle for map value_type.  
- Full dual of buynode `005a4870` / caller `005a4b70` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005a4950_StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005a4950_StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005a4950_FUN_005a4950.md` |
| Annotated | `docs/reconstruction/raw/aa_005a4950_FUN_005a4950.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005a4950.cpp` |
| Function | `docs/reconstruction/functions/aa_005a4950_FUN_005a4950.md` |
| Function named | `docs/reconstruction/functions/aa_005a4950_StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_005a4b70  InsertOrFind-style u32 key isnil21  [residual]
  └─ StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred (0x005a4950)  [OWN R12-033]
        └─ FUN_005a4870  buynode node 0x24  [residual]
        └─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)  [R10-030 dualed]
        └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)  [R11-007 dualed; parent dual]

Peer (do not merge):
  00407200 StdTree_InsertAndRebalance_Isnil21_Inferred  [WQ9I-B; node 0x28 Val16]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005a4950-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005a4950` | Port as **StdTree always-insert + RB rebalance** for **isnil@+0x21 / node 0x24**. **thiscall** ECX=map; **ret 0x10**. Max size `≥ 0x0CCCCCCB` throws. Pair with buynode `005a4870`, caller InsertOrFind-style `005a4b70`, dualed L/R rotates isnil21. **Do not merge** with Val16/0x28 always-insert `00407200`. |
| Pair with | Residual buynode 0x24; residual InsertOrFind `005a4b70`; dualed Lrotate/Rrotate isnil21; peer Val16 always-insert for CF reference only. |
| Naming caution | **Not** InsertOrFind (`005a4b70`). **Not** the Val16/0x28 always-insert (`00407200`). **Not** skill-product-specific despite skills-abilities partition. |

---

## Parent merge handoff (not done here)

Parent dual R11-007 Rrotate listed this unit among 14 callers — now dualed R12-033 as the always-insert consumer for the node-0x24 instantiation. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).
