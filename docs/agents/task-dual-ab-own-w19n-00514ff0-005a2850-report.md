# Dual A/B report — W19-N OWN (`aa_00514ff0`, `aa_005a2850`)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00514ff0`, `0x005a2850`. Dual A/B + three-rep refine.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `force_decompile` + `read_memory` + `analyze_function_complete` (+ xrefs / callees / callers). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).  
**Image base:** `0x400000`.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_00514ff0` / `0x00514ff0` | `Object_PurgeSkillHBListChain_Inferred` | **accept-with-gaps** |
| `aa_005a2850` / `0x005a2850` | `Map_Tree_Predecessor_Isnil15` | **accept-with-gaps** |

---

## Sealed facts — `0x00514ff0` Object_PurgeSkillHBListChain_Inferred

1. **ABI:** object in **ECX** (`__thiscall`); stack **one dword** (predicate ctx host); epilogue **`RET 4`**.
2. **Body:** `0x00514ff0`–`0x00515024` (then `CC` pad; sibling `FUN_00515030` at next).
3. **Gate:** if `*(u8*)(this+0x25) != 0` → list purge.
4. **List call:** `ECX = *(this+0xB0)` (pointer, not `lea`);  
   `CNDDoubleList_InvokePredicateAndRemove_Inferred(list, LAB_00512eb0, &stackArg, 0)`.
5. **Predicate `LAB_00512eb0`:** type tag `payload+0x1c==1` → RTTI Base→**CVOGHBSkillBase** → gate `hb+0x44` → if `*ctx!=0` set `hb+0x6a4=1` → `vtbl+0x18(1,0)` → return 1 (remove).
6. **Chain:** `ECX = *(this+0xAC)`; if non-null **`push 0; call self`** (does **not** forward caller ctx).
7. **Decomp noise falsified:** bare `__fastcall(int)`; `FUN_00514ff0(0)` with null this; omitted list ECX.
8. **Three-rep:** raw 2026-07-23 CF ≡ live/force decompile ≡ body/predicate/RTTI bytes (ABI corrected by bytes).
9. **Callers (context):** `Skill_ApplyStatusEffectLocal`, `FUN_0056d520` (weapon fire), `FUN_005c8fe0` / `FUN_004f62e0` (damage; often arg **1**), others (9 xrefs).

### Gaps

- Product English method name (keep `_Inferred`).
- Field English for `+0x25` / `+0xAC` / `hb+0x44` / `hb+0x6a4`.
- Runtime / bit-exact image diff.
- Full per-caller object-type taxonomy.

---

## Sealed facts — `0x005a2850` Map_Tree_Predecessor_Isnil15

1. **ABI:** **`ECX = Node**`** (`__fastcall`); no stack args; plain **`RET` (`C3`)**; void.
2. **Body:** `0x005a2850`–`0x005a28a0` (leaf; **no CALL**).
3. **Node (partial):** left`+0`, parent`+4`, right`+8`, isnil **`+0x15`**.
4. **CF (predecessor / `operator--`):**
   - isnil → `*pIt = right` (end → max);
   - else if left non-nil → rightmost of left;
   - else climb while `cur == parent->left`; maybe `*pIt = parent`.
5. **Not** successor, insert, rebalance, key compare, color, or map shell.
6. **Sibling:** same algorithm as `Map_Tree_Predecessor_Isnil49` (`0x00537770`) with different isnil offset.
7. **Callers:** **21** static map insert/find helpers (e.g. `Map_InsertOrFind_IntKey` dual already labels this predecessor).
8. **Three-rep:** raw 2026-07-23 ≡ live/force decompile ≡ body bytes.

### Gaps

- Product / MSVC template English name.
- Full node schemas per caller map (keys/colors vary).
- Runtime edge cases; bit-exact image diff.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00514ff0` | `reviews/A_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md` | `reviews/B_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md` | **accept-with-gaps** |
| `0x005a2850` | `reviews/A_aa_005a2850_Map_Tree_Predecessor_Isnil15.md` | `reviews/B_aa_005a2850_Map_Tree_Predecessor_Isnil15.md` | **accept-with-gaps** |

---

## Files

### `aa_00514ff0` / `Object_PurgeSkillHBListChain_Inferred`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00514ff0_FUN_00514ff0.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Object_PurgeSkillHBListChain_Inferred.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_00514ff0.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00514ff0_FUN_00514ff0.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00514ff0_FUN_00514ff0.annotated.md` |

### `aa_005a2850` / `Map_Tree_Predecessor_Isnil15`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_005a2850_Map_Tree_Predecessor_Isnil15.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_005a2850_Map_Tree_Predecessor_Isnil15.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_005a2850_Map_Tree_Predecessor_Isnil15.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_005a2850_FUN_005a2850.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Map_Tree_Predecessor_Isnil15.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_005a2850.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_005a2850_FUN_005a2850.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_005a2850_FUN_005a2850.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w19n-00514ff0-005a2850-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004e2600` | `CNDDoubleList_InvokePredicateAndRemove_Inferred` (list util callee) |
| `0x00512eb0` | `LAB_00512eb0` SkillBase stop/remove predicate |
| `0x00515030` | Sibling loop form (flag `+0x26`, walk `+0xAC`) |
| `0x00514e20` | `Skill_SiblingCastClear` (different predicate / skillId+TFID) |
| `0x00537770` | `Map_Tree_Predecessor_Isnil49` (same CF, isnil `+0x49`) |
| `0x005d2360` | `Map_InsertOrFind_IntKey` (consumer of predecessor) |

---

## Scaffold noise rejected

| Old alias | Action |
|---|---|
| `Named_CalleeOf_…Client_PacketDispatch_00514ff0` | **Ignore** — not product semantics |
| `Named_CalleeOf_…VOG_DEBUG_STOP_005a2850` | **Ignore** — assert noise in distant callers |

---

## AutoCore impact

- **No server port required** from this dual: both units are client object-HB bookkeeping and generic map iterator helpers.
- When porting client skill HB clear paths, treat `0x00514ff0` as list purge + linked-object hop — not wire RPC.
- Map ports must use the **correct isnil-offset predecessor** (`+0x15` here vs `+0x49` sibling); do not share one helper across layouts.
