# Function record: ActionManager_NotifyListenersAndCompact_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0062a410` |
| **Canonical name** | `ActionManager_NotifyListenersAndCompact_Inferred` |
| **Ghidra name** | `FUN_0062a410` |
| **Address** | `0x0062a410` |
| **Body range** | `0x0062a410`–`0x0062a444` exclusive (**52** / `0x34` B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | vehicle / world action lifecycle |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + ABI sealed; product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0062a410_ActionManager_NotifyListenersAndCompact_Inferred.md`, `reviews/B_aa_0062a410_ActionManager_NotifyListenersAndCompact_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W24-P) |

## Alias

- `FUN_0062a410`
- `Named_CalleeOf_…` parent-seed scaffolds if present — **not** product names
- Role: notify manager listener table (`+0x3c/+0x40`) via vtbl+0xC, then compact nulls

## Purpose

Given action manager pointer and action object:

1. Reverse-walk listeners in `*(manager+0x3c)[0..count@+0x40)`.
2. For each non-null listener: `(*listener->vtbl + 0xC)(action)` thiscall.
3. Tail-call `FUN_005fff20` with `EAX = manager+0x3c` to strip null pointer slots.

Primary caller: `ActionManager_UnregisterAndRelease_Inferred` (`FUN_0055df40`).

## Signature

```c
void ActionManager_NotifyListenersAndCompact_Inferred(
    void *manager,   // [esp+4]
    void *action);   // [esp+8]
// cdecl — caller cleans 8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0062a410_FUN_0062a410.md` (+ W24-P append)
- Annotated: `docs/reconstruction/raw/aa_0062a410_FUN_0062a410.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ActionManager_NotifyListenersAndCompact_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0062a410.cpp`
- Review A/B: as above
- Scaffold record: `docs/reconstruction/functions/aa_0062a410_FUN_0062a410.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005fff20` @ `0x005fff20` (EAX = PtrVec at manager+0x3c) |
| **Callers** | `FUN_0055df40` only (Ghidra) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body bytes (52 B) | **High** |
| cdecl two stack args (parent ADD ESP,8) | **High** |
| table base +0x3c / count +0x40 | **High** |
| vtbl+0xC thiscall notify | **High** |
| EAX=manager+0x3c tail compact | **High** (bytes + `FUN_005fff20` in_EAX) |
| Product English name | **Inferred** |
| Runtime / differential | Open |

## Related

- Parent dual: `A/B_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred`
- Sibling table notify: `FUN_0062a490` (different offsets / vtbl+8)
- Peer reverse-list: `aa_00628f10` (W24-P co-owned)
