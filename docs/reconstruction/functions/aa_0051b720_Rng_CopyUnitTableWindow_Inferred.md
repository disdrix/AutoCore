# Function record: Rng_CopyUnitTableWindow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b720` |
| **Canonical name** | `Rng_CopyUnitTableWindow_Inferred` |
| **Ghidra name** | `FUN_0051b720` |
| **Address** | `0x0051b720` |
| **Body** | `0x0051b720`–`0x0051b768` exclusive (72 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual sealed** (WQ9R-A 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Caller-buffer variant of the global RNG unit-table window sampler. Copies `nWords` ushorts from `tableBase[cursor]` into `dst`, wraps cursor when `cursor+nWords > 0xFFFFF`, advances cursor by **1**, returns old cursor as dice-seed index.

Primary skill consumer: `Skill_ApplyStatusEffectLocal` re-rolls `packet+0x3C` (`lDiceSeed`) when world sim flag `+0x7e` is set — pattern `push buf; push 600; RandomUnitScalar(); mov ecx,eax; call this; mov [pkt+0x3C],eax`.

## Signature

```c
// __thiscall  RET 8
uint32_t Rng_CopyUnitTableWindow_Inferred(RngHost* this, int nWords, void* dst);
```

| Param | Role |
|---|---|
| `this` | RNG host (`&DAT_00d20c1c`) |
| `nWords` | ushort count (callers use **600**) |
| `dst` | destination (`nWords*2` bytes) |
| return | pre-increment cursor |

## Layout (host)

| Offset | Field |
|---|---|
| `+0x08` | table base (`uint8_t*`, 0x200000 after init) |
| `+0x0C` | cursor (int, ushort index) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051b720_FUN_0051b720.md`
- Annotated: `docs/reconstruction/raw/aa_0051b720_FUN_0051b720.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Rng_CopyUnitTableWindow_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0051b720.cpp`
- Dual A/B: `reviews/A|B_aa_0051b720_Rng_CopyUnitTableWindow_Inferred.md`

## Related

| VA | Name | Relation |
|---|---|---|
| `0x007a4330` | `CVOGReaction_RandomUnitScalar` | Singleton getter → `this` |
| `0x0058ab60` | `Rng_CloneSeededTable_Inferred` | Sibling: heap clone + force seed + fixed 600 |
| `0x007a4170` | unit float draw | Single ushort * 1/65536 from same stream |
| `0x0051aa00` | `Skill_ApplyStatusEffectLocal` | Caller (dice seed re-roll) |

## Confidence

| Claim | Level |
|---|---|
| Window copy + wrap + cursor++ | **Confirmed** |
| Return old cursor | **Confirmed** |
| Product C++ name | **Inferred** (`_Inferred` required) |
