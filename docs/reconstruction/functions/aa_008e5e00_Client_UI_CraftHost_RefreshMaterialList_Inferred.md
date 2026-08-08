# Function record: Client_UI_CraftHost_RefreshMaterialList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5e00` |
| **Canonical name** | `Client_UI_CraftHost_RefreshMaterialList_Inferred` |
| **Ghidra name** | `FUN_008e5e00` |
| **Address** | `0x008e5e00`–`0x008e6386` inclusive (**1415 B** / `0x587`) |
| **Module** | `autoassault.exe` |
| **System** | `inventory-transfer` |
| **Dual** | R10-015 2026-08-05 — **accept-with-gaps** |

## Evidence for name

1. Body exclusively drives craft host **list widget** at `host+0x754` (same field dualed bind units use for preview selection).
2. Fills candidates from cargo + locker + equip — same inventory sources as dualed parent `Client_UI_CraftHost_BindObjectByTfid_Inferred` (`0x008e5ce0`).
3. On selection TFID change, **calls that dualed parent** (`FUN_008e5ce0` stdcall host/lo/hi).
4. String tags `[L]` (locker) / `[M]` (equip) distinguish inventory origin in the list.
5. Scaffold `Named_CalleeOf_Client_RefreshOpenMissionUiWindows_*` is parent-name only; body is craft-host list refresh (one caller is mission-window refresh; another is craft-host sibling).

`_Inferred`: product host class RTTI not sealed in this unit.

## Signature (sealed)

```c
// EDI = craft/UI host*; no stack args; void; plain RET
void Client_UI_CraftHost_RefreshMaterialList_Inferred(/* host in EDI */);
```

## Key offsets

| Offset | Role |
|---|---|
| `host+0x754` | material/candidate list widget* |
| `host+0x758` | companion for `FUN_007fbd30` (asm ESI) |
| `host+0x7cc` | bound object* (TFID fallback when list sel invalid) |
| `list+0x568` | zeroed after restore |
| `char+0x250` / `+0x2b0` | vehicle → cargo grid |
| `char+0xcbc` | locker grid |
| `char+0x5a0` | equip TFID table (8-byte entries) |
| `obj+0x160/0x164` | object TFID lo/hi |
| `obj+0x17c` bit 19 | list inclusion filter (product English open) |
| `DAT_00d1b644+0xf5` | locker UI visibility flag |
| `DAT_00a3af60` / `+0x64` | `"[M]"` / `"[L]"` |

## Cross-links

- Dualed parent (rebind): `Client_UI_CraftHost_BindObjectByTfid_Inferred` @ `0x008e5ce0`
- Dualed bind body: `UI_CraftHost_BindResolvedObject_Inferred` @ `0x008e5990`
- Callers: `Client_RefreshOpenMissionUiWindows` @ `0x0093a940`; sibling site `0x008e63f5`
- Ghidra twin record: `aa_008e5e00_FUN_008e5e00.md`

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008e5e00_FUN_008e5e00.md` |
| Annotated | `docs/reconstruction/raw/aa_008e5e00_FUN_008e5e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_CraftHost_RefreshMaterialList_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008e5e00.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_008e5e00_Client_UI_CraftHost_RefreshMaterialList_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_008e5e00_Client_UI_CraftHost_RefreshMaterialList_Inferred.md` |
| Report | `docs/agents/task-dual-ab-008e5e00-r10-report.md` |

## Gaps

- Product demangle for host/list classes.
- Bit-19 product English (polarity vs parent “Broken”).
- Residual helper English (not OWN).
- Runtime / bit-exact / differential.
