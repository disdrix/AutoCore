# Skeptical / adversarial review: `Client_RequestCastSkill` @ `0x00941590`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941590` |
| **Review type** | Skeptical / adversarial (try to falsify current interpretation) |
| **Date** | 2026-07-23 |
| **Scope** | Cast-send unit and claims attached across RE artifacts / topic extraction |
| **Verdict** | **needs-more-evidence** |

**Generic approval is insufficient.** This review is not a rubber stamp. Concrete checks performed are listed in §8.

---

## 1. What was inspected

### Primary unit artifacts

| Path | Role |
|------|------|
| `docs/reconstruction/raw/aa_00941590_Client_RequestCastSkill.md` | Immutable decompile |
| `docs/reconstruction/raw/aa_00941590_Client_RequestCastSkill.annotated.md` | Scaffold notes |
| `docs/reconstruction/reconstructed-exact/Client_RequestCastSkill.cpp` | Clean port surface |
| `docs/reconstruction/functions/aa_00941590_Client_RequestCastSkill.md` | Record / confidence |
| `docs/reconstruction/systems/skills-abilities.md` | System map entry |
| `docs/topic-extractions/skill-cast.md` | Packet layout, HB, status codes |

### Cross-check / attack surfaces

| Path | Why |
|------|-----|
| `reconstructed-exact/Client_CastSkillFromQuickBarSlot.cpp` | Sole named caller into RequestCast |
| `reconstructed-exact/Client_QuickBarActivateSkillSlot.cpp` | Parallel `0x2030` builder (does **not** call this unit) |
| `reconstructed-exact/Skill_LocalCastValidate.cpp` | Validate callee signature chaos |
| `docs/topic-extractions/skill-cast.md` | Layout table vs body stores |

**Not performed:** fresh Ghidra re-decompile, CE send capture, instruction dump of packet stores.

---

## 2. Evidence used

### A. Authoritative body (raw) — mechanical facts

1. Hidden client base via `in_EAX` (not a formal parameter).
2. Skill object from entity chain vtable `+0x234(nSkillId)`; require `skill+0x5f6 != 0`.
3. Validate must return `0` to continue.
4. Target TFID from `Client_Skill_ResolveCastTarget`; invalid TFID aborts send.
5. If `*(client+0xe04)+0x7e == 0` and no active cast binding and `skill+0x61c == 0` → `Skill_StartCastAgainHeartbeat` with charge delay `skill+0x14`.
6. Buffer tagged `0x2030`, sent with size `0x28` via `Client_SendSectorPacket`.
7. Failure path formats message; may UI-log and return.

### B. Topic extraction claims under attack

- Layout: `+0 opcode, +4 pad, +8 TFID16, +0x18 skillId, +0x1C aim float3`
- Optimistic CD HB type 8 before send
- `bIsItemSkill` / source TFID rules apply to **inbound** `0x2031`, not this outbound builder

### C. Negative evidence

- No formal `this` in signature.
- No explicit `skill+0x5fc` write into the send buffer in this decompile (unlike QB activate path).
- `unaff_*` args into HB / vtable calls.

---

## 3. Attack results (claim-by-claim)

### Claim 1 — Function is the sole / canonical C2S cast sender

| Sub-claim | Attack result |
|-----------|----------------|
| Named entry for player cast send | **Survives** as *a* sender |
| Sole path | **BROKEN.** `Client_QuickBarActivateSkillSlot` independently packs `0x2030` size `0x28` and sends via sector connection vtable `+0x18` without calling this unit |
| “Also QB builder …” plate wording | **Misleading.** QB activate is a **sibling**, not a wrapper around RequestCast |

**Severity:** High for architecture docs that funnel all casts through RequestCastSkill.

---

### Claim 2 — Packet layout WI-SKL-001 is sealed by this body

