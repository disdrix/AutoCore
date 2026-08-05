# Review B residual refresh (skeptical): `DropToGrid` @ `0x00860a50` (2026-07-29)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860a50` |
| **Review type** | Skeptical residual — **not** full re-dual |
| **Counterpart** | `A_aa_00860a50_Client_UI_InventoryDropToGrid_residual.md` |
| **Prior dual** | `B_aa_00860a50_Client_UI_InventoryDropToGrid.md` (2026-07-29) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Attacks on residual claims

| # | Challenge | Outcome |
|---:|---|---|
| 1 | Y is just `local_105` (no page scale) | **Falsified.** Pack site `imul byte ptr [esi+0x564]` after `call FUN_0085f1d0` then `add al,[esp+localY]` before store to `+0x19`. |
| 2 | `FUN_0085f1d0` is opaque / unrelated to page height | **Falsified as body.** Bytes: load `this+0x56c` → load `+0x1c`. Consumer family (FindFree/CanPlace/Alloc) uses grid `+0x1c` as page height; product `pageH×pageIdx` matches FindFree `yStart`. |
| 3 | `extraout_EDX` is decompiler garbage; type@+0x1a unsealed | **Falsified.** Asm: `mov edx,[esi+0x56c]` before type==4 branch; grid fallthrough; `mov dl,[edx+4]` into packet `+0x1a`. Same host as Grab type-from. |
| 4 | Function only sends `0x2036` | **Still falsified** (prior B) — `0x2027`/`0x40` arms remain. Residual does not re-open that. |
| 5 | Return 1 = drop placed | **Still falsified** — busy soft-OK; place is DropResponse + `FUN_00571620`. |
| 6 | “Early allows only types 1 and 3” exclusive allow-list | **Still overstated** — class-4 conjunct only. |
| 7 | type host **is** InventoryGrid object | **Not required.** Residual seals **offsets** (`+0x56c`, host `+4`, host `+0x1c`). Object English remains **Probable**. |
| 8 | Server needs `lQuantity@+0x1c` from client grid drop | **Unsupported by this builder** — grid path never writes `+0x1c`; AutoCore `InventoryDropPacket` does not read quantity. |

---

## 2. Surviving contract (drop packet only)

```text
// Grid arm only (not store 0x2027):
buf[0..3]  = LE 0x2036
buf+0x08   = item COID (held +0x160/+0x164)
buf+0x10   = item global (held +0x168)
buf+0x18   = cellX              // FUN_0085f220 out
buf+0x19   = pageH*pageIdx+cellY
buf+0x1a   = *(typeHost+4)      // destination inventory type
size       = 0x20
// typeHost = *(window+0x56c); pageH = *(typeHost+0x1c); pageIdx = *(i8*)(window+0x564)
Client_SendSectorPacket(..., 0x20, buf)
DAT_00d1a8f6 = 1
```

Risk if wrong: multi-page cargo/locker drops land on wrong row; DropResponse places into wrong type grid.

---

## 3. Confidence (adversarial residual)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode `0x2036` + size `0x20` | **Confirmed** | Wrong handler |
| X@+0x18 / Y@+0x19 / type@+0x1a offsets | **Confirmed** | Server mis-place |
| Y = pageH×pageIdx+cellY (asm) | **High** | Multi-page wrong row |
| typeHost EDX provenance | **Confirmed** | Wrong inventoryType |
| pageH English (= InventoryGrid page dim) | **High** (offset+consumer); host object ID **Probable** | Mis-name only if offset shared by coincidence |
| Full 0x40 store map | **Open** (out of residual) | Store sell path |
| Runtime multi-page | **Open** | Edge pageIdx |

---

## 4. Open (do not invent)

1. Live capture with pageIdx≥1 correlating UI page, wire Y, DropResponse place Y.
2. Store `0x2027` field diagram (separate unit of work).
3. Caller graph for EAX/ESI window type.
4. Whether `FUN_0085f220` outs are always page-local (vs absolute) when pageIdx=0 only — formula still holds for pageIdx=0 (Y=cellY).

**Verdict:** residual challenges on **Y formula** and **type@+0x1a** **defeated**. **accept-with-gaps.**
