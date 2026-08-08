# Review B (skeptical / adversarial): `aa_0082f810` UI_InteractionMenu_AddSendTell_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082f810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_0082f810_UI_InteractionMenu_AddSendTell_Inferred.md` |
| **Agent** | MEGA-073 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on CF/role; product host class remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is skill-cast / HB math (skills-abilities core) | **Falsified as cast** — pure UI button create; residual of interaction-menu populate parent |
| 2 | Standard `__thiscall` with ECX=this at entry | **Falsified for leaf entry** — entry uses **EDI** host; ECX only set for nested virtual create/label |
| 3 | Has stack formals / `ret 4` | **Falsified** — no stack args; epilogue `POP ESI; RET` (`C3`) |
| 4 | Creates multiple buttons / invite-kick style branch | **Falsified** — single create; only null-check branch |
| 5 | Disables button when not leader (convoy peer) | **Falsified** — no `vtbl+0xD4`; no `FUN_00574880` |
| 6 | Slot is same as convoy invite `+0x540` | **Falsified** — store is **`+0x554`** only |
| 7 | Button id is `0x11171`/`0x11172` | **Falsified** — id is **`0x11176`** |
| 8 | Caption is generic / empty | **Falsified** — exact product string **"Send a Tell"** @ `0x00a72158` |
| 9 | Decompiler `void(void)` means no this | **Falsified as ABI** — `unaff_EDI` is real host; parent installs EDI |
| 10 | Multiple independent callers | **Falsified** — sole caller `FUN_0082fe20` (2 sites, alternate order) |
| 11 | Plate string proves full UI class name | **Unproven for class** — only widget XML; role from "Send a Tell" English + parent family |
| 12 | Product name retail-known without `_Inferred` | **Unproven** — keep `_Inferred` |
| 13 | Runtime Confirmed | **Rejected** — no Launcher; Terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single create + optional label | **Confirmed** | Wrong menu UX |
| Button id `0x11176` + "Send a Tell" | **Confirmed** | Wrong net/UI id map |
| Slot `+0x554` | **Confirmed** | Host layout mismatch |
| EDI host convention | **Confirmed** | Port must match parent register contract |
| No disable / no crew gate | **Confirmed** | Over-port convoy logic |
| Product host class English | Open | Naming only |
| Create/label method product names | Open | Cosmetic |

---

## 3. Cross-check

```
FUN_0082fe20 (dualed PopulateTargetButtons):
  after target resolve + not-self gate:
    order A (vtbl+0x478==0): … f8d0, f9a0, f810, fc40, fa60, fb30, fd50
    order B (else):          … fd50, fb30, fa60, fc40, f810, f9a0, f8d0
  both paths: MOV EDI,ESI before CALL 0082f810

FUN_0082fb30 (dualed Convoy Invite/Kick peer):
  same XML plate + vtbl+0x444 / +0x1D8 pattern
  different ids 0x11171/0x11172, slots +0x540/+0x544, plus disable

aa_0082f810 (this unit):
  id 0x11176, caption "Send a Tell", slot +0x554, no disable — simpler leaf
```

**Attack on "ECX thiscall leaf":** entry bytes start `8B 07` (`MOV EAX,[EDI]`), not `MOV EAX,[ECX]`. Parent never places host in ECX for this CALL.

**Attack on "always non-null button":** store runs after JZ join with ESI possibly 0 — host slot can be null.

**Attack on "tell send network here":** body only creates/labels/stores a UI button; no packet / chat send.

---

## 4. Residual risks

- Parent register contract (EDI) is fragile if parent is re-ordered — keep as menu-host this from dualed `FUN_0082fe20`.
- Button id `0x11176` command sink not dualled here — do not invent chat-send wiring.
- Partition tags **skills-abilities** but unit is **UI / interaction menu** residual of that tree — parent matrix should not treat as cast manager.

**Verdict:** **accept-with-gaps** — no CF reject; skill-cast / thiscall-entry / multi-button / disable claims falsified.
