# Review B (skeptical / adversarial): `aa_004fdcb0` Vehicle_CastItemSkillsOnEquip

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fdcb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004fdcb0_Vehicle_CastItemSkillsOnEquip.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function attaches weapon mesh | **Falsified** — no slot store; only skill/reaction casts |
| 2 | Always casts something | **Falsified** — multiple gates; empty skill tables no-op |
| 3 | operator_delete aborts function | **Falsified as product behavior** — decompiler warning; loop structure continues (attack on clean “noreturn” claim) |
| 4 | Only weapons call this | **Falsified** — armor/wheelset/ornament/melee xrefs |
| 5 | Phase B runs without world context | **Falsified** — `FUN_004ce940==0` skips phase B |
| 6 | Bit `0x100` meaning finished English | **Fail** — flag sealed; name open |
| 7 | Ready for bit-exact skill replay | **Fail** — runtime open |

---

## 2. Surviving contract

```
thiscall(vehicle, item):
  if !host || !clonebase || !item || !ResolveFromTFID(host.tfid): return
  // phase A: item reaction list flag 0x100 → CastSkillOnTarget
  // phase B: if world ctx: foreach skill slot tables → Resolve + Cast + delete
```

Equip duals that call this **after** bind (`+0x158`) cannot be attacked away.

---

## 3. Open

Skill-id table product layout; delete-vs-loop decompiler noise; runtime.

**Verdict:** Role = equip skill cast, not mesh attach. **accept-with-gaps.**
