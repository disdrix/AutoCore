# Function record: Material_ReleaseAndNullField0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f660` |
| **Canonical name** | `Material_ReleaseAndNullField0x18_Inferred` |
| **Ghidra name** | `FUN_0096f660` |
| **Address** | `0x0096f660`–`0x0096f681` (**34 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | gfx / material resource |
| **Completion status** | **Dual-reviewed 2026-07-29 W26-M** — accept |

Primary record: `docs/reconstruction/functions/aa_0096f660_FUN_0096f660.md`.

## Signature

```c
void __fastcall Material_ReleaseAndNullField0x18_Inferred(int* holder);
```

## Contract

```
obj = *holder
if obj:
  res = obj->field_0x18
  if res:
    if --res->refcount_at_plus4 == 0: res->vtbl[+8]()
  obj->field_0x18 = 0
```
