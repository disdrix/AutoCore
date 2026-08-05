# Function record: ClientCamera_ApplyModeDistanceBand

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090dd50` |
| **Canonical name** | `ClientCamera_ApplyModeDistanceBand` |
| **Prior names** | `FUN_0090dd50`, `Named_CalleeOf_Client_RecvCreateCharacter_0090dd50` |
| **Address** | `0x0090dd50` |
| **Body** | `0x0090dd50`–`0x0090df0f` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / camera |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 W17-H |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Leaf: recompute camera distance **min / max / rate** from integer **mode** at `cam+0x60c`, then clamp current distance slots (`+0x530`, `+0x52c`) into the band. Used after special-event camera mode restore (Respawn, TeleportIn/Out) and character create.

## Signature (sealed)

```c
void ClientCamera_ApplyModeDistanceBand(void *cam /* EAX */);
// No stack args. Plain RET (C3). Zero callees.
```

## Algorithm (sealed)

| mode@+0x60c | min@+0x524 | max@+0x528 | notes |
|---|---:|---:|---|
| **0** | 2.0 | 11.0 or 16.0 (`DAT_00d1b26c`) | rate=(max-min)/16; optional secondary init if `*(DAT_00d1b6d8+0x6b9)` |
| **1** | 6.0 | 20.0 or 30.0 | rate=(max-min)/16 |
| **else** | 12.0 | 20.0 | force `+0x52c=+0x530=20`; rate=0.5 |

Then clamp `+0x530` and `+0x52c` into `[min,max]`.

## Layouts (fields used)

| Object | Off | Field |
|---|---|---|
| Camera | `+0x60c` | mode (int) |
| Camera | `+0x524` | min distance |
| Camera | `+0x528` | max distance |
| Camera | `+0x52c` | secondary current |
| Camera | `+0x530` | primary current |
| Camera | `+0x534` | rate |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0090dd50_FUN_0090dd50.md`
- Annotated: `docs/reconstruction/raw/aa_0090dd50_FUN_0090dd50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ClientCamera_ApplyModeDistanceBand.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_0090dd50.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0090dd50_ClientCamera_ApplyModeDistanceBand.md`
- Review B: `docs/reconstruction/reviews/B_aa_0090dd50_ClientCamera_ApplyModeDistanceBand.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | **none** (leaf) |
| **Callers** | `ClientSpecialEvent_Respawn_Update`, `ClientSpecialEvent_Respawn_dtor`, `ClientSpecialEvent_TeleportIn_ctor`, `ClientSpecialEvent_TeleportOut_ctor`, `Client_RecvCreateCharacter`, `FUN_00979310`, `FUN_009791c0`, `FUN_009788b0`, `FUN_00910b40`, `FUN_0091aa30`, + sites `0x00924171`, `0x0081c1b5` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / mode table / clamp | **High** (decompile + bytes) |
| Float pool constants | **High** (`read_memory`) |
| EAX-object ABI / plain RET | **High** |
| Product mode names (chase/orbit/…) | **Open** (no strings) |
| `DAT_00d1b26c` product meaning | **Open** |
| Name `ClientCamera_ApplyModeDistanceBand` | **Probable** (behavior + callers; no format string) |
| Runtime / bit-exact | Open |

## Dual A/B

| Review | Verdict |
|---|---|
| A fidelity | **accept** |
| B adversarial | **accept** |
