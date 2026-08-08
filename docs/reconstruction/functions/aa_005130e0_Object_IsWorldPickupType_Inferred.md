# Function record: Object_IsWorldPickupType_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005130e0` |
| **Canonical name** | `Object_IsWorldPickupType_Inferred` |
| **Ghidra name** | `FUN_005130e0` |
| **Address** | `0x005130e0`–`0x0051314d` (code body **0x6E** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / client-interact / object-type filter |
| **Classification** | worker |
| **Dual verdict** | **accept-with-gaps** (A∩B WQ9R-C 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Return whether a cloned world object’s type is eligible for soft skill-filter / world-pickup treatment:

- Optional loose gate (`requireLoose` → `this+0xac==0`).
- Type table on clonebase `+0x38` (Object bit7 / fixed loot types / special Vehicle).

## Signature

```c
uint8_t __thiscall Object_IsWorldPickupType_Inferred(void *this, char requireLoose);
```

## Sealed facts

1. thiscall; `RET 4`; AL bool.
2. Type accept: 1(bit), 4,6,8,10,0xc,0x10,0x1a,0x1c,0x32,0x34,0x42; Vehicle 0xe + RTTI + `+0x2ac`.
3. Creatures/Characters fail.
4. Eight callers including gather pair filter and interact pickup prompt.

## Gaps

- Product C++ name.
- English for `this+0xac` and vehicle `+0x2ac`.
- Runtime confirmation.

## Artifacts

See `aa_005130e0_FUN_005130e0.md` for full artifact list.
