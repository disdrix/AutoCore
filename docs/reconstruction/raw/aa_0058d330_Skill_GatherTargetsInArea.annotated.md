# Annotated low-level: Skill_GatherTargetsInArea (`aa_0058d330`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d330` |
| **VA** | `0x0058d330` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_0058d330_Skill_GatherTargetsInArea.md` (capture 2026-07-23) |
| **Confidence** | Function role **INFERRED** (area/chain multi-target collect); control structure **High**; mode table CF **sealed** 2026-07-29 strengthen (`reviews/a_0058d330.md`) |

---

## 1. Signature (parameter roles — Probable)

```c
void Skill_GatherTargetsInArea(
    TFID_16* outList,          // param_1 — output TFID array (stride 0x10)
    int      startIndex,       // param_2 — starting slot index (short used)
    undefined4 queryCtx,       // param_3 — spatial query arg
    ObjectEntity* pCaster,     // param_4 — caster; vtbl+0x1c8 / +0x19c / +0x210
    TFID_16* originTfid,       // param_5 — 4 dwords copied to local origin
    undefined4 radiusOrMode,   // param_6 — passed to distance + query
    int      maxTargets,       // param_7 — decremented; stop when < 1
    int      filterMode,       // param_8 — 0,1,3,6,7,10,11… branch key
    undefined4 filterArg,      // param_9
    char     bChainReorigin,   // param_10 — if set, move origin to last hit
    char     bAllowSelfMode,   // param_11 — with mode 1
    undefined4 a12, a13,       // filter extras into FUN_0058a810
    char     bSortByDistance,  // param_14 — deferred insert path
    undefined4 a15);           // into distance helper
```

Widths: all stack args standard 32-bit; `char` flags use low byte. Names beyond plate are **Probable**.

---

## 2. Phases

### Phase A — setup

```text
local_ac = FUN_0058d9c0()          // intrusive list/node arena head
local_ac[+0x29] = 1; ring-link self
copy origin TFID from param_5 → local_80..local_74
casterBody = pCaster->vtbl+0x1c8()
if casterBody == 0:
    FUN_00567ce0(&DAT_00af32a0, 0x38d1b717)   // fallback spatials / assert cookie
else:
    pos = (body interior)->vtbl+0x1a4()        // position float3/4
FUN_004e8a40(&pos, auStack_50)                 // normalize / matrix helper
```

### Phase B — broadphase gather

```text
queryFlags = 1
if 0 < filterMode < 3: queryFlags = 0x11   // modes 1 (ally) and 2 (hostile)
else if filterMode == 7: queryFlags = 10

FUN_004ea350(queryCtx, originTfid, radiusOrMode, outVec, 0, queryFlags)
// fills pvStack_9c vector of candidate object pointers
```

### Phase C — filter candidates into pointer vector `pvVar7`

For each candidate `obj` in broadphase vector (prefer-**nonzero** primary for 7/10):

| `filterMode` | Test | Keep rule |
|---:|---|---|
| `7` | interior vtbl `+0x1dc` | **nonzero** → take entity slot immediately; **0** → fall into `+0xd4` then `+0xdc` link path |
| `10` | vtbl `+0x198` | **nonzero** (dead-like) → take entity slot immediately; **0** → link path |
| `6` | skip `+0xd4` | only `+0xdc` nonzero → entity slot |
| other | `LAB_0058d534` | `+0xd4` nonzero else `+0xdc` nonzero |

Kept objects store **entity interior base** (`link+4+obj`) into a growable int vector (`FUN_004073a0` when capacity tight).

### Phase D — accept into TFID outList

```text
factionOrTeam = 0
if pCaster->vtbl+0x19c(): factionOrTeam = *(seat+0x34)

for each kept entity:
    if bChainReorigin && casterBody && entity->vtbl+0x1c8() == casterBody:
        skip                                    // don't retarget same body
    if !FUN_0058a810(entity, caster, outList, mode, ...):
        skip                                    // relationship / hostility filter Probable

    // self rules: allow if mode in {0, 0xB, or (1 && bAllowSelfMode)}
    dist = FUN_004e9aa0(&origin, factionOrTeam, radiusOrMode, entityPos)

    if !bSortByDistance:
        write entity TFID (entity+0x160.. as [0x58..0x5b] dword indices) to outList[startIndex++]
        if bChainReorigin: origin = entity position (chain lightning style)
        if maxTargets hits 0: break
    else if dist > 0:
        push (dist, tfid) into sort structure FUN_0058def0

    if startIndex == 99: break                  // hard cap 99 targets
