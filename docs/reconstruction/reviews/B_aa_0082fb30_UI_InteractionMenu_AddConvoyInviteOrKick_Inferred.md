# Review B (skeptical / adversarial): `aa_0082fb30` UI_InteractionMenu_AddConvoyInviteOrKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fb30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0082fb30_UI_InteractionMenu_AddConvoyInviteOrKick_Inferred.md` |
| **Agent** | WQ9D-I OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on CF/role; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is skill-cast logic (WQ-009 core) | **Falsified as cast** — pure UI button create; convoy residual consumer of crew dual |
| 2 | Standard `__thiscall` ECX=this | **Falsified** — entry uses **EDX** target; ESI host; `ret` not `ret 4` |
| 3 | Always creates both buttons | **Falsified** — exclusive Invite **or** Kick branch |
| 4 | `FUN_005749d0` this = target | **Falsified** — this = `*(localPlayer+0xCB0)` crew host (peer dual + asm shape) |
| 5 | Disable means destroy button | **Falsified** — `vtbl+0xD4(0)` disable/hide; pointer still stored |
| 6 | Plate string proves full UI system name | **Unproven for class** — only widget XML; role from Invite/Kick English |
| 7 | `+0x6B4` is definitely character level | **Unproven** — numeric gate only; English open |
| 8 | Product name retail-known | **Unproven** — `_Inferred` |
| 9 | Runtime Confirmed | **Rejected** — no Launcher |
| 10 | `param_1` (ECX) is a real formal | **Likely phantom** — unused; decompiler `__fastcall` residue |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Invite/Kick exclusive branch | **Confirmed** | Wrong menu UX |
| Button ids + strings | **Confirmed** | Wrong net/UI id map |
| Slots +0x540 / +0x544 | **Confirmed** | Host layout mismatch |
| Crew membership via +0xCB0 | **Confirmed** | Always-invite bug |
| Leader disable via 00574880 | **High** | Non-leader can kick |
| ESI host convention | **High** | Port must match parent |
| `+0x6B4` product | Open | Gate edge cases |

---

## 3. Cross-check

```
FUN_0082fe20:
  resolves target TFID; if not self/local:
    builds button packs including FUN_0082fb30 twice (order depends on vtbl+0x478)
aa_005749d0:
  4×0x10 @ +0x198; callers include this unit
aa_00574760:
  (index+0x1A)*0x10 slot load — same formula body as FUN_00574880 with index from +0x194
```

**Attack on “Invite when already in crew”:** branch requires `ContainsMember` true for Kick path; Invite only when host null or not member.

**Attack on “Kick available to all members”:** both branches can disable when `FUN_00574880() != localPlayer`.

---

## 4. Residual risks

- Parent register contract (ESI) is fragile if inlined differently — keep as menu-host this from `FUN_0082fe20`.
- `FUN_00574880` ECX recovery not OWN; assume crew/roster host matching `+0xCB0` family.
- Not skill-cast residual math — parent matrix should tag **UI / convoy** not cast manager.

**Verdict:** **accept-with-gaps** — no CF reject.
