# Function record: StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00458510` |
| **Canonical name** | `StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred` (Inferred) |
| **Ghidra name** | `FUN_00458510` |
| **Address** | `0x00458510` |
| **Body range** | `0x00458510`–`0x004585C5` exclusive (**181** B / `0xB5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std map insert-or-find (Val8 / isnil+0x15 / uint key / EAX+EBX ABI) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + unsigned key + equal-no-write sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00458510_StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.md`, `reviews/B_aa_00458510_StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.md` (2026-08-04 W37-K) |
| **Last reviewed** | `2026-08-04` |

## Alias

- `FUN_00458510`
- `Named_CalleeOf_Named_CalleeOf_Named_Palantir_00458510` (legacy scaffold — **reject** as product)

## Purpose

Unique map insert-or-find by **unsigned** 32-bit key. Walk tree (isnil@+0x15), optional predecessor, insert via `FUN_00438140`, or return existing node with `inserted=0` (no value rewrite).

## Signature

```c
// Register ABI (bytes):
//   EAX = MapShell*  (head@+4, size@+8)
//   EBX = Val8*      (key at +0)
//   stack: InsertPair* out  → {it*, inserted:u8@+4}
//   returns out in EAX; RET 4
InsertPair* StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred(
    MapShell_Isnil15* map,
    InsertPair* out,
    const Val8* value);
```

## Algorithm

1. Walk from `head->parent` while child not isnil; compare `value->key` **unsigned** to `node->key@+0x0C`.
2. If last step went left:
   - If node is leftmost (`head->left`): insert with `addLeft=1` → `{it,1}`.
   - Else predecessor (`FUN_004129f0`).
3. If `node->key < value->key` (unsigned): insert with `addLeft=goLeft` → `{it,1}`.
4. Else equal: `{node,0}` — **no** mapped rewrite.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00458510_FUN_00458510.md` (+ W37-K append)
- Annotated: `docs/reconstruction/raw/aa_00458510_FUN_00458510.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00458510.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00458510-005e13b0-w37k-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00438140` (insert+RB, color@+0x14, max `0x1ffffffd`); `FUN_004129f0` (predecessor isnil15) |
| **Callers** | `FUN_00444850`, `FUN_00444880`, `FUN_0043daf0`, `FUN_004582e0`, `FUN_00752d60`, `FUN_00763620` (6 xrefs) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `RET 4` + EAX map + EBX value* | **High** (bytes) |
| Unsigned key compare | **High** (`SETB`/`JAE`) |
| isnil@+0x15 / key@+0x0C | **High** |
| Equal-no-write | **High** |
| Product English / demangle | **Inferred** |
| Insert helper full dual | Open (unOWN) |
| Runtime / differential | Open |

## Related

- W35-H `FourCCFnPtrMap_TryInsert_DAT_00d21958` (`0x00444850`) — thin wrapper; left this dual open.
- Peer thiscall signed isnil15: `aa_004a7580` (W23-F) — different ABI/compare.
