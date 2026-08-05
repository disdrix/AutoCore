# Raw capture: FUN_005ab9d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ab9d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ab9d0` |
| **Canonical name** | `FUN_005ab9d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_005ab9d0(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_ESI;
  BSTR unaff_EDI;
  undefined1 *puVar3;
  uint local_1014 [510];
  undefined1 auStack_81c [8];
  undefined2 uStack_814;
  void *pvStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a650b;
  pvStack_c = ExceptionList;
  uStack_10 = 0x5ab9ef;
  puVar3 = (undefined1 *)0x0;
  local_1014[0] = 0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x68))(param_1);
  uStack_814 = 0;
  local_1014[0] = local_1014[0] & 0xffff0000;
  iVar2 = (**(code **)(*param_1 + 0x44))(param_1,&stack0xffffefe0);
  if ((iVar2 == 0) && (local_1014 != (uint *)0x0)) {
    cVar1 = FUN_00798bb0(local_1014,L"name",auStack_81c);
    if (cVar1 == '\0') {
      (**(code **)(local_1014[0] + 8))(local_1014);
    }
    else {
      cVar1 = FUN_00799460(local_1014,L"index",&stack0xffffefe0,10);
      if (cVar1 == '\0') {
        unaff_ESI = 0xffffffff;
      }
      cVar1 = FUN_00798bb0(local_1014,L"description",&stack0xffffefe4);
      if (cVar1 != '\0') {
        puVar3 = &stack0xffffefe4;
      }
      (**(code **)(local_1014[0] + 8))(local_1014);
      FUN_005aaf20(auStack_81c,&stack0xffffefdc,unaff_ESI,puVar3);
    }
  }
  SysFreeString(unaff_EDI);
  ExceptionList = pvStack_1c;
  return;
}
```
