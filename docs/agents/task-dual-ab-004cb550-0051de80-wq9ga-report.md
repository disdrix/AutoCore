# Dual A/B report — WQ9G-A OWN-ONLY (`aa_004cb550`, `aa_0051de80`)

**Date:** 2026-08-04  
**Agent:** WQ9G-A OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004cb550`, `0x0051de80`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-4 residual — isnil29 free-subtree for StdTree_EraseRange + SkillCNDHash complete dtor.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-A**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cb550` StdTree_FreeSubtree_Isnil29_Inferred | **accept-with-gaps** — free-subtree CF/ABI/RET4/left-walk/sole EraseRange caller sealed; product demangle open |
| `aa_0051de80` SkillCNDHash_CompleteDtor_Inferred | **accept-with-gaps** — complete dtor CF/ABI/vtbl/soft-lock/teardown order/sole scalar caller sealed; freelist host dual + product English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): false-complete decompile free, Map_FreeSubtree merge, scalar-as-complete, lock-abort, host-free-in-complete all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Sealed facts — `0x004cb550` StdTree_FreeSubtree_Isnil29_Inferred

1. **Body:** `0x004cb550`–`0x004cb584` inclusive (**53 B** / `0x35`); terminal **`C2 04 00`** + `CC` pad. Ghidra body end `004cb584`.

2. **ABI:** MSVC **`__fastcall`/`__thiscall`-style**.  
   - `ECX` = tree_base (threaded; unused in body except recursive pass)  
   - stack `node*`  
   - **void**  
   - **`ret 4`**

3. **Algorithm (bytes authority — decompiler incomplete):**  
   - If `node->isnil@+0x29 != 0`: return (do not free sentinel).  
   - Loop: recursive free **right** `@+8`; `left = node->left@+0`; `operator_delete(node)`; `node = left`; until isnil.  
   - **No value destroy.**

4. **Callers:**  
   - External (1): `StdTree_EraseRange_Isnil29_Inferred` (`0x004cbaa0`) full-clear @ `0x004cbabc` — `PUSH head->parent`.  
   - Self recursive @ `0x004cb567`.

5. **Name:** `StdTree_FreeSubtree_Isnil29_Inferred` — role High (CF + sole EraseRange free pair); product demangle **Inferred**.  
   Reject identity merge with `Map_FreeSubtree_Isnil29` @ `0x0051bbc0` (twin CF, different VA/caller pair).  
   Reject scaffold VOG_DEBUG_STOP path name.

6. **Decompile ⊊ bytes** for left-walk; **bytes sealed**. False-noreturn on `operator_delete` corrected (`ADD ESP,4` continues).

### Gaps — `004cb550`

1. Product/PDB demangle for map value_type of EraseRange callers.  
2. Whether value dtor is required before free for this instantiation (none in body).  
3. Runtime / bit-exact open.

### Dual A/B — `004cb550`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cb550_StdTree_FreeSubtree_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cb550_StdTree_FreeSubtree_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files — `004cb550`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cb550_FUN_004cb550.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb550_FUN_004cb550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cb550.cpp` |
| Function | `docs/reconstruction/functions/aa_004cb550_FUN_004cb550.md` |
| Function named | `docs/reconstruction/functions/aa_004cb550_StdTree_FreeSubtree_Isnil29_Inferred.md` |

---

## Sealed facts — `0x0051de80` SkillCNDHash_CompleteDtor_Inferred

1. **Body:** `0x0051de80`–`0x0051deea` inclusive (**107 B** / `0x6B`); terminal bare **`C3`** + `CC` pad. Immediately after scalar dtor `0x0051de60`–`0x0051de7d`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = skill CNDHash*  
   - no stack args  
   - **void**  
   - **bare `ret`**  
   - SEH `LAB_009a371b`

3. **Identity:** reinstalls vtbl **`PTR_FUN_009ce1b8`** (`mov [esi], 0x009ce1b8`). Same vtbl as dualed `SkillCNDHash_Ctor_Inferred` / scalar dtor vtbl[0].

