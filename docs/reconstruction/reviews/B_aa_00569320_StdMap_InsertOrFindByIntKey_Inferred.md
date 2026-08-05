# Review B (skeptical / adversarial): `aa_00569320` StdMap_InsertOrFindByIntKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00569320` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-J) |
| **Counterpart** | `reviews/A_aa_00569320_StdMap_InsertOrFindByIntKey_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is lower_bound only (no insert) | **Falsified** — calls `FUN_005690a0` insert paths |
| 2 | This is map erase / clear | **Falsified** — no unlink of equal keys |
| 3 | Key is pointer / string | **Falsified** — `int` compare at `node[3]` |
| 4 | isnil at different offset than sibling maps | **Falsified** — `+0x49` matches Map_Predecessor dual |
| 5 | cdecl / caller cleans stack | **Falsified** — `ret 8` |
| 6 | Returns bool in EAX only | **Falsified** — pair written through out pointer |
| 7 | Many direct callers | **Falsified** — sole `FUN_00569560` |
| 8 | Leaf | **Falsified** — insert + predecessor callees |
| 9 | Value size sealed by this body | **Not proven** — value never sized here |
| 10 | Chain scaffold name is product | **Falsified** — noise |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find control flow | **High** | Corrupted tree if ported wrong |
| ABI ret 8 + pair out | **High** | Stack smash |
| isnil/key offsets | **High** | Infinite walk / bad compare |
| map/set family | **High** | Wrong container assumption low risk |
| Domain-specific name | **Open** | Cosmetic only |
| Runtime golden | **Open** | rare rebalance edge cases live in callee |

---

## 3. Cross-check against raw + bytes

Must preserve:

```
walk root by int key
if last left:
  if at *head: insert left; inserted=1; return
  else predecessor()
if node.key < *key: insert; inserted=1; return
else: inserted=0; it=node
```

Clean **must not**:

- Skip predecessor on non-leftmost left step
- Treat equal as insert
- Use wrong isnil offset
- Claim value layout sealed

---

## 4. Surviving contract for AutoCore

```c
// Prefer std::map<int, T>::insert / try_emplace for server ports.
// This unit is client MSVC tree glue — do not reimplement RB unless hooking retail.
std::pair<iterator, bool> insert_or_find(Map& m, int key);
```

---

## 5. Open questions

1. Value type / sizeof node beyond isnil.
2. Which game subsystem owns the maps that reach `FUN_00569560`.
3. Whether set-only (no value) vs map (value after key) for this instantiation.

**Verdict:** **accept-with-gaps**
