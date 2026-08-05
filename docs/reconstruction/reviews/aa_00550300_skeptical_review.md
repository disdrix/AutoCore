# Skeptical / adversarial review: `Skill_ResolveTargetList` @ `0x00550300`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00550300` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Target list builder role, outFlags claims, relationship to eSkillResponses |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_00550300_Skill_ResolveTargetList.md` | Body |
| `raw/aa_00550300_Skill_ResolveTargetList.annotated.md` | Human refine |
| `reconstructed-exact/Skill_ResolveTargetList.cpp` | Clean |
| `functions/aa_00550300_Skill_ResolveTargetList.md` | Record |
| `reconstructed-exact/CVOGReaction_CastSkillOnTarget.cpp` | Primary caller + flag map |
| `docs/topic-extractions/skill-cast.md` | Cast pipeline narrative |
| Sibling reviews of `aa_004d09a0` / `aa_0054c570` | Confusion with ResolveSkillTargets |

**Not performed:** assembly of formals, runtime, live re-decompile.

---

## 2. Evidence used

### Body-derived behavior

- 100-slot wipe to `DAT_009d1ca8..`
- Primary TFID resolve + filter
- Bit OR into `*param_10` values `1` and `2`
- Optional `Skill_GatherTargetsInArea`
- Return = target count (char)

### Caller mapping (CastSkillOnTarget)

```
if resolveFlags & 2 → 0x0D (range)
else if resolveFlags & 4 → 0x0E (target)
else collapse other bits
```

Note: this body only **sets** bits 1 and 2 in the observed stores. Bit 4 / bit 8 appear in `Client_Skill_ResolveCastTarget` (maps bit2→code 0xd, bit4→0xe, bit8→code 3, bit1→“Nothing is targeted”). Likely writers: `FUN_0054ff00` (receives `outFlags`) and/or `Skill_GatherTargetsInArea` — **not sealed in this unit**.

---

## 3. Attack results

### Claim 1 — “Builds the authoritative cast target list for all skills”

| Sub-claim | Attack result |
|-----------|----------------|
| Builds TFID array up to 100 | **Survives** |
| Used on player cast send | **Survives via indirection.** Ghidra callers: `Client_Skill_ResolveCastTarget` (`0x0093b3a0`), `CVOGReaction_CastSkillOnTarget`, `NPC_TryCastSkillFromSet`. RequestCast → ResolveCastTarget → **this** function |
| Replaces `CVOGReaction_ResolveSkillTargets` | **BROKEN.** Different address/function (`0x0054c570`) — name collision risk only |

---

### Claim 2 — outFlags bit1 = no target, bit2 = out of range

| Sub-claim | Attack result |
|-----------|----------------|
| Bit 1 OR’d on no-primary when skill wants target | **Holds as CF** |
| Bit 2 OR’d when range helper == 0 | **Holds as CF** |
| Labels “no target” / “out of range” are retail names | **INFERRED only** — plate admits inference |
| Complete flag vocabulary | **Falsified as complete** — caller tests bit 4 which this body never sets |

---

### Claim 3 — Returns eSkillResponses 13/14

| Sub-claim | Attack result |
|-----------|----------------|
| Function return is 13/14 | **Falsified** — return is count |
| Caller maps flags to 13/14 | **Probable** at CastSkillOnTarget |
| Topic docs that attribute 13/14 to “resolve” generically | **Sloppy** if tied to this return value |

---

### Claim 4 — Clean is port-ready targeting module

| Sub-claim | Attack result |
|-----------|----------------|
| CF fidelity to raw | **Holds** |
| Sealed helper ABIs | **Fails** (`FUN_0054ff00`, `FUN_0058c0a0`, Gather 15-arg) |
| Sealed skill flag enums | **Fails** |
| Compilable against game types | **Fails** (opaque ints / externs) |

---

### Claim 5 — Primary object TFID indices `0x58..0x5b` are `+0x160`

