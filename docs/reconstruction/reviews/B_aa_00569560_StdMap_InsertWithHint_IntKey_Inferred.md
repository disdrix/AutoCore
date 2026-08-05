# Review B (skeptical / adversarial): `aa_00569560` StdMap_InsertWithHint_IntKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00569560` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-G) |
| **Counterpart** | `reviews/A_aa_00569560_StdMap_InsertWithHint_IntKey_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a pure lower_bound / find (no insert) | **Falsified** — many paths call `FUN_005690a0` (insert+rebalance; map/set too-long throw) |
| 2 | This is the same body as `00569320` InsertOrFind | **Falsified** — different entry; this unit *calls* `00569320` only on fallback; body 356 B vs 184 B |
| 3 | Key offset is `+0x10` (staging maps) | **Falsified for this family** — compares `node[3]` / `+0x0C`; matches dual `aa_00569320` / `aa_00537770` |
| 4 | Multiple independent callers | **Falsified** — sole `FUN_005697d0` |
| 5 | `ret 8` like InsertOrFind | **Falsified** — all paths `ret 0x0C` (3 stack args) |
| 6 | Clean invents extra tree walks | **Falsified** — clean mirrors raw CF (empty / leftmost / end / pred / succ / fallback) |
| 7 | Hint always trusted (no fallback) | **Falsified** — fall-through to `FUN_00569320` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hinted insert role | **High** | Wrong container port (find vs insert) |
| Key `+0x0C` / isnil `+0x49` | **High** | Corrupt tree links if port uses wrong layout |
| Fallback to InsertOrFind | **High** | Missing equal-key path when hint is stale |
| Value domain / node total size | Medium–Open | Over/under-alloc on server port |
| SBORROW4 succ gate exactness | Medium | Edge overflow keys (rare int extremes) |

---

## 3. Cross-check against raw + bytes

```
sub esp,8; this=EDI
if size==0 → insert(head, left)
if hint==*head && key < hint.key → insert left
if hint==head && rightmost.key < key → insert right
else if key < hint.key → pred; maybe insert
else if key > hint.key (SBORROW4) → succ; maybe insert
else InsertOrFind → *outIt = it
ret 0x0C
```

Clean must **not** invent capacity math, alternate key offsets, or drop the fallback path.

Do **not** merge this body with `aa_00569320` — role-related, not the same function.

---

## 4. Surviving contract for AutoCore

```csharp
// Port of StdMap_InsertWithHint_IntKey_Inferred
// Prefer Dictionary/SortedDictionary insert with optional hint ignored,
// or implement full RB tree if bit-exact tree shape matters.
// On size overflow client throws "map/set<T> too long" (via insert callee).
Node InsertWithHint(Map map, Node hint, int key)
{
    // if hint valid for position → insert there
    // else InsertOrFind(map, key)
}
```

Equal-key behavior is owned by fallback `StdMap_InsertOrFindByIntKey_Inferred` (inserted=0).

---

## 5. Open questions

1. Full node / value layout for maps that reach `FUN_005697d0`.
2. Whether AutoCore server should throw on max size or assert.
3. Runtime golden for hint-valid vs hint-stale paths.

**Verdict:** **accept-with-gaps**
