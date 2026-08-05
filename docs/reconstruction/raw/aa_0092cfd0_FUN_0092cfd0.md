# Raw capture: FUN_0092cfd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092cfd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092cfd0` |
| **Canonical name** | `FUN_0092cfd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0092cfd0(int param_1,ushort param_2,byte param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  if ((0xeff < param_2) && (param_2 < 0xf08)) {
    uVar4 = 0;
    do {
      switch(uVar4) {
      case 0:
        iVar3 = 5;
        break;
      case 1:
        iVar3 = 6;
        break;
      case 2:
        iVar3 = 0x78;
        break;
      case 3:
        iVar3 = 0x14;
        break;
      default:
        iVar3 = 0;
        if (uVar4 < 4) break;
        iVar1 = 0;
        goto LAB_0092d057;
      }
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch(uVar4) {
      case 0:
        iVar1 = param_1 + 0x1172;
        break;
      case 1:
        iVar1 = param_1 + 0x1276;
        break;
      case 2:
        iVar1 = param_1 + 0x13ae;
        break;
      default:
        iVar1 = param_1 + 0x2c0e;
      }
LAB_0092d057:
      if (iVar3 != 0) {
        pcVar2 = (char *)(iVar1 + 0x32);
        do {
          if (*(ushort *)(pcVar2 + -0x32) == param_2) {
            bVar5 = (-(pcVar2[-4] != '\0') & param_3 & 0x80) != 0;
            pcVar2[-1] = bVar5;
            if (((*pcVar2 == '\0') && (!bVar5)) || (pcVar2[-0x2e] != '\0')) {
              if (((*pcVar2 != '\0') || (bVar5)) || (pcVar2[-0x2e] == '\0')) goto LAB_0092d0ad;
              pcVar2[-0x2e] = '\0';
            }
            else {
              pcVar2[-0x2e] = '\x01';
            }
            pcVar2[-0x2d] = '\x01';
          }
LAB_0092d0ad:
          if (*(ushort *)(pcVar2 + -0x30) == param_2) {
            bVar5 = (-(pcVar2[-3] != '\0') & param_3 & 0x80) != 0;
            *pcVar2 = bVar5;
            if ((bVar5) || (pcVar2[-1] != '\0')) {
              if (pcVar2[-0x2e] != '\0') {
                if ((bVar5) || (pcVar2[-1] != '\0')) goto LAB_0092d0f5;
                goto LAB_0092d0e9;
              }
              pcVar2[-0x2e] = '\x01';
            }
            else {
LAB_0092d0e9:
              if (pcVar2[-0x2e] == '\0') goto LAB_0092d0f5;
              pcVar2[-0x2e] = '\0';
            }
            pcVar2[-0x2d] = '\x01';
          }
LAB_0092d0f5:
          pcVar2 = pcVar2 + 0x34;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 4);
  }
  return;
}
```
