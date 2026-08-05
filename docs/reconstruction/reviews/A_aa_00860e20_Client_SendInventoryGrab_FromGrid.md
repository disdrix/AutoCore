# Review A (reconstruction fidelity): `aa_00860e20` Client_SendInventoryGrab_FromGrid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860e20` |
| **VA** | `0x00860e20` |
| **Canonical name** | `Client_SendInventoryGrab_FromGrid` |
| **Review date** | `2026-07-29` (dual residual pack/split strengthen) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw/annotated) |
| **Counterpart** | `reviews/B_aa_00860e20_Client_SendInventoryGrab_FromGrid.md` |
| **Prior dual** | `aa_00860e20_reconstruction_review.md` / `aa_00860e20_skeptical_review.md` |
| **Live re-decompile** | Ghidra MCP `decompile_function` 2026-07-29 — body **≡** raw capture |
| **Call-site residual** | Xrefs `0x0083e677`, `0x00861a98`, `0x00861b3c` (asm context; parent funcs not named in DB) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

C2S InventoryGrab from a grid window: optional EDI pre-clear, helper `FUN_007fbbb0`, busy gate `DAT_00d1a8f6`, **pack** opcode **`0x2034`** size **`0x20`** (item TFID from resolved object, `ucTypeFrom` from `*(window+0x56c)+4`, `lQuantity`=`param_2`), send via connection vtable `+0x18`, set busy flags, **always return 1**.

`param_2` is the **whole-stack or partial-split request count** (not a flags dword). Server stack-split is answered on S2C GrabResponse (`aa_00811be0`), not in this unit.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_00860e20_Client_SendInventoryGrab_FromGrid.md` |
| Annotated | `raw/aa_00860e20_Client_SendInventoryGrab_FromGrid.annotated.md` |
| Clean | `reconstructed-exact/Client_SendInventoryGrab_FromGrid.cpp` |
| Function record | `functions/aa_00860e20_Client_SendInventoryGrab_FromGrid.md` |
| Sibling pack | Hardpoint `0x00862d90` decompile (type=2, no qty write) |
| Peer response | GrabResponse dual `aa_00811be0` (splitFlag@+0x20, count@+0x1c) |
| Server | `InventoryGrabPacket.cs` / tests; `GameOpcode.InventoryGrab = 0x2034` |
| Retail struct | `Documentation/PACKET STRUCTURES.md` `SMSG_Sector_InventoryGrab` Size=`0x20` |
| Wire RE | `docs/inventory-cargo-wire-re.md` locker section |
| Live Ghidra | body + 3 call xrefs + hardpoint sibling |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode `0x2034`, send size `0x20` | **Confirmed** | Immediate + size arg; live re-decompile |
| Busy gate + set after send path | **High** | `DAT_00d1a8f6` / `DAT_00d1b4b0` |
| Type byte from window `+0x56c→+4` | **High** | CF explicit |
| Item ids from resolve `+0x160/+0x164/+0x168` | **High** | Dual vtbl+0x3ac resolves |
| Quantity at `+0x1c` = `param_2` | **Confirmed** | `uStack_4 = param_2`; callers supply qty |
| Callers load qty via vfunc `+0x25c` or field `+0x4fc` | **High** | asm at `0x00861a8e` / `0x0083e66b` |
| EDI = selection host (register arg) | **High** | call sites `MOV EDI,EBX/ESI` then CALL |
| Stack `param_1` = inventory window | **High** | PUSH window before CALL |
| Always return 1 (even busy-skip) | **High** | Single return site |
| Packet `+0x04` unused by FromGrid | **Confirmed** | Not written in body |
| Packet `+0x11..+0x17`, `+0x19..+0x1b` unwritten | **Confirmed** | pads / stack garbage |
| Partial split requested via `lQuantity < source` | **High** (contract) | PACKET STRUCTURES + GrabResponse peer; **not** validated by this body alone |
| Connection global identity | **Tentative** | `_INFERRED` vtbl+0x18 vs Hardpoint `Client_SendSectorPacket` |
| Pre-clear block semantics | **Tentative** | CF sealed; purpose open |

---

## 4. Control flow: clean ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Optional EDI pre-clear | `if (unaff_EDI) { resolve; match → flags + vcall }` | Same | **Yes** |
| Always `FUN_007fbbb0` | Yes | Yes | **Yes** |
| Busy gate | `if (DAT_00d1a8f6 == 0)` | Same | **Yes** |
| Packet fill | opcode → TFID → type → qty | Same order | **Yes** |
| Conditional net send | null-check connection then vtable+0x18 size 0x20 | Same | **Yes** |
| Busy set | `DAT_00d1b4b0=1`, `DAT_00d1a8f6=1` | Same | **Yes** |
| Return | always `1` | always `1` | **Yes** |

Type renames only. No invented clamps. Clean models EDI as explicit third param for portability — honest expansion of decompiler `unaff_EDI`.

---

## 5. Packet pack map (decompile-sealed)

Ghidra stack names map 1:1 onto a contiguous `0x20` buffer at `auStack_20`:

| Stack name | Off | Write | Source |
|---|---:|---|---|
| `auStack_20[0]` | `+0x00` | `0x2034` | literal opcode |
| `auStack_20[1]` | `+0x04` | **none** | stack garbage (docs “txn id” — **not** this builder) |
| `uStack_18` | `+0x08` | `*(item+0x160)` | COID lo |
| `uStack_14` | `+0x0c` | `*(item+0x164)` | COID hi |
| `uStack_10` | `+0x10` | `*(item+0x168)` | TFID global byte |
| *(gap)* | `+0x11..+0x17` | **none** | pad |
| `uStack_8` | `+0x18` | `*(*(window+0x56c)+4)` | **`ucTypeFrom`** |
| *(gap)* | `+0x19..+0x1b` | **none** | pad |
| `uStack_4` | `+0x1c` | `param_2` | **`lQuantity`** |

Retail `SMSG_Sector_InventoryGrab` (Id=5653, Size=`0x20`): `fidItem@+0x8`, `ucTypeFrom@+0x18`, `lQuantity@+0x1c`.

Server `InventoryGrabPacket` (non-equip path): `ItemCoid@+0x08`, `ItemGlobal@+0x10`, `InventoryType@+0x18`, `Quantity@+0x1c` (`Math.Max(1, …)`).

### FromGrid vs Hardpoint pack (sibling `0x00862d90`)

| Off | FromGrid | Hardpoint |
|---:|---|---|
| `+0x00` | `0x2034` | `0x2034` |
| `+0x04` | unwritten | unwritten (server may treat as EquipmentCbid for type 2) |
| `+0x08..+0x10` | item TFID | item TFID |
| `+0x14` | unwritten | unwritten (server EquipmentSlotHint for type 2) |
| `+0x18` | window type | **literal `2`** |
| `+0x1c` | **`param_2` qty** | **not written** (server forces Quantity=1) |
| Send | conn vtbl `+0x18` size `0x20` | `Client_SendSectorPacket(&DAT_00d1a840, 0x20, buf)` |
| Busy | sets `DAT_00d1a8f6` / `DAT_00d1b4b0` | different gate (`DAT_00d1b6d8`); no same busy pair |

---

## 6. Split contract (request half; response elsewhere)

This unit **only packs** the request quantity. Stack-split lifecycle:

```text
UI (whole or partial count)
  → FromGrid packs lQuantity@+0x1c = count
  → C2S 0x2034 size 0x20
  → S2C GrabResponse 0x2035 (aa_00811be0):
       whole:  splitFlag@+0x20 == 0 → cursor apply full/count
       split:  splitFlag != 0 → peel source, spawn SplitCoid@+0x28, cursor = new stack
  → later Drop 0x2036 / DropResponse 0x2037 places (not this unit)
