# Function record: Client_Input_PollBoundActions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925d60` |
| **Canonical name** | `Client_Input_PollBoundActions` |
| **Address** | `0x00925d60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input (bound-action edge poll); **interact Activate residual** → `interaction-activation` |
| **Completion status** | **Sectioned partial** + **Activate interact edge sealed 2026-07-29** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Last refined** | 2026-07-29 (interact Activate ~15f residual dual) |
| **Dual A/B** | `reviews/A|B_aa_00925d60_Client_Input_PollBoundActions.md` — **accept-with-gaps** |

## Purpose

Per-frame poll of **edge** ActionMap flags (held@slot + edge@slot+1 pairs). Activates quick-bar slots, UI toggles, chat reply, arena dialogs, **world Activate/interact**, etc. Complements `Client_Input_DriveControlTick` (held thr/steer/HB).

## Signature (decompiler-derived)

```c
undefined4 Client_Input_PollBoundActions(int *param_1, int param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00925d60_Client_Input_PollBoundActions.md`
- Annotated: `docs/reconstruction/raw/aa_00925d60_Client_Input_PollBoundActions.annotated.md`
- Clean (sectioned): `docs/reconstruction/reconstructed-exact/Client_Input_PollBoundActions.cpp`
- Dual: `docs/reconstruction/reviews/A|B_aa_00925d60_Client_Input_PollBoundActions.md`
- System: `docs/reconstruction/systems/interaction-activation.md` (flow D)

## Notable groups (clean sections)

| Section | Content |
|---|---|
| 1 | Early UI/misc edges |
| 2 | Chat reply |
| 3 | Arena/battle UI |
| 4 | Modal early-out vtbl+0x194 |
| 5 | Mode 8 hard-stop + PushDriveAxes |
| 6 | QB slots 0–9 primary |
| 7 | QB slots 0–9 shift row |
| 8 | Map/target/companion edges |
| 9 | Menu/dialog toggles |
| 10 | Remaining edges (tail) |
| **10 / Activate residual** | **`DAT_00d1be62/63` "Activate"** → optional C2S **0x2055** @20f, else UseObject path @**15f** |

## Sealed residual — Interact Activate edge (2026-07-29)

**Labels:** Action display name **"Activate"** (`s_Activate_00a8554c` @ ActionMap `+0x4b9`). Runtime flags **`DAT_00d1be62` (held) / `DAT_00d1be63` (edge)**; alternate `(*DAT_00d1b624)(3)`.

**Order:**

1. Clear edge / honor modal `param_1[0x31e]`.
2. Special gather (`FUN_0058cd60` family, imm range **20.0f**): if TFID hit → `FUN_00925580` (**C2S 0x2055**, size **0x30**) and **stop** (no UseObject).
3. Else resolve interact target within **15.0f**:
   - Prefer `DAT_00d1d888` if not self and dist² ≤ **`DAT_00aaaca4` = 225.0f** (=15²);
   - Else `Skill_GatherTargetsInArea` r=**15.0f** (masks 3; town `+0xf5` → 7,0x14);
   - Else `FUN_009197a0(15.0f)` / mask-8 fallback.
4. Send:
   - `obj+0x11c != 0` (also `pi[0x47]`) → **`Client_SendUseObject`**;
   - else `FUN_00524520(obj) != 0` → **`Client_SendUseObject_IfInteractable`**.
5. Senders are **exclusive** on this edge (no dual 0x2072).

| Constant | VA / form | Value | Use |
|---|---|---|---|
| Gather / nearest r | imm `0x41700000` | **15.0f** | UseObject path |
| Select max dist² | `DAT_00aaaca4` | **225.0f** | `d1d888` gate |
| Early gather r | imm `0x41a00000` | **20.0f** | 0x2055 path only |
| Click peer (not this) | `DAT_00aaa6fc` | **25.0f** | pick hub only |

## Related

- `Client_Input_DriveControlTick` @ `0x009223b0` (`aa_009223b0`) — held drive axes
- `Client_QuickBar_ActivateSlot` / `Client_QuickBarActivateSkillSlot`
- `Client_SendUseObject` @ `0x00916740` / `Client_SendUseObject_IfInteractable` @ `0x00930d70`
- `Client_InteractClickPickTarget` @ `0x009247b0` — click path (25f)
- `FUN_009197a0` @ `0x009197a0` — nearest interactive ≤ r
- `FUN_00925580` @ `0x00925580` — C2S 0x2055

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler (Activate slice, fresh) | **High** |
| QB slot edge → ActivateSlot(i, row, -1) | High |
| Activate → 15f UseObject / IfInteractable branch | **High** |
| Activate → exclusive 0x2055 first | **High** |
| Full semantic names for every DAT edge | Tentative |
| Gather mask taxonomy / 0x2055 product role | Tentative |

## Open questions

1. Exact frame order vs DriveControlTick.
2. Complete ActionMap name table for each edge DAT (outside Activate residual).
3. `0x2055` product semantics + `FUN_0058cd60` mode-6 class filter.
4. ActionMap slot index math: display `+0x4b9` ↔ `DAT_00d1be62`.
