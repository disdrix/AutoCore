# Function record: UI_InventoryWindow_OnItemClickDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008612b0` |
| **Canonical name** | `UI_InventoryWindow_OnItemClickDispatch_Inferred` |
| **Address** | `0x008612b0`–`0x00861676` exclusive (**966 B** / `0x3C6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Dual A/B complete (accept-with-gaps)** — gap-close 2026-08-05 |
| **Bit-for-bit / runtime / diff** | Open (static seal only; terminal false) |

## Alias

- Ghidra: `FUN_008612b0`
- Twin record: `aa_008612b0_FUN_008612b0.md`
- MEGA-125 parent hint: `UI_InventoryWindow_OnEquipCommand` — equip is one branch only; this unit owns full click/use/store/equip dispatch

## Purpose

Inventory-window UI virtual (vtable install `@0x00a64b00`) handling the selected inventory-item action:

1. **Early path** when `DAT_00d1b6d8+0xcd0 != 0` or `window+0x4b8 == 0` → `FUN_0085f220` (+ optional `DAT_00d1b1f8->vtbl[+0x3ac]`).
2. **RTTI** soft-cast selected child `CNDUIWindow` → **`CWndInventoryItem`**.
3. **Mode** `@*(window+0x56c)+4`:
   - **4** → `FUN_00861280` then close `vtbl[+0x33c](0)`.
   - **3** → require `DAT_00d1b644+0xf5` else return 0.
   - **1** (and 3 with flag) → resolve item and dispatch.
4. **Store UI** (`DAT_00d1bdfa`): reject type 4; store session gate; dualed **`Item_IsWantedByStore_Inferred`** → toast *“The store does not want that item.”* (chrome **`0x4e24`**) **or** C2S **`StoreTransactionRequest 0x2027`** size **`0x40`** via dualed **`Client_SendSectorPacket`**.
5. **Non-store:** soft-success template word `0x3f4==8`; dualed **`Client_SendUseObject_IfInteractable`**; special flag bit 19 → `FUN_0093a330`; use-by-coid → dualed **`Client_UseInventoryItemByCoid`**; types **8** / **`0x32`** → dualed **`Client_PromptSkillTargetSelect`**; else dualed equip leaf **`UI_InventoryWindow_TryEquipOrLockedToast_Inferred`**.
6. Fallthrough close `vtbl[+0x33c](0)` return 1.

## Signature (register)

```c
// ECX = inventory window this*
// stack: 2 opaque UI formals (unused in body); RET 0x8
// returns: AL 1=handled, 0=reject/blocked
uint8_t __fastcall UI_InventoryWindow_OnItemClickDispatch_Inferred(
    void* window /*ECX*/);
```

## Key offsets / constants

| Location | Role |
|---|---|
| `window+0x4b8` | selected UI child\* |
| `window+0x56c` | mode/state object\*; mode dword `@+4` (1/3/4) |
| window `vtbl[+0x33c]` | close/dismiss (arg 0) |
| inv-item `vtbl[+0x3ac]` | resolve backing item\* |
| `item+0xa8` | type-block\*; type `@+0x38`; template `@+0x3c` |
| `item+0x160` | TFID 16B |
| `item+0x17c` bit 19 | special path → `FUN_0093a330` |
| template `+0x3f2` bit7 | use-by-coid vs type-dispatch |
| template `+0x3f4` word==8 | soft success return 1 |
| opcode **`0x2027`** / size **`0x40`** | store sell C2S |
| string `@0x00a52924` | `"The store does not want that item."` |
| chrome **`0x4e24`** | toast id (shared family) |
| vtable slot **`0x00a64b00`** | sole install (DATA xref) |

## Callers / callees

| Direction | Addr | Name / role |
|---|---|---|
| Install ×1 | `0x00a64b00` | DATA vtable slot (no code CALL) |
| Callee | `0x004898a4` | `__RTDynamicCast` |
| Callee | `0x0085f220` | early non-item path |
| Callee | `0x00861280` | mode-4 leaf |
| Callee | `0x00861200` | dualed **TryEquipOrLockedToast** |
| Callee | `0x00513770` | dualed **Item_IsWantedByStore_Inferred** |
| Callee | `0x00807460` | dualed **Client_SendSectorPacket** |
| Callee | `0x00930d70` | dualed **Client_SendUseObject_IfInteractable** |
| Callee | `0x00941f50` | dualed **Client_UseInventoryItemByCoid** |
| Callee | `0x0093bac0` | dualed **Client_PromptSkillTargetSelect** |
| Callee | `0x0093a330` / `0x00524520` / `0x007fbb70` | residual special / interact / post-use |
| Callee | `0x007a69d0` / `0x007a6de0` / `0x007fdfb0` | locale + toast |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008612b0_FUN_008612b0.md`
- Annotated: `docs/reconstruction/raw/aa_008612b0_FUN_008612b0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/UI_InventoryWindow_OnItemClickDispatch_Inferred.cpp`
- Clean (FUN twin): `docs/reconstruction/reconstructed-exact/FUN_008612b0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_008612b0_UI_InventoryWindow_OnItemClickDispatch_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_008612b0_UI_InventoryWindow_OnItemClickDispatch_Inferred.md`
- Report: `docs/agents/task-dual-ab-008612b0-gap-close-report.md`

## Confidence

| Claim | Level |
|---|---|
| Body span 966 B + `RET 0x8` + pad `CC` | **Confirmed** |
| ECX=window this; AL return; no code callers; vtable `@0x00a64b00` | **Confirmed** |
| RTTI CNDUIWindow → CWndInventoryItem | **Confirmed** |
| Mode cascade 1/3/4 @ `*(+0x56c)+4` | **Confirmed** |
| Store reject string + chrome `0x4e24` + opcode `0x2027` size `0x40` | **Confirmed** |
| Child duals (equip leaf / IsWantedByStore / SendSector / UseObject / UseByCoid / PromptSkill) | **Confirmed** (named duals) |
| Product window class / mode English / close-vtbl English / stack formals | **Open** → `_Inferred` |
| Runtime / bit-exact / differential | **Open** |
