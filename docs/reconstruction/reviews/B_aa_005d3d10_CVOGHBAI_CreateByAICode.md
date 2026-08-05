# Review B (skeptical / adversarial): `aa_005d3d10` CVOGHBAI_CreateByAICode

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d3d10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d3d10_CVOGHBAI_CreateByAICode.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on Character redirect scalars |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always CreatureBase | **Falsified — switch multi-class** |
| 2 | Driver is size 0x100 | **Falsified — 0x110** |
| 3 | Case 6 runs profile trio | **Falsified — plate skips post-ctor for 6** |
| 4 | AICode is float business value | **Falsified — int encoded as tiny floats** |
| 5 | Finished exact profile field map | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| AICode→class map | High | Wrong HBAI subclass / crash |
| Alloc sizes | High | Heap overrun |
| Character redirect gate | Tentative | Wrong foot vs char AI |
| Profile post-init slots | Tentative | Uninitialized ranges |

---

## 3. Cross-check against raw

```
switch AICode(int as float bits):
  1: CharacterOrMine 0x110 (or redirect Creature 0x100)
  2: CreatureBase 0x100
  3: Bot 0x100
  4: CharacterOrMine 0x110
  5: Driver 0x110
  6: WalkingTurreted 0xD0
  def: Base_Default 0xD0
stamp size@+4; post-ctor profile vcalls (not 6).
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
CreateByAICode(aiCode, ctx, profileFloats):
  map AICode → HBAI subclass + heap size; construct; init profile
  Driver AICode 5 is required for DR NPC vehicles
  Do not invent codes; table is tCreatureAI AICode field
Server may mirror class choice for sim or keep AI server-authoritative.
```

---

## 5. Open questions

1. Seal Character redirect formula vs tCreatureAI columns.
2. Confirm case 6 rarity in retail AI table.
3. Ghidra: name DAT_00b05060 allocator.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on Character redirect scalars
