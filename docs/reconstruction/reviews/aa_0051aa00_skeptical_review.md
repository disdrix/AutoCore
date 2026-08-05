# Skeptical / adversarial review: `Skill_ApplyStatusEffectLocal` @ `0x0051aa00`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aa00` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Local 0x2031 apply, cast-again side effects, return codes |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_0051aa00_Skill_ApplyStatusEffectLocal.md` | Body |
| `raw/aa_0051aa00_Skill_ApplyStatusEffectLocal.annotated.md` | Human refine |
| `reconstructed-exact/Skill_ApplyStatusEffectLocal.cpp` | Clean |
| `functions/aa_0051aa00_Skill_ApplyStatusEffectLocal.md` | Record |
| `Client_RecvSkillStatusEffect` / `CVOGReaction_CastSkillOnTarget` | Callers |
| `docs/topic-extractions/skill-cast.md` | lDelayTime / optimistic CD narrative |

**Not performed:** assembly, runtime, string/enum seal for `0x11`.

---

## 2. Evidence used

### Body-derived returns

| Value | When |
|------:|------|
| `2` | Entry default; fail if skill never resolves |
| `0` | Skill resolved (may still cancel later → 0x11) |
| `0x11` | Active binding present and cancel conditions met |

### Packet gates

- `+0x38` item flag splits load path and CD path.
- `+0x10` delay splits immediate apply vs HB.
- `world+0x7e` gates sim-only CD HB and random extra.

---

## 3. Attack results

### Claim 1 — “Applies all skill combat effects client-side”

| Sub-claim | Attack result |
|-----------|----------------|
| Loads skill + builds target list + calls apply helper | **Survives** |
| Authoritative damage/heal | **Falsified for server truth** — local presentation/apply only |
| `FUN_005538a0` is full combat | **Unnamed** — cannot claim |

---

### Claim 2 — Always starts optimistic cast-again cooldown

| Sub-claim | Attack result |
|-----------|----------------|
| Calls `Skill_StartCastAgainHeartbeat` | **Only when** non-item **and** `world+0x7e != 0` **and** skill skip-flag clear |
| Matches player RequestCast optimistic CD | **Different site** — RequestCast starts HB **before** send on **client** (`world+0x7e==0` path). This body starts HB on **sim** flag. **Polarity opposite to naive “always” reading** |
| Plate “may StartCastAgain when world+0x7e (sim)” | **Survives** |

Critical: do not implement “ApplyStatusEffectLocal restarts CD on client success” from this body alone — Recv may cancel optimistic HB on failure instead (topic narrative).

---

### Claim 3 — Return `0x11` is eSkillResponses cancel on wire

| Sub-claim | Attack result |
|-----------|----------------|
| Local return 0x11 on binding cancel | **Holds as CF** |
| Packet status field written here | **Not shown** — status already in packet |
| Equals retail enum name “Cancel” | **Unsealed** |

---

### Claim 4 — Item skill path is fully understood

| Sub-claim | Attack result |
|-----------|----------------|
| Uses ResolveSkillTargets | **Holds** |
| InsertCategoryCooldown then free skill | **Holds as CF** |
| `operator_delete` always returns | **Decompiler says noreturn** — contamination risk; may be `delete` of non-pool object |
| Category field from `this[0x25]` bytes | **Overlay garbage risk** |

---

### Claim 5 — Clean rank-sum offsets are sealed

| Sub-claim | Attack result |
|-----------|----------------|
| Clean uses skill `+0x5f6/+0x174` | Cross-unit from CastSkillOnTarget packer — **Probable** |
| Matches raw `this[9]` HB overlay expression bit-exactly | **No** — reconstruction improved/guessed |
| Skeptical bar for bit-exact | **Fail** until assembly |

---

### Claim 6 — Port-ready apply module

| Sub-claim | Attack result |
|-----------|----------------|
| CF guide for AutoCore Recv path | **Partial** — delay=0 immediate path is the live server policy path |
| Full skill field map | **Fails** |
| Convention sealed | **Fails** |

---

## 4. Alternate interpretations

### Minimal reading

Client/sim helper that materializes skill state for a status-effect buffer and either plays effects now or schedules an active-skill heartbeat, with special cancel handling when an optimistic cast binding exists.

### What the name oversells

“ApplyStatusEffectLocal” sounds like pure FX. Body mutates cast bindings, category CDs, and heartbeat queues — **state machine**, not only particles.

---

## 5. What was confirmed despite skepticism

1. Item vs non-item split on `+0x38`.
2. Target strip math from packet size.
3. Delay branch structure.
4. `0x11` early return on binding match / flag / invalid target.
5. Clean preserves major call order (lookup → clear → CD → strip → apply/HB).

---

## 6. Critical contradictions found

### C1 — Cast-again HB polarity vs RequestCast

RequestCast: client (`+0x7e==0`) starts optimistic HB **before** send.  
ApplyStatusEffectLocal: starts HB when `+0x7e!=0` (sim).  

Topic story that success “confirms” optimistic CD is **not** the same as this function restarting CD on client Recv.

### C2 — Skill-as-heartbeat type contamination

Treating `CVOGHBBase` fields as skill layout will corrupt ports of cancel/CD branches.

### C3 — Clean rank offset “improvement”

Reconstruction review may accept CF; skeptical review rejects bit-exact claim for rank compare.

---

## 7. Residual uncertainty

| # | Item | Blocks sealing? |
|---|------|-----------------|
| R1 | Skill field map under mis-type | **Yes** |
| R2 | CD HB polarity on Recv success | **Yes** for cooldown UX |
| R3 | Return `0x11` consumer | Yes |
| R4 | Immediate apply helper semantics | Yes for combat parity |
| R5 | Item delete path | Medium |

---

## 8. Concrete checks performed

1. Enumerated returns `2` / `0` / `0x11`.
2. Mapped every `world+0x7e` test — sim vs client branches.
3. Confirmed StartCastAgain only under sim + non-item.
4. Confirmed target count formula against packer size.
5. Compared clean rank offsets to raw overlay — not identical.
6. Cross-checked topic optimistic-CD story vs this body.

---

## 9. Verdict

### **`needs-more-evidence`**

Structurally valuable, but skill layout contamination and CD polarity make naive ports dangerous.

### Acceptance bar later

1. Re-type skill runtime; kill CVOGHBBase overlay.
2. Assembly of Recv → Apply call and return use.
3. Trace client success Recv: does it call StartCastAgain or only leave optimistic HB?
4. Name `FUN_005538a0` / `FUN_006061e0`.

### Port guidance

- Prefer server `lDelayTime=0` → immediate apply path.
- Do not double-start cast-again HB on client Recv success.
- Treat `0x11` as local cancel until wire enum sealed.
- Do not trust HB member names for skill fields.

---

## 10. Summary table

| # | Claim | Result |
|---|-------|--------|
| 1 | Full combat apply | **Overclaim** |
| 2 | Always restarts CD | **Falsified** |
| 3 | 0x11 wire enum | **Unsealed** |
| 4 | Item path sealed | **Partial** |
| 5 | Rank offsets bit-exact | **Fail** |
| 6 | Port-ready | **Fails seal** |

**Final verdict: `needs-more-evidence`**
