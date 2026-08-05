# Review B (skeptical / adversarial): `Client_QuickBar_ActivateSlot` @ `0x009436c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009436c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual refresh; base 2026-07-23) |
| **Counterpart** | `reviews/A_aa_009436c0_Client_QuickBar_ActivateSlot.md` |
| **Verdict** | **accept-with-gaps** on CF; type-5 **reclassified**; residual math **sealed** |

---

## 1. Claims under attack

| # | Claim | Attack | Residual outcome |
|---|---|---|---|
| 1 | All skill casts go through CastSkillFromQuickBarSlot | **Overstated** — on-foot slot0/1 uses QuickBarActivateSkillSlot; primary path may CastSkillFromQB from hardpoint list | **Stands** as overstatement warning |
| 2 | type 5 is “power” | **False friend** — prior dual inferred “power” from UI host / phrase text | **Retracted.** Table `DAT_00d177c8` is chat-macro phrases; activate calls chat-send `FUN_00941fb0` (opcode **0x2021**). Prefer **chat-macro bank** |
| 3 | subtype 8 always blocks use | **Local only** — only this path checks `+0x3f4==8` | **Stands** |
| 4 | Outer if is “in vehicle” | **Fragile** — compound of on-foot flags + host visibility; polarity easy to misread | **Stands** — document gate, do not rename to “in vehicle” alone |
| 5 | mode 1 is “alternate activate” | **Mislabel** if read as second activate path | **Corrected:** mode 1 = page select (`FUN_008a0ed0`); shift-QB from PollBoundActions |
| 6 | Packing formula is opaque magic | Algebra shows identity with type table +8 | **Sealed High** |
| 7 | `+3000` / `0xfffff447` are mystery combat windows | 64-bit add of 3000 + signed range [0,14] for macro row | **Sealed High** |

---

## 2. Surviving contract for AutoCore

```
QuickBar_ActivateSlot(slot, mode, page):
  if vehicle-host-visible path:
    slot0 → on-foot? QuickBarActivateSkillSlot(0) : TryPrimaryFire/hardpoint
    slot1 → on-foot? QuickBarActivateSkillSlot(1) : TryFireSecondaryWeapons
    // other slots: no-op on this arm
  else if QB UI present:
    page = (page==-1) ? UI+0x50c : page
    if mode==1: SelectPage(slot-as-page); return
    flat = slot + page*10
    if busy[flat]: return
    busy=1; switch type[flat]:
      1 → CastSkillFromQuickBarSlot(payload.lo)
      2 → find cargo by COID; block subtype 8; UseInventoryItem(1); busy=0
      5 → if int64(payload)+3000 in [0,14]:
             for phrase in macroBank[row][0..4]:
               if phrase: SendChatOrMacro(...)
             busy=0; return
    busy=0
```

Server parity notes:

- Skill cast and item use are client-initiated; authority remains server.
- Chat-macro path is **social UI**, not skill power pool / heat.
- Do not invent type enum values beyond 1/2/5 observed here.

---

## 3. Skeptical hits on residual “seals”

| Seal | Challenge | Hold? |
|---|---|---|
| type-5 = chat-macro | Could still be hybrid (macro + power UI host +0x1138) | **Hold as bank table + 0x2021**; host identity Probable only |
| Primary fire name for `FUN_00922270` | Body prefers hardpoint skill cast before gun fire | **Hold as primary-fire family** with skill-first walk documented |
| Use-item `0x2045` | Packet name not in all catalogs as C2S UseItem | **Hold** — body hardcodes 0x2045; S2C pair 0x2046 in PACKET STRUCTURES |
| Page select on mode 1 | Call-site register handoff of page index noisy in decomp | **Hold role** of callee; ABI framing residual open |

---

## 4. Open questions

1. Formal type-enum product name (UI bind strings).
2. Chat channel / arg mapping into `FUN_00941fb0` from type-5 (decomp arg count).
3. Subtype-8 busy-latch leave-set intentional?
4. Live shift-QB + macro-bank keybind capture.
5. Global rename of residual FUN_* (out of unit scope).

**Verdict:** Dispatcher map usable for AutoCore hotbar. Prior “power” type-5 claim **must not** drive combat-power server work. Residual math/packing sealed. **accept-with-gaps.**
