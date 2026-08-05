# Function record: CircularListHead_ClearFreeNodes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b8340` |
| **Canonical name** | `CircularListHead_ClearFreeNodes_Inferred` |
| **Ghidra name** | `FUN_005b8340` |
| **Address** | `0x005b8340`–`0x005b8369` exclusive (**41 B** / `0x29`) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | circular list head clear (free all non-head nodes) |
| **Name confidence** | **Inferred** (structural from bytes + multi-caller list use; no product string/RTTI) |
| **Completion** | Dual A/B W37-AC — **accept-with-gaps** |
| **Runtime / bit-exact / diff** | Open |

## Role

Shared list-clear primitive used by ObjectMotion host teardown, NDSpecialFX finalize, and related host/buffer teardown paths. Callers pass:

- Host-embedded list heads (e.g. `host+0x7dc`)
- Buffer-embedded list heads (e.g. `buffer+8` when primary buffer is heap, not inline)

## Signature

```c
void __fastcall CircularListHead_ClearFreeNodes_Inferred(void* head);
// head+0, head+4 = link fields; empty ⇒ both == head
```

## Contrast with related clears

| Unit | VA | Diff vs this |
|---|---|---|
| `StdList_Clear_Inferred` | `0x00404060` | list object + `_Myhead` + size@+8; decompile also collapses free-loop |
| `OwningSList_ClearDestroy_ScalarDtor` | `0x004bf740` | singly-linked; scalar dtor vtbl[0](1); count@+0xc |
| This unit | `0x005b8340` | ECX is sentinel; bare delete; free-loop **proven in bytes** |

## Artifacts

See `aa_005b8340_FUN_005b8340.md` for full path table.
