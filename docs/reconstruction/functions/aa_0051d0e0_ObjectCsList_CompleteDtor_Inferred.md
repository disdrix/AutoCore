# Function record (named): ObjectCsList_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d0e0` |
| **Semantic name** | `ObjectCsList_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_0051d0e0` |
| **Address** | `0x0051d0e0`–`0x0051d107` exclusive (**39 B** / `0x27`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object core / CS-owned list teardown |
| **Naming basis** | Complete dtor for Object SharedBase CS helper (`core+0xB0`, `sizeof 0x2C`); dual-phase vtbl install `009ce154`→`009ce07c` + drain + `DeleteCriticalSection`; pairs with W30-F `ObjectCsList_ClearDestroy_Inferred` |
| **Status** | Dual sealed W31-R (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Tear down the Object CS-list **object** (not only its nodes): MSVC complete-dtor sequence installs derived then base vtbls around `FUN_0051bc90` drains, then destroys the embedded `CRITICAL_SECTION` at `+0x04`. Callers that own the allocation use scalar wrapper `FUN_0051d0c0` (or free after this complete body).

## Signature

```c
// __thiscall/__fastcall; ECX=list*; void; bare RET
void __fastcall ObjectCsList_CompleteDtor_Inferred(void *list);
```

## Layouts

### List (`sizeof 0x2C` — sealed via SharedBase_Ctor / W30-F)

| Off | Field | Conf |
|----:|-------|------|
| `+0x00` | vtbl (`009ce154` then `009ce07c` during dtor) | **High** |
| `+0x04` | `CRITICAL_SECTION` (deleted here) | **High** |
| `+0x1C` | head node* | **High** |
| `+0x20` | field (zeroed by clear) | **High** (role open) |
| `+0x24` | field (zeroed by clear) | **High** (role open) |
| `+0x28` | busy / TraversalLock flag | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051d0e0_FUN_0051d0e0.md`
- Annotated: `docs/reconstruction/raw/aa_0051d0e0_FUN_0051d0e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ObjectCsList_CompleteDtor_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0051d0e0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0051d0e0_FUN_0051d0e0.md`
- Reviews: `A_aa_0051d0e0_ObjectCsList_CompleteDtor_Inferred.md`, `B_aa_0051d0e0_ObjectCsList_CompleteDtor_Inferred.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_0051d0c0` | scalar deleting for derived vtbl |
| Callee | `FUN_0051bc90` ×2 | drain |
| Callee | `DeleteCriticalSection` | `this+4` |
| Related | `ObjectCsListBase_ScalarDeletingDtor_Inferred` `0x0051bf10` | base scalar |
| Related | `ObjectCsList_ClearDestroy_Inferred` `0x0051b8a0` | node clear only |
| Related ctor | `Object_SharedBase_Ctor` `0x00518940` | `new(0x2C)` + CS init @ `+0xB0` |

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor ABI / CF / sizes | **High** |
| Dual vtbl + DeleteCS | **High** |
| Distinct from clear-only `0051b8a0` | **High** |
| Product English | **Open** |
