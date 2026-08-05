# Function record: Client_RequestCastSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941590` |
| **Canonical name** | `Client_RequestCastSkill` |
| **Address** | `0x00941590` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual 2026-07-29** — CF + WI-SKL-001 skillId store sealed (asm); runtime/diff open |

---

## 1. Summary

Player cast intent path. Looks up skill on local entity, runs `Skill_LocalCastValidate`, resolves cast target TFID, optionally starts optimistic cast-again heartbeat, sends **C2S 0x2030** size `0x28` (skill id + TFID + aim), updates quick-bar UI, maybe first-time tip `0x23`. On validate failure, formats and toasts a failure string.

---

## 2. Signature

```c
// retail: client in EAX at entry; RET 0x18 (6 stack args)
void Client_RequestCastSkill(
    int nSkillId,                 // → packet +0x18
    int tfid0, int tfid1, int tfid2, int tfid3,  // seed TFID for ResolveCastTarget
    void* pAimPos);               // float3; held in EBP
// client object in EAX (body uses EDI)
```

---

## 3. Packet 0x2030 (WI-SKL-001 Confirmed)

| Off | Field | Source on this path |
|---:|---|---|
| +0x00 | `msgId = 0x2030` | imm store |
| +0x04 | pad | unset |
| +0x08 | target TFID 16B | resolve out (EBX + stack copies) |
| +0x18 | skillId | **formal `nSkillId`** (asm Confirmed 2026-07-29) |
| +0x1C | aim float3 | `pAimPos` |

Prior decomp gap (no visible +0x18 store) closed via pack-site asm: `MOV` from skill-id arg home into packet slot after TFID/aim stores. Resolve’s third arg is `&tfid0` (seed), not `&nSkillId`.

---

## 4. Behavior outline

1. Require `client+0xe98` entity root; lookup skill via entity `vtbl+0x234(nSkillId)`; require rank `skill+0x5f6 != 0`
2. `Skill_LocalCastValidate(entity, 0, pSkill, 0)` (decomp may truncate skill to `char` — body uses full pointer)
3. On ok: `Client_Skill_ResolveCastTarget(scratch, pSkill, &tfid0, pAim, 1)`; abort send if TFID == invalid
4. If `*(client+0xe04)+0x7e == 0` and free cast binding and `skill+0x61c == 0`: clear counter + `Skill_StartCastAgainHeartbeat(entity, pSkill, skill+0x14)` (**thiscall**, no 4th arg)
5. If charge `skill+0x14 > 0` and free binding: FX `vtbl+0x238(3, nSkillId, rankSum, 0, …)` + `"...Activating Skill..."` text
6. Pack + `Client_SendSectorPacket(client, 0x28, pkt)`
7. QB UI `client+0x10b0` → `vtbl+0x3d8` / `+0x450`
8. Maybe tip `0x23` from skill tip/cost fields
9. On fail: `Skill_FormatFailureMessage` + `FUN_008f8200` if UI ready

---

## 5. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_00941590_Client_RequestCastSkill.*` |
| Clean | `reconstructed-exact/Client_RequestCastSkill.cpp` |
| Dual residual | `reviews/a_00941590.md` |
| Dual A/B | `reviews/A_aa_00941590_*`, `B_aa_00941590_*` |
| Topic | `docs/topic-extractions/skill-cast.md` |
| Callee | `aa_0051a790` LocalCastValidate; `aa_0093b3a0` ResolveCastTarget |
| Sibling builders | `aa_00921b50` QuickBar, `aa_009418e0` CastFromSlot |

---

## 6. Confidence

| Dimension | Level |
|---|---|
| Opcode / size | High (Confirmed WI-SKL-001) |
| Control flow | High (decompiler + asm) |
| Optimistic HB order (before send) | High |
| Packet +0x18 skillId store | **Confirmed** (asm residual) |
| `EAX` client | High |
| HB / FX unaff recovery | **Sealed** (phantoms) |
| Overall | **Human-refined + dual residual; runtime/diff open** |

---

## 7. Open questions

1. ~~Asm-confirm skillId write into 0x2030 on this path~~ **Closed 2026-07-29**.
2. ~~Recover `unaff_EBX` / `unaff_retaddr`~~ **Closed** — not real formals.
3. Product type name for `client+0xe04` (role sealed).
4. Runtime cast trace / CE capture.
