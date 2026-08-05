# Review B (skeptical / adversarial): `aa_00860a50` Client_UI_InventoryDropToGrid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860a50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00860a50_Client_UI_InventoryDropToGrid.md` |
| **Live re-decompile** | Ghidra MCP 2026-07-29 — body matches raw |
| **Verdict** | **needs-more-evidence** on XY seal + store path; grid opcode/size **survive** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function only sends InventoryDrop `0x2036` | **Falsified** — also `0x2027` / size `0x40` |
| 2 | Grid path is `0x2036` size `0x20` | **Survives** — `'6'+' '` + `size=0x20`; re-decompile |
| 3 | “Early allows only types 1 and 3” | **Overstated** — gate is type∉{1,3} **and** class==4 |
| 4 | Return 1 = drop accepted | **Falsified** — busy fake-success; also store path |
| 5 | XY packing sealed | **Survives residual** — pack-site imul/add; type via EDX typeHost (see residual B) |
| 6 | Portable void signature | **Broken** — this in EAX |
| 7 | Unit places item in grid | **Falsified** — DropResponse + `FUN_00571620` place |
| 8 | Type@+0x1a is destination inventory | **Survives as CF** — enum labels from DropResponse table |

---

## 2. Surviving contract

```
UI this (EAX):
  if !host || !hit-test: return 0
  if type∉{1,3} && held.class==4: return 0
  if trade type5 customized/non-tradable: toast; return 0
  if busy: return 1
  if store-like path: send 0x2027 size 0x40
  else: send 0x2036 size 0x20 with X/Y/type/COID
  set busy; return 1
  on reject: toast; return 0
```

**Do not treat as pure 0x2036 grid drop API.** Name `…DropToGrid` under-describes the 0x40 store arm.

---

## 3. Opcode / size evidence (attack cannot remove)

| Path | Opcode materialization | Size |
|---|---|---|
| Grid | `acStack_100[0]='6'`, `[1]=' '`, `[2]=0`, `[3]=0` → LE **`0x2036`** | **`0x20`** |
| Store (type 4 / vendor mode) | `acStack_100[0]='\''` (0x27), `[1]=' '` → **`0x2027`** | **`0x40`** |

Grid field offsets (COID@+8, global@+0x10, X@+0x18, Y@+0x19, type@+0x1a) match server `InventoryDropPacket.Read` and retail `SMSG_Sector_InventoryDrop`.

---

## 4. What still fails seal

| Topic | Why open |
|---|---|
| Y byte formula | **Sealed residual** — pack-site `imul [esi+0x564]` + add cellY; pageH from `FUN_0085f1d0` |
| `extraout_EDX+4` type source | **Sealed residual** — `mov edx,[esi+0x56c]` then `mov dl,[edx+4]` |
| `lQuantity@+0x1c` | Struct declares it; grid path does not write — server may ignore |
| 0x2027 identity | Store-like by strings + size; not fully typed |
| Callers / EAX layout | Not in unit pack |
| Runtime | No live drop capture this session |

---

## 5. Alternate interpretations

### Minimal reading

UI method: resolve drop cell → reject illegal class/type/trade → emit one of two sector packets or toast.

### Competing type-4 / 0x2027 stories

1. Vendor/store sell packet (favored: “store does not want that item” string).
2. Other commerce opcode reusing same builder (less likely).

### Type gate misread

Wire RE phrase “early allows types 1 and 3” is a **partial paraphrase** of one conjunct. Types 2/4/5/6 can still enter later arms.

---

## 6. DropResponse link (critical for completeness)

Attack on “this function completes inventory drop”:

| Step | Unit | Role |
|---|---|---|
| C2S request | **this** (`0x2036`/`0x20`) | Write typeTo@+0x1a, X/Y |
| S2C apply | `Client_RecvInventoryDropResponse` `0x00813730` | Switch type@+0x1a → grid; place |

Without DropResponse, client cargo/locker grid is **not** stamped. Documented switch already exists — do not re-derive; link:

- `raw/aa_00813730_Client_RecvInventoryDropResponse.annotated.md`
- `systems/inventory-transfer.md` § DropResponse packet
- `docs/inventory-cargo-wire-re.md` § Locker type 3

---

## 7. Open questions

1. ~~Asm of XY packing~~ → residual sealed; live multi-page still open.
2. Typed drop struct for port (fields known; host object English Probable).
3. 0x2027 full field map.
4. Live cargo↔locker drop sequence with Grab FromGrid.

**Verdict:** Grid **0x2036/0x20**, COID/X/Y/type offsets, **Y formula**, and **type host** **survive** residual attack. Dual-opcode naming, busy return semantics, and place ownership must not be overclaimed. Residual: `B_aa_00860a50_…_residual.md`.
