# Review A (reconstruction fidelity): `aa_005d1280` NPC_TryCastSkillFromSet

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d1280` |
| **VA** | `0x005d1280` |
| **Canonical name** | `NPC_TryCastSkillFromSet` |
| **Review date** | `2026-07-23` (dual residual strengthen `2026-07-29`) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d1280_NPC_TryCastSkillFromSet.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

AI skill selection + cast for NPCs (`__thiscall`, from `CVOGHBAIDriver_DoLogic`). Controller: owner **`+0x64`**, post-cast CD map **`+0x98`/`+0x9c`**, cast chance **`+0x08`**. Algorithm: early-out if post-cast timer active; require `Skill_LocalCastValidate` + world server/sim (`owner world+0x7e`); optional random gate; walk skill-set entries (stride **0x18**); HP-ratio band filter; skip if casting **`skill+0x628`** or category CD remaining; resolve target TFID from flags **`+0x614`**; `ResolveTargetList` + `LocalRangeTargetCheck` + `ValidateTargetForSkill`; `CVOGReaction_CastSkillOnTarget`; insert post-cast timer. Substantial (~332 lines).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d1280_NPC_TryCastSkillFromSet.md` |
| Annotated | `docs/reconstruction/raw/aa_005d1280_NPC_TryCastSkillFromSet.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NPC_TryCastSkillFromSet.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d1280_NPC_TryCastSkillFromSet.md` |
| Fresh re-decompile | Ghidra `decompile_function` `0x005d1280` (2026-07-29 residual; once) |
| Ghidra type | `NPCSkillSetEntry` size **24** (`get_struct_layout`) |
| Stride peer | `SkillSet_GetEntryCount` `0x00402d80` — `(end-begin)/0x18` |
| Constants | `read_memory` `@0x009da970` / `@0x009da978` / `@0x00aaaaa8` / `@0x00aaa728` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Called from `CVOGHBAIDriver_DoLogic` (set index 0/1/2) | **High** | clean caller unit |
| Post-cast map `this+0x98` / sentinel `+0x9c`; node deadline `+0x10` | **High** | CF re-decompile |
| `LocalCastValidate(caster,0,null,0)==0` + `world+0x7e≠0` gate | **High** | CF; server/sim product word still open |
| Optional cast-chance gate `this+0x08` when owner `+0xb8` bit `0x80` | **High CF** | formula constants sealed below |
| Skill-set entry **stride 0x18** | **High / Confirmed** | body `/0x18` + `SkillSet_GetEntryCount` |
| HP band filter uses entry min/max floats vs cur/max HP | **High** | CF; vtbl `+0x23c`/`+0x244` roles INFERRED |
| Full cast pipeline callees | **High** | Resolve → Range → Validate → CastSkillOnTarget |
| `NPCSkillSetEntry` **used** field roles | **High (role)** | skillId / delay / rank / hpMin / hpMax |
| `NPCSkillSetEntry` **byte packing / pads** | **INFERRED** | Ghidra layout; no string/PDB; leave pads unnamed |
| Exact return type | Unsettled | early: map node / rand residue; fallthrough `pResult` |
| Threat scalar `owner+0x124` | Tentative | INFERRED global scale; AI combat cross-check open |
| Runtime / live AI pick | Open | set index / HP-band capture needed |

---

## 4. Control flow: clean ≡ raw ≡ re-decompile

| Stage | Match |
|---|---|
| 1 post-cast map early-out / erase expired | **Yes** |
| 2 LocalCastValidate + world+0x7e | **Yes** |
| 3 optional rand cast-chance | **Yes** |
| 4 char-key set lookup + HP ratio | **Yes** |
| 5 random start + walk stride 0x18 | **Yes** |
| 6 HP band / casting / cat CD / state | **Yes** |
| 7 target TFID from `skill+0x614` | **Yes** |
| 8 Resolve + Range + Validate | **Yes** |
| 9 CastSkillOnTarget + arm post-cast | **Yes** |
| Optional threat scalar write | **Yes** |
| No invented player quickbar path | **Yes** |

---

## 5. `NPCSkillSetEntry` residual (2026-07-29)

**Size `0x18` Confirmed** (vector divide + peer GetEntryCount).

| Off | Size | Role (this body) | Status |
|---:|---:|---|---|
| `+0x00` | 4 | skill id → tree lookup / EnsureLoaded | **SEALED role High** |
| `+0x04` | 2 | packing between id and delay | **INFERRED** (no string) |
| `+0x06` | 2 | post-cast delay ms (add `g_dwClientTickMs`) | **SEALED role High** |
| `+0x08` | 2 | s-rank → EnsureLoadedInTree | **SEALED role High** |
| `+0x0a` | 2 | packing after rank | **INFERRED** (no string) |
| `+0x0c` | 4 | HP ratio min | **SEALED role High** |
| `+0x10` | 4 | HP ratio max | **SEALED role High** |
| `+0x14` | 4 | unused in this body | **INFERRED** (no string) |

Offsets follow Ghidra `NPCSkillSetEntry` (`get_struct_layout`); **not** PDB/string-sealed. Do **not** invent product names for pads / `+0x14`. Assembly formal of packing remains open by policy (no `disassemble_bytes`).

### Cast-chance constants (`read_memory`)

| VA | Value | Use |
|---|---|---|
| `0x009da970` | double **90.0** | threshold base |
| `0x009da978` | double **40.0** | scale factor |
| `0x00aaaaa8` | double **≈0.001** | scale factor |
| `0x00aaa728` | double **2^32** | unsigned int→double bias |

Gate: `90 − chance·0.001·40 < (rand%100)` → early return (fail cast). Product scale of `this+0x08` still open.

---

## 6. Gaps / open

1. Assembly formal of entry packing (pads / rank width).
2. Exact return type (map node vs residue vs null).
3. Confirm client never executes full cast path (`world+0x7e`).
4. Live AI cast capture (set index / HP band / skill pick).
5. Threat scalar product meaning (`owner+0x124`).

**Verdict:** **accept-with-gaps** — residual wave sealed entry **roles + stride 0x18** + chance constants; pad names withheld; return type / runtime / server-only remain.
