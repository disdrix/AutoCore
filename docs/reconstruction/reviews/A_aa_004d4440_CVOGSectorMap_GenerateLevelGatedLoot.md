# Review A (reconstruction fidelity): `aa_004d4440` CVOGSectorMap_GenerateLevelGatedLoot

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d4440` |
| **VA** | `0x004d4440` |
| **Canonical name** | `CVOGSectorMap_GenerateLevelGatedLoot` |
| **Ghidra name** | `FUN_004d4440` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004d4440_CVOGSectorMap_GenerateLevelGatedLoot.md` |
| **System** | `inventory-transfer` / kill loot |
| **Verdict** | **accept-with-gaps** — major phases sealed; loot-table builder residual |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Level-gated loot generation + world drop (or dump-to-FILE)** for a victim/template context.

Large unit (`__chkstk` / ~4K path buffer). Parent kill dual groups with credits floaters; also called from `0x0057e0da` and dispatch path.

### High-level phases

1. **Level delta gate**  
   `level = victim->…->vtbl[+0x27c]()` (deep this-adjust).  
   `delta = level - param_2`.  
   If `delta >= 11` → fall through → return `uVar5 & 0xffffff00` (failure / no-loot class).

2. **Context + drop-chance**  
   - `FUN_004ce940(param_5)` world/context touch.  
   - `def = FUN_00508dc0(param_5)`; if null → fail return.  
   - `chance = *(float*)(def + 0x10)`.  
   - Unit RNG; if `chance <= unit` → **early success return 1** (no items rolled — “no drop this time” still low-byte 1).

3. **Build CBID vector**  
   `FUN_0050b890(outVec, param_2, *(byte*)(…template…+0x532), 1)` — fills `std::vector`-like dword list of CBIDs.

4. **For each CBID**  
   - `item = CVOGReaction_GiveItemByCbid(cbid)`; null → delete vector, return 0.  
   - `init = item->vtbl[+0x08](cbid, map, 1)`; if non-zero **break** (abort loop; cleanup path).  
   - Optional: if `item[0x2a]+0x3c` def present → `FUN_00509c70` (mod/affix apply).  
   - `item[0x5c..]` ← `FUN_00521510(param_4)` pose/id blob.  
   - Optional bonus roll vs `DAT_00aaa8ec` (**0.08f**): hash lookup `map+0xfc` → maybe `FUN_00513de0(1)`.  
   - If `param_6 == 0` (live place): `PlaceWorldObject(item, param_4, 5.0f, 1)`.  
   - Else (dump mode): zero 4K buffer, `sprintf("%s:%i\n", name via vtbl+0x15c)`, `fwrite` to `param_7`, destroy item `vtbl[0](1)`.

5. **Cleanup / return**  
   Vector delete; success path returns low-byte **1**; other fails clear low byte.

---

## 2. ABI (decompiler-derived)

```c
// __thiscall this = sector map*
uint CVOGSectorMap_GenerateLevelGatedLoot(
    Map* this,
    int levelBaseOrPlayerLevel,  // param_2 — subtracted from victim level
    int* victimOrTemplate,       // param_3 — deep vtbl level + template byte @ path
    void* posOrSource,           // param_4 — pose for PlaceWorldObject / FUN_00521510
    void* lootKey,               // param_5 — into 004ce940 / 00508dc0
    char dumpMode,               // param_6 — 0 place world, else FILE dump
    FILE* dumpFile);             // param_7 — only if dumpMode
```

Return: low byte 1 on “handled ok” (including chance-miss early out); 0 / high-bits-cleared on hard fail.

---

## 3. Constants (read_memory)

| Symbol / imm | Value | Role |
|---|---|---|
| level delta max | **11** | `delta < 11` required |
| `DAT_00aaa638` | 1/65536 | unit RNG scale |
| place radius | **5.0f** (`0x40a00000`) | `PlaceWorldObject` |
| `DAT_00aaa8ec` | **0.08f** | secondary bonus roll threshold |

---

## 4. Callers

| VA | Note |
|---|---|
| `0x004dae52` | OnDeathAwardKillXp loot arm |
| `0x0057e0da` | other loot/dispatch consumer |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Level delta &lt; 11 gate | **Confirmed** |
| Chance float at def+0x10 | **Confirmed** |
| Per-CBID GiveItemByCbid + place r=5 | **Confirmed** |
| Dump mode sprintf/fwrite | **Confirmed** |
| `FUN_0050b890` full loot table algorithm | **Medium** (callee residual) |
| Exact victim this-adjust chain | **Medium** |

---

## 6. Gaps

1. Dual `FUN_0050b890` (CBID list builder).
2. Dual `FUN_00508dc0` / loot def layout.
3. `FUN_00509c70` affix apply.
4. Bonus path `FUN_00513de0` product meaning.
5. Precise return-code matrix for AutoCore port.

**Verdict:** **accept-with-gaps**.
