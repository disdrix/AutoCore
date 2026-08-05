# Annotated low-level: Client_SendInstantRepairRequest

| Field | Value |
|---|---|
| Stable ID | `aa_0092ce00` |
| VA | `0x0092ce00` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0092ce00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_SendInstantRepairRequest — INC option 1.
   Sends opcode 0x20B6 (EMSG_Sector_InstantRepair_Request), body often just opcode (4 bytes).
   Not implemented in AutoCore yet. */

void Client_SendInstantRepairRequest(void)

{
  int iVar1;
  int in_EAX;
  DWORD DVar2;
  undefined4 local_4;
  
  if (DAT_00d1b6d8 != 0) {
    local_4 = 0x20b6;
    if (*(int *)(in_EAX + 0xc78) != 0) {
      (**(code **)(**(int **)(in_EAX + 0xc78) + 0x18))(0xffffffff,&local_4,4,0);
    }
    iVar1 = DAT_00d1b6d8;
    DVar2 = GetTickCount();
    *(DWORD *)(iVar1 + 0x620) = DVar2;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