| Sub-claim | Attack result |
|-----------|----------------|
| Opcode `0x2030` | **Not broken** |
| Size `0x28` | **Not broken** (send arg) |
| `+8` TFID 16B | **Probable** — four dwords from resolve into contiguous stack slots |
| `+0x1C` aim float3 from `pAimPos` | **Probable** — three dwords from `pvVar6` at `uStack_120..118` (~`+0x1C` from buffer base) |
| `+0x18` skillId = stack skill arg / skill+0x5fc | **ATTACKED / not sealed.** Body overwrites `nSkillId` with TFID dword0 after resolve; no later `skill+0x5fc` store into the buffer is visible. QB path explicitly writes `skill+0x5fc` at `+0x18`. This unit’s decompile does **not** show the same store |

**Alternate readings:**

1. Ghidra merged stack slots and lost the skill-id store (common).
2. `nSkillId` was never the WAD skill id (lookup key only) and skill id is recovered elsewhere — but then plate text is wrong.
3. Layout plate was reverse-engineered from QB path and **projected** onto this function.

**Severity:** Critical for any port that packs from this reconstruction alone.

---

### Claim 3 — Optimistic cast-again HB always runs before send

| Sub-claim | Attack result |
|-----------|----------------|
| HB before send when gates open | **Not broken** for the gated path |
| Always | **BROKEN.** Skipped when `world+0x7e != 0`, when active binding TFID is valid, or when `skill+0x61c != 0` |
| Identity of `client+0xe04` as “world/sim” | **Unproven** — offset only; name is narrative |
| Duration formula (CD × vehicle modifier + charge) | **Not in this body** — lives in `Skill_StartCastAgainHeartbeat` |

---

### Claim 4 — `Skill_LocalCastValidate` call is signature-correct

| Sub-claim | Attack result |
|-----------|----------------|
| Call present; success == 0 | **Not broken** |
| Args `(entity, 0, (char)skill, 0)` are correct retail args | **BROKEN as a sealed ABI.** Truncating skill pointer to `char` is a decompiler signature failure. Skill_LocalCastValidate body treats a later formal as a full skill pointer (`+0x5fc`, `+0x628`, …) |

Cross-unit contamination: this caller cannot be used to seal LocalCastValidate’s prototype without assembly.

---

### Claim 5 — Function owns full cast validation semantics

| Sub-claim | Attack result |
|-----------|----------------|
| Local pre-check via LocalCastValidate | **Not broken** |
| Range / target legality fully enforced here | **Falsified.** Target resolve can fail only as invalid TFID; deeper range/target codes are inside validate/range helpers, not re-checked at send |
| Server authority | Correctly **not** claimed by body (send-only after optimistic local checks) |

---

### Claim 6 — Naming / plate “Confirmed”

| Name | Warranted? | Attack |
|------|------------|--------|
| `Client_RequestCastSkill` | Working name OK | Acceptable if Ghidra/session symbol |
| WI-SKL-001 “Confirmed” layout | **Overclaim for this unit** | Opcode/size strong; skill-id slot weak |
| `pOwnerCtx` as skill runtime | Probable | Offsets `+0x5f6/+0x5fc/+0x14/+0x61c` consistent with skill object elsewhere |
| Function record “Partial scaffold” | Honest | Holds |

---

## 4. Alternate interpretations

### 4.1 Minimal hard-to-attack reading

```
// client in EAX (or hidden this)
// if skill lookup+rank ok and LocalCastValidate==0 and resolved TFID valid:
//   maybe StartCastAgainHeartbeat
//   maybe charge UI
//   send 0x28-byte sector message starting with 0x2030
// else maybe format failure string
```

### 4.2 What is not proven

- Single canonical send path for all player casts.
- Exact byte map of all 0x28 payload fields from *this* decompile alone.
- World/sim flag object type at `+0xe04`.
- Correct C++ prototype for ports.

---

## 5. What was confirmed despite skepticism

