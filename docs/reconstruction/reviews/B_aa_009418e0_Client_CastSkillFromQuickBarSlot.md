# Review B (skeptical / adversarial): `Client_CastSkillFromQuickBarSlot` @ `0x009418e0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009418e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual refresh) |
| **Counterpart** | `reviews/A_aa_009418e0_Client_CastSkillFromQuickBarSlot.md` |
| **Residual scratch** | `reviews/a_009418e0.md` |
| **Verdict** | **accept-with-gaps** on CF + ABI; flag **enum names** still open |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function reads a quick-bar slot index | **Falsified** — skill id only; slot→skill is ActivateSlot type-1 |
| 2 | Always fills aim from selection | **Falsified** — bit5 clear skips aim; prompt arm returns; both-flags seed path |
| 3 | Flag 0x800 means “cannot cast” | **Overstated** — 0x800+0x20 falls through to cast with invalid TFID seed |
| 4 | This is the only cast entry | **Falsified** — QuickBarActivateSkillSlot packs 0x2030; RequestCast is shared |
| 5 | Client unrecovered (`unaff_ESI`) | **Falsified residual** — ESI Confirmed; callers `MOV ESI,&DAT_00d1a840` or live client ESI |
| 6 | `FUN_0093bac0` unknown | **Falsified residual** — PromptSkillTargetSelect + string; stores skill @ `+0x30c0` |
| 7 | `FUN_0093b7f0` is “stance/gadget only” | **Narrowed** — multi-state “can’t do that while you are …” gate (dead/waiting/town/flags/enhanced) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Terminal handoff to RequestCast | High | Cast never sent |
| 0x800 clear → entity TFID aim | High | Wrong target |
| Cursor mode (0x800 set, 0x20 clear) | **High** (was Medium) | String + EAX=skillId store |
| Both flags set fall-through | Medium | Cast with invalid TFID seed |
| Client ESI | **Confirmed** | Wrong entity root |
| FUN_0093b7f0 product name | Low name / High role | Doc rename only |

---

## 3. Surviving contract for AutoCore

```
// retail: client in ESI; skillId stack; RET 4
CastSkillFromQuickBarSlot(client, skillId):
  if cast-blocked (FUN_0093b7f0 feedback) or skill missing: return
  if (skill.flags+0x614 & 0x800) == 0:
      fill TFID from selection/self; maybe aim
  else if (flags & 0x20) == 0:
      PromptSkillTargetSelect(client, show=1);  // skillId in EAX → client+0x30c0
      return
  RequestCastSkill(client, skillId, tfid…, aim)
```

---

## 4. Open questions (post-residual)

1. English enum names for `skill+0x614` bits `0x800` / `0x20` (behavior sealed).
2. Whether both-flags-set path is intentional “self/no-target cast with zero aim”.
3. Product name for `FUN_0093b7f0`.
4. Runtime coverage of all flag arms.

**Verdict:** Safe as skill-id pre-cast resolver into RequestCast; do not invent slot-index math in this body. ABI residual closed.