4. **Algorithm:**  
   - If lock byte `@+0x1d != 0`: log `"HashError:Destructor, already locked for traversal"` + `"VOG_DEBUG_STOP"` then **continue** (no abort).  
   - `SkillCNDHash_DestroyBucketTable_Inferred` (`0x004cba60`) with `ECX=this`.  
   - `FUN_0059c8a0` with **`LEA ECX,[this+0x20]`** (freelist/slab host teardown).  
   - Does **not** free host object.

5. **Caller (1):** sole code xref — `SkillCNDHash_ScalarDeletingDtor_Inferred` (`0x0051de60`) @ `0x0051de63`.

6. **Name:** `SkillCNDHash_CompleteDtor_Inferred` — family High (string + vtbl + scalar caller); product English **Inferred**.  
   Reject scalar-dtor identity; reject inventory CNDHash merge; reject VOG_DEBUG_STOP scaffold name.

7. **Decompile ≡ bytes** for CF (live 2026-08-04 ≡ raw 2026-07-23). Soft-lock continue sealed.

### Gaps — `0051de80`

1. Product/PDB class name for skill CNDHash.  
2. Full dual of freelist/slab teardown `FUN_0059c8a0` (not OWN).  
3. Full vtbl method map beyond ctor/scalar/complete chain.  
4. Runtime / bit-exact open.

### Dual A/B — `0051de80`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051de80_SkillCNDHash_CompleteDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051de80_SkillCNDHash_CompleteDtor_Inferred.md` | **accept-with-gaps** |

### Files — `0051de80`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051de80_FUN_0051de80.md` |
| Annotated | `docs/reconstruction/raw/aa_0051de80_FUN_0051de80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillCNDHash_CompleteDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051de80.cpp` |
| Function | `docs/reconstruction/functions/aa_0051de80_FUN_0051de80.md` |
| Function named | `docs/reconstruction/functions/aa_0051de80_SkillCNDHash_CompleteDtor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
StdTree_EraseRange_Isnil29_Inferred (0x004cbaa0)   [dualed WQ9F-C]
  └─ full clear → StdTree_FreeSubtree_Isnil29_Inferred (0x004cb550)  [OWN WQ9G-A]
        // twin CF Map_FreeSubtree_Isnil29 @ 0x0051bbc0 is Map_EraseRange free — do not merge

SkillCNDHash_ScalarDeletingDtor_Inferred (0x0051de60)  [dualed WQ9F-H; vtbl[0]]
  └─ SkillCNDHash_CompleteDtor_Inferred (0x0051de80)   [OWN WQ9G-A]
        ├─ SkillCNDHash_DestroyBucketTable_Inferred (0x004cba60)  [dualed WQ9E-A]
        │     └─ SkillCNDHash_ReleaseChainsToFreelist_Inferred (0x004cb680)  [dualed WQ9F-A]
        └─ FUN_0059c8a0 (this+0x20 freelist/slab host)   [not dualled]
```

Parent depth-3 duals left free-subtree `004cb550` and complete dtor `0051de80` open; this wave seals them.

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cb550` | Port as **isnil29 free-subtree**: right recurse + left walk + node `delete`; **RET 4**; ECX threaded. Pair only with `StdTree_EraseRange_Isnil29` full-clear — **not** `Map_FreeSubtree_Isnil29` (`0x0051bbc0`). Ignore decomp noreturn on delete. |
| `0051de80` | Port as **complete object dtor** for skill CNDHash: vtbl `009ce1b8`, soft-log lock@+0x1d (continue), destroy bucket table, teardown host@+0x20. **Do not** free host here — scalar dtor does. **Do not** abort on lock. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs/assembly_context). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean uses meaningful names (not Ghidra iVar paste); `_Inferred` where product English unproven.  
- Odd behavior preserved: false-noreturn delete + missing left-walk in free decomp; soft-lock continue in complete dtor.  
- **Terminal false.**

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (and/or containers table for free-subtree)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004cb550-0051de80-wq9ga-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
