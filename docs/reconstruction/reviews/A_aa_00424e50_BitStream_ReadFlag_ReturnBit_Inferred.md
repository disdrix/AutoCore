# Review A (reconstruction fidelity): `aa_00424e50` BitStream_ReadFlag_ReturnBit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00424e50` |
| **VA** | `0x00424e50` |
| **Canonical name** | `BitStream_ReadFlag_ReturnBit_Inferred` (was `FUN_00424e50`) |
| **Ghidra symbol** | `FUN_00424e50` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of UnpackSkillHBEntry / VehicleNet unpack) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00424e50_BitStream_ReadFlag_ReturnBit_Inferred.md` |
| **System** | network-bitstream |
| **VehicleNet parent** | `VehicleNet_UnpackSkillHBEntry` `0x005b1570` (identity triple flags) |
| **Sibling** | `BitStream_readFlag` `0x0042ad50` (out-param / success-return ABI — **different**) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Read one bit from a BitStream and return it as the low byte (0/1).** On oversize cursor, sticky-fail and return 0.

Layout (same family as sealed `readFlag` / `readBits`):

| Offset | Role |
|---|---|
| `+0x0c` | buffer base |
| `+0x18` | bit cursor |
| `+0x1c` | sticky error byte |
| `+0x2c` | max bit index |

Live CF (`__fastcall` stream in ECX):

```
u = stream+0x18
if (stream+0x2c) < u:
  stream+0x1c = 1
  return 0                // low byte cleared (decomp: in_EAX & ~0xff)
byte = buffer[(u>>3)]
stream+0x18 = u + 1
return (byte & (1 << (u & 7))) != 0
```

**VehicleNet use:** after optional 64-bit identity words in `UnpackSkillHBEntry`, stores returned flag into `out+0x18` / `out+0x30` band (decomp `puVar4+6` / `+0xc` as byte).

**Other callers:** `FUN_005b17b0` (ghost unpack), `FUN_0042d960` (challenge response — out of VehicleNet domain).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00424e50` |
| Callers | `005b1570`, `005b17b0`, `0042d960` |
| Parent dual | `A_aa_005b1570_VehicleNet_UnpackSkillHBEntry_Inferred.md` |
| Sibling dual | `A_aa_0042ad50_BitStream_readFlag.md` |

---

## 3. Signature

```c
// returns 0 or 1 in AL; not "success" like 0x0042ad50
uint8_t /*bool*/ __fastcall BitStream_ReadFlag_ReturnBit(BitStream *stream /*ECX*/);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Single-bit read + cursor++ | **High** |
| Oversize → sticky `+0x1c` + return 0 | **High** |
| Return **value** is the bit (≠ success code) | **High** |
| Distinct from `0x0042ad50` ABI | **High** |
| Shared non-VehicleNet callers | **High** |

**Verdict:** **accept-with-gaps**
