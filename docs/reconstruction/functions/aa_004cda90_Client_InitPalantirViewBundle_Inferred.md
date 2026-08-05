# Function record (named): Client_InitPalantirViewBundle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cda90` |
| **Semantic name** | `Client_InitPalantirViewBundle_Inferred` |
| **Ghidra name** | `FUN_004cda90` |
| **Address** | `0x004cda90`–`0x004cdc34` exclusive (**420 B** / `0x1A4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir graphics + env bootstrap |
| **Naming basis** | Sole caller window-init path with `"Could not get Palantir desktop window."`; GfxView ctor path `gfxView.cpp` / `PalViewBackground.fx`; three owned slots `+0xE890/+0xE894/+0xE898` |
| **Status** | Dual sealed W30-F (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC-style factory method on a large client/core parent object:

1. `operator_new(0x150)` + `FUN_0075ceb0` → **GfxView** @ `parent+0xE890`; stamp near **0.5f** / far **1000.f|500.f** (by `parent+0x7d`).
2. If `parent+0xE89C` (Palantir desktop host, pre-stuffed by caller) non-null: wire view into desktop fields + vcall.
3. `operator_new(0x198)` + `FUN_00492dd0(0, parent)` → `parent+0xE894`.
4. `operator_new(0xC8)` + `Class_009c7a1c_Ctor` → `parent+0xE898`.
5. Cross-wire `view+4 = env`, `env+0xC0 = view`.
6. `FUN_0048fc90(env, 1)` environment phase init.
7. Publish `*(env+4)` into process global `DAT_00d1a54c` with `FUN_0074e200` toggle.
8. Return **1**.

## Signature

```c
// __thiscall/__fastcall; ECX=parent*; returns 1; bare RET (C3)
uint32_t __fastcall Client_InitPalantirViewBundle_Inferred(void *parent);
```

## Parent offsets (sealed)

| Off | Role | Conf |
|----:|------|------|
| `+0x7D` | mode byte (far plane select) | **High** |
| `+0xE890` | GfxView* (`sizeof 0x150`) | **High** |
| `+0xE894` | env host* (`sizeof 0x198`) | **High** |
| `+0xE898` | `Class_009c7a1c*` (`sizeof 0xC8`) | **High** |
| `+0xE89C` | optional Palantir desktop* | **High** (caller-stamped) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cda90_FUN_004cda90.md`
- Annotated: `docs/reconstruction/raw/aa_004cda90_FUN_004cda90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_InitPalantirViewBundle_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004cda90.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004cda90_FUN_004cda90.md`
- Reviews: `A_aa_004cda90_Client_InitPalantirViewBundle_Inferred.md`, `B_aa_004cda90_Client_InitPalantirViewBundle_Inferred.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_00948530` | sole CODE xref `0x00948aad` |
| Callee | `FUN_0075ceb0` | GfxView complete ctor |
| Callee | `FUN_00492dd0` | env host ctor |
| Callee | `FUN_00496f70` | `Class_009c7a1c_Ctor` (W29-G) |
| Callee | `FUN_0048fc90` | VOGEnvironmentSector phase init |
| Related | `Class_009c7a1c_CompleteDtor` `0x004970b0` | twin of helper ctor |

## Confidence

| Claim | Level |
|---|---|
| ABI + return 1 + three store offsets | **High** |
| GfxView identity (path/strings in ctor) | **High** |
| Structural factory role | **High** |
| Product demangle parent / env class | **Open** |
| Float field English (near/far) | **Probable** |
