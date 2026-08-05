# Review B (skeptical / adversarial): `aa_00931440` Client_SendInventoryEquipC2S

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00931440_Client_SendInventoryEquipC2S.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | thiscall only (item as this) | Bytes use **EAX=item** and **ECX=client** | **Dual-register ABI sealed** |
| 2 | Function returns success 1 | `xor eax,eax` always | **Always 0; parent returns 1** |
| 3 | Unit validates equip / town | No string gates; no `FUN_004fabc0` | **Emit-only** |
| 4 | Only one opcode | Live branch packs **0x2053** or **0x203c** | **Two opcodes** |
| 5 | 0x203c size is 16 like COID | Push/size **0x40** on non-0xe | **0x40 sealed** |
| 6 | mode unused on type 0xe | Type 0xe path never writes `param_2` | **Mode only on 0x203c path** |
| 7 | Null net crashes | Both branches check `client+0xc78` | **Null-safe skip** |
| 8 | Same as S2C InventoryEquip builder | This unit is C2S from equip confirm; S2C builder is separate (`FUN_00813f40` family) | **Direction distinct** |
| 9 | Scaffold name “Named_CalleeOf…” sufficient | Callers include Hardpoint drop type-0xe | **Broader than ConfirmEquip alone** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI EAX/ECX/stack | **Confirmed** | Wrong client equip wire |
| Opcode split 0x2053/0x203c | **Confirmed** | Wrong sector handler |
| Sizes 0x10/0x40 | **Confirmed** | Truncated/overlong packets |
| Emit-only role | **High** | Server might wrongly re-validate client-side |
| Full 0x40 zeros meaning | **Tentative** | Missed C2S fields |
| type 0xe product class | **Tentative** | Mis-named customize |

---

## 3. Cross-check against raw / bytes

```
raw 2026-07-23 ≡ live decompile 2026-07-29 ≡ clean Client_SendInventoryEquipC2S.cpp CF
entry: 8B 90 A8 00 00 00  83 EC 50  83 7A 38 0E
type0xe send: push 0; push 0x10; lea buf; push; push -1; call [vtbl+0x18]
else send:    push 0; push 0x40; ...
exit: 33 C0  83 C4 50  C2 04 00
```

Reject ports that:

- Treat unit as equip **validator**.
- Assume single opcode.
- Put item in ECX as this without client.
- Use return value as success.

---

## 4. Surviving contract for AutoCore

```
// C2S after client equip/customize pre-gates
// type 0xe  → opcode 0x2053, 16 bytes, item COID only
// else      → opcode 0x203c, 64 bytes, item TFID + mode
// net = client+0xc78; if null, no-op
// return ignored (0)

// Sector should handle both opcodes as equip/customize requests.
// Do not confuse with S2C InventoryEquip notify builder.
```

---

## 5. Open questions

1. Wire layout of remaining 0x40 bytes (hardpoint hints? put-in-hand?).
2. type `0xe` clonebase English / relation to `VehicleSwitch` enum name.
3. Live packet capture vs this plate.
4. Hardpoint drop mode=1 vs ConfirmEquip mode from inventory window.

**Verdict:** **accept-with-gaps** — adversarial kills validator / single-opcode / wrong-ABI misreads; emit contract stands with field-map residual.
