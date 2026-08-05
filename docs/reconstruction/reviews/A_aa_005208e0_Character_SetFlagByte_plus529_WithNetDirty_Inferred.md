# Review A (reconstruction fidelity): `aa_005208e0` Character_SetFlagByte_plus529_WithNetDirty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005208e0` |
| **VA** | `0x005208e0` |
| **Canonical name** | `Character_SetFlagByte_plus529_WithNetDirty_Inferred` (Ghidra `FUN_005208e0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005208e0_Character_SetFlagByte_plus529_WithNetDirty_Inferred.md` |
| **System** | character / vehicle ghost net |
| **Evidence pass** | Live `batch_decompile` + `read_memory` (change-detect `@+0x529`, mask `0x100`); callers UnpackGhost / pack helpers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Change-detecting char setter** at character **`+0x529`**. On value change:

1. Store new byte at `this+0x529`.
2. Resolve character NetObject via `*( *(this+4)+4 + this + 0x18 )`; if non-null, `NetObject_SetMaskBits(net, 0x100, 0)`.
3. If vehicle at `this+0x250` has a NetObject at the same relative `+0x18` chain, dirty vehicle with the **same** mask `0x100`.

No-op when new value equals current. No clamp.

**Callers:** `VehicleNet_UnpackGhostVehicle` (`0x005f7720`), `FUN_005ffc20`, `FUN_0060a820`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005208e0_FUN_005208e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005208e0_FUN_005208e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005208e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005208e0_FUN_005208e0.md` |
| Live | `8A 44 24 04  56  8B F1  38 86 29 05 00 00  74 …  88 86 29 05 00 00` + `push 0; push 0x100; call NetObject_SetMaskBits` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = character*
// stack: char value  (ret 4)
void Character_SetFlagByte_plus529_WithNetDirty(void *self, char value);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| value | stack byte | **High** |
| field | `this+0x529` | **High** |
| mask | `0x100` lo, `0` hi | **High** |
| vehicle dual-dirty | `this+0x250` → net `+0x18` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Change-detect then store | **Yes** | **High** |
| Self net dirty `0x100` | **Yes** | **High** |
| Optional vehicle net dirty `0x100` | **Yes** | **High** |
| Early exit when equal | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Byte field `+0x529` | **High** | decomp + bytes |
| Dirty only on change | **High** | cmp before store |
| Mask `0x100` both paths | **High** | imm in body |
| English flag meaning | **Open** | residual (GM/AI/party/… TBD from pack wire) |
| Product name | **Tentative** | inferred offset+behavior |

---

## 6. Gaps

1. Map `+0x529` and ghost mask bit `0x100` to packUpdate / wire field.
2. Confirm vehicle dual-dirty consumers treat bit identically.
3. Whether value is strictly bool (callers may pass 0/1 only).

**Verdict:** **accept-with-gaps**
