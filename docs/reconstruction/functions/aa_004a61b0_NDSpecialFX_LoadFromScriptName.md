# Function record: NDSpecialFX_LoadFromScriptName

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a61b0` |
| **Canonical name** | `NDSpecialFX_LoadFromScriptName` |
| **Address** | `0x004a61b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-fx` |
| **Completion status** | **Dual-reviewed** — path/open/parse High; success return residual |
| **Bit-for-bit / runtime / diff** | Open (success epilogue not recovered) |
| **Dual reviews** | `reviews/A_aa_004a61b0_NDSpecialFX_LoadFromScriptName.md`, `reviews/B_aa_004a61b0_NDSpecialFX_LoadFromScriptName.md` |
| **Wave owner** | dual-w6-sfx (OWN-ONLY) |

## Alias

Human name (string-derived, weak): `Named_VOG_DEBUG_STOP_004a61b0` — prefer **NDSpecialFX_LoadFromScriptName**.

## Purpose

Build `..\scripts\<name>[_nfx.xml]`, open as tagged `NDSpecialFX` document, parse first node into a special-FX object, run instantiate helper `FUN_004a0b90(fx, fx+0xd5, 1, -1, stamp)`, return FX pointer to client callers (interact icons, weather, elite, skills, particles).

## Signature (decompiler-derived)

```c
void * __cdecl NDSpecialFX_LoadFromScriptName(char *pszName, int flags /* unused in body */, int unused /* stamp → 004a0b90 */);
```

## Three-rep summary (2026-07-29)

| Rep | Method | Result |
|---|---|---|
| 1 | Ghidra decompile | Full path/open/parse CF; success ends `004a0b90` + dtor helpers + `operator_delete`; modeled return null |
| 2 | `read_memory` | Prefix `..\scripts\` @ `0x00a96040`; suffix `_nfx.xml` @ `0x009ca184`; tag `NDSpecialFX` |
| 3 | Basic pcode + callers | Fail BB zeros EAX; success BB noreturn-modeled at delete; 39 xrefs need non-null |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a61b0_NDSpecialFX_LoadFromScriptName.md`
- Annotated: `docs/reconstruction/raw/aa_004a61b0_NDSpecialFX_LoadFromScriptName.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDSpecialFX_LoadFromScriptName.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004a61b0_NDSpecialFX_LoadFromScriptName.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004a61b0_NDSpecialFX_LoadFromScriptName.md`

## Callers / callees

**Callees:** `FUN_00799940`, `NDXml_OpenTaggedDocument`, `FUN_00799900`, `FUN_004a4fa0`, `FUN_004a0b90`, `FUN_004b85d0`, `FUN_004b99c0`, `FUN_007989b0`, `FUN_007a4480`, `strstr`, `operator_delete`.

**Callers (sample):** `Client_UpdateNpcInteractIcons`, `CVOGCreature_PostCreateFromPacket`, `CVOGSpawnPoint_CreateCreature`, weather loaders (`FUN_00553d20` family), `FUN_005a9400` (tire FX), skill FX paths, elite `generic_elite`.

## Confidence

| Claim | Level |
|---|---|
| Control flow path/open/parse | **High** |
| Suffix `_nfx.xml` (not `.xml`) | **High** |
| `flags` unused in this VA | **High** |
| Success returns usable FX* | **High (callers)** / **Low (decompiler)** |
| Parameter semantic names | Probable |
| Types | Tentative |

## Residual

1. Success return / ownership after `FUN_004a0b90`.
2. Confirm whether `operator_delete` frees template post-clone.
3. Name of field at FX+0xd5.
