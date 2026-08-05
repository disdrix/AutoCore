# Skeptical / adversarial review: `CVOGReaction_CastSkillOnTarget` @ `0x004d09a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d09a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | SkillStatusEffect packer claims, field map, network role |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_004d09a0_CVOGReaction_CastSkillOnTarget.md` | Body |
| `raw/aa_004d09a0_CVOGReaction_CastSkillOnTarget.annotated.md` | Plate |
| `reconstructed-exact/CVOGReaction_CastSkillOnTarget.cpp` | Clean |
| `functions/aa_004d09a0_CVOGReaction_CastSkillOnTarget.md` | Record |
| `docs/topic-extractions/skill-cast.md` | Field offsets, size, status codes, source TFID rules |
| `systems/skills-abilities.md` | Cast reaction entry |
| Contrast | Client outbound `0x2030` builders (RequestCast / QuickBar) |

**Not performed:** re-decompile, CE of 0x2031, caller list for NPC path `FUN_005d1280`.

---

## 2. Evidence used

### Mechanical packing (body)

| Offset (byte, from plate/topic) | Body store | Evidence quality |
|---------------------------------|------------|------------------|
| `+0` opcode | `*pPacket = 0x2031` | **Strong** |
| `+4` size short | `(n*3)*8 + 0x58` after targets | **Strong** |
| `+8` skillId | `skill+0x5fc` → `pPacket[2]` | **Strong** |
| `+0xC` level | short sum rank fields → `pPacket[3]` as short | **Strong** |
| `+0x10` delay | `max(0, skill+0x14 - param_11)` → `pPacket[4]` | **Strong** |
| `+0x14` status | byte `0` or `99` from `param_10` → `pPacket[5]` | **Strong value; weak meaning** |
| `+0x18..` position | `param_7` float3 → `pPacket[6..8]` | **Strong** |
| `+0x28` source TFID | `param_3+0x160..` → `pPacket[10..0xd]` | **Strong store; identity of param_3 open** |
| `+0x38` item flag | `*(bool*)(pPacket+0xe) = (param_5==0)` | **Polarity subtle** |
| targets @ `+0x50` region | walk from `pPacket+0x14` with -4 base writes | **Stride 6 dwords = 0x18** |

### What is *not* in body

- No `SendSectorPacket` / connection vtable send.
- `local_8` codes `0xd` (13) / `0xe` (14) **never assigned into status byte**.
- `operator_delete` immediately after optional local apply.

---

## 3. Attack results

### Claim 1 — This is *the* SkillStatusEffect network packer

| Sub-claim | Attack result |
|-----------|----------------|
| Builds 0x2031-shaped buffer | **Holds** |
| Sends it on the wire | **NOT SHOWN.** Delete without send |
| Server and client share this exact function | **Unproven** — gate `param_1+0x7e != 0` looks like **sim/server mode required**; client cast *send* path is 0x2030 |

**Alternate readings:**

1. **Local apply workspace** — buffer only exists to feed `Skill_ApplyStatusEffectLocal`.
2. **Decompiler lost send** before delete (possible; not evidenced).
3. **Caller sends** after return — but function **deletes** buffer and returns 0, so caller cannot send *this* allocation unless delete is wrong.

**Severity:** Critical for “network packer” product claims.

---

### Claim 2 — Status field is eSkillResponses (0 ok, 4 power, 6 busy, 7 CD, 13 range, 14 target)

| Sub-claim | Attack result |
|-----------|----------------|
| Topic list of eSkillResponses | Documented elsewhere |
| This packer writes those codes into `+0x14` | **BROKEN.** Only writes `0` or `99` (`'c'`) from `param_10` |
| Resolve errors 13/14 applied to status | **BROKEN.** Computed into `local_8`, never copied to packet; then `local_8` reused for ApplyStatusEffectLocal return |

**Severity:** Critical if ports expect this function to emit range/target failures in status.

---

### Claim 3 — `+0x10` is remaining charge (`lDelayTime`), not cooldown

| Sub-claim | Attack result |
|-----------|----------------|
| Body: `skill+0x14 - param_11`, clamp ≥ 0 | **Holds as formula** |
| `skill+0x14` is charge delay field | **Probable** (matches topic / other units using `+0x14` as charge) |
| Not cooldown | **Consistent** with topic claim that CD is optimistic HB elsewhere — **not proven solely here** |

---

### Claim 4 — Source TFID at `+0x28` must be character not vehicle (player path)

| Sub-claim | Attack result |
|-----------|----------------|
| Topic extraction retail notes | Strong *elsewhere* |
| This body enforces character TFID | **Falsified as enforcement.** It copies whatever `param_3+0x160` is |
| Correctness depends on caller | **Holds** — unit is dump of `param_3` identity fields |

---

### Claim 5 — Target entries are `{TFID, int16 mana, int16 maxMana, pad}`

