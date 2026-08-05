# Dual A/B report — W28-O OWN-ONLY (`0x005adfa0`, `0x00418bf0`)

**Date:** 2026-07-29  
**Agent:** W28-O OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005adfa0`, `0x00418bf0`. Dual A/B + artifacts.  
**Partition:** wave28  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005adfa0` StdTree_Min_Val12 | **accept** — Val12 `_Tree_min` / leftmost; cdecl; `ret`; return node* in EAX; decomp void is defect |
| `aa_00418bf0` StdTree_Max_Val12 | **accept** — Val12 `_Tree_max` / rightmost; cdecl; `ret`; return node* in EAX; decomp void is defect |

---

## `aa_005adfa0` — StdTree_Min_Val12

### Sealed facts

1. **Body:** `0x005adfa0`–`0x005adfba` exclusive (**26** B / `0x1A`). Final **`c3`** (`ret`); following `cc` pad.

2. **ABI:** **`__cdecl`**; one stack arg `node*`; returns **`node*`** in **EAX**; no stack cleanup.

3. **Algorithm (bytes — authority):**
   ```
   left = node->left
   if left.isnil@+0x19: return node
   do { node = left; left = node->left } while !left.isnil
   return node   // leftmost non-nil
   ```

4. **Callees:** none (leaf).

5. **Callers (6):** `FUN_004188e0`, `FUN_004e4130`, `FUN_005399f0`, `FUN_00573250`, `FUN_005ae990`, `FUN_005e15a0` — Val12 erase leftmost (`head->left`) fixup.

6. **Node:** Val12 / 0x1c — left@0 parent@4 right@8 value@0x0c color@0x18 **isnil@0x19**.

7. **Name:** structural `StdTree_Min_Val12`. Prior `Named_*RecvSkillStatusEffect*` is **narrow**.

8. **Decompiler:** live ≡ 2026-07-23 raw marks **void** and walks into nil — **rejected**. Bytes + caller EAX use seal return.

### Gaps

1. Product/MSVC demangle per map instantiation.  
2. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005adfa0_StdTree_Min_Val12.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005adfa0_StdTree_Min_Val12.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005adfa0_StdTree_Min_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005adfa0_StdTree_Min_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_005adfa0_StdTree_Min_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005adfa0_FUN_005adfa0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Min_Val12.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005adfa0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005adfa0_FUN_005adfa0.md` |
| Annotated | `docs/reconstruction/raw/aa_005adfa0_FUN_005adfa0.annotated.md` |

---

## `aa_00418bf0` — StdTree_Max_Val12

### Sealed facts

1. **Body:** `0x00418bf0`–`0x00418c0b` exclusive (**27** B / `0x1B`). Final **`c3`** (`ret`); `cc` pad; next symbol `FUN_00418c10` = `StdTree_Rrotate_Val12`.

2. **ABI:** **`__cdecl`**; one stack arg `node*`; returns **`node*`** in **EAX**.

3. **Algorithm (bytes — authority):**
   ```
   right = node->right  // +8
   if right.isnil@+0x19: return node
   do { node = right; right = node->right } while !right.isnil
   return node   // rightmost non-nil
   ```

4. **Callees:** none (leaf).

5. **Callers (6):** same set as Min — Val12 erase rightmost (`head->right`) fixup.

6. **Node:** same Val12 layout (isnil@+0x19).

7. **Name:** structural `StdTree_Max_Val12`. Prior Named_* alias is **narrow**.

8. **Decompiler:** same void/walk-into-nil defect class as Min — **rejected**.

### Gaps

1. Product/MSVC demangle.  
2. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00418bf0_StdTree_Max_Val12.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00418bf0_StdTree_Max_Val12.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00418bf0_StdTree_Max_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00418bf0_StdTree_Max_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_00418bf0_StdTree_Max_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00418bf0_FUN_00418bf0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Max_Val12.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00418bf0.cpp` |
| Raw | `docs/reconstruction/raw/aa_00418bf0_FUN_00418bf0.md` |
| Annotated | `docs/reconstruction/raw/aa_00418bf0_FUN_00418bf0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### StdTree_Min_Val12 (`0x005adfa0`)

- Port as **generic Val12 Tree_min**, not skill-status-specific logic.
- Preserve **cdecl + return node***; do **not** copy Ghidra void decompile.
- isnil @ **+0x19**; walk **left** (`+0`) only.
- Used after erase when recomputing head leftmost.

### StdTree_Max_Val12 (`0x00418bf0`)

- Port as **generic Val12 Tree_max** twin of Min.
- Preserve **cdecl + return node***; walk **right** (`+8`) only.
- Used after erase when recomputing head rightmost.
- Do not merge with neighbor Rrotate @ `0x00418c10`.

### Family context (owned elsewhere)

| Helper | VA | Role |
|--------|-----|------|
| StdTree_Buynode_Val12 | `0x005ae220` | W24-I |
| StdTree_Lrotate_Val12 | `0x00573170` | W26-Q |
| StdTree_Rrotate_Val12 | `0x00418c10` | W26-Q |
| StdTree_EraseNode_Val12 | `0x005ae990` | W27-T (calls Min/Max) |

---

## Notes

- No Launcher. No parent ledger / partition map / COVERAGE_LEDGER edits.
- Did not write artifacts for non-owned erase callers (`005ae990` dualed W27-T; `004e4130` dualed W27-Q; etc.).
- **Critical:** scaffold raw decompile is historically preserved but **not** behavior-authoritative for these two units; clean/annotated follow `read_memory` bytes.
