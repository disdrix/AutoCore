# Dual A/B report — R12-014 OWN-ONLY (`0x00511950`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-014**  
**Scope:** VA `0x00511950` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including residual buynode `005118b0`, InsertOrFind `00511b40`, peer Val16 insert `00407200`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-014**.  
**System:** skills-abilities.  
**Parent dual:** `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00511950` StdTree_InsertAndRebalance_Node24_Isnil21_Inferred | **accept-with-gaps** — always-insert CF/ABI/RET0x10/Node24/isnil21 sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): InsertOrFind-merge / Val16-peer-merge / isnil29-merge / wrong RET / skill-only / cdecl all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00511950` — sealed facts

1. **Body:** `0x00511950`–`0x00511b3a` inclusive (**491 B** / `0x1EB`); pad `CC` before `FUN_00511b40`.
2. **ABI:** **`__thiscall`** ECX=map; stack `(Node** out, char addLeft, Node* where, const void* value)`; **`ret 0x10`** (`C2 10 00`).
3. **Semantics:** MSVC-style **`_Tree` always-insert + RB rebalance** for **Node24 / isnil@+0x21**:
   - if `size ≥ 0xCCCCCCB` → throw `"map/set<T> too long"`.
   - buynode via `FUN_005118b0` (red, isnil0, `new(0x24)`); `size++`.
   - link under `where` (empty / left / right + leftmost/rightmost).
   - while parent color red: uncle recolor or L/R rotate; root black; `*out = n`.
4. **Layout:** left@+0, parent@+4, right@+8, int key@**+0x0C**, payload@+0x10.., color@**+0x20**, isnil@**+0x21**; node **0x24**; tree+4=head, tree+8=size.
5. **Callees:** `FUN_005118b0` (buynode), `FUN_0050e9f0` (Lrotate dualed), `FUN_005a27f0` (Rrotate dualed parent), length_error path. **One Lrotate path inlined**.
6. **Callers (1):** `FUN_00511b40` @ `0x00511b99`, `0x00511bd0` (InsertOrFind int-key shell).
7. **Xrefs:** 2 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` (Ghidra `FUN_00511950`). Product demangle open → `_Inferred`. **Not** Val16 peer name `StdTree_InsertAndRebalance_Isnil21_Inferred` (`00407200`).
9. **Decompile ≡ raw CF**; RET / size gate / isnil imm sealed via `read_memory`; call sites `MOV ECX,EDI` seal thiscall.

### Gaps

- Product / MSVC demangle for value_type (int key + vector of 0x10 elements).  
- Nested buynode `005118b0` and parent InsertOrFind `00511b40` residual (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00511950_StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00511950_StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00511950_FUN_00511950.md` |
| Annotated | `docs/reconstruction/raw/aa_00511950_FUN_00511950.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00511950.cpp` |
| Function | `docs/reconstruction/functions/aa_00511950_FUN_00511950.md` |
| Function named | `docs/reconstruction/functions/aa_00511950_StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00511b40  InsertOrFind int-key shell  [residual]
  └─ StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (0x00511950)  [OWN R12-014]
       ├─ FUN_005118b0  buynode Node24 isnil21  [residual]
       ├─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)  [R10-030 dualed]
       └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)  [R11-007 dualed parent]

Peer always-insert (other instantiation, dualed elsewhere):
  00407200 StdTree_InsertAndRebalance_Isnil21_Inferred  (Val16 / node 0x28)
  00406c40 StdTree_InsertAndRebalance_Isnil29_Inferred
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00511950-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00511950` | Port as **shared StdTree always-insert + rebalance** for **Node24 / isnil@+0x21 / color@+0x20**. **thiscall** ECX=map; stack `(out**, addLeft, where*, value*)`; **ret 0x10**. Max size **0xCCCCCCB**. Pair with dualed L/R rotates isnil21; residual buynode `005118b0` and InsertOrFind `00511b40`. Do **not** merge with Val16 insert `00407200`. |
| Pair with | dualed Rrotate parent `005a27f0`; dualed Lrotate `0050e9f0`; residual parent shell `00511b40`. |
| Naming caution | **Not** `StdTree_InsertAndRebalance_Isnil21_Inferred` (Val16 peer). **Not** InsertOrFind. **Not** skill product logic. |

---

## Parent merge handoff (not done here)

Parent dual R11-007 listed this VA among Rrotate callers — now dualed R12-014. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).

**Terminal:** false.