```

Documented partial rule (`PACKET STRUCTURES.md`): request count at grab `+0x1c` **strictly less** than source quantity → server SplitFlag=1 + new SplitCoid.

**FromGrid does not compare** request qty to source qty; comparison is server-side / UI pre-call.

---

## 7. Call-site residual (EDI + qty sealed)

| Site | Pattern (asm) |
|---|---|
| `0x00861a98` | `host.vtbl+0x3ac` → item; `item.vtbl+0x25c` → qty EAX; `PUSH EAX; PUSH EDI; MOV EDI,EBX; CALL` |
| `0x00861b3c` | same with `ESI` host: `MOV EDI,ESI` then CALL |
| `0x0083e677` | window into EAX (global inv window switch); `MOV ESI,[ESI+0x4fc]` qty; `PUSH ESI; PUSH EAX; CALL` |

Sealed calling shape:

```text
param_1 (stack) = inventory window*
param_2 (stack) = lQuantity (u32/i32 grab count)
EDI             = selection / item host*  (GetObject @ vtbl+0x3ac)
return          = 1 always
```

---

## 8. Gaps / open

1. Parent function **names** for the three xrefs (DB has no function containing those VAs).
2. Pre-clear block purpose (`DAT_00d1d8dc` / `DAT_00d1d8f4/f5`) — CF only.
3. Who clears `DAT_00d1a8f6` (GrabResponse dual already **falsified** clearer-in-response).
4. Runtime whole vs partial grab capture / bit-exact.
5. Whether any path fills `+0x04` before send (not FromGrid).
6. Connection singleton name vs Hardpoint `DAT_00d1a840` identity.

**Verdict:** **accept-with-gaps.** Clean faithful; **pack map + qty-as-split-request + caller ABI** sealed by decompile + call-site asm. No fidelity reject.
