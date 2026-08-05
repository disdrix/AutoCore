# Review A (reconstruction fidelity): `aa_006070e0` Outpost_CastSkillsForBeaconShare

| Field | Value |
|---|---|
| **Stable ID** | `aa_006070e0` |
| **VA** | `0x006070e0` |
| **Canonical name** | `Outpost_CastSkillsForBeaconShare` |
| **Former name** | `FUN_006070e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (outpost beacon-share skill bank cast) |
| **Counterpart** | `reviews/B_aa_006070e0_Outpost_CastSkillsForBeaconShare.md` |
| **System** | `skills-abilities` / outpost |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-faction **outpost skill bank cast** gated by the outpost’s current **beacon-share ratio** (`this+0x24c`). Walks the faction’s skill-entry vector (stride **0x10**), materializes each skill via `CVOGReaction_ResolveSkillTargets`, resolves per-faction TFID targets, validates, batches TFIDs (flush at **> 0x62**), and calls `CVOGReaction_CastSkillOnTarget`.

**Sole caller:** `FUN_006078e0` (`0x006078e0`) — recomputes `ratio = factionBeacons / totalBeacons` into `this+0x24c`; when ratio **changes**, calls this unit with **factionIndex = `*(this+0x234)`**.

---

## 2. Inspected evidence

| Source | Detail |
|---|---|
| Live Ghidra | `decompile_function` `0x006070e0`, sibling `0x00606d70`, caller `0x006078e0`; `get_function_callers` / `get_function_callees`; `read_memory` `0x009de7d8` (16), `0x00d029d0` (32) |
| Raw | `docs/reconstruction/raw/aa_006070e0_FUN_006070e0.md` |
| Annotated | `docs/reconstruction/raw/aa_006070e0_FUN_006070e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Outpost_CastSkillsForBeaconShare.cpp` |
| Sibling | `Outpost_CastSkillsForFaction` `0x00606d70` (same invalid string / bank / cast shape) |
| Naming | registry `Outpost_CastSkillsForBeaconShare`; string `"Invalid outpost skill cast for skill %d, map: %s"` |

**Tools per task rules:** decompile + read_memory (+ callers/callees). **No** `disassemble_bytes`. **No** Launcher.

---

## 3. Signature

```c
// MSVC __thiscall: ECX = outpost object
void __thiscall Outpost_CastSkillsForBeaconShare(
    void *thisOutpost,
    int   factionIndex);   // must be in [0, 3]; else no-op
```

**Caller ABI (`FUN_006078e0`):**
```
// thiscall: ECX = outpost (same this as 006078e0)
// stack:    factionIndex = *(outpost + 0x234)
Outpost_CastSkillsForBeaconShare(*(outpost+0x234));
```

---

## 4. Control flow (sealed)

```
if factionIndex < 0 or factionIndex >= 4: return

factionBase = this + factionIndex * 0x48

// skill bank vector: begin = *(factionBase+0xd4), end = *(factionBase+0xd8)
// entry stride 0x10; count = (end - begin) >> 4
for each entry e in bank:
  // SKIP when:
  //   e.flag(+0xC) != 0
  //   OR  ratio(this+0x24c) < e.threshold(+0x8)     // strict: (r<=t && t!=r)
  if skip: advance; continue

  skill = CVOGReaction_ResolveSkillTargets(e.skillId, levelByteFrom e+0x4)
  if skill == null:
    log "Invalid outpost skill cast for skill %d, map: %s"
    advance; continue
  // (see gap: decompiler also places log after free — CF residual)

  batchCount = 0
  // TFID vector: begin = *(factionBase+0xb4), end = *(factionBase+0xb8), stride 8
  for each tfid8 in faction TFID list:
    obj = CVOGReaction_ResolveObjectTarget(0, tfid.lo, tfid.hi)   // mode 0 (≠ faction's 1)
    if obj == null: continue
    container = obj.vtbl[+0x1ec]()
    if container == 0: continue
    // CS-locked walk of container list (+0xb4 region) via FUN_004294f0 / FUN_004022a0
    for each entity in container walk:
      side = entity.vtbl[+0x1d8]()
      if (side == 0 OR *(side + 0x250) == 0)
         AND Skill_ValidateTargetForSkill(skill, entity, NULL) != 0:
        append entity TFID (entity+0x160 .. +0x16c) to batch   // dwords [0x58..0x5b]
        if batchCount > 0x62:   // 98 → flush at 99
          append terminator DAT_009de7d8 (FFFF.., 0, 0)
          CVOGReaction_CastSkillOnTarget(skill, outpostAdj, 0, 0, batch, &DAT_00d029d0, 0, -1, 0, 0)
          batchCount = 0
    // leave CS if held (byte container+0x28)

  if batchCount > 0:
    append terminator; CastSkillOnTarget(...)  // same arg shape
  operator_delete(skill)
  advance entry
