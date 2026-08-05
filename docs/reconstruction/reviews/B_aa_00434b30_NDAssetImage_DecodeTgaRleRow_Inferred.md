# Review B (skeptical / adversarial): `aa_00434b30` NDAssetImage_DecodeTgaRleRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00434b30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-P) |
| **Counterpart** | `reviews/A_aa_00434b30_NDAssetImage_DecodeTgaRleRow_Inferred.md` |
| **Verdict** | **accept-with-gaps** on RLE/row ABI; residual product names + stream English |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | cdecl / bare `RET` | **Falsified** — epilogue **`RET 0x18`**; thiscall + 6 stack args |
| 2 | Returns full EAX success code | **Falsified** — only **AL** = RLE state; `CONCAT31` is decompiler packing |
| 3 | Decodes whole image | **Falsified** — **one row**; outer loop is LoadTGA |
| 4 | Only 24/32 bpp | **Falsified** — cases **8, 15, 16, 24, 32** via jump table |
| 5 | RLE count = `pkt & 0x7F` (no +1) | **Falsified** — `pkt - 0x7F` ≡ `(pkt&0x7F)+1` when high bit set |
| 6 | No cross-row state | **Falsified** — `param_7` carry + stream pos rewind on RLE span |
| 7 | Multiple independent callers | **Falsified** — sole `NDAssetImage_LoadTGA` `@0x00434a34` |
| 8 | Leaf (no callees) | **Falsified** — `FUN_00434dd0`, `FUN_00433280`, stream vtbl |
| 9 | 32bpp writes 4 B into dest row | **Falsified** — writes **3 B RGB** + separate alpha via `FUN_00433280` |
| 10 | Decompile drifted vs raw | **Falsified** — live ≡ 2026-07-23 body |
| 11 | Clean modernized CF | **Falsified** — clean preserves decompiler CF |
| 12 | Product name sealed by string | **Sustained gap** — no in-body product symbol; `_Inferred` correct |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI / `RET 0x18` / AL state | **High** | Broken row loop / stack smash when porting |
| RLE vs raw split | **High** | Corrupt TGA pixels |
| bpp allow-list via table | **High** | Wrong expand path |
| Cross-row leftover encoding | **High** CF; **Tentative** exact encode formula edge cases | Stripe artifacts on wide RLE |
| Stream `+0x14`/`+0x10` roles | **High** call shape; **Tentative** English | Wrong seek semantics |
| `FUN_00433280` alpha plane | **Probable** (sibling dual exists) | Alpha ignored / wrong plane |
| Product name | **Tentative** | Naming only |

---

## 3. Cross-check

```
Rep A — decompile_function(0x00434b30):
  SEH; loop width; RLE/raw; bpp switch; FUN_00434dd0; FUN_00433280; AL state

Rep B — read_memory prologue/epilogue + tables:
  55 8B EC 6A FF 68 C0CC9B00 … 8B D9 33 F6
  epilogue … 8A 45 1C … C2 18 00
  table 00434d9c → 00434cce/00434c6e/00434c32/00434bde/00434cfa
  index 00434db0 bpp-8 map

Rep C — xrefs + assembly_context(00434a34):
  sole CALL from NDAssetImage_LoadTGA; MOV [ebp-0x2c], AL
```

**Attack on “RLE is optional decoration”:** LoadTGA routes types 9/10/11 exclusively here; wrong CF breaks all compressed TGA. **High severity if wrong; sealed.**

**Attack on naming `NDAssetImage_*`:** sole caller is sealed `NDAssetImage_LoadTGA`; structural membership **High**, product export name **open** — `_Inferred` retained.

---

## 4. Surviving contract

```
AL = DecodeTgaRleRow(stream ECX, row_ctx, dest*, bpp_obj, width, p6, state):
  while i < width:
    pkt = (state==0xFF) ? stream.read1() : state; state=0xFF
    if pkt & 0x80:  // RLE
      run = pkt - 0x7F
      if i+run > width: state=leftover_RLE; pos=stream.tell(); run=width-i
      read sample by bpp; replicate run into dest (32→RGB+alpha helper)
      if state!=0xFF: stream.seek(pos,0)
    else:            // raw
      run = pkt + 1
      if i+run > width: state=leftover_raw; run=width-i
      FUN_00434dd0(..., run, ..., i)
    dest += (row_ctx.bpp16==24) ? run*3 : run
    i += run
  return state
```

---

## 5. Gaps surviving attack

1. Product symbol.
2. Stream method English.
3. Full dual of raw/alpha helpers.
4. Runtime golden TGA vectors.

**Verdict:** **accept-with-gaps**
