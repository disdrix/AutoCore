# Review A (reconstruction fidelity): `aa_004c2f10` Object_SetU16_plus142

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2f10` |
| **VA** | `0x004c2f10` |
| **Canonical name** | `Object_SetU16_plus142` (inferred; Ghidra `FUN_004c2f10`) |
| **Plate alias** | `Named_CalleeOf_CVOGCharacter_LevelUp_004c2f10` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c2f10_Object_SetU16_plus142.md` |
| **System** | combat / character attrs / ghost unpack |
| **Evidence pass** | Live `batch_decompile` + `read_memory` (`66 8B 44 24 04  66 89 81 42 01 00 00  C2 04 00`); callers LevelUp/UnpackGhost |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Unguarded u16 store** to object field **`+0x142`**.

No mask bits, no dirty flags, no clamps — pure setter.

**Callers include:**

- `VehicleNet_UnpackGhostVehicle` (`0x005f7720`)
- `CVOGCharacter_LevelUp` / `LevelDown` / `ApplyCharacterLevelPacket` / `ApplyCreateFromPacket`
- `UI_OnAttributePointClick_Inferred` (`0x008f92e0`)
- `FUN_00521230` (attr apply helper cluster)

Sibling quartet: `0x004c2ee0` (+0x13c), `0x004c2ef0` (+0x13e), `0x004c2f00` (+0x140), `0x004c2f10` (+0x142).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c2f10_FUN_004c2f10.md` |
| Annotated | `docs/reconstruction/raw/aa_004c2f10_FUN_004c2f10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004c2f10.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c2f10_FUN_004c2f10.md` |
| Live | body: `66 8B 44 24 04  66 89 81 42 01 00 00  C2 04 00` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = object*
// stack: uint16_t value  (ret 4)
void Object_SetU16_plus142(void *self, uint16_t value);
// *effectively*  *(uint16_t*)(self + 0x142) = value;
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| value | stack word | **High** |
| dest | `this+0x142` | **High** (imm `0x142` in encoding) |
| Epilogue | `ret 4` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Single store | **Yes** | **High** |
| No side effects | **Yes** | **High** |
| No `NetObject_SetMaskBits` | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Unguarded u16@+0x142 | **High** | bytes |
| Used from ghost unpack + level paths | **High** | callers |
| English attribute name | **Open** | residual (stat/attr index TBD; last of +0x13c quartet) |
| Product name | **Tentative** | offset-based |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Map `+0x142` to product attr via LevelUp packet field order (with +0x13c/+0x13e/+0x140).
2. Whether ghost unpack writes same semantic units as LevelUp.

**Verdict:** **accept-with-gaps**
