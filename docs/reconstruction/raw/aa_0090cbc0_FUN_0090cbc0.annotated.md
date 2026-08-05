# Annotated low-level: FUN_0090cbc0

| Field | Value |
|---|---|
| Stable ID | `aa_0090cbc0` |
| VA | `0x0090cbc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0090cbc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0090cbc0(void)

{
  int iVar1;
  char cVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iStack_4;
  
  iVar1 = DAT_00d1b6d8;
  if ((DAT_00d1b6d8 != 0) && (cVar2 = (**(code **)(*in_EAX + 0x3d8))(), cVar2 != '\0')) {
    FUN_0090c700();
    iVar5 = 0;
    iVar3 = FUN_0090c810();
    if (0 < iVar3) {
      iVar6 = (iVar3 + -0x19) / 3 + 1;
      in_EAX[0x169] = iVar6;
      if (iVar3 < 0x19) {
        in_EAX[0x169] = 0;
        in_EAX[0x143] = 0;
      }
      else if (iVar6 < in_EAX[0x143]) {
        in_EAX[0x143] = iVar6;
      }
      if ((int *)in_EAX[0x168] != (int *)0x0) {
        iVar3 = *(int *)in_EAX[0x168];
        if (in_EAX[0x169] == 0) {
          (**(code **)(iVar3 + 0xcc))(0);
        }
        else {
          (**(code **)(iVar3 + 0xcc))(1);
          (**(code **)(*(int *)in_EAX[0x168] + 0x460))(g_flOne / (float)in_EAX[0x169]);
        }
        (**(code **)(*(int *)in_EAX[0x168] + 0x34c))();
      }
      puVar7 = *(undefined4 **)(iVar1 + 0x574);
      iStack_4 = -1;
      do {
        if (puVar7 == *(undefined4 **)(iVar1 + 0x578)) break;
        iVar3 = FUN_0051a0e0(*puVar7);
        if ((iVar3 != 0) && (iStack_4 = iStack_4 + 1, in_EAX[0x143] * 3 <= iStack_4)) {
          FUN_0090c9a0(iVar3,1);
          iVar5 = iVar5 + 1;
        }
        puVar7 = puVar7 + 1;
      } while (iVar5 < 0x18);
      iVar3 = *(int *)(iVar1 + 0x540);
      iVar6 = 0;
      if (*(char *)(iVar3 + 0x1d) != '\0') {
        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0,"VOG_DEBUG_STOP");
      }
      *(undefined1 *)(iVar3 + 0x1d) = 1;
      iVar3 = iVar5;
      while (iVar5 < 0x18) {
        iVar4 = *(int *)(iVar1 + 0x540);
        if (*(char *)(iVar4 + 0x1d) == '\0') {
          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
          FUN_007a4480(0,"VOG_DEBUG_STOP");
        }
        if (iVar6 == 0) {
          iVar6 = *(int *)(iVar4 + 0x14);
        }
        else {
          iVar6 = *(int *)(iVar6 + 0x14);
        }
        if (iVar6 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(iVar6 + 8);
        }
        if (iVar4 == 0) break;
        iVar4 = FUN_0051a0e0(*(undefined4 *)(iVar4 + 0x100));
        if ((iVar4 != 0) && (iStack_4 = iStack_4 + 1, in_EAX[0x143] * 3 <= iStack_4)) {
          FUN_0090c9a0(iVar4,0);
          iVar5 = iVar3 + 1;
          iVar3 = iVar5;
        }
      }
      *(undefined1 *)(*(int *)(iVar1 + 0x540) + 0x1d) = 0;
      return;
    }
    in_EAX[0x143] = 0;
    if ((int *)in_EAX[0x168] != (int *)0x0) {
      (**(code **)(*(int *)in_EAX[0x168] + 4))(0);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
