# Function record: UI_InteractionMenu_AddIgnoreToggle

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082f8d0` |
| **Canonical name** | `UI_InteractionMenu_AddIgnoreToggle` |
| **Ghidra name** | `FUN_0082f8d0` |
| **Address** | `0x0082f8d0`–`0x0082f988` inclusive |
| **Body size** | **185 B** (`0xB9`); pad `CC` after |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | interaction menu / social UI (partition skills-abilities residual) |
| **Agent** | MEGA-074 OWN-ONLY dual |
| **Date** | 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

---

## Purpose

**Interaction-menu ignore button pack.** For menu host (EDI) and target object (EAX), create either **Add to Ignore** (`0x11179`) or **Remove from Ignore** (`0x1117c`) using plate `i_m_int_2d_btn_generic.xml`, store the button on the host at `+0x560` / `+0x56c`. Membership via `FUN_00573af0` name lookup on `DAT_00d1da2c` (ignore vector `@+0x38`, entry name `@+0x10`).

## Signature

```c
// EAX = target object*; EDI = menu host*; ret 0 (C3)
void UI_InteractionMenu_AddIgnoreToggle(/* parent regs */);
```

## Sealed facts

1. Live decompile ≡ frozen raw CF (2026-08-05 ≡ 2026-07-23).
2. Entry `cmp [eax+0x6b4],1` — EAX is target.
3. Parent `FUN_0082fe20` sets `MOV EDI,ESI` (host) and `MOV EAX,EBP` (owner/target) before both call sites.
4. Exclusive toggle: ignore-list hit → Remove + early return; else Add.
5. Button ids `0x11179` / `0x1117c`; strings sealed via `read_memory`.
6. Slots host `+0x560` (Add), `+0x56c` (Remove).
7. Direct callee only `FUN_00573af0` (thiscall list + name).
8. Not skill-cast residual — pure UI widget factory.
9. Same size/shape twin as dualed Friends pack `UI_InteractionMenu_AddFriendsToggle` (`0x0082f9a0`).

## Gaps

1. Product / MSVC name for menu host and `DAT_00d1da2c` type.
2. English for object `+0x6B4`.
3. Dual of `FUN_00573af0` / name getter `vtbl+0x160` (not OWN).
4. Runtime / bit-exact / differential.

## Artifacts

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082f8d0_FUN_0082f8d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0082f8d0_FUN_0082f8d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddIgnoreToggle.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082f8d0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_0082f8d0_FUN_0082f8d0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0082f8d0_UI_InteractionMenu_AddIgnoreToggle.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0082f8d0_UI_InteractionMenu_AddIgnoreToggle.md` |
| Report | `docs/agents/task-dual-ab-0082f8d0-mega-074-report.md` |

## Related (not OWN)

| VA | Name / role |
|---|---|
| `0x0082fe20` | `UI_InteractionMenu_PopulateTargetButtons_Inferred` (parent, dualed) |
| `0x0082f9a0` | `UI_InteractionMenu_AddFriendsToggle` (sibling pack, dualed MEGA-075) |
| `0x0082fb30` | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (sibling pack) |
| `0x00573af0` | Ignore-list name lookup (undualed) |
