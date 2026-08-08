# Dual A/B report — WQ9H-J OWN-ONLY (`0x00408990`, `0x00408a30`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9H-J**  
**Scope:** VAs `0x00408990`, `0x00408a30` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-J**.  
**Work item:** WQ-009 depth-5 residual dual seal (CNDHash/freelist neighborhood residual leaves — sealed as **StdTree** buynode + head alloc, not freelist).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00408990` StdTree_Buynode_Val16_Isnil21_Inferred | **accept-with-gaps** — stdcall buynode CF/ABI/Val16/isnil21 sealed; product + parent insert dual open |
| `aa_00408a30` StdTree_BuyHeadNode_Isnil29_Inferred | **accept-with-gaps** — head shell CF/ABI/layout/callers sealed; self-link outside unit; product open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): freelist/CNDHash, Val24-merge, thiscall-host, full-Buyheadnode-inside-VA, Client-chain names all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00408990` — sealed facts

1. **Body:** `0x00408990`–`0x00408a13` inclusive (**132 B** / `0x84`); epilogue **`RET 0x14`** (`C2 14 00`).
2. **ABI:** `__stdcall`; 5 stack args; **EAX** = node\* \| null; entry is **not** thiscall (ECX used only for nested ctor).
3. **Semantics:** MSVC-style CNDHash-neighborhood residual that is actually **StdTree buynode**:
   - SEH frame (`LAB_009bc6b1`).
   - `operator_new(0x28)`.
   - If non-null: thiscall `FUN_004099b0` → left/parent/right; **Val16** @+0x10..+0x1c; **color** @+0x20; **isnil=0** @+0x21.
4. **Callers (1):** `FUN_00407200` (insert/rebalance; `"map/set<T> too long"`) @ `0x0040726d` — args `(head, where, head, value*, color=0)`; rebalance reads color @+0x20.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Name:** `StdTree_Buynode_Val16_Isnil21_Inferred` (Ghidra `FUN_00408990`). Reject freelist/CNDHash; reject Val24/isnil29 merge.
7. **Decompile ≡ raw CF**; size/ABI/layout sealed via `read_memory` + disasm.

### Gaps

- Product / PDB English for value_type (4 dwords).  
- Full dual of ctor `FUN_004099b0` and insert parent `FUN_00407200` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00408990_StdTree_Buynode_Val16_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00408990_StdTree_Buynode_Val16_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00408990_FUN_00408990.md` |
| Annotated | `docs/reconstruction/raw/aa_00408990_FUN_00408990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val16_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408990.cpp` |
| Function | `docs/reconstruction/functions/aa_00408990_FUN_00408990.md` |
| Function named | `docs/reconstruction/functions/aa_00408990_StdTree_Buynode_Val16_Isnil21_Inferred.md` |

---

## VA `0x00408a30` — sealed facts

1. **Body:** `0x00408a30`–`0x00408ab9` inclusive (**138 B** / `0x8A`); bare **`RET`** (`C3`).
2. **ABI:** no stack args; **EAX** = node\* (decompiler `void` is **false**).
3. **Semantics:** **StdTree head/sentinel shell** for isnil@+0x29 family:
   - SEH frame (`LAB_009bc690`).
   - `operator_new(0x30)`.
   - Zero left/parent/right (MSVC field-address null checks).
   - **color=1** (black) @+0x28; **isnil=0** @+0x29; Val24 region untouched.
4. **Callers (4):** `FUN_00405b40`, `FUN_00405e60`, `FUN_00405fb0`, `FUN_004d98f0` — each: `host+4 = node`; **isnil=1**; self-link L/P/R; `host+8 = 0`.
5. **Xrefs:** 4 UNCONDITIONAL_CALL.
6. **Name:** `StdTree_BuyHeadNode_Isnil29_Inferred` (Ghidra `FUN_00408a30`). Reject Client chain-of-caller scaffold; reject freelist; reject claiming self-link inside this VA.
7. **Decompile ≡ raw CF**; color/isnil stores sealed via `read_memory`.

### Gaps

- Product / PDB English for host tree types.  
- Full dual of tree ctor wrappers (not OWN).  
- OOM null-path odd (field checks / unconditional color stores) — preserve.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00408a30_StdTree_BuyHeadNode_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00408a30_StdTree_BuyHeadNode_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00408a30_FUN_00408a30.md` |
| Annotated | `docs/reconstruction/raw/aa_00408a30_FUN_00408a30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_BuyHeadNode_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408a30.cpp` |
| Function | `docs/reconstruction/functions/aa_00408a30_FUN_00408a30.md` |
| Function named | `docs/reconstruction/functions/aa_00408a30_StdTree_BuyHeadNode_Isnil29_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00407200  (insert/rebalance isnil@+0x21; map/set too long)
  └─ StdTree_Buynode_Val16_Isnil21_Inferred (0x00408990)   [OWN WQ9H-J]
        └─ FUN_004099b0 node construct Val16/isnil21       [residual]

FUN_00405fb0 / FUN_00405b40 / FUN_00405e60 / FUN_004d98f0  (tree ctors)
  └─ StdTree_BuyHeadNode_Isnil29_Inferred (0x00408a30)     [OWN WQ9H-J]
        → caller sets isnil=1 + self-link + size=0
```

Partition labeled these “CNDHash/freelist neighborhood residual leaves” by VA proximity to freelist/ctor depth-5 work; machine CF is **StdTree node buy + head shell**, not CNDHash freelist release.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00408990-00408a30-wq9hj-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00408990` | Port as **shared StdTree buynode** for **isnil@+0x21 / Val16 / size 0x28**. **stdcall RET 0x14**. Pair with insert `00407200` when dualed. Do not merge with Val24 isnil29 buynode `00407e30` or freelist helpers. |
| `00408a30` | Port as **head node shell** for **isnil@+0x29 / size 0x30**. Callers must set isnil=1 + self-link. Pair with tree ctors `00405b40`/`00405e60`/`00405fb0`/`004d98f0`. Contrast Val16 buynode `00408990`. |
| Pair with | insert/rebalance isnil21; isnil29 buynode/insert family; FreeHead tidy twins when dualed. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (container/STL residual — general StdTree, not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00408990`, `0x00408a30`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: MSVC field-address null checks on head shell; decompiler void return on head (machine EAX).  
- `_Inferred` naming (product English unproven); Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
