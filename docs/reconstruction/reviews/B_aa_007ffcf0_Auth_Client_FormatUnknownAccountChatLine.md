# Review B (skeptical / adversarial): `Auth_Client_FormatUnknownAccountChatLine` @ `0x007ffcf0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ffcf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007ffcf0_Auth_Client_FormatUnknownAccountChatLine.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on object layout |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server-side account ban or kick | **Falsified — client chat UI text** |
| 2 | Formats login credentials for AuthServer | **Falsified — chat logging banners** |
| 3 | Unknown Account is always the displayed name | **Falsified — only when +0xe0c null** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Banner string set | High | Wrong UX copy |
| DAT_00d1775c toggle semantics | High | Sticky enable/disable broken |
| Offsets +0x109c/+0xe0c/+0xe98 | Medium | Wrong object layout if mis-attributed |
| Channel class 6/16 | Tentative | Wrong chat tab only |
| Clean is CF-preserving scaffold | High | Low for map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth/UI layout mistakes |

---

## 3. Cross-check against raw

```
FormatUnknownAccountChatLine(slot):
  first = (flag[slot]==0); if first: flag[slot]=1
  if chatRoot(+0x109c)==0: maybe clear flag; return
  name = account(+0xe0c)? +0xc : "Unknown Account"
  who  = player(+0xe98)? vtbl+0x160() : "Player"
  verb = first ? "Enabled" : "Disabled"
  sprintf("%s %s [%s]", verb, who, name)
  emit SYSTEM separators + line via FUN_008f8200
  if !first: blank + flag[slot]=0
```

---

## 4. Surviving contract for AutoCore

```
Auth_Client_FormatUnknownAccountChatLine(param_1):
  client chat-log toggle banners for Unknown Account vs named Player;
  not auth protocol.
```

---

## 5. Open questions

1. Identify in_EAX type and who calls with param_1 values.
2. Seal FUN_008f8200 arg meanings (channel, color, text).

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on object layout — safe as behavioral map for AutoCore client auth/login UX; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