| Sub-claim | Attack result |
|-----------|----------------|
| TFID four dwords written | **Holds** |
| Two shorts from object vtable `+0x214` result `+300` / `+0x12e` | **Holds** as raw offsets |
| Those shorts are mana/maxMana | **Probable name only** |
| Unresolved object → invalid TFID constants + zero shorts | **Holds** |

---

### Claim 6 — Size formula VERIFIED

| Sub-claim | Attack result |
|-----------|----------------|
| `n*0x18+0x58` | **Holds** against body math |
| Header size field is short at `pPacket+1` | **Holds** |

---

### Claim 7 — Item skill flag `+0x38` / `bIsItemSkill`

| Sub-claim | Attack result |
|-----------|----------------|
| Store exists at dword index `0xe` (byte offset 0x38) | **Holds** |
| Value `param_5 == 0` → true | **Holds as polarity** — so **param_5 non-zero clears item flag** |
| Topic “learned skills send 0, reaction/item use 1” | Must map through **param_5 polarity carefully** — naive “pass bIsItemSkill as param_5” may invert |

---

## 4. Alternate interpretations

### Minimal reading

```
if sim_flag && skill && source:
  build 0x2031 buffer in heap
  fill header fields from skill/source/args
  ensure TFID list (provided or ResolveTargetList)
  pack targets + terminator + size
  maybe ApplyStatusEffectLocal
  free buffer
  return 0
```

### Not proven

- Network emission.
- Full eSkillResponses emission.
- param roles beyond offsets used.

---

## 5. What was confirmed despite skepticism

1. Opcode `0x2031` and size formula.
2. Skill id / level / delay / position / source TFID stores.
3. Target stride 0x18 with optional mana shorts.
4. Status only 0 or 99 from param_10 in this body.
5. Resolve-error codes computed but not applied to status in-body.
6. Clean matches raw CF including missing send.
7. Distinct from client `0x2030` request path.

---

## 6. Critical contradictions found

### C1 — “Packer” without send + immediate free

Cannot be the complete wire implementation unless decompiler is wrong or apply-local is the only consumer.

### C2 — eSkillResponses narrative vs status byte domain `{0, 99}`

Topic/docs describe many status codes for **inbound** handling; this builder does not produce them.

### C3 — Resolve failure codes orphaned

`0xd`/`0xe` computation looks purposeful then discarded from the packet — either dead code path, missing status store, or errors only affect control flow not shown (they don’t — packing continues).

### C4 — Entry gate `+0x7e != 0`

Client cast *request* paths skip optimistic HB when world `+0x7e != 0` (server/sim). Here the function **requires** `+0x7e != 0`. That is a **mode polarity** worth sealing: this unit is likely **sim/server-side local/reaction cast**, not client outbound request.

---

## 7. Residual uncertainty

| # | Item | Blocks sealing? |
|---|------|-----------------|
| R1 | Network role vs local-only | **Yes** |
| R2 | Status code domain | **Yes** |
| R3 | Orphaned resolve errors | **Yes** |
| R4 | param_1..11 names | Yes |
| R5 | Caller `FUN_005d1280` contract | Yes |
| R6 | Whether delete is mis-decomp | Yes |

---

## 8. Concrete checks performed

1. Mapped every `pPacket[...]` store to topic offsets.
2. Confirmed no send callee in raw/clean.
3. Traced `local_8` from resolve flags through end of function — never stored to status.
4. Rechecked size formula algebra.
5. Compared `+0x7e` polarity to RequestCast / QuickBar HB gates (inverted requirement).
6. Verified target loop terminator condition and stride.
7. Clean vs raw parity including ApplyStatusEffectLocal gate.

---

## 9. Verdict

### **`needs-more-evidence`**

Field packing math for several header fields is strong; **network-packer and eSkillResponses-emitter stories do not survive**. Mode gate suggests sim/reaction local path.

### Port guidance

- Safe to use for **buffer field layout** of skill id, delay, size, target stride when building 0x2031-shaped messages.
- Do **not** assume this function sends.
- Do **not** assume it writes full eSkillResponses set.
- Preserve `+0x7e` gate polarity when matching retail client/sim split.
- Map item flag through `param_5 == 0` polarity carefully.

### Acceptance bar later

1. Caller graph for `0x004d09a0` (who consumes buffer?).
2. Asm check that send is not optimized into delete mis-id.
3. Explain or fix orphaned `local_8` codes.
4. Runtime 0x2031 capture vs this layout.

---

## 10. Summary table

| # | Claim | Result |
|---|-------|--------|
| 1 | Network packer | **Send not shown** |
| 2 | Full eSkillResponses in status | **Falsified** |
| 3 | Delay = remaining charge formula | **Holds** |
| 4 | Enforces character source TFID | **Falsified** (caller-owned) |
| 5 | Target slot layout | **Holds** (names soft) |
| 6 | Size formula | **Holds** |
| 7 | Item flag polarity | **Subtle / easy to invert** |

**Final verdict: `needs-more-evidence`**