1. Opcode constant `0x2030` and send size `0x28`.
2. Local validate gate before send; failure formats a message.
3. Optimistic HB is conditional and pre-send when gates pass.
4. Invalid TFID aborts the send path.
5. Parallel QB activate path exists and is independent.
6. Clean C++ did not invent extra modern structure beyond raw.

---

## 6. Critical contradictions found

### C1 — Two independent `0x2030` builders

RequestCastSkill (this unit) vs QuickBarActivateSkillSlot: different client base recovery, different send API, different skill-id store visibility, different aim handling. System map lists both as “request cast” family without stating divergence.

### C2 — Layout plate vs visible skill-id store

Topic extraction + function plate assert `+0x18 = skillId`. This body does not show that store after clobbering `nSkillId`. QB path does. **Cannot seal layout from this unit alone.**

### C3 — LocalCastValidate ABI vs call site

Call site truncates skill to `char`; callee body uses skill-sized offsets on a differently named formal. Shared decompiler failure across the cast graph.

### Body CF contradictions

**None** that overturn: “validate 0 → resolve → maybe HB → pack 0x2030 → send 0x28” as the success spine.

---

## 7. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | Formal `this` / calling convention | Yes for clean port API |
| R2 | Skill-id field packing in this buffer | Yes for WI-SKL-001 seal |
| R3 | `+0xe04` / `+0x7e` object identity | Yes for sim/server mode story |
| R4 | `unaff_*` real values into HB/FX | Yes for charge UI parity |
| R5 | Runtime packet bytes | Yes for any “Confirmed complete” |
| R6 | Whether Ghidra lost stores | Yes — needs asm or CE |

---

## 8. Concrete checks performed

1. Re-derived success/failure spine from raw alone.
2. Mapped stack names to claimed layout offsets for opcode, TFID, aim.
3. Searched body for `0x5fc` skill-id write into send buffer — **absent**.
4. Compared to QB activate path for skill-id and send API divergence.
5. Compared LocalCastValidate call args to LocalCastValidate body formals.
6. Verified HB gates (`+0x7e`, binding invalid, `+0x61c`) in raw text.
7. Checked clean for invented branches — none.
8. Checked function record for over-completion — none (scaffold).

**Not done:** live packet dump; asm of stack stores; re-decompile.

---

## 9. Verdict

### **`needs-more-evidence`**

**Why not `no-critical-contradiction`:**  
The interpretation package oversells a sealed packet layout and a single cast-send funnel. Skill-id packing in *this* decompile is not evidenced; dual `0x2030` builders diverge; LocalCastValidate ABI is corrupted at the call site.

**Why not `critical-contradiction`:**  
Opcode, size, validate gate, conditional HB, and send call are not overturned as CF.

### Acceptance bar later

1. Asm or CE dump of the 0x28 payload for a RequestCastSkill send (skill id slot).
2. Recover formal client `this` and HB/FX args.
3. Document dual-path architecture (RequestCast vs QuickBarActivate) in system map.
4. Fix or explicitly demote LocalCastValidate prototype using assembly.

### Port guidance (adversarial)

- Do **not** implement only RequestCastSkill and delete QB activate packing.
- Do **not** trust `+0x18 skillId` from this unit’s decompile alone — cross-check QB path / CE.
- Do **not** treat `in_EAX` / `unaff_*` as sealed ABI.
- Do **preserve** conditional optimistic HB gates.

---

## 10. Summary table (attack scorecard)

| # | Claim | Result |
|---|-------|--------|
| 1 | Sole cast sender | **Fails** (sibling QB path) |
| 2 | Full WI-SKL-001 layout sealed here | **Opcode/size hold; skillId slot fails** |
| 3 | HB always before send | **Fails** (gated) |
| 4 | LocalCastValidate call ABI | **Decompiler-broken** |
| 5 | Full validation ownership | **Overclaim** |
| 6 | Naming / Confirmed plate | **Partial overclaim** |

**Final verdict: `needs-more-evidence`**
