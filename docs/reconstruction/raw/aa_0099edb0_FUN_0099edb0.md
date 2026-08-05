# Raw capture: FUN_0099edb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099edb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0099edb0` |
| **Canonical name** | `FUN_0099edb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0099edb0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  
  if (unaff_EBX == (int *)0x0) {
    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",
            "N != NULL",0x18,
            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\mpi\\is_prime.c");
    raise(0x16);
  }
  if (param_1 == 0) {
    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",
            "result != NULL",0x19,
            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\misc\\mpi\\is_prime.c");
    raise(0x16);
  }
  if (*unaff_EBX != 0) {
    for (uVar1 = *(uint *)(unaff_EBX[3] + -4 + *unaff_EBX * 4); uVar1 != 0; uVar1 = uVar1 >> 1) {
    }
  }
  FUN_00770330(param_1);
  iVar2 = FUN_007775d0();
  if (iVar2 != 0) {
    iVar3 = 0;
    do {
      if (iVar2 == (&DAT_00a240d0)[iVar3 * 2]) {
        return *(undefined4 *)(&UNK_00a240d4 + iVar3 * 8);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    return 1;
  }
  return 0;
}
```
