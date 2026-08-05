# Function record: StdMap_InsertOrFindByIntKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a1a0` |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Val12` (Inferred) |
| **Ghidra name** | `FUN_0053a1a0` |
| **Address** | `0x0053a1a0` |
| **Body range** | `0x0053a1a0`–`0x0053a259` exclusive (**185** B / `0xB9`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std map insert-or-find (Val12 / int key) |
| **Completion status** | **Sealed** — dual A/B **accept-with-gaps** (W28-P 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0053a1a0_StdMap_InsertOrFindByIntKey_Val12.md`, `reviews/B_aa_0053a1a0_StdMap_InsertOrFindByIntKey_Val12.md` |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0053a1a0`
- Always-insert helper: `StdTree_InsertAndRebalance_Val12` @ `0x00539210` (W27-Q)
- Peer int-key walk parent of other Val12 insert clone: `FUN_00567860` (W27-R)

## Purpose

Lower-bound walk by signed int key (`node[3]` / +0x0C); on miss insert via Val12 rebalance helper; on hit return existing iterator with `inserted=0`.

## Signature

```c
void __thiscall StdMap_InsertOrFindByIntKey_Val12(
    MapShell_Val12* map,   // ECX; +0x04 head, +0x08 size
    InsertPair* out,       // { Node* it; u8 inserted@+4 }
    const Val12* value);   // key at +0 (3 dwords)
// RET 8
```

## Algorithm

1. Walk from root with `key < node->key` → left else right; stop on isnil@+0x19; track `addLeft`.
2. If `addLeft` and `where == leftmost`: insert left; `inserted=1`.
3. Else if `addLeft`: predecessor (`FUN_005ae050`); then if `where->key < key` insert.
4. Else if `where->key < key` insert with last `addLeft`.
5. Else hit: `inserted=0`, `it=where`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053a1a0_FUN_0053a1a0.md`
- Annotated: `docs/reconstruction/raw/aa_0053a1a0_FUN_0053a1a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFindByIntKey_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0053a1a0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004e5120-0053a1a0-w28p-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00539210` StdTree_InsertAndRebalance_Val12, `FUN_005ae050` predecessor |
| **Callers** | `FUN_0053a8e0` only (1 xref @ `0053aa2d`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 8` + thiscall ECX=map | **High** (bytes) |
| Int key @ +0x0C / isnil@+0x19 | **High** |
| Insert vs find pair out | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Insert rebalance: `aa_00539210` (W27-Q)
- Range erase pair unit: `aa_004e5120` StdMap_EraseRange_Val12 (this dual)
