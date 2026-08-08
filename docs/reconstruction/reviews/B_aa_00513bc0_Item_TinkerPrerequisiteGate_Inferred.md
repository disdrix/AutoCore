# Review B (skeptical / adversarial): `aa_00513bc0` Item_TinkerPrerequisiteGate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513bc0` |
| **VA** | `0x00513bc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-104 OWN-ONLY) |
| **Counterpart** | `reviews/A_aa_00513bc0_Item_TinkerPrerequisiteGate_Inferred.md` |
| **System** | inventory-transfer / tinker kit validation |
| **Verdict** | **accept-with-gaps** |

**Tools:** Same live Ghidra set as Path A. **No** `disassemble_bytes`. No Launcher / runtime Confirmed.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This **is** the full tinker validator / applies the kit | Body is pure type compare; no skill/level/charge | **Falsified** as full validator — leaf prereq only |
| 2 | This **is** the skill check for “You do not possess the Tinkering skill…” | No skill table / no string; skill path is parent + `FUN_00521eb0` | **Falsified** as skill check |
| 3 | `__fastcall` / no stack arg / plain `RET` | Machine: `[ESP+4]` candidate + `C2 04 00` | **Falsified** |
| 4 | Returns full EAX status codes 0/1/2/3 like parent | Machine clears/sets **AL only**; parent maps fail→3 | **Falsified** as multi-status |
| 5 | Type `0x44` always allowed | Requires kit def subtype **10** | **Falsified** as unconditional |
| 6 | Type `0x46` always allowed | Requires kit def subtype **11** | **Falsified** as unconditional |
| 7 | Scaffold name implies nested skill-string callee product role | Xref-seed plate only; sole caller is type validator | **Falsified** product plate |
| 8 | Multiple static callers | 1 UNCONDITIONAL_CALL @ `0x00513c36` | **Survives** — narrow |
| 9 | Direct type match is `cand host+0x38` | Candidate load is **`+0xb4`** on the pointer; kit uses host `+0xa8`→`+0x38` | **Survives with asymmetry** |
| 10 | `0x44`/`0x46` invent product “gadget” names | Numeric sealed; English open | **Tentative** product only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + RET 4 + AL bool | **High** | Wrong port convention |
| Direct / 0x44 / 0x46 branch membership | **High** | Accept wrong item classes for tinker |
| Subtype immediates 10 / 11 | **High** | Break type-6 remap family |
| Sole static caller | **High** | Miss dynamic dispatch if any |
| Role = prereq gate (not skill/charge) | **High** | Mis-place in port stack |
| Product type English / field names | **Tentative** | Docs only |
| `candidate+0xb4` vs always `host+0x38` layout story | **Probable** | Type source confusion |

---

## 3. Cross-check against raw / peers

- Live decompile **≡** 2026-07-23 scaffold CF.
- Disassembly sequential `SUB 0x44` / `SUB 2` confirms **only** 0x44 and 0x46 specials — no hidden cases.
- Peer `FUN_00509b10`: type-6 subtype **10→0x44**, **11→0x46** — inverse consistency.
- Peer `FUN_00513d10` (`Item_IsAffixableType_Inferred`): type-6 subtype window **10–11** — same subtype pair.
- Parent `FUN_00513c10` call site: `TEST AL,AL` / fail→`mov eax,3` — status codes live in parent, not here.

---

## 4. Surviving contract for AutoCore

```c
// Port as leaf bool gate. Do NOT merge skill/level/charge logic from FUN_00513c10.
bool Item_TinkerPrerequisiteGate(Item* kit /*this*/, Item* candidate) {
  if (!candidate) return false;
  auto* host = kit->field_a8;
  uint32_t candType = candidate->field_b4;
  if (candType == host->type /*+0x38*/) return true;
  if (candType == 0x44) return host->def /*+0x3c*/->subtype /*+0x3f4*/ == 10;
  if (candType == 0x46) return host->def->subtype == 11;
  return false;
}
// ABI: thiscall, RET 4, AL bool.
// Keep distinct from Item_ValidateTinkerKitUse (00513c10) and Character_GetTinkerSkillOrCap (00521eb0).
```

---

## 5. What would overturn this dual

1. Additional type specials in retail not visible in current body (would require different image).
2. Evidence `RET 4` is wrong / extra stack args.
3. Static or dynamic callers beyond `FUN_00513c10` that use return as multi-status.
4. Evidence subtype compares are not exact equality to 10/11.

**Verdict:** **accept-with-gaps** — CF/ABI/type specials **High**; product lexicon + parent dual open.
