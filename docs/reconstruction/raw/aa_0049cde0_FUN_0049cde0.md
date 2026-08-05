# Raw capture: FUN_0049cde0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0049cde0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0049cde0` |
| **Canonical name** | `FUN_0049cde0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0049cde0(int param_1,int *param_2)

{
  int iVar1;
  char cStack_b;
  byte bStack_a;
  char cStack_9;
  int *local_8;
  int iStack_4;
  
  if (((param_2 != (int *)0x0) &&
      (iVar1 = (**(code **)(*param_2 + 0x44))(param_2,&local_8), iVar1 == 0)) &&
     (local_8 != (int *)0x0)) {
    *(byte *)(param_1 + 0x98a) = *(byte *)(param_1 + 0x98a) | 0x40;
    iVar1 = param_1 + 0x928;
    param_2 = (int *)((uint)param_2 & 0xffffff00);
    cStack_9 = '\0';
    bStack_a = 0;
    cStack_b = '\0';
    iStack_4 = 0;
    FUN_00798f30(local_8,&iStack_4,L"radius",iVar1,param_1 + 0x92c,&param_2);
    if (((char)param_2 != '\0') && (iStack_4 != 0)) {
      iVar1 = param_1 + 0x92c;
    }
    FUN_005b8370(iStack_4,4,iVar1,param_1);
    *(byte *)(param_1 + 0x98b) =
         *(byte *)(param_1 + 0x98b) ^ ((char)param_2 << 6 ^ *(byte *)(param_1 + 0x98b)) & 0x40;
    FUN_00799300(local_8,L"radiusIncrease",param_1 + 0x930);
    FUN_007995a0(local_8,&iStack_4,L"axis",param_1 + 0x93c,param_1 + 0x948,&param_2,&bStack_a);
    FUN_005b8370(iStack_4,0xc,param_1 + 0x93c,param_1);
    *(byte *)(param_1 + 0x98c) =
         *(byte *)(param_1 + 0x98c) ^ (*(byte *)(param_1 + 0x98c) ^ bStack_a) & 1;
    *(byte *)(param_1 + 0x98b) = *(byte *)(param_1 + 0x98b) & 0x7f | (char)param_2 << 7;
    FUN_007996d0(local_8,L"useBodyH",&cStack_9);
    *(byte *)(param_1 + 0x98c) =
         *(byte *)(param_1 + 0x98c) ^ (cStack_9 * '\x04' ^ *(byte *)(param_1 + 0x98c)) & 4;
    cStack_b = '\0';
    FUN_007996d0(local_8,L"relativeCoords",&cStack_b);
    *(byte *)(param_1 + 0x98c) =
         *(byte *)(param_1 + 0x98c) ^ (cStack_b * '\b' ^ *(byte *)(param_1 + 0x98c)) & 8;
    FUN_00799200(local_8,L"rotationPosition",param_1 + 0x934,param_1 + 0x938,&param_2);
    *(byte *)(param_1 + 0x98c) =
         *(byte *)(param_1 + 0x98c) ^ ((char)param_2 * '\x02' ^ *(byte *)(param_1 + 0x98c)) & 2;
    (**(code **)(*local_8 + 8))(local_8);
    return 1;
  }
  FUN_007a4480(0,"VOG_DEBUG_STOP");
  return 0;
}
```
