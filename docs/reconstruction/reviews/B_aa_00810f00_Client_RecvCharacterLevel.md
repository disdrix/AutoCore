# Review B (skeptical / adversarial): `aa_00810f00` Client_RecvCharacterLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810f00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00810f00_Client_RecvCharacterLevel.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on opcode + EAX contract |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Additive money/XP grant | **Falsified — absolute ApplyCharacterLevelPacket path** |
| 2 | Body proves opcode 0x2017 | **Falsified as body claim — dispatch/plate external** |
| 3 | Always refreshes local level UI | **Falsified — only when local TFID matches** |
| 4 | Portable (client, packet) signature | **Weak — EAX packet residual** |
| 5 | Finished exact port | **Overstated — Apply field map + UI vcalls open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Absolute snapshot apply | High | Wipe currency/XP with sparse packet |
| TFID resolve | High | Wrong target / silent skip |
| Local UI match polarity | High | Stale level chrome |
| Opcode binding | Tentative | Dead handler |
| EAX packet framing | Tentative | Wrong field offsets |

---

## 3. Cross-check against raw

```
pObj = LookupTFID(pkt+0x10, +8, +0xc);
if pObj: vtbl+0xcc ApplyCharacterLevelPacket;
if local char TFID match: RefreshLocalLevelUi + optional +0x1034;
always RefreshOpenMissionUiWindows;
optional +0x10b0 FUN_008a05a0.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
On S2C CharacterLevel (dispatch-bound 0x2017):
  resolve object by packet TFID; apply ABSOLUTE level/money/XP snapshot
  if local character TFID matches: refresh level UI/HUD
  always refresh open mission windows
Do NOT treat as additive GiveXP/GiveCredits.
Do NOT send full-total GiveXP on login (would re-apply XP).
```

---

## 5. Open questions

1. Exact PacketDispatch case binding for VA 0x00810f00.
2. Full ApplyCharacterLevelPacket field map cross-check.
3. Whether missing object should log vs silent skip.
4. Runtime login CharacterLevel capture.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on opcode + EAX contract
