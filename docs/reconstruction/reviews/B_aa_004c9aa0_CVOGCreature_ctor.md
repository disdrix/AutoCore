# Review B (skeptical / adversarial): `aa_004c9aa0` CVOGCreature_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9aa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c9aa0_CVOGCreature_ctor.md` |
| **Agent** | W21-F OWN-ONLY |
| **Verdict** | **accept** on sealed structural gates; **needs-more-evidence** on full field English / some callee product names |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Dead / unused | 8 static xrefs incl. CreateCreature / GiveItem / Skill / Character | **Falsified** |
| 2 | Character-only ctor | Character calls with flag **0** as **base**; factories use flag **1** + size **0x690** | **Falsified** as character-only |
| 3 | Always most-derived | Character `push 0`; factories `push 1` | **Falsified** — flag-gated |
| 4 | `__cdecl` / no this | `mov esi,ecx`; `ret 4` | **Falsified** — thiscall + 1 stack arg |
| 5 | Size is 0xF30 (character) | CreateCreature/Skill/GiveItem `new(0x690)` | **Falsified** — **0x690** creature |
| 6 | No parent base chain | Always `FUN_005c82a0(0)` | **Falsified** |
| 7 | Vtbl is generic / not creature | `PTR_CVOGCreature_SetupGraphics_009cbe38` installed @ +0x40; SetupGraphics dual exists | **Falsified** |
| 8 | Complete-object adjust −0xd9c (character) | Decompile uses **−0x4fc** for this type | **Falsified** as character adjust |
| 9 | Cookies match character `009d0004` | Image `009d4d14` / `009d4d0c` | **Falsified** — creature cookies |
| 10 | `FUN_00518940` uses ECX=this | Image `lea ecx,[esi+0x500]` | **Falsified** — **this+0x500** |
| 11 | Map head optional | Always `FUN_0058d9c0` + self-link | **Falsified** as optional |
| 12 | `new(0x60)` always succeeds path | Null → store 0 without `005d55f0` | **Falsified** as always-construct |
| 13 | GiveItem is sole caller | 8 distinct sites | **Falsified** — multi-caller |
| 14 | Clean deleted field stores | Spot-check major blocks vs live decompile | **Falsified** — CF preserved |
| 15 | Product name certain as `CVOGCreature_ctor` | Strong structural; no PDB string in body | **Survives refined** as **Probable** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 4 + return this | **High** | Wrong ABI in ports |
| mostDerived flag semantics | **High** | Double-base init / crash |
| Creature vtbl identity | **High** | Wrong class layout |
| Heap 0x690 most-derived | **High** | Buffer over/under alloc |
| Parent `005c82a0(0)` always | **High** | Missing base state |
| Map head + 0x60 subobj | **High** | Null deref later |
| Character flag-0 base path | **High** | Nested ctor order wrong |
| Full field English | **Open** | Docs only |
| `005d55f0` / `0096e0e0` product | **Tentative** | Subsystem mis-label |

---

## 3. Cross-check against raw / image

### 3.1 Spine (authoritative)

```
if mostDerived: cookies(009d4d14/009d4d0c); FUN_00518940(this+0x500)
FUN_005c82a0(this, 0)
install creature vtbls (+ SetupGraphics); co_adjust -0x4fc
defaults…; mapHead=AllocNode; FUN_0096e0e0
sub=new(0x60)? FUN_005d55f0(this,0):0  // @+0xF8
twin_zero x0x13; flag@+0x2f0=0
return this
```

### 3.2 Image seals

| Fact | Pattern |
|---|---|
| EH prolog | `6A FF 68 1C1D9A00 64 A1…` |
| this in ESI | `8B F1` |
| Flag test | `39 5C 24 20` / `74 28` |
| Cookies | `C7 46 04 144D9D00` / `C7 46 44 0C4D9D00` |
| SetupGraphics vtbl | `C7 46 40 38BE9C00` |
| Epilogue | `8B C6 … C2 04 00` |
| 15.0f load source | `DAT_00aaa7a4` = `00 00 70 41` |

### 3.3 Factory seals

| Site | Size / flag |
|---|---|
| CreateCreature | `0x690` / 1 |
| GiveItemByCbid | `0x690` / 1 |
| Skill spawn | `0x690` / 1 |
| Character ctor | flag **0** (base) |

Clean preserves spine. **No deleted branches. No character-size conflation.**

---

## 4. Surviving contract for AutoCore

```
// CVOGCreature construction
Creature* CVOGCreature_ctor(Creature* self, int mostDerivedFlag):
  if mostDerivedFlag: install creature dual-base cookies; base_helper(self+0x500)
  parent_base_ctor(self, 0)                 // FUN_005c82a0
  install CVOGCreature vtbls (SetupGraphics secondary @ +0x40)
  default fields; map head; 0x60 subobject
  return self

// Most-derived heap: 0x690
// Character embeds as base with mostDerivedFlag=0 then overlays character vtbls.
// Do NOT use character cookies (009d0004) or co-adjust -0xd9c here.
```

---

## 5. Open questions

1. Retail symbol confirmation (PDB / RTTI string).
2. Full offset→English table for creature layout.
3. Product names for `FUN_005c82a0`, `FUN_005d55f0`, `FUN_0096e0e0`.
4. Runtime watch: CreateCreature path field snapshot after ctor.
5. Bit-diff vs retail EXE.

**Verdict:** Adversarial review **accepts** ABI, mostDerived gate, creature vtbl identity, 0x690 factory size, parent chain, map head, and 0x60 subobject. Residual gaps are field/product English — not CF.
