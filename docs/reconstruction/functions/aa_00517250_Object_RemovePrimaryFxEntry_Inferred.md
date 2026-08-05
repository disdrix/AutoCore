# Function record: Object_RemovePrimaryFxEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517250` |
| **Canonical name** | `Object_RemovePrimaryFxEntry_Inferred` |
| **Ghidra name** | `FUN_00517250` |
| **Address** | `0x00517250` |
| **Body range** | `0x00517250`–`0x005172c1` (114 B / `0x72`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / object primary FX ptr-vector single-remove |
| **Dual A/B** | `reviews/A_aa_00517250_Object_RemovePrimaryFxEntry_Inferred.md`, `reviews/B_aa_00517250_Object_RemovePrimaryFxEntry_Inferred.md` (2026-07-29 W29-N) |

## Signature

```c
void __thiscall Object_RemovePrimaryFxEntry_Inferred(void *self, void *fx);
```

## Role

Single-entry remove used when:

1. Owned-list teardown clears sticky current FX at `+0x130`.
2. `CVOGObject_SetInteractSpecialFX` replaces the interact special-FX pointer.

Not a full vector free — primary bulk teardown remains in `Object_TeardownOwnedFxLists_Inferred`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00517250_FUN_00517250.md`
- Annotated: `docs/reconstruction/raw/aa_00517250_FUN_00517250.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_RemovePrimaryFxEntry_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00517250.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00517250_FUN_00517250.md`
- Report: `docs/agents/task-dual-ab-00516930-00517250-w29n-report.md`
