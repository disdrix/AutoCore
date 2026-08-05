# Function record: ObjectMotion_SlotTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b4620` |
| **Canonical name** | `ObjectMotion_SlotTick_Inferred` |
| **Ghidra name** | `FUN_004b4620` |
| **Address** | `0x004b4620` |
| **Body span** | `004b4620`–`004b490d` (**749 B / `0x2ED`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction slot |
| **Convention** | `__thiscall` + **`ret 8`**; return 0\|1 in AL |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; nested free helpers + product name open |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Dual A/B** | `reviews/A_aa_004b4620_ObjectMotion_SlotTick_Inferred.md`, `reviews/B_aa_004b4620_ObjectMotion_SlotTick_Inferred.md` (2026-07-29 W26-H) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Per-slot **outer tick** for object-motion / reaction entities: host abort gates, radius pull (0.4 / −0.5 / 0.99 constants), duration timers, nested sealed integrate step. Sole list caller removes slot when return is 0.

## Signature

```c
// thiscall; ret 8
// flag is integer (Ghidra may type as float); dt is float seconds
uint8_t __thiscall ObjectMotion_SlotTick_Inferred(void *slot, int flag, float dt);
// 0 = remove from parent list; 1 = keep
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b4620_FUN_004b4620.md`
- Annotated: `docs/reconstruction/raw/aa_004b4620_FUN_004b4620.annotated.md`
- Clean (mirror): `docs/reconstruction/reconstructed-exact/FUN_004b4620.cpp`
- Named: `docs/reconstruction/reconstructed-exact/ObjectMotion_SlotTick_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004b4620_FUN_004b4620.md`
- Review A/B: dual files above

## Callers / callees (sealed-relevant)

| Dir | VA | Name |
|---|---|---|
| Caller | `0x005bb5e0` | list tick / remove on 0 |
| Callee | `0x004b1100` | `ObjectMotion_IntegrateStep_Inferred` (W24-C) |
| Callee | `0x004cd220` | `CVOGMap_SampleHeightfieldY` |
| Callee | `0x004b0f80` / `0x004b2b90` / `0x004b18f0` / `0x0076f5f0` | residual helpers |

## Confidence

| Claim | Level |
|---|---|
| CF ≡ live decompile | **Confirmed** |
| ABI ret 8 + 0\|1 | **Confirmed** |
| Radius constants | **Confirmed** |
| Nested integrate dual link | **Confirmed** (W24-C) |
| Product C++ name | **Inferred** (`_Inferred`) |
| Runtime / differential | **Open** |

## Prior scaffold alias

`Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b4620` — superseded.
