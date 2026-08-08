# Dual A/B report — R13-030 OWN-ONLY (`0x005118b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-030**  
**Scope:** VA `0x005118b0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including residual vector ctor `005114e0`, parent insert already dualed `00511950`, InsertOrFind `00511b40`, peer Val16 buynode `00408990`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` / `get_function_callees` + `read_memory` + `disassemble_function` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-030**.  
**System:** skills-abilities.  
**Parent dual:** `0x00511950` StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (R12-014).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005118b0` StdTree_Buynode_Node24_Isnil21_Inferred | **accept-with-gaps** — buynode CF/ABI/RET0x14/Node24/isnil21 sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Val16-merge / isnil29-merge / freelist / thiscall-map / skill-only / wrong RET all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005118b0` — sealed facts

1. **Body:** `0x005118b0`–`0x00511935` inclusive (**134 B** / `0x86`); `RET 0x14` then EH tail / `CC` pad before `FUN_00511950`.
2. **ABI:** **`__stdcall`**; stack `(left*, parent*, right*, value*, color)`; **`ret 0x14`** (`C2 14 00`); **EAX** = node* | null.
3. **Semantics:** MSVC-style **`_Tree` buynode** for **Node24 / isnil@+0x21**:
   - `operator_new(0x24)`; null → return null.
   - write left/parent/right at +0/+4/+8.
   - `key = *value` at **+0x0C**.
   - residual `FUN_005114e0` thiscall on **node+0x10** with source `value+4` (vector-of-0x10-byte-elements copy).
   - `color = arg` at **+0x20**; **isnil = 0** at **+0x21**.
4. **Layout:** left@+0, parent@+4, right@+8, int key@**+0x0C**, payload@+0x10.., color@**+0x20**, isnil@**+0x21**; node **0x24**.
5. **Callees:** `operator_new` (`0x00489892`), `FUN_005114e0` (`0x005114e0`, residual R13-029).
6. **Callers (1):** `FUN_00511950` @ `0x005119e2` (parent dual R12-014; passes red `color=0`).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_Buynode_Node24_Isnil21_Inferred` (Ghidra `FUN_005118b0`). Product demangle open → `_Inferred`. **Not** Val16 peer name `StdTree_Buynode_Val16_Isnil21_Inferred` (`00408990`).
9. **Decompile ≡ raw CF**; RET / `new(0x24)` / isnil imm sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for value_type (int key + vector element type).  
- Nested vector ctor `005114e0` residual (R13-029, not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005118b0_StdTree_Buynode_Node24_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005118b0_StdTree_Buynode_Node24_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005118b0_FUN_005118b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005118b0_FUN_005118b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Node24_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005118b0.cpp` |
| Function | `docs/reconstruction/functions/aa_005118b0_FUN_005118b0.md` |
| Function named | `docs/reconstruction/functions/aa_005118b0_StdTree_Buynode_Node24_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00511b40  InsertOrFind int-key shell  [residual R13-031]
  └─ StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (0x00511950)  [R12-014 dualed parent]
       ├─ StdTree_Buynode_Node24_Isnil21_Inferred (0x005118b0)  [OWN R13-030]
       │    └─ FUN_005114e0  vector payload copy  [residual R13-029]
       ├─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)  [R10-030 dualed]
       └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)  [R11-007 dualed]

Peer buynode (other instantiation, dualed elsewhere):
  00408990 StdTree_Buynode_Val16_Isnil21_Inferred  (node 0x28 / Val16)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005118b0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005118b0` | Port as **shared StdTree buynode** for **Node24 / isnil@+0x21 / color@+0x20**. **`__stdcall`**; stack `(left*, parent*, right*, value*, color)`; **ret 0x14**. `new(0x24)`; key@+0x0C; vector payload via residual `005114e0`; isnil forced 0. Pair with dualed parent insert `00511950`. Do **not** merge with Val16 buynode `00408990`. |
| Pair with | dualed parent insert `00511950`; residual vector ctor `005114e0`. |
| Naming caution | **Not** `StdTree_Buynode_Val16_Isnil21_Inferred` (Val16 peer). **Not** skill product logic. **Not** freelist/CNDHash. |

---

## Parent merge handoff (not done here)

Parent dual R12-014 listed this VA as residual buynode — now dualed R13-030. Registry / matrix / system ledger / dual_ab_pairs updates are parent-merge responsibility (forbidden for this OWN agent).

**Terminal:** false.
