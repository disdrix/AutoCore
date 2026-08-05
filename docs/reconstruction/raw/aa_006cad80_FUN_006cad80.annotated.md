# Annotated low-level: WorldCast_SetupCollectorAndDispatch_Inferred (FUN_006cad80)

| Field | Value |
|---|---|
| Stable ID | `aa_006cad80` |
| VA | `0x006cad80` |
| Body | `0x006cad80`–`0x006cae18` (excl. `0x006cae19`) |
| Canonical name | `WorldCast_SetupCollectorAndDispatch_Inferred` |
| System | world / map collision cast |
| Date | 2026-07-29 (W19-M dual) |

## Machine-level notes

- Prefer `read_memory` when decompiler naming is vague; CF matches live decompile.
- `__thiscall` + **`ret 0x14`** sealed by epilogue bytes.
- `param_3 + 8` (as `undefined4*`) is **byte offset +0x20** on the ray (`mov dl,[eax+0x20]`).
- `param_3 + 4` is **byte offset +0x10** (pointer into ray mid-section).
- Vfunc is **thiscall on world**: ECX=world; stack `(packet*, collector*, 0)`.

## Collector writes (this = param_1)

| Offset | Value |
|---|---|
| `+0x04` | `ray*` (`param_3`) |
| `+0x08` | `filter ? filter+0x14 : 0` |
| `+0x0c` | `result*` (`param_6`) |
| `+0x34` | if `*(char*)(ray+0x20) != 0` and filter non-null: `filter+0x10`; else `0` |

## Ray packet (stack locals)

| Field (decomp) | Source |
|---|---|
| `local_30..local_24` | copy of `ray[0..3]` (16 bytes) |
| `local_20` | constant `1` |
| `local_1c` | `ray + 0x10` (pointer) |
| `local_18` | constant `0x10` |
| `local_14` | `param_5` (extra; wrapper passes `0`) |

## Dispatch

```
world = param_2;
packet = &local_30;
collector = param_1;
(*world->vtbl[0x30/4])(world /*ECX*/, packet, collector, 0);
```

## Annotated CF

```c
// void __thiscall WorldCast_SetupCollectorAndDispatch(
//     Collector* this, World* world, Ray* ray, void* filter,
//     uint32_t extra, void* result);
// RET 0x14
void __thiscall FUN_006cad80(
    int collector, int *world, undefined4 *ray, int filter,
    undefined4 extra, undefined4 result)
{
  int shapeOfs;
  // stack packet locals...
  *(undefined4 **)(collector + 4) = ray;
  *(undefined4 *)(collector + 0xc) = result;
  *(int *)(collector + 8) = (filter == 0) ? 0 : (filter + 0x14);
  if (*(char *)((char *)ray + 0x20) == '\0' || filter == 0) {
    *(undefined4 *)(collector + 0x34) = 0;
  } else {
    *(int *)(collector + 0x34) = filter + 0x10;
  }
  // pack ray[0..3], flags 1 / 0x10, ptr ray+0x10, extra
  (**(code **)(*world + 0x30))(/*packet*/, collector, 0); // ECX=world
  return; // ret 0x14
}
```

## Open questions

- Product names for Collector / World cast vfunc / ray POD.
- Full hit-result layout written by vtbl+0x30 (owned by world cast impl, not this VA).
- Whether any other caller exists beyond `MapCollisionCtx_CastRay` (xrefs show 1 CODE).
