# Review B (skeptical / adversarial): `aa_00813bf0` Client_RecvInventoryUnequipNotify

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813bf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` (residual refresh `2026-07-29`) |
| **Counterpart** | `reviews/A_aa_00813bf0_Client_RecvInventoryUnequipNotify.md` |
| **Verdict** | **accept-with-gaps** — demux + class map sealed; runtime open |

---

## 1. Claims under attack

| # | Claim | Attack / outcome |
|---|---|---|
| 1 | Same 0x203E struct as C2S SendUnequip | **Partial parity sealed.** Size 0x30 shared; item TFID + dest X/Y + type-hint overlap. C2S builder does **not** fill vehicle `@+0x18` / realm `@+0x20` / invType `@+0x2A` — server/S2C owns those. |
| 2 | “Demux” of bidirectional opcode is mysterious | **Falsified mystery.** No body demux: S2C = `PacketDispatch` case `0x203e` → RecvNotify; C2S = `SendInventoryUnequip` → `SendSectorPacket`. Direction only. |
| 3 | invType labels sealed enum | **CF holds**; wire HARDPOINT=2 documented; invType-2 helper arg framing still Probable |
| 4 | Non-local class switch complete | **Sealed High** for cases present: 6/10/0xc/0x10/0x1c + default return. Helpers bound by slot + strings (ornament/melee/weapon/wheelset/armor/powerplant). |
| 5 | RaceItem cleared here | **Falsified for this unit.** Class 6 requires subtype 10 (ornament); RaceItem is subtype 0xb @ `+0x270` — not this switch. |
| 6 | Always places on local unequip | **Falsified** — type 0 no place; place can fail toast |
| 7 | Finished exact | **Partial** — refined; runtime/diff still open |

---

## 2. Surviving contract

```
log unequip; vehicle = resolve(realm, id)
if !vehicle: optional destroy; return
if local owner:
  switch invType: place cargo/locker or UI helper; toast on fail
else:
  resolve item; clear hardpoint by class:
    6/sub10 → ornament +0x26c null
    10      → PowerPlant +0x268 null
    0xc/sub9 → melee +0x264 null
    0xc else → weapon slot +0x260[i] null
    0x10     → wheelset +0x258 null
    0x1c     → armor +0x254 null
    default  → return
refresh UI / FUN_0092f120 on non-local
```

---

## 3. Residual disposition

| Prior gap | Disposition |
|-----------|-------------|
| C2S/S2C demux | **Sealed High** — directional |
| Full hardpoint clear map | **Sealed High** for switch cases |
| FUN_* product names | **High** role names from strings; PDB open |
| Runtime | Still open |

**Verdict:** Local place switch + non-local class clear usable for AutoCore S2C 0x203E. Runtime still required for live parity.
