# Review B (skeptical / adversarial): `aa_008146b0` Client_RecvCreateCharacter

| Field | Value |
|---|---|
| **Stable ID** | `aa_008146b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008146b0_Client_RecvCreateCharacter.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on extended flag + opcodes |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always creates new object | **Falsified — early return when local TFID already matches** |
| 2 | Always restores quickbar | **Falsified — only when local TFID match AND in_AL non-zero** |
| 3 | GiveItemByCbid is inventory loot | **Weak name — used as object allocate-by-cbid here** |
| 4 | Signature fully portable | **Weak — in_AL residual** |
| 5 | Finished exact | **Overstated — huge helper surface** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| TFID early-out | High | Double-create / skip create |
| Extended QB 100-slot restore | High | Empty bars after login |
| Alloc fail log path | High | Silent fail vs assert |
| in_AL meaning | Tentative | Wrong extended vs base |

---

## 3. Cross-check against raw

```
if local vehicle TFID == pkt+0x90/94: return (skip);
else lookup TFID; if null:
  if client TFID match && !in_AL: return
  alloc by CBID; create vcalls; if local TFID: UI refresh; if in_AL: QB 0..99
optional inventory UI refresh; end log.
Clean preserves structure; many names still FUN_*.
```

---

## 4. Surviving contract for AutoCore

```
On S2C CreateCharacter:
  skip if already bound local vehicle TFID matches packet
  else allocate/create by CBID when missing
  local character path: level UI + optional extended quickbar (100 items + skills)
  refresh related inventory UI when present
Seal in_AL / extended before treating base vs extended as distinct opcodes.
```

---

## 5. Open questions

1. Opcode(s) for create vs create-extended.
2. in_AL source (caller / prior instruction).
3. Full ApplyCreateFromPacket field map cross-check.
4. Runtime login create capture.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on extended flag + opcodes
