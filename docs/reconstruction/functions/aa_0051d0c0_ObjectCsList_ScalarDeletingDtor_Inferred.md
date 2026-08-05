# Function record: ObjectCsList_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d0c0` |
| **Canonical name** | `ObjectCsList_ScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_0051d0c0` |
| **Address** | `0x0051d0c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object core / CS-owned list teardown |
| **Wave** | W37-O OWN-ONLY dual |
| **Completion status** | **Sealed** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Derived ObjectCsList scalar deleting dtor (`PTR_FUN_009ce154[0]`): complete dtor then optional heap free. **Not skill.**

## Signature

```c
void * __thiscall ObjectCsList_ScalarDeletingDtor_Inferred(void *list, uint8_t flags);
```

## See also

- Complete twin: `aa_0051d0e0_ObjectCsList_CompleteDtor_Inferred.md` (W31-R)
- Base scalar: `aa_0051bf10_ObjectCsListBase_ScalarDeletingDtor_Inferred.md` (W31-R)
- Report: `docs/agents/task-dual-ab-00788db0-0051d0c0-w37o-report.md`
