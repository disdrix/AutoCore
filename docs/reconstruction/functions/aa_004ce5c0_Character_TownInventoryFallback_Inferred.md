# Function record: Character_TownInventoryFallback_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce5c0` |
| **Canonical name** | `Character_TownInventoryFallback_Inferred` |
| **Ghidra name** | `FUN_004ce5c0` |
| **Address** | `0x004ce5c0`–`0x004ce5e3` |
| **Body size** | **36 B** / `0x24` (through final `RET 4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + offsets + callers sealed; flag/product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004ce5c0_Character_TownInventoryFallback_Inferred.md`, `reviews/B_aa_004ce5c0_Character_TownInventoryFallback_Inferred.md` |
| **Last reviewed** | `2026-08-05` (MEGA-118) |

## Alias

- `FUN_004ce5c0` (Ghidra)
- Partition hint: `Character_TownInventoryFallback`
- `Named_CalleeOf_Client_SendInventoryUnequip_004ce5c0` (**retired** incomplete parent-seed)

## Purpose

Leaf **mode-gate** allowing locker / town-inventory fallback:

```
if (!character) return false;
return modeHost[+0xf5] || modeHost[+0x7e];
```

Used when free-slot search fails (unequip / inventory-move) or when move mode is **3** — parents then use character **`+0xcbc`** (inventory type 3 / locker grid).

## Signature

```c
bool __thiscall Character_TownInventoryFallback_Inferred(int modeHost, int character); // ret 4
```

| Arg | Location | Evidence |
|---|---|---|
| modeHost | **ECX** | body `cmp [ecx+0xf5]` / `[ecx+0x7e]`; call sites load `DAT_00d1b644` or `client+0xe04` into ECX |
| character | stack | body `cmp [esp+4],0`; call sites push `DAT_00d1b6d8` / `client+0xe98` |
| return | AL bool | `xor al,al` / `mov al,1` / `setne al` |
| cleanup | **`RET 4`** | three `c2 04 00` |

## Algorithm

1. Null character → false.
2. If `modeHost+0xf5 != 0` → true.
3. Else return `modeHost+0x7e != 0`.

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers (3 sites)** | `Client_SendInventoryUnequip` `0x00862caa`; `FUN_008012f0` mode-3 `0x00801351`; free-slot miss `0x00801654` |

## Related

- Sibling `aa_004ce5f0` `Character_HostModeGateForObjectV210` — same flag pair after object `vtbl+0x210(0)`.
- Parent `aa_00862c00` `Client_SendInventoryUnequip` — free-slot fail → this gate → `char+0xcbc` retry.
- Layout: inv type **3** → `*(client+0xe98)+0xcbc` (locker).

## Confidence

| Claim | Level |
|---|---|
| thiscall + ret 4; leaf CF | **High** |
| ECX=modeHost; stack=character | **High** (bytes + 3 call sites) |
| Offsets `+0xf5` / `+0x7e` | **High** |
| Locker/`+0xcbc` fallback role | **High** (caller CF) |
| Product flag / “town” English / PDB | **Open** → `_Inferred` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004ce5c0_FUN_004ce5c0.md`
- Annotated: `docs/reconstruction/raw/aa_004ce5c0_FUN_004ce5c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Character_TownInventoryFallback_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_004ce5c0.cpp`
- Report: `docs/agents/task-dual-ab-004ce5c0-mega-118-report.md`
