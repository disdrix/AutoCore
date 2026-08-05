# Function record: NPC_TryCastSkillFromSet

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d1280` |
| **Canonical name** | `NPC_TryCastSkillFromSet` |
| **Address** | `0x005d1280` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (this = AI skill-set controller) |
| **Return type** | `void*` (cast-result / map-node / null — exact type unsettled) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual 2026-07-29** — CF accept-with-gaps; entry **roles+stride sealed**; pad packing INFERRED; runtime open |
| **Bit-for-bit / runtime / diff** | Open |

---

## 1. Summary

AI cast from skill-set table (called from `CVOGHBAIDriver_DoLogic`):

1. Early-out if post-cast timer for this set still active (`this+0x98` map / sentinel `+0x9c`; node deadline `+0x10`).
2. Require `Skill_LocalCastValidate` ok **and** owner world `+0x7e` (server/sim).
3. Optional random cast-chance gate (`this+0x08`) when owner flag `+0xb8` bit `0x80`.
4. Char-key skill-set lookup; walk entries stride **0x18** (`NPCSkillSetEntry`).
5. Filter HP ratio band; skip casting (`skill+0x628`) / category CD / state blocks.
6. Resolve target TFID from `skill+0x614` flags (self / selected / area gather).
7. `Skill_ResolveTargetList` → `Skill_LocalRangeTargetCheck` → `Skill_ValidateTargetForSkill`.
8. `CVOGReaction_CastSkillOnTarget`; arm post-cast deadline = now + entry delay ms.
9. Optional inferred threat scalar write on owner `+0x124`.

---

## 2. Signature (decompiler-derived)

```c
void* __thiscall NPC_TryCastSkillFromSet(
    void* this,            // AI skill-set controller
    int nSkillSetIndex);   // skill bank key (char map + int post-cast map)
```

**Controller offsets (High from CF where noted; else INFERRED):**

| Offset | Role | Confidence |
|---:|---|---|
| `+0x08` | cast-chance scalar | High CF (scale product open) |
| `+0x18` | selected-target side chain | Tentative |
| `+0x64` | owner object chain | High use |
| `+0x98` / `+0x9c` | post-cast int-key map root / sentinel | **High** |

### `NPCSkillSetEntry` (size / stride `0x18` — **Confirmed**)

Ghidra type + this-body field use (2026-07-29 residual). **Not** PDB/string-sealed.

| Off | Size | Name / role | Status |
|---:|---:|---|---|
| `+0x00` | 4 | `nSkillId` — skill tree key | **SEALED role** |
| `+0x04` | 2 | pad | **INFERRED** (no string) |
| `+0x06` | 2 | `wUsPostCastDelayMs` — arm post-cast CD | **SEALED role** |
| `+0x08` | 2 | `nSRank` — EnsureLoadedInTree rank | **SEALED role** |
| `+0x0a` | 2 | pad | **INFERRED** (no string) |
| `+0x0c` | 4 | `flHpRatioMin` | **SEALED role** |
| `+0x10` | 4 | `flHpRatioMax` | **SEALED role** |
| `+0x14` | 4 | unused here | **INFERRED** (no string) |

Peer: `SkillSet_GetEntryCount` `0x00402d80` — `(end-begin)/0x18`.

### Cast-chance constants (`read_memory`, 2026-07-29)

| VA | Value |
|---|---|
| `0x009da970` | 90.0 |
| `0x009da978` | 40.0 |
| `0x00aaaaa8` | ≈0.001 |
| `0x00aaa728` | 2^32 (u32→double bias) |

---

## 3. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_005d1280_NPC_TryCastSkillFromSet.*` |
| Clean | `reconstructed-exact/NPC_TryCastSkillFromSet.cpp` |
| Dual A | `reviews/A_aa_005d1280_NPC_TryCastSkillFromSet.md` (**accept-with-gaps**) |
| Dual B | `reviews/B_aa_005d1280_NPC_TryCastSkillFromSet.md` (**accept-with-gaps**) |
| System map | `systems/skills-abilities.md` |
| Topic | `docs/topic-extractions/skill-cast.md` § NPC notes |
| Callees | LocalCastValidate, EnsureLoadedInTree, ResolveTargetList, LocalRangeTargetCheck, ValidateTargetForSkill, CastSkillOnTarget, GatherTargetsInArea |
| Stride peer | `SkillSet_GetEntryCount` `aa_00402d80` |

---

## 4. Confidence

| Dimension | Level |
|---|---|
| Role in AI cast | **High** |
| Pipeline order / CF | **High** (dual accept-with-gaps; re-decompile match) |
| Post-cast map + LocalCastValidate gate | **High** |
| Entry stride 0x18 + used field roles | **High** |
| Entry pad packing / product names | **INFERRED** (leave unnamed) |
| Return type | Unsettled |
| Runtime / server-only sim | Open |
| Overall | **Partial; dual residual complete; runtime next** |

---

## 5. Open questions (linked → skills-abilities)

1. Assembly formal of entry packing (pad widths) — open by policy without disassemble.
2. Exact return type of cast-result pointer (map node vs skill result vs null).
3. Confirm server-only execution via `world+0x7e` (client should not cast on this path).
4. Live AI cast capture (which set index / HP band picks which skill).
5. Cross-check threat scalar (`owner+0x124` / inferred scale) with AI combat system.
