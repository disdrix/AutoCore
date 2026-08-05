# Function record: Host_ActionList_Push

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507290` |
| **Canonical name** | `Host_ActionList_Push` |
| **Former name** | `FUN_00507290` |
| **Address** | `0x00507290` |
| **Body range** | `0x00507290`–`0x005072c5` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics / action host list |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + caller ECX sealed; product host type residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00507290_Host_ActionList_Push.md`, `reviews/B_aa_00507290_Host_ActionList_Push.md` |
| **Last reviewed** | `2026-07-29` (W19-O) |

## Purpose

Append a pointer into the host growable pointer vector at **`host+0x94`** (count `+0x98`, capacity `+0x9c`). Grow via `FUN_005b3370` when full. Used by physics action base construction to register the action on its host.

## Signature

```c
void __thiscall Host_ActionList_Push(void *host, void *itemPtr);  // ECX=host; ret 4
```

## Layout

| Offset | Field |
|---|---|
| `host+0x94` | `void**` data |
| `host+0x98` | `int` count |
| `host+0x9c` | `uint` capacity (`& 0x7fffffff` for full test) |

## Algorithm

1. If `count == (capacity & 0x7fffffff)`: `FUN_005b3370(&vector, 4)`.
2. `data[count] = itemPtr`; `count++`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00507290_FUN_00507290.md`
- Annotated: `docs/reconstruction/raw/aa_00507290_FUN_00507290.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Host_ActionList_Push.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00507290.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-own-w19o-006078e0-00507290-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callee** | `FUN_005b3370` grow helper |
| **Callers** | `Phys_ActionBase_ctor` `0x00636370`, `FUN_00636220`, `FUN_0066e660` (×2) — **ECX=host** at every site |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| ECX=host, stack=item, ret 4 | **High** |
| Vector offsets +0x94/+0x98/+0x9c | **High** |
| Element size 4 | **High** |
| Product host C++ type name | **Low** (residual) |
| Capacity high-bit meaning | **Medium** (masked; ownership flag inferred) |

## Related

- `aa_00636370` Phys_ActionBase_ctor (primary consumer)
- `FUN_005b3370` vector grow
- Sibling dtors / dual-host actions (`FUN_0066e660`)
