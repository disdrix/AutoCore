# Raw capture: FUN_0094caa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094caa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094caa0` |
| **Canonical name** | `FUN_0094caa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0094caa0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined2 extraout_var;
  char unaff_BL;
  void *unaff_ESI;
  undefined4 auStack_18 [2];
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if ((((*(int *)((int)unaff_ESI + 0xe98) != 0) &&
       (piVar1 = *(int **)((int)unaff_ESI + 0x1050), piVar1 != (int *)0x0)) &&
      (cVar4 = (**(code **)(*piVar1 + 0x3d8))(), cVar4 != '\0')) &&
     (*(int *)(*(int *)((int)unaff_ESI + 0xe98) + 0x250) != 0)) {
    if ((unaff_BL != '\0') &&
       (iVar2 = *(int *)(*(int *)((int)unaff_ESI + 0xe98) + 0x250),
       cVar4 = FUN_00521e90(*(undefined4 *)(piVar1[0x144] + 0xce0),*(undefined4 *)(iVar2 + 0x2b0),
                            CONCAT22(extraout_var,*(undefined2 *)(iVar2 + 0x1e6))), cVar4 == '\0'))
    {
      FUN_007fdfb0(unaff_ESI,"Your inventory is too full to accept.",0xffffffff,1,0);
      return;
    }
    iVar2 = *(int *)((int)unaff_ESI + 0xe98);
    auStack_18[0] = 0x208f;
    iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);
    uStack_10 = *(undefined4 *)(iVar3 + 0x164 + iVar2);
    uStack_c = *(undefined4 *)(iVar3 + 0x168 + iVar2);
    Client_SendSectorPacket(unaff_ESI,0x18,auStack_18);
  }
  return;
}
```
