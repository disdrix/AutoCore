# Review A (reconstruction fidelity): `aa_00519d20` VehiclePaintColor_LookupById_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519d20` |
| **VA** | `0x00519d20`–`0x00519d72` |
| **Canonical name** | `VehiclePaintColor_LookupById_Inferred` (Ghidra `FUN_00519d20`) |
| **Ghidra name** | `FUN_00519d20` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryUsePaint_00519d20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00519d20_VehiclePaintColor_LookupById_Inferred.md` |
| **System** | vehicle paint / tint / garage UI |
| **Live tools** | `batch_decompile`, lazy loader `00519a30`, paint apply path |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Global **paint/tint color definition lookup by integer id** against hash table globals `DAT_00b042b4` (mask) / `DAT_00b042bc` (bucket heads) / `DAT_00b042b8` (ready count):

```c
// __cdecl (caller cleans) — decompiler bare RET
void* /* color def* or first dword */ VehiclePaintColor_LookupById_Inferred(uint32_t id);
```

Body:

1. If `DAT_00b042b8 < 1` → `FUN_00519a30()` lazy load/build table (DB/XML fill + `FUN_0051e3d0` inserts).
2. Bucket: `*(DAT_00b042bc + (DAT_00b042b4 & id) * 4)` → chain head at `+4`.
3. Walk chain: node key at `node+0x10`; on match take `*(node+0x8)` as value pointer.
4. If value null → return **0**; else return **`*value`** (first dword of payload — used as texture/color handle by consumers).

**Not** the medal table (`DAT_00b042e0` / `MedalDef_LookupById`); adjacent but distinct global block.

### Callers (seal)

| Caller | Use |
|---|---|
| `FUN_004fcd80` vehicle tint refresh | `Lookup(vehicle+0x1a8)` and `Lookup(vehicle+0x1ac)` → feed `FUN_009733d0` |
| Paint setters `004faaf0` / `004fab40` | Share `DAT_00b042b8` + lazy `00519a30`; clamp paint index to table count |
| Garage/UI `FUN_008801b0` | Resolves paint ids for vehicle sheet |
| Tooltip / item UI peers | Multiple `0084xxxx` / `008ffxxx` |

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x00519d20` ≡ raw |
| Lazy loader | `FUN_00519a30` |
| Tint consumer | `FUN_004fcd80` (`_tint.dds` path) |
| Paint packet | `Client_RecvInventoryUsePaint` `0x008095f0` |
| Medal contrast | `MedalDef_LookupById` `0x0051a0e0` (different globals) |
| Raw / clean | `raw/aa_00519d20_*`, `reconstructed-exact/FUN_00519d20.cpp` |

---

## 3. Authoritative body

```c
if (DAT_00b042b8 < 1) FUN_00519a30();
node = bucket_chain_head(DAT_00b042bc, DAT_00b042b4 & id);
while (node) {
  if (node->key_at_0x10 == id) {
    value = *(void**)(node+8);
    return value ? *value : 0;
  }
  node = *(node+0xc);
}
return 0;
```

---

## 4. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B ≡ raw ≡ live | **Confirmed** |
| Lazy load when count `< 1` | **Confirmed** |
| Hash mask/bucket globals | **Confirmed** |
| Returns `*payload` or 0 | **Confirmed** |
| Paint/tint domain (not medals) | **High** (tint.dds + vehicle `+0x1a8/+0x1ac` + paint apply) |
| Product typename of payload | **Open** (`_Inferred`) |
| Full `00519a30` DB schema | **Open** (residual) |

**Verdict:** **accept-with-gaps.**
