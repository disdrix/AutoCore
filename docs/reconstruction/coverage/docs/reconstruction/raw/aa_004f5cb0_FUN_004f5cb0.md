# Raw capture: FUN_004f5cb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5cb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f5cb0` |
| **Canonical name** | `FUN_004f5cb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004f5cb0(int param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int local_108;
  char local_104 [260];
  
  piVar4 = (int *)(param_1 + 0x28c);
  local_108 = 8;
  do {
    if (0 < *piVar4) {
      iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);
      uVar3 = 0;
      if (*(char *)(iVar1 + 0x716) != '\0') {
        do {
          piVar5 = (int *)(uVar3 * 0x110 + *(int *)(iVar1 + 0x720));
          if (*piVar5 == *piVar4) {
            _snprintf(local_104,0x104,"%S%s",(int)piVar5 + 10,&DAT_00a28904);
            FUN_004f5ae0((char)piVar5[2],local_104);
          }
          iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);
          bVar2 = (char)uVar3 + 1;
          uVar3 = (uint)bVar2;
        } while (bVar2 < *(byte *)(iVar1 + 0x716));
      }
    }
    piVar4 = piVar4 + 1;
    local_108 = local_108 + -1;
  } while (local_108 != 0);
  return;
}
```
