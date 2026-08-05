# Review B (skeptical / adversarial): `Client_RequestCastSkill` @ `0x00941590`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual refresh) |
| **Counterpart** | `reviews/A_aa_00941590_Client_RequestCastSkill.md` |
| **Residual** | `reviews/a_00941590.md` |
| **Verdict** | **accept-with-gaps** — layout + register residuals sealed; runtime still open |

---

## 1. Claims under attack

| # | Claim | Attack result (2026-07-29) |
|---|---|---|
| 1 | This is the only path that sends `0x2030` | **Still overstated** — QB activate is a parallel packer (architecture, not CF bug) |
| 2 | Server receives skill id from `+0x18` | **Survives via asm** — store from stack `nSkillId`; decomp omission was false negative |
| 3 | Optimistic HB always starts | **Falsified** — gated by world `+0x7e`, binding validity, `skill+0x61c` |
| 4 | Validate non-zero means cast success | **Falsified** — `0` is success path; non-zero formats failure |
| 5 | Client is a stack argument in retail | **Falsified** — retail `EAX` → `EDI`; clean first-arg is readability modeling |
| 6 | `unaff_EBX` / `unaff_retaddr` are live inputs | **Falsified** — asm shows no HB 4th arg; FX arg2 = skill id |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode/size 0x2030 / 0x28 | High | Wrong wire header |
| TFID + aim packing | High | Wrong target |
| skillId @ +0x18 content | **Confirmed** (asm) | Server mis-parse skill |
| Local validate gate | High | Spam casts / silent fail |
| HB optimistic vs S2C status effect | High (gated) | Double CD start |
| `client+0xe04` type name | Medium | Doc-only |

---

## 3. Surviving contract for AutoCore

```
RequestCastSkill (C2S 0x2030, 0x28):
  client (EAX) validates skill rank + LocalCastValidate==0
  ResolveCastTarget(seed TFID args → scratch out); abort if invalid
  optional optimistic cast-again HB (thiscall entity, skill, chargeMs)
  pack: +0 opcode, +8 TFID16, +0x18 nSkillId, +0x1C aim float3
  Client_SendSectorPacket(client, 0x28, pkt); QB UI; tip 0x23
On validate fail: chat message only (no send)
```

---

## 4. Open questions

1. ~~Confirm skillId dword store at `+0x18`~~ **Closed** (asm residual).
2. ~~Recover `hbExtra` / FX register sources~~ **Closed** (phantoms / skill id).
3. Relationship of this unit vs QuickBarActivateSkillSlot — **documented dual builders**; both valid.
4. Runtime packet dump still optional proof.
5. Product name for `client+0xe04` object.

**Verdict:** Safe client cast-intent map; WI-SKL-001 skillId sealed for this path. **accept-with-gaps.**
