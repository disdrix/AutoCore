# Dual A/B report — R11-007 OWN-ONLY (`0x005a27f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-007**  
**Scope:** VA `0x005a27f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including twin Lrotate `0050e9f0` re-dual).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-007**.  
**Parent dual:** `0x00407200` StdTree_InsertAndRebalance_Isnil21_Inferred (WQ9I-B).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005a27f0` StdTree_Rrotate_Isnil21_Inferred | **accept-with-gaps** — Rrotate CF/ABI/RET4/isnil21/leaf sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Lrotate-merge / isnil29-merge / skill-only alias / wrong RET / non-leaf all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005a27f0` — sealed facts

1. **Body:** `0x005a27f0`–`0x005a2841` inclusive (**82 B** / `0x52`); pad `CC`.
2. **ABI:** **`__thiscall`** ECX=tree; stack `Node* x`; **`ret 4`** (`C2 04 00` ×3 exits).
3. **Semantics:** MSVC-style **`_Tree` right-rotate** for **isnil@+0x21**:
   - `y = x->left` (`*x`); `x->left = y->right`.
   - If `y->right` not isnil (`+0x21 == 0`): `y->right->parent = x`.
   - `y->parent = x->parent`.
   - If `x` is root (`head->parent`): root = `y`; else if right-of-parent / left-of-parent reattach.
   - `y->right = x`; `x->parent = y`.
4. **Layout:** left@+0, parent@+4, right@+8, color@**+0x20**, isnil@**+0x21**; tree+4=head, head+4=root.
5. **Callees:** none (leaf).
6. **Callers (14):** `FUN_00405650`, `FUN_00407200`, `FUN_0041ba30`, `FUN_004e37e0`, `FUN_004e3e70`, `FUN_00511950`, `FUN_00511c00`, `FUN_0059d300`, `FUN_005a2ea0`, `FUN_005a3500`, `FUN_005a4590`, `FUN_005a4950`, `FUN_005ae2f0`, `FUN_005ae6d0`.
7. **Xrefs:** 35 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_Rrotate_Isnil21_Inferred` (Ghidra `FUN_005a27f0`). Product demangle open → `_Inferred`. Reject old CVOGReaction chain alias as product name.
9. **Twins (CF):** Lrotate dualed `0050e9f0` (same family); peer dualed Rrotates isnil29 `004192f0` / isnil2D `0042a840` / isnil31 `00403ee0`.
10. **Decompile ≡ raw CF**; RET + isnil imm `0x21` sealed via `read_memory`; parent call sites `MOV ECX,EDI` seal thiscall.

### Gaps

- Product / MSVC demangle for map value_type / instantiation.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005a27f0_StdTree_Rrotate_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005a27f0_StdTree_Rrotate_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005a27f0_FUN_005a27f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005a27f0_FUN_005a27f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005a27f0.cpp` |
| Function | `docs/reconstruction/functions/aa_005a27f0_FUN_005a27f0.md` |
| Function named | `docs/reconstruction/functions/aa_005a27f0_StdTree_Rrotate_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00407200  StdTree_InsertAndRebalance_Isnil21_Inferred  [WQ9I-B dualed]
  └─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)   [R10-030 dualed]
  └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)   [OWN R11-007]
  └─ StdTree_Buynode_Val16_Isnil21_Inferred (0x00408990) [dualed]

Peer Rrotates (other families, dualed elsewhere):
  004192f0 StdTree_Rrotate_Isnil29_Inferred
  0042a840 StdTree_Rrotate_Isnil2D_Inferred
  00403ee0 StdTree_Rrotate_Isnil31_Inferred
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005a27f0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005a27f0` | Port as **shared StdTree right-rotate** for **isnil@+0x21 / color@+0x20 / node 0x28**. **thiscall** ECX=tree; stack `Node* x`; **ret 4**. Leaf. Pair with Lrotate `0050e9f0` and InsertAndRebalance `00407200`. Do not merge with isnil29/2D/31 Rrotates. |
| Pair with | InsertAndRebalance isnil21; buynode Val16 isnil21; dualed Lrotate isnil21; peer family Rrotates for CF reference only. |
| Naming caution | **Not** skill/CVOGReaction-specific. **Not** Lrotate (`0050e9f0`). **Not** isnil29 Rrotate (`004192f0`) despite near-identical body (only isnil imm differs). |

---

## Parent merge handoff (not done here)

Parent dual WQ9I-B and R10-030 Lrotate listed this rotate as residual gap — now dualed R11-007. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).
