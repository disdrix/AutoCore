# Annotated low-level: Character_HostModeGateForObjectV210 (FUN_004ce5f0)

| Field | Value |
|---|---|
| Stable ID | `aa_004ce5f0` |
| VA | `0x004ce5f0`–`0x004ce632` |
| Canonical | `Character_HostModeGateForObjectV210` |
| System | inventory-transfer / equip / hardpoint gates |
| Date | 2026-07-23 scaffold; 2026-07-29 W19-F dual seal |

## Machine-level notes

- **Leaf gate** — no external CALL targets; one **indirect** vcall on the object.
- **ABI sealed:** `__thiscall` ECX=host, stack object*, **`ret 4`** (three exits).
- **MI this-adjust** on object matches common CVOG pattern:  
  `adj = *( *(obj+4) + 4 ) + obj + 4` then `(*adj->vtbl)[0x210/4](adj, 0)`.
- **Host flags** (product English **open**):
  - `host+0xf5` (u8): if set → allow when vcall non-null.
  - `host+0x7e` (u8): else allow iff set.
- **Call-site reuse:** equip helpers often call with ECX=host without pushing object; MSVC leaves caller's stack arg0 (item/object) at the callee's `[esp+4]` — matches `thiscall`+one stack arg and equip type-0xe path.
- **Roles via xrefs (not body):**
  - Vehicle equip gate inside `Character_TryEquipItem` type **0xe** — false → status **1**.
  - Type **0x10** equip helper `FUN_004f6890` — same false→**1**.
  - `Client_SendInventoryDrop_Hardpoint` (two sites).
  - Confirm/customize UI path `FUN_00941b20`.

## Pseudocode (annotated)

```c
// Structural gate: object must expose non-null vfunc+0x210(0), and host must have
// mode flag +0xf5 or +0x7e. Product names for flags / vfunc open.
bool __thiscall Character_HostModeGateForObjectV210(int host, int object)
{
  if (object == 0) return false;
  int adj = *(int *)(*(int *)(*(int *)(object + 4) + 4) + 4 + object);
  int r = (*(int (__thiscall **)(int, int))(*(int *)adj + 0x210))(adj, 0);
  if (r == 0) return false;
  if (*(char *)(host + 0xf5) != 0) return true;
  return *(char *)(host + 0x7e) != 0;
}
```

## Open questions

- Product English for host `+0xf5` / `+0x7e` on this object class (not assumed equal to world/continent same offsets).
- Product name / return type of object **vtbl+0x210** with arg **0** (distinct from host vcall shapes that pass `(0,1)` elsewhere).
- PDB symbol.
