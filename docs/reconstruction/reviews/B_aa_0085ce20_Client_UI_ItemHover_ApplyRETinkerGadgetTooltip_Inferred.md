# Review B (adversarial): `aa_0085ce20` Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085ce20` |
| **VA** | `0x0085ce20` |
| **Canonical name** | `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial / falsification |
| **Counterpart** | `reviews/A_aa_0085ce20_Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks attempted

| # | Hypothesis | Result |
|---|------------|--------|
| 1 | Thiscall / ECX is `this` widget | **Falsified** — prologue never loads ECX from object; EBX null-checked; callers leave EBX as widget |
| 2 | `param_1` is mode enum | **Falsified** — mode is `DAT_00d1d900`; stack char is 0/1 gate only |
| 3 | Function sends RE/tinker C2S | **Falsified** — no packet builders; only vtbl text/cursor |
| 4 | Mode values are skill IDs | **Falsified for this path** — compares to 0/4/5 with domain strings; skill IDs would not match |
| 5 | Scaffold name (Tinkering skill string only) is product name | **Reject** — covers RE + Gadget + Tinker |
| 6 | Gadget TFID globals are kit TFIDs | **Falsified** — `d940/d944` only on gadget path; `d938/d93c` only on tinker path |
| 7 | Decompiler `local_178` skill unused on success | **Noted** — skill used only for ≤0 message path; ok path does not format skill |
| 8 | Always places tooltip | **Falsified** — mode≠0,4,5 returns after clear without place epilogue |

---

## Residual risks

- Clean C++ compresses STOSD/MOVSD string copies to `strcpy`/`sprintf` — CF preserved, not byte-identical.
- Unowned apply-code helpers may refine message map (esp. gadget code defaults).
- `widget+0xce` flag product meaning open (treated as “enabled for ok chrome”).

---

## Confirmations with A

- ABI EAX/EBX/cdecl char sealed.
- Mode triple + string/RTTI map sealed.
- Dual verdict align: **accept-with-gaps**.
