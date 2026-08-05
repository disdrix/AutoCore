# Function record: StdMap_InsertOrFindByIntKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e18d0` |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Val12` (Inferred) |
| **Ghidra name** | `FUN_005e18d0` |
| **Address** | `0x005e18d0` |
| **Body range** | `0x005e18d0`–`0x005e1988` exclusive (**184** B / `0xB8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std map insert-or-find (Val12 / signed int key) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + signed key + out-pair sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005e18d0_StdMap_InsertOrFindByIntKey_Val12.md`, `reviews/B_aa_005e18d0_StdMap_InsertOrFindByIntKey_Val12.md` (2026-07-29 W30-L) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005e18d0`
- `Named_CalleeOf_Named_CalleeOf_Mission_after_CVOGRegionMissions_005e18d0` (legacy scaffold — **narrow**; mission is caller domain)
- Peer: `aa_0053a1a0` same structural name (insert helper `00539210` vs this unit’s `005e13b0`)

## Purpose

Lower-bound walk by **signed int** key (`node[3]` / +0x0C); on miss insert via Val12 rebalance helper `FUN_005e13b0`; on hit return existing iterator with `inserted=0` and no value rewrite.

## Signature

```c
void __thiscall StdMap_InsertOrFindByIntKey_Val12(
    MapShell_Val12* map,   // ECX; +0x04 head, +0x08 size
    InsertPair* out,       // { Node* it; u8 inserted@+4 }
    const Val12* value);   // key at +0 (3 dwords)
// RET 8
```

## Algorithm

1. Walk from root with `key < node->key` (signed) → left else right; stop on isnil@+0x19; track `addLeft`.
2. If `addLeft` and `where == leftmost`: insert left; `inserted=1`.
3. Else if `addLeft`: predecessor (`FUN_005ae050`); then if `where->key < key` insert.
4. Else if `where->key < key` insert with last `addLeft`.
5. Else hit: `inserted=0`, `it=where`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005e18d0_FUN_005e18d0.md`
- Annotated: `docs/reconstruction/raw/aa_005e18d0_FUN_005e18d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFindByIntKey_Val12_005e18d0.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005e18d0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005e15a0-005e18d0-w30l-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005e13b0` (always-insert+rebalance; buynode `005ae220`), `FUN_005ae050` (predecessor) |
| **Callers** | `FUN_005e0610` only (1 xref @ `0x005e06db`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 8` + thiscall ECX=map | **High** (bytes) |
| Signed int key @ +0x0C / isnil@+0x19 | **High** (`setl`/`jge`) |
| Insert vs find pair out; equal no rewrite | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Always-insert (not OWN): `FUN_005e13b0` → buynode `aa_005ae220`
- Predecessor: `aa_005ae050` StdTree_Dec_Val12 (W29-E **accept**)
- Peer insert-or-find: `aa_0053a1a0` (W28-P)
- Erase dual unit: `aa_005e15a0` StdTree_EraseAndRebalance_Val12
