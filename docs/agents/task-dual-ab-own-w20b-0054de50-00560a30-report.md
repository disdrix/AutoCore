# Dual A/B report — W20-B OWN (`aa_0054de50`, `aa_00560a30`)

**Date:** 2026-07-29  
**Agent:** W20-B OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0054de50`, `0x00560a30`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function bounds / xrefs / callees / callers). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` (image base `0x400000`).  
**Dual A/B:** fidelity (A) vs adversarial (B) reviews — not two programs.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_0054de50` / `0x0054de50` | `SkillElementTypeMap_TreeInsertAndRebalance` | **accept-with-gaps** |
| `aa_00560a30` / `0x00560a30` | `PhysSim_MergeHosts_Inferred` | **accept-with-gaps** |

---

## Sealed facts — `0x0054de50` SkillElementTypeMap_TreeInsertAndRebalance

1. **ABI:** MSVC **`__thiscall`** — **ECX = MapShell** (head `@+4`, size `@+8`); stack **`outIt*`, `addLeft`, `where*`, `value*`**; epilogue **`RET 0x10`** (`C2 10 00`). Body **`0x0054de50`–`0x0054e03a`**.

2. **Always-insert:** no key compare. `FUN_006173a0` → `operator_new(0x18)`, copy **2 dwords** to node `+0x0C`/`+0x10`, color **0** (red) at `+0x14`, isnil **0** at `+0x15`. Then `size++`.

3. **Link:** empty tree (where == head) sets root/leftmost/rightmost; `addLeft==0` → right (+ rightmost); else left (+ leftmost).

4. **RB rebalance:** while parent color red; uncle recolor / rotates (`FUN_004e22d0`, `FUN_006753b0` + one inlined L-rotate with isnil guard `+0x15`); root painted black; `*outIt = newNode`.

5. **Throw:** if `size > 0x1ffffffd` → `"map/set<T> too long"` @ `0x00a1530c` via `_CxxThrowException`. Cap is **distinct** from staging map's `0x4924922`.

6. **Sole static caller:** `SkillElementTypeMap_InsertOrFind` (`0x0054eb20`) at `0x0054eb79` / `0x0054ebb0` (miss paths only).

7. **Name:** `SkillElementTypeMap_TreeInsertAndRebalance` — descriptive from parent dual + node family. Former `FUN_0054de50` / VOG_DEBUG scaffold chain (**misleading**).

8. **Three-rep:** raw 2026-07-23 CF ≡ live decompile ≡ body bounds / prologue size cmp / epilogue / string bytes.

### Gaps (`0054de50`)

1. Product/PDB English for map / method.  
2. Dual of rotate helpers + node ctor (roles sealed only).  
3. Runtime / bit-exact / differential — open.

---

## Sealed facts — `0x00560a30` PhysSim_MergeHosts_Inferred

1. **ABI:** **`__thiscall`** — **ECX = world/sim**; stack **`Host* dest`**, **`Host* src`**; epilogue **`RET 0x8`** (`C2 08 00`); returns **dest***. Body **`0x00560a30`–`0x00560c8b`**. Parent flush seals `mov ecx,esi` before call (decomp often omits this).

2. **Equal hosts:** `dest == src` → return dest, no side effects.

3. **Activate:** if `host+0x29 == 0` → `PhysSim_ActivateHost` (`0x0055eb80`) for dest and/or src.

4. **Merge work:**  
   - List at **`host+0x68`** via `FUN_00560750`  
   - Append ptr vectors at **`+0x3c`**, **`+0x4c`**, **`+0x58`** (elem size 4; grow `FUN_005b3300`)  
   - Rebind: body `item+0x44=dest`, index `item+0x58`; others `item+0x10` / `item+0x14`  
   - Max scalar `+0x08`; add `+0x0c/+0x10/+0x18/+0x14`  
   - Append 8-byte vector at **`+0x74`**

5. **World host table:** data `world+0x08`, count `world+0x0c`; swap-remove by `src+0x24` index; fix moved host index; `count--`.

6. **Teardown:** `dest+0x28` dirty = OR of both flags; `(*src->vtbl)(src, 1)` scalar-deleting destroy; return dest.

7. **Sole static caller:** `PhysSim_FlushPendingBodyPairs_Inferred` (`0x00561320`) @ `0x0056134b` when body hosts (`body+0x44`) differ.

8. **Name:** `PhysSim_MergeHosts_Inferred` — descriptive from parent dual language. Former `FUN_00560a30` / SpawnPoint scaffold chain (**misleading**).

9. **Three-rep:** raw ≡ live decompile ≡ prologue/epilogue/destroy bytes.

### Gaps (`00560a30`)

1. Product English host/island type.  
2. Dual of `FUN_00560750` (+0x68 list).  
3. English labels for vectors B/C/D.  
4. Runtime / bit-exact — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x0054de50` | `reviews/A_aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance.md` | `reviews/B_aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance.md` | **accept-with-gaps** |
| `0x00560a30` | `reviews/A_aa_00560a30_PhysSim_MergeHosts_Inferred.md` | `reviews/B_aa_00560a30_PhysSim_MergeHosts_Inferred.md` | **accept-with-gaps** |

---

## Files

### `aa_0054de50` / `SkillElementTypeMap_TreeInsertAndRebalance`

| Kind | Absolute path |
|------|----------------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0054de50_FUN_0054de50.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\SkillElementTypeMap_TreeInsertAndRebalance.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_0054de50.cpp` |
| Raw (+ re-verify append) | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0054de50_FUN_0054de50.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0054de50_FUN_0054de50.annotated.md` |

### `aa_00560a30` / `PhysSim_MergeHosts_Inferred`

| Kind | Absolute path |
|------|----------------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00560a30_PhysSim_MergeHosts_Inferred.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00560a30_PhysSim_MergeHosts_Inferred.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00560a30_PhysSim_MergeHosts_Inferred.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00560a30_FUN_00560a30.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\PhysSim_MergeHosts_Inferred.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_00560a30.cpp` |
| Raw (+ re-verify append) | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00560a30_FUN_00560a30.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00560a30_FUN_00560a30.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w20b-0054de50-00560a30-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0054eb20` | `SkillElementTypeMap_InsertOrFind` (sole caller of `0054de50`) |
| `0x006173a0` | Node construct `new(0x18)` for skill-element map |
| `0x004e22d0` / `0x006753b0` | RB rotates used by insert |
| `0x00561320` | `PhysSim_FlushPendingBodyPairs_Inferred` (sole caller of `00560a30`) |
| `0x0055eb80` | `PhysSim_ActivateHost` |
| `0x00560750` | Merge host+0x68 list |
| `0x005b3300` | Vector grow |
| `0x0055efd0` | `PhysSim_PushBodyPair_Inferred` (pair producer) |
| `0x00561910` | Island step (calls flush) |

---

## AutoCore impact

- **Skills catalog:** type-id → factory map inserts go through insert-or-find; **always-insert helper must not** be used for equal-key refresh; size cap **`0x1ffffffd`** and node **0x18** are specific to this map family (not staging `0x50` / cap `0x4924922`).
- **Physics:** when body pairs cross hosts, flush merges hosts via **world in ECX** + dest/src hosts; keep body host field **`+0x44`** consistent with rebind; do not model merge as free-standing 2-arg or as spawn-point logic.
