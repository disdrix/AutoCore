# Function record: ActionHost_RemoveReverseListEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00628f10` |
| **Canonical name** | `ActionHost_RemoveReverseListEntry_Inferred` |
| **Ghidra name** | `FUN_00628f10` |
| **Address** | `0x00628f10` |
| **Body range** | `0x00628f10`–`0x00628f64` exclusive (**84** / `0x54` B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | vehicle / world action lifecycle |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + ABI sealed; product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00628f10_ActionHost_RemoveReverseListEntry_Inferred.md`, `reviews/B_aa_00628f10_ActionHost_RemoveReverseListEntry_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W24-P) |

## Alias

- `FUN_00628f10`
- `Named_CalleeOf_…` parent-seed scaffolds — **not** product names
- Role: order-preserving remove of action* from host reverse list; clear back-link; dirty host

## Purpose

Given host `this` and action pointer:

1. Find `action` in `*(host+0x4c)[0..count@+0x50)`.
2. Decrement count; shift-left to close hole when index still in range.
3. Store `0` at `action+0x10` (clear host back-pointer).
4. Store `1` at `host+0x28` (dirty flag).

Primary parent path: `ActionManager_UnregisterAndRelease_Inferred` with `this = *(action+0x10)`.

## Signature

```c
void __thiscall ActionHost_RemoveReverseListEntry_Inferred(
    void *host,     // ECX
    void *action);  // [esp+4]
// RET 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00628f10_FUN_00628f10.md` (+ W24-P append)
- Annotated: `docs/reconstruction/raw/aa_00628f10_FUN_00628f10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ActionHost_RemoveReverseListEntry_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00628f10.cpp`
- Review A/B: as above
- Scaffold record: `docs/reconstruction/functions/aa_00628f10_FUN_00628f10.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none |
| **Callers** | `FUN_0055df40`, `FUN_00560f70`, `FUN_00561580` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body bytes (84 B) | **High** |
| `__thiscall` + `ret 4` | **High** |
| list +0x4c / count +0x50 | **High** |
| clear action+0x10; dirty host+0x28 | **High** |
| Parent this = `*(action+0x10)` | **High** (parent bytes; W23-P) |
| Product English name | **Inferred** |
| Not-found safety | **Med** (count-- still runs) |
| Runtime / differential | Open |

## Related

- Parent dual: `A/B_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred`
- Peer notify: `aa_0062a410` (W24-P co-owned)
