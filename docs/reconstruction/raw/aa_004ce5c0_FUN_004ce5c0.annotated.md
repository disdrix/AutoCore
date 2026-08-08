# Annotated low-level: Character_TownInventoryFallback_Inferred (FUN_004ce5c0)

| Field | Value |
|---|---|
| Stable ID | `aa_004ce5c0` |
| VA | `0x004ce5c0`–`0x004ce5e3` (Ghidra body end) |
| Canonical name | `Character_TownInventoryFallback_Inferred` |
| Ghidra name | `FUN_004ce5c0` |
| System | inventory-transfer |
| Date | 2026-08-05 (MEGA-118 dual refresh) |
| Prior scaffold | 2026-07-23 unknown-system plate |

---

## Machine-level notes

- Live decompile **≡** raw CF. Prefer assembly for ABI: **ECX = mode host**, stack = **character\***, **`RET 4`**.
- Leaf predicate — no external CALLs, no stores.
- Flags on **mode host** (`DAT_00d1b644` or `client+0xe04`), **not** on the character stack arg (character is null-gate only).
- True path in parents rebinds free-slot / mode-3 work to character **`+0xcbc`** (inventory type **3** / locker grid).
- Sibling `0x004ce5f0` `Character_HostModeGateForObjectV210` reuses the same `+0xf5` / `+0x7e` pair after an object vcall.
- Retire parent-seed `Named_CalleeOf_Client_SendInventoryUnequip_004ce5c0` (incomplete; multi-caller).

## Pseudocode (annotated)

```c
// ABI: __thiscall — ECX=modeHost, stack character*; ret 4; AL bool
bool __thiscall Character_TownInventoryFallback_Inferred(int modeHost, int character)
{
  // null character → deny locker/town fallback
  if (character == 0) {
    return false;
  }
  // primary mode flag (product English open; same offset family as host-mode gate)
  if (*(char *)(modeHost + 0xf5) != '\0') {
    return true;
  }
  // secondary mode flag
  return *(char *)(modeHost + 0x7e) != '\0';
}
```

## Call-site ABI (sealed)

| Site | ECX | stack | After true |
|---|---|---|---|
| `Client_SendInventoryUnequip` `00862caa` | `DAT_00d1b644` | `DAT_00d1b6d8` | `char+0xcbc` free-slot retry |
| `FUN_008012f0` mode-3 `00801351` | `client+0xe04` | `client+0xe98` (char) | locker grid `char+0xcbc` |
| `FUN_008012f0` free-slot miss `00801654` | `client+0xe04` | `client+0xe98` | free-slot retry → mode **3** |

## Open questions

- Product/PDB symbol.
- English labels for `+0xf5` / `+0x7e` and for `DAT_00d1b644` vs `client+0xe04`.
- Product name “town” vs layout “locker” for `+0xcbc`.
- Runtime / bit-exact / differential.
