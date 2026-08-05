# Review A (reconstruction fidelity): `aa_00813730` Client_RecvInventoryDropResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813730` |
| **VA** | `0x00813730` |
| **Body range** | `0x00813730` – `0x00813bd2` |
| **Canonical name** | `Client_RecvInventoryDropResponse` |
| **Review date** | `2026-07-29` (dual residual — ABI + dispatch seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw/annotated) |
| **Counterpart** | `reviews/B_aa_00813730_Client_RecvInventoryDropResponse.md` |
| **Prior dual** | `aa_00813730_reconstruction_review.md` / `aa_00813730_skeptical_review.md` |
| **Live re-decompile** | Ghidra MCP `decompile_function` 2026-07-29 — body **≡** raw capture |
| **Dispatch seal** | `Client_PacketDispatch` `case 0x2037`/`0x203b` → this VA; **sole** xref call `0x008159c2` |
| **ABI seal** | Call site `0x008159be`: `MOV EBX,ESI; MOV EAX,EBP; CALL`; prologue `MOV ESI,EAX` + `CMP [EBX],0x203b` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C InventoryDropResponse handler: clear busy (`client+0xb6`), early-out shared opcode **`0x203b`**, fail toast if success `@+0x22==0`, bind target inventory by type `@+0x1a` (1 cargo / 3 locker / 5 trade / 6 other), then:

- **Non-swap** (`swapFlag@+0x23==0`): resolve dropped item, place via `FUN_00571620` / `InventoryGrid_PlaceItemFootprint` at locX/Y **only if** not already at that cell, else skip place.
- **Swap** (`@+0x23≠0`, concat `@+0x38==0`): resolve occupant COID `@+0x28`, clear/adjust, place packet item.
- **Concat** (`@+0x38≠0`): stack-merge arms (type-6 special); toast on missing occupant.

Optional UI page host refresh via `local_94` → `FUN_0085e890`. Does **not** handle hardpoint (type 2) — that is equip path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_00813730_Client_RecvInventoryDropResponse.md` |
| Annotated | `raw/aa_00813730_Client_RecvInventoryDropResponse.annotated.md` |
| Clean | `reconstructed-exact/Client_RecvInventoryDropResponse.cpp` |
| Function record | `functions/aa_00813730_Client_RecvInventoryDropResponse.md` |
| Prior dual | `reviews/aa_00813730_*` |
| System / wire | `systems/inventory-transfer.md`, `docs/inventory-cargo-wire-re.md` |
| Packet docs | `Documentation/PACKET STRUCTURES.md` § InventoryDropResponse |
| Server Write | `src/AutoCore.Game/Packets/Sector/InventoryDropResponsePacket.cs` |
| Place callee | `aa_00571620` InventoryGrid_PlaceItemFootprint |
| Dispatch | `Client_PacketDispatch` `0x00815710` (live re-decompile + raw) |
| C2S sibling | `aa_00860a50` DropToGrid (type@+0x1a producer) |
| Grab sibling | `aa_00811be0` GrabResponse (same EAX/EBX dispatch framing) |
| Scratch | `tmp/a_00813730.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Clear `client+0xb6` + `FUN_007a69d0` | **Confirmed** | Prologue `MOV ESI,EAX`; `MOV BYTE [ESI+0xB6],0` (`read_memory`) |
| Early `*packet == 0x203b` return | **Confirmed** | Bytes `81 3B 3B 20 00 00` = `CMP [EBX],0x203B` |
| Dispatch binds **`0x2037` and `0x203b`** → this function | **Confirmed** | Live decompile of `0x00815710` + sole xref `0x008159c2` |
| Body does **not** positive-compare `0x2037` | **High** | Dispatch-level seal only (expected) |
| EAX=client / EBX=packet | **Confirmed** | Call site `8B DE 8B C5 E8…` + prologue; matches GrabResponse pattern |
| Fail when success `@+0x22 == 0` → toast + `FUN_007fc150` | **Confirmed** | Bytes `80 7B 22 00`; string `"Inventory Drop failed... server returned false"` |
| Require `client+0xe04`, nested `+0xe4e8`, char `+0xe98` | **High** | Silent returns |
| Type switch 1/3/5/6 + default invalid toast | **High** | CF; string `"Called Drop on invalid inventory object…"` |
| Case 1 grid: vehicle `char+0x250→+0x2b0`; UI `client+0x1040→+0x50c→+0x580` | **High** CF; cargo label **High** (wire RE + enum) |
| Case 3 grid: `char+0xcbc`; UI `client+0x1034→+0x510→+0x580` | **High** | locker sealed by wire RE |
| Case 5: `char+0xce0`; UI `client+0x1050→+0x588` + mission UI refresh | **High** CF; “trade” label **Probable** |
| Case 6: TFID `char+0xcd8/+0xcdc` → `obj+0xce0`; UI `+0x58c` | **High** CF; other-party trade **Probable** |
| locX `@+0x18` / locY `@+0x19` → place args | **High** | `unaff_EBX[6]` low byte = X; body + PACKET STRUCTURES + server Write |
| Non-swap item: type6 TFID `@+0x08`; else cursor `client+0x9b8` vtbl `+0x3ac` | **High** | |
| Place via `FUN_00571620` only if not already at (X,Y) | **High** | `FUN_00571b60` + vfuncs `+0x250/+0x254` gate |
| Server success ⇒ client place success | **Falsified** | Place can fail → toast `"Dropping failed trying to add…"` |
| Swap `@+0x23` / concat `EBX[0xe]` (`@+0x38`) branch structure | **High** CF |
| Occupant resolve `FUN_00571010(EBX[10], EBX[0xb])` = COID `@+0x28/+0x2c` | **High** CF; field name **Probable** |
| Full swap qty / type-6 concat retail semantics | **Probable** | Unnamed vfuncs; not port-ready |
| Portable cdecl `(client, packet)` | **Tentative** | Registers sealed; formals unused in clean |
| Live body ≡ raw | **Yes** | 2026-07-29 re-decompile |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Busy clear + helper + `0x203b` | **Yes** |
| Success fail path | **Yes** |
| World/char null gates | **Yes** |
| Type switch + grid/UI bindings | **Yes** |
| Non-swap place / skip-if-already | **Yes** |
| Swap / concat arms + error strings | **Yes** |
| Trailing `local_94` → `FUN_0085e890` | **Yes** |
| Live re-decompile ≡ raw | **Yes** (2026-07-29) |
| No invented modernization branches | **Yes** |

