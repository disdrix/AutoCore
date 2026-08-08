# Review B (skeptical / adversarial): `aa_005130e0` Object_IsWorldPickupType_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005130e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9R-C) |
| **Counterpart** | `reviews/A_aa_005130e0_Object_IsWorldPickupType_Inferred.md` |
| **Scratch** | `tmp/a_005130e0.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + analyze/xrefs/callers. **No** `disassemble_bytes`. Own VA `0x005130e0` only.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl free function | **Falsified** — callers set ECX; `RET 4` |
| 2 | Always ignores +0xac | **Falsified** — when stack arg≠0, `CMP [ecx+0xac],0` / `JNZ` out |
| 3 | Accepts all entities / creatures | **Falsified** — default 0; 0x12/0x14 not in table |
| 4 | All vehicles pass | **Falsified** — needs RTTI vehicle **and** `+0x2ac!=0` |
| 5 | Type1 always true | **Falsified** — returns bit7 of blob+0x3f2 only |
| 6 | Product name is Confirmed | **Overstated** — no plate/string; `_Inferred` required |
| 7 | “Pickup” is only role | **Partial** — also soft filterA==-1 and graphics gate; pickup string is strongest English anchor |
| 8 | Live diverges from scaffold raw | **Falsified** — identical CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 AL bool | **High** | ABI break |
| Type accept set | **High** | wrong loot filters |
| Vehicle special flag gate | **High** CF / Probable English | wrong abandoned-vehicle pick |
| requireLoose / +0xac | **High** CF / Probable English | over/under-filter held objects |
| Product name | **Inferred** | rename if PDB |
| Runtime | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if requireLoose==0 || this+0xac==0:
    switch type(this+0xa8 +0x38):
      1 → blob+0x3f2 >> 7
      {4,6,8,10,0xc,0x10,0x1a,0x1c,0x32,0x34,0x42} → 1
      0xe → RTDynamicCast Vehicle && +0x2ac → 1
  return 0

bytes:
  80 7C 24 04 00 … 83 B9 AC 00 00 00 00 …
  jump table @ 00513150 / index @ 00513160
  … 32 C0 C2 04 00
```

**No conflict** on owned ABI/CF/type table. English of flags and product name remain open.

---

## 4. Surviving contract for AutoCore

```
// Object_IsWorldPickupType_Inferred @ 0x005130e0
// ECX=object; stack requireLoose; RET 4; AL bool

// Port as pure type/loose gate — do NOT fold Gather mode logic here.
// filterA==-1 in Skill_GatherTargetPairFilter means "call this with 1".
// Interact prompt: true → "to pick up" branch.
// Vehicle: only special-flag (+0x2ac) vehicles, not all type 0xe.
```

Port rules:

- Keep type table exact; do not add Creature/Character.
- Preserve requireLoose polarity (1 = stricter).
- Nested RTTI cast addresses are image constants — do not invent alternate type checks without re-seal.

---

## Checklist

| Check | Result |
|---|---|
| Adversarial ABI attack | **Pass** (thiscall sealed) |
| Type table attack | **Pass** |
| Name humility | **Pass** (`_Inferred`) |
| No disassemble_bytes | **Pass** |
