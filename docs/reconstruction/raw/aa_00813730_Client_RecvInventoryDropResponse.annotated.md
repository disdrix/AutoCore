# Annotated low-level: Client_RecvInventoryDropResponse (`aa_00813730`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813730` |
| **VA** | `0x00813730` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_00813730_Client_RecvInventoryDropResponse.md` (capture 2026-07-23) |
| **System** | inventory-transfer |
| **Wire** | S2C **`0x2037`** DropResponse; ignore **`0x203b`** |
| **Opcode seal** | **Confirmed** (2026-07-29): `Client_PacketDispatch` `case 0x2037`/`0x203b` → this VA; sole xref `0x008159c2`; live re-decompile ≡ raw |
| **ABI seal** | **Confirmed** (2026-07-29 residual): call site `0x008159be` `MOV EBX,ESI; MOV EAX,EBP; CALL`; prologue `MOV ESI,EAX` + `CMP [EBX],0x203b` |
| **Body range** | `0x00813730` – `0x00813bd2` |
| **Dual residual** | `reviews/A_aa_00813730_*` + `B_aa_00813730_*`; scratch `tmp/a_00813730.md` |

---

## 1. Calling convention

```c
// EAX = client, EBX = packet (dispatch) — Confirmed via call site + prologue
void Client_RecvInventoryDropResponse(void);
```

### Packet fields (from plate + raw)

| Offset | Type | Meaning |
|---:|---|---|
| `+0x00` | u32 | Opcode (`0x2037` via dispatch; body early-outs **`0x203b`**) |
| `+0x08` | TFID_16 | Item TFID |
| `+0x18` | u8 | **locX** |
| `+0x19` | u8 | **locY** |
| `+0x1a` | u8 | **inventoryType** |
| `+0x1c` | u32 | quantity (used in concat path) |
| `+0x22` | u8 | **success** (0 → toast fail) |
| `+0x23` | u8 | **swapFlag** (0 = simple place, ≠0 swap/concat) |
| `+0x28/+0x2c` | u32×2 | swap peer COID (`EBX[10/11]`) |
| `+0x38` | u8 | concat/split related (`EBX[0xe]`) |

### inventoryType switch

| Value | Grid resolution |
|---:|---|
| **1** | Cargo: vehicle `char+0x250` → `vehicle+0x2b0`; UI `client+0x1040→+0x50c→+0x580` |
| **3** | Locker: `char+0xcbc`; UI `client+0x1034→+0x510→+0x580` |
| **5** | Trade: `char+0xce0`; UI `client+0x1050→+0x588` |
| **6** | Other object inventory via TFID at `char+0xcd8/+0xcdc` → `+0xce0` |
| default / 2 | Invalid → error toast |

---

## 2. Control flow (compressed)

```text
client+0xb6 = 0
FUN_007a69d0()
if opcode == 0x203b: return

if success@+0x22 == 0:
  toast "Inventory Drop failed... server returned false"; return

require client+0xe04, nested +0xe4e8, client+0xe98 (character) non-null

resolve grid* from inventoryType switch → iVar8
if grid == 0: toast "invalid inventory object"; return

if swapFlag@+0x23 == 0:
  // SIMPLE PLACE
  resolve item (type6: from packet TFID; else cursor via client+0x9b8 vfunc +0x3ac)
  if already at (x,y) matching vfuncs +0x250/+0x254: skip place
  else PlaceItemFootprint(grid/item, x, y, qty...)  // FUN_00571620
  on fail: error "Dropping failed trying to add to inventory"
  refresh mission UI; FUN_0092ce90()
else:
  // SWAP / CONCAT
  peer = FUN_00571010(swapCoidLo, swapCoidHi)
  if concat flag@+0x38 == 0:
    // swap: clear peer place, place packet item at x,y, adjust qtys
  else:
    // concatenate stacks / hand merge paths (type6 special)
  errors: "swap" / "concatinate" strings

if local_94 (UI refresh host): FUN_0085e890()
```

---

## 3. Side-effect order

1. Clear busy byte; log helper.
2. Validate success + client pointers.
3. Bind **target grid** by type.
4. Branch simple vs swap/concat.
5. **`FUN_00571620` PlaceItemFootprint** on success paths (multi-cell stamp).
6. Cursor clear helpers (`FUN_007fc150` / `FUN_007fc270`).
7. Mission UI refresh; optional `FUN_0085e890` on grid UI object.
8. Toasts on failure; often `FUN_007fc150` after toast.

---

## 4. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `unaff_EBX` | Packet base | **Confirmed** |
| Type map 1/3/5/6 | Cargo / locker / trade / other | **High** |
| `FUN_00571620` | `InventoryGrid_PlaceItemFootprint` | **Confirmed** |
| `FUN_00571010` | Resolve object by COID pair | **High** |
| Place call arg order | ECX=grid vs item — **register recovery fragile**; behaviorally places into resolved `iVar8` grid | **Probable** |

---

## 5. Confidence / open

| Area | Level |
|---|---|
| Opcode `0x2037` dispatch binding | **Confirmed** (PacketDispatch + sole xref; body only rejects 0x203b) |
| EAX=client / EBX=packet | **Confirmed** (call site `0x008159be` + prologue `read_memory`) |
| Type→grid pointer map | **High** |
| Success/swap/concat branching | **High** |
| Base fields X/Y/type/success/swap | **High** (body + PACKET STRUCTURES + AutoCore Write; `@+0x22`/`0x203b` byte-sealed) |
| Full swap qty accounting | **Probable** |
| Occupant `@+0x28` / concat `@+0x38` wire | **Probable** (body + docs; AutoCore Write omits) |
| Place thiscall ECX at call sites | **Probable** |
| Bit-exact full packet / runtime | **Open** |
