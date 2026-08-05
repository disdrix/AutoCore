# Review A (reconstruction fidelity): `aa_00519a30` VehiclePaintColor_EnsureTableLoaded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519a30` |
| **VA** | `0x00519a30`–`0x00519d1a` |
| **Canonical name (Ghidra)** | `FUN_00519a30` |
| **Proposed name** | `VehiclePaintColor_EnsureTableLoaded_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_Client_InitInstance_00519a30` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W16-D) |
| **Reviewer role** | Reconstruction fidelity / dual residual |
| **Counterpart** | `reviews/B_aa_00519a30_VehiclePaintColor_EnsureTableLoaded_Inferred.md` |
| **System** | vehicle paint / tint / garage UI |
| **Live tools** | `decompile_function`, `read_memory`, `audit_globals_in_function`, callers/callees; sibling Lookup dual; loader `007c9230` plate |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Lazy rebuild of the global vehicle paint-color definition hash** consumed by `VehiclePaintColor_LookupById_Inferred` (`0x00519d20`).

```
if (DAT_00b042b8 < 1) FUN_00519a30();  // Lookup / paint setters
```

Pipeline:

1. **SEH** frame `LAB_009a36a5`.
2. **`FUN_0051d1d0(&DAT_00b042ac, 4)`** — recreate `CNDHash` with `1<<4` buckets (bytes: `push 4; mov ecx, 0x00b042ac; call`).
3. Zero three local **0xC-stride** vectors.
4. **`FUN_007e1d80(*DAT_00b0469c)`** — DBReader enter (`PrepareDataConnection` dual).
5. **`FUN_007c9230(...)`** — load three tables; plate paths `//vColorBiomek/row`, `//vColorHuman/row`, `//vColorMutant/row`; fields **`IDColor`**, **`intRGBColor`**, **`intWorth`**.
6. **`FUN_007b7df0(*DAT_00b0469c)`** — DBReader leave.
7. **Phase 1** (vector `local_30`): for each row → `operator_new(0x10)`; `payload[0]=RGB`, `payload[1]=Worth`; **`FUN_0051e3d0(key=IDColor, payload, 0)`** always insert; **`FUN_0051d430`** secondary map insert.
8. **Phase 2** (vector `pvStack_50`): hash-lookup by `IDColor`; miss → insert `RGB` + `Worth` at `payload+8`; hit → `*(payload+8)=Worth`; map insert.
9. **Phase 3** (vector `local_40`): same with `Worth` at `payload+0xC`.
10. Free temp vectors; restore SEH; **return void**.

