# Chain note: `CVOGReaction_CastSkillOnTarget` 0x2031 packer residual seal

| Field | Value |
|---|---|
| **Date** | `2026-07-29` |
| **Topic** | Static seal of reaction/NPC packer: layout, size, no-wire-in-unit, callers |
| **Unit** | `CVOGReaction_CastSkillOnTarget` @ `0x004d09a0` (`aa_004d09a0`) |
| **Opcode** | buffer msgId `0x2031` (`GameOpcode.SkillStatusEffect`) — **local buffer**, not proven emit |
| **System** | `skills-abilities` |
| **Audience** | Dual-review residual strengthen; cold resume |

---

## Seal chain (static)

```
NPC / reaction / outpost / summon / bulk FUN_*
  └─ (often) LocalCastValidate + ResolveTargetList + range/target checks
  └─ CVOGReaction_CastSkillOnTarget @ 0x004d09a0
        ├─ gate world+0x7e && skill && source
        ├─ optional seat remap (types 0xe/0x12/0x14/3, vtbl+0x19c)
        ├─ operator_new(0x9a0) → pack header 0x2031
        ├─ null list → Skill_ResolveTargetList (flags local only)
        ├─ walk TFID → Object_ResolveFromTFID → mana shorts
        ├─ terminator + size = n*0x18+0x58
        ├─ optional Skill_ApplyStatusEffectLocal @ 0x0051aa00
        └─ operator_delete(packet); return 0

S2C sibling (separate ownership):
  Client_PacketDispatch case 0x2031
    → Client_RecvSkillStatusEffect @ 0x00811170
      → may also Skill_ApplyStatusEffectLocal
```

Do **not** claim `CastSkillOnTarget` is the PacketDispatch path. Do **not** claim Recv is the packer.

---

## Evidence table

| Claim | Tool / source | Conf |
|---|---|---|
| Callees exclude net send | `get_function_callees(0x004d09a0)` | **High** |
| Callers include NPC/Outpost/Summon | `get_function_callers` / xrefs | **High** |
| Opcode dword 0x2031 | decompile body `*pPacket = 0x2031` | **High** |
| Targets @ +0x40 | packer cursor math + Apply `(size-0x40)/0x18` walk | **High** |
| Size `n*0x18+0x58` | body `(n*3)*8+0x58` | **High** |
| Status 0/`'c'` from param_10 only | `-(param_10!=0)&99` | **High** |
| resolveFlags not → packet status | body: no store of local_8 to +0x14 | **High** |
| Always return 0 | both arms | **High** |

---

## Dual-review unit

| Stable ID | Name | Reviews | Verdict |
|---|---|---|---|
| `aa_004d09a0` | `CVOGReaction_CastSkillOnTarget` | A/B residual strengthen 2026-07-29 | **accept-with-gaps** |

Paths:

- `reviews/A_aa_004d09a0_CVOGReaction_CastSkillOnTarget.md`
- `reviews/B_aa_004d09a0_CVOGReaction_CastSkillOnTarget.md`
- Scratch: `tmp/a_004d09a0.md`
- Related S2C chain: `reviews/CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md`

---

## Sealed vs still open

### Sealed (static, high confidence)

- Packer field map + size formula + terminator accounting
- Target slot base **+0x40**
- **No network send inside this unit**
- Named high-value caller set
- resolveFlags map is local-only / discarded relative to packet status and return

### Still open

- Which (if any) server unit copies this buffer onto the wire for remote clients
- Runtime multi-target capture
- Product English for `this` / `+0x7e`
- Binary diff / bit-exact
