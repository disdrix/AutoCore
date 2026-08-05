# Function record: effEffect_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970260` |
| **Canonical name** | `effEffect_Unserialize` |
| **Address** | `0x00970260` |
| **Body range** | `0x00970260`–`0x00970852` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `graphics-effects` |
| **Completion status** | **Dual reviewed (accept-with-gaps)** — three-rep 2026-07-29; outer EFCT/PARM protocol sealed; FUN_* apply paths open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Unserialize an **EFCT** effect chunk from a `stoChunkReader`: reject unsupported versions, resolve effect by name, then apply a run of **PARM** parameters (types 1–5). Special-case `AlphaTestEnable` → technique `Alpha_Test` and a flag byte on the effect object.

## Signature (decompiler-derived)

```c
/* effEffect::Unserialize
   owns "Invalid TAG unserializing effEffect" @ 0x00a9ec1c
   source: ...\palantir\graphics\Effects\effEffect.cpp
*/
uint32_t effEffect_Unserialize(uint32_t *effect /* param_1 */, int reader /* param_2 */);
// returns 0 on success (non-PARM terminator); 0xFFFFFFFF on tag/version/resolve/bind failure
```

## Protocol (sealed)

| Item | Value |
|---|---|
| Outer tag (u32) | `0x45464354` (`EFCT`; file bytes `TCFE`) |
| Param tag (u32) | `0x5041524d` (`PARM`; file bytes `MRAP`) |
| Version 1 | Reject — DX8 message, line `0x30f` |
| Versions 2–3 | Accept (`1 < ver < 4`) |
| Other versions | Reject — invalid version, line `0x3ac` |
| Wrong tag | Reject — invalid TAG, line `0x308` |
| PARM types | 1 bool, 2 int, 3 float[], 4 inline string, 5 nested/string resource |
| AlphaTest | name `AlphaTestEnable` + nonzero → `Alpha_Test` + `*(uint8_t*)(effect+1)=1` |

## Three-rep (2026-07-29)

| Rep | Method | Result |
|---|---|---|
| A | `decompile_function(0x00970260)` | Full body; plate tags/versions/switch |
| B | `force_decompile(0x00970260)` | **Identical** to A |
| C | `read_memory` strings + basic p-code | Tags `45464354`/`5041524d` in p-code; string cluster `0x00a9eba8`–`0x00a9ec40`+ |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00970260_effEffect_Unserialize.md`
- Annotated: `docs/reconstruction/raw/aa_00970260_effEffect_Unserialize.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/effEffect_Unserialize.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00970260_effEffect_Unserialize.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00970260_effEffect_Unserialize.md`

## Callers / callees

**Callers (9 UNCONDITIONAL_CALL xrefs):**

| Function | VA | Sites |
|---|---|---|
| `gfxGeometryPiece_Unserialize` | `0x0074af60` | 2 (`0x0074b086`, `0x0074b203`) |
| `FUN_0095ef50` | `0x0095ef50` | 7 |

**Notable named callees (this unit only — not dualed):**

- `stoChunkReader_EnterChunkScope` (`0x004370b0`)
- `stoChunkReader_readF32Array` (`0x00436090`)
- `vog_LogMessage` (`0x00996dc0`)
- plus FUN_* name intern / apply / leave-scope helpers

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler (≡ force) | **Confirmed** |
| EFCT/PARM tags + version policy + returns | **Confirmed** |
| AlphaTestEnable special case | **Confirmed** |
| Parameter semantic names (`effect*`, `reader*`) | **High** (probable) |
| FUN_* apply semantics / full wire layout | **Tentative / open** |
| Plate vehicle-tint / glm commentary | **Not body-proven** |
