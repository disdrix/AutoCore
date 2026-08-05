# Review A (reconstruction fidelity): `aa_007ffcf0` Auth_Client_FormatUnknownAccountChatLine

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ffcf0` |
| **VA** | `0x007ffcf0` |
| **Canonical name** | `Auth_Client_FormatUnknownAccountChatLine` |
| **System** | auth-login |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007ffcf0_Auth_Client_FormatUnknownAccountChatLine.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_007ffcf0_*.md` (or FUN_ twin) |
| Clean | `docs/reconstruction/reconstructed-exact/Auth_Client_FormatUnknownAccountChatLine.cpp` |
| String / plate evidence | From clean header + body |

---

## 2. Purpose (from unit)

Admin/chat-logging UI: toggle per-slot flag DAT_00d1775c[param_1]; if game chat root at +0x109c set, emit SYSTEM banner lines — 'Chat Logging Has Been Enabled/Disabled For %s %s [%s]' with Player name (vtbl+0x160) or 'Player', account string at +0xe0c+0xc or 'Unknown Account'. Bracket lines with '-----------------'. Display only.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Strings Unknown Account / Player / Chat Logging Has Been Enabled|Disabled For / SYSTEM | **High** | Literals |
| Per-index sticky flag DAT_00d1775c[param_1] | **High** | set on entry if was 0; clear on disable path |
| Chat root required at this/game +0x109c | **High** | null → early path |
| Account label from +0xe0c (+0xc) or Unknown Account | **High** | both branches |
| Player label from +0xe98 vtbl+0x160 or 'Player' | **High** | both branches |
| Channel class cVar5 = (param_1!=0 ? 10 : 0) + 6 → 6 or 16 | **Medium** | formula in body; meaning open |
| No auth wire / no server command | **High** | FUN_008f8200 chat UI only |
| Control flow preserved clean ≡ raw scaffold | **High** | No modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Toggle flag → null chat root short-circuit → format enable|disable → three SYSTEM lines | **Yes** |
| Enable path inserts blank line before banners; disable after | **Yes** |

---

## 5. Gaps

1. in_EAX object identity (game vs chat manager) not sealed.
2. param_1 slot meaning (which admin log channel) open.
3. FUN_008f8200 signature / color DAT_00a1419b open.

**Verdict:** **accept-with-gaps**
