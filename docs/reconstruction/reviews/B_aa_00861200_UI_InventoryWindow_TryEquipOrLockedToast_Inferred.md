# Review B (skeptical / adversarial): `aa_00861200` UI_InventoryWindow_TryEquipOrLockedToast_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00861200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-125 OWN dual) |
| **Counterpart** | `reviews/A_aa_00861200_UI_InventoryWindow_TryEquipOrLockedToast_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** same live Ghidra set as Path A. **No** `disassemble_bytes`. No Launcher / no runtime Confirmed.

---

## 1. Claims under attack

| # | Attack claim | Result |
|---|---|---|
| 1 | This VA **is** full `UI_InventoryWindow_OnEquipCommand` | **Falsified** — parent `FUN_008612b0` (966 B) owns modes 1/3/4, RTTI cast, store/use/special types; this is an 84 B leaf |
| 2 | Unit **sends** equip C2S (`0x203c` / `0x2053`) itself | **Falsified** — only CALL `00941b20`; opcodes live in dualed `Client_SendInventoryEquipC2S` |
| 3 | **ECX = window thiscall** | **Falsified** — entry tests ECX as item; parent `MOV ECX,EBX; MOV EAX,EDI` |
| 4 | **Always** toast / always fail | **Falsified** — success path CALL ConfirmEquip + return its EAX |
| 5 | `in_EAX` is undefined / garbage | **Falsified** — parent seals EAX=window (EDI) |
| 6 | Merge with `Client_ConfirmEquipOrCustomizeItem` | **Falsified** — separate VA; this is thin gate + toast |
| 7 | Merge with unequip / grab hardpoint senders | **Falsified** — no 0x203E / grab builders; string is equip-locked only |
| 8 | Three explicit stack args pushed after resolve (like modal Yes site) | **Nuanced** — mode/flag pushed **before** resolve virtual; stack balance requires caller-clean `vtbl[+0x3ac]`; still ends as ConfirmEquip's 3-dword frame |
| 9 | Product name without `_Inferred` | **Rejected** — window/mode/vtbl English open |
| 10 | Runtime Confirmed | **Rejected** — terminal false; no Launcher |

---

## 2. Surviving contract

```text
// ECX=item*, EAX=window*
if (item && window->slot_at_0x56c) {
  mode = slot->dword_at_4
  resolved = item->vtbl[+0x3ac](mode, 1)   // caller-clean args remain for next call
  return Client_ConfirmEquipOrCustomizeItem(client=&DAT_00d1a840,
                                            item=resolved, mode, confirmFlag=1)
}
toast("This equipment cannot be changed at this time.", chrome=0x4e24)
return 0
```

---

## 3. Residual risks (honest gaps)

| Risk | Severity | Mitigation |
|---|---|---|
| Product window class stamp | Med | Parent RTTI only seals selected child as `CWndInventoryItem`; keep `_Inferred` |
| Mode dword English | Med | Document values 1/3/4 from parent only; do not invent UI labels |
| `vtbl[+0x3ac]` semantics | Med | Pattern-matched as resolve/root across inventory duals; not demangled here |
| Caller-clean virtual assumption | Low–Med | Forced by `00941b20` `RET 0xC` balance; peer sites push 3 args explicitly |
| Runtime toast / equip | Med | Deferred (OWN-ONLY, no Launcher) |

---

## 4. What would flip to reject

- Live body diverging from raw CF (not observed 2026-08-05).
- Second code caller with different register ABI (not observed — single xref).
- Proof that `00941b20` is **not** entered with item/mode/flag from this stack shape.

---

## 5. Verdict

Path B **cannot** reject the sealed CF/ABI/string/chrome/ConfirmEquip forward. Naming stays **`_Inferred`**. Product English + runtime remain open.

**Verdict:** **accept-with-gaps**