return
```

### Skill-bank entry (stride **0x10**)

| Off | Type | Role |
|---:|---|---|
| +0x00 | `u32` | skill id → `ResolveSkillTargets` arg0 |
| +0x04 | `u8` (+ pad) | rank/level byte → Resolve 2nd arg (low byte; CONCAT22 high half is decompiler noise from pointer) |
| +0x08 | `f32` | **min beacon-share threshold** |
| +0x0C | `char` | **skip when non-zero** (beacon polarity **≠** faction bank, which requires flag ≠ 0) |

### Ratio gate

```
ratio = *(float*)(this + 0x24c)     // written by FUN_006078e0 = factionBeacons / totalBeacons
process iff flag==0 AND ratio >= threshold
// skip formula from decompile: flag!=0 OR (ratio < threshold)
```

### Batch / cast

| Fact | Value |
|---|---|
| Batch element | 16-byte TFID (`entity+0x160`) |
| Flush when | `count > 0x62` (i.e. after 99th push) |
| Terminator | `DAT_009de7d8`: `FF FF FF FF FF FF FF FF 00 00 00 00 00 00 00 00` (`read_memory`) |
| Aim buffer | `&DAT_00d029d0` — BSS zeros (`read_memory` 32B all 0) |
| Source object | `*( *(this+4) + 4 ) + this + 4` (outpost CVOG adj; same pattern as sibling) |
| Extra / charge | `0, 0xffffffff, 0, 0` |

---

## 5. Contrast vs `Outpost_CastSkillsForFaction` (`0x00606d70`)

| Aspect | BeaconShare (`006070e0`) | Faction (`00606d70`) |
|---|---|---|
| Entry gate | factionIndex only | also requires global list `this+0x228` non-empty |
| Skill flag +0xC | process when **0** | process when **≠ 0** |
| Extra gate | `ratio(+0x24c) >= threshold(+0x8)` | none |
| Target list | **per-faction** `factionBase+0xb4/0xb8` | **global** `this+0x228/0x22c` |
| `ResolveObjectTarget` mode | **0** | **1** |
| Nested walk | vfunc `+0x1ec` + CS iterator + vfunc `+0x1d8` / `+0x250` | direct ValidateTarget on resolved object |
| Invalid string | same | same |

---

## 6. Callees (this unit)

| Address | Name | Role here |
|---|---|---|
| `0x0054c570` | `CVOGReaction_ResolveSkillTargets` | materialize skill from id+rank |
| `0x004bae70` | `CVOGReaction_ResolveObjectTarget` | TFID → object (mode **0**) |
| `0x00553650` | `Skill_ValidateTargetForSkill` | gate before batch |
| `0x004d09a0` | `CVOGReaction_CastSkillOnTarget` | batch cast / 0x2031 local pack |
| `0x004294f0` | `FUN_004294f0` | enter/init CS walk (with `+0xb4`) |
| `0x004022a0` | `FUN_004022a0` | list iterator next (0 = more) |
| `0x007a4480` | `FUN_007a4480` | log (level 1) |
| `0x00489822` | `operator_delete` | free ResolveSkillTargets heap |
| EXTERNAL | `LeaveCriticalSection` | unlock if held |

**Caller:** only `FUN_006078e0`.

---

## 7. Side effects

- Heap: allocate skill via Resolve (callee); free via `operator_delete`.
- Cast path may apply local skill status (callee `CastSkillOnTarget` dual: **no wire in that unit**).
- Log on resolve-null (product intent); possible always-log residual if free returns (see B / gaps).
- CS lock/unlock around container walk.
- **No** direct network send in this unit.

---

## 8. Confidence

| Area | Level |
|---|---|
| Name + outpost skill-cast role | **High** (string + caller ratio) |
| factionIndex [0,3], stride 0x48 bank | **High** |
| Ratio gate +0x24c vs entry +0x8 | **High** |
| Flag polarity vs faction sibling | **High** (decompile both) |
| Target list per-faction +0xb4; mode 0 | **High** |
| Batch >0x62 + terminator bytes | **High** (`read_memory`) |
| Nested vfunc English names | **Low** |
| Invalid-log vs free ordering | **Medium** (Ghidra noreturn warning) |
| Resolve 2nd-arg full width | **Medium** (byte sealed; high half artifact) |
