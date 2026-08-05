# Review A (reconstruction fidelity): `aa_004bacf0` StdMap_EraseRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bacf0` |
| **VA** | `0x004bacf0` |
| **Canonical name (Ghidra)** | `FUN_004bacf0` |
| **Proposed name** | `StdMap_EraseRange_Inferred` (**High** role as MSVC `map`/`set` range erase; product symbol absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004bacf0` — chain-of-callers only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004bacf0_StdMap_EraseRange_Inferred.md` |
| **System** | STL / used by `client-fx` NDSpecialFX map `@+0x228` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**MSVC-style red-black tree map/set range erase** on a small map facade:

```
map_facade {
  /* +0x00 */  // (unused here)
  /* +0x04 */  node *head;   // sentinel / end node
  /* +0x08 */  size_t size;
}
```

Nodes use classic layout: `left@0`, `parent@4`, `right@8`, …, **`isnil` flag @ `+0x15`**.

### Full-range fast path

If `first == *head` **and** `last == head` (erase entire tree):

1. `FUN_004ba770(head->parent)` — recursive free of all non-nil nodes.
2. Reset head self-links (`left=parent=right=head`), `size=0`.
3. `*out_it = *head` (begin == end).
4. Return.

### Partial range

While `first != last`:

1. Compute **in-order successor** of `first` (standard tree successor: right-min, else parent climb) using `isnil @ +0x15`.
2. `FUN_004baa30(&first, first)` — single-node erase (`"invalid map/set<T> iterator"` throw string inside `004baa30` seals STL identity).
3. Advance `first` to successor.

Then `*out_it = first`.

**Not** list unlink (`005875c0`), not FX list clearer (`004b85d0`) though teardown uses this on the FX map.

Callers: `FUN_004b99c0` (TeardownCore), `FUN_004badb0`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004bacf0` |
| Single erase | live `FUN_004baa30` (throw string `"invalid map/set<T> iterator"`) |
| Recursive free | live `FUN_004ba770` (isnil gate, recurse right, delete) |
| Callers | `get_function_callers` → `004b99c0`, `004badb0` |
| Parent dual | `A_aa_004b99c0_NDSpecialFX_TeardownCore_Inferred.md` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004bacf0` |
| Function record | `docs/reconstruction/functions/aa_004bacf0_FUN_004bacf0.md` |

**This pass:** live decompile; callees; callers. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = map facade*
void __thiscall StdMap_EraseRange_Inferred(
    void *map,       // this — head @ +4, size @ +8
    void **out_it,   // param_2 — receives end iterator
    void *first,     // param_3 — start node*
    void *last);     // param_4 — end node* (exclusive)
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `FUN_004ba770` | Recursive destroy of RB subtree / full tree |
| `FUN_004baa30` | Erase single iterator (rebalance + delete; throws on nil) |

| Caller | Role |
|---|---|
| `FUN_004b99c0` | NDSpecialFX TeardownCore — clear map at `fx+0x228` |
| `FUN_004badb0` | Additional map clear site |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Full-range detection (`first==*head && last==head`) | Yes |
| `004ba770` + head reset + size 0 | Yes |
| Successor walk + `004baa30` loop | Yes |
| `*out_it` write | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| MSVC `map`/`set` range erase | **High** | isnil `+0x15`; throw string in `004baa30` |
| Head @ `map+4`, size @ `map+8` | **High** | body |
| Full clear vs partial range | **High** | two CF paths |
| Used for NDSpecialFX map `@+0x228` | **High** | TeardownCore dual |
| Mapped type / key type | **Tentative** | not recovered here |
| Product / CRT export name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Exact STL instantiation (`map<K,V>` vs `set<K>`).
2. Whether `004badb0` is public clear wrapper or another domain owner.
3. Node payload free: `004baa30` deletes node; value dtor may be inlined/empty for POD keys.
4. Runtime not run.

**Verdict:** **accept-with-gaps** — STL range-erase CF High; key/value types open.
