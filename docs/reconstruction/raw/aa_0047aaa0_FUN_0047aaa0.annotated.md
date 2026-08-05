# Annotated low-level: FUN_0047aaa0

| Field | Value |
|---|---|
| Stable ID | `aa_0047aaa0` |
| VA | `0x0047aaa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0047aaa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0047aaa0(undefined4 param_1,int param_2)

{
  byte bVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  
  if ((*(uint *)(in_EAX + 0x68) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00476cc0();
  }
  if (param_2 != 0xd) {
                    /* WARNING: Subroutine does not return */
    FUN_00476cc0();
  }
  *(uint *)(in_EAX + 0x68) = *(uint *)(in_EAX + 0x68) | 1;
  FUN_0047a420();
  FUN_0047a480();
  iVar2 = FUN_0047a3c0();
  uVar3 = FUN_0047a3c0();
  *(undefined1 *)(in_EAX + 0x123) = local_4;
  *(undefined1 *)(in_EAX + 0x238) = local_5;
  *(int *)(in_EAX + 200) = iVar2;
  *(undefined4 *)(in_EAX + 0xcc) = uVar3;
  *(char *)(in_EAX + 0x127) = local_8;
  *(undefined1 *)(in_EAX + 0x126) = local_7;
  *(undefined1 *)(in_EAX + 0x260) = local_6;
  switch(local_7) {
  case 0:
  case 3:
    *(undefined1 *)(in_EAX + 0x12a) = 1;
    break;
  case 2:
    *(undefined1 *)(in_EAX + 0x12a) = 3;
    break;
  case 4:
    *(undefined1 *)(in_EAX + 0x12a) = 2;
    break;
  case 6:
    *(undefined1 *)(in_EAX + 0x12a) = 4;
  }
  bVar1 = *(char *)(in_EAX + 0x12a) * local_8;
  *(byte *)(in_EAX + 0x129) = bVar1;
  if (bVar1 < 8) {
    uVar4 = (uint)bVar1 * iVar2 + 7 >> 3;
  }
  else {
    uVar4 = (uint)(bVar1 >> 3) * iVar2;
  }
  *(uint *)(in_EAX + 0xd8) = uVar4;
  FUN_00470090(iVar2,uVar3,local_8,local_4,local_6,local_5);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
