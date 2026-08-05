# Function record: StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539210` |
| **Canonical name** | `StdTree_InsertAndRebalance_Val12` (Inferred) |
| **Ghidra name** | `FUN_00539210` |
| **Address** | `0x00539210` |
| **Body range** | `0x00539210`–`0x005393fa` exclusive (**490** B / `0x1EA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map insert+rebalance (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + string + buynode sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00539210_StdTree_InsertAndRebalance_Val12.md`, `reviews/B_aa_00539210_StdTree_InsertAndRebalance_Val12.md` (2026-07-29 W27-Q) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00539210`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCharacter_Appl_00539210` (legacy scaffold — **narrow**)
- Peer sole-caller clone: `Map_TreeInsertAndRebalance_Val12` @ `0x0051c1c0` (W25-G)

## Purpose

Allocate and link a Val12 red-black tree node (`StdTree_Buynode_Val12`), update size / extremities / root, rebalance while parent is red, paint root black, write `*outIt = newNode`. Throw if size exceeds `0x15555553`.

## Signature

```c
void __thiscall StdTree_InsertAndRebalance_Val12(
    MapShell_Val12* map,       // ECX; +0x04 head, +0x08 size
    MapNode_Val12** outIt,     // *outIt = inserted node
    char addLeft,              // 1 left, 0 right
    MapNode_Val12* where,      // parent or head
    const Val12* value);       // 3 dwords
// RET 0x10
```

## Algorithm

1. If `map->size > 0x15555553` → throw `"map/set<T> too long"`.
2. `n = StdTree_Buynode_Val12(head, where, head, value, color=0)`.
3. `size++`; link n as first / left / right child; maybe update leftmost/rightmost.
4. RB fixup while parent color red: recolor uncle or rotate (L/R helpers + one inlined Lrotate).
5. Paint root black; `*outIt = n`; return.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00539210_FUN_00539210.md`
- Annotated: `docs/reconstruction/raw/aa_00539210_FUN_00539210.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00539210.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004e4130-00539210-w27q-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005ae220` (StdTree_Buynode_Val12), `FUN_00573170`, `FUN_00418c10`, STL throw chain |
| **Callers** | `FUN_0053a1a0`, `FUN_0053a8e0` (9 xrefs) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0x10` + thiscall ECX=map | **High** |
| Val12 / color@+0x18 / isnil@+0x19 | **High** |
| Buynode = `FUN_005ae220` color 0 | **High** |
| Throw string + max size constant | **High** |
| Multi-caller shared helper | **High** (xrefs) |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Buynode: `aa_005ae220` StdTree_Buynode_Val12 (W24-I **accept**)
- Rotates: `aa_00573170` / `aa_00418c10` (W26-Q **accept**)
- Peer insert: `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12 (W25-G)
- Erase twin this dual: `aa_004e4130` StdTree_EraseAndRebalance_Val12
