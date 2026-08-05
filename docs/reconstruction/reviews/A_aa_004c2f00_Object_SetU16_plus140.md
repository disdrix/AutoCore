# Review A (reconstruction fidelity): `aa_004c2f00` Object_SetU16_plus140

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2f00` |
| **VA** | `0x004c2f00` |
| **Canonical name** | `Object_SetU16_plus140` (inferred; Ghidra `FUN_004c2f00`) |
| **Plate alias** | `Named_CalleeOf_CVOGCharacter_LevelUp_004c2f00` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c2f00_Object_SetU16_plus140.md` |
| **System** | combat / character attrs / ghost unpack |
| **Evidence pass** | Live `batch_decompile` + `read_memory` (`mov word [ecx+0x140], ax; ret 4`); callers LevelUp/UnpackGhost |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Unguarded u16 store** to object field **`+0x140`**.

No mask bits, no dirty flags, no clamps — pure setter.

**Callers include:**

- `VehicleNet_UnpackGhostVehicle` (`0x005f7720`) — combat/net ghost path
- `CVOGCharacter_LevelUp` / `LevelDown` / `ApplyCharacterLevelPacket` / `ApplyCreateFromPacket`
- `UI_OnAttributePointClick_Inferred` (`0x008f92e0`)

Sibling quartet: `0x004c2ee0` (+0x13c), `0x004c2ef0` (+0x13e), `0x004c2f00` (+0x140), `0x004c2f10` (+0x142).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c2f00_FUN_004c2f00.md` |
| Annotated | `docs/reconstruction/raw/aa_004c2f00_FUN_004c2f00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004c2f00.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c2f00_FUN_004c2f00.md` |
| Live | body: `66 8B 44 24 04  66 89 81 xx xx 00 00  C2 04 00` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = object*
// stack: uint16_t value  (ret 4)
void Object_SetU16_plus140(void *self, uint16_t value);
// *effectively*  *(uint16_t*)(self + 0x140) = value;
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| value | stack word | **High** |
| dest | `this+0x140` | **High** |
| Epilogue | `ret 4` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Single store | **Yes** | **High** |
| No side effects | **Yes** | **High** |
| No NetObject_SetMaskBits | **Yes** | **High** (contrast `0x005208e0`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Unguarded u16@+0x140 | **High** | bytes |
| Used from ghost unpack + level paths | **High** | callers |
| English attribute name | **Open** | residual (stat/attr index TBD) |
| Product name | **Tentative** | offset-based |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Map `+0x140` to product attr (str/end/acc/etc.) via LevelUp packet field order.
2. Whether ghost unpack writes same semantic units as LevelUp.
3. Sibling `0x004c2f10` (+0x142) not dualed in this batch unit.

**Verdict:** **accept-with-gaps**
