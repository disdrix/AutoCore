# Review B (skeptical / adversarial): `Client_PacketDispatch` @ `0x00815710`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00815710` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00815710_Client_PacketDispatch.md` |
| **Verdict** | **accept-with-gaps** on switch CF; **needs-more-evidence** on register contracts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Clean is a full semantic rewrite of every packet body | **Falsified** — clean is a CF-preserving switch; bodies live in callees |
| 2 | `pPacket` is always a CharacterLevel packet | **Falsified** — decomp type is a header stand-in; only `dwOpcode` (and a few header fields) used at this layer |
| 3 | `0x2030` skill cast is S2C-dispatched here | **Falsified** — absent; C2S builders only |
| 4 | `0x2070` and `0x2071` are interchangeable | **Falsified** — 0x2070 force-complete; 0x2071 progress-only |
| 5 | All `FUN_*` cases are fully identified | **Overstated** — many still FUN; comments use GameOpcode names only |
| 6 | GiveXP uses formal `pPayload` | **Weak** — body of award reads `unaff_EDI` / framing; dispatch arg may not match formal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode → named handler for sealed siblings | High | Low for AutoCore server emit of those opcodes |
| No-op fallthrough set completeness | High | Client ignores expected server acks |
| Register-framed handlers (0x205E/0x205F/grab) | Medium | Server amount framing must match ESI/EDI contract |
| Full 0x8xxx / 0x9xxx coverage | Medium | Unknown opcodes return 0 (caller may error) |
| Param renames pCtx/pPacket/pPayload | Medium | Documentation only if call-sites use other names |

---

## 3. Surviving contract for AutoCore

```
Client_PacketDispatch(ctx, packetHeader, payload) -> 1 handled / 0 unknown
  switch packetHeader.opcode:
    0x2017 CharacterLevel  -> RecvCharacterLevel
    0x2031 SkillStatusEffect
    0x2035/2039 GrabResponse; 0x2037/203B DropResponse
    0x203C InventoryEquip
    0x205E GiveCredits; 0x205F GiveXP
    0x2070 CompleteDynamicObjective; 0x2071 ObjectiveState
    ... (full switch as raw)
Do NOT expect S2C 0x2030 here.
```

---

## 4. Open questions

1. Exact calling convention into this switch (who sets ESI/EDI for GiveXP).
2. Whether any intentional no-ops should later become handlers.
3. High-opcode set completeness vs retail traffic.

**Verdict:** Safe as the client S2C hub map; do not treat formal param types as sealed packet structs.
