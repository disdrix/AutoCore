# Review B (skeptical / adversarial): `aa_00513b00` Object_CopyReactionOrLocalTransform4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513b00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00513b00_Object_CopyReactionOrLocalTransform4_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Applies damage / impulse | Only copies 4 dwords | **Falsified** as apply |
| 2 | Always uses local `+0x160` | Prefers `+0x210` / `+0x214` first | **Falsified** always-local |
| 3 | Same as `GetWorldPositionPtr` (`00404c90`) | Different offsets / vtbls | **Falsified** merge |
| 4 | Out buffer ABI fully sealed | `unaff_*` decompiler noise | **Survives** as gap |
| 5 | Multi-target only | Called from single-hit `004d78e0` | **Falsified** multi-only |

---

## 2. Live ≡ raw

Live matches three-arm copy. Callers: `004d78e0`, skill ctor.

---

## 3. Surviving contract

```
// prefer transform4 from vtbl+0x210(0) component @+0x164
// else from vtbl+0x214() component @+0x164
// else obj local +0x160 (four dwords)
```

**Gaps kept:** out ABI; product vtbl names.

**Verdict:** **accept-with-gaps**.
