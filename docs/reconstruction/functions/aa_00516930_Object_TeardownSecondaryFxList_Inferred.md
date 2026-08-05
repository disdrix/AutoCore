# Function record: Object_TeardownSecondaryFxList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516930` |
| **Canonical name** | `Object_TeardownSecondaryFxList_Inferred` |
| **Ghidra name** | `FUN_00516930` |
| **Address** | `0x00516930` |
| **Body range** | `0x00516930`–`0x005169a8` (121 B / `0x79`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / object secondary FX ptr-vector teardown |
| **Dual A/B** | `reviews/A_aa_00516930_Object_TeardownSecondaryFxList_Inferred.md`, `reviews/B_aa_00516930_Object_TeardownSecondaryFxList_Inferred.md` (2026-07-29 W29-N) |

## Signature

```c
void __thiscall Object_TeardownSecondaryFxList_Inferred(void *self, int unused_stack);
```

## Role

First step of `Object_TeardownOwnedFxLists_Inferred` (W28-H): clear secondary list before primary walk / sticky remove. Also used by `FUN_00518370` before setting `+0x184` bit 2 and loading mission-complete FX variants.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00516930_FUN_00516930.md`
- Annotated: `docs/reconstruction/raw/aa_00516930_FUN_00516930.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_TeardownSecondaryFxList_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00516930.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00516930_FUN_00516930.md`
- Report: `docs/agents/task-dual-ab-00516930-00517250-w29n-report.md`
