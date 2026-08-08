# Review B (skeptical / adversarial): `aa_00513400` Item_ValidateGadgetAttach_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513400` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00513400_Item_ValidateGadgetAttach_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on CF/ABI/codes/role; **reject** tinker-merge / mutator / wrong-ABI / skill-gate claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is the **tinkering skill** gate (`"You do not possess the Tinkering skill…"`) | **Falsified** — that string is mode-4 path via **`FUN_00513c10`**, not this VA. Scaffold `Named_CalleeOf_*Tinkering*` **retired**. |
| 2 | Same unit as tinker-kit validator `0x00513c10` | **Falsified** — different body, different return map (tinker uses 0..4 + category), different RTTI (`CVOGTinkeringKit` vs `CVOGGadget`) |
| 3 | Function **mutates** inventory / attaches gadget | **Falsified** — leaf: only loads + virtual reads; no stores to item/gadget fields; no network |
| 4 | `__stdcall` / no this / two stack args | **Falsified** — `MOV ESI,ECX`; `RET 4`; callers set ECX=item, PUSH gadget |
| 5 | ECX is gadget, stack is item | **Falsified** — call sites `MOV ECX,ESI` after item in ESI; PUSH gadget/RTTI result |
| 6 | Return 1 means “wrong type” | **Falsified** — parents map **1 → "No gadget slots are available."**; type fail is **2** |
| 7 | Return 2 means “duplicate” | **Falsified** — **2** is wrong-type string; **3** is duplicate string |
| 8 | `used == cap` uses free-count semantics inverted | **Falsified for “always wrong”** — equal → "no slots"; with used=0 empty would only trip if cap=0. Role sealed by string, not free-vs-used English of each vtbl |
| 9 | Type exceptions are fallthrough bugs | **Falsified** — deliberate `SUB 0x44` / `SUB 2` with subtype word gates before return 2 |
| 10 | Has non-virtual callees / is not a leaf | **Falsified** — analyze callees **[]**; only `CALL [vtbl+imm]` |
| 11 | Ready for runtime Confirmed / bit-exact | **Fail** — no Launcher; terminal false |
| 12 | Product symbol exactly `Item_ValidateGadgetAttach` | **Unproven** — English role high via strings; PDB demangle open → keep **`_Inferred`** |

---

## 2. Decisive dataflow — sealed contract

```text
// ECX = Item* host
// [esp+4] = Gadget*
// ret 4; EAX ∈ {0,1,2,3}

gadgetType = TemplateType(gadget)           // ac-chain → +0x3c → +0x4c4
hostType   = *( *(host+0xa8) + 0x38 )

if (gadgetType != hostType) {
  if (gadgetType == 0x44 && HostSubtype(host) == 10) goto ok;
  if (gadgetType == 0x46 && HostSubtype(host) == 11) goto ok;
  return 2;                                 // wrong type string
}
ok:
if ((int16)host.vtbl[+0x8c]() == (int)host.vtbl[+0x80]())
  return 1;                                 // no slots string

gid = *(AcNode(gadget) + 0x34)
for (i = 0; i < host.vtbl[+0x80](); ++i)
  if ((uint16)host.vtbl[+0x7c](i) == (uint16)gid)
    return 3;                               // duplicate string
return 0;                                   // allow
```

### Byte anchors (not decompiler-only)

| Addr | Bytes / insn | Meaning |
|---|---|---|
| `00513409` | `8B F1` | ESI = this |
| `0051341e` | `8B 8E A8 00 00 00` | hostComp = `[item+0xa8]` |
| `00513429` | `83 E8 44` | type probe **0x44** |
| `0051342e` | `83 E8 02` | type probe **0x46** |
| `00513441` | `B8 02 00 00 00` `C2 04 00` | return **2** |
| `0051345c` | `FF 90 8C 00 00 00` | vtbl **+0x8c** |
| `00513469` | `FF 92 80 00 00 00` | vtbl **+0x80** |
| `00513475` | `B8 01 00 00 00` `C2 04 00` | return **1** |
| `005134a5` | `FF 52 7C` | vtbl **+0x7c** |
| `005134c3` | `33 C0` `C2 04 00` | return **0** |
| `005134cc` | `B8 03 00 00 00` `C2 04 00` | return **3** |

---

## 3. Relation attack: gadget vs tinker vs RE

| Unit | Role | RTTI / mode |
|---|---|---|
| **This** `0x00513400` | Gadget attach validate | `CVOGGadget`; hover mode **5** |
| Sibling `0x00513c10` | Tinker-kit validate | `CVOGTinkeringKit`; hover mode **4** |
| Parent `0x0085ce20` | UI tooltip presenter | modes 0 / 4 / 5 (dualed) |
| Apply `0x0085fa20` | Confirm / error dialog | calls this unit first |

**Cannot** merge gadget validator with tinker skill string path.

---

## 4. Semantic attacks on name

Role name is **not** in this body (no strings). Adversarial acceptance uses **external dualed** parent evidence:

- Mode **5** + `__RTDynamicCast(…, CVOGGadget)` then `FUN_00513400`
- Exact strings for codes 1/2/3 in both hover and apply parents
- Confirm dialogs: “apply this gadget”, “Applying this gadget will make it unusable…”

**Accept** English **ValidateGadgetAttach** at **High** via that chain; keep **`_Inferred`** for missing PDB demangle.

---

## 5. Confidence table (adversarial)

| Dimension | Level |
|---|---|
| Function boundary + `RET 4` | **High / Sealed** |
| ECX=item; 1 stack gadget | **High / Sealed** |
| Codes 0/1/2/3 CF | **High / Sealed** |
| Code↔string map | **High / Sealed** (parent dual + live decompile) |
| Not tinker / not mutator | **High / Sealed** |
| Vtbl product names | **Probable** |
| Type-id product English | **Tentative** |
| Runtime Confirmed | **Open** |

---

## 6. Verdict

**accept-with-gaps** — CF/ABI/return map/gadget-attach role sealed; product demangle, type-id English, orphan xref boundary, and runtime remain open.

Falsified alternatives: tinker-skill gate, tinker-kit merge, inventory mutator, swapped args, swapped return codes, non-thiscall ABI.
