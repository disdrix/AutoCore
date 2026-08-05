# Function record (named): ObjectCsListBase_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bf10` |
| **Semantic name** | `ObjectCsListBase_ScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_0051bf10` |
| **Address** | `0x0051bf10`–`0x0051bf3e` exclusive (**46 B** / `0x2E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object core / CS-owned list teardown |
| **Naming basis** | vtbl `PTR_FUN_009ce07c` slot0 scalar deleting dtor; base-phase only (no `009ce154` install); pairs with complete dtor `ObjectCsList_CompleteDtor_Inferred` |
| **Status** | Dual sealed W31-R (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Virtual scalar deleting dtor for the **base** Object CS-list type: install base vtbl, drain nodes under CS, destroy the embedded critical section, optionally free the object when MSVC flag bit0 is set. Does **not** run the derived-vtbl phase present in `ObjectCsList_CompleteDtor_Inferred`.

## Signature

```c
// __thiscall; ECX=list*; stack flags; RET 4; returns this
void * __thiscall ObjectCsListBase_ScalarDeletingDtor_Inferred(void *list, uint8_t flags);
```

## Layouts

Same list object as W30-F / complete dtor (`sizeof 0x2C`, CS @ `+0x04`, head @ `+0x1C`, lock @ `+0x28`).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051bf10_FUN_0051bf10.md`
- Annotated: `docs/reconstruction/raw/aa_0051bf10_FUN_0051bf10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ObjectCsListBase_ScalarDeletingDtor_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0051bf10.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0051bf10_FUN_0051bf10.md`
- Reviews: `A_aa_0051bf10_ObjectCsListBase_ScalarDeletingDtor_Inferred.md`, `B_aa_0051bf10_ObjectCsListBase_ScalarDeletingDtor_Inferred.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Xref | `PTR_FUN_009ce07c` @ `0x009ce07c` | virtual slot0 |
| Callee | `FUN_0051bc90` | drain |
| Callee | `DeleteCriticalSection` | `this+4` |
| Callee | `operator_delete` | conditional |
| Related complete | `ObjectCsList_CompleteDtor_Inferred` `0x0051d0e0` | derived dual-phase |
| Related clear | `ObjectCsList_ClearDestroy_Inferred` `0x0051b8a0` | nodes only |

## Confidence

| Claim | Level |
|---|---|
| Scalar-deleting role + ABI | **High** |
| Base vtbl identity | **High** |
| Product base class name | **Open** |
