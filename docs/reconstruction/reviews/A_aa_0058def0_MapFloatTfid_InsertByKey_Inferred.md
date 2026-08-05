# Review A (reconstruction fidelity): `aa_0058def0` MapFloatTfid_InsertByKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058def0` |
| **VA** | `0x0058def0` |
| **Canonical name** | `MapFloatTfid_InsertByKey_Inferred` (was `FUN_0058def0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0058def0_MapFloatTfid_InsertByKey_Inferred.md` |
| **System** | `skills-abilities` (`Skill_GatherTargetsInArea` sort path) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tree **thiscall**: **lower_bound-style walk** on float keys at `node+0x10`, then **`FUN_0058da40`** insert helper, then return an **iterator pair** via out-param:

- `*param_2 = *insertedOrFound` (node\* / iterator value)
- `*((u8*)param_2 + 4) = 1` (inserted/success flag byte)

In gather: when sort-by-distance is active and distance `fStack_a4 > 0`, parent packs TFID dwords + float dist and calls this to insert into the local map before final inorder dump (`FUN_0058c7a0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058def0_FUN_0058def0.md` |
| Annotated | `docs/reconstruction/raw/aa_0058def0_FUN_0058def0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0058def0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0058def0_FUN_0058def0.md` |
| Parent dual | `reviews/A_aa_0058d330_Skill_GatherTargetsInArea.md` |
| Dump sibling | `FUN_0058c7a0` (own dual this batch) |
| Insert helper | `FUN_0058da40` @ `0x0058da40` (not owned) |
| Ghidra | `batch_decompile` + `analyze_function_complete` + callers |

**Live re-decompile 2026-07-29 ≡ raw.** Sole caller: `Skill_GatherTargetsInArea` @ `0x0058d74e`.

---

## 3. Signature

```c
// __thiscall: ECX = tree object (param_1; uses *(tree+4) head)
void __thiscall MapFloatTfid_InsertByKey_Inferred(
    Tree* tree,                 /* ECX / param_1 */
    IteratorOut* outIt,         /* param_2: { node*, u8 flag@+4 } */
    float* key);                /* param_3: float key (distance) */
```

Parent site (simplified):

```
// TFID already staged; afStack_68[0] = distance
FUN_0058def0(auStack_38, afStack_68);
// decomp shows 2 stack formals after this — tree in ECX from local map object
```

Ghidra thiscall framing: `param_1` = tree, `param_2` = out iterator, `param_3` = `&floatKey`. Parent decompile may elide ECX tree.

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Start at `head[1]` (root) / head in `tree+4` | **Yes** |
| While `!node.isnil(+0x29)`: compare `node[4]` float vs `*key` | **Yes** |
| `key >= nodeKey` → go right (`node[2]`); else left (`node[0]`) | **Yes** (decomp: `<=` uses right) |
| Track `bVar4` insert-left/right hint | **Yes** |
| `FUN_0058da40(&key, bVar4, parent, key)` | **Yes** |
| Out: `*param_2 = *result`; byte at `param_2+4 = 1` | **Yes** |
| No gather mode / filter logic | **Yes** |

### Compare polarity (sealed)

```
fKey = node[+0x10]
if (fKey < *param_3 || fKey == *param_3)  // fKey <= *key
  go right
else
  go left
bVar4 = (fKey > *param_3)                 // strict greater → true
```

Matches MSVC `map` lower_bound / insert hint for ascending keys (nearest-first dump after equal-order residual on ties).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole caller GatherTargetsInArea | **High** | one xref |
| Float key at node+0x10 | **High** | `puVar7[4]` |
| Insert via `FUN_0058da40` | **High** | callee |
| Out iterator + flag byte 1 | **High** | stores |
| Sort-path only (parent `param_14`) | **High** | parent dual |
| Exact multi-arg thiscall stack | **Probable** | parent elision residual |
| Equal-key policy (multi same dist) | **Probable** | `<=` goes right → after equals |
| Product insert name | **Inferred** | |

---

## 6. Gaps / open

1. Full `FUN_0058da40` ownership (node alloc, rebalance, payload copy from parent stack).
2. Whether equal distances preserve insertion order.
3. Tree object layout beyond `+4` head pointer (`+8` size used by erase).
4. Runtime sort verification.

**Verdict:** **accept-with-gaps**
