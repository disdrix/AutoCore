# Raw capture: FUN_0040ccb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ccb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040ccb0` |
| **Canonical name** | `FUN_0040ccb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x0040cd7a) */
/* WARNING: Removing unreachable block (ram,0x0040cd17) */
/* WARNING: Removing unreachable block (ram,0x0040cde1) */

int FUN_0040ccb0(void)

{
  uint uVar1;
  uint uVar2;
  int in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  uint uVar3;
  
  uVar1 = *(uint *)(in_EAX + 0x720);
  uVar2 = *(uint *)(in_EAX + 0x728);
  uVar3 = *(uint *)(in_EAX + 0x728);
  iVar5 = *(int *)(*(int *)(in_EAX + 4) + 4);
  iVar6 = *(int *)(in_EAX + 0x724);
  iVar7 = *(int *)(in_EAX + 0x72c);
  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x27c))();
  iVar5 = (**(code **)(*(int *)(iVar5 + 4 + in_EAX) + 0x27c))();
  iVar5 = iVar5 * (iVar4 + -5);
  lVar8 = __alldiv(iVar5,iVar5 >> 0x1f,2,0);
  if (lVar8 < CONCAT44((iVar6 - iVar7) - (uint)(uVar1 < uVar2),uVar1 - uVar3)) {
    iVar5 = *(int *)(*(int *)(in_EAX + 4) + 4);
    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x27c))();
    iVar5 = (**(code **)(*(int *)(iVar5 + 4 + in_EAX) + 0x27c))();
    iVar5 = iVar5 * (iVar6 + -5);
    lVar8 = __alldiv(iVar5,iVar5 >> 0x1f,2,0);
  }
  else {
    lVar8 = CONCAT44((*(int *)(in_EAX + 0x724) - *(int *)(in_EAX + 0x72c)) -
                     (uint)(*(uint *)(in_EAX + 0x720) < *(uint *)(in_EAX + 0x728)),
                     *(uint *)(in_EAX + 0x720) - *(uint *)(in_EAX + 0x728));
  }
  if (lVar8 < 1) {
    return 0;
  }
  uVar1 = *(uint *)(in_EAX + 0x720);
  uVar2 = *(uint *)(in_EAX + 0x728);
  uVar3 = *(uint *)(in_EAX + 0x728);
  iVar5 = *(int *)(in_EAX + 0x724);
  iVar6 = *(int *)(in_EAX + 0x72c);
  iVar7 = *(int *)(*(int *)(in_EAX + 4) + 4);
  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x27c))();
  iVar7 = (**(code **)(*(int *)(iVar7 + 4 + in_EAX) + 0x27c))();
  iVar7 = iVar7 * (iVar4 + -5);
  lVar8 = __alldiv(iVar7,iVar7 >> 0x1f,2,0);
  if (CONCAT44((iVar5 - iVar6) - (uint)(uVar1 < uVar2),uVar1 - uVar3) <= lVar8) {
    return *(int *)(in_EAX + 0x720) - *(int *)(in_EAX + 0x728);
  }
  iVar5 = *(int *)(*(int *)(in_EAX + 4) + 4);
  iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(in_EAX + 4) + 4) + 4 + in_EAX) + 0x27c))();
  iVar5 = (**(code **)(*(int *)(iVar5 + 4 + in_EAX) + 0x27c))();
  iVar5 = iVar5 * (iVar6 + -5);
  iVar5 = __alldiv(iVar5,iVar5 >> 0x1f,2,0);
  return iVar5;
}
```
