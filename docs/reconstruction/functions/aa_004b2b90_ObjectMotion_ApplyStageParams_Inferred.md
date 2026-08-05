# Function record: ObjectMotion_ApplyStageParams_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b2b90` |
| **Canonical name** | `ObjectMotion_ApplyStageParams_Inferred` |
| **Ghidra name** | `FUN_004b2b90` |
| **Address** | `0x004b2b90` |
| **Body span** | `004b2b90`–`004b3253` (**1732 B / `0x6C4`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction stage params |
| **Convention** | `__thiscall` + **`ret 8`**; void |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; stage field English open |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Dual A/B** | `reviews/A_aa_004b2b90_ObjectMotion_ApplyStageParams_Inferred.md`, `reviews/B_aa_004b2b90_ObjectMotion_ApplyStageParams_Inferred.md` (2026-07-29 W27-E) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Per-slot **stage-parameter apply** for object-motion / reaction entities, called from SlotTick after timers with a dirty flag:

- **dirty ≠ 0:** copy end-state block (`stage+0x36c` → `slot+0x3e`, 0x1D dwords), apply flag-gated template fields (`stage+0x3e0..3e3`), RNG scales via `DAT_00aaa638`, optional `FUN_004b2910`, snapshot baseline `slot+4` → `slot+0x21`.
- **dirty == 0:** `progress = g_flOne − remaining/total`; lerp baseline→end by progress; always `slot[0xb] += slot[9] * dt`.

## Signature

```c
// thiscall; ret 8; void
void __thiscall ObjectMotion_ApplyStageParams_Inferred(void *slot, char dirty, float dt);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b2b90_FUN_004b2b90.md`
- Annotated: `docs/reconstruction/raw/aa_004b2b90_FUN_004b2b90.annotated.md`
- Clean (mirror): `docs/reconstruction/reconstructed-exact/FUN_004b2b90.cpp`
- Named: `docs/reconstruction/reconstructed-exact/ObjectMotion_ApplyStageParams_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004b2b90_FUN_004b2b90.md`
- Review A/B: dual files above

## Callers / callees (sealed-relevant)

| Dir | VA | Name |
|---|---|---|
| Caller | `0x004b4620` | `ObjectMotion_SlotTick_Inferred` |
| Caller | `0x005bc120` | related motion path |
| Callee | `0x004b2910` | byte-channel helper (unsealed) |
| Callee | — | `CVOGReaction_RandomUnitScalar` |

## Confidence

| Claim | Level |
|---|---|
| CF ≡ live decompile | **Confirmed** |
| ABI ret 8 void | **Confirmed** |
| progress formula | **Confirmed** |
| Product field English / schema | **Open** |
| Runtime / differential | **Open** |

## Prior scaffold alias

`Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b2b90` — superseded.
