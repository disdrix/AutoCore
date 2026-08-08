# Function record: Client_LoadKeymapIni

Canonical named twin of `functions/aa_0092f710_FUN_0092f710.md`.

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092f710` |
| **Canonical name** | `Client_LoadKeymapIni` |
| **Ghidra name** | `FUN_0092f710` |
| **Address** | `0x0092f710` |
| **System** | input-drive-control |
| **Dual verdict** | **accept-with-gaps** (MEGA-022 A+B) |
| **See** | `aa_0092f710_FUN_0092f710.md` for full tables |

## Naming basis

| Evidence | Weight |
|---|---|
| Literal `fopen("keymap.ini","r")` @ `0x00a2e624` | **High** |
| InitInstance plate `Ini, Keymap, colors` | **High** |
| Writer header `AUTO ASSAULT KEY MAPPING FILE` (`FUN_007f9480`) | **High** |
| Parallel naming to dualed `Client_LoadVogIniConfig` | Style |
| PDB/demangle product method English | Open (not required for this name) |

Scaffold names `Named_keymap_ini` and `Named_CalleeOf_Named_Client_InitInstance_0092f710` **retired**.

## Port contract (summary)

```
Client_LoadKeymapIni(client)   // RET 4; boot-time only
  ActionMap = client + 0x116c
  missing keymap.ini → write default from ActionMap
  else parse Description=primary;alt with // comments
  apply via ActionMap_TrySetSlotBind (lane0 then lane1; flag-gated)
```
