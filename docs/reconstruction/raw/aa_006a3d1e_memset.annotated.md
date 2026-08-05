# Annotated low-level: memset

| Field | Value |
|---|---|
| Stable ID | `aa_006a3d1e` |
| VA | `0x006a3d1e` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a3d1e`.
- CRT/import thunk or standard library surface for this address.

## Pseudocode (annotated copy of raw)

```c
void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x006a3d1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}
```
