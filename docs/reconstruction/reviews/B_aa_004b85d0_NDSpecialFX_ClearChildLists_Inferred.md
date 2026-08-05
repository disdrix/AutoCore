# Review B (skeptical / adversarial): `aa_004b85d0` NDSpecialFX_ClearChildLists_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b85d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004b85d0_NDSpecialFX_ClearChildLists_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full FX destructor (frees host) | No `operator_delete(this)`; no free of `+0x3C`/`+0x60` | **Falsified** as full dtor — list-only |
| 2 | Only mission audio cleanup | Five lists + map; audio is `+0x1EC` optional branch | **Falsified** as audio-only |
| 3 | Identical to `FUN_004b99c0` | TeardownCore also frees blocks, bit0 unlink, map header | **Distinct** |
| 4 | Always stops sounds | Requires payload `+0x10B != 0` | **Survives** as conditional |
| 5 | Noreturn deletes abort mid-clear | Known Ghidra artifact; multiple sequential clears in source | **Survives** as noise |

---

## 2. Live ≡ raw

Live decompile matches raw `aa_004b85d0`: sequential list resets at `+0x1E0`, `+0x204`, `+0x210`, `+0x1EC`, `+0x1F8`, map at `+0x228`. Parent dual `A_aa_004b99c0` documents this as step 3 of teardown.

---

## 3. Surviving contract

```
// fastcall ECX = NDSpecialFX*
// clear+free child intrusive lists @ +0x1E0,+0x204,+0x210,+0x1EC,+0x1F8
// clear map tree @ +0x228 (payload free + RB walk / 004ba770)
// does not free host, +0x3C, +0x60, or map header allocation itself beyond node walk
```

**Gaps kept:** payload type names; exact map free completeness under decompiler splits.

**Verdict:** **accept-with-gaps**.