| Sub-claim | Attack result |
|-----------|----------------|
| dword indices 0x58 × 4 = 0x160 | **Arithmetic holds** |
| Equate sealed across all object types | **Probable** (matches source TFID packing elsewhere) but not proven for every class |

---

## 4. Alternate interpretations

### Minimal reading

Skill-driven TFID list filler for reaction cast packing: optional single primary + optional splash/area gather. Status flags are side channel for caller.

### What the name oversells

“ResolveTargetList” sounds like full legality. Body does **not** run `Skill_ValidateTargetForSkill` / `Skill_LocalCastValidate`. Range helper is opaque; many skills may only hit the wipe+return-0 path.

---

## 5. What was confirmed despite skepticism

1. Return is count, not eSkillResponses.
2. Bits 1 and 2 are written on documented paths.
3. Distinct from `CVOGReaction_ResolveSkillTargets`.
4. Gather is optional and mode-gated via `skill+0x624`.
5. Clean did not invent a modern multi-target API.

---

## 6. Critical contradictions found

### C1 — Flag bit 4 in caller vs body

CastSkillOnTarget maps bit 4 → wrong target; this function never sets bit 4 in the decompile. Either another writer ORs it, Gather sets it via `outFlags`, or the caller map is partially dead / from a different producer.

### C2 — Player cast path naming

RequestCast does not call this directly; it goes through `Client_Skill_ResolveCastTarget` (`0x0093b3a0`), which maps outFlags to toasts / invalid TFID. Docs that skip that hop under-specify the graph.

### C3 — INFERRED labels presented as plate fact

“1=no target, 2=out of range” is useful but unsealed.

---

## 7. Residual uncertainty

| # | Item | Blocks sealing? |
|---|------|-----------------|
| R1 | Full outFlags vocabulary | **Yes** for error UX |
| R2 | Helper identities | Yes |
| R3 | Call packing from CastSkillOnTarget | Yes for port |
| R4 | Runtime gather counts | Yes for multi-target skills |
| R5 | Invalid TFID global identity | Medium |

---

## 8. Concrete checks performed

1. Listed every store to `*param_10` in raw — only `\|1` and `\|2`.
2. Confirmed return is `local_32` count.
3. Compared to CastSkillOnTarget flag collapse — bit4 unexplained by this body.
4. Confirmed no call to LocalCastValidate / ValidateTargetForSkill.
5. Verified clean preserves wipe count 100 and Gather branch structure.

---

## 9. Verdict

### **`needs-more-evidence`**

Useful list builder reconstruction, but flag semantics and helper chain are not sealed; must not be treated as the universal player-cast resolver.

### Acceptance bar later

1. ~~Decompile/name `FUN_0054ff00` and `FUN_0058c0a0`~~ **Closed 2026-07-29 residual** — Filter + RangeCheck `_Inferred` (see `reviews/a_00550300.md`).
2. ~~Trace who sets outFlags bit 4 (Gather?)~~ **Closed** — Filter `0x0054ff00` (not Gather for 4/8).
3. Assembly of CastSkillOnTarget call site vs this prototype — static packing matches; live optional.
4. Runtime dump of outList + flags for single-target vs splash skills — still open.

### Port guidance

- Implement count + bit1/bit2 behavior for reaction packing.
- Map 13/14 at **caller**, not as this return.
- Player path: implement via `Client_Skill_ResolveCastTarget` semantics (flags → 0xd/0xe/toasts), not only raw count.

---

## 10. Summary table

| # | Claim | Result |
|---|-------|--------|
| 1 | Shared list builder (player+NPC+reaction) | **Survives** (via ResolveCastTarget) |
| 2 | Flag labels sealed | **INFERRED only** |
| 3 | Returns 13/14 | **Falsified** |
| 4 | Port-ready clean | **Fails seal** |
| 5 | TFID at +0x160 | **Probable** |

**Final verdict: `needs-more-evidence`**
