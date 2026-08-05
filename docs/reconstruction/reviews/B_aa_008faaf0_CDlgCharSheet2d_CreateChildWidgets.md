# Review B (skeptical / adversarial): `CDlgCharSheet2d_CreateChildWidgets` @ `0x008faaf0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008faaf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B; decompiler blocked) |
| **Counterpart** | `reviews/A_aa_008faaf0_CDlgCharSheet2d_CreateChildWidgets.md` |
| **Verdict** | **accept-with-gaps** on UI role + asset set; **reject full-CF accept** until decomp/asm recovery |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Full clean CF ≡ retail | Clean is a structural stub (`return;` after comments) | **Survives as gap** — clean plate already marks NOT CF-complete; do not promote to accept |
| 2 | Decompiler blocked so function is unknown | Signature + 30 strings + image prolog | **Falsified** — role is character-sheet widget construct |
| 3 | Spends attribute points / mutates char stats | Would call spend/net helpers | **Falsified** — callees are UI ctor/attach/XML + optional first-time tip |
| 4 | Sends network packets | Would call `Client_Send*` / bitstream | **Falsified** — not in callee set |
| 5 | Only experience/credits (no attrib UI) | Missing add-button / tooltip strings | **Falsified** — full combat/theory/tech/perception set present |
| 6 | Direct CALL from many sites | Multi-caller graph | **Falsified** — single **DATA** xref `0x00a35b30` (virtual) |
| 7 | First child XML is experience label | Infer from string table order alone | **Falsified for first load** — image pushes `i_d_tabs_c_2d_wnd_icon.xml` first after attach |
| 8 | Host offset map is finished | Scaffold listed no offsets | **Partially sealed** — image shows at least `+0x1478` and `+0x1464`; rest open |
| 9 | Tip always shown on construct | MaybeShow is unconditional | **Not sealed** — callee exists; conditions/id residual |

---

## 2. What the evidence actually proves

| Fact | Strength |
|---|---|
| Function at `0x008faaf0` named `CDlgCharSheet2d_CreateChildWidgets` | **Proven** (Ghidra) |
| `void __fastcall (void *this)` / ECX this | **Proven** |
| Decompile fails with overlapping varnodes | **Proven** (live + force) |
| 671 insns / 69 BB / ~30 calls / 30 string refs | **Proven** (signature) |
| DATA slot `0x00a35b30` = this VA | **Proven** (`read_memory` LE dword) |
| Entry: SEH → `FUN_00792600` → `operator_new(0x488)` → `FUN_0040ddd0` | **Proven** (image) |
| Store child @ `this+0x1478`; attach `vtbl+0xA8`; load XML `child.vtbl+0x28` | **Proven** (image) |
| Early XMLs include tab icon, icon cover, bg_character | **Proven** (push imm string addrs) |
| Full `i_d_c_2d_*` experience/credits/attrib/tooltip/close set in body | **Proven** (string refs) |
| Calls `Client_MaybeShowFirstTimeTip` somewhere in body | **Proven** (callee list) |
| Exact tip id and whether gated | **Open** |
| Complete offset↔widget English map | **Open** |
| Bit-exact / runtime | **Open** |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UI CreateChildWidgets for char sheet | **High** | Mis-file system ownership |
| No packet / no attrib-spend in this VA | **High** | Wrong server work from UI dual |
| Construct pattern matches sibling dialogs | **High** | Wrong ctor size / attach vfunc |
| First recovered slots `+0x1478` / `+0x1464` | **High** | Wrong child ownership in ports |
| Full ordered build sequence | **Medium** | Blank/wrong chrome if reimplemented from scaffold only |
| Tip id / when shown | **Tentative** | Wrong first-time UX bit |
| Clean plate as executable CF | **Low** | Anyone treating stub as complete will ship empty dialog |

---

## 4. Surviving contract for AutoCore

```
CDlgCharSheet2d (client dialog, virtual CreateChildWidgets):
  vtbl DATA slot @ 0x00a35b30 → CDlgCharSheet2d_CreateChildWidgets @ 0x008faaf0

  CreateChildWidgets(this):
    FUN_00792600()                    // base / list init
    repeat:
      child = operator_new(0x488)     // dominant child size (also other sizes e.g. 200 possible)
      FUN_0040ddd0 / FUN_007b5dd0     // child ctors (both callees)
      store child* into this+host_off  // known: +0x1478, +0x1464; more residual
      this->vtbl+0xA8 attach
      child->vtbl+0x28 load "i_d_c_2d_*.xml" / "i_d_tabs_c_2d_*.xml"
      optional this->vtbl+0x404 / child->vtbl+0xFC layout helpers
    Client_MaybeShowFirstTimeTip(...) // optional tip; id residual
    // no C2S; no attribute mutation

  Asset family: title/name/level_race_class/clan, XP+credits (+wide),
    four attrib panes + add buttons + tooltips, tab icon(+cover), close.
```

Porting guidance: **do not** implement attribute point spend or credit editors inside this function. Wire those to separate handlers. This VA is **chrome construction**.

---

## 5. Open questions (must not be papered over)

1. Full decompile after varnode fix **or** complete asm reconstruction of 69 blocks.
2. Exhaustive host-offset table (all ~30 children).
3. Exact `Client_MaybeShowFirstTimeTip` tip id(s) and branch conditions.
4. Vtable base address and slot offset (English method index).
5. Meaning of immediates 40000–40004 (control ids?).
6. Whether wide XP/credits variants are resolution-gated or always dual-created.
7. Runtime open-once vs every show.

---

## 6. Verdict

**accept-with-gaps.**

Adversarial position: role, virtual dispatch, XML asset family, and image-sealed construct prolog are **solid**. The clean three-rep is correctly a **structural scaffold**, not a CF twin of retail. Do **not** upgrade to clean **accept** until decompiler recovers or a full asm walk produces offset-complete clean plate. Residual is reconstruction depth, not identity of the function.
