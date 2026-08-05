# Review B (skeptical / adversarial): `Client_BuildInterfaceOptionsDialog` @ `0x0081c4d0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0081c4d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0081c4d0_Client_BuildInterfaceOptionsDialog.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Authoritative gameplay state machine | Falsified — options UI builder only |
| 2 | Sends SET_NEW_MISSION_ACTIVE to server on construct | Falsified — construct/load UI |
| 3 | Finished bit-exact port | Overstated — large widget tree untyped |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Options toggles exist client-side | High | Missing UI prefs |
| SET_NEW_MISSION_ACTIVE label | High | Wrong default behavior docs |
| Full widget tree offsets | Tentative | Cosmetic only |

---

## 3. Cross-check against raw

```
BuildInterfaceOptionsDialog:
  clear/create NDUI children from i_o_ui_2d_*.xml;
  labels include QB drag-shift + auto-set new mission active;
  UI only.
```

---

## 4. Surviving contract for AutoCore

```
BuildInterfaceOptionsDialog():
  client settings dialog; no C2S on build.
  Mission auto-active and QB drag-shift are option keys (see LoadGraphicsIniKeys).
```

---

## 5. Open questions

1. Map each checkbox to graphics/INI key + persist path.
2. Confirm interaction with SET_NEW_MISSION_ACTIVE runtime flag.

**Verdict:** **accept-with-gaps**
