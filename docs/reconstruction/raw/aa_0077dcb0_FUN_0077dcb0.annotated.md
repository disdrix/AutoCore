# Annotated low-level: FUN_0077dcb0

| Field | Value |
|---|---|
| Stable ID | `aa_0077dcb0` |
| VA | `0x0077dcb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0077dcb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0077dcb0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",
            "md != NULL",0xd1,
            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\hashes\\sha2\\sha256.c");
    raise(0x16);
  }
  param_1[10] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0x6a09e667;
  param_1[3] = 0xbb67ae85;
  param_1[4] = 0x3c6ef372;
  param_1[5] = 0xa54ff53a;
  param_1[6] = 0x510e527f;
  param_1[7] = 0x9b05688c;
  param_1[8] = 0x1f83d9ab;
  param_1[9] = 0x5be0cd19;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
