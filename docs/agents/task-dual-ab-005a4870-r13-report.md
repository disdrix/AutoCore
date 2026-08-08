# Dual A/B report — R13-008 OWN-ONLY (`0x005a4870`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-008** (dual start **2686**)  
**Scope:** VA `0x005a4870` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent erase `005a4590` re-dual, insert `005a4950` re-dual, payload ctor `005a42d0`, range shell `005a4c30`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` / `get_function_callees` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-008**.  
**Parent dual:** `0x005a4590` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-032).  
**System:** skills-abilities.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005a4870` StdTree_Buynode_Isnil21_Node0x24_Inferred | **accept-with-gaps** — alloc/construct CF/ABI/RET0x14/node0x24/isnil21/key+vec sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Val16-merge / isnil29-merge / freelist / thiscall-map / skill-product / void-return / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005a4870` — sealed facts

1. **Body:** `0x005a4870`–`0x005a48f5` inclusive (**134 B** / `0x86`); Ghidra body end `005a48f5`; pad `CC` after SEH unwind tail; insert sibling at `0x005a4950`.
2. **ABI:** **`__stdcall`**; stack `left`, `parent`, `right`, `value*`, `color`; **EAX** = node\* \| null; **`ret 0x14`** (`C2 14 00`).
3. **Semantics:** MSVC-style **`_Tree` buynode** for **isnil@+0x21 / node 0x24**:
   - SEH frame (`LAB_009a6321`).
   - `operator_new(0x24)`; OOM → return null without construct.
   - Store left/parent/right; `*value` → **key@+0x0C**.
   - `FUN_005a42d0` thiscall **ECX=node+0x10**, src=`value+4` — vector-like dword copy; begin/end/cap @ **+0x14/+0x18/+0x1c**.
   - **color@+0x20** from arg; **isnil=0@+0x21**.
4. **Layout:** node **0x24**; color@**+0x20**; isnil@**+0x21**; u32 key @+0x0C; vector-like @+0x10 (heap @+0x14/18/1c).
5. **Callees:** `operator_new` @ `0x00489892`; `FUN_005a42d0` (residual).
6. **Callers (1):** `FUN_005a4950` (always-insert dualed R12-033) @ `0x005a49e2`.
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_Buynode_Isnil21_Node0x24_Inferred` (Ghidra `FUN_005a4870`). Product demangle open → `_Inferred`.
9. **Twins / peers:** Val16 isnil21 buynode `00408990` (0x28; do not merge); Val24 isnil29 `00407e30`/`005a2de0` (do not merge); family insert `005a4950` + erase `005a4590` (parent).
10. **Decompile ≡ raw CF**; RET + size imm + isnil imm `0x21` + color@+0x20 sealed via `read_memory` / disasm.

### Gaps

- Product / MSVC demangle for map value_type (u32 key + vector-like).  
- Full dual of payload ctor `005a42d0` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005a4870_StdTree_Buynode_Isnil21_Node0x24_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005a4870_StdTree_Buynode_Isnil21_Node0x24_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005a4870_FUN_005a4870.md` |
| Annotated | `docs/reconstruction/raw/aa_005a4870_FUN_005a4870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Isnil21_Node0x24_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005a4870.cpp` |
| Function | `docs/reconstruction/functions/aa_005a4870_FUN_005a4870.md` |
| Function named | `docs/reconstruction/functions/aa_005a4870_StdTree_Buynode_Isnil21_Node0x24_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_005a4b70  InsertOrFind-style u32 key isnil21     [residual]
  └─ StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred (0x005a4950)  [R12-033 dualed]
        └─ StdTree_Buynode_Isnil21_Node0x24_Inferred (0x005a4870)      [OWN R13-008]
              └─ FUN_005a42d0  vector-like copy @ node+0x10            [residual]
        └─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)               [R10 dualed]
        └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)               [R11 dualed]

Sibling erase (parent dual R12-032; same node family):
  005a4590 StdTree_EraseAndRebalance_Isnil21_Inferred  — frees heap@+0x14; delete 0x24

Peer buynodes (do not merge):
  00408990 StdTree_Buynode_Val16_Isnil21_Inferred  (node 0x28)
  00407e30 / 005a2de0 Val24 isnil29                (node 0x30)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005a4870-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005a4870` | Port as **StdTree buynode** for **isnil@+0x21 / node 0x24**. **`__stdcall`** 5 args; **ret 0x14**; EAX=node\|null. `new(0x24)`; key@+0x0C; vector-like via `005a42d0` @+0x10 (heap @+0x14/18/1c); color@+0x20; isnil0@+0x21. Pair with dualed always-insert `005a4950` and erase `005a4590`. **Do not merge** with Val16/0x28 buynode `00408990` or isnil29 0x30 buynodes. |
| Pair with | Dualed insert R12-033; dualed erase parent R12-032; residual `005a42d0`; dualed L/R rotates isnil21. |
| Naming caution | **Not** insert (`005a4950`). **Not** erase (`005a4590`). **Not** Val16 isnil21 (`00408990`). **Not** skill-product exclusive despite skills-abilities partition. |

---

## Parent merge handoff (not done here)

Parent dual R12-032 listed this buynode as residual sibling of erase isnil21 — now dualed R13-008. Insert R12-033 already depends on this unit. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).
