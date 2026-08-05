# Review B (skeptical / adversarial): `UI_InventoryPanel_MessageHandler_Inferred` @ `0x008be900`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008be900` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-F OWN dual) |
| **Counterpart** | `reviews/A_aa_008be900_UI_InventoryPanel_MessageHandler_Inferred.md` |
| **Verdict** | **accept-with-gaps** — dispatch CF holds; panel product name residual |

---

## 1. Claims under attack

| # | Claim | Attack | Residual outcome |
|---|---|---|---|
| 1 | This **is** the only inventory use entry | **False** — use is `FUN_00941d50`; this is one **UI dispatcher** into it (also QuickBar dual) | **Hold as panel handler**, not sole use |
| 2 | Control ids `0x9c43..` are inventory-global | **False friend** — same id band appears in other UI (e.g. auth frame control assignment); meaning is **per-handler** | **Hold local semantics only** |
| 3 | msg `0xe` always sends **0x2045** | **False** — UseInventoryItem has equip arm without 0x2045; and failure falls to UseObject path | **Hold cascade, not always 0x2045** |
| 4 | `0x9c40` close **returns 1** like CloseBtn case | **Different** — this unit calls `FUN_007fca10` then **falls through** to default; CloseBtn dual returns 1 | **Hold decomp fallthrough** |
| 5 | Name "InventoryPanel" is product-sealed | **Inferred** — role from use/IfInteractable + slot widgets; class English open | **Keep `_Inferred`** |
| 6 | Scroll math is bit-exact without ROUND mode | **Fragile** — depends on x87 ROUND helper; intent sealed | **Hold intent; open bit-exact** |
| 7 | Default call loses `this` | **Decomp may omit ECX** — peer duals note `mov ecx,edi` pattern; treat as thiscall to `FUN_0087b500` | **Hold thiscall default** |

---

## 2. Surviving contract for AutoCore

```
// UI message handler — client chrome only
// ret 8; thiscall
uint32 HandleInventoryPanelMessage(Panel* self, int msg, int controlId) {
  if (controlId in 0x9c43..0x9c46) {
    slot = controlId - 0x9c43;
    if (msg == 5) { /* geometry via FUN_007fd420 */; return 1; }
    if (msg == 6) { /* set UI flags; hide aux */; return 1; }
    if (msg == 0xe) {
      if (!UseInventoryItem(mode=1)) SendUseObject_IfInteractable();
      return 1;
    }
  }
  if (controlId == 0x9c40 && msg == 8) LeaveDialogHost(); // then default
  if (controlId == 0x9c41 && msg == 8) return 1;
  if (controlId == 0x9c42 && msg == 0x1a) { /* scroll sync */; return 1; }
  return DefaultMessageHandler(self, msg, controlId);
}
```

Server parity notes:

- **Do not** implement this dispatcher server-side.
- Authority remains on sealed C2S **0x2045** / UseObject paths when those callees fire.
- msg `0xe` is **not** proof a packet was sent (gates inside UseInventoryItem).

---

## 3. Skeptical hits on residual "seals"

| Seal | Challenge | Hold? |
|---|---|---|
| Slot band 0x9c43..0x9c46 | Off-by-one exclusive bounds | **Hold** — `0x9c42 < id && id < 0x9c47` |
| ret 8 | Could be ret 0 with stack noise | **Hold** — bytes `C2 08 00` |
| Use then IfInteractable | Order reversed? | **Hold** — decomp: use first; only on `==0` interactable |
| Float bias 2^32 | Wrong constant | **Hold** — `read_memory` `4F800000` |

---

## 4. What would falsify

1. Product PDB names this a non-inventory dialog with coincident ids.
2. Live msg `0xe` path never reaches `FUN_00941d50` (different register setup) — would reclassify caller chain, not CF of this unit.
3. Second message handler with different use cascade for same panel.

None observed in static dual.

---

## 5. Open questions

1. Product panel class.
2. Msg code lexicon (`5`/`6`/`0xe`/`0x1a`).
3. Item selection path into EDI for use.
4. Runtime capture.

**Verdict:** Adversarial review **does not break** ABI / slot band / use cascade / default fallthrough. Product panel English residual. **accept-with-gaps.**
