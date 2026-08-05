# Raw capture: FUN_004ecf70

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ecf70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ecf70` |
| **Canonical name** | `FUN_004ecf70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall
FUN_004ecf70(undefined4 *param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  float fVar3;
  
  fVar3 = g_flOne;
  *param_1 = &PTR_FUN_009ccf24;
  *(undefined1 *)(param_1 + 10) = 0;
  *(undefined1 *)((int)param_1 + 0x29) = 0;
  *(undefined1 *)((int)param_1 + 0x2a) = 1;
  *(undefined1 *)((int)param_1 + 0x2b) = 1;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[0xc] = 0;
  param_1[0xd] = param_2;
  param_1[0xf] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0xe] = param_3;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0x80000000;
  param_1[0x24] = 0;
  param_1[0x26] = 0;
  param_1[0x25] = 0;
  param_1[0x27] = 0;
  param_1[0x3c] = 0;
  param_1[0x2f] = 0;
  param_1[0x2e] = 0;
  param_1[0x2d] = 0;
  param_1[0x2c] = 0;
  param_1[0x33] = 0;
  param_1[0x32] = 0;
  param_1[0x31] = 0;
  param_1[0x30] = 0;
  param_1[0x37] = 0;
  param_1[0x36] = 0;
  param_1[0x35] = 0;
  param_1[0x34] = 0;
  param_1[0x2c] = fVar3;
  param_1[0x31] = fVar3;
  param_1[0x36] = fVar3;
  param_1[0x3b] = 0;
  param_1[0x3a] = 0;
  param_1[0x39] = 0;
  param_1[0x38] = 0;
  param_1[0x40] = DAT_009ccc18;
  param_1[0x41] = DAT_009ccc1c;
  param_1[0x42] = DAT_009ccc20;
  param_1[0x43] = DAT_009ccc24;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x73] = &PTR_FUN_009ccc2c;
  param_1[0x7b] = 0;
  param_1[0x7a] = 0;
  param_1[0x7c] = 0;
  *(undefined1 *)(param_1 + 0x7d) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  param_1[0x73] = &PTR_FUN_009cccfc;
  iVar2 = 0x40 - (int)param_4;
  do {
    cVar1 = *param_4;
    param_4[(int)param_1 + iVar2] = cVar1;
    param_4 = param_4 + 1;
  } while (cVar1 != '\0');
  *(undefined1 *)(param_1 + 0x62) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return param_1;
}
```
