# Review A (reconstruction fidelity): `aa_0058df60` MapFloatTfid_EraseRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058df60` |
| **VA** | `0x0058df60` |
| **Canonical name** | `MapFloatTfid_EraseRange_Inferred` (was `FUN_0058df60`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0058df60_MapFloatTfid_EraseRange_Inferred.md` |
| **System** | shared tree helper (gather teardown; also `FUN_0058cd60`, `FUN_0058e020`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tree **thiscall** **erase range** `[first, last)`:

1. **Fast clear** if range is full tree: `first == *head && last == head` → `FUN_0058da00(head[1])` free subtree, reset head self-links, `tree+8 = 0` (size), `*out = *head` (begin), return.
2. Else **iterate** from `first` toward `last` with inorder successor; each step `FUN_0058dc30` erases current node; write final iterator to `*param_2`.

Gather uses this on the distance map before `operator_delete(head)` when cleaning the sort structure.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058df60_FUN_0058df60.md` |
| Annotated | `docs/reconstruction/raw/aa_0058df60_FUN_0058df60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0058df60.cpp` |
| Function record | `docs/reconstruction/functions/aa_0058df60_FUN_0058df60.md` |
| Parent gather | `Skill_GatherTargetsInArea` teardown @ `0x0058d8ac` |
| Related | `FUN_0058cd60`, `FUN_0058e020` |
| Callees | `FUN_0058da00` (subtree free), `FUN_0058dc30` (single erase) |
| Ghidra | `batch_decompile` + `analyze_function_complete` + callers |

**Live re-decompile 2026-07-29 ≡ raw.**

---

## 3. Signature

```c
// __thiscall
void __thiscall MapFloatTfid_EraseRange_Inferred(
    Tree* tree,           /* ECX / param_1; head at +4, size at +8 */
    Node** outIt,         /* param_2: written end iterator */
    Node* first,          /* param_3 */
    Node* last);          /* param_4 — end sentinel (often head) */
```

### Gather teardown (parent)

```
FUN_0058df60(&fStack_a4, *local_ac, local_ac);
// decomp: out scratch, first=leftmost/begin, last=head
operator_delete(local_ac);  // free head node after clear
```

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Full-range detect: `first==*head && last==head` | **Yes** |
| Full clear: free root subtree, size=0, re-self-link head | **Yes** |
| Partial: while first≠last, successor, `FUN_0058dc30` erase | **Yes** |
| Same inorder successor as dump unit (`+0x29` isnil) | **Yes** |
| `*out =` final iterator | **Yes** |
| No TFID list mutation | **Yes** |

### Full-clear sketch

```
if (first == *head && last == head):
  FUN_0058da00(head->parent_or_root)   // head[1]
  head->parent = head; tree.size = 0
  *head = head; head->right = head
  *out = *head
  return
// else erase loop...
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Erase range / clear CF | **High** | body |
| Full-tree fast path | **High** | dual condition + size 0 |
| Partial path uses 0058dc30 | **High** | callee |
| Callers: gather + 0058cd60 + 0058e020 | **High** | 3 xrefs |
| Same node family as alloc/insert/dump | **High** | isnil + links |
| Product `erase` / `clear` name | **Inferred** | |
| Exact gather arg order vs decomp | **Probable** | thiscall elision residual |

---

## 6. Gaps / open

1. Ownership duals for `FUN_0058da00` / `FUN_0058dc30` (free + rebalance).
2. Whether partial-range is used outside full clear in live gather (parent sites look full-clear).
3. Runtime leak check if erase skipped.
4. Product name.

**Verdict:** **accept-with-gaps**
