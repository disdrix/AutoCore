# Review B (skeptical / adversarial): `aa_0082fa60` UI_InteractionMenu_AddClanInviteOrKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fa60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_0082fa60_UI_InteractionMenu_AddClanInviteOrKick_Inferred.md` |
| **Agent** | MEGA-076 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on CF/role; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is skill-cast / HB residual math (skills-abilities core) | **Falsified as cast** — pure UI button create; social pack child of `PopulateTargetButtons` |
| 2 | Same ABI as convoy sibling (`ESI` host + `EDX` target) | **Falsified** — clan pack uses **EAX** target + **EBX** host (`MOV ESI,EAX`; parent `MOV EBX,ESI` / `MOV EAX,EBP`) |
| 3 | Standard `__thiscall` ECX=this | **Falsified** — no ECX formal; helper sets `ECX=EBX` only at call; `ret` not `ret 4` |
| 4 | Always creates both Invite and Kick | **Falsified** — exclusive branches; at most one store |
| 5 | Kick requires same-clan membership check in this unit | **Unproven / open** — CF only compares `+0x24` on two lookup results; no pointer-equality or clan-id compare |
| 6 | `FUN_004c22a0` this = target object | **Falsified** — `MOV ECX,[DAT_00d1da30]` before both CALLs |
| 7 | `+0x6B4` is definitely character level | **Unproven** — numeric gate only; shared with convoy pack |
| 8 | Plate XML proves product UI class name | **Unproven for class** — only widget resource; role from Invite/Kick **Clan** English |
| 9 | Product name retail-known | **Unproven** — `_Inferred` required |
| 10 | Runtime Confirmed | **Rejected** — no Launcher; Terminal false |
| 11 | Ghidra `void FUN_0082fa60(void)` signature is complete | **Falsified as complete** — register args EAX/EBX are real; decompiler phantom `in_EAX`/`unaff_EBX` |
| 12 | Merge with convoy pack as one function | **Falsified** — separate VA, ids (`0x11173/4` vs `0x11171/2`), slots (`+0x548/54C` vs `+0x540/544`), different membership path (clan table vs crew `+0xCB0`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Invite/Kick exclusive branch | **Confirmed** | Wrong menu UX |
| Button ids + strings | **Confirmed** | Wrong net/UI id map |
| Slots +0x548 / +0x54C | **Confirmed** | Host layout mismatch |
| Clan table via DAT_00d1da30 | **Confirmed** | Wrong lookup host |
| EAX target / EBX host ABI | **Confirmed** | Port register smash |
| Rank field `+0x24` English | **Open** | Mis-named rank/authority |
| Same-clan on kick | **Open** | Extra kick button across clans |
| Product class name | **Inferred** | Naming only |

---

## 3. Cross-check

```
FUN_0082fe20 (dualed PopulateTargetButtons):
  resolves target TFID → EBP; ESI = menu host
  pack order A: … Trade, Clan(0082fa60), Convoy(0082fb30), Name
  pack order B: Name, Convoy, Clan(0082fa60), Trade …
  before Clan: MOV EBX,ESI ; MOV EAX,EBP ; CALL 0082fa60

FUN_004c22a0 (raw):
  thiscall scan this+0x1E4 vector for (*e==k0 && e[1]==k1)

FUN_0082f7d0 (raw):
  host.vtbl+0x444(xml, flags, id, -1); optional btn.vtbl+0x1D8 setText

Convoy sibling 0082fb30 (dualed):
  crew path +0xCB0 / ContainsMember / leader disable — NOT used here
```

**Attack on “Invite when target already clanned”:** invite arm requires `targetClan == 0` after lookup; kick arm only when targetClan non-null.

**Attack on “anyone can invite”:** invite also requires `localClan+0x24 >= 2` (threshold 2).

**Attack on “this is convoy mis-tagged”:** strings are `"Invite To Clan"` / `"Kick From Clan"` (`read_memory`); ids and slots disjoint from convoy dual.

---

## 4. Residual risks

- Parent register contract (EAX/EBX) is fragile if a different caller appears — currently **only** `FUN_0082fe20` (2 sites).
- `FUN_004c22a0` / `FUN_0082f7d0` not OWN-dualed; helper setText param map in decompiler is noisy — call-site strings/ids sealed regardless.
- Kick without explicit same-clan check may be incomplete product logic or rank fields only meaningful in-clan — leave open, do not invent.
- Partition system tag is skills-abilities (parent residual); behavioral system is **interaction-menu social UI**.

**Verdict:** **accept-with-gaps** — no CF reject; adversarial misroles falsified.
