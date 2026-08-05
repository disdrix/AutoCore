# Annotated low-level: Client_LookupObjectByTfid_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004bb0a0` |
| VA | `0x004bb0a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bb0a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_LookupObjectByTfid_Inferred — resolve world object by TFID.
   
   Parameters (INFERRED from CharacterLevel dispatch):
     globalFlag (byte), coidLo (uint), coidHi (uint)
   Returns: object* or null.
   
   Called from Client_RecvCharacterLevel before ApplyCharacterLevelPacket vfunc. */

void * __cdecl Client_LookupObjectByTfid_Inferred(byte bGlobal,uint nCoidLo,uint nCoidHi)

{
  int *piVar1;
  void *pvVar2;
  undefined3 in_stack_00000005;
  
  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(_bGlobal,nCoidLo,nCoidHi);
  if (piVar1 != (int *)0x0) {
    pvVar2 = (void *)(**(code **)(*piVar1 + 0x1dc))();
    return pvVar2;
  }
  return (void *)0x0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
