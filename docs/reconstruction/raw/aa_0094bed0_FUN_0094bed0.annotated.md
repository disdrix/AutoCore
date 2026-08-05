# Annotated low-level: Object_009d33c4_FactoryRegisterListed_Inferred (FUN_0094bed0)

| Field | Value |
|---|---|
| Stable ID | `aa_0094bed0` |
| VA | `0x0094bed0`–`0x0094bf8d` (**190 B** / `0xBE`) |
| System | object factory / host listing registration |
| Date | 2026-07-29 (W30-K dual seal) |
| Ghidra | `FUN_0094bed0` |

## Machine-level notes

- Prefer **bytes** when decompiler conflicts (stack COID args, `ret 8`, SEH restore).
- **EDI** is a required live input (host). Stack `(coid_lo, coid_hi)`.
- Allocation size **0x210** matches derived object family with ctor `Object_009d33c4_Ctor` (W29-H).
- Listing manager is `*(host + 0xd34)`; peer host field `+0xe04` is passed into two virtuals.
- Global `DAT_00af30f4` is first arg of `vtbl+8`.

## Sealed control flow

```
SEH install (LAB_009ab618)
obj = operator_new(0x210)
if (obj) obj = Object_009d33c4_Ctor(obj)   // FUN_00575440
// no null short-circuit after this
obj->vtbl[2](DAT_00af30f4, host->field_e04, 1)   // +8
Object_SetCoidIdentity(obj, coid_lo, coid_hi, 1) // FUN_00512160
obj->vtbl[+0x218/4](host->field_e04)
hr = Object_RegisterListed(host->list_d34, obj)  // FUN_004bc180
if (hr < 0) { obj->vtbl[0](1); return NULL; }   // scalar deleting dtor
return obj
// ret 8 both paths
```

## Pseudocode (bytes-corrected)

```c
// EDI = host; stack (coid_lo, coid_hi); ret 8
void *__fastcall Object_009d33c4_FactoryRegisterListed_Inferred(
    void *host /*EDI*/, uint32_t coid_lo, uint32_t coid_hi)
{
  void *obj = operator_new(0x210);
  if (obj != NULL)
    obj = Object_009d33c4_Ctor(obj); // thiscall

  void *field_e04 = *(void **)((char *)host + 0xe04);
  void *g = DAT_00af30f4;
  // vtbl+8
  (*(void (__thiscall **)(void *, void *, void *, int))(*(uint32_t *)obj + 8))
    (obj, g, field_e04, 1);

  Object_SetCoidIdentity(obj, coid_lo, coid_hi, 1);

  field_e04 = *(void **)((char *)host + 0xe04);
  (*(void (__thiscall **)(void *, void *))(*(uint32_t *)obj + 0x218))
    (obj, field_e04);

  int hr = Object_RegisterListed(*(void **)((char *)host + 0xd34), obj);
  if (hr < 0) {
    (*(void (__thiscall **)(void *, int))(*(uint32_t *)obj))(obj, 1);
    return NULL;
  }
  return obj;
}
```

## Related (not OWN)

| VA / symbol | Role |
|---|---|
| `0x00575440` | `Object_009d33c4_Ctor` (W29-H) |
| `0x00575c00` | scalar deleting dtor (vtbl[0]) |
| `0x00512160` | `Object_SetCoidIdentity` |
| `0x004bc180` | `Object_RegisterListed` (W19-E) |
| `0x008119c0` | sole caller |
| `DAT_00af30f4` | global first arg to vtbl+8 |

## Open

- Product/PDB type English for `009d33c4` family and host class.
- Semantic English for host `+0xe04` and `vtbl+8` / `+0x218`.
- OOM path (null new) is undefined in image.
- Runtime / bit-exact.
