# Function record: StdMap_InsertOrFindByIntKey_Val12 (`0x005aed20`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005aed20` |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Val12` (**Inferred** structural) |
| **Ghidra name** | `FUN_005aed20` |
| **Address** | `0x005aed20` |
| **Body range** | `0x005aed20`–`0x005aedd8` exclusive (**184** B / `0xB8`); pad `CC` → `0x005aede0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std map insert-or-find (Val12 / int key) |
| **Completion status** | **Sealed** — dual A/B **accept-with-gaps** (W30-M 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md`, `reviews/B_aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md` |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005aed20`
- Legacy: `Named_CalleeOf_Mission_MissionStopLimit_005aed20` (**narrow** — xref chain via CrazyTaxi XML dump only)
- Always-insert helper: `StdTree_InsertAndRebalance_Val12` @ `0x005ae4e0` (W27-T)
- Peer same-role VA: `aa_0053a1a0` @ `0x0053a1a0` (insert via `0x00539210`) — **do not merge**

## Purpose

Lower-bound walk by signed int key (`node[3]` / +0x0C); on miss insert via Val12 rebalance helper `0x005ae4e0`; on hit return existing iterator with `inserted=0`.

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
3. Else if `addLeft`: predecessor (`FUN_005ae050` / `StdTree_Dec_Val12`); then if `where->key < key` insert.
4. Else if `where->key < key` insert with last `addLeft`.
5. Else hit: `inserted=0`, `it=where`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005aed20_FUN_005aed20.md`
- Annotated: `docs/reconstruction/raw/aa_005aed20_FUN_005aed20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFindByIntKey_Val12_005aed20.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005aed20.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005aed20-005accf0-w30m-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005ae4e0` StdTree_InsertAndRebalance_Val12 (W27-T); `FUN_005ae050` StdTree_Dec_Val12 (W29-E) |
| **Callers** | `FUN_005acf10` (CrazyTaxi XML dump / MissionStopLimit) @ `005ad0ae`; call site `005ada8b` in undefined body ~`005ad2f0` (CrazyTaxi vtable +0x48 parse/load) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 8` + thiscall ECX=map | **High** (bytes ×3) |
| Int key @ +0x0C / isnil@+0x19 | **High** |
| Insert vs find pair out | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Insert rebalance: `aa_005ae4e0` (W27-T)
- Peer insert-or-find: `aa_0053a1a0` (W28-P)
- Predecessor: `aa_005ae050` (W29-E)
