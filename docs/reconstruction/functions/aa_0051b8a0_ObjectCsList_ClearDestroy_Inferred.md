# Function record (named): ObjectCsList_ClearDestroy_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b8a0` |
| **Semantic name** | `ObjectCsList_ClearDestroy_Inferred` |
| **Ghidra name** | `FUN_0051b8a0` |
| **Address** | `0x0051b8a0`–`0x0051b99c` exclusive (**252 B** / `0xFC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object core / CS-owned list teardown |
| **Naming basis** | Operates on Object SharedBase CS helper (`new(0x2C)` @ `+0xB0`, vtbl `PTR_FUN_009ce154`); same algorithm family as sealed `List_ClearDestroy` (`0x0040dc40`) with node next@+8 |
| **Status** | Dual sealed W30-F (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Drain-and-scalar-delete every node in the Object CS-list under its critical section. Refuses (throws `E_ACCESSDENIED` / `0x80070005`) when TraversalLock-style flag `list+0x28` is set. Does **not** destroy the list object or call `DeleteCriticalSection` (that is the separate dtor path `FUN_0051d0e0` / scalar `FUN_0051bf10`).

## Signature

```c
// __thiscall/__fastcall; ECX=list*; void; bare RET
void __fastcall ObjectCsList_ClearDestroy_Inferred(void *list);
```

## Layouts

### List (`sizeof 0x2C` — sealed via SharedBase_Ctor)

| Off | Field | Conf |
|----:|-------|------|
| `+0x00` | vtbl `PTR_FUN_009ce154` | **High** |
| `+0x04` | `CRITICAL_SECTION` | **High** |
| `+0x1C` | head node* | **High** |
| `+0x20` | field (zeroed) | **High** (role open) |
| `+0x24` | field (zeroed) | **High** (role open) |
| `+0x28` | busy / TraversalLock flag | **High** |

### Node

| Off | Field | Conf |
|----:|-------|------|
| `+0x00` | vtbl → scalar dtor | **High** |
| `+0x04` | cleared to 0 pre-dtor | **High** |
| `+0x08` | next* | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051b8a0_FUN_0051b8a0.md`
- Annotated: `docs/reconstruction/raw/aa_0051b8a0_FUN_0051b8a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ObjectCsList_ClearDestroy_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0051b8a0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0051b8a0_FUN_0051b8a0.md`
- Reviews: `A_aa_0051b8a0_ObjectCsList_ClearDestroy_Inferred.md`, `B_aa_0051b8a0_ObjectCsList_ClearDestroy_Inferred.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `Object_SharedBase_Dtor` `0x00518ec0` | before scalar-delete of `+0xB0` |
| Caller | CODE `0x00514d30` | same list ECX |
| Related ctor | `Object_SharedBase_Ctor` `0x00518940` | allocates helper |
| Related dtor | `FUN_0051d0e0` / `FUN_0051bf10` | list object teardown |
| Sibling | `List_ClearDestroy` `0x0040dc40` | inventory-style next@+0x10 |

## Confidence

| Claim | Level |
|---|---|
| ABI + CS + throw + drain CF | **High** |
| SharedBase `+0xB0` target | **High** |
| Distinct from list object dtor | **High** |
| Product English | **Open** |
