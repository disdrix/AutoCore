# Dual A/B report — W24-O OWN `aa_004e22d0` + `aa_006753b0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W24-O  
**Scope:** VAs `0x004e22d0`, `0x006753b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e22d0` Tree_RotateLeft_Isnil15 | **accept** — left-rotate CF + ABI + isnil@0x15 + leaf sealed |
| `aa_006753b0` Tree_RotateRight_Isnil15 | **accept** — right-rotate CF + ABI + isnil@0x15 + leaf sealed |

---

## VA `0x004e22d0` — sealed facts

1. **Body:** `0x004e22d0`–`0x004e231d` (78 B; leaf; `RET 4` ×3).
2. **ABI:** **ECX**=map*; stack `node* x`; void return.
3. **Semantics:** Standard **left rotate**: hoist `x->right` to `x`'s place; `x` becomes left child of former right.
4. **isnil:** guard at `+0x15` before reparenting promoted child's former left.
5. **Root:** `head = *(map+4)`; root = `head->parent` (`head+4`).
6. **No recolor:** no `+0x14` access; pure structural.
7. **Callers (30):** shared with `006753b0` — insert/erase rebalance (e.g. `SkillElementTypeMap_TreeInsertAndRebalance` @ `0x0054de50`, `Map_EraseNode_IntKey`, `FUN_004baa30`, …).
8. **Name:** `Tree_RotateLeft_Isnil15` (Ghidra `FUN_004e22d0`; **Inferred**).
9. **Twins:** R-rotate same family `Tree_RotateRight_Isnil15` @ `0x006753b0`; staging L-rotate `Tree_RotateLeft` @ `0x00568b70` (isnil@`+0x49`).
10. **Decompile ≡ bytes** for CF.

### Gaps

- Product/PDB symbol (Inferred name only).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e22d0_Tree_RotateLeft_Isnil15.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004e22d0_Tree_RotateLeft_Isnil15.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e22d0_FUN_004e22d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e22d0_FUN_004e22d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tree_RotateLeft_Isnil15.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e22d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004e22d0_FUN_004e22d0.md` |
| Function named | `docs/reconstruction/functions/aa_004e22d0_Tree_RotateLeft_Isnil15.md` |
| Scratch | `docs/reconstruction/tmp/a_004e22d0.md` |

---

## VA `0x006753b0` — sealed facts

1. **Body:** `0x006753b0`–`0x00675401` (82 B; leaf; `RET 4` ×3).
2. **ABI:** **ECX**=map*; stack `node* x`; void return.
3. **Semantics:** Standard **right rotate**: hoist `x->left` to `x`'s place; `x` becomes right child of former left.
4. **isnil:** guard at `+0x15` before reparenting promoted child's former right.
5. **Root:** `head = *(map+4)`; root = `head->parent` (`head+4`).
6. **No recolor:** no `+0x14` access; pure structural.
7. **Callers (30):** same set as `004e22d0`.
8. **Name:** `Tree_RotateRight_Isnil15` (Ghidra `FUN_006753b0`; **Inferred**).
9. **Twins:** L-rotate same family `Tree_RotateLeft_Isnil15` @ `0x004e22d0`; staging R-rotate `Tree_RotateRight` @ `0x005681a0` (isnil@`+0x49`, near-clone).
10. **Decompile ≡ bytes** for CF.

### Gaps

- Product/PDB symbol (Inferred name only).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006753b0_Tree_RotateRight_Isnil15.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_006753b0_Tree_RotateRight_Isnil15.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006753b0_FUN_006753b0.md` |
| Annotated | `docs/reconstruction/raw/aa_006753b0_FUN_006753b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tree_RotateRight_Isnil15.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006753b0.cpp` |
| Function | `docs/reconstruction/functions/aa_006753b0_FUN_006753b0.md` |
| Function named | `docs/reconstruction/functions/aa_006753b0_Tree_RotateRight_Isnil15.md` |
| Scratch | `docs/reconstruction/tmp/a_006753b0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e22d0` | isnil15 map/set left-rotate leaf — pair with `Tree_RotateRight_Isnil15`; isnil@0x15 (not staging +0x49); no color writes; required for insert/erase rebalance parity on 0x18-class maps. |
| `006753b0` | isnil15 map/set right-rotate leaf — twin of left; near-clone of staging `Tree_RotateRight` with different isnil immediate; keep families separate. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ get_function_by_address).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- This report: `docs/agents/task-dual-ab-004e22d0-006753b0-w24o-report.md`
