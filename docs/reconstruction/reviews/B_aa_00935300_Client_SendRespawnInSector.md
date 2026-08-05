# Review B (skeptical / adversarial): `aa_00935300` Client_SendRespawnInSector

| Field | Value |
|---|---|
| **Stable ID** | `aa_00935300` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00935300_Client_SendRespawnInSector.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Packet carries destination station | **Falsified** — current vehicle pose only |
| 2 | COID is vehicle COID | **Attacked** — plate: character coid at 0xe98 entity |
| 3 | Works without vehicle | **Falsified** — requires `char+0x250` |
| 4 | Always sends when dead | **Overstated** — map id mismatch / null char skip |
| 5 | Name “RespawnInSector” = full respawn SM | **Overstated** — request only; server SpecialEvent completes |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode / size | High | Broken INC |
| Pose-as-current | High | Server wrong pad math |
| COID source | High | Wrong entity airlift |
| Post-send cleanup | Tentative | UI stuck |
| Server dest resolution | Probable | Pad/station table open |

---

## 3. Cross-check against raw

Body is small and matches plate layout. Clean scaffold preserves gates and pack order. Cross-check `Client_SendSectorPacket` as transport (dual-reviewed elsewhere).

---

## 4. Surviving contract for AutoCore

```
SendRespawnInSector (C2S 0x2073, 0x28 bytes):
  require local char + vehicle (+0x250)
  require map context match
  packet = {0x2073, vehicle.pos.xyz, vehicle.quat.xyzw, char.coid.i64}
  Client_SendSectorPacket(client, 0x28, packet)
  cleanup FUN_007fc840
Server resolves destination; client does not encode station id here.
```

---

## 5. Open questions

1. Live confirmation COID is character not vehicle.
2. INC option matrix (only option 0?).
3. SpecialEvent Respawn S2C dual review.
4. No other SendRespawn\* units found in this corpus.

**Verdict:** Thin C2S request sealed; full respawn pipeline not this unit.
