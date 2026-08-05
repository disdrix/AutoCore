# Raw capture: FUN_008cc7f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008cc7f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008cc7f0` |
| **Canonical name** | `FUN_008cc7f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x008cc905) */

void __fastcall FUN_008cc7f0(int param_1)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *unaff_EBX;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 local_8c [128];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009ac5be;
  local_c = ExceptionList;
  if (unaff_EBX != (char *)0x0) {
    if (param_1 == 0) {
      *unaff_EBX = '\0';
      return;
    }
    uVar6 = *(uint *)(param_1 + 0x740);
    ExceptionList = &local_c;
    pvVar2 = (void *)FUN_00541a80();
    pvVar2 = CNDHash_LookupByKey(pvVar2,uVar6);
    if (pvVar2 == (void *)0x0) {
      uVar6 = *(uint *)(param_1 + 0x73c);
      pvVar2 = (void *)FUN_00541a80();
      pvVar2 = CNDHash_LookupByKey(pvVar2,uVar6);
      if (pvVar2 == (void *)0x0) {
        *(undefined4 *)unaff_EBX = DAT_00a41270;
        *(undefined2 *)(unaff_EBX + 4) = DAT_00a41274;
        ExceptionList = local_c;
        return;
      }
    }
    puVar5 = local_8c;
    uVar3 = (*(code *)PTR_FUN_00af8c9c)();
    FUN_00403450((int)pvVar2 + 0xb4,uVar3);
    uStack_4 = 0;
    uVar3 = 0xffffffff;
    FUN_007a69d0(puVar5,0xffffffff);
    pcVar4 = (char *)FUN_007a6de0(puVar5,uVar3);
    do {
      cVar1 = *pcVar4;
      *unaff_EBX = cVar1;
      pcVar4 = pcVar4 + 1;
      unaff_EBX = unaff_EBX + 1;
    } while (cVar1 != '\0');
  }
  ExceptionList = local_c;
  return;
}
```
