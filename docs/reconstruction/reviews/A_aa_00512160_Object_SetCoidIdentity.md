# Review A (reconstruction fidelity): `aa_00512160` Object_SetCoidIdentity

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512160` |
| **VA** | `0x00512160` |
| **Canonical name** | `Object_SetCoidIdentity` |
| **Ghidra name** | `FUN_00512160` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00512160_Object_SetCoidIdentity.md` |
| **System** | `inventory-transfer` / object identity |
| **Verdict** | **accept** — pure 3-store setter; sealed by body + registry |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Set COID identity triple on an object**: write 64-bit COID (`lo`/`hi`) and a one-byte flag.

```c
// __thiscall this = object*
void Object_SetCoidIdentity(object* this, uint32_t coidLo, uint32_t coidHi, uint8_t flag)
{
  this->byte_at_0x168 = flag;   // +0x168
  this->coidLo        = coidLo; // +0x160
  this->coidHi        = coidHi; // +0x164
}
```

Live decompile (full body):

```
*(undefined1 *)(param_1 + 0x168) = param_4;
*(undefined4 *)(param_1 + 0x160) = param_2;
*(undefined4 *)(param_1 + 0x164) = param_3;
return;
```

Matches `NAMING_REGISTRY.md` proposed row: *thiscall write COID +0x160/164 flag +0x168*.

---

## 2. ABI (SEALED)

| Slot | Role |
|------|------|
| **ECX** | object* |
| stack arg0 | coidLo → `+0x160` |
| stack arg1 | coidHi → `+0x164` |
| stack arg2 | flag u8 → `+0x168` |
| return | void |

---

## 3. Inspected artifacts

| Artifact | Path |
|---|---|
| Live decompile | Ghidra `0x00512160` |
| Raw / clean | `raw/aa_00512160_*`, `reconstructed-exact/FUN_00512160.cpp` |
| Function record | `functions/aa_00512160_FUN_00512160.md` |
| Registry | `NAMING_REGISTRY.md` → `Object_SetCoidIdentity` |
| Callers (sample) | `004d2750`, `004d2820`, `00811be0` (grab split), many create/spawn paths |

---

## 4. Call-site pattern (kill/loot)

Typical map allocator pattern (see `004d2750` / `004d2820`):

1. Read map 64-bit counter at `map+0xe6e0` / `+0xe6e4`.
2. Post-increment with carry (`0xfffffffe < lo`).
3. `Object_SetCoidIdentity(item, oldLo, oldHi, 1)`.

Grab-response dual already documents split bind via this unit.

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Three stores only; no branches | **Confirmed** |
| Offsets `+0x160/+0x164/+0x168` | **Confirmed** |
| Name `Object_SetCoidIdentity` | **High** (registry + COID field usage) |
| Flag meaning of `+0x168` beyond “written by callers as 1” | **Medium** |

---

## 6. Gaps

1. Semantic of flag `+0x168` values other than `1` not enumerated.
2. Whether COID is always map-global monotonic remains caller-local.

**Verdict:** **accept**.
