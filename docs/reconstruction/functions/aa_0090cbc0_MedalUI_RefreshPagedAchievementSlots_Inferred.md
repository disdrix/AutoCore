# Function record: MedalUI_RefreshPagedAchievementSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090cbc0` |
| **Canonical name** | `MedalUI_RefreshPagedAchievementSlots_Inferred` |
| **Ghidra name** | `FUN_0090cbc0` |
| **Address** | `0x0090cbc0`–`0x0090cdfe` (**575 B** / `0x23F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Partition** | MEGA-063 — Post-force-complete medal UI refresh |
| **Completion status** | **Dual sealed** (A/B **accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Naming rationale

| Evidence | Weight |
|---|---|
| Caller `Client_RecvCompleteDynamicObjective` (S2C **0x2070**) after force-complete | High |
| Sibling prep `MedalUI_PrepClearButtonSlots_Inferred` (`0090c700`) sole-called here | High |
| Apply sibling loads `"i_d_a_2d_btn_achievement.xml"`; count sibling walks same manager | High |
| Achievements window caller `FUN_0090d0d0` uses `"i_d_a_2d_wnd_bg_achievements.xml"` | High |
| Paged fill: 24 slots, row stride 3, scrollbar at host+0x5a0 | High |
| Partition map hint: **Post-force-complete medal UI refresh** | Medium |
| No product symbol inside body → **`_Inferred`** suffix | Required |

Retired: `Named_VOG_DEBUG_STOP_0090cbc0`.

## Purpose

Orchestrate a full **paged medal/achievement slot refresh** on the MedalUI host:

1. Require `DAT_00d1b6d8` manager and host `vtbl[+0x3d8]` visible.
2. Prep-clear 24 button slots (`FUN_0090c700`).
3. Count displayable medals (`FUN_0090c810` — vector + hash).
4. Zero-count: reset page index; hide scrollbar.
5. Non-zero: compute/clamp maxPage/pageIndex; show scrollbar + range; fill ≤24 slots from page start (`pageIndex * 3`) via vector (`flag=1`) then hash (`flag=0`) apply (`FUN_0090c9a0`).

## Signature

```c
// Retail ABI: EAX = MedalUI host*; void; bare RET
void MedalUI_RefreshPagedAchievementSlots_Inferred(void);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0090cbc0_FUN_0090cbc0.md` |
| Annotated | `docs/reconstruction/raw/aa_0090cbc0_FUN_0090cbc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUI_RefreshPagedAchievementSlots_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0090cbc0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0090cbc0_FUN_0090cbc0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0090cbc0-mega-063-report.md` |

## Callers / callees

| Direction | Value |
|---|---|
| Callers | `Client_RecvCompleteDynamicObjective` @ `0081015f`; `FUN_0080ce50` JMP @ `0080ce87`; `FUN_0090d0d0` @ `0090d364`; `FUN_00946c00` @ `009473a5`; `0090ce73`; `00952bb1` |
| Callees | `FUN_0090c700`, `FUN_0090c810`, `FUN_0051a0e0`, `FUN_0090c9a0`, `FUN_007a4480` |

## Gaps

- Product English for host / manager / scrollbar classes.
- Product English for vtbl slots used here.
- Apply `flag` 0 vs 1 product meaning (source path only sealed).
- Residual caller duals outside OWN.
- Runtime / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets | **High** |
| Medal UI refresh role | **High** |
| Page math (24 slots / stride 3) | **High** |
| Product type names | **Low** |
