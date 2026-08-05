# Review B (skeptical / adversarial): `aa_004fe380` Vehicle_ApplyItemStatusHooksOnEquip

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe380` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004fe380_Vehicle_ApplyItemStatusHooksOnEquip.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Same as `004fdcb0` skill cast | **Falsified** — different callees (`00508c00/50` hooks vs `CastSkillOnTarget`) |
| 2 | Runs without character host | **Falsified** — early gate on `+0xb0` and `+0x1dc` |
| 3 | All subtypes get hooks | **Falsified** — only def subtype **10** and **0xb** |
| 4 | Decompiler loop index is bit-exact | **Attack holds residual** — first loop uses `+0x5c(0)` in dump; may be index collapse |
| 5 | `unaff_retaddr` is random garbage | **Partial** — parent passes 0/1; treat as **flag**, not proven portable formal |
| 6 | Product name final | **Fail** — inferred from equip dual call sites |
| 7 | Ready for bit-exact | **Fail** |

---

## 2. Surviving contract

```
thiscall(vehicle, item /*, flag residual */):
  if !host || !host.resolve || !item: return
  FUN_004ce940()
  for each skill-ish entry on item tables:
    hA = FUN_00508c00(id); hB = FUN_00508c50(id)
    if subtype==0xb && hA: hA.vtbl+4(item, resolve(...))
    if subtype==10 && hB: hB.vtbl+4(item, resolve(...))
  // second loop: hash-loaded defs at +0x4c0 same pattern
```

Ornament dual: unbind path `FUN_004fe380(prev,0)` then bind `FUN_004fe380(new,1)` — **survives**.

---

## 3. Open

| Topic | Why |
|---|---|
| Handler map product types | `00508c00/50` undualed |
| First-loop index fidelity | decompiler residual |
| Full ABI of flag | unaff |

**Verdict:** Distinct from cast unit; subtype split sealed. **accept-with-gaps.**
