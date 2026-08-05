# Function record: `aa_004a4fa0` NDSpecialFX_ParseXmlEventNode

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a4fa0` |
| **Canonical name** | `NDSpecialFX_ParseXmlEventNode` |
| **Ghidra name** | `FUN_004a4fa0` |
| **Address** | `0x004a4fa0` – `0x004a617f` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-fx` / NDSpecialFX XML |
| **Completion status** | **Dual A/B sealed** (2026-07-29 OWN-ONLY W16-T) |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- `FUN_004a4fa0`
- Prior wrong scaffold alias: `Drive_driver` / `Drive_driver_004a4fa0` (string `driver` is a **Group owner**, not the function role — **superseded**)

## Purpose

Parse one special-FX **event** XML node: map type name → event id, allocate/init ~`0x240` FX object, walk children (Group / Particle / Geometry / Trail / Lightning / Sound / MusicEvent / Force / Include / Parameter / Fluid), return FX* or NULL.

## Signature

```c
// __cdecl
void *NDSpecialFX_ParseXmlEventNode(
    IXmlNode *node,            // not BSTR (Ghidra mislabel)
    int *outEventType,
    uint8_t *customIdCounter);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a4fa0_FUN_004a4fa0.md` (+ 2026-07-29 live append)
- Annotated: `docs/reconstruction/raw/aa_004a4fa0_FUN_004a4fa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004a4fa0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/NDSpecialFX_ParseXmlEventNode.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004a4fa0_NDSpecialFX_ParseXmlEventNode.md`
- Review B: `docs/reconstruction/reviews/B_aa_004a4fa0_NDSpecialFX_ParseXmlEventNode.md`

## Callers / callees

**Callers (xrefs):**

| VA | Function |
|---|---|
| `0x004a62fe` | `NDSpecialFX_LoadFromScriptName` |
| `0x004a6568` | `FUN_004a6390` (`FxMaster_LoadMasterFromXML`) |
| `0x004a6767` | `FUN_004a6670` |

**Notable callees (not dual-owned here):**  
`FUN_004ba310` (ctor), `FUN_004b6850`, `FUN_004b99c0` (teardown), `FUN_004a34f0` Particle, `FUN_004a3fa0` Geometry, `FUN_0049e540` Trail, `FUN_0049e830` Lightning, `FUN_004a79e0` / `FUN_004a7f80` attach, `FUN_0049f2a0` Force, `FUN_0049f9a0` Include, `FUN_004a7580` Parameter insert, `FUN_004a6910`/`FUN_0049f430`/`FUN_004b92b0` Fluid, XML helpers `FUN_00798bb0`/`FUN_00799300`/`FUN_00799460`/`FUN_007996d0`, `_wcsicmp`, `SysFreeString`, `operator_new`/`operator_delete`.

## Confidence

| Claim | Level |
|---|---|
| Body span + `__cdecl` | **High** |
| Arg0 is XML node iface (not BSTR) | **High** (prologue vtbl+0x44) |
| Event-type string → id table | **High** |
| Group owner → attach id table | **High** |
| Child element dispatch set | **High** |
| Sound defaults 10.f / 80.f | **High** (`read_memory`) |
| `fx+0x28` event id; `fx+0x60` force | **High** |
| Enumerator / child-count packing | **Medium–Low** (decomp noise) |
| Callee internal semantics | **Out of scope** |
