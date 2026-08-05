# Function record: ObjectMotion_AdvanceStage_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b0f80` |
| **Canonical name** | `ObjectMotion_AdvanceStage_Inferred` |
| **Ghidra name** | `FUN_004b0f80` |
| **Address** | `0x004b0f80` |
| **Body span** | `004b0f80`–`004b10fe` (**383 B / `0x17F`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction stage chain |
| **Convention** | `__thiscall` + **`ret 4`**; return 0\|1 in AL |
| **Completion status** | **partial** — three-rep + dual A/B sealed 2026-07-29; product name open |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Dual A/B** | `reviews/A_aa_004b0f80_ObjectMotion_AdvanceStage_Inferred.md`, `reviews/B_aa_004b0f80_ObjectMotion_AdvanceStage_Inferred.md` (2026-07-29 W27-E) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Per-slot **stage advance** for object-motion / reaction entities:

1. Side effects on current stage (mission-complete audio **or** FX spawn + multi-hit flush).
2. Follow `stage+0x2f4` next link into `slot[1]`.
3. mode-1 + end-sentinel + no secondary timer → return **0** (remove).
4. Else load duration `*next` into `slot[0x5c]`, optional RNG jitter (`+0x1e4` bit2 × `DAT_00aaa638`), mirror to `slot[0x5d]`, return **1**.

## Signature

```c
// thiscall; ret 4
uint8_t __thiscall ObjectMotion_AdvanceStage_Inferred(void *slot, char mode);
// mode 0 = soft (SlotTick radius rebind); mode 1 = hard (duration expired)
// 0 = remove from parent list; 1 = keep / duration reloaded
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b0f80_FUN_004b0f80.md`
- Annotated: `docs/reconstruction/raw/aa_004b0f80_FUN_004b0f80.annotated.md`
- Clean (mirror): `docs/reconstruction/reconstructed-exact/FUN_004b0f80.cpp`
- Named: `docs/reconstruction/reconstructed-exact/ObjectMotion_AdvanceStage_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004b0f80_FUN_004b0f80.md`
- Review A/B: dual files above

## Callers / callees (sealed-relevant)

| Dir | VA | Name |
|---|---|---|
| Caller | `0x004b4620` | `ObjectMotion_SlotTick_Inferred` (sole) |
| Callee | `0x00725a70` | `CSoundManager_TryQueueMissionCompleteSound_Inferred` (W18-R) |
| Callee | `0x004b6980` | `NDSpecialFX_FlushStagedMultiHits_Inferred` |
| Callee | `0x004e9530` / `0x004b7e50` / RNG | residual |

## Confidence

| Claim | Level |
|---|---|
| CF ≡ live decompile | **Confirmed** |
| ABI ret 4 + 0\|1 | **Confirmed** |
| Stage-chain advance via `+0x2f4` | **Confirmed** |
| Product C++ name | **Inferred** (`_Inferred`) |
| Runtime / differential | **Open** |

## Prior scaffold alias

`Mission_Uses_Client_GetMissionCompleteAudioTable` — superseded (partial keyword hit only).
