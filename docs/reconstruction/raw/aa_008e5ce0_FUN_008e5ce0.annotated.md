# Annotated low-level: FUN_008e5ce0 → Client_UI_CraftHost_BindObjectByTfid_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008e5ce0` |
| VA | `0x008e5ce0`–`0x008e5df3` |
| System | `inventory-transfer` |
| Date | 2026-08-04 (WQ8R-H dual seal; prior scaffold 2026-07-23) |
| Tools | decompile + force_decompile + read_memory + assembly context; **no** disassemble_bytes |

## ABI (bytes + callers)

| Slot | Role | Evidence |
|------|------|----------|
| stack0 | **Craft/UI host\*** (`this` for `FUN_008e5990`) | Invalid path: `mov ecx,[esp+0xC]; push 0; call FUN_008e5990`; success: `mov ecx,[esp+0x14]; push eax; call` |
| stack1 | **coidLo** | Prologue `mov edi,[esp+0x10]` after dual push |
| stack2 | **coidHi** | Prologue `mov esi,[esp+0x10]` first load |
| return | void | `RET 0x0C` (**stdcall**, 12 B) |

Decompiler `param_1` unused is wrong — it is host for thiscall into bind. **Bytes win**.

## Semantics

```
if ((coidLo & coidHi) == 0xFFFFFFFF) {
  CraftHost_BindObject(host, NULL);   // clear selection
  return;
}
if (localChar == NULL) return;

// Prefer cargo/vehicle grid lookup when available:
obj = NULL;
if (char has vehicle cargo grid OR (locker present && flag DAT_00d1b644+0xf5)) {
  // first attempt via InventoryGrid_FindItemByCoid when vehicle path valid
  obj = FindItemByCoid(coidLo, coidHi);  // FUN_00571010
  // re-find if first path left broken-or-null under locker flag
}
// Broken filter: (obj+0x17c >> 19) & 1  — broken items skip to equip scan
if (obj == NULL || broken(obj)) {
  n = EquipSlotCount(char);            // FUN_00522000
  for i in [0, n):
    slot = char+0x5a0 + i*8;           // TFID pair array
    if slot valid && slot == (lo,hi):
      obj = CVOGReaction_ResolveObjectTarget(1, lo, hi);
      break;
  if not found: return;
}
if (obj != NULL)
  CraftHost_BindObject(host, obj);     // FUN_008e5990 thiscall
```

## Callees

| VA / symbol | Role |
|-------------|------|
| `FUN_008e5990` | Bind/clear craft host selection (name UI, recipe slots, TFID on subwidget) |
| `InventoryGrid_FindItemByCoid` (`0x00571010`) | Cargo/locker TFID→item |
| `FUN_00522000` | Equip slot count upper bound (unsealed) |
| `CVOGReaction_ResolveObjectTarget` | Resolve world/equip object from TFID |

## Callers

| Site | Context |
|------|---------|
| `FUN_008e5e00` @ `008e6345` | After list rebuild: if subwidget TFID (vtbl+0x44c) changed → rebind |
| `008e82ef` | Sibling panel path: push host + TFID from vtbl+0x44c |

## Classification

**Worker** — selection bind helper for craft/RE host panel; no network.

## Name

`Client_UI_CraftHost_BindObjectByTfid_Inferred`

Reject scaffold `Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e5ce0` (mission-chain naming; body is craft host + inventory TFID resolve).
