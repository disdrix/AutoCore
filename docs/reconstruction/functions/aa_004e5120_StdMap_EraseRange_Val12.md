# Function record: StdMap_EraseRange_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e5120` |
| **Canonical name** | `StdMap_EraseRange_Val12` (Inferred) |
| **Ghidra name** | `FUN_004e5120` |
| **Address** | `0x004e5120` |
| **Body range** | `0x004e5120`–`0x004e51d4` exclusive (**180** B / `0xB4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map range erase (Val12) |
| **Completion status** | **Sealed** — dual A/B **accept-with-gaps** (W28-P 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004e5120_StdMap_EraseRange_Val12.md`, `reviews/B_aa_004e5120_StdMap_EraseRange_Val12.md` |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004e5120`
- Peer layout (isnil@+0x15): `StdMap_EraseRange_Inferred` @ `0x004bacf0`
- Sibling Val12 range erase instance: `FUN_0053a260` (not this VA)

## Purpose

Erase half-open iterator range `[first, last)` on a Val12 map/set. Full-tree range uses recursive free + head reset; partial range walks successors and calls single-node Val12 erase.

## Signature

```c
void __thiscall StdMap_EraseRange_Val12(
    MapShell_Val12* map,   // ECX; +0x04 head, +0x08 size
    MapNode_Val12** outIt,  // *outIt = first after erase (== last)
    MapNode_Val12* first,
    MapNode_Val12* last);
// RET 0x0C
```

## Algorithm

1. If `first == head->left && last == head`: free root subtree (`FUN_004e2940`), self-link head, size=0, `*outIt=*head`.
2. Else while `first != last`: compute successor (isnil@+0x19), `StdTree_EraseAndRebalance_Val12(map, &first, cur)`, advance.
3. `*outIt = first`; return.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e5120_FUN_004e5120.md`
- Annotated: `docs/reconstruction/raw/aa_004e5120_FUN_004e5120.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_EraseRange_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004e5120.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004e5120-0053a1a0-w28p-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_004e2940` (subtree free), `FUN_004e4130` StdTree_EraseAndRebalance_Val12 |
| **Callers** | `FUN_004e7350` only (1 xref @ `004e7362`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0x0c` + thiscall ECX=map | **High** (bytes) |
| Val12 / isnil@+0x19 | **High** |
| Full vs partial range | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Erase node: `aa_004e4130` StdTree_EraseAndRebalance_Val12 (W27-Q)
- Insert pair unit: `aa_0053a1a0` StdMap_InsertOrFindByIntKey_Val12 (this dual)
