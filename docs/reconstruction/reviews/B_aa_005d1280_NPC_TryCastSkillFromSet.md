# Review B (skeptical / adversarial): `aa_005d1280` NPC_TryCastSkillFromSet

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d1280` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` (dual residual strengthen `2026-07-29`) |
| **Counterpart** | `reviews/A_aa_005d1280_NPC_TryCastSkillFromSet.md` |
| **Verdict** | **accept-with-gaps** on CF + entry roles; packing pads / return type / runtime open |

---

## 1. Claims under attack

| # | Claim | Attack outcome |
|---|---|---|
| 1 | Player quickbar cast | **Falsified** — NPC AI set cast from HBAIDriver |
| 2 | Ignores LocalCastValidate | **Falsified** — required return 0 |
| 3 | Entry layout fully PDB-sealed | **Falsified as total seal** — roles High; pads/packing INFERRED |
| 4 | Stride 0x10 or 0x20 | **Falsified** — body + GetEntryCount use **0x18** |
| 5 | Always returns null | **Falsified** — early map-node / rand residue; fallthrough `pResult` |
| 6 | Pad fields have product names | **Blocked** — no string; leave INFERRED unnamed |
| 7 | Threat write always fires | **Falsified** — only when slot-timer path captured skill `+0x28` and threat list empty |
| 8 | Client always runs full cast | **Open / Tentative** — gated on `world+0x7e`; product server-only unproven at runtime |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pipeline order (9 stages) | **High** | NPC never casts / spam |
| Post-cast map `+0x98`/`+0x9c` | **High** | Cast thrash |
| Entry stride 0x18 | **High** | Wrong skill index / OOB |
| Used entry field **roles** | **High** | Wrong skill / band / CD arm |
| Entry **byte packing** (pads) | Tentative | Misaligned load if rank/delay wrong width |
| `world+0x7e` gate | Tentative product | Client false cast if gate misread |
| Return type | Unsettled | Caller misuse of pointer |
| Threat scalar | Tentative | AI threat mis-port |

---

## 3. Cross-check against raw + re-decompile

```
if postCD live: return node;
if LocalCastValidate!=0 or !world+0x7e: skip;
optional chance gate (90 - chance*0.001*40 < rand%100);
lookup set; HP=cur/max; random start;
for each entry stride 0x18:
  load skill; EnsureLoaded(rank); HP band; skip cast/CD/state;
  resolve TFID; Resolve/Range/Validate; Cast; arm postCD=now+delayMs;
optional threat scalar.
Clean ≡ raw ≡ 2026-07-29 decompile CF.
```

---

## 4. Surviving contract for AutoCore

```
NPC_TryCastSkillFromSet(aiCtrl, setIndex):
  NPC cast from skill bank; pair HBAIDriver + LocalCastValidate family
  Entry vector stride 0x18; roles: skillId, delayMs, sRank, hpMin, hpMax
  Do not invent pad product names; do not claim PDB seal
  AutoCore NPC combat skills critical; runtime pick table still open
```

---

## 5. Residual disposition

| Prior gap | Disposition |
|-----------|-------------|
| Entry stride 0x18 | **Sealed High / Confirmed** (body + GetEntryCount) |
| skillId / delayMs / sRank / hpMin / hpMax roles | **Sealed High** from CF field use |
| Pad @+4 / +0xa / +0x14 product names | **Leave INFERRED** (no string) |
| Byte packing formal (asm) | Still open (policy: no disassemble) |
| Cast-chance float constants | **Sealed** via `read_memory` (90 / 40 / ~0.001 / 2^32) |
| Return type | Still unsettled |
| Server-only `world+0x7e` | CF High; runtime open |
| Live AI cast capture | Still open |
| Threat scalar product | Still open |

**Verdict:** **accept-with-gaps** — CF + entry roles sealed; packing pads unnamed INFERRED; return / runtime remain.
