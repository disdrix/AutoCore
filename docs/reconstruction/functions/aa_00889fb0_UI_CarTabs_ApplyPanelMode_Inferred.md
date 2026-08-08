# Function record: UI_CarTabs_ApplyPanelMode_Inferred (`FUN_00889fb0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00889fb0` |
| **Canonical name** | `UI_CarTabs_ApplyPanelMode_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00889fb0` |
| **Address** | `0x00889fb0`–`0x0088a12e` (**383 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Classification** | worker |
| **Dual** | R11-033 2026-08-05 — **accept-with-gaps** |
| **Name confidence** | Inferred (strong structural + init XML cargo/mission + multi-caller; no product plate on function) |
| **Parent (partition)** | `0x0082f510` `UI_Window_OnCommand_Class8_Inferred` (case `0xb`) |

## Role

Car-tabs dialog **binary panel mode apply**: switch between **cargo** tab (`i_d_tabs_car_2d_tab_cargo.xml` @ host `+0x514`) and **mission** tab (`i_d_tabs_car_2d_tab_mission.xml` @ host `+0x518`), with chrome pair at `+0x50c`/`+0x510` and mode dword at `+0x528`.

## Mode map

| Mode | Chrome | Active tab |
|-----:|--------|------------|
| 0 | show A / hide B | cargo (`+0x514`) expand+layout; mission collapse+detach |
| 1 | hide A / show B | cargo collapse+detach; mission expand+layout |

## ABI

| Item | Value |
|------|-------|
| Mode | **EAX** `{0,1}` |
| Stack | `host*`, `force` (char) |
| Cleanup | **`RET 8`** |
| Return | void |

## Related (not owned)

| VA | Name / note |
|---|---|
| `0x0082f510` | parent class-8 OnCommand (dualed WQ8R-F) — case `0xb` |
| `0x0088a290` | car-tabs init / XML load; tails into this apply |
| `0x00822cb0` | child expand/collapse geometry helper |
| `0x00756c90` | list-detach helper |
| `0x00888b00` | sibling binary panel apply (mode slot `[0x14d]`) |
| `0x00889410` | sibling ternary panel apply (mode slot `[0x14c]`) |
| `DAT_00d1b880` | car-tabs dialog singleton |

## See also

- Ghidra twin record: `aa_00889fb0_FUN_00889fb0.md`
- Dual report: `docs/agents/task-dual-ab-00889fb0-r11-report.md`
