# Review B (skeptical / adversarial): `aa_00599dd0` ItemDef_CountConfiguredModSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00599dd0` |
| **VA** | `0x00599dd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00599dd0_ItemDef_CountConfiguredModSlots_Inferred.md` |
| **Evidence** | Live decompile + `read_memory` body + multi-caller set + `00513cf0` dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Returns bool only | Body adds up to five; AL can be 2..5 | **Falsified** |
| 2 | Scans a length-prefixed list | Fixed five offsets only | **Falsified** |
| 3 | Sentinel is `0` | Compare is `-1` (`OR EDX,-1`) | **Falsified** |
| 4 | Stack args / `__cdecl` | Plain `ret`; ECX host | **Falsified** |
| 5 | First field treated same as rest in asm | First: set EAX=0/1; rest: ADD 1 — same math | **Equivalent** |
| 6 | “Mod slots” product string on VA | No string | **Not sealed** — `_Inferred` |
| 7 | Clean diverges from live | Scaffold ≡ decompile | **Falsified** |
| 8 | Only used by broken-roll gate | Many UI/tooltip/garage callers | **Falsified narrow use** — gate is one consumer |
| 9 | Offsets on *item instance* always | `00513cf0` walks host→def; other callers may pass def directly | **Open host identity** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Count 0..5 of five dwords | **Confirmed** | Wrong eligibility / UI counts |
| Sentinel `-1` | **Confirmed** | Over/undercount |
| ECX object + offsets | **Confirmed** | Wrong layout class |
| “Mod” English | **Medium** | Doc only |
| Homogeneous object type across all xrefs | **Medium** | Mis-attributed layouts |
| Runtime | **N/A leaf** | — |

---

## 3. Surviving contract for AutoCore

```
// thiscall ECX=obj; ret 0
count = 0
for off in (0x498, 0x49c, 0x4a0, 0x4a4, 0x4a8):
  if *(int32*)(obj+off) != -1: count++
return (uint8)count   // 0..5
// NOT bool; NOT length-list; NOT zero-sentinel
```

Port rule: keep five fixed fields and `-1` empty. Do not collapse to “any non-zero.”

---

## 4. Cross-check vs `00513cf0`

`Item_HasModSlotConfig` is **`count > 0`** after a null-def gate — it does **not** reimplement the five-field walk. This unit owns the slot arithmetic; the predicate owns the host walk. Do not merge them.

---

## 5. Open questions

1. Product names for `+0x498..+0x4a8`.
2. Whether UI callers count the same semantic “mods” as loot broken gate.
3. RTTI / def class of ECX at each major caller.

**Verdict:** **accept-with-gaps** — adversarial pass keeps count CF sealed; English + host-class residual.
