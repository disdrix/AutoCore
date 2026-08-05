# Review B (skeptical / adversarial): `Client_Skill_ResolveCastTarget` @ `0x0093b3a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093b3a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23`; **residual close** `2026-07-29`; **hardpoint strengthen** `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0093b3a0_Client_Skill_ResolveCastTarget.md` |
| **Verdict** | **accept-with-gaps** on CF + sealed static residuals (incl. hardpoint plate); runtime open |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the only TFID resolve for player cast | **Overstated** — reactions/NPC use ResolveTargetList directly; two extra FUN_* callers exist |
| 2 | outFlags bit4 means “area/no enemy” | **Weak English** — bit real; label still toast-inferred (0xe = Wrong target type via FormatFailure table) |
| 3 | `FUN_004f8b80` is nearest enemy | **Falsified / renamed** — hardpoint occupant TFID walk; fail string "No enemies found." is UX only |
| 4 | Invalid TFID always means “no cast” | **Partial** — callers (RequestCast) check equality; silent invalid is intentional on sticky/on-foot gates |
| 5 | Clean renamed params change ABI | **Falsified** — still 5 formals + client-in-EAX (`RET 0x14`) |
| 6 | Sticky path writes active-bind TFID to out | **Falsified by asm** — write_seed uses listOut regs; binding only gates silent vs toast |
| 7 | `pA` is unrecovered garbage | **Falsified** — `local_750` / activeBindScratch |
| 8 | Hardpoint this is client object | **Falsified** — ECX = `*(char+0x250)`, not client; not resolveSource |
| 9 | Helper sentinel is a different invalid | **Partial** — different **pointer** (`DAT_009cd0f8` ≠ `A15870`); **content identical** (`read_memory` Confirmed) so Equals always treats empty as invalid |
| 10 | Hardpoint overrides related | **Falsified** — related (`skill+0x614&2`) tested **before** hardpoint (`&8`) on bit4 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| outFlags bit tests | High CF | Wrong fail/success branch |
| Toast codes 0xd / 0xe / 3 | High presence + FormatFailure seal | Wrong eSkillResponses map |
| Active-binding first arg | **Confirmed** | Miss sticky gate |
| Sticky out TFID source | **Confirmed invalid listOut** | Wrong server target if assumed sticky TFID |
| Related vtbl `+0x19c` | Medium–High | Wrong self TFID |
| Hardpoint ECX this plate | **Confirmed** | Wrong entity for slot walk |
| Hardpoint reload → write_seed | **Confirmed** | Dropped occupant TFID |
| Sentinel content ≡ invalid | **Confirmed** | Miss empty-hardpoint fail |
| Hardpoint product word | Probable / `_Inferred` | Name only |

---

## 3. Surviving contract for AutoCore

```
ResolveCastTarget (player; client in EAX; 5 stack formals):
  require local character (+0xe98)
  optional force-seed when skill+0x614 == 1
  ResolveTargetList(world, source, seed, aim) → outFlags + TFID
    filter may OR bits 4 / 8 / 0x10
  on list valid: write 16B TFID to out
  on bit4:
       if skill&2 → related TFID (vtbl+0x19c → +0x164)
       else if skill&8:
            this = *(char+0x250)
            tfid* = Vehicle_ResolveFirstHardpointOccupantTfid_Inferred(this)
            reload write_seed regs from *tfid
            if TFID_EqualsObjectId(tfid, g_abTfidInvalid) == 0 → write_seed
            else fail: optional "No enemies found." (report && !on-foot); invalid
       else fail code 0xe
  on list invalid + skill+0x615&2 + active bind present:
       write invalid silently (no sticky TFID promote)
  on hard fail: optional chat; write invalid sentinel
```

---

## 4. Hardpoint residual attack results

| Residual | Attack | Outcome |
|---|---|---|
| Helper is enemy search | UX string only; body is 3-slot walk | **Closed** as occupant TFID helper |
| this source | asm `MOV ECX,[char+0x250]` | **Closed Confirmed** |
| Empty vs invalid | `read_memory` DAT_009cd0f8 ≡ A15870 16B | **Content sealed**; pointers still distinct |
| Related vs hardpoint order | `&2` before `&8` on bit4 | **Closed Confirmed** |
| Product “hardpoint” | no string in helper or this unit | **Still open** (name `_Inferred`; does not block role) |

---

## 5. Open questions

1. ~~Seal `FUN_004f8b80`~~ **Closed** as hardpoint occupant helper.
2. ~~Who sets outFlags bits 4 and 8~~ **Closed** at filter.
3. ~~Recover `TFID_NotEquals` first arg~~ **Closed** → activeBindScratch.
4. ~~Hardpoint this / reload / sentinel content~~ **Closed** this strengthen.
5. Runtime / differential verification.
6. Why sticky silent-invalid (channel UX?) — product intent open.
7. Slot-table product English — owned by `aa_004f8b80`.

**Verdict:** Safe hop unit for cast pipeline; dual static residuals including hardpoint call-site plate closed 2026-07-29. Do not invent sticky-as-target or “nearest enemy search” without new asm evidence. Keep helper name `_Inferred` until product string anchors the slot table.
