# Raw capture: FUN_0077fca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077fca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0077fca0` |
| **Canonical name** | `FUN_0077fca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0077fca0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_20 [8];
  
  if (param_1 == 0) {
    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",
            "md != NULL",0x43,
            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\hashes\\sha2\\sha224.c");
    raise(0x16);
  }
  if (param_2 == (undefined4 *)0x0) {
    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",
            "out != NULL",0x44,
            "c:\\vog\\1_code\\torquenetworklibrary\\libtomcrypt\\hashes\\sha2\\sha224.c");
    raise(0x16);
  }
  FUN_0077f960(param_1,local_20);
  puVar2 = local_20;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return;
}
```
