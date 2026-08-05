# Review B (skeptical / adversarial): `aa_008e9290` UiTargetPanel_PaintSlotChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e9290` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008e9290_UiTargetPanel_PaintSlotChrome_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Writes `unaff_ESI` as color | Asm `mov [eax], [esp+8]` stack color | **Falsified** decompiler store source |
| 2 | Mutates TFID match fields `+0x508/+0x50c` | Only color/paint path | **Falsified** |
| 3 | Always repaints every slot | Skip when `[buf+1]==desired` | **Falsified** as unconditional write |
| 4 | Selected key is −0x51 | Selected is **0xFF**; unselected **0xAF** | **Falsified** swap |
| 5 | Is the match loop itself | Match is parent `008e9690` | **Falsified** — paint only |
| 6 | ECX thiscall panel | Panel in **EAX** | **Falsified** as ECX-this |

---

## 2. Live ≡ raw

Live decompile matches 4-slot loop structure; assembly is authoritative for color dword packing (`0xFF32FF32` / `0xFFAFAFAF`).

---

## 3. Surviving contract

```
// EAX=panel*, EBX=selected_index_or_-1
// for i in 0..3:
//   slot = *(panel+0x5d8+4*i); if !slot continue
//   key/color = (i==EBX) ? 0xFF / 0xFF32FF32 : 0xAF / 0xFFAFAFAF
//   if colorBuf[1]!=key: write color, vtbl+0x34c, clear *(vtbl+0x1a0()+0x184)
```

**Verdict:** **accept-with-gaps**.