---

## 5. Packet field map (body-backed + cross-check)

| Offset | Size | Field | Body use | Server / docs |
|---:|---:|---|---|---|
| `+0x00` | 4 | opcode | early-out if **`0x203b`** (**Confirmed** bytes) | Write omits (BasePacket); dispatch **`0x2037`** |
| `+0x08` | 8 | item TFID/COID | resolve / toast id | `WriteTFID` |
| `+0x10` | 1 | global flag | (TFID pair) | `ItemGlobal` |
| `+0x18` | 1 | locX | place / already-at | `InventoryPositionX` |
| `+0x19` | 1 | locY | place / already-at | `InventoryPositionY` |
| `+0x1a` | 1 | inventoryType | switch 1/3/5/6 | `InventoryType` |
| `+0x1c` | 4 | quantity (concat) | dword use in arms | **not written** by AutoCore base packet |
| `+0x22` | 1 | success | fail toast (**Confirmed** bytes) | `WasSuccessful` |
| `+0x23` | 1 | swap/concat flag | non-zero → swap/concat | `HasSwappedOrConcatenatedItem` |
| `+0x28` | 8 | occupant COID | `FUN_00571010` | docs only; AutoCore Write **omits** |
| `+0x38` | 1 | concat sub-mode | `EBX[0xe]`; 0=swap, ≠0=concat | docs `1`=merge; AutoCore Write **omits** |

Normal non-swap success responses may end after `+0x23` (~36 B) — matches PACKET STRUCTURES.

### Type → grid (raw expressions)

| Type `@+0x1a` | Grid | UI host chain |
|---:|---|---|
| 1 | `*(*(char+0x250)+0x2b0)` | `client+0x1040 → +0x50c → +0x580` |
| 3 | `*(char+0xcbc)` | `client+0x1034 → +0x510 → +0x580` |
| 5 | `*(char+0xce0)` | `client+0x1050 → +0x588` |
| 6 | TFID(char+0xcd8) → `+0xce0` | `client+0x1050 → +0x58c` |
| 2 / default | invalid toast | — |

---

## 6. Opcode + ABI seal (residuals closed)

### 6.1 Opcode (prior dual left Tentative)

```text
Client_PacketDispatch @ 0x00815710:
  case 0x2037:
  case 0x203b:
    Client_RecvInventoryDropResponse();  // call site 0x008159c2
    return 1;
```

Evidence: live Ghidra decompile of dispatch + sole xref to `0x00813730` + body `CMP [EBX],0x203b`.  
`0x203b` is intentionally a no-op inside the body (shared jump slot with MM drop).

### 6.2 Register ABI (prior dual left Probable)

| Source | Evidence |
|---|---|
| Call site `0x008159be` | `8B DE` MOV EBX,ESI; `8B C5` MOV EAX,EBP; `E8 …` CALL DropResponse |
| Prologue | `8B F0` MOV ESI,EAX; clear `[ESI+0xB6]`; `CMP [EBX],0x203B`; `CMP BYTE [EBX+0x22],0` |
| Sibling | GrabResponse `0x008159ac`: same `MOV EBX,ESI; MOV EAX,EBP` pattern |

**Sealed:** client in **EAX**, packet in **EBX**. Portable cdecl formals remain unused / Tentative.

---

## 7. Link to C2S Drop (`aa_00860a50`)

C2S Drop grid path writes type `@+0x1a` / X `@+0x18` / Y `@+0x19` / COID `@+0x08` into size-`0x20` opcode **`0x2036`**. This S2C handler switches on the same type enum and places at the echoed X/Y. Hardpoint type **2** is **not** a DropResponse place path (equip / hardpoint handlers).

---

## 8. Gaps / open

1. Full swap qty accounting and type-6 concat vfunc sequence (semantics Probable; not bit-exact).
2. Place thiscall: ECX=grid recovery at call sites (place unit claims thiscall; DropResponse decompile omits this).
3. AutoCore does not yet emit occupant `@+0x28` / concat `@+0x38` — server parity gap if stack-merge is required.
4. Formal portable signature (registers Confirmed; formals unused).
5. Runtime multi-type drop / swap / concat captures; differential / bit-exact open.
6. `FUN_007a69d0`, `FUN_007fc150`, `FUN_007fc270`, `FUN_0092ce90`, `FUN_0085e890`, `FUN_00571b60`, `FUN_00571b80`, `FUN_00571010` — CF roles known; sealed names open unless sibling duals seal them.

**Verdict:** Scaffold-faithful large handler; **opcode dispatch Confirmed**; **register ABI Confirmed**; place/type CF High. **accept-with-gaps** (swap/concat depth + place ECX + runtime).
