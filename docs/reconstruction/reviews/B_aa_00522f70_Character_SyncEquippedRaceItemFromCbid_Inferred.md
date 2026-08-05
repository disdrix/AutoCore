# Review B (skeptical / adversarial): `aa_00522f70` Character_SyncEquippedRaceItemFromCbid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522f70` |
| **VA** | `0x00522f70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00522f70_Character_SyncEquippedRaceItemFromCbid_Inferred.md` |
| **Evidence** | Live decompile; callee names; sibling setter `0x00524680` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always recreates item even if CBID matches | **Falsified** | resolve + clonebase `+0x34` compare gate |
| 2 | Creates item when CBID is `-1` | **Falsified** | early stop after teardown |
| 3 | Does not call GiveItemByCbid | **Falsified** | direct call on create path |
| 4 | Writes CBID field itself | **Falsified** | reads `+0x514` only (setter is `0x00524680`) |
| 5 | `unaff_ESI` TFID dest is proven `+0x518` | **Open** | decomp artifact; plausible but unsealed |
| 6 | Definitely “race item” product name | **Open** | structural inference from vehicle twin + CBID equip pattern |
| 7 | Clean invents spawn math | **Falsified** | float imms present in raw |
| 8 | `__thiscall` with stack arg | **Falsified** | decomp `__fastcall` ECX-only |

---

## 2. Surviving contract

```
Character_SyncEquippedRaceItemFromCbid(self):
  obj = ResolveTFID(self+0x518)
  if obj && clonebase(obj).cbid == *(self+0x514): return
  TeardownPrior(self)           // FUN_005210b0
  if *(self+0x514) == -1: return
  item = GiveItemByCbid(cbid)
  if !item: return
  // init / spawn near char / attach / scale / cache TFID
```

**Residual risk:** TFID write-back target; teardown helper semantics; product naming.

**Verdict:** **accept-with-gaps**
