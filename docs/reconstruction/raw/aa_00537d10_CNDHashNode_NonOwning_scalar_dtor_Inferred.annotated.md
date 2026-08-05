# Annotated low-level: CNDHashNode_NonOwning_scalar_dtor_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_00537d10` |
| VA | `0x00537d10` |
| System | container / CNDHash |
| Date | 2026-07-29 |

## Machine-level notes

- MSVC scalar-deleting dtor; vtbl[0] of `PTR_FUN_009cf02c`.
- Does **not** free `this+0x08` (contrast `FUN_00537550` / `009cefec`).
- `ret 4`; returns `this`.
- Adjacent integrity walker starts at `0x00537d30` (int3 pad between).
- Insert family stamping this vtbl: `FUN_0053c460` (def hash) and siblings.

## Pseudocode (annotated)

```c
// void* __thiscall scalar_dtor(Node* this, uint8_t flags)
undefined4 * __thiscall FUN_00537d10(undefined4 *param_1, byte param_2)
{
  *param_1 = &PTR_FUN_009cf02c;           // restore/set vptr
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);            // MSVC scalar bit0
  }
  return param_1;
}
```

## Open questions

- Product RTTI / mangled name.
- Full multi-domain set of hashes using `009cf02c`.
