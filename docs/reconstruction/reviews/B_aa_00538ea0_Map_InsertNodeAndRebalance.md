# Review B (skeptical / adversarial): `aa_00538ea0` Map insert node + RB rebalance

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538ea0` |
| **VA** | `0x00538ea0` |
| **Canonical name** | `FUN_00538ea0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_00538ea0_Map_InsertNodeAndRebalance.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** on shape; **reject** find/upsert/mission-logic roles |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Insert-or-find / may not allocate” | **Falsified** — always `FUN_005380d0` + `size++`; no key walk |
| “Equal-key payload update” | **Falsified** — no key compare at all; parent owns equal path |
| “Mission eligibility / dialog / GiveMission” | **Falsified** — pure tree mutator; only string is STL length_error text |
| “Generic shared insert for every map in the binary” | **Partial** — algorithm is STL `_Tree` insert; **this VA** is specialized to **0x50** nodes (color `+0x48`, isnil `+0x49`, 14-dword value). Other maps use other insert VAs (e.g. skill CD map) |
| “`RET 8` like parent insert-or-find” | **Falsified** — epilogue **`C2 10 00`** (four stack args) |
| “Self-recursive rebalance” | **Falsified** — scaffold listed self-callee; body has no call to self |
| “`FUN_005681a0` / `FUN_00568b70` are not map-relative” | **Falsified** — both `__thiscall` with `ECX=map` (`mov ecx,edi` at call sites); use head at `map+4` |
| “color 0 = black” | **Falsified** — new node color **0**, loop while parent color **0**, then set colors to **1** and root to **1** → **0=red, 1=black** (MSVC map convention) |
| Product export name `std::map::_Insert` | **Unproven** — structure matches; no PDB name for this instance |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| `void` return | Out-param `*outIt = newNode` is contract; epilogue `mov [eax],ecx` with `eax=outIt*` — callers may read `*return` as node |
| Rotate calls show only one arg | Both are `__thiscall(map, node*)`; ECX = map from `edi` |
| `piVar6[0x12]` color on uncle | `0x12 * 4 = 0x48` — same color byte as `+0x48` |
| Scaffold callees include `FUN_00538ea0` (self) | **False** — callees: `FUN_005380d0`, `FUN_00568b70`, `FUN_005681a0`, string/exception/`_CxxThrowException` |
| Decomp `param_1` as plain `int` | ECX map object (`MapShell*`) |

---

## 3. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Is node size shared with category-CD map? | CD uses **0x1C** / color `+0x18`; this ctor **`new(0x50)`** | **High** distinct |
| Is `+0x48` isnil not color? | ctor: color arg → `+0x48`, isnil forced `0` at `+0x49`; rebalance reads `+0x48`; rotates guard `+0x49` | **High** |
| Size limit magic wrong? | Bytes `cmp [edi+8], 0x04924923` + `jb` over throw ≡ decomp `size > 0x4924922` | **High** |
| Head layout not leftmost/root/rightmost? | Empty insert writes all three slots; left/right insert update head[0]/head[2] when extremum | **High** |
| Inlined rotate ≠ `FUN_00568b70`? | Same pointer rewires + isnil parent fixup; code-gen duplicate, not different semantics | **High** |

---

## 4. Surviving contract (minimal)

```
// thiscall on MapShell (Character+0x508 when used from staging)
// ALWAYS inserts a new node (caller must ensure miss / correct where+addLeft)

void Map_InsertNodeAndRebalance(
    MapShell* map,          // ECX
    Node** outIt,           // *outIt = newly allocated node
    char addLeft,           // 1 → left child of where; 0 → right
    Node* where,            // parent, or head if tree empty
    const void* valuePair); // 14 dwords → node+0x10
// RET 0x10
//
// Throws if map->size > 0x4924922 ("map/set<T> too long")
// Node: new(0x50), color red (0), isnil 0, RB rebalance, root black
//
// Do NOT call for equal-key refresh — parent FUN_00539cb0 handles find-only.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| `RET 0x10` + 4 stack args | **Agree** |
| Always alloc + rebalance | **Agree** — critical vs parent insert-or-find |
| color `+0x48` / isnil `+0x49` / node `0x50` / 14 dwords | **Agree** |
| 0=red, 1=black | **Agree** |
| `FUN_005681a0` R-rot / `FUN_00568b70` L-rot | **Agree** roles |
| Sole static caller `FUN_00539cb0` | **Agree** |
| Product English open | **Agree** |
| Helper English names | Roles **High**, names **Tentative** |

---

## 6. Residual (honest)

1. Product / export / typedef name for this map specialization.
2. Whether any dynamic/indirect call sites exist beyond static xrefs (none found).
3. Runtime insert rebalance capture (root paint / size).
4. Bit-exact image diff vs clean rewrite.
5. Why grandparent left-rotate is inlined on the parent-is-right path only (MSVC codegen; not a semantic gap).

---

## 7. Verdict

### **accept-with-gaps**

ABI, always-insert CF, size cap, node geometry, color convention, rotation helpers, and sole static caller are **sealed**. Reject find/upsert/mission-business claims and self-recursion scaffold noise. Dual A layout table is acceptable with product name open.
