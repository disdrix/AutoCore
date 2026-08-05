# Review A (reconstruction fidelity): `aa_0052b4e0` CVOGCharacter_WipeMissionMaps_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b4e0` |
| **VA** | `0x0052b4e0` |
| **Canonical name** | `CVOGCharacter_WipeMissionMaps_Inferred` (structural) |
| **Ghidra name** | `FUN_0052b4e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0052b4e0_CVOGCharacter_WipeMissionMaps_Inferred.md` |
| **System** | missions-progression / character mission hashes |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bulk mission-map wipe** on a character object: recreate two CNDHash instances and **vtbl+4 clear** five mission-related maps.

Linear body (no branches):

```
CNDHash_Recreate( *(char+0x530), *(char+0x530)->log2Bits@+0x1c );   // FUN_00539dd0 / vtbl 009cfa7c
(*(char+0x548)->vtbl + 4)();   // clear — active objectives hash (system map)
(*(char+0x540)->vtbl + 4)();   // clear — active missions
(*(char+0x538)->vtbl + 4)();   // clear — completed
(*(char+0x53c)->vtbl + 4)();   // clear — completed instance
(*(char+0x544)->vtbl + 4)();   // clear — sibling mission map
CNDHash_Recreate( *(char+0x55c), *(char+0x55c)->log2Bits@+0x1c );   // FUN_00539e30 / pending objectives
```

Slot map (from `systems/missions-progression.md` + sealed recreate duals):

| Offset | Role |
|---|---|
| `+0x530` | Mission-related CNDHash (recreate twin `009cfa7c`) |
| `+0x538` / `+0x53c` | Completed mission hashes |
| `+0x540` | Active missions |
| `+0x544` | Sibling map (GiveMission insert path) |
| `+0x548` | Active objectives |
| `+0x55c` | Pending objectives (recreate twin end) |

**ABI:** `__fastcall` / this in ECX (`param_1` = character).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0052b4e0_*`, `reconstructed-exact/FUN_0052b4e0.cpp` |
| Function record | `functions/aa_0052b4e0_FUN_0052b4e0.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x0052b4e0` (2026-07-29) ≡ clean |
| Bytes | `read_memory` 48 B — `mov esi,ecx`; load `[esi+0x530]`; `push [eax+0x1c]`; `call 00539dd0`; five `call [edx+4]` |
| Recreate duals | `A_aa_00539dd0_CNDHash_Recreate_009cfa7c.md`, `A_aa_00539e30_CNDHash_Recreate_009cfa88.md` |
| System map | `systems/missions-progression.md` (slots 538/53c/540/55c/548) |
| Callers | `FUN_009466f0` (site `00946a05`); also xref `0094ead3` |

**Not performed:** disassemble_bytes, Launcher, runtime, full caller dual.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body ≡ raw ≡ live; linear 7 steps | **Confirmed** | decompile + bytes |
| First recreate is `+0x530` via `00539dd0` with bits `@+0x1c` | **Confirmed** | body + sealed dual |
| Last recreate is `+0x55c` via `00539e30` | **Confirmed** | body + sealed dual |
| Five middle clears are vtbl+4 on 548/540/538/53c/544 | **Confirmed** | order in decompile |
| Slot roles active/completed/pending | **High** | system map |
| Product English for `+0x530` / `+0x544` | **Open** / Probable | map partial |
| Caller semantic (full char reset vs mission-only) | **Tentative** | not dualed here |
| clean ≡ raw | **High** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Recreate +0x530 | Yes |
| Clear 548, 540, 538, 53c, 544 (vtbl+4) | Yes |
| Recreate +0x55c | Yes |
| No other branches | Yes |

### Recovered CF

```c
// void __fastcall CVOGCharacter_WipeMissionMaps(Character* ch)
CNDHash_Recreate_009cfa7c(ch->hash530, ch->hash530->log2Bits);
ClearVtbl4(ch->map548);
ClearVtbl4(ch->map540);
ClearVtbl4(ch->map538);
ClearVtbl4(ch->map53c);
ClearVtbl4(ch->map544);
CNDHash_Recreate_009cfa88(ch->hash55c, ch->hash55c->log2Bits);
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_009466f0` (+ site `0094ead3`) | higher reset / net path (Open English) |
| Callee | `FUN_00539dd0` | Recreate hash @ +0x530 |
| Callee | `FUN_00539e30` | Recreate hash @ +0x55c |
| Callee | five maps vtbl+4 | Clear containers |

---

## 6. Gaps / open

1. Product English for `+0x530` and `+0x544` maps.
2. Full dual of callers (`009466f0` / `0094ead3`) — when wipe runs.
3. Whether vtbl+4 is “RemoveAll” vs “Destroy values” per map type (role Clear High; owning semantics Open per map).
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — wipe order + slot offsets sealed High; caller product Open.
