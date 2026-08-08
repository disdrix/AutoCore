# Function record: Client_UI_CraftHost_ResetRecipePanel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e2d60` |
| **Canonical name** | `Client_UI_CraftHost_ResetRecipePanel_Inferred` |
| **Ghidra name** | `FUN_008e2d60` |
| **Address** | `0x008e2d60`–`0x008e2e5e` (255 B / `0xFF`) |
| **Module** | `autoassault.exe` |
| **System** | `inventory-transfer` |
| **Dual** | MEGA-085 2026-08-05 — **accept-with-gaps** |

## Evidence for name

1. Partition hint: `UI_CraftHost_ResetRecipePanel`; parent dual context `0x008e5990` (`UI_CraftHost_BindResolvedObject` / bind stores `host+0x7cc` then **always** calls this).
2. Sibling dualed `Client_UI_CraftHost_BindObjectByTfid_Inferred` (`0x008e5ce0`) resolves TFID → object → `FUN_008e5990` — same host family.
3. Body is pure local UI clear: 5×5 cell TFID `0xFFFFFFFF` stamps, owned dtor, widget hide/refresh — matches “reset recipe panel” not mission refresh.
4. Rejected scaffold `Named_CalleeOf_*Client_RefreshOpen*`.

`_Inferred`: host product RTTI / vtbl slot English not sealed in this unit.

## ABI

```c
void __stdcall Client_UI_CraftHost_ResetRecipePanel_Inferred(void* host); // RET 4
```

## Host field map (this unit)

| Offset | Use |
|--------|-----|
| `+0x534` | Row widget ptrs ×5 |
| `+0x5b8` | Cell widget ptrs ×25 |
| `+0x61c` | Owned object* ×25 (via cellBase+0x64) |
| `+0x680` | Cell TFID pairs ×25 |
| `+0x748` | Footer chrome widget |
| `+0x768` | Optional widget |
| `+0x76c` | Optional widget (tail hide) |

## Cross-links

- Parent bind (unowned residual): `FUN_008e5990` @ `0x008e5990`
- TFID bind (dualed): `Client_UI_CraftHost_BindObjectByTfid_Inferred` @ `0x008e5ce0`
- Panel refresh (residual): `FUN_008e5e00` @ `0x008e5e00`
- Machine twin: `FUN_008e2d60`

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_008e2d60_FUN_008e2d60.md`
- Annotated: `docs/reconstruction/raw/aa_008e2d60_FUN_008e2d60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_UI_CraftHost_ResetRecipePanel_Inferred.cpp`
- Reviews: `A_` / `B_aa_008e2d60_Client_UI_CraftHost_ResetRecipePanel_Inferred.md`
- Report: `docs/agents/task-dual-ab-008e2d60-mega-085-report.md`
