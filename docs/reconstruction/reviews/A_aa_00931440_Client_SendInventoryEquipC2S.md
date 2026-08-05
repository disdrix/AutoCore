# Review A (reconstruction fidelity): `aa_00931440` Client_SendInventoryEquipC2S

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931440` |
| **VA** | `0x00931440`–`0x009314ec` |
| **Canonical name** | `Client_SendInventoryEquipC2S` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (C2S equip / type-0xe emit) |
| **Counterpart** | `reviews/B_aa_00931440_Client_SendInventoryEquipC2S.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** — ABI/CF/opcodes/sizes sealed; full 0x40 field map + type-0xe product English open |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs. Context decompile of callers (read-only). **No** `disassemble_bytes`. **No** Launcher. Own VA only.

---

## 1. Purpose

Leaf-ish C2S emitter called after equip/customize **pre-gates** succeed:

```
Client_SendInventoryEquipC2S(client, item, mode):
  if cloneType(item) == 0xe:
    send opcode 0x2053 size 0x10 (COID lo/hi)
  else:
    send opcode 0x203c size 0x40 (16B identity + mode)
  return 0
```

Not a validator — parent `Client_ConfirmEquipOrCustomizeItem` owns town / space / permanent-customize modal gates.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` `0x00931440` ≡ scaffold raw |
| Live bytes | `read_memory` entry 160 B + tail through `RET 4` |
| Callers | `0x00941b20` ConfirmEquip; `0x00863430` Hardpoint drop |
| Parent dual (context) | `reviews/A_aa_00941b20_Client_ConfirmEquipOrCustomizeItem.md` |
| Clean | `reconstructed-exact/Client_SendInventoryEquipC2S.cpp` |
| Raw / annotated | `raw/aa_00931440_Client_SendInventoryEquipC2S{,.annotated}.md` |
| Function record | `functions/aa_00931440_Client_SendInventoryEquipC2S.md` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED / Confirmed**

| Fact | Evidence |
|---|---|
| Item in **EAX** | First insn `mov edx,[eax+0xa8]` |
| Client in **ECX** | `cmp [ecx+0xc78],0` |
| Mode on stack | `RET 4`; decompile `param_2` |
| Return | `xor eax,eax` → **0** |
| Body | `0x00931440`–`0x009314ec` |

Matches parent review call plate: `// ECX=client, EAX=item, stack=mode`.

### 3.2 Control flow — **SEALED**

Live decompile **≡** 2026-07-23 raw. Type probe `*(*(item+0xa8)+0x38)`:

| Branch | Opcode | Size | Payload |
|---|---|---|---|
| type == `0xe` | `0x2053` | `0x10` | COID lo/hi @ item `+0x160/+0x164` |
| else | `0x203c` | `0x40` | 16B @ `+0x160..+0x16c`; byte0; mode |

Null net → no send; type-0xe path returns early after send; both paths end **0**.

### 3.3 Send interface — **High**

`client+0xc78` non-null → `(*(net))->vtbl[+0x18](-1, buf, size, 0)`.

### 3.4 Callers — **Confirmed**

| Site | Context |
|---|---|
| `Client_ConfirmEquipOrCustomizeItem` @ `0x00941d31` | After all gates; then parent returns **1** |
| `Client_SendInventoryDrop_Hardpoint` @ `0x008634e9` | Type 0xe + town OK; **mode=1** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EAX item / ECX client / RET 4 | **Confirmed** | bytes |
| Opcodes + sizes | **Confirmed** | decompile + immediates |
| Return always 0 | **Confirmed** | |
| item identity offsets 0x160 family | **High** | parent TFID layout family |
| type 0xe = “customize in town” class | **High** | parent toast; product class name open |
| Complete 0x40 C2S field map | **Tentative** | only TFID+mode proven written |
| 0x2053 == AutoCore `VehicleSwitch` product | **Probable** | enum name; dual role residual |

---

## 5. Gaps

1. Exact C2S `0x203c` field dictionary for unwritten zeros in the 0x40 buffer.
2. Product English / clonebase class for type `0xe`.
3. Net object class at `+0xc78`.
4. Runtime capture of both packet shapes.
5. Whether sector treats C2S `0x203c` same id as S2C `InventoryEquip` framing.

**Verdict:** **accept-with-gaps** — emit contract sealed; wire field dictionary residual on 0x40 body.