**Not** the lookup (`00519d20`), not medal table load (`00519660` / `DAT_00b042e0`), not paint apply packet (`008095f0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00519a30` ≡ raw CF |
| Entry / hash recreate | `read_memory` @ `0x00519a30` — `6A 04 B9 AC 42 B0 00 E8…` |
| Globals audit | `DAT_00b042ac/b4/bc`, `DAT_00b0469c`, SEH, map residuals |
| Loader | live `FUN_007c9230` plate strings + 0xC row push |
| Insert | live `FUN_0051e3d0` (hash node key@+0x10, value@+0x8) |
| Recreate | live `FUN_0051d1d0` |
| Sibling dual | `A\|B_aa_00519d20_VehiclePaintColor_LookupById_Inferred` |
| Callers | `get_function_callers` → `004faaf0`, `004fab40`, `00519d20`, `008d1700`, `008d42b0`, `0094a6a0` |
| Raw / clean | updated this pass |

**Not performed:** Launcher, runtime fill, bit-exact, parent ledgers.

---

## 3. Signature / ABI

```c
// __cdecl void — bare ret after FS:[0] restore
void VehiclePaintColor_EnsureTableLoaded_Inferred(void);
```

| Fact | Evidence |
|---|---|
| No stack formals | decompile + callers `call` with no pushes of paint ids |
| SEH | `push LAB_009a36a5`; `ExceptionList` |
| Hash this | absolute `0x00b042ac` into ECX for recreate |
| DB this | `mov ecx, [0x00b0469c]` for enter/query/leave |

---

## 4. Sealed layouts / globals

### Hash object (`DAT_00b042ac`)

| Off / global | Field | Notes |
|---|---|---|
| base `0x00b042ac` | CNDHash object | recreate target |
| `+0x08` / `DAT_00b042b4` | mask | `id & mask` |
| `+0x0c` / `DAT_00b042b8` | entry count | Lookup gate `< 1`; ++ in insert |
| `+0x10` / `DAT_00b042bc` | bucket table* | heads at `bucket+4` chain |

### Hash node (from `FUN_0051e3d0`)

| Off | Field |
|---|---|
| `+0x08` | payload* (`0x10` block) |
| `+0x0c` | next chain |
| `+0x10` | key (`IDColor`) |

### Payload (`0x10`)

| Off | Phase writer | Field |
|---|---|---|
| `+0x00` | all inserts | `intRGBColor` — **Lookup returns this dword** |
| `+0x04` | phase 1 | `intWorth` (first vector) |
| `+0x08` | phase 2 insert/update | `intWorth` (second vector) |
| `+0x0c` | phase 3 insert/update | `intWorth` (third vector) |

### Row (`0x0C`) from loader

| Off | Plate field |
|---|---|
| `+0x00` | `IDColor` |
| `+0x04` | `intRGBColor` |
| `+0x08` | `intWorth` |

---

## 5. Callees (roles)

| VA | Name / plate | Role | Conf |
|---|---|---|---|
| `0x0051d1d0` | CNDHash recreate (`VOG_DEBUG_STOP` sibling) | rebuild buckets power 4 | **Confirmed** |
| `0x007e1d80` | `DBReader_PrepareDataConnection` | enter | **Confirmed** (dual) |
| `0x007c9230` | vColor* loader | three vectors of 0xC rows | **High** |
| `0x007b7df0` | `DBReader_ReleaseDataConnection` | leave | **Confirmed** (dual) |
| `0x0051e3d0` | CNDHash insert | key+payload | **Confirmed** |
| `0x0051d430` | map insert by int key | secondary ordered index | **High CF / name Tentative** |
| `operator_new(0x10)` | payload alloc | **Confirmed** |
| `operator_delete` | free temp vectors | **Confirmed** (SEH noise) |

---

## 6. Callers

| Caller | Use |
|---|---|
| `VehiclePaintColor_LookupById` `0x00519d20` | `if (DAT_00b042b8 < 1) Ensure()` |
| `FUN_004faaf0` / `004fab40` | set vehicle `+0x1a8` / peer paint idx; clamp to `DAT_00b042b8` after ensure |
| `FUN_008d1700`, `008d42b0`, `0094a6a0` | additional ensure xrefs (UI/init residual) |

---

## 7. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH + recreate(hash,4) | **Yes** |
| DB enter → `007c9230` → leave | **Yes** |
| Phase1 always-insert | **Yes** |
| Phase2 lookup insert/update +8 | **Yes** |
| Phase3 lookup insert/update +0xC | **Yes** |
| Free + return | **Yes** (SEH restore naming noise only) |

---

## 8. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Lazy paint-color table build | **Confirmed** | Lookup sibling |
| Hash globals b042ac/b4/b8/bc | **Confirmed** | |
| DB bookend + vColor* domain | **High** | loader plate |
| Row IDColor/RGB/Worth | **High** | strings in `007c9230` |
| Payload+0 = Lookup return dword | **Confirmed** | Lookup `return *payload` |
| Three-phase merge by id | **Confirmed** | |
| Faction↔phase binding | **Tentative** | stack/out-arg map residual |
| `0051d430` product structure | **Tentative** | ordered id map likely |
| Uninit payload holes | **High** | `new` without zero |
| Product function name | **Tentative** | `_Inferred` |
| Runtime / bit-exact | **Open** | |

---

## 9. Gaps / open

1. Exact mapping of phase 1/2/3 vectors → Biomek/Human/Mutant after `007c9230` arg bind.
2. Secondary map host for `FUN_0051d430` (globals `DAT_00b04288` / `94` / `a0` residual).
3. Whether +4/+8/+0xC are truly per-faction **worth** only or overloaded.
4. `operator_new(0x10)` without zero — single-faction ids leave garbage in unset slots (Lookup only needs +0).
5. Decompiler `ExceptionList = local_20` falsified by epilogue bytes (restores SEH saved list).

**Verdict:** **accept-with-gaps** — CF + domain + hash/payload contract sealed; faction-phase bind and secondary map naming residual.
