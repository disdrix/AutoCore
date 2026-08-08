# Function record: FUN_008e5ce0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5ce0` |
| **Canonical name** | `FUN_008e5ce0` |
| **Preferred human name** | `Client_UI_CraftHost_BindObjectByTfid_Inferred` |
| **Address** | `0x008e5ce0`–`0x008e5df3` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual sealed (WQ8R-H)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias

- `Client_UI_CraftHost_BindObjectByTfid_Inferred`
- **Reject:** `Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e5ce0`

## Purpose

Resolve TFID → item (cargo/locker, else equip slots) and bind into craft host via `FUN_008e5990`. Invalid TFID clears selection.

## Signature (sealed)

```c
// stdcall RET 0x0C
void __stdcall Client_UI_CraftHost_BindObjectByTfid_Inferred(
    void* host, uint32_t coidLo, uint32_t coidHi);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008e5ce0_FUN_008e5ce0.md`
- Annotated: `docs/reconstruction/raw/aa_008e5ce0_FUN_008e5ce0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_UI_CraftHost_BindObjectByTfid_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_008e5ce0.cpp`
- Named record: `docs/reconstruction/functions/aa_008e5ce0_Client_UI_CraftHost_BindObjectByTfid_Inferred.md`
- Dual A/B: `reviews/A_aa_008e5ce0_*` / `reviews/B_aa_008e5ce0_*`

## Callers / callees

- Callers: `FUN_008e5e00` @ `008e6345`; site `008e82ef`
- Callees: `FUN_008e5990`, `InventoryGrid_FindItemByCoid`, `FUN_00522000`, `CVOGReaction_ResolveObjectTarget`

## Confidence

| Claim | Level |
|---|---|
| stdcall 3-arg ABI + invalid clear | High |
| FindItem + broken filter + equip fallback | High |
| Host thiscall into FUN_008e5990 | High |
| Product name of host class | Open (inferred craft host) |
| FUN_00522000 full contract | Open (unowned) |
