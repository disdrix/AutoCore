# Annotated: `aa_004a4fa0` NDSpecialFX_ParseXmlEventNode

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a4fa0` |
| **VA** | `0x004a4fa0` |
| **Body span** | `004a4fa0` – `004a617f` |
| **Canonical name** | `NDSpecialFX_ParseXmlEventNode` |
| **System** | `client-fx` / NDSpecialFX XML |
| **Date** | `2026-07-29` (OWN-ONLY dual seal; live Ghidra decompile + `read_memory`) |
| **Calling convention** | `__cdecl` (EBP frame, bare `ret`) |

---

## Purpose

Parse one **NDSpecialFX event XML node** into a heap FX object (~`0x240` bytes):

1. Read event **type name** attribute (wide) → map to integer event id (or allocate custom id ≥ 100).
2. Construct FX object; store event id at **`+0x28`**.
3. Optionally read a float attr into **`+0x58`**.
4. Enumerate child nodes; dispatch by element name (`Group`, `Particle`, `Geometry`, `Trail`, `Lightning`, `Sound`, `MusicEvent`, `Force`, `Include`, `Parameter`, `Fluid`).
5. On hard failure: teardown (`FUN_004b99c0`) + `operator_delete` (noreturn).
6. On success: return FX pointer; on early gate fail: return **NULL**.

Callers: `NDSpecialFX_LoadFromScriptName`, `FxMaster_LoadMasterFromXML` (`FUN_004a6390`), `FUN_004a6670`.

---

## Signature (sealed shape; names inferred)

```c
// __cdecl
// node: XML/COM node with vtbl (NOT BSTR) — Ghidra mislabels param_1 as BSTR
void *NDSpecialFX_ParseXmlEventNode(
    IXmlNode *node,           // [ebp+8]  — vtbl+0x44 used first
    int *outEventType,        // [ebp+0xC]
    uint8_t *customIdCounter  // [ebp+0x10] — bumped on unknown type names
);
// returns FX* or NULL
```

Sibling review of `NDSpecialFX_LoadFromScriptName` passes a 4th stack arg (`pszName`); **this body does not reference a 4th arg** in decompile — treat as caller-only / unused on this VA.

---

## High-level CF

```
SEH + large stack
hr = node->vtbl[+0x44](... out locals ...)
if hr != 0 OR primary attr blob null:
  log path / free BSTRs
  return NULL

if !FUN_00798bb0(... type name into wide buf ...):
  // fall through to fail return
else:
  *outEventType = map_wcsicmp(typeName)  // Create..Suspension or custom+100
  fx = new(0x240); if non-null: FUN_004ba310()
  fx->eventType(+0x28) = *outEventType
  FUN_004b6850(...)
  if FUN_00799460(floatAttr): fx+0x58 = value; FUN_00799300(...)
  node->vtbl[+0x30](... children enumerator ...)
  if !children: teardown+delete (noreturn)
  children->vtbl[+0x20](...)
  for i in 0 .. count-1:
    get child; free prior BSTR; get child name
    switch name:
      Group / Particle / Geometry / Trail / Lightning / Sound /
      MusicEvent / Force / Include / Parameter / Fluid
    release child
  release enumerator (x2)
  free BSTRs
  return fx

// fail:
return NULL
```

---

## Event type table

See raw live append. Unknown names: `*outEventType = *customIdCounter + 100; (*customIdCounter)++`.

---

## Group owner attach ids

See raw live append. `DAT_009c9ef0` = `L"top"`. Unmatched `weaponMelee` chain uses  
`id = (wcsicmp!=0 ? 0 : 0x15)` via `(-(neq)&0xffffffeb)+0x15`.

---

## Sound subobject (`0x138` bytes)

Defaults before attrs:

| Off | Init |
|---|---|
| zero fill | `0x4e` dwords (`0x138` bytes) |
| `+0x11c` | `g_flOne` (volume) |
| `+0x110` | `DAT_009c7c28` = **10.0f** (radius) |
| `+0x114` | `DAT_009c7c2c` = **80.0f** (maxradius) |
| `+0x104` | u32 sound-category default **0**, then switch on event type |

Event-type → default sound category at `+0x104` (before `soundType` override):

| Event types | Category dword |
|---|---|
| Create (0) | `0x46` (`'F'`) |
| Death / DeathOverkill / DeathFiery / DeathPeaceful | `0x32` (`'2'`) |
| Fire (4) | `0x0A` |
| Hit / HitVehicle / HitFirer | `0x0D` |
| Miss | `0x0C` |
| Collision | `0x28` (`'('`) |

Attrs: `soundName`, `looping`, `unlinked`, `Sound3D`, `eventPlay`, `soundRegion`, `radius`, `maxradius`/`maxRadius`, `fadeTime`, `volume`, `hasStereo`, `rpmMultiplier`, `localOnly`, `soundType` (Generic / ENGINE_* / MY_* / Collision / Weather …).

Then `Client_GetMissionCompleteAudioTable`, `FUN_007249c0` validate; fail → delete sound block; success → `FUN_004a79e0` attach.

---

## Parameter type map (`+4` field of 0x28 block)

| type string | value |
|---|---|
| targetDirection | 1 |
| target | 0 |
| missAbsolute | 5 |
| missRelative | 6 |
| targetLength | 4 |
| number (match) | 2 |
| *(else)* | 3 |

(`3 - (neq!=0)` → match gives 2, else 3.)

---

## Residuals (OWN)

1. Exact IXml vtbl names for `+0x44`, `+0x30`, `+0x20`, `+0x1c`, `+8` — call shapes sealed; COM names not.
2. Full bodies of `FUN_004ba310`, `FUN_004b6850`, `FUN_004b99c0`, child loaders — **not owned**.
3. Decompiler stack/reg recovery noise (`unaff_ESI`, `unaff_EDI`, `pvStack_958` reused as child count) — CF of string maps and dispatch is High; some intermediate locals Low.
4. Ghidra warning “Removing unreachable block (ram,0x004a5789)”.
5. Runtime / differential **Open**.
