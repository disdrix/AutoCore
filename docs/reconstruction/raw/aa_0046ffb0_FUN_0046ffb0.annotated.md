# Annotated low-level: FUN_0046ffb0

| Field | Value |
|---|---|
| Stable ID | `aa_0046ffb0` |
| VA | `0x0046ffb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0046ffb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0046ffb0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_EAX;
  void *pvVar3;
  int iVar4;
  int unaff_EDI;
  
  if ((in_EAX != 0) && (unaff_EDI != 0)) {
    if (*(short *)(unaff_EDI + 0x14) == 0) {
      FUN_00476d60();
      return;
    }
    FUN_004766e0();
    uVar1 = *(uint *)(in_EAX + 0x6c);
    *(uint *)(in_EAX + 0x6c) = uVar1 | 0x100000;
    if (*(code **)(in_EAX + 0x248) == (code *)0x0) {
      pvVar3 = malloc(0x200);
    }
    else {
      pvVar3 = (void *)(**(code **)(in_EAX + 0x248))();
    }
    if ((pvVar3 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_00476cc0();
    }
    *(uint *)(in_EAX + 0x6c) = uVar1;
    *(void **)(in_EAX + 500) = pvVar3;
    if (pvVar3 == (void *)0x0) {
      FUN_00476d60();
      return;
    }
    iVar4 = 0;
    if (*(short *)(unaff_EDI + 0x14) != 0) {
      do {
        *(undefined2 *)(*(int *)(in_EAX + 500) + iVar4 * 2) = *(undefined2 *)(param_1 + iVar4 * 2);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(ushort *)(unaff_EDI + 0x14));
    }
    uVar2 = *(undefined4 *)(in_EAX + 500);
    *(uint *)(unaff_EDI + 8) = *(uint *)(unaff_EDI + 8) | 0x40;
    *(uint *)(unaff_EDI + 0xb8) = *(uint *)(unaff_EDI + 0xb8) | 8;
    *(undefined4 *)(unaff_EDI + 0x7c) = uVar2;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
