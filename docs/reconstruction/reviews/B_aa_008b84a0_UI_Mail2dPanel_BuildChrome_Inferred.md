# Review B (skeptical / adversarial): `UI_Mail2dPanel_BuildChrome_Inferred` @ `0x008b84a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b84a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-013 dual seal) |
| **Counterpart** | `reviews/A_aa_008b84a0_UI_Mail2dPanel_BuildChrome_Inferred.md` |
| **Verdict** | **accept-with-gaps** — chrome builder CF holds; product English + refresh wire residual |

---

## 1. Claims under attack

| # | Claim | Attack | Residual outcome |
|---|---|---|---|
| 1 | This is a **mail network send** / inventory transfer authority | **False** — body only constructs UI children, selects tabs, optional client helper `FUN_00980250`; no item move / equip / transfer callees | **Hold as client chrome builder only** |
| 2 | Scaffold name `UI_mail_bg_frame_deposit` is the product method | **False friend** — that XML is one **send-arm** child; function also builds receive list + both tabs + shared chrome | **Reject scaffold name; use BuildChrome** |
| 3 | Mode `@+0x510==1` means “panel open” not receive | **Weak** — receive arm builds list + selects receive tab; send arm builds compose/deposit; gate is mode, not mere open | **Hold receive-vs-send mode** |
| 4 | `FUN_00980250(…, 3)` is a sealed C2S opcode | **False** — only payload dword `3` + throttle observed; opcode/family not dualled here | **Hold call site; open wire map** |
| 5 | ECX thiscall is wrong (EDI/ESI register ABI like tab helpers) | **Falsified** — entry `MOV EBP,ECX`; callees rebind ESI/EDI for dualed helpers | **Hold ECX=this** |
| 6 | Sole DATA xref means unused / dead | **False** — vtable slot `@0x00a475b0` is live dispatch surface | **Hold vtable-owned method** |
| 7 | Runtime Confirmed from static dual | **Forbidden** — no Launcher | **Never Runtime Confirmed** |
| 8 | Parent partition `0x00756c90` means this is a child of move-to-front | **Context only** — this **calls** dualed `00756c90`; residual parent score ≠ class parent | **Hold call edge; no type inheritance claim** |

---

## 2. Surviving contract for AutoCore

```
// Client UI only — do not port as server authority
// thiscall; no stack args; plain RET
void UI_Mail2dPanel_BuildChrome(Mail2dPanel* self) {
  // shared i_d_mail_2d chrome + close id 0x9c40
  // new tab chrome 0x81c → receive @+0x55c (id 0x9c43), send @+0x558 (id 0x9c42)
  if (self->mode_at_0x510 == 1) {
    // receive frames + list @+0x5a4
    // select receive tab; collapse send tab + MoveToFront
    // if GetTickCount - last >= 10000: helper(payload=3); last = now
  } else {
    // send/deposit/credits/edits/item-drop/postage
    // collapse receive + MoveToFront; select send
    // clear +0x518/+0x51c = -1
  }
  self->vcall_layout_0x34c();
}
```

Server parity notes:

- **Do not** implement this method server-side as inventory transfer.
- Tab helpers remain dualed `UI_TabChrome_SetSelected_Inferred` / `UI_Widget_MoveToFrontInParentGroup_Inferred`.
- Attachment drop chrome (`0x9c44`) is UI surface only in this unit.

---

## 3. Skeptical hits on residual "seals"

| Seal | Challenge | Hold? |
|---|---|---|
| Body end `0x008b8b76` | Off-by-one vs next INT3 pad | **Hold** — last insn `RET` at `008b8b76`; pads `CC` follow |
| Mode `==1` receive | Could be inverted product labels | **Hold structural** — receive arm selects `+0x55c` receive tab |
| Control id lexicon | Same band used in inventory panel dual | **Hold local** — ids are per-handler; do not globalize |
| Throttle `0x2710` = 10 s | Could be other unit | **Hold** — `GetTickCount` delta compare literal |
| Vtbl `+0x404` = LoadXmlChild | Product name open | **Hold role Inferred** from (outslot, path, id) pattern |

---

## 4. What would falsify

1. Product PDB names this a non-mail dialog with coincident XML stems.
2. Live call with `@+0x510==1` selects send tab (would invert mode labels).
3. Direct CALL sites with different register ABI than ECX thiscall.
4. Body path that mutates inventory item ownership without UI-only callees.

None observed in static dual.

---

## 5. Open questions

1. Product panel class English / RTTI.
2. `FUN_00980250` request family / opcode map.
3. Vtable owner type for slot `@0x00a475b0`.
4. Full semantic map of shared chrome slots and credit denomination edits.
5. Runtime capture.

**Verdict:** Adversarial review **does not break** thiscall ABI, dual-tab construction, mode branch, dualed tab helper call pattern, or vtable ownership. Product English + wire residual. **accept-with-gaps.**
