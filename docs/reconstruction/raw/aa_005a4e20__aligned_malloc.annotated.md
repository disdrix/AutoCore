# Annotated low-level: _aligned_malloc

| Field | Value |
|---|---|
| Stable ID | `aa_005a4e20` |
| VA | `0x005a4e20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005a4e20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void * __cdecl _aligned_malloc(size_t _Size,size_t _Alignment)



{

  void *pvVar1;

  

                    /* WARNING: Could not recover jumptable at 0x005a4e20. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  pvVar1 = _aligned_malloc(_Size,_Alignment);

  return pvVar1;

}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
