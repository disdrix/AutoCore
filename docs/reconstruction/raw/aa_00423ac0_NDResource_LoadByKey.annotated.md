# Annotated low-level: NDResource_LoadByKey

| Field | Value |
|---|---|
| Stable ID | `aa_00423ac0` |
| VA | `0x00423ac0` |
| System | `nd-resource` |
| Date | `2026-07-29` (dual A/B seal) |

## Machine-level notes

- Source: raw capture for `aa_00423ac0` + live `read_memory` / decompile 2026-07-29.
- **ABI:** `__stdcall`, 4 stack formals, **`ret 0x10`**. Not thiscall.
- **Out-param:** `*param_1` always written (including null) before return.
- **Type token:** not a formal — `FUN_00423b10()` returns `&DAT_00d1f734` (singleton with vtable `PTR_FUN_00a95ae8`).
- **Cache:** first arg to LookupOrCreate is `*(NDResourceCache**)DAT_00d1f050` (global pointer, BSS at static dump).
- **Virtual:** `resource->vtable[1]` at **+0x04**; AL bool → EAX 0/1 via ESI accumulator.
- **Tristate:** −1 null / 0 init-fail / 1 init-ok.
- Caller `NDXml_LoadDocumentFromPath` passes `param_3=0`, `param_4=0` and tests **`rc < 0`** only.

## Pseudocode (annotated)

```c
/* NDResource_LoadByKey — aa_00423ac0 / 0x00423ac0

   Contract (machine-sealed):
     stdcall (pOut, key, p3, p4) → ret 0x10
     *pOut always assigned
     return -1 | 0 | 1

   Callees:
     FUN_00423b10            → type token (&DAT_00d1f734)
     NDResourceCache_LookupOrCreate(cache, key, type, p3, p4) @ 0x0075dba0
     (*resource->vtbl)[+4]   → init/load bool
*/

int /* tristate */ NDResource_LoadByKey(
    void **pOutResource,   /* param_1 — always written */
    void  *pKey,           /* param_2 — path/name object at NDXml site */
    void  *pMatchCtx,      /* param_3 — opaque; NDXml=0 */
    int    createPolicy)   /* param_4 — opaque; NDXml=0; cache compares to 1 */
{
  char initOk;
  void *typeToken;
  int  *resource;

  typeToken = FUN_00423b10();  /* ensure singleton type; return &DAT_00d1f734 */
  resource = (int *)NDResourceCache_LookupOrCreate(
      DAT_00d1f050, pKey, typeToken, pMatchCtx, createPolicy);
  *pOutResource = resource;
  if (resource == (int *)0x0) {
    return -1;                 /* 0xffffffff */
  }
  /* thiscall: ECX=resource, call [vtable+4] */
  initOk = (**(code **)(*resource + 4))();
  return (int)(initOk != '\0'); /* 0 or 1 */
}
```

## Open questions

- Exact types for `pKey` / `pMatchCtx` / `createPolicy` (see LookupOrCreate body).
- Symbolic name for vtbl+4 beyond init/load.
