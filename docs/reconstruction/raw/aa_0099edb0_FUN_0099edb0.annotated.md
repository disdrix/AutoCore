# Annotated low-level: FUN_0099edb0

| Field | Value |
|---|---|
| Stable ID | `aa_0099edb0` |
| VA | `0x0099edb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0099edb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
