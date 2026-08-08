# Review B (skeptical / adversarial): `aa_00513fc0` Item_RequiresBindOrTradeLock

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513fc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00513fc0_Item_RequiresBindOrTradeLock.md` |
| **System** | `inventory-transfer` |
| **Work item** | MEGA-050 OWN-ONLY dual seal |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; **reject** mis-names and overclaims below |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is **only** a callee of `Client_OnVehicleSwitchFailure` | **Falsified** — 4 xrefs: equip confirm, click dispatch, vehicle switch, tooltip `FUN_00847240` |
| 2 | Scaffold name `Named_CalleeOf_Client_OnVehicleSwitchFailure_*` is accurate role | **Falsified** — mis-seed; vehicle path is one consumer |
| 3 | Decompiler signature `bool(param_1,param_2)` is full ABI | **Falsified** — missing **ECX=item**; asm + 4 call sites seal thiscall + **RET 8** |
| 4 | Function **sets** Customized / bind flag | **Falsified** — pure probe; writes are `Item_SetCustomized` `0x00513e30` |
| 5 | Function emits equip C2S | **Falsified** — no packet callees; equip emit is `0x00931440` in parent |
| 6 | Always true for type 0xe (town item) | **Falsified** — type only opens gate; still needs `0x4b8>=2` **or** vtbl+0x60 |
| 7 | `blob+0x4b8 > 1` is stack capacity | **Falsified** — capacity peer uses `0x4ba` / 200 / 999999 at `0x0040abf0`; this is short threshold ≥2 |
| 8 | `1 < short` differs from `short >= 2` | **Falsified** — integer-equivalent; asm is `CMP word,2; JL` |
| 9 | Null resolve returns true (fail-open bind) | **Falsified** — returns false (`BL=0`) |
| 10 | Type 4 items require bind via this unit | **Falsified** — type 4 not in CMP chain; parent equip path silently rejects type 4 earlier |
| 11 | `vtbl+0x60` is known product `IsOwned` | **Unproven** — force-true when non-zero only; English open |
| 12 | Ready for bit-exact / runtime Confirmed | **Fail** — static seal only; terminal false |

---

## 2. Decisive dataflow — sealed contract

```
// ECX = Item*
// stack: coid_lo (item+0x160), coid_hi (item+0x164)
// RET 8; AL bool

host = *(item+0xa4)
reaction = *(host+0xe4e8)
obj = ResolveObjectTarget(reaction, mode=1, coid_lo, coid_hi)
if obj == 0: return 0

holder = obj[0x2a]
type   = *(holder+0x38)
blob   = *(holder+0x3c)

if type not in {0xC,0x1C,0xA,0x10,0xE}
   and not (type==6 and *(i16*)(blob+0x3F4) in {10,11}):
    return 0

need = (*(i16*)(blob+0x4B8) >= 2)
if (obj->vtbl[0x60/4]() != 0): return 1
return need
```

**Byte-backed (not decompiler-only):**

- Entry: `8B 81 A4 00 00 00` — ECX base.
- Resolve call: `6A 01 E8 …` → `0x004bae70`.
- Type CMPs: `0xC, 0x1C, 0xA, 0x10, 0xE, 0x6` then subtype `0xA`/`0xB` at `+0x3F4`.
- Threshold: `66 83 BA B8 04 00 00 02` (`CMP word [edx+0x4b8], 2`).
- Vfunc: `FF 52 60` (`CALL [EDX+0x60]` with ECX=obj).
- Epilogues: `C2 08 00` ×3.

---

## 3. Relation attack: “is this the customize setter / equip sender?”

| Unit | VA | Attack note |
|------|-----|-------------|
| `Item_SetCustomized` | `0x00513e30` | Separate XOR bit20 writer; vehicle path calls **after** this probe |
| Equip C2S | `0x00931440` | Parent success tail only |
| Stack eligibility | `0x00513e70` | Different flags (`+0x3f2` / Broken bit19) |
| This unit | `0x00513fc0` | Predicate only |

Caller string `"Customizes On Equip"` and permanent-customize modal are **call-site** evidence for role naming — not strings inside this body. That is acceptable for role seal, not for inventing a PDB symbol.

---

## 4. Prior scaffold correction (adversarial)

| Prior | Correction |
|-------|------------|
| System `unknown` | **`inventory-transfer`** |
| Named_CalleeOf vehicle-switch | **Retire** — multi-caller bind probe |
| Decompiler-only 2-arg freestanding | **thiscall + RET 8** |

---

## 5. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Predicate not mutator | **High** | Double-set Customized / phantom writes |
| ABI ECX+RET8 | **High** | Stack corruption on port |
| Type gate set | **High** | Wrong item classes prompt modal |
| Role bind/customize need | **High** | Miss equip modal gate |
| Name `Item_RequiresBindOrTradeLock` | **Probable** | PDB may differ |
| `0x4b8` / vtbl+0x60 English | **Low** | Mislabel field docs |
| Type product taxonomy | **Low** | Wrong game-design notes |

---

## 6. Verdict

### **accept-with-gaps**

Accept sealed CF, ABI, type gate, dual return paths, and bind/customize-need role from caller contracts. Reject Named_CalleeOf-only parent, decompiler-missing-this ABI, setter/packet overclaims, and capacity mislabel of `+0x4b8`. Gaps: product English for types/fields/vfunc, PDB name, runtime verification.
