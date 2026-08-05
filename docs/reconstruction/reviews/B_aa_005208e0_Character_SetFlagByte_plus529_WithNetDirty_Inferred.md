# Review B (skeptical / adversarial): `aa_005208e0` Character_SetFlagByte_plus529_WithNetDirty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005208e0` |
| **VA** | `0x005208e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005208e0_Character_SetFlagByte_plus529_WithNetDirty_Inferred.md` |
| **Evidence** | Live decompile + body bytes; callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always dirties net even if unchanged | **Falsified** | `cmp [esi+0x529], al; je` skip |
| 2 | Dirties heat/combat mask `0x20000000` | **Falsified** | imm is `0x100` |
| 3 | Writes a different offset | **Falsified** | `+0x529` in encoding |
| 4 | Only dirties character, never vehicle | **Falsified** | second path via `this+0x250` |
| 5 | Validates / clamps to 0/1 | **Falsified** | raw char store |
| 6 | Clean invents dual-dirty | **Falsified** | raw ≡ clean ≡ live |
| 7 | Semantic flag name known | **Open** | body is mechanical only |

---

## 2. Surviving contract

```
Character_SetFlagByte_plus529(self, v):
  if *(s8*)(self+0x529) == v: return
  *(s8*)(self+0x529) = v
  if charNet: NetObject_SetMaskBits(charNet, 0x100, 0)
  if vehicle && vehicleNet: NetObject_SetMaskBits(vehicleNet, 0x100, 0)
```

**Verdict:** **accept-with-gaps**
