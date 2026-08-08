# Function record: UI_InteractionMenu_AddFriendsToggle

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082f9a0` |
| **Canonical name** | `UI_InteractionMenu_AddFriendsToggle` |
| **Ghidra name** | `FUN_0082f9a0` |
| **Address** | `0x0082f9a0`–`0x0082fa58` inclusive |
| **Body size** | **185 B** (`0xB9`); pad `CC` after |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | interaction menu / social UI (partition skills-abilities residual) |
| **Agent** | MEGA-075 OWN-ONLY dual |
| **Date** | 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

---

## Purpose

**Interaction-menu friends button pack.** For menu host (EDI) and target object (EAX), create either **Add to Friends** (`0x11177`) or **Remove from Friends** (`0x1117a`) using plate `i_m_int_2d_btn_generic.xml`, store the button on the host at `+0x558` / `+0x564`. Membership via `FUN_00573a30` name lookup on `DAT_00d1da2c`.

## Signature

```c
// EAX = target object*; EDI = menu host*; ret 0 (C3)
void UI_InteractionMenu_AddFriendsToggle(/* parent regs */);
```

## Sealed facts

1. Live decompile ≡ frozen raw CF (2026-08-05 ≡ 2026-07-23).
2. Entry `cmp [eax+0x6b4],1` — EAX is target.
3. Parent `FUN_0082fe20` sets `MOV EDI,ESI` (host) and `MOV EAX,EBP` (owner/target) before both call sites.
4. Exclusive toggle: friends-list hit → Remove + early return; else Add.
5. Button ids `0x11177` / `0x1117a`; strings sealed via `read_memory`.
6. Slots host `+0x558` (Add), `+0x564` (Remove).
7. Direct callee only `FUN_00573a30` (thiscall list + name).
8. Not skill-cast residual — pure UI widget factory.

## Gaps

1. Product / MSVC name for menu host and `DAT_00d1da2c` type.
2. English for object `+0x6B4`.
3. Dual of `FUN_00573a30` / name getter `vtbl+0x160` (not OWN).
4. Runtime / bit-exact / differential.

## Artifacts

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082f9a0_FUN_0082f9a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0082f9a0_FUN_0082f9a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddFriendsToggle.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082f9a0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_0082f9a0_FUN_0082f9a0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0082f9a0_UI_InteractionMenu_AddFriendsToggle.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0082f9a0_UI_InteractionMenu_AddFriendsToggle.md` |
| Report | `docs/agents/task-dual-ab-0082f9a0-mega-075-report.md` |

## Related (not OWN)

| VA | Name / role |
|---|---|
| `0x0082fe20` | `UI_InteractionMenu_PopulateTargetButtons_Inferred` (parent, dualed) |
| `0x0082fb30` | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (sibling pack) |
| `0x0082f8d0` | Ignore toggle twin (residual) |
| `0x00573a30` | Friends-list name lookup (undualed) |
