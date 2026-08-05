# Review A (reconstruction fidelity): `aa_00533220` CVOGCharacter_SetLevelWithFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533220` |
| **VA** | `0x00533220` |
| **Body span** | `00533220` – `00533c2e` |
| **Canonical name** | `CVOGCharacter_SetLevelWithFlags_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00533220` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W19-J) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00533220_CVOGCharacter_SetLevelWithFlags_Inferred.md` |
| **System** | missions-progression / XP / character level |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Set **absolute** character level and **flag-selectively rebuild** progression pools from `tExperienceLevel`, clamp total XP, refresh skills/vehicle/UI hooks, rebind vehicle equipment, and fold buff/item modifiers into the selected pools.

Not a +1 LevelUp / −1 LevelDown; those are `0x00532d30` / `0x005330e0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (authoritative + W19-J re-verify) | `raw/aa_00533220_FUN_00533220.md` |
| Annotated | `raw/aa_00533220_FUN_00533220.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_SetLevelWithFlags_Inferred.cpp` |
| Alias clean | `reconstructed-exact/FUN_00533220.cpp` |
| Function record | `functions/aa_00533220_FUN_00533220.md` |

**This pass (live, OWN VA):**

- Ghidra `decompile_function` @ `0x00533220`
- Ghidra `read_memory` entry + epilogue — **`ret 8`** (`C2 08 00`) after `add esp,0x44`
- Ghidra `get_function_by_address` bounds `00533220`–`00533c2e`
- Ghidra `get_function_xrefs` / callers — sole `FUN_0080bec0` @ `0080bf02`
- Ghidra `get_assembly_context` @ caller — `ECX=[ESI+0xe98]`; push level; push flags
- Context decompile of caller + `FUN_00521230` (race seed) — not owned
- Cross dual: skill/attrib pool names from `a_00533f90`; LevelUp/Down siblings for field map
- **Not performed:** Launcher, `disassemble_bytes`, runtime golden, bit-exact image diff

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | `CVOGCharacter *this` | `mov esi,ecx` |
| **`[esp+4]`** | `int newLevel` | caller push vfunc result |
| **`[esp+8]`** | `uint flags` | caller push obj+8; body `and ebx,1` etc. |
| **Return** | void | `ret 8` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `ret 8` thiscall | **High** | `read_memory` |
| Flags `0x1` / `0x4` / `0x40` | **High** | plate + caller bit checks |
| skill `+0x6ce`, attrib `+0x6cc`, research `+0x580` | **High** | stores + sealed Add* dual |
| Absolute `nLevel` + table reaccumulate 2..N | **High** | |
| Total XP clamp `+0x730` from row `+0x10` | **High** | XP.md agrees `+0x730` total XP |
| Sole CharacterLevel-path caller | **High** | 1 xref |
| Product English symbol | **Inferred** | |
| Equip rebind field names | **Medium** | CF sealed; callees residual |
| `Skill_SetRankAndReevaluate` 3rd arg | **Low–Medium** | `unaff_EDI` gap |
| Bit-for-bit / runtime / differential | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Flag decode + zero pools | Yes |
| Level store + changed/up flags | Yes |
| Loop 2..newLevel table grants | Yes |
| Skill HB / hash reeval when `0x4` | Yes |
| Vehicle pools + vtable + auto-missions | Yes |
| Equip rebind + buff list | Yes (plate; clean preserves) |

### Recovered contract

```c
void SetLevelWithFlags(CVOGCharacter* self, int newLevel, unsigned flags);
// flags: 1=skill rebuild, 4=attrib+skills, 0x40=research
// side effects: XP clamp, vehicle, missions, equip, item grants
```

---

## 6. Callers

| Caller | Site | Role |
|---|---|---|
| `FUN_0080bec0` | `0x0080bf02` | apply CharacterLevel snapshot / level fields |

**1 xref only.**

---

## 7. Gaps

1. Product/PDB English symbol.
2. `unaff_EDI` → `Skill_SetRankAndReevaluate` third argument.
3. Full equip-slot product names / `FUN_00514390` predicate.
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
