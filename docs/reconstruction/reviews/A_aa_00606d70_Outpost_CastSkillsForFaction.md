# Review A (reconstruction fidelity): `aa_00606d70` Outpost_CastSkillsForFaction

| Field | Value |
|---|---|
| **Stable ID** | `aa_00606d70` |
| **VA** | `0x00606d70` |
| **Canonical name** | `Outpost_CastSkillsForFaction` |
| **Former name** | `FUN_00606d70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (outpost faction skill-bank cast) |
| **Counterpart** | `reviews/B_aa_00606d70_Outpost_CastSkillsForFaction.md` |
| **System** | `skills-abilities` / outpost |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On **outpost capture / faction change**, cast every **enabled** skill in the **new faction's skill bank** against every **valid object** in the outpost's shared object TFID vector. Builds multi-target TFID batches (max **99** + terminator), then calls `CVOGReaction_CastSkillOnTarget` (0x2031 packer / local apply path; **no wire in that unit**).

Sole caller: capture path `FUN_006082e0` (string `CaptureOutpost`) at site `0x0060855b`, with `factionIndex = capturer root race` after world `+0x7e` gate.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live Ghidra | `decompile_function` `0x00606d70`; `analyze_function_complete`; `get_function_callers`; `audit_globals_in_function`; `read_memory` prologue + `DAT_009de7d8` + `DAT_00d029d0` |
| Caller (context only) | `decompile_function` `0x006082e0` — `Outpost_CastSkillsForFaction(local_28)` |
| Sibling (context only) | `Outpost_CastSkillsForBeaconShare` `0x006070e0` — same skill bank / batch / terminator pattern |
| Downstream duals | `A\|B_aa_004d09a0` CastSkillOnTarget; `A\|B_aa_00553650` ValidateTarget; `aa_0054c570` ResolveSkillTargets |
| Raw / clean | `raw/aa_00606d70_*`; `reconstructed-exact/Outpost_CastSkillsForFaction.cpp` |
| Naming | string `"Invalid outpost skill cast for skill %d, map: %s"` @ `0x009de858`; registry `Outpost_CastSkillsForFaction` |

---

## 3. Signature (ABI sealed from prologue)

```c
// __thiscall — ECX = outpost; stack[4] = factionIndex
// Prologue (read_memory @ 0x00606d70):
//   mov eax, [esp+4]     ; factionIndex
//   sub esp, 0x650       ; TFID batch + locals
//   mov esi, ecx         ; this
//   jl / jge if factionIndex < 0 || >= 4 → return
//   mov ecx, [esi+0x228] ; object begin; null → return
//   mov edi, [esi+0x22c] ; end; (end-begin)>>3 == 0 → return
void __thiscall Outpost_CastSkillsForFaction(void *thisOutpost, int factionIndex /* 0..3 */);
```

**Return:** void (no meaningful EAX). Completeness tool's `undefined` return is noise.

---

## 4. Control flow (sealed)

```
if factionIndex < 0 or factionIndex >= 4: return
if this+0x228 == 0: return                          // object TFID vector begin
if ((this+0x22c - this+0x228) >> 3) == 0: return    // empty object list (stride 8)

bankBase = this + factionIndex * 0x48
// skill vector: *(bankBase+0xd4) begin, *(bankBase+0xd8) end, stride 0x10

for each skillEntry in skill vector:
  if *(char*)(skillEntry + 0x0C) == 0:
    continue                                       // disabled entry

  skill = CVOGReaction_ResolveSkillTargets(
            *(int*)skillEntry,                     // skillId @ +0
            rankFromEntry+4);                      // rank byte @ +4 (see gaps)
  if skill == NULL:
    log Invalid(skillId, mapName); advance; continue

  batchCount = 0
  for each objEntry in object vector [this+0x228, this+0x22c) stride 8:
    obj = CVOGReaction_ResolveObjectTarget(1, objEntry[0], objEntry[1])
    if obj == NULL: continue
    if (char)Skill_ValidateTargetForSkill(skill, obj, NULL) == 0: continue  // notify=0

    copy TFID16 from obj+0x160..+0x16c into batch[batchCount]
    batchCount++
    if batchCount > 0x62:                          // 99
      write terminator batch[batchCount] = DAT_009de7d8..e4
      CastSkillOnTarget(skill, outpostAsSource, 0, 0, batch, &DAT_00d029d0, 0, -1, 0, 0)
      batchCount = 0

  if batchCount > 0:
    write terminator; CastSkillOnTarget(... same args ...)

  operator_delete(skill)                           // free 0x630 runtime; DOES return
  log Invalid(...)                                 // decomp places log after both paths — see gaps
  advance skill iterator +0x10
