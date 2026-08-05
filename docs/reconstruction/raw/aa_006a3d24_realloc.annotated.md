# Annotated low-level: realloc

| Field | Value |
|---|---|
| Stable ID | `aa_006a3d24` |
| VA | `0x006a3d24` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a3d24`.
- CRT/import thunk or standard library surface for this address.

## Pseudocode (annotated copy of raw)

```c
void * __cdecl realloc(void *_Memory,size_t _NewSize)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = realloc(_Memory,_NewSize);
  return pvVar1;
}
```
