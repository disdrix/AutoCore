# Review B (skeptical / adversarial): `aa_0082fe20` UI_InteractionMenu_PopulateTargetButtons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fe20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0082fe20_UI_InteractionMenu_PopulateTargetButtons_Inferred.md` |
| **Agent** | WQ9E-D OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on CF/role; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is skill-cast residual math | **Falsified** — pure UI button populate; child strings Invite/Kick/Tell/Trade |
| 2 | Always builds convoy buttons only | **Falsified** — seven packs; convoy is one child (`FUN_0082fb30`) |
| 3 | Both pack orders are identical | **Falsified** — `vtbl+0x478` selects reverse order (call sites) |
| 4 | Direct CALL callers exist | **Falsified as CALL** — sole xref is **DATA** vtbl slot `0x00a720e0` |
| 5 | Standard stdcall with stack args | **Falsified** — `mov esi,ecx`; children use parent-preserved regs; `ret` not `ret N` |
| 6 | Builds buttons when target is local player | **Falsified** — owner probe / affinity / null-local gates skip pack |
| 7 | Product name retail-known | **Unproven** — `_Inferred` |
| 8 | Runtime Confirmed | **Rejected** — no Launcher |
| 9 | `FUN_0082d2b0` is the button factory | **Falsified** — shell rebuild; packs are separate callees |
| 10 | Decompiler void return hides EAX payload | **Unproven / low risk** — no EAX store before rets; role is void populate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Host thiscall + `+0x4C0` gate | **Confirmed** | Wrong menu activation |
| TFID resolve + skip-self | **Confirmed** | Self-menu spam / null deref |
| Dual pack order | **Confirmed** | UX button order |
| Convoy child dual attachment | **Confirmed** | Orphan convoy buttons |
| Vtbl dispatch | **Confirmed** | Looking for CALL xrefs fails |
| Product English | **Inferred** | Rename only |
| Affinity/owner vtbl product meaning | Open | Edge-case gates |

---

## 3. Cross-check

```
FUN_0082fb30 (dualed child):
  ESI=host, EDX=target; Invite/Kick; called from this unit ×2
FUN_0082f810 / f8d0 / f9a0 / fa60 / fc40 / fd50:
  sibling packs with Tell/Ignore/Friends/Clan/Trade/name strings
DAT_00d1b6d8:
  local player — same global as child dual disable path
aa_00520330 / +0xCB0:
  crew host back-link read by convoy child (not written here)
```

**Attack on “parent is only convoy”:** seven distinct packs; convoy is one of two order positions.

**Attack on “no xrefs ⇒ dead code”:** DATA vtbl slot proves virtual method surface; children are live dualed/undualed workers.

---

## 4. Residual risks

- Register contract for children (ESI/EDI/EBX/EDX/EAX) is parent-set and fragile if ported as pure C thiscall-only.
- `FUN_0090d400` close path uses unaff registers — not OWN; do not over-claim.
- Not cast-manager residual — matrix should tag **UI / interaction menu**.

**Verdict:** **accept-with-gaps** — no CF reject.
