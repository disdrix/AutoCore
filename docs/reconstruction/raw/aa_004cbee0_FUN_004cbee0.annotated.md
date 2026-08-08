# Annotated: FUN_004cbee0 → StdMap_InsertOrFind_PairKey_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbee0` |
| **VA** | `0x004cbee0` |
| **Named** | `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` |
| **Ghidra** | `FUN_004cbee0` |
| **Agent** | WQ9F-D 2026-08-04 |
| **Companion raw** | `aa_004cbee0_FUN_004cbee0.md` |

---

## Role

MSVC-style **`std::map` insert-or-find** for the same **isnil@+0x29** / node-0x30 family as `004cbe20`, but keyed by a **two-dword pair**:
- **lo** = `value[0]` / node **+0x10** — compared **unsigned**
- **hi** = `value[1]` / node **+0x14** — compared **signed** (primary)

Order is MSVC-style pair: hi primary, lo secondary. On miss, inserts via dualed `StdTree_InsertAndRebalance_Isnil29_Inferred`. On hit, `{it, inserted=0}` without rewrite.

Sole caller in image: hint-insert parent `FUN_004cc220` fallthrough when hint path rejects.

---

## ABI / layout

| Item | Value |
|---|---|
| Convention | `__thiscall` |
| ECX | map shell* |
| Stack +4 | `InsertPair*` |
| Stack +8 | `const PairKey*` (`uint32_t lo; int32_t hi;` + optional mapped tail) |
| Return | void; **RET 8** |
| Node / isnil | same as int-key peer (+0x28 color / +0x29 isnil) |

---

## Control flow (annotated)

1. Load head/root; isnil@+0x29 gate.
2. Walk: go **right** (addLeft=0) when `node <= key`:
   - `node.hi < key.hi` **OR** (`node.hi <= key.hi` **AND** `node.lo <= key.lo` unsigned)
   - else go **left** (addLeft=1)
3. If addLeft and where==leftmost → insert addLeft=1.
4. Else if addLeft → predecessor `FUN_004cb4f0`.
5. If `node < key` strict (same hi/lo rules with strict lo) → insert with saved addLeft.
6. Else equal → `{where, 0}`.

---

## Callees / callers

| Role | Target |
|---|---|
| Insert+RB | `0x004cbb60` dualed |
| Predecessor | `0x004cb4f0` residual |
| Caller (1) | `FUN_004cc220` @ `0x004cc3ae` |

---

## Reject / narrow

- VOG_DEBUG_STOP Named_CalleeOf scaffold product — **reject**.
- Not int-key twin `004cbe20` (different compare width).
- Not Val12 pair maps (isnil@+0x19).
- Product demangle / English pair type (TFID vs custom) open → `_Inferred`.
