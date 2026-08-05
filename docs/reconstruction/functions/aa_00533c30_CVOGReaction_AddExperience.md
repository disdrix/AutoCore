# Function record: CVOGReaction_AddExperience

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533c30` |
| **Canonical name** | `CVOGReaction_AddExperience` |
| **Address** | `0x00533c30` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` (character + amount + isKillPath) |
| **Completion status** | **Human-refined clean** — kill spree, cap, level loops annotated; DAT_* table values open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Client XP apply kernel: optional kill-path spree + weapon bonus, personal XP scalar, max-level soft cap, total XP mutation, level-up / level-down loops (guard 300 / `0x12d`).

Called from mission final-complete (`PacketOrNonKill`), S2C GiveXP, and kill XP paths (`KillPath`).

## Signature

```c
bool __thiscall CVOGReaction_AddExperience(
    void* thisCharacter,
    int nAmount,
    XpIsKillPath isKillPath);  // 0 = PacketOrNonKill, non-0 = KillPath
```

Returns `false` if scaled amount is 0; `true` otherwise (including level-loop early exits).

## Behavioral summary

1. **KillPath only:** `GetTickCount` spree window 5s at `+0x734`/`+0x738` (clamp 0..5); if `WeaponAllowsKillXpBonus`, scale amount by `(table[i]+1.0f)` with `i` from entity `+0xe818` clamped 0..15.
2. `scaled = (int)(nAmount * flPersonalXpGain(+0xc54))`.
3. Soft cap when at max level (`+0xc50`) and `specialMode(+0x6b4) < 1`: clamp room under `Experience_GetCumulativeThreshold(level)`.
4. If `scaled == 0` → `false`.
5. `nTotalExperience(+0x730) += scaled`.
6. If entity flag `+0x7e`: negative path LevelDown loop; max-level positive clamp; else LevelUp while `total >= threshold(level)` (guard `< 0x12d`).

## Character offsets (this unit)

| Offset | Role |
|---|---|
| `+0x6b4` | specialMode — skip max-level soft cap when > 0 |
| `+0x6c8` | nLevel |
| `+0x730` | nTotalExperience |
| `+0x734` | dwLastKillTick |
| `+0x738` | cSpreeOrLevelHint |
| `+0xc50` | nMaxLevel |
| `+0xc54` | flPersonalXpGain |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Named; sole client XP mutate kernel |
| Control flow | High | Raw plate + XP.md algorithm agree |
| Field offsets | High | verified by use + XP.md |
| Spree window 5s / clamp 5 | High | literal constants |
| Weapon bonus table DAT_* values | Probable | addresses known; float payloads unread this pass |
| Vtable level getter `+0x27c` | Probable | decompiler chain |
| Overall | **High (static)** | Dual review filed |

## Open questions

- Exact float payloads at `DAT_00aaa7b8` / `DAT_00aaa8f4` / `DAT_00aaa8f0`.
- Whether `WeaponAllowsKillXpBonus` is correctly named for this gate (also used as mode switch in mission units).
- Server `GiveXp` parity for personal scalar and max-level clamp.
- Level-down threshold indexing (`level-1` vs `level`) edge cases at level 1.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00533c30_CVOGReaction_AddExperience.md` |
| Annotated | `raw/aa_00533c30_CVOGReaction_AddExperience.annotated.md` |
| Clean | `reconstructed-exact/CVOGReaction_AddExperience.cpp` |
| Reviews | `reviews/A_aa_00533c30_review.md`, `reviews/B_aa_00533c30_review.md`; also `aa_00533c30_reconstruction_review.md`, `aa_00533c30_skeptical_review.md` |
| Callee | `functions/aa_0052c860_Experience_GetCumulativeThreshold.md` |
| Prior art | `docs/XP.md` |
