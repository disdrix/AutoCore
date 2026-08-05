# Annotated low-level: Host34_NestedHash0xC_Singleton_Ctor_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0096eec0` |
| VA | `0x0096eec0`–`0x0096ef6a` exclusive (**170 B**) |
| Canonical name | `Host34_NestedHash0xC_Singleton_Ctor_Inferred` |
| Ghidra name | `FUN_0096eec0` |
| System | NestedHash0xC host + singleton + type-token once-init |
| Date | 2026-07-29 (W35-S dual seal) |

## Machine-level notes

- **ABI:** stack `self*`; `RET 4`; returns self in EAX. **Not** ECX-thiscall.
- **SEH:** `LAB_009b1316`.
- Prefer **bytes** over decompiler for map-register tail (`FUN_0043bd40` tree/key dropped in decompile).
- Nested shell is sealed W34-F `NestedHash_Ctor_Sentinel0xC_Inferred` @ `0x0043fdf0`.
- Reject scaffold `Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_Driver_Version_*`.

## Layout (object size **0x34**)

| Offset | Init | Notes |
|---|---|---|
| `+0x00`…`+0x27` | `FUN_0043fdf0(self)` | NestedHash sentinel-0x0C shell (span 0x28) |
| `+0x28` | `1` (byte) | host flag |
| `+0x2c` | `0` | dword |
| `+0x30` | `0` | dword |

## Side effects

| Site | Action |
|---|---|
| `DAT_00d1f04c` | `= self` (singleton) |
| `DAT_00d1f7e8` bit0 | once-init guard for static type object |
| `DAT_00d1f7e4` | `= &PTR_FUN_00a9ef54` then atexit `LAB_009c3370` |
| `*DAT_00d1f050 + 0x58` map | insert key `0x00d1f7e4` → value `{LAB_0096ed30, 0}` via `FUN_0043bd40` |

## Pseudocode (annotated; bytes-corrected map path)

```c
// stack(self*); RET 4; returns self
Host34* Host34_NestedHash0xC_Singleton_Ctor_Inferred(Host34* self)
{
  // SEH LAB_009b1316
  DAT_00d1f04c = self;
  NestedHash_Ctor_Sentinel0xC_Inferred(self);   // FUN_0043fdf0
  self->flag28 = 1;
  self->field2c = 0;
  self->field30 = 0;

  if ((DAT_00d1f7e8 & 1) == 0) {
    DAT_00d1f7e8 |= 1;
    DAT_00d1f7e4 = &PTR_FUN_00a9ef54;            // static type-token object
    _atexit(LAB_009c3370);                       // dtor thunk for DAT_00d1f7e4
  }

  // bytes: EBP = *DAT_00d1f050 (NDResourceCache*); ECX = EBP+0x58
  // key on stack = 0x00d1f7e4; value slot from FUN_0043bd40
  uint32_t* slot = (uint32_t*)FUN_0043bd40(/*ECX=cache+0x58, EAX=&key*/);
  slot[0] = (uint32_t)LAB_0096ed30;
  slot[1] = 0;

  return self;
}
```

## Open gaps

- Product English for host / map value type.
- Full contract of unowned `FUN_0043bd40` tree node layout.
- `LAB_0096ed30` body (not a defined function symbol).
- Flag/`field2c`/`field30` runtime meaning.
- Runtime / bit-exact / differential.
