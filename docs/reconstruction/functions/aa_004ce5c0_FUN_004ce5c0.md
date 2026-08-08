# Function record: FUN_004ce5c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce5c0` |
| **Canonical name** | `FUN_004ce5c0` (Ghidra) |
| **Named form** | `Character_TownInventoryFallback_Inferred` |
| **Address** | `0x004ce5c0`–`0x004ce5e3` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **dual A/B sealed** — MEGA-118 **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004ce5c0_Character_TownInventoryFallback_Inferred.md`, `reviews/B_aa_004ce5c0_Character_TownInventoryFallback_Inferred.md` |
| **Last reviewed** | `2026-08-05` (MEGA-118) |

## Alias

- `FUN_004ce5c0` (Ghidra)
- `Character_TownInventoryFallback_Inferred` (structural; partition hint)
- `Named_CalleeOf_Client_SendInventoryUnequip_004ce5c0` (**retired** — incomplete parent-seed)

## Purpose

Leaf **mode-gate** for locker / town-inventory fallback:

1. Null character* → false.
2. Else true if `modeHost+0xf5`, else `modeHost+0x7e != 0`.

Parents use true to rebind free-slot / inventory-move work to character **`+0xcbc`** (inv type 3 / locker).

## Signature (sealed)

```c
bool __thiscall FUN_004ce5c0(int modeHost /*ECX*/, int character /*stack*/); // ret 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004ce5c0_FUN_004ce5c0.md` (+ MEGA-118 append)
- Annotated: `docs/reconstruction/raw/aa_004ce5c0_FUN_004ce5c0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Character_TownInventoryFallback_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004ce5c0.cpp`
- Named record: `docs/reconstruction/functions/aa_004ce5c0_Character_TownInventoryFallback_Inferred.md`
- Report: `docs/agents/task-dual-ab-004ce5c0-mega-118-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none — **leaf** |
| **Callers** | `Client_SendInventoryUnequip` `0x00862caa`; `FUN_008012f0` `0x00801351` + `0x00801654` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| thiscall + ret 4; ECX=modeHost; stack=character | **High** |
| Flags `+0xf5` / `+0x7e` | **High** (offsets); English **Open** |
| Role: locker/`+0xcbc` fallback gate | **High** (caller CF) |
| Product/PDB symbol / “town” English | **Open** → `_Inferred` |
