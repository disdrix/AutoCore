# Annotated low-level: NDXml_GetLoaderSingleton

| Field | Value |
|---|---|
| Stable ID | `aa_007b6a20` |
| VA | `0x007b6a20`–`0x007b6a82` |
| System | `client-xml` |
| Date | 2026-07-29 (W17-I) |

## Machine-level notes

- **Meyers singleton**: first call sets BSS once-flag `DAT_00d20c48\|=1`, constructs static object at `DAT_00d20c38`, registers `atexit(LAB_009c3040)`, returns `&DAT_00d20c38`.
- **No stack args** — plain `RET`; return in **EAX**.
- **SEH prolog** present only for the init path that calls `_atexit` (MSVC static-init pattern).
- **Vtable** `PTR_FUN_00a95b88`: slot0 = scalar deleting dtor `FUN_004239a0` → body `FUN_007b65d0`.
- **Consumers** pass return value as `this` into `NDXml_LoadDocumentFromPath` (`0x007b6c70`) and many path/image/UI loaders.
- Prefer decompile CF over inventing product field names for `+0x08/+0x0c`.

## Pseudocode (annotated)

```c
// Canonical: void *NDXml_GetLoaderSingleton(void);
// Returns process-static loader object* at DAT_00d20c38.

undefined * FUN_007b6a20(void)
{
  // SEH frame (local_c / puStack_8 / uStack_4)
  if ((DAT_00d20c48 & 1) == 0) {           // once guard (adjacent BSS)
    DAT_00d20c48 |= 1;
    *(int *)(0x00d20c3c) = 1;              // object+0x04 flags: search-path bit
    *(void **)(0x00d20c38) = &PTR_FUN_00a95b88; // object+0x00 vtable
    *(int *)(0x00d20c40) = 0;              // object+0x08
    *(int *)(0x00d20c44) = 0;              // object+0x0c
    _atexit(LAB_009c3040);                 // process-exit dtor
  }
  return &DAT_00d20c38;                    // always
}
```

## Control flow

```
SEH prolog
if (once_flag & 1) == 0:
  once_flag |= 1
  obj.flags(+4) = 1
  obj.vtbl(+0)  = PTR_FUN_00a95b88
  obj+8 = 0; obj+c = 0
  atexit(LAB_009c3040)
restore ExceptionList
return &obj
```

## Open questions

1. Full product class name for the singleton (NDXml loader vs broader ND resource host).
2. Exact IDL / meaning of vtable slots beyond slot0 dtor.
3. Contents of search-path table `DAT_00d1e574` (owned by load path, not this unit).
4. Whether any caller depends on pre-init zeroed BSS before first call (unlikely — all go through getter).
