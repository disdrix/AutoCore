# Raw capture: FUN_007fce10

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fce10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fce10` |
| **Canonical name** | `FUN_007fce10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fce10(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int local_4;
  
  if (DAT_00d1b6d8 != 0) {
    iVar1 = *(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0x74 + DAT_00d1b6d8);
    cVar4 = '\0';
    local_4 = 0;
    piVar6 = (int *)(param_1 + 0x3220);
    do {
      iVar5 = 0;
      do {
        piVar6[5] = local_4 + iVar5;
        if (iVar1 == 0) {
LAB_007fcebe:
          iVar7 = *(int *)(DAT_00d1b6d8 + 0x930 + (uint)(byte)(cVar4 * '\n' + (char)iVar5) * 8);
          piVar6[2] = iVar7;
          piVar6[3] = iVar7 >> 0x1f;
          piVar6[4] = 0;
          if (iVar7 == -1) {
            *piVar6 = 0;
          }
          else if (iVar7 < -2000) {
            *piVar6 = 5;
          }
          else if (iVar7 < -1000) {
            *piVar6 = 4;
          }
          else {
            *piVar6 = (iVar7 < 0) + 2;
          }
        }
        else {
          uVar2 = *(uint *)(DAT_00d1b6d8 + 0x74c + (uint)(byte)(cVar4 * '\n' + (char)iVar5) * 4);
          iVar7 = *(int *)(*(int *)(*(int *)(iVar1 + 0x10) + (*(uint *)(iVar1 + 8) & uVar2) * 4) + 4
                          );
          if (iVar7 == 0) {
LAB_007fce9b:
            iVar7 = 0;
          }
          else {
            do {
              if (uVar2 == *(uint *)(iVar7 + 0x10)) {
                if (iVar7 == 0) goto LAB_007fce9b;
                iVar7 = *(int *)(iVar7 + 8);
                goto LAB_007fcea2;
              }
              iVar7 = *(int *)(iVar7 + 0xc);
            } while (iVar7 != 0);
            iVar7 = 0;
          }
LAB_007fcea2:
          if (iVar7 == 0) goto LAB_007fcebe;
          iVar3 = *(int *)(iVar7 + 0x5fc);
          piVar6[2] = iVar3;
          piVar6[3] = iVar3 >> 0x1f;
          piVar6[4] = iVar7;
          *piVar6 = 1;
        }
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 6;
      } while (iVar5 < 10);
      cVar4 = cVar4 + '\x01';
      local_4 = local_4 + 10;
    } while (local_4 < 100);
  }
  return;
}
```
