# Dual A/B report — W26-Q OWN `aa_00573170` + `aa_00418c10`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-Q  
**Scope:** VAs `0x00573170`, `0x00418c10` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md` (W26-Q).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00573170` StdTree_Lrotate_Val12 | **accept** — Val12 left-rotate CF/ABI/isnil@+0x19 + leaf sealed |
| `aa_00418c10` StdTree_Rrotate_Val12 | **accept** — Val12 right-rotate CF/ABI/isnil@+0x19 + leaf sealed |

---

## VA `0x00573170` — sealed facts

1. **Body:** `0x00573170`–`0x005731BE` exclusive (**78** B; pad `CC` after last `RET 4`).
2. **ABI:** **`__thiscall`**; ECX = tree (`_Myhead` @ `this+4`); stack `node* x`; **void**; **`RET 4`**.
3. **Semantics:** MSVC `_Tree` **left-rotate** about `x`: `y = x->right`; splice `y->left` under `x`; reattach `y` (root / left / right of parent); `y->left = x`.
4. **Classification:** **leaf** (0 callees).
5. **Callers (13):** `FUN_004188e0`, `FUN_0044a8c0`, `FUN_004e4130`, `FUN_0051c1c0`, `FUN_00539210`, `FUN_005399f0`, `FUN_00567450`, `FUN_00573250`, `FUN_00573510`, `FUN_005ae4e0`, `FUN_005ae990`, `FUN_005e13b0`, `FUN_005e15a0`.
6. **Xrefs:** 26.
7. **Node:** Val12 / 0x1c — left@0 parent@4 right@8 value@0x0c color@0x18 **isnil@0x19** (matches `StdTree_Buynode_Val12`).
8. **Name:** `StdTree_Lrotate_Val12` (Ghidra `FUN_00573170`). Prior Named_* skill-status name is **narrow**.
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / full MSVC demangle per map type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00573170_StdTree_Lrotate_Val12.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00573170_StdTree_Lrotate_Val12.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00573170_FUN_00573170.md` |
| Annotated | `docs/reconstruction/raw/aa_00573170_FUN_00573170.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00573170.cpp` |
| Function | `docs/reconstruction/functions/aa_00573170_FUN_00573170.md` |
| Function named | `docs/reconstruction/functions/aa_00573170_StdTree_Lrotate_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_00573170.md` |

---

## VA `0x00418c10` — sealed facts

1. **Body:** `0x00418c10`–`0x00418c62` exclusive (**82** B; pad `CC` after last `RET 4`).
2. **ABI:** **`__thiscall`**; ECX = tree; stack `node* x`; **void**; **`RET 4`**.
3. **Semantics:** MSVC `_Tree` **right-rotate** about `x`: `y = x->left`; splice `y->right` under `x`; reattach `y`; `y->right = x`.
4. **Classification:** **leaf** (0 callees).
5. **Callers (13):** same set as Lrotate.
6. **Xrefs:** 32.
7. **Node:** same Val12 layout (isnil@+0x19).
8. **Name:** `StdTree_Rrotate_Val12` (Ghidra `FUN_00418c10`). Prior Named_* skill-status name is **narrow**.
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / full MSVC demangle per map type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00418c10_StdTree_Rrotate_Val12.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00418c10_StdTree_Rrotate_Val12.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00418c10_FUN_00418c10.md` |
| Annotated | `docs/reconstruction/raw/aa_00418c10_FUN_00418c10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00418c10.cpp` |
| Function | `docs/reconstruction/functions/aa_00418c10_FUN_00418c10.md` |
| Function named | `docs/reconstruction/functions/aa_00418c10_StdTree_Rrotate_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_00418c10.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00573170` / `00418c10` | Port any Val12 `std::map`/`set` insert/erase rebalance with **identical** L/R rotate pointer surgery (isnil@+0x19). Closes W25-G residual on rotate helper product names with structural names. Prefer one shared helper pair rather than inlining per map. |
| Pair with | `StdTree_Buynode_Val12` (`0x005ae220`) and `Map_TreeInsertAndRebalance_Val12` (`0x0051c1c0`) already dualed. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names inferred from MSVC `_Lrotate`/`_Rrotate` + Val12 layout evidence.
