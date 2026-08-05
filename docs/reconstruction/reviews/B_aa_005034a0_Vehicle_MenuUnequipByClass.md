# Review B (skeptical / adversarial): `aa_005034a0` Vehicle_MenuUnequipByClass

| Field | Value |
|---|---|
| **Stable ID** | `aa_005034a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005034a0_Vehicle_MenuUnequipByClass.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Switch key is clonebase `+0x38` type | **Falsified** — separate menu enum; parent maps type→case |
| 2 | Only powerplant unequip | **Falsified** — string family covers PP/wheel/armor/weapon/item |
| 3 | Always returns non-null item | **Falsified** — many null paths when clear out stays 0 |
| 4 | Sends C2S unequip | **Falsified** — local graphics/slot + audio only |
| 5 | Cases 4–9 unreachable | **Open** — no xrefs outside `00504f60` cases 1–3; body still present |
| 6 | Armor returns via out-param | **Falsified** — case3 uses **prior** `veh+0x254` then SetEquippedArmor clear |
| 7 | Audio helper name is mission-complete | **Working Ghidra name** — args sealed; product routing open |

---

## 2. Surviving contract

```
thiscall vehicle, enum classId:
  play menu_unequip_* for classId
  clear slot via class-specific equip helper(null/0)
  maybe NetObject_SetMaskBits
  return COM iface of detached item or null
```

Parent dual `00504f60` **cannot** be attacked on calling cases **1/2/3** for PP/wheelset/armor.

---

## 3. Open

| Topic | Why |
|---|---|
| Live use of weapon cases 4–7 | No xrefs found in this pass |
| Mask bit product meaning | Immediates only |
| Bit-exact / runtime | Deferred |

**Verdict:** Switch + strings + clear helpers sealed. **accept-with-gaps.**
