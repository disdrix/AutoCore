# Function record: StdTree_InsertHint_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a8e0` |
| **Canonical name** | `StdTree_InsertHint_Val12` (Inferred) |
| **Ghidra name** | `FUN_0053a8e0` |
| **Address** | `0x0053a8e0` |
| **Body range** | `0x0053a8e0`–`0x0053aa43` exclusive (**355** B / `0x163`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map insert-with-hint (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + Val12 + callees sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0053a8e0_StdTree_InsertHint_Val12.md`, `reviews/B_aa_0053a8e0_StdTree_InsertHint_Val12.md` (2026-07-29 W28-Q) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0053a8e0`
- `Named_CalleeOf_Named_CalleeOf_CVOGCharacter_ApplyCreateFromPack_0053a8e0` (legacy scaffold — **narrow**)

## Purpose

MSVC `_Tree` **insert with iterator hint** for a unique Val12 map: try empty / leftmost / end / neighbor (pred/succ + isnil) fast inserts via `StdTree_InsertAndRebalance_Val12`; otherwise full insert-or-find (`FUN_0053a1a0`) and write `*outIt`.

## Signature

```c
MapNode_Val12** __thiscall StdTree_InsertHint_Val12(
    MapShell_Val12* map,       // ECX; +0x04 head, +0x08 size
    MapNode_Val12** outIt,
    MapNode_Val12* hint,
    const Val12* value);      // key @ +0
// RET 0x0C
```

## Algorithm

1. `size==0` → InsertAndRebalance(addLeft=1, head).
2. `hint==leftmost && key < hint.key` → InsertAndRebalance(1, hint).
3. `hint==head && rightmost.key < key` → InsertAndRebalance(0, rightmost).
4. Else if `key < hint.key`: Prevnode(hint); if pred.key < key → insert right of pred if pred.right isnil else left of hint.
5. Else if `hint.key < key`: Nextnode; if usable gap → insert right of hint if hint.right isnil else left of succ.
6. Else InsertOrFind → `*outIt = pair.node`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053a8e0_FUN_0053a8e0.md`
- Annotated: `docs/reconstruction/raw/aa_0053a8e0_FUN_0053a8e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertHint_Val12.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0053a8e0.cpp`
- Function FUN_*: `docs/reconstruction/functions/aa_0053a8e0_FUN_0053a8e0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0053a8e0-006cad30-w28q-report.md`
- Scratch: `docs/reconstruction/tmp/a_0053a8e0.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00539210` StdTree_InsertAndRebalance_Val12; `FUN_0053a1a0` InsertOrFind; `FUN_005ae050` Prevnode; `FUN_005ae0b0` Nextnode |
| **Callers** | `FUN_0053af20` (1 xref @ `0053af74`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0x0c` + thiscall ECX=map | **High** |
| Val12 isnil@+0x19 / key@+0x0c | **High** |
| Hint insert role (not always-insert alone) | **High** |
| MSVC neighbor insert targets | **High** (bytes + MSVC pattern; decomp aliases local) |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Insert rebalance: `aa_00539210` StdTree_InsertAndRebalance_Val12 (W27-Q)
- Erase peer family: `aa_004e4130` StdTree_EraseAndRebalance_Val12 (W27-Q)
- Buynode: `aa_005ae220` StdTree_Buynode_Val12 (W24-I)
