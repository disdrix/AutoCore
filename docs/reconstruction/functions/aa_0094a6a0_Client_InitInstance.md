# Function record: Client_InitInstance

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094a6a0` |
| **Canonical name** | `Client_InitInstance` |
| **Address** | `0x0094a6a0`–`0x0094b324` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-boot` / InitInstance |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** — ABI/phase order/strings/gates sealed; many manager type English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Review date** | `2026-07-29` |

## Alias

- Ghidra: `FUN_0094a6a0`
- Scaffold: `Named_Client_InitInstance_0094a6a0`

## Purpose

Client **InitInstance** bring-up: crypto, COM, render, sector map, asset catalog, clonebase lists, optional data tables (XP/credits/loot/medals), physics, generators, sound, UI. Product strings `"Client InitInstance"` / `"InitInstance::done"`.

## Signature (sealed)

```c
// __stdcall: client app object on stack; RET 4; return 1 on success
// Graphics fail path: _exit(1) — does not return
uint32_t __stdcall Client_InitInstance(void *clientApp);
```

Caller: `FUN_0094ba40` → `Client_InitInstance(&DAT_00d1a840)`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0094a6a0_Client_InitInstance.md` (+ full body scaffold `aa_0094a6a0_FUN_0094a6a0.md`)
- Annotated: `docs/reconstruction/raw/aa_0094a6a0_Client_InitInstance.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_InitInstance.cpp` (+ `FUN_0094a6a0.cpp`, `Named_Client_InitInstance_0094a6a0.cpp`)
- Dual A: `docs/reconstruction/reviews/A_aa_0094a6a0_Client_InitInstance.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0094a6a0_Client_InitInstance.md`

## Callers / callees

| Direction | Address / name | Role |
|---|---|---|
| Caller | `FUN_0094ba40` @ `0x0094ba40` | sole static caller (dev client entry) |
| Callee (sample) | `FUN_007a4400` / `4480` / `4390` | progress banners |
| Callee | `FUN_007b6a20` | `NDXml_GetLoaderSingleton` |
| Callee | `FUN_004d8a10` | sector map ctor path |
| Callee | `FUN_00948530` | InitRenderEngine (0 ok) |
| Callee | `Experience_*` / `EnsureQuest*` / `FUN_00519660` / `FUN_005129b0` | gated table batch |
| Callee | `CoInitializeEx`, `QueryPerformanceCounter`, `_exit`, … | Win32 / CRT |

## Key client object offsets (this unit)

| Off | Role (from this function) |
|---|---|
| `+0x3c10` | LED_FX host ptr (optional) |
| `+0x31ec` / `+0x31f0` | early manager slots |
| `+0x4d0` / `+0x4ec` / `+0x4f0` / `+0x4f4` | mid managers / UI |
| `+0x9e6`…`+0x9e9` | mission-complete audio flags |
| `+0xdc0` / `+0xde8` / `+0xdec` | sound / render / gfx helper |
| `+0xd30` / `+0xd34` / `+0xd38` | clonebase host / cloned list / HB list |
| `+0xe04` | sector map (`0xe920` object) |
| `+0x31f5` | **light-boot gate** (char) |
| `+0xd80` / `+0xd88`…`+0xd98` | init-done flag + QPC stamps |
| `+0x13` | post-init ready byte set to 1 |

## Confidence

| Claim | Level |
|---|---|
| Name Client_InitInstance | **High** (product strings) |
| ABI stdcall 1-arg RET 4 | **High** (exit bytes) |
| Phase order / gates | **High** (decompile ≡ raw) |
| Sole caller FUN_0094ba40 | **High** |
| Per-slot product class English | **Probable / Tentative** |
| Server relevance | **None expected** (client boot) |
