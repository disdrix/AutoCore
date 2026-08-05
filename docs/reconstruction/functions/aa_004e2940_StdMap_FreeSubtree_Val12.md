# Function record: StdMap_FreeSubtree_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2940` |
| **Canonical name** | `StdMap_FreeSubtree_Val12` |
| **Ghidra name** | `FUN_004e2940` |
| **Address** | `0x004e2940`–`0x004e2975` (**53 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL map/set Val12 |
| **Wave** | W29-L |
| **Verdict** | **accept** |

## Signature

```c
void StdMap_FreeSubtree_Val12(void *node); // ret 4
```

## Layout

| Offset | Role |
|---|---|
| `+0` | left* (post-delete walk) |
| `+4` | parent* (unused here) |
| `+8` | right* (recurse free) |
| `+0x19` | isnil byte |

## Related

- Peer isnil@+0x15: `StdMap_FreeSubtree_Isnil15_Inferred` (`0x004ba770`)
- Range erase caller: `StdMap_EraseRange_Val12` (`0x004e5120`, W28-P)
- Single erase: `StdTree_EraseAndRebalance_Val12` (`0x004e4130`, W27-Q)

## Artifacts

See `aa_004e2940_FUN_004e2940.md`.
