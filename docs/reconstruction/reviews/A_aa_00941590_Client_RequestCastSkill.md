# Review A (reconstruction fidelity): `aa_00941590` Client_RequestCastSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941590` |
| **VA** | `0x00941590` |
| **Canonical name** | `Client_RequestCastSkill` |
| **Review date** | `2026-07-29` (residual refresh) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00941590_Client_RequestCastSkill.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00941590_Client_RequestCastSkill.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RequestCastSkill.cpp` |
| Prior dual | `aa_00941590_reconstruction_review.md` / `aa_00941590_skeptical_review.md` |
| Residual scratch | `reviews/a_00941590.md` |
| Caller | `Client_CastSkillFromQuickBarSlot.cpp` / `FUN_00941ac0` |
| Resolve | `Client_Skill_ResolveCastTarget` (seed TFID in, scratch out) |
| System | `docs/reconstruction/systems/skills-abilities.md` |

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| C2S `0x2030` size `0x28` | **High** | WI-SKL-001 / send call |
| Guard `+0xe98`, skill vtbl `+0x234`, rank `+0x5f6` | **High** | Early returns |
| `Skill_LocalCastValidate` then resolve TFID | **High** | Success branch |
| Optimistic cast-again HB when world `+0x7e==0` and `skill+0x61c==0` | **High** | CF match; asm thiscall |
| Packet pack TFID + aim + opcode | **High** | Stores preserved |
| **skillId @ `+0x18` = stack `nSkillId`** | **Confirmed** | asm residual 2026-07-29 |
| Client formalized from `EAX` → EDI | **High** | prologue `MOV EDI,EAX` |
| Failure message + chat path | **High** | `DAT_00d1b8dc` gate |
| QB UI notify `+0x10b0` / tip `0x23` | **High** | Post-send |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Outer gates + validate | **Yes** |
| Resolve / HB / charge FX | **Yes** |
| Pack + `Client_SendSectorPacket(..., 0x28, ...)` | **Yes** |
| Failure path no send | **Yes** |

---

## 4. Gaps (post-residual)

1. ~~skillId packet slot store OPEN~~ **Closed** — formal `nSkillId` @ +0x18.
2. ~~`hbExtra` / `fxArg` unaff~~ **Closed** — phantoms; HB 3-arg thiscall; FX arg2 = skill id.
3. `client+0xe04` **product type name** still open (role sealed: world/sim + `+0x7e`).
4. Runtime / CE / bit-exact still open.

**Verdict:** Cast request CF faithful; WI-SKL-001 layout sealed on this path. **accept-with-gaps.**
