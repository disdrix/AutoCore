# Annotated low-level: FUN_0077bad0

| Field | Value |
|---|---|
| Stable ID | `aa_0077bad0` |
| VA | `0x0077bad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0077bad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint FUN_0077bad0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",
            "out != NULL",0xcc,"C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c"
           );
    raise(0x16);
  }
  if (param_3 == 0) {
    fprintf((FILE *)(_iob_exref + 0x40),"LTC_ARGCHK \'%s\' failure on line %d of file %s\n",
            "prng != NULL",0xcd,
            "C:\\vog\\1_code\\TorqueNetworkLibrary\\libtomcrypt\\prngs\\yarrow.c");
    raise(0x16);
  }
  FUN_00974320();
  iVar1 = FUN_00973d30(param_1,param_1,param_2);
  return ~-(uint)(iVar1 != 0) & param_2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
