# Function record: StdMap_InsertAlways_Val12_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00567860` |
| **Canonical name** | `StdMap_InsertAlways_Val12_IntKey` (Inferred) |
| **Ghidra name** | `FUN_00567860` |
| **Address** | `0x00567860` |
| **Body range** | `0x00567860`–`0x005678c0` exclusive (**96** B / `0x60`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black map always-insert (Val12, signed int key) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; always-insert CF + ABI sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00567860_StdMap_InsertAlways_Val12_IntKey.md`, `reviews/B_aa_00567860_StdMap_InsertAlways_Val12_IntKey.md` (2026-07-29 W29-M) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00567860`
- Prior wave notes sometimes called this "insert-or-find parent" — **incorrect**: unit always inserts

## Purpose

Walk Val12 tree by **signed int key** (`value[0]` / `node+0x0c`); **always** call `Map_TreeInsertAndRebalance_Val12` (`FUN_00567450`); always set out-pair `inserted=1`. Equal keys go right (no uniqueness gate).

## Signature

```c
struct InsertPair {
    MapNode_Val12* it;   // +0
    uint8_t inserted;    // +4  — always 1
};

void __thiscall StdMap_InsertAlways_Val12_IntKey(
    MapShell_Val12* map,      // ECX; head@+4, size@+8
    InsertPair* out,          // stack0
    const int32_t* value);    // stack1 — key = value[0]
// RET 8
```

## Algorithm

1. Start at head; if root non-nil, walk left on `key < node.key` (signed), else right (includes equal).
2. Always `InsertAndRebalance(..., addLeft, parent, value)`.
3. `out = {newNode, 1}`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00567860_FUN_00567860.md` (+ W29-M append)
- Annotated: `docs/reconstruction/raw/aa_00567860_FUN_00567860.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertAlways_Val12_IntKey.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00567860.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004e7350-00567860-w29m-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00567450` (Map_TreeInsertAndRebalance_Val12, W27-R → buynode `005ae220`) |
| **Callers** | `FUN_00565950` @ `0x0056641a`, `0x00566452` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| Always-insert / `inserted=1` | **High** |
| Signed int key @ +0x0c | **High** |
| isnil@+0x19 Val12 | **High** |
| `ret 8` + thiscall | **High** |
| Product demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Always-insert helper: `aa_00567450` Map_TreeInsertAndRebalance_Val12 (W27-R)
- Node buy: `aa_005ae220` StdTree_Buynode_Val12 (W24-I)
- Peer insert-or-find int: `aa_0053a1a0` StdMap_InsertOrFindByIntKey_Val12 (W28-P) — **do not merge**
- Peer insert-or-find uint: `aa_00573810` StdMap_InsertOrFind_Val12_UintKey (W28-T) — **do not merge**