```

---

## 5. Layout / constants (sealed)

### Outpost fields used

| Offset | Role | Evidence |
|---:|---|---|
| `+0x04` → vb/adj chain | MI adjustor for entity base / source / map | `*( *(this+4) + 4 ) + this + 4` |
| `+0x228` / `+0x22c` | Shared **object** TFID-ref vector begin/end | prologue; stride `>> 3` → **8** |
| `faction*0x48 + 0xd4/0xd8` | Per-faction **skill** bank vector begin/end | body; stride `>> 4` → **0x10** |
| map name for log | `*( *( *(src+4)+4 ) + 0xa8 + src ) + 0xb4` | log tail (after source adjust) |

**Four** faction banks (`factionIndex ∈ [0,3]`), each **0x48** bytes apart.

### Skill bank entry (0x10)

| Off | Size | Role |
|---:|---:|---|
| `+0x00` | u32 | `skillId` → `ResolveSkillTargets` |
| `+0x04` | u8 | rank (passed as 2nd arg; decomp `CONCAT22` artifact) |
| `+0x08` | ? | unused here (BeaconShare compares float @ +8 vs `outpost+0x24c`) |
| `+0x0C` | char | **enabled** — `0` skips entry |

### Object vector entry (0x8)

| Off | Role |
|---:|---|
| `+0x00` / `+0x04` | pair → `CVOGReaction_ResolveObjectTarget(1, a, b)` |

### TFID batch

| Fact | Value |
|---|---|
| Stack buffer | `local_640[400]` dwords = **100** × 16-byte TFID slots |
| Flush threshold | `batchCount > 0x62` → flush at **99** targets |
| Terminator | `DAT_009de7d8..e4` = `{0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000}` (`read_memory`) |
| Target TFID source | object `+0x160..+0x16c` (standard entity TFID) |
| Aim arg | `&DAT_00d029d0` — BSS zeros (`read_memory` 32× `00`) |
| Source | outpost MI-adjusted subobject (same formula as other outpost/entity thiscall adjustors) |

### `CastSkillOnTarget` call shape (as decompiled)

```
CVOGReaction_CastSkillOnTarget(
  skill,                    // resolved 0x630 runtime
  outpostAsSource,          // MI adjust of thisOutpost
  0,                        // pTargetObj null
  0,                        // bNotItem-ish
  local_640,                // TFID list w/ terminator
  &DAT_00d029d0,            // aim float3 zeros
  0,                        // bHasExtra
  0xFFFFFFFF,               // extraVal
  0,                        // bStatusC → status 0 (not 'c')
  0);                       // chargeConsumed
```

Maps to sealed `aa_004d09a0` packer ABI (thiscall world/context may be ECX and under-shown in this decompile — same pattern as other named callers).

### ValidateTarget site

| Site | Parent | notify | On accept |
|---|---|---:|---|
| `0x00606EB6` | this unit | **0** | append TFID + cast |

---

## 6. Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| **Caller (sole)** | `FUN_006082e0` (CaptureOutpost path) | `0x006082e0` / xref `0x0060855b` |
| Callee | `CVOGReaction_ResolveSkillTargets` | `0x0054c570` — skillId + rank → 0x630 or null |
| Callee | `CVOGReaction_ResolveObjectTarget` | type arg **1** |
| Callee | `Skill_ValidateTargetForSkill` | notify **0** |
| Callee | `CVOGReaction_CastSkillOnTarget` | `0x004d09a0` — 0x2031 packer |
| Callee | `operator_delete` | free skill runtime (**returns**; Ghidra noreturn warning = false) |
| Callee | `FUN_007a4480` | log level **1**, format string |

---

## 7. Decompiler hazards (fidelity notes)

1. **`operator_delete` “does not return”** — false (same class of warning sealed on CastSkillOnTarget dual). Function continues skill bank walk after free.
2. **`param_1` / `iVar4` reuse** — decompiler merges outpost `this`, bank base, batch count, and post-adjust source into the same SSA names. **Port must keep them distinct** (`thisOutpost`, `bankBase`, `batchCount`, `source`). Multi-skill iteration is real product intent; naive decomp rewrite is not safe.
3. **`CONCAT22` on rank** — high half from skill-vector begin pointer is almost certainly a decomp artifact; sealed intent is rank byte @ entry `+0x04` as `rankPacked` (see `aa_0054c570`).
4. **Invalid log after success** — decomp places log after both null and non-null skill resolve. Product intent likely “log on resolve miss only”; treat always-on log as **gap** until register-level skillId identity is confirmed.

---

## 8. Confidence

| Area | Level |
|---|---|
| Name / role / sole capture caller | **High** |
| ABI thiscall + factionIndex `[0,3]` | **High** (prologue) |
| Object vector `+0x228/22c` stride 8 | **High** |
| Skill bank `faction*0x48+0xd4/d8` stride 0x10 | **High** |
| Enabled flag `@+0x0C`, skillId `@+0` | **High** |
| Batch 99 + terminator `{-1,-1,0,0}` | **High** |
| ValidateTarget notify=0 → TFID append | **High** |
| CastSkillOnTarget arg packing / aim zeros | **High** (decomp + sibling) |
| Rank packing exact width | **Medium** (byte sealed; CONCAT22 garbage) |
| Invalid-log control polarity | **Medium / gap** |
| Multi-skill register fidelity vs decomp merge | **Medium** (algorithm High; decomp vars Low) |

**Verdict:** **accept-with-gaps** — algorithm and layouts sealed for port; log polarity + rank width + decomp register merge remain open.
