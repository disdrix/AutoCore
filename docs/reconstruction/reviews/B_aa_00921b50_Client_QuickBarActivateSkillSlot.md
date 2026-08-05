# Review B (skeptical / adversarial): `Client_QuickBarActivateSkillSlot` @ `0x00921b50`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921b50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual refresh; base 2026-07-23) |
| **Counterpart** | `reviews/A_aa_00921b50_Client_QuickBarActivateSkillSlot.md` |
| **Verdict** | **accept-with-gaps** (upgrades prior `needs-more-evidence` on thin scaffold) |

---

## 1. Claims under attack

| # | Claim | Attack | Residual outcome |
|---|---|---|---|
| 1 | Server applies skill without client `0x2030` | No — this path always builds/sends when validate passes | **Falsified** for this path |
| 2 | Uses hidden skills in slot count | Skip when `skill+0x615 & 1` | **Falsified** as CF |
| 3 | Packet size `0x20` | Send arg and struct Size=`0x28` | **Falsified** |
| 4 | Thin wrapper around `Client_RequestCastSkill` | Zero calls; different send + fail UX + skill select | **Falsified** |
| 5 | `nSlotIndex` is persisted QB slot 0–99 skill id | No type-table/`character_quickbar` read; counter over skill list | **Falsified** |
| 6 | Same as type-1 ActivateSlot cast | Type-1 → CastSkillFromQuickBarSlot(skillId); this unit only on-foot 0/1 + DriveControl | **Falsified as identity** |
| 7 | Aim XYZ “often 0” is intentional authored zero | Zeros then copy from never-written locals | **Stands as open** — do not port as authoritative aim |
| 8 | LocalCastValidate takes skill as `char` | Sibling dual + body offsets prove pointer; decomp cast is false | **Falsified ABI reading** |
| 9 | Always starts cast-again HB | Requires world `+0x7e==0` and `skill+0x61c==0` | **Falsified** (gates hold) |
| 10 | Aborts send on invalid TFID | No invalid check before send (unlike RequestCast) | **Stands** — may send invalid target TFID |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `0x2030` layout (+0 opcode, +8 TFID, +0x18 skillId, +0x1C aim) | **High** (aim source **Open**) | Cast fail / desync |
| Hidden/skip bit0 at `+0x615` | **High** CF / **Probable** product name | Cast wrong skill / wrong slot |
| Slot = visible list index | **High** | Map wrong skill to key |
| Callers only 0/1 literals | **High** | Invent multi-slot walker |
| ResolveCastTarget TFID | **High** | Wrong target |
| Cast-again HB gates | **High** | Spam cast / missing CD overlay |
| Aim XYZ bytes | **Open** | Bad VFX anchor if server echoes |
| Sector conn global name | **INFERRED** | Doc only |
| Runtime | **Open** | Live desync |

---

## 3. Cross-check against raw + live decompile

Live Ghidra `decompile_function(0x00921b50)` **2026-07-29** ≡ raw capture body (no CF drift).

```
resolve char → seed TFID/pos → lock list+0x74
  walk: skip (skill+0x615&1); break when count==nSlotIndex
unlock
if skill && LocalCastValidate==0:
  skillId = skill+0x5fc
  if world+0x7e==0: Clear(skillId); if skill+0x61c==0: StartCastAgainHB
  if skill+0x14: vfunc+0x238 charge FX
  pack 0x2030; ResolveCastTarget; send 0x28 via conn vtbl+0x18
  optional FUN_0089ff80
```

Callees (MCP): `Skill_LocalCastValidate@0051a790`, `Skill_ClearActiveCastCounterAndQueueId@00517b90`, `Skill_StartCastAgainHeartbeat@00519200`, `Client_Skill_ResolveCastTarget@0093b3a0`, `FUN_00411900`, `FUN_007a4480`, `FUN_0089ff80`.

---

## 4. Surviving contract for AutoCore

```
QuickBarActivateSkillSlot(visibleSkillIndex):  // typically 0 or 1 only from callers
  char = local character via DAT_00d1b6d8 chain
  seed = self interior +0x164.. or selection +0xa4→+0x160..
  skill = Nth skill in entity+0x74 list with (skill+0x615 & 1) == 0
  if !skill or LocalCastValidate(entity,0,skill,0) != 0: return  // silent
  skillId = skill+0x5fc
  if world+0x7e == 0:
    ClearActiveCastCounterAndQueueId(skillId)
    if skill+0x61c == 0:
      StartCastAgainHeartbeat(entity, skill, skill+0x14)  // optimistic CD
  if skill+0x14 != 0: charge FX vfunc+0x238(...)
  tfid = ResolveCastTarget(skill, seed, defaultAim, report=1)
  send C2S 0x2030 size 0x28: { pad4, tfid16, skillId, aimXYZ? }
  // aim: do NOT invent zeros as product truth until stack residual closed
  // NOT the type-1 QB path (that uses skill id → RequestCastSkill)
```

Server parity:

- Authority remains on server for cast success/CD; client optimistic HB type 8 matches RequestCast topic notes.
- Do not implement “hotbar slot N → skill list index N” for full 0–99 bar — only this on-foot/drive path uses indices 0/1.
- Persist bar (`QuickBarUpdate` 0x2062 / `character_quickbar`) is a **different** subsystem.

---

## 5. Skeptical hits on residual “seals”

| Seal | Challenge | Hold? |
|---|---|---|
| Visible-index vs QB skill id | Could UI still present skills in list order matching bar? | **Hold as mechanical identity** — this unit never reads QB payload table |
| Callers only 0/1 | Future codepaths might pass other indices | **Hold observed xrefs**; signature is general `char` |
| No invalid-TFID abort | Resolve may still write invalid; server may reject | **Hold** — client still sends |
| Aim uninit | Could be alias with resolve out beyond decomp naming | **Open** — do not port aim from this path without capture |
| `+0x615` bit0 = “hidden” | Could mean passive/non-activatable/etc. | **Hold CF**; name Probable |

---

## 6. Open questions

1. Close aim stack residual (asm of aim stores / CE capture).
2. Product string for `+0x615` bit0 filter.
3. Full list node layout product type at `+0x74`.
4. Whether DriveControlTick and ActivateSlot on-foot paths should both map to skill 0/1 for AutoCore input.
5. Runtime dual of send bytes vs RequestCast for same skill.

**Verdict:** Adversarial attacks on wrapper/slot-table/size claims **fail**. Aim residual and product naming remain open. Dual quality **sealed at accept-with-gaps**.
