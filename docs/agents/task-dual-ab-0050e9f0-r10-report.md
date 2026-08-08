# Dual A/B report — R10-030 OWN-ONLY (`0x0050e9f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-030**  
**Scope:** VA `0x0050e9f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including twin Rrotate `005a27f0` dual).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_xrefs_to` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-030**.  
**Parent dual:** `0x00407200` StdTree_InsertAndRebalance_Isnil21_Inferred (WQ9I-B).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0050e9f0` StdTree_Lrotate_Isnil21_Inferred | **accept-with-gaps** — Lrotate CF/ABI/RET4/isnil21/leaf sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Rrotate-merge / isnil29-merge / skill-only alias / wrong RET / non-leaf all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0050e9f0` — sealed facts

1. **Body:** `0x0050e9f0`–`0x0050ea3d` inclusive (**78 B** / `0x4E`); pad `CC CC`.
2. **ABI:** **`__thiscall`** ECX=tree; stack `Node* x`; **`ret 4`** (`C2 04 00` ×3 exits).
3. **Semantics:** MSVC-style **`_Tree` left-rotate** for **isnil@+0x21**:
   - `y = x->right` (+8); `x->right = y->left`.
   - If `y->left` not isnil (`+0x21 == 0`): `y->left->parent = x`.
   - `y->parent = x->parent`.
   - If `x` is root (`head->parent`): root = `y`; else if left-of-parent / right-of-parent reattach.
   - `y->left = x`; `x->parent = y`.
4. **Layout:** left@+0, parent@+4, right@+8, color@**+0x20**, isnil@**+0x21**; tree+4=head, head+4=root.
5. **Callees:** none (leaf).
6. **Callers (14):** `FUN_00405650`, `FUN_00407200`, `FUN_0041ba30`, `FUN_004e37e0`, `FUN_004e3e70`, `FUN_00511950`, `FUN_00511c00`, `FUN_0059d300`, `FUN_005a2ea0`, `FUN_005a3500`, `FUN_005a4590`, `FUN_005a4950`, `FUN_005ae2f0`, `FUN_005ae6d0`.
7. **Xrefs:** 30 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_Lrotate_Isnil21_Inferred` (Ghidra `FUN_0050e9f0`). Product demangle open → `_Inferred`. Reject old CVOGReaction chain alias as product name.
9. **Twins (CF):** Rrotate residual `005a27f0` (same family); peer dualed Lrotates isnil29 `004192a0` / isnil2D `0044e010` / isnil31 `00403e90`.
10. **Decompile ≡ raw CF**; RET + isnil imm `0x21` sealed via `read_memory`; parent call sites `MOV ECX,EDI` seal thiscall.

### Gaps

- Product / MSVC demangle for map value_type / instantiation.  
- Full dual of twin Rrotate `005a27f0` (role sealed; not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0050e9f0_StdTree_Lrotate_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0050e9f0_StdTree_Lrotate_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0050e9f0_FUN_0050e9f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0050e9f0_FUN_0050e9f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0050e9f0.cpp` |
| Function | `docs/reconstruction/functions/aa_0050e9f0_FUN_0050e9f0.md` |
| Function named | `docs/reconstruction/functions/aa_0050e9f0_StdTree_Lrotate_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00407200  StdTree_InsertAndRebalance_Isnil21_Inferred  [WQ9I-B dualed]
  └─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)   [OWN R10-030]
  └─ FUN_005a27f0  Rrotate isnil21                     [residual]
  └─ StdTree_Buynode_Val16_Isnil21_Inferred (0x00408990) [dualed]

Peer Lrotates (other families, dualed elsewhere):
  004192a0 StdTree_Lrotate_Isnil29
  0044e010 StdTree_LeftRotate_Isnil2D_Inferred
  00403e90 StdTree_Lrotate_Isnil31_Inferred
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0050e9f0-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0050e9f0` | Port as **shared StdTree left-rotate** for **isnil@+0x21 / color@+0x20 / node 0x28**. **thiscall** ECX=tree; stack `Node* x`; **ret 4**. Leaf. Pair with Rrotate `005a27f0` and InsertAndRebalance `00407200`. Do not merge with isnil29/2D/31 Lrotates. |
| Pair with | InsertAndRebalance isnil21; buynode Val16 isnil21; residual Rrotate isnil21; peer family Lrotates for CF reference only. |
| Naming caution | **Not** skill/CVOGReaction-specific. **Not** Rrotate (`005a27f0`). **Not** isnil29 Lrotate (`004192a0`) despite near-identical body (only isnil imm differs). |

---

## Parent merge handoff (not done here)

Parent dual WQ9I-B listed this rotate as residual gap — now dualed R10-030. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).
