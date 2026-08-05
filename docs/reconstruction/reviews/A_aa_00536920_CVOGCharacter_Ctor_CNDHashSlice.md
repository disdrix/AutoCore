# Review A (reconstruction fidelity): `aa_00536920` CVOGCharacter_Ctor (CNDHash slice)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536920` |
| **VA** | `0x00536920` |
| **Canonical name** | `CVOGCharacter` constructor (mission **CNDHash** heap installs) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00536920_CVOGCharacter_Ctor_CNDHashSlice.md` |
| **System** | missions-progression / CNDHash family / character |
| **Live tools** | `batch_decompile`; sealed AllocBuckets duals; NAMING_REGISTRY field map; callers |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose (CNDHash-focused)

Large `__thiscall` character constructor. This dual **seals the CNDHash object installs** only; remaining character fields (vtbls, maps, tick stamps, skill slots) are noted as out-of-scope residual.

### Signature

```c
CVOGCharacter* __thiscall Ctor(CVOGCharacter *this, int bFullBaseInit /*param_2*/);
```

When `param_2 != 0`: installs base subobject fixups (`DAT_009d0004` / `DAT_009cfffc`) + `FUN_00518940` under SEH state 0. Always continues into character body init.

### CNDHash heap installs (each `operator_new(0x34)` + inline field init + AllocBuckets)

| Char off | dword idx | Object vtbl | bits | size pre-Alloc | AllocBuckets | Product name (registry / residual) |
|---|---|---|---|---|---|---|
| `+0x534` | `0x14d` | `PTR_FUN_009cfa64` | 8 | `0x100` | `FUN_00537a10` | mission-adjacent hash (recreate `00539d70`) |
| `+0x540` | `0x150` | `PTR_FUN_009cfa4c` | 4 | `0x10` | `FUN_005378d0` | `charActiveMissionsHash` |
| `+0x544` | `0x151` | `PTR_FUN_009cfa4c` | 4 | `0x10` | `FUN_005378d0` | sibling 16-bucket `009cfa4c` |
| `+0x538` | `0x14e` | `PTR_FUN_009cfa4c` | 8 | `0x100` | `FUN_005378d0` | `charCompletedMissionsHash` |
| `+0x53c` | `0x14f` | `PTR_FUN_009cfa4c` | 8 | `0x100` | `FUN_005378d0` | `charInstanceCompletedMissionsHash` |
| `+0x548` | `0x152` | `PTR_FUN_009cfa58` | 4 | `0x10` | `FUN_00537970` | `charActiveObjectivesHash` |
| `+0x6f0` | `0x1bc` | `PTR_FUN_009cfa70` | 4 | `0x10` | `FUN_00537ab0` | extra `009cfa70` table |
| `+0x530` | `0x14c` | `PTR_FUN_009cfa7c` | 4 | `0x10` | `FUN_00537b50` | recreate via `00539dd0` |
| `+0x55c` | `0x157` | `PTR_FUN_009cfa88` | 2 | `4` | `FUN_00537bf0` | `charPendingObjectivesHash` |

Each install body (identical layout, stamp deltas only):

```
*hash = object_vtbl;
hash[+4]=0; hash[+8]=size; hash[+0xc]=0; buckets/head/tail=0;
log2Bits@+0x1c; lock@+0x1d=0; freelist@+0x20=0; slab vec +0x28..+0x30=0;
AllocBuckets_*(hash);  // size → mask
*(char + field) = hash;  // null if operator_new failed
```

Object footprint **0x34** matches sealed CNDHash ctor duals.

### Related non-hash containers in same ctor (context only)

- RB/map head at `+0x50c` (`param_1[0x143]`) via `FUN_00538270` — mission staging map family (not CNDHash).
- Other tree heads `+0x588`, `+0xc74` — out of CNDHash dual scope.

### Callers

| Site | Role |
|---|---|
| `CVOGReaction_GiveItemByCbid` @ `0x0051a170` | name-seed from alias |
| `FUN_00854d20`, `FUN_00855810`, `FUN_008fa9f0` | client/character create paths |

---

## 2. Confidence

| Claim | Level |
|---|---|
| Nine `operator_new(0x34)` CNDHash installs with listed stamps | **Confirmed** |
| Field offsets = dword_index×4 | **Confirmed** |
| Registry mapping for `+0x538/+0x53c/+0x540/+0x548/+0x55c` | **High** |
| Size→mask via AllocBuckets twins | **Confirmed** (sealed duals) |
| `param_2` gates partial base init | **Confirmed** |
| Full character layout (non-hash) | **Open** residual |
| Product English class name | **Probable** (`CVOGCharacter`) |

---

## 3. Gaps

1. Semantic product names for `+0x530`, `+0x534`, `+0x544`, `+0x6f0` beyond recreate/reset usage.
2. Full SEH state machine / base-class chain beyond hash installs.
3. Whether `operator_new` null leaves dangling null slots safely on all paths — High for write, Open for later null checks.

**Verdict:** **accept-with-gaps** — CNDHash install table + offsets sealed High; rest of ctor residual.
