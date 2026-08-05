# Raw capture: FUN_004cd3c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd3c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cd3c0` |
| **Canonical name** | `FUN_004cd3c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
FUN_004cd3c0(int param_1,int *param_2,int *param_3,undefined4 *param_4,int param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x7f) = 1;
  iVar1 = param_4[1];
  if (((-1 < iVar1) && (-1 < *param_3)) && (0 < param_5)) {
    FUN_007a4480(1,
                 "Dropped map object of COID:%I64i CBID:%I32i bytes:%li pVOGO:0x%08x hr:0x%08x pModPlace:0x%08x"
                 ,*param_4,iVar1,*param_3,param_5,param_6,param_7,param_8);
    iVar1 = (**(code **)(*param_2 + 4))(param_5,1);
    if (iVar1 != -1) {
      return 1;
    }
    FUN_007a4480(1,"Seek error, seeking %li bytes from current",param_5);
    return 0;
  }
  FUN_007a4480(1,
               "Hit a really bad object with an invalid COID:%I64i CBID:%I32i or bytes:%li pVOGO:0x%08x hr:0x%08x"
               ,*param_4,iVar1,*param_3,param_5,param_6,param_7);
  return 0;
}
```
