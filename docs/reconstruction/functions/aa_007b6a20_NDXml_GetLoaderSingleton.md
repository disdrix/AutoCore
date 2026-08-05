# Function record: NDXml_GetLoaderSingleton

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6a20` |
| **Canonical name** | `NDXml_GetLoaderSingleton` |
| **Address** | `0x007b6a20`–`0x007b6a82` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-xml` |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** — ABI/CF/singleton layout sealed; full class/vtable product names open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Review date** | `2026-07-29` |

## Alias

- Ghidra: `FUN_007b6a20`
- Scaffold: `Named_CalleeOf_Client_LoadVogIniConfig_007b6a20` (role incomplete — not VOG-ini-only)

## Purpose

Meyers **singleton getter** for the process-static **NDXml path-loader** object stored at `DAT_00d20c38`. First call constructs the object (vtable, flags=1, zeroed fields) and registers process-exit cleanup via `_atexit(LAB_009c3040)`. Always returns `&DAT_00d20c38`.

Primary evidence chain: `NDXml_OpenTaggedDocument` → **this** → `NDXml_LoadDocumentFromPath(loader, doc, path)`.

## Signature (sealed)

```c
// cdecl / no args; return pointer in EAX; plain RET
void *NDXml_GetLoaderSingleton(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007b6a20_NDXml_GetLoaderSingleton.md` (+ scaffold `aa_007b6a20_FUN_007b6a20.md`)
- Annotated: `docs/reconstruction/raw/aa_007b6a20_NDXml_GetLoaderSingleton.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDXml_GetLoaderSingleton.cpp` (+ `FUN_007b6a20.cpp`)
- Dual A: `docs/reconstruction/reviews/A_aa_007b6a20_NDXml_GetLoaderSingleton.md`
- Dual B: `docs/reconstruction/reviews/B_aa_007b6a20_NDXml_GetLoaderSingleton.md`

## Callers / callees

| Direction | Notes |
|---|---|
| Callees | `_atexit` only |
| Callers | **50+** including `NDXml_OpenTaggedDocument`, `NDUIWindow_LoadInterfaceFile`, `CVOGTerrain_LoadMapImage` / `LoadTintMap` / `ReloadRandomTintFile`, `CVOGCreature_SetupGraphics`, many unnamed loaders |
| Static object | `DAT_00d20c38`…`DAT_00d20c44`; once guard `DAT_00d20c48` |
| Vtable | `PTR_FUN_00a95b88` (slot0 dtor `FUN_004239a0`) |

## Confidence

| Claim | Level |
|---|---|
| Singleton getter CF / once-init | **High** |
| Return `&DAT_00d20c38` | **High** |
| Object +0x04 flags = 1 at init (search-path) | **High** |
| NDXml loader role via OpenTagged + LoadDocumentFromPath | **High** |
| Full product class / remaining vtable slots | **Tentative** |
| English field names for +0x08/+0x0c | **Tentative** |
