# Annotated low-level: Client_RequestCastSkill (`aa_00941590`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941590` |
| **VA** | `0x00941590` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_00941590_Client_RequestCastSkill.md` (capture 2026-07-23) |
| **Related** | C2S `RequestCastSkill` `0x2030` size `0x28` (WI-SKL-001); sibling QB path `0x00921b50` |
| **Residual** | `reviews/a_00941590.md` (2026-07-29 asm seal) |

---

## 1. Corrected signature

```c
// Custom: client object in EAX (body: EDI); RET 0x18
// Stack: skill id + seed TFID (4 dwords) + aim pointer
void Client_RequestCastSkill(
    int nSkillId,          // stack arg0 — WAD/learned skill id → packet +0x18
    int tfid0, int tfid1, int tfid2, int tfid3,  // seed for ResolveCastTarget
    float* pAimPos);       // 3×f32 aim / target position (held in EBP)
// implicit: ClientContext* client in EAX (decompiler `in_EAX`)
```

| Name | Width | Origin | Role |
|---|---|---|---|
| `client` | ptr | `EAX` | Client root (`+0xe98` character link, `+0xe04` world/sim, `+0x10b0` QB UI) |
| `nSkillId` | i32 | stack arg0 | Lookup key; **packed at +0x18** (not clobbered) |
| `tfid0..3` | i32×4 | stack arg1..4 | Seed TFID; resolve reads these; equals/pack use resolve **out** |
| `pAimPos` | ptr | stack arg5 | Aim XYZ for packet `+0x1C` |

Decompiler `unaff_EBX` / `unaff_retaddr` are **phantoms** (asm residual 2026-07-29): HB is 3-arg thiscall; FX arg2 = `nSkillId`.

---

## 2. Packet layout C2S `0x2030` (size `0x28`) — Confirmed

| Offset | Size | Field |
|---|---:|---|
| `+0x00` | 4 | msgId = `0x2030` |
| `+0x04` | 4 | pad (unset) |
| `+0x08` | 16 | target TFID (resolve out) |
| `+0x18` | 4 | skillId = formal **`nSkillId`** (asm Confirmed) |
| `+0x1C` | 12 | aim `float3` from `pAimPos` |

Sent via `Client_SendSectorPacket(client, 0x28, buf)`.

---

## 3. Control flow

```text
character = client+0xe98
if character == 0 → return

pSkill = character->vtbl+0x234(nSkillId)     // lookup learned/runtime skill
if pSkill == 0 OR (i16)(pSkill+0x5f6) == 0 → return   // rank must be nonzero

rc = Skill_LocalCastValidate(character_interior, 0, pSkill, 0)
if rc != 0:
    msg = Skill_FormatFailureMessage(rc, stackbuf, character_or_null)
    if DAT_00d1b8dc: UI toast FUN_008f8200(...); return
    return

// third arg is &seedTfid (arg1), NOT &nSkillId — decomp mislabeled
tfid = Client_Skill_ResolveCastTarget(scratch, pSkill, &tfid0, pAimPos, 1)
if TFID_EqualsObjectId(tfid, g_abTfidInvalid_A15870): return   // no target

// Optimistic cast-again heartbeat (hotbar CD) — skip when world+0x7e != 0
if *(client+0xe04)+0x7e == 0:
    if no active cast binding for skillId(pSkill+0x5fc)
       AND Skill_ClearActiveCastCounterAndQueueId(skillId)
       AND (pSkill+0x61c) == 0:
        Skill_StartCastAgainHeartbeat thiscall(entity, pSkill, chargeMs=pSkill+0x14)

// Activating VFX / float text when charge (pSkill+0x14) > 0 and no binding
if (i16)(pSkill+0x14) > 0 and no active binding:
    character->vtbl+0x238(3, nSkillId, rank+bonus, /*charge*/0, 0,0,0,0)
    FUN_007fb690(..., chargeMs * g_flMsToSeconds, pSkill+0x184, "...Activating Skill...", ...)

// Build & send 0x2030 (+0x18 = nSkillId)
packet = { 0x2030, pad, tfid×4, skillId, aim×3 }
Client_SendSectorPacket(client, 0x28, packet)

// Quick-bar UI notify
qb = client+0x10b0
if qb && qb->vtbl+0x3d8(): qb->vtbl+0x450(pSkill)

// First-time tip 0x23 if skill has cost/range-ish fields set
if pSkill+8>0 OR pSkill+0x44>0 OR pSkill+0xA>0:
    Client_MaybeShowFirstTimeTip(0x23)
```

---

## 4. Side-effect order (success path)

1. Read character / skill rank.
2. Local validate (no write).
3. Resolve target TFID (may read world selection).
4. **Maybe** clear cast counter + **start cast-again heartbeat** (optimistic CD) — **before** network send.
5. Optional activating UI string / VFX.
6. **Send** sector packet `0x2030`.
7. QB widget callback `+0x450`.
8. Optional tip.

Failure path: format message + optional UI only; **no** packet, **no** heartbeat.

---

## 5. Field map

| Offset | Object | Role |
|---|---|---|
| `client+0xe98` | client | character entity root |
| `client+0xe04` | client | world; `+0x7e` suppresses optimistic HB |
| `client+0x10b0` | client | quick-bar UI object |
| `pSkill+0x5f6` | skill | rank (i16); must be ≠ 0 |
| `pSkill+0x5fc` | skill | skill id |
| `pSkill+0x14` | skill | charge delay ms (i16) |
| `pSkill+0x174` | skill | rank bonus for display level |
| `pSkill+0x61c` | skill | blocks StartCastAgain when nonzero |
| `pSkill+0x184` | skill | UI string slot for activating text |
| `pSkill+0x8` / `+0xA` / `+0x44` | skill | tip gating (cost / related) |

---

## 6. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `in_EAX` unnamed | **Client context** register arg | **High** |
| `LocalCastValidate(..., (char)pOwnerCtx, ...)` | Third arg is **skill pointer**, not char | **High** |
| `unaff_retaddr` into vtbl+0x238 | Stack/register pollution; treat display args as incomplete | **Open** |
| World `+0x7e == 0` → allow HB | When **sim/server-like** flag set, HB comes from inbound `0x2031` instead | **High** (topic) |

---

## 7. Open questions

- Precise ABI (is EAX always client, or is there a hidden `this`?).
- Full meaning of `pSkill+0x61c` (item skill vs other).
- Relationship of stack args a2–a5 before resolve (legacy TFID in/out).
