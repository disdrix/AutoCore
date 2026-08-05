# Dual A/B report — W23-B OWN `aa_004076a0` + `aa_005681a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-B  
**Scope:** VAs `0x004076a0`, `0x005681a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004076a0` LogicUiEventQueue_InsertN | **accept-with-gaps** — insert-N CF + ABI + stride 0x138 + 1.5× grow sealed; nested helpers residual |
| `aa_005681a0` Tree_RotateRight | **accept** — right-rotate CF + ABI + isnil@0x49 + leaf sealed |

---

## VA `0x004076a0` — sealed facts

1. **Body:** `0x004076a0`–`0x00407991` (754 B; `RET 0xC`).
2. **ABI:** **ECX**=queue*; stack `insertAt`, `count`, `valueSrc`; void return.
3. **Semantics:** POD-construct 0x138 value → insert **N** elements (grow or in-place shift+fill).
4. **Stride:** `0x138` (magic `0xD20D20D3` div; lea×0x138; local 312 B).
5. **Max size:** `0x00D20D20` (`&DAT_00d20d20`); overflow → `FUN_00418130`.
6. **Growth:** prefer `cap + (cap>>1)`; else exact `size+count` via `FUN_004059c0`.
7. **Callers (2):** `LogicUiEventQueue_InsertOne_GrowPath` @ `0x00406943`; `FUN_00406840` @ `0x00406898`.
8. **Name:** `LogicUiEventQueue_InsertN` (Ghidra `FUN_004076a0`).
9. **Twin pattern:** `UiToastVector_InsertN` (`0x00403980`, stride 0x98).
10. **Decompile ≡ bytes** for CF.

### Gaps

- Product English for owning queue type.  
- Full 0x138 event record layout.  
- Nested helper duals (`00408880`, `00409a70`, `00406970`, `00409a90`, `00409ac0`).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004076a0_LogicUiEventQueue_InsertN.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004076a0_LogicUiEventQueue_InsertN.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004076a0_FUN_004076a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004076a0_FUN_004076a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LogicUiEventQueue_InsertN.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004076a0.cpp` |
| Function | `docs/reconstruction/functions/aa_004076a0_FUN_004076a0.md` |
| Function named | `docs/reconstruction/functions/aa_004076a0_LogicUiEventQueue_InsertN.md` |
| Scratch | `docs/reconstruction/tmp/a_004076a0.md` |

---

## VA `0x005681a0` — sealed facts

1. **Body:** `0x005681a0`–`0x005681f1` (82 B; leaf; `RET 4` ×3).
2. **ABI:** **ECX**=map*; stack `node* x`; void return.
3. **Semantics:** Standard **right rotate**: hoist `x->left` to `x`'s place; `x` becomes right child of former left.
4. **isnil:** guard at `+0x49` before reparenting promoted child's former right.
5. **Root:** `head = *(map+4)`; root = `head->parent` (`head+4`).
6. **No recolor:** no `+0x48` access; pure structural.
7. **Callers (4):** `FUN_00538780`, `FUN_00538ea0`, `FUN_00568c60`, `FUN_005690a0` (insert/erase rebalance).
8. **Name:** `Tree_RotateRight` (Ghidra `FUN_005681a0`; **Inferred**).
9. **Twin:** `Tree_RotateLeft` @ `0x00568b70` (sealed W19-K).
10. **Decompile ≡ bytes** for CF.

### Gaps

- Product/PDB symbol (Inferred name only).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005681a0_Tree_RotateRight.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005681a0_Tree_RotateRight.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005681a0_FUN_005681a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005681a0_FUN_005681a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tree_RotateRight.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005681a0.cpp` |
| Function | `docs/reconstruction/functions/aa_005681a0_FUN_005681a0.md` |
| Function named | `docs/reconstruction/functions/aa_005681a0_Tree_RotateRight.md` |
| Scratch | `docs/reconstruction/tmp/a_005681a0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004076a0` | Logic-UI queue insert-N — preserve 0x138 stride, 1.5× growth, max `0x00D20D20`, and construct-before-mutate; InsertOne path is thin wrapper at `004068f0`. |
| `005681a0` | Map/set tree right-rotate leaf — pair with `Tree_RotateLeft`; isnil@0x49; no color writes; required for insert/erase rebalance parity. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- This report: `docs/agents/task-dual-ab-004076a0-005681a0-w23b-report.md`
