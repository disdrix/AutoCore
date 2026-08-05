# Function record: StdMap_Dtor_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7350` |
| **Canonical name** | `StdMap_Dtor_Val12` (Inferred) |
| **Ghidra name** | `FUN_004e7350` |
| **Address** | `0x004e7350` |
| **Body range** | `0x004e7350`–`0x004e737e` exclusive (**46** B / `0x2E`); pad `CC` |
| **Ghidra listed end** | `0x004e736f` — **stale** (cuts mid post-delete path) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black map destructor (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + null epilogue sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004e7350_StdMap_Dtor_Val12.md`, `reviews/B_aa_004e7350_StdMap_Dtor_Val12.md` (2026-07-29 W29-M) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004e7350`
- `Named_CalleeOf_Named_VOG_DEBUG_STOP_004e7350` (legacy scaffold — **narrow**; parent is large object dtor)

## Purpose

Destroy a Val12 map: full erase-range via `StdMap_EraseRange_Val12` (`FUN_004e5120`), free the header node with `operator_delete`, then set `head=0` and `size=0`.

## Signature

```c
void __thiscall StdMap_Dtor_Val12(MapShell_Val12* map);  // ECX; RET 0 (C3)
```

## Algorithm

1. `EraseRange(map, &tmp, *head /*begin*/, head /*end*/)` — W28-P unit.
2. `operator_delete(head)` — falls through (decomp false-noreturn residual).
3. `head = 0; size = 0`.
4. `ret`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e7350_FUN_004e7350.md` (+ W29-M append)
- Annotated: `docs/reconstruction/raw/aa_004e7350_FUN_004e7350.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_Dtor_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004e7350.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004e7350-00567860-w29m-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_004e5120` (StdMap_EraseRange_Val12, W28-P); `operator_delete` |
| **Callers** | `FUN_004d64d0` @ `0x004d6970`, `0x004d697b` (two map members) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + post-delete nulls | **High** (bytes) |
| `ret` / thiscall | **High** |
| Val12 via erase-range | **High** |
| Product demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Erase-range: `aa_004e5120` StdMap_EraseRange_Val12 (W28-P)
- Single erase used by erase-range: `aa_004e4130` StdTree_EraseAndRebalance_Val12 (W27-Q)
- Peer isnil@+0x15 erase family: `aa_004bacf0` — **do not merge**
