# Raw capture: FUN_005b4de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b4de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b4de0` |
| **Canonical name** | `FUN_005b4de0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_005b4de0(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a68bf;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0076cf00("SetupFrondForTreeType");
  local_4 = 0;
  FUN_0068a4d0(*(undefined4 *)(param_1 + 0x50),2,0xffffffff,0xffffffff,0xffffffff);
  if (*(short *)(*(int *)(param_1 + 0x50) + 0x40) != 0) {
    *(uint *)(*(int *)(param_1 + 0x10) + 0xc4) =
         *(ushort *)(*(int *)(param_1 + 0x70) + *(int *)(*(int *)(param_1 + 0x50) + 0x3c) * 2) - 2;
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xd0);
    cVar2 = FUN_0096fdf0();
    iVar3 = FUN_00752a00(uVar1,&DAT_00b05240);
    if ((iVar3 == -1) && (cVar2 != '\0')) {
      FUN_0096f5d0();
    }
    local_4 = 0xffffffff;
    FUN_0076cef0();
    ExceptionList = local_c;
    return 1;
  }
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_c;
  return 0;
}
```
