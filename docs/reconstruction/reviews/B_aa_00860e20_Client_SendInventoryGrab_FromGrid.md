# Review B (skeptical / adversarial): `aa_00860e20` Client_SendInventoryGrab_FromGrid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860e20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual pack/split strengthen) |
| **Counterpart** | `reviews/A_aa_00860e20_Client_SendInventoryGrab_FromGrid.md` |
| **Live re-decompile** | Ghidra MCP 2026-07-29 — body matches raw |
| **Call-site residual** | 3 UNCONDITIONAL_CALL xrefs; asm packs qty + EDI |
| **Verdict** | **accept-with-gaps** on pack/CF/ABI shape; runtime / clearer / parent names open |

---

## 1. Claims under attack (post residual)

| # | Claim | Attack result |
|---|---|---|
| 1 | C2S InventoryGrab opcode `0x2034` size `0x20` | **Survives** — immediate + size arg; re-decompile confirms |
| 2 | Return 1 means “sent OK” | **Falsified** — always 1, including busy skip |
| 3 | Two-arg signature complete | **Broken as portable formals-only** — live **EDI** selection host required |
| 4 | Semantic name InventoryGrab | Working — no string in body; plate + system + server enum |
| 5 | Type byte is cargo/locker enum | CF holds for load path; enum labels external (DropResponse / wire RE) |
| 6 | Full 0x20 wire including pads | **Written fields Confirmed**; unwritten slots are garbage (not zeroed) |
| 7 | `+0x04` is txn id from this builder | **Falsified** — FromGrid never writes `+0x04` |
| 8 | `param_2` is quantity / split request count | **Survives** — stored at `+0x1c`; callers from GetQty `+0x25c` or `+0x4fc` |
| 9 | This unit performs stack split | **Falsified** — only packs request count; peel is GrabResponse `aa_00811be0` |
| 10 | Clean = retail exact | Scaffold fidelity yes; unwritten pad bytes not modeled as zero |
| 11 | Send helper identity | **Open** — `_INFERRED` vtbl+0x18 vs Hardpoint `Client_SendSectorPacket(&DAT_00d1a840,…)` |
| 12 | Hardpoint uses same qty field | **Falsified** — Hardpoint does not write `+0x1c`; server forces qty=1 for type 2 |

---

## 2. Surviving contract (minimal hard reading)

```
// ABI (call-site sealed)
//   EDI  = selection host (GetObject @ vtbl+0x3ac)
//   arg0 = inventory window*  (type at *(window+0x56c)+4)
//   arg1 = lQuantity          (whole stack or partial split count)
//
maybe_clear_cursor(EDI);
FUN_007fbbb0();
if !busy(DAT_00d1a8f6):
  pkt[+0x00] = 0x2034
  // +0x04 unwritten
  pkt[+0x08/+0x0c/+0x10] = resolve(EDI).TFID
  // +0x11..+0x17 unwritten
  pkt[+0x18] = *(*(window+0x56c)+4)   // ucTypeFrom
  // +0x19..+0x1b unwritten
  pkt[+0x1c] = quantity               // lQuantity (pack/split request)
  send(conn.vtbl+0x18, pkt, 0x20)
  DAT_00d1b4b0 = 1; DAT_00d1a8f6 = 1
return 1 always
```

**Opcode/size cannot be attacked away.** Written field offsets match retail `SMSG_Sector_InventoryGrab` and server non-equip `InventoryGrabPacket` reads.

---

## 3. Pack vs split — adversarial split of duties

| Stage | Owner | What is sealed |
|---|---|---|
| **Pack request** | **this unit** | `0x2034` / `0x20` / TFID / typeFrom / **lQuantity@+0x1c** |
| Decide partial vs whole | UI caller (before call) | qty source vfunc `+0x25c` or field `+0x4fc` |
| Server split decision | sector server | `lQuantity < source` → SplitFlag (docs) |
| **Apply split / cursor** | **GrabResponse** `aa_00811be0` | splitFlag@+0x20, count@+0x1c, SplitCoid@+0x28 |
| Place into grid | Drop / DropResponse | not grab |

Attack that “FromGrid splits stacks” **fails**. Attack that “FromGrid packs the split request count” **holds**.

---

## 4. What still fails seal

| Topic | Why open |
|---|---|
| Parent function names at 3 xrefs | Addresses not inside named functions in current DB |
| Pre-clear block purpose | Three competing stories still viable |
| Busy clearer site | Not in this function; GrabResponse dual already rules out response body |
| Runtime capture | No CE/packet log this session |
| Connection singleton name | Marked `_INFERRED` for a reason |
| Pad / garbage wire values | Unwritten; bit-exact needs capture |
| Equip path field reuse at `+0x04/+0x14` | Server-side for type 2 only; FromGrid is grid path |

---

## 5. Alternate interpretations

### Minimal (accepted)

Thin C2S packer: build grab request, fire sector send, raise busy. UI pre-clear optional. Quantity is caller-supplied grab count (whole or partial).

### Rejected overclaims

1. “Return indicates send success” — always 1.
2. “Txn id@+0x04 is set here” — not written.
3. “This function peels the stack” — GrabResponse only.
4. “Same packet layout fully shared with Hardpoint including qty” — Hardpoint omits `+0x1c` write and forces type=2.

### Type enum provenance

Body does not name cargo/locker. Labels from DropResponse (1/3/5/6), wire RE, server `InventoryTypes`. Byte path unbreakable; label table external.

---

## 6. Cross-check: server reader risk

`InventoryGrabPacket.Read` non-equip:

- COID `@+0x08`, global `@+0x10`, type `@+0x18`, qty `@+0x1c` with `Math.Max(1, …)`.
- Provisional position fields `@+0x28/+0x2c` require length ≥ `0x30` — **outside** client FromGrid size `0x20` → never set from this builder.

Equip branch (type 2) reinterprets `+0x04` / `+0x14` — **not FromGrid’s job** (Hardpoint / equip grab). Do not merge equip reinterpretation into FromGrid pack seal.

---

## 7. Open questions

1. Name the three callers once functions are defined / recovered.
2. Live grab: cargo whole, locker whole, partial split (typeFrom 1 vs 3; qty &lt; stack).
3. Asm frame proof that Ghidra `uStack_*` offsets ≡ wire (high confidence already via contiguous naming + retail struct).
4. Identity of sector send path vs `DAT_00d1a840`.

**Verdict:** Mechanical CF + pack map + caller ABI **OK**. Dual A’s accept-with-gaps is correct. Do not seal runtime, busy clearer, or parent names. Do not claim this unit performs split — only **packs** the split/whole quantity.
