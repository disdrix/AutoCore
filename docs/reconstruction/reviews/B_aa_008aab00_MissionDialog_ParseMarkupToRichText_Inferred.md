# Review B (skeptical / adversarial): `FUN_008aab00` @ `0x008aab00`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aab00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md` |
| **Verdict** | **accept-with-gaps** on markup matrix + ABI + paint ordinals; **needs-more-evidence** on product names and key-display helpers |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is `__thiscall` with ECX = widget this | Entry `mov esi,ecx` treats ECX as **string**; widget is stack; callers push widget | **Falsified as classic thiscall-on-widget** — survives as ECX=markup, stack=widget |
| 2 | Function is mission **journal state** writer | No stores to journal/mission objects; only widget vtbl calls + locals | **Falsified** — paint-only |
| 3 | Only used by UpdateMissionJournal | 6 xrefs across detail panel, journal helper, other UI | **Falsified sole-caller** — multi-caller chrome helper |
| 4 | Scaffold `Named_npc` is product name | Only one of many tags; auto plate from `[$/npc]` | **Demote / reject product** |
| 5 | All `[$` sequences are tags | Unknown `[$` falls through to emit first char as plain | **Survives with unknown-tag path** |
| 6 | Colors are RGB only | Immediates are 0xFFxxxxxx → ARGB with alpha 255 | **Survives as ARGB** |
| 7 | Key table always populated in image | `read_memory` @ `DAT_00d1bbf5` all zero static | **Survives as runtime-filled** |
| 8 | `FUN_007f9160` always sprintf-formats | Non-zero return **skips** sprintf (goto append path) | **Survives with branch** |
| 9 | Clean invented pause length | Immediate `0x14` in decompile | **Falsified invention** |
| 10 | Body larger than chkstk frame suggests | Frame 0x204c matches work+run+staging; bounds 0x458 code size | **Survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tag open/close matrix | **High** | Wrong mission text colors |
| ABI ECX/stack | **High** | Call sites crash / wrong paint target |
| AppendText +0x250 | **High** | Silent no text |
| SetColor/PopColor ordinals | **High** role / **Tentative** names | Cosmetic port mislabel |
| Key path CF | **High** | Wrong hotkey labels in dialogs |
| Key table stride/count | **High** math | Truncated bind scan |
| Product function name | **Open** | Registry noise |
| Free Look special case English | **High** string | Wrong default key label |

---

## 3. Cross-check spine

```
if !widget || !markup: return
FUN_007a69d0()
copy markup → work[4096]
i=0; runLen=0
while work[i]:
  if work[i]=='[' and work[i+1]=='$':
    flush run via vtbl+0x250 if runLen>0
    match tags:
      color open  → vtbl+0x230(color)
      color close → vtbl+0x23c()
      pause       → vtbl+0x254(0x14)
      key open…close → resolve display → vtbl+0x250
      else        → emit '[' into run
  else:
    accumulate plain
flush trailing run
```

### What this unit is **not**

| Non-claim | Why |
|---|---|
| S2C / C2S packet handler | no opcodes / send helpers |
| Dialog button rebuild | that is `FUN_008ac110` / clear is `008aa560` |
| Reward chrome fill | `FUN_008aa760` |
| Complete objective | separate managers |

---

## 4. Residual attacks left open

1. Could +0x230 be “set style” not color? (Immediates look like ARGB; multi-tag parallel pattern strongly color.)
2. Does `FUN_007f9160` write into `local_2040` or a TLS/global display buffer?
3. Is work buffer exactly 4096 or decompiler split artifact (`local_1000`+`local_ffa`)? **Total ~4K sealed by frame.**

---

## 5. Verdict

**accept-with-gaps** — adversarial pass fails to break markup matrix, ABI, or paint ordinals; product English and key-helper internals remain open. No runtime Confirmed.
