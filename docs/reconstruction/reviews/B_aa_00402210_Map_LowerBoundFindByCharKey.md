# Review B (skeptical / adversarial): `aa_00402210` Map_LowerBoundFindByCharKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402210` |
| **VA** | `0x00402210` |
| **Canonical name** | `Map_LowerBoundFindByCharKey` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00402210_Map_LowerBoundFindByCharKey.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is pure `std::map::lower_bound` (returns first ≥ key) | Post-check `cand.key <= key` rejects strict greater | **Falsified** as open lower_bound API — **exact find** |
| 2 | Same helper as int-key map finds | Nil `+0x21` vs `+0x15`/`+0x1d`/`+0x29`; key **char@+0x0C** vs int slots | **Falsified** — distinct layout + key width |
| 3 | Hash map / linear scan | Ordered tree walk left/right | **Falsified** |
| 4 | Mutates map / inserts on miss | Body only writes `*pOut`; no alloc/link writes | **Falsified** |
| 5 | Returns mapped value / skill object | Returns **node pointer** (or end) only | **Falsified** value-return claim |
| 6 | Three stack arguments as Ghidra signature | `ret 8` + body never loads Stack[0xC] | **Falsified** third formal — **ABI is 2 stack args** |
| 7 | Decompiler `pMap` is the map / `pOutIt` is out-iterator | Body **writes** through first stack arg, **reads char** through second | **Agree rename** — names were swapped |
| 8 | Unsigned key compare | Asm uses `JL`/`JGE` on byte CMP (signed) | **Attack fails** — **signed** char |
| 9 | Exclusive to one skill API | ≥7 named callers / 11 xrefs | **Falsified** exclusive single-caller |
| 10 | Product name required for seal | No string/RTTI in this VA | **Agree leave structural** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Exact-match semantics | **Confirmed** | Port as lower_bound → false hits on next char key |
| Nil `+0x21` | **Confirmed** | Walk off tree / infinite loop |
| Key char `+0x0C` | **Confirmed** | Wrong slot / wrong width (int grab) |
| End = `*(map+4)` | **Confirmed** | Hit/miss inversion for all callers |
| `ret 8` / two formals | **Confirmed** | Stack imbalance if callers modeled with 3 |
| Leaf (no callees) | **Confirmed** | False dependency graph |
| Skill/cast **usage** cluster | **High** | Not a product symbol |
| Map owner / header type | **Open** | Wrong `this` for hooks |
| Full node after key | **Open** | Port value offsets from wrong dual |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile (2026-07-29).
read_memory @ 0x00402210:
  cmp byte ptr [reg+0x21], 0   ; nil
  cmp [reg+0x0C], key_byte     ; char key (signed path via JL/JGE)
  ret 8                        ; stdcall cleanup 8 → two stack formals + thiscall ECX
callees: none
xrefs: 11 sites; callers include NPC_TryCastSkillFromSet, FUN_0059a940,
       FUN_00616d10, FUN_00620ff0, FUN_007eaf20×2, FUN_00845030, FUN_00955eb0
```

### Lower_bound trap

Walk alone looks like lower_bound. **Do not stop there.** The exit gate:

```
if (cand != end && cand->key <= *pKey) hit; else end;
```

With walk invariant (candidate is first with key ≥ search), `<=` seals **equality**. Returning lower_bound without that gate is a **port bug**.

### Layout / width trap

Do **not** call int-key find helpers on this tree. Nil **`+0x21`** and **char** key at **`+0x0C`** are a different family from `+0x15` / `+0x1d` / `+0x29` int maps.

### ABI trap

Ghidra may show `void (this, pMap, pOutIt, pKey)` with three stack formals. Bytes end in **`ret 8`**. Model callers as:

```
Map_LowerBoundFindByCharKey(map, &outNode, &charKey);  // thiscall
```

---

## 4. Surviving contract for AutoCore

```
Map_LowerBoundFindByCharKey(mapHeader, &outNode, &charKey):
  // read-only exact find; signed char key @ node+0x0C; nil @ node+0x21
  // end sentinel = *(mapHeader+4)
  // outNode = matching node OR end

Consumers (this image, non-exhaustive):
  NPC_TryCastSkillFromSet, FUN_0059a940, FUN_00616d10, FUN_00620ff0,
  FUN_007eaf20, FUN_00845030, FUN_00955eb0  — often map @ object+0x51c

AutoCore must NOT:
  - reuse +0x15 / +0x1d / +0x29 int-key helpers on this tree
  - treat miss as "nearest key" (exact only)
  - invent insert/bind logic in this VA
  - assume unsigned char compares
  - model a third stack argument
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Exact find (not pure lower_bound API) | **Agree Confirmed** |
| Nil +0x21 / key char +0x0C / L+0 / R+8 | **Agree Confirmed** |
| End = *(this+4) | **Agree Confirmed** |
| ret 8; two stack formals; decompiler phantom 3rd | **Agree Confirmed** |
| Multi-caller skill/cast cluster | **Agree High** |
| Structural name OK; product open | **Agree** |
| clean ≡ raw ≡ live (CF) | **Agree** |
| accept-with-gaps | **Agree** |

Naming: registry name `Map_LowerBoundFindByCharKey` is fine historically; document that **runtime contract is exact find**. Do not promote a product method name without string/RTTI.

---

## 6. Open questions

1. Optional: seal full node size / value fields via a map-factory dual — **not this VA's write**.
2. Runtime capture of hit/miss on a known char-key map dump.
3. Bit-exact vs retail image.
4. Whether xref sites `0x006165b0` / `0x00616bb0` / `0x00620e90` are live calls or plate noise — **out of own-VA scope**.

**Verdict:** **accept-with-gaps** — agree with A; block lower_bound / cross-layout conflation, unsigned-key mistake, and three-arg ABI.
