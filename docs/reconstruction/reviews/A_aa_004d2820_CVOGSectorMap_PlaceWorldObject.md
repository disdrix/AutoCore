# Review A (reconstruction fidelity): `aa_004d2820` CVOGSectorMap_PlaceWorldObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d2820` |
| **VA** | `0x004d2820` |
| **Canonical name** | `CVOGSectorMap_PlaceWorldObject` |
| **Ghidra name** | `FUN_004d2820` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004d2820_CVOGSectorMap_PlaceWorldObject.md` |
| **System** | `inventory-transfer` / world loot place |
| **Verdict** | **accept-with-gaps** — place pipeline sealed; vtbl names residual |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Register / place an already-constructed object into the sector map world**, ensuring it has a COID, then drop it on the ground and set a related flag.

Pipeline:

1. `obj->vtbl[+0x218](map)` — attach/register with map.
2. If `(obj[0x58] & obj[0x59]) == 0xffffffff` — **both COID dwords are −1** (no identity yet):
   - post-inc `map+0xe6e0` 64-bit counter (same as `004d2750`);
   - `Object_SetCoidIdentity(obj, oldLo, oldHi, 1)`;
   - `obj->vtbl[+0x2a4](*(map+0xe4e8))`.
3. Always: `CVOGSectorMap_DropObjectOnGround(map, obj, pos/radius args…)` (`FUN_004d0ed0`).
4. `related = obj->vtbl[+0x1d4]()` twice; if non-null, set `*(related + 0x2ac) = 1`.

### Callers (xrefs)

| From | Context |
|---|---|
| `004d32a7` | `004d31a0` chance special drop |
| `004d46fb` | `004d4440` loot table place (radius **5.0f**) |
| `004dadxx` region | kill XP loot objects |
| `00531028` | inventory add fail → world path (`Client_SendInventoryAddItem` dual) |
| `0050b656`, `0061234c`, `00612436` | other loot/collect paths |

Parent kill dual labels this as **loot objects** path (vs credits floaters).

---

## 2. ABI (decompiler-derived)

```c
// __thiscall this = sector map*
void CVOGSectorMap_PlaceWorldObject(
    Map* this,
    Object* obj,       // param_2 — existing item/object*
    /* pos / radius / flags from stack — decompiler shows param_3, param_4
       forwarded into DropObjectOnGround */);
```

`004d4440` call site: `FUN_004d2820(item, param_4, 0x40a00000, 1)` → radius **5.0f**, flag **1**.  
`004d31a0` call site: radius **1.0f** (`0x3f800000`), flag **1**.

---

## 3. Identity gate (SEALED)

```
if ((obj[+0x160] & obj[+0x164]) == 0xffffffff)  // via dword indices 0x58/0x59
  assign next map COID + bind context
```

`0x58 * 4 = 0x160`, `0x59 * 4 = 0x164` — same COID fields as `Object_SetCoidIdentity`.  
`(a & b) == −1` is true iff **both** are all-bits-one.

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Map attach vtbl+0x218 first | **Confirmed** |
| Missing COID → allocate + stamp | **Confirmed** |
| Always drop on ground | **Confirmed** |
| Sets related `+0x2ac = 1` via vtbl+0x1d4 | **Confirmed** (semantics Medium) |
| Used for loot / failed inventory place | **High** (xrefs + parent duals) |

---

## 5. Gaps

1. Product names for vtbl `+0x218`, `+0x2a4`, `+0x1d4`.
2. Exact meaning of `+0x2ac` flag (seen on vehicles as special flag elsewhere).
3. Full DropObjectOnGround arg recovery per call site.

**Verdict:** **accept-with-gaps**.