```

If `bSortByDistance`: `FUN_0058c7a0` flushes sorted hits into `outList` with `maxTargets` limit.

### Phase E — terminate + free

```text
outList[startIndex] = DAT_009d4d28..34          // invalid TFID terminator (16B)
operator_delete broadphase vector
operator_delete filter vector / list arena
```

---

## 3. Output format

| Item | Size | Notes |
|---|---:|---|
| Each TFID | `0x10` | 4×u32; written at `outList + index*0x10` |
| Terminator | `0x10` | `DAT_009d4d28` family (invalid) |
| Max before forced break | 99 | `local_d4` compared as short |

Distinct from `0x2031` on-wire target records (`0x18` with mana fields) — this helper fills **TFID-only** lists for later packers.

---

## 4. Side-effect order

1. Construct temporary list arena + origin copy.
2. Broadphase query → heap vector of objects.
3. Filter → second vector of entity interiors.
4. Writes to **caller-provided** `outList`.
5. May relocate origin for chain mode (local only).
6. Free temps (decompiler “noreturn” on `operator_delete` is EH noise).

No network. No skill field mutation.

---

## 5. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| Huge stack frame / many `uStack_*` | Temporaries for TFID, pos, SEH, two vectors | **High** |
| `param_8` magic 0/1/2/3/4/6/7/8/9/10/0xb | **Gather mode enum** — **CF sealed** 2026-07-29 strengthen (query/pass-1/accept/self + callers); English names **INFERRED** | **High** CF |
| `piVar8[0x58]` TFID | dword index `0x58` → offset **0x160** (standard entity TFID) | **High** |
| Cap `99` | Hard-coded max targets in this gatherer | **Confirmed** |
| `operator_delete` noreturn | Same allocator warning as other units | **High** |

---

## 5b. Mode table (`param_8`) — residual seal 2026-07-29

See `reviews/a_0058d330.md` for full evidence (body + `FUN_0058a810` + callers + `CloneBaseObjectType`).

| Mode | INFERRED role | Query flags | Pass-1 / accept highlights |
|---:|---|---:|---|
| 0 | Self / related-owner | 1 | `+0x214` equals caster; self OK |
| 1 | Ally / non-hostile | `0x11` | `+0x298==0`; self if `param_11` |
| 2 | Hostile / enemy | `0x11` | `+0x298!=0` |
| 3 | Living interact | 1 | types `0xe` Veh / `0x12` Cre / `0x14` Char only |
| 4 | Same related TFID | 1 | dual `+0x214` TFID match |
| 6 | `+0xdc`-only broadphase | 1 | skip `+0xd4` gate |
| 7 | Type-filtered special | 10 | `+0x1dc`; callers often `filterA=0x14` |
| 8 | Unfiltered | 1 | early accept in helper |
| 9 | Type-3 or hostile | 1 | type==3 else `+0x298` |
| 10 | Dead / corpse-like | 1 | allows `vtbl+0x198!=0` |
| 0xb | Same vehicle/crew | 1 | `+0x210` / `FUN_005749d0`; self OK |

Skill path: `gatherMode = skill+0x60c`, `filterA = skill+0x610`.

---

## 6. Call-graph context

Used when skill flags request multi-target / splash / chain resolution (plate). Feeds lists consumed by `Skill_ResolveTargetList` / cast packers. Sibling spatial helpers: `FUN_004ea350` (query), `FUN_004e9aa0` (distance), `FUN_0058a810` (pair filter).

---

## 7. Open questions

- Retail / PDB names for `filterMode` integers (behavior sealed).
- Name `FUN_0058a810` / spatial helpers (out of this unit ownership).
- Units of `radiusOrMode` / distance helper.
- Runtime / bit-exact / image diff.
