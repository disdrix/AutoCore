# Review B (skeptical / adversarial): `Client_CastAfterPrompt` @ `0x00941ac0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941ac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00941ac0_Client_CastAfterPrompt.md` |
| **Residual scratch** | `reviews/a_00941ac0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | skillId is a stack formal | **Falsified** — only stack formal is aim*; skill from `*(client+0x30c0)` |
| 2 | Client in EAX like RequestCast entry | **Falsified for this unit** — client in **EDI**; EAX loaded from EDI for callees |
| 3 | Always sends 0x2030 | **Falsified** — CastBlock nonzero skips RequestCast |
| 4 | Clears prompt only on success | **Falsified** — Prompt(-1,0) runs on both arms |
| 5 | `+0x30c0` is UI-only and not re-read for cast | **Falsified** — sole skill source for this complete path |
| 6 | TFID comes from client selection slot only | **Narrowed** — callers pass `obj+0x160`; body trusts ESI |
| 7 | Same as CastSkillFromQuickBarSlot | **Falsified as identity** — sibling enters prompt or packs TFID/aim itself; this unit only completes pending |
| 8 | `DAT_00d1d900` is a distinct mode enum | **Falsified as distinct storage** — it **is** `client+0x30c0` absolute on singleton |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pending skill → RequestCast skill arg | **Confirmed** | Cast wrong skill after target pick |
| Clear always after pick-complete | **Confirmed** | Sticky target-select cursor |
| CastBlock skip send | **Confirmed** | Send while dead/town/etc. |
| ESI TFID 16B from pick | **Confirmed** | Wrong target seed |
| Aim ptr required | **High** | Resolve/aim packet zeros |
| Name `Client_CastAfterPrompt` | Medium (role) | Doc only |
| Second caller `FUN_00861680` semantics | Medium | Miss alternate complete path |

---

## 3. Cross-check against raw + asm + siblings

```
// enter (CastSkillFromQuickBarSlot) — NOT this unit
MOV  EAX, skillId
PUSH 1
PUSH client          // ESI there
CALL Prompt          // stores +0x30c0

// complete (this unit) — InteractClickPickTarget
CMP  DAT_00d1d900, -1
JZ   use_object_path
LEA  ESI, [selected + 0x160]
MOV  EDI, &DAT_00d1a840
PUSH &DAT_00d1a640
CALL Client_CastAfterPrompt
// → RequestCast(*(EDI+0x30c0), *ESI…) if CastBlock==0
// → Prompt(EDI, 0) EAX=-1

// ESC — does NOT call this unit
OR   EAX, -1
PUSH 0
PUSH &DAT_00d1a840
CALL Prompt
```

Raw decompile’s `unaff_ESI` / `unaff_EDI` are **real** register formals (not phantoms): both call sites set them immediately before `CALL`. Contrast RequestCast residual where some `unaff_*` were true phantoms.

RequestCast `RET 0x18` (annotated + epilogue bytes) matches six stack dwords (skill + TFID×4 + aim). Client remains EAX→EDI inside RequestCast.

---

## 4. Surviving contract for AutoCore

```
// After skill target-select prompt is active (client.pendingSkillOrMode != -1):
// on world click that resolves a target object:
if (castBlocked) { clearPrompt(); return; }
RequestCastSkill(
  skillId = client.pendingSkillOrMode,   // +0x30c0
  targetTfid = object.tfid,              // +0x160
  aim = defaultAimBuffer);
clearPrompt();                           // pending = -1
```

**Do not** require the skill id on the click message — it is session state on the client object.  
**Do** clear pending even when local cast-block feedback fires.

---

## 5. Open questions (post-dual)

1. Exact aim buffer authorship (`DAT_00d1a640` vs `00d1a660`) under each caller.
2. Whether multi-mode values `{0,2,3,4,5}` can reach this unit (gate is `!= -1`; skill path expected for RequestCast lookup).
3. Rename in Ghidra still pending (`FUN_00941ac0` → `Client_CastAfterPrompt`).
4. Runtime packet capture of complete-after-prompt vs quick-bar immediate cast.

**Verdict:** Adversarial pass does **not** overturn `+0x30c0` → RequestCastSkill seal. **accept-with-gaps.**
