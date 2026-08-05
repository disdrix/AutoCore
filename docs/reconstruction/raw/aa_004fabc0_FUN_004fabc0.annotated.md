# Annotated low-level: FUN_004fabc0 / Character_TryEquipItem

| Field | Value |
|---|---|
| Stable ID | `aa_004fabc0` |
| VA | `0x004fabc0` |
| Canonical (dual) | `Character_TryEquipItem` |
| System | inventory-transfer / equip |
| Date | 2026-07-29 (W17-E dual; supersedes 2026-07-23 scaffold notes) |

## Machine-level notes

- Source: raw capture + live `decompile_function` / `read_memory` (no `disassemble_bytes`).
- **ECX** = character / equip host (`this`); stack **`item*`**, optional **`out*`**; **`ret 8`**.
- Always (when item non-null): **`item+0x17c |= 0x10`** then **`FUN_00512670`** dirty (`| 0x20000` self + `+0xac` chain).
- Broken gate: **`(item+0x17c >> 19) & 1`** → return code **9** (sealed `ItemFlag_Broken` / peer duals).
- Session block: host interior `+0xa8` object, byte **`+0xf6`** nonzero → return **0xf**.
- Precheck: host vtbl path `+0x210(0,1)` then `FUN_00514390` — fail → return **6**.
- Type switch on **`*(item[0x2a] + 0x38)`** (clonebase type id) via MSVC jump table at `0x004fad58` / index `0x004fad78`.
- Named parent seed: `Client_ConfirmEquipOrCustomizeItem` `0x00941b20`; also UI inventory click / hardpoint drop / other equip UI.

## Pseudocode (annotated)

```c
// ECX = Character* host
// [esp+4] = Item* item
// [esp+8] = optional out dword* (cleared to 0)
// ret 8
uint __thiscall Character_TryEquipItem(int host, int *item, uint *outOpt)
{
  if (item == NULL) return 8;
  if (outOpt != NULL) *outOpt = 0;

  // sticky equip-attempt flag at item flags dword
  item[0x5f] /* +0x17c */ |= 0x10;
  Object_PropagateDirtyBit0x20000(item);   // FUN_00512670

  if (((uint)item[0x5f] >> 19) & 1)        // ItemFlag_Broken
    return 9;

  int sessionish = *(int *)(*(int *)(*(int *)(host + 4) + 4) + 0xa8 + host);
  if (sessionish != 0 && *(char *)(sessionish + 0xf6) != 0)
    return 0xf;

  // equip precheck (host virtual + helper)
  void *ctx = host_vtbl_plus_0x210(host, 0, 1);
  if (!FUN_00514390(ctx, /*0*/))
    return 6;

  switch (*(int *)(item[0x2a] + 0x38)) {   // clonebase type
  case 6:
    return FUN_004f6940(dynamic_cast_to_simple_gfx(item), outOpt);
  case 8:
  case 0x32:
    return 0xc;
  case 10:
    return FUN_004f6840(item->vtbl[+0x1f4](outOpt), outOpt);
  case 0xc:
    return FUN_004f65e0(item->vtbl[+0x1e0](outOpt), outOpt);
  case 0xe: // vehicle
    if (!FUN_004ce5f0(host)) return 1;
    return FUN_004f6560() ? 0xe : 0;
  case 0x10:
    return FUN_004f6890(item->vtbl[+0x1f0](outOpt), outOpt);
  case 0x1c:
    return FUN_004f67e0(item->vtbl[+0x1f8](outOpt), outOpt);
  default:
    return 8;
  }
}
```

## Status codes (this unit)

| Code | When |
|-----:|------|
| **0** | Vehicle path: `FUN_004f6560` returned 0 |
| **1** | Vehicle path: `FUN_004ce5f0(host)` failed |
| **6** | Precheck `FUN_00514390` failed |
| **8** | Null item / unsupported clonebase type |
| **9** | **ItemFlag_Broken** set |
| **0xc** | Clonebase type **8** or **0x32** |
| **0xe** | Vehicle path success (`FUN_004f6560` nonzero) |
| **0xf** | Host session object `+0xf6` nonzero |
| other | Passthrough from type-specific equip helpers |

## Byte anchors

| Addr / pattern | Bytes | Meaning |
|----------------|-------|---------|
| entry | `56 8b 74 24 08` | `push esi; mov esi,[esp+8]` item |
| null item | `b8 08 00 00 00 … c2 08 00` | return 8, ret 8 |
| flag OR | `83 8e 7c 01 00 00 10` | `or [esi+0x17c], 0x10` |
| dirty call | `e8 7d 7a 01 00` @ `004FABEE` | → `00512670` |
| Broken | `c1 e8 13` `a8 01` | bit 19 |
| return 9 | `b8 09 00 00 00` | equip reject Broken |
| tables | `004fad58` / `004fad78` | switch jump + index |

## Open questions

- Product English for item flag **`0x10`** at `+0x17c` (equip-dirty / pending-apply — not Broken).
- Product names for status codes **6 / 0xc / 0xe / 0xf** and session byte `+0xf6`.
- Exact host type (Character vs Client wrapper) — MI `+4/+4` walk is shared pattern.
- Full semantics of each type-specific equip helper (owned by those VAs, not this dual).
- Original PDB symbol.
