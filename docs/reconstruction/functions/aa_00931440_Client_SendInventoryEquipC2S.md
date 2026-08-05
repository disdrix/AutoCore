# Function record: Client_SendInventoryEquipC2S

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931440` |
| **Canonical name** | `Client_SendInventoryEquipC2S` |
| **Address** | `0x00931440`–`0x009314ec` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual A/B sealed** (W19-T 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias history

| Name | Status |
|---|---|
| `FUN_00931440` | Ghidra / scaffold |
| `Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_00931440` | Auto callee alias |
| `Client_SendInventoryEquipC2S` | **Canonical** — C2S equip / type-0xe customize emit |

## Purpose

Pack and send the client→sector equip request after parent validation:

- **Type `0xe`** (clone meta `item[0xa8]+0x38`): opcode **`0x2053`**, size **`0x10`**, item COID lo/hi at `+0x160/+0x164`.
- **Else:** opcode **`0x203c`**, size **`0x40`**, 16-byte identity from `item+0x160..+0x16c`, mode byte from stack arg.

Null `client+0xc78` skips send. Return value is always **0** (caller owns success).

## Signature (sealed)

```c
// Bytes: EAX=item, ECX=client, stack mode, RET 4, return 0
uint32_t Client_SendInventoryEquipC2S(Client *client, Item *item, uint8_t mode);
```

## Control flow (sealed)

```
type = *(*(item+0xa8)+0x38)
if type == 0xe:
  pack 0x2053 + COID pair
  if client+0xc78: vtbl+0x18(-1, buf, 0x10, 0); return 0
else:
  pack 0x203c + 16B identity + mode
  if client+0xc78: vtbl+0x18(-1, buf, 0x40, 0)
return 0
```

Live decompile ≡ 2026-07-23 raw (no CF delta). Body through `RET 4`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00931440_Client_SendInventoryEquipC2S.md`
- Annotated: `docs/reconstruction/raw/aa_00931440_Client_SendInventoryEquipC2S.annotated.md`
- Scaffold raw: `docs/reconstruction/raw/aa_00931440_FUN_00931440.md` (+ annotated)
- Clean: `docs/reconstruction/reconstructed-exact/Client_SendInventoryEquipC2S.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00931440.cpp`, `Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_00931440.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00931440_Client_SendInventoryEquipC2S.md`
- Review B: `docs/reconstruction/reviews/B_aa_00931440_Client_SendInventoryEquipC2S.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Callers | `Client_ConfirmEquipOrCustomizeItem` `0x00941b20` @ `0x00941d31` | Success tail after gates |
| Callers | `Client_SendInventoryDrop_Hardpoint` `0x00863430` @ `0x008634e9` | Type 0xe, mode=1 |
| Callees | Indirect only: `(*(client+0xc78))->vtbl[+0x18]` | Sector packet send |

## Related opcodes (AutoCore enum context)

| Opcode | AutoCore name | This unit |
|---|---|---|
| `0x203C` | `InventoryEquip` | C2S equip request (also used S2C equip notify elsewhere) |
| `0x2053` | `VehicleSwitch` | C2S type-0xe path |

## Confidence

| Claim | Level |
|---|---|
| ABI EAX/ECX/stack + RET 4 | **Confirmed** (`read_memory`) |
| CF type 0xe vs else + sizes | **Confirmed** |
| Opcodes 0x203c / 0x2053 | **Confirmed** |
| Return always 0 | **Confirmed** |
| Offsets item+0xa8/+0x160 family, client+0xc78 | **High** |
| Full 0x40 field map beyond TFID+mode | **Tentative** |
| Product English type 0xe / net class | **Tentative** |
