# Dual A/B report — W19-F OWN-ONLY (`0x0059c000`, `0x004ce5f0`)

**Date:** 2026-07-29  
**Agent:** W19-F OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0059c000`, `0x004ce5f0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0059c000` CloneBase_AllocAndLoadByType | **accept-with-gaps** — **cdecl materialize by type, alloc/load map, E_FAIL default, record offsets sealed; product type English + cache open** |
| `aa_004ce5f0` Character_HostModeGateForObjectV210 | **accept-with-gaps** — **thiscall+ret4 leaf gate, MI vcall+0x210(0), host +0xf5/+0x7e sealed; flag/vfunc product English open** |

---

## `aa_0059c000` — CloneBase_AllocAndLoadByType

### Sealed facts

1. **ABI:** `int32_t CloneBase_AllocAndLoadByType(record*)` — **stack arg**, epilogue bare **`ret`** (cdecl). Body `0x0059c000`–`0x0059c443`.

2. **Optional cache:** if `DAT_00b04694`, `FUN_00540850(record+0x34)` → `record+0x3c`; non-null skips type switch to name-fill.

3. **Type switch** on `record+0x38` via index `0x0059c474` + jumps `0x0059c444`. Default returns **`0x80004005` (`E_FAIL`)** (bytes `B8 05 40 00 80`; decomp `-0x7fffbffb`).

4. **Per-type alloc + load** sealed (generic `0x4c0`/vtbl `0x009d55fc`; vehicle **`0xe`** size `0x744` → `VehicleDb_LoadCloneBase`; powerplant **`10`** → `DB_ReadPowerPlantSpecific`; etc.).

5. **Record map:** `+0x34` cbid; `+0x38` type; `+0x3c` object*; `+0x40` name; `+0x188` secondary name (`strncpy` 0x41).

6. **Success:** name convert via `PTR_FUN_00af8c9c` + `FUN_00403450` into `obj+0x10`; return **0**. Loader non-zero → propagate.

7. **Callers:** `FUN_004f1e20`, `FUN_004eb0c0`. Parent-seed VOG_DEBUG_STOP name is **failure-log only**.

8. **Live decompile ≡ 2026-07-23 raw.**

### Gaps

1. Product/PDB symbol.  
2. Full type→product-class English.  
3. Cache flag / `FUN_00540850` semantics (other VAs).  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0059c000_CloneBase_AllocAndLoadByType.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0059c000_CloneBase_AllocAndLoadByType.md` |
| Function record | `docs/reconstruction/functions/aa_0059c000_CloneBase_AllocAndLoadByType.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CloneBase_AllocAndLoadByType.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0059c000.cpp` |
| Raw | `docs/reconstruction/raw/aa_0059c000_FUN_0059c000.md` |
| Annotated | `docs/reconstruction/raw/aa_0059c000_FUN_0059c000.annotated.md` |

---

## `aa_004ce5f0` — Character_HostModeGateForObjectV210

### Sealed facts

1. **ABI:** `bool __thiscall Gate(host, object)` — ECX=host, stack object*, **`ret 4`**. Body `0x004ce5f0`–`0x004ce632`.

2. **CF:** null object → false; MI-adjust object; **`vtbl+0x210(0)`**; null → false; else `host+0xf5` **or** `host+0x7e`.

3. **Leaf** — no external CALLs; only indirect vcall. Full body hex sealed.

4. **Callers (6):** TryEquipItem type 0xe; type 0x10 helper; hardpoint drop ×2; confirm path; equip-family helper. False → equip status **1** at known sites.

5. **Not** confirm-only; **not** Broken (9); **not** host vcall with `(0,1)`.

6. **Live decompile ≡ 2026-07-23 raw.**

### Gaps

1. Product English for host `+0xf5` / `+0x7e`.  
2. Product name for object vfunc `+0x210`.  
3. PDB symbol.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004ce5f0_Character_HostModeGateForObjectV210.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004ce5f0_Character_HostModeGateForObjectV210.md` |
| Function record | `docs/reconstruction/functions/aa_004ce5f0_Character_HostModeGateForObjectV210.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_HostModeGateForObjectV210.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004ce5f0.cpp` |
| Raw | `docs/reconstruction/raw/aa_004ce5f0_FUN_004ce5f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004ce5f0_FUN_004ce5f0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### CloneBase_AllocAndLoadByType (`0x0059c000`)

- Port as **type-dispatch materialize**, not a single vehicle loader and not a debug helper.
- Preserve **E_FAIL** on unknown type; surface loader HRESULTs.
- Keep record offsets `+0x34/+0x38/+0x3c/+0x40/+0x188` aligned with ensure-load parent `FUN_004f1e20`.
- Vehicle type **`0xe`** still bottoms in `VehicleDb_LoadCloneBase` (separate dual ownership).

### Character_HostModeGateForObjectV210 (`0x004ce5f0`)

- Port as **pure predicate** — no equip mutations at this VA.
- Vehicle equip path: gate false → client status **1** (distinct from Broken **9**).
- Preserve object **MI + vtbl+0x210(0)** and host **`+0xf5` / `+0x7e`** offsets without inventing product flag names until sealed.
