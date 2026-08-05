# Raw capture: FUN_004eb0f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eb0f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004eb0f0` |
| **Canonical name** | `FUN_004eb0f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_004eb0f0(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *unaff_EDI;
  undefined4 uVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a274d;
  local_c = ExceptionList;
  pcVar4 = (char *)*unaff_EDI;
  pcVar3 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    pcVar3 = PTR_DAT_00afa2bc;
  }
  pcVar1 = pcVar3 + 1;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  if (4 < (uint)((int)pcVar3 - (int)pcVar1)) {
    if (pcVar4 == (char *)0x0) {
      pcVar4 = PTR_DAT_00afa2bc;
    }
    uVar5 = 0xffffffff;
    ExceptionList = &local_c;
    FUN_007b6a20(pcVar4,0xffffffff);
    cVar2 = FUN_007b6730(pcVar4,uVar5);
    if (cVar2 != '\0') {
      cVar2 = FUN_0099bfc0(unaff_EDI);
      if (cVar2 == '\0') {
        FUN_00764030();
        local_4 = 0;
        FUN_00764830(unaff_EDI);
        local_4 = 0xffffffff;
        FUN_00763f60();
        ExceptionList = local_c;
        return 1;
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}
```
