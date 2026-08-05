# Skeptical / adversarial review: `Client_QuickBarActivateSkillSlot` @ `0x00921b50`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921b50` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Hotbar activate unit, packet claims, relationship to RequestCastSkill |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_00921b50_Client_QuickBarActivateSkillSlot.md` | Body |
| `raw/aa_00921b50_Client_QuickBarActivateSkillSlot.annotated.md` | Scaffold |
| `reconstructed-exact/Client_QuickBarActivateSkillSlot.cpp` | Clean |
| `functions/aa_00921b50_Client_QuickBarActivateSkillSlot.md` | Record |
| `reconstructed-exact/Client_RequestCastSkill.cpp` | Sibling sender |
| `docs/topic-extractions/skill-cast.md` | Layout / HB narrative |
| `systems/skills-abilities.md` | Flow diagram |

**Not performed:** CE capture, asm of aim stores, re-decompile.

---

## 2. Evidence used

### Mechanical body

1. `nSlotIndex` is a **counting index** over skills that do **not** have `skill+0x615 & 1` set (hidden/passive filter — name unproven).
2. Validate + optimistic HB + pack/send all happen **here**, not via RequestCastSkill.
3. Skill id written from `skill+0x5fc` into packet `+0x18` region (`iStack_20`).
4. Aim region assigned from `uStack_60/5c/58` which are **never assigned** in the visible body (only `uStack_70..64` and optional vehicle override are written for the resolve *input* TFID seed).
5. Send API: connection object vtable `+0x18(0xffffffff, buf, 0x28, 0)` — not `Client_SendSectorPacket`.

### Topic extraction

Claims both this unit and RequestCastSkill call `Skill_StartCastAgainHeartbeat` before send — **supported for both** when gates pass, but send paths differ.

---

## 3. Attack results

### Claim 1 — Builds Confirmed WI-SKL-001 `0x2030` size `0x28`

| Sub-claim | Attack result |
|-----------|----------------|
| Opcode `0x2030` | **Holds** |
| Size `0x28` | **Holds** |
| `+0x18 = skill+0x5fc` | **Holds** (explicit) |
| `+8 = TFID from resolve` | **Probable** (four dwords from resolve return) |
| `+0x1C aim XYZ (often 0)` | **Weak.** Plate admits “often 0”; body copies from never-written stack slots after zeroing a different trio — could be decompiler aliasing **or** real uninitialized aim. **Not sealed** |

---

### Claim 2 — This is a thin wrapper around RequestCastSkill

| Sub-claim | Attack result |
|-----------|----------------|
| Calls RequestCastSkill | **Falsified** — zero calls |
| Same validation + HB intent | **Partial** — both call LocalCastValidate + conditional StartCastAgainHeartbeat |
| Same send path | **Falsified** — different send API and client base recovery |

---

### Claim 3 — Slot index maps 1:1 to visible quick-bar buttons

| Sub-claim | Attack result |
|-----------|----------------|
| Counter increments only for entries without `+0x615 & 1` | **Holds as CF** |
| That filter equals “shown on bar” | **Unproven** — could hide passives, items, cooldowns, unlearned, etc. |
| Index matches UI widget order | **Not evidenced** in this unit |

---

### Claim 4 — LocalCastValidate usage is ABI-correct

Same attack as RequestCastSkill: `(char)skill` truncation. **Decompiler ABI broken.** Success test `== 0` still holds as CF.

---

### Claim 5 — Failure path surfaces FormatFailureMessage

| Sub-claim | Attack result |
|-----------|----------------|
| Validate fail formats UI message | **Falsified for this unit.** On validate != 0, function simply falls through and returns — **no** `Skill_FormatFailureMessage`. RequestCastSkill *does* format. User-visible error parity between paths is **not** shared |

**Severity:** High for UX/port parity assumptions.

---

### Claim 6 — Aim is intentionally zero

| Sub-claim | Attack result |
|-----------|----------------|
| Plate “often 0” | Narrative |
| Body proves zero aim | **Not cleanly.** Zeros written then overwritten from uninit names; resolve also gets `&DAT_00d1a640` as aim argument — another aim source not copied into the packet aim slots in visible code |

---

## 4. Alternate interpretations

### Minimal reading

```
find Nth non-flagged skill on character list;
if LocalCastValidate==0:
  maybe StartCastAgainHeartbeat;
  maybe charge vtable;
  pack 0x2030 with skill+0x5fc + resolved TFID + aim?;
  send 0x28 on sector connection;
```

### Competing architecture

| Path | Validate fail UX | Send API | Skill id source |
|------|------------------|----------|-----------------|
| QuickBarActivate | Silent | conn `+0x18` | `skill+0x5fc` |
| RequestCastSkill | FormatFailureMessage | `Client_SendSectorPacket` | unclear in decompile |

---

## 5. What was confirmed despite skepticism

1. Slot-index walk with skip flag and traversal lock.
2. Opcode/size and explicit skill id store.
3. Conditional optimistic HB gated by world `+0x7e` and `skill+0x61c`.
4. Independent of RequestCastSkill.
5. Clean fidelity to raw CF.

---

## 6. Critical contradictions found

### C1 — Dual send architecture vs single “cast request” story

System map flow `QuickBarActivate / RequestCast → …` implies interchangeable fronts. Bodies show **two send implementations** with different failure UX.

### C2 — Aim “often 0” vs unresolved stack

Cannot honestly seal aim field from this decompile.

### C3 — Silent validate failure vs RequestCast messaging

Same LocalCastValidate return codes; only RequestCast formats them.

---

## 7. Residual uncertainty

| # | Item | Blocks sealing? |
|---|------|-----------------|
| R1 | Aim bytes | Yes |
| R2 | `+0x615` bit1 meaning | Yes for slot mapping |
| R3 | Global client/world objects | Yes |
| R4 | Who calls with which slot indices | Yes |
| R5 | Runtime packet | Yes |

---

## 8. Concrete checks performed

1. Confirmed no `Client_RequestCastSkill` call.
2. Confirmed `skill+0x5fc` → `iStack_20`.
3. Listed all writes to `uStack_70..58` — aim trio unassigned.
4. Compared failure UX to RequestCastSkill.
5. Verified skip condition `+0x615 & 1`.
6. Clean vs raw parity for send site.

---

## 9. Verdict

### **`needs-more-evidence`**

Opcode/size/skill-id are strong; aim, ABI, and dual-path product story are not. Silent validate failure is a real behavioral divergence from RequestCastSkill.

### Port guidance

- Implement as **standalone packer**, not RequestCast wrapper.
- Decide deliberately whether validate failures should be silent (retail-accurate) or shared messaging (product choice — document if diverging).
- Seal aim with CE/asm before trusting ground-target casts from this path.

---

## 10. Summary table

| # | Claim | Result |
|---|-------|--------|
| 1 | Full layout sealed | **Partial** (aim weak) |
| 2 | Wrapper around RequestCast | **Falsified** |
| 3 | Slot ≡ UI button | **Unproven** |
| 4 | LocalCastValidate ABI | **Broken decompile** |
| 5 | Failure messaging | **Silent here** |
| 6 | Aim intentionally zero | **Not sealed** |

**Final verdict: `needs-more-evidence`**
