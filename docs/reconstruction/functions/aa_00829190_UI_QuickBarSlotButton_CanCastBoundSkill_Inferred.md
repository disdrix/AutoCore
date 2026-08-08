# Function record: UI_QuickBarSlotButton_CanCastBoundSkill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829190` |
| **Canonical name** | `UI_QuickBarSlotButton_CanCastBoundSkill_Inferred` |
| **Ghidra name** | `FUN_00829190` |
| **Address** | `0x00829190` |
| **Body range** | `0x00829190` – `0x00829359` (458 bytes / `0x1CA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / quickbar / skills-abilities (WQ-008 residual mention via cast helpers) |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (role `_Inferred`; force-flag + bit0x800 product open) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept-with-gaps** |
| **Last reviewed** | `2026-08-04` (WQ8R-D) |

## Alias

- `FUN_00829190`
- Descriptive: `QuickBarSlot_IsSkillCastReady_Inferred`

## Purpose

Boolean **readiness** for a QuickBar **slot-button** whose payload is a skill:

1. Require local world root, `payloadKind==1`, non-null skill*.
2. Optional UI force-true (`DAT_00d1b644+0xf5`).
3. Else: seed aim/TFID from local character; `Skill_LocalCastValidate(..., skipBusy=1, skill, 0)` must return **0** or **6** (busy still counts as UI-ready).
4. If `skill+0x614 & 0x800` clear: `Client_Skill_ResolveCastTarget` then true iff resolved TFID **≠** invalid sentinel `DAT_00a1e810`.
5. If bit set: true without resolve.

## Signature (byte-sealed 2026-08-04)

```c
// MSVC __thiscall; RET (no stack cleanup); bool AL
bool UI_QuickBarSlotButton_CanCastBoundSkill_Inferred(
    UI_QuickBarSlotButton* this  // ECX
);
```

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / size | **Confirmed** |
| ABI thiscall 0-arg + bool AL | **Confirmed** |
| payloadKind `+0x548==1` / skill `+0x558` | **Confirmed** (layout + AssignSkill dual) |
| LocalCastValidate skipBusy=1; accept {0,6} | **Confirmed** |
| Resolve vs invalid when `+0x614&0x800==0` | **Confirmed** |
| Naming product English | **Inferred** (role-sealed) |
| `DAT_00d1b644+0xf5` product | Open |
| bit `0x800` product | Open |
| Runtime | Open |

## Open questions

1. Product name for skill flag `+0x614 & 0x800`.
2. Product name for UI force-ready `DAT_00d1b644+0xf5`.
3. Containing function for sole xref `0x00829883` (icon enable) — boundary sparse in Ghidra.
4. Whether skipBusy=1 is intentional UI-only relaxation vs cast request path (RequestCast often uses 0).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00829190_FUN_00829190.md` (+ WQ8R-D append)
- Annotated: `docs/reconstruction/raw/aa_00829190_FUN_00829190.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00829190.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_00829190_UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.md` (+ B)
- Scaffold record: `docs/reconstruction/functions/aa_00829190_FUN_00829190.md`

## Callers / callees

**Callees:** `Skill_LocalCastValidate` `0x0051a790`; `Client_Skill_ResolveCastTarget` `0x0093b3a0`; `TFID_EqualsObjectId` `0x00404aa0`; character vtbl `+0x19c` / `+0x1a0`.

**Callers:** sole xref `0x00829883` (button this in ESI).
