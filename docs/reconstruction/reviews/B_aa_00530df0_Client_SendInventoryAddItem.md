# Review B (skeptical / adversarial): `aa_00530df0` Client_SendInventoryAddItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00530df0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00530df0_Client_SendInventoryAddItem.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on send site + noreturn edges |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Function alone “sends” 0x2047 on the wire | **Weak** — body allocates/fills and may rely on Serialize or other call for transport; no explicit `Client_SendSectorPacket` in clean body |
| 2 | Local place always mirrors server authority | **Falsified as exclusive truth** — optimistic place/merge can diverge; residual log proves client detects inconsistency |
| 3 | `operator_delete` is noreturn | **Ghidra overclaim** — free must return to caller in retail MSVC; clean inherits bad edges |
| 4 | Type-4 path always notifies | **Overstated** — gated on host nested pointer non-null |
| 5 | Signature fully sealed | **Probable only** — thiscall host/item/mergeContext plate-level |
| 6 | Finished exact port | **Overstated** — helper FUN_* and stack LogicUi scratch still opaque |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode 0x2047 + size 0x20 | High | Wrong C2S struct |
| +0x12 branch place vs merge | High | Stack merge desync |
| Serialize callee | High | Field map wrong (owned by aa_004fadb0) |
| Wire emit site | Tentative | Silent “send” without packet |
| Noreturn delete | Low (as noreturn) | Port never returns |

---

## 3. Cross-check against raw

```
clear item bit2;
pkt = new 0x20; *pkt = 0x2047;
if !Serialize(pkt, item, &iter): delete; /* Ghidra noreturn */
type4 LogicUi optional;
if pkt[+0x12]==0:
  PlaceFootprint; bind or world-drop; vcall; delete
else:
  merge FUN_00571830(mergeContext, iter COID…); residual check; delete
```

Clean preserves branch structure. Cross-unit: RecvAddItem uses related `@+0x12` polarity (merge/place vs re-find) — keep aligned.

---

## 4. Surviving contract for AutoCore

```
On client add-to-cargo:
  clear item flag bit2
  build 0x20 packet opcode 0x2047 via Inventory_SerializeAddItemPacket
  if addToExisting==0: optimistic PlaceItemFootprint + bind
  else: merge helper + residual inventory-failure log
  free packet
Do not port Ghidra noreturn delete as true noreturn without verifying epilogue.
Confirm wire transmit path (Serialize vs sibling send) before claiming C2S emit complete.
```

---

## 5. Open questions

1. Exact send call for 0x2047 (Serialize internal vs missing vcall).
2. `FUN_00570710` residual meaning.
3. World-drop `FUN_004d2820` retail conditions.
4. Runtime cargo-add capture.

**Verdict:** Safe as builder CF; seal wire emit + delete edges before production port.
