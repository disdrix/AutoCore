# Annotated low-level: Client_SendUpdateFirstTimeFlags

| Field | Value |
|---|---|
| Stable ID | `aa_0092c6d0` |
| VA | `0x0092c6d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0092c6d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Send EMSG_Sector_UpdateFirstTimeFlags_Request (0x20B1).
   Payload: opcode + 4x uint32 FirstTimeFlags (size 0x14).
   ESI = game state; EDX = pointer to 4 dwords (char+0xD30 or copy).
   Copies flags into local player char+0xD30 then sends via connection vtable+0x18.
   AutoCore: UpdateFirstTimeFlagsRequestPacket / HandleUpdateFirstTimeFlagsRequest. */

void __fastcall Client_SendUpdateFirstTimeFlags(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  byte bVar2;
  int unaff_ESI;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(int *)(unaff_ESI + 0xe98) != 0) && (param_2 != (undefined4 *)0x0)) {
    bVar2 = 0;
    iVar1 = 0xd30;
    do {
      *(undefined4 *)(iVar1 + *(int *)(unaff_ESI + 0xe98)) =
           *(undefined4 *)((int)param_2 + iVar1 + -0xd30);
      bVar2 = bVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (bVar2 < 4);
    local_10 = *param_2;
    local_c = param_2[1];
    local_8 = param_2[2];
    local_4 = param_2[3];
    local_14 = 0x20b1;
    if (*(int *)(unaff_ESI + 0xc78) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,&local_14,0x14,0);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
