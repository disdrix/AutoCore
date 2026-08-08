# Review B (skeptical / adversarial): `aa_00402ae0` StdMap_Find_Tfid_Isnil29_EaxMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402ae0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-083) |
| **Counterpart** | `reviews/A_aa_00402ae0_StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is pure lower_bound only | **Falsified** — equality gate after `FUN_00403e50`; writes end on miss |
| 2 | This is insert-or-find / `operator[]` | **Falsified** — no buynode/link/color stores |
| 3 | thiscall ECX=map like twin `004cba00` | **Falsified** — bytes `MOV ESI,EAX`; call sites load map into **EAX** |
| 4 | RET 8 / two stack args | **Falsified** — `C2 04 00` only; key in **EDI** |
| 5 | Respawn-only helper (Named_CalleeOf product) | **Falsified** — 5 xrefs incl. key-down / other client paths |
| 6 | Skill CNDHash bucket lookup | **Falsified** — tree lower_bound + pair key; not hash |
| 7 | Key is single int | **Falsified** — 8-byte lo@+0x10 hi@+0x14 |
| 8 | Decompiler `in_EAX`/`unaff_EDI` are phantom noise | **Falsified** — ABI formals confirmed by disasm + call sites |
| 9 | “TFID” PDB-sealed product name | **Careful** — structural from `+0x160/+0x164` keys + twin dual; name **Inferred** |
| 10 | Same ABI as `StdMap_Find_Tfid_Isnil29_Inferred` (`004cba00`) | **Falsified** — clone CF/layout only; EAX/EDI/RET4 vs ECX/RET8 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| find vs lower_bound vs insert | **High** | Wrong miss/insert semantics |
| RET 4 / EAX map / EDI key | **High** | Stack imbalance / wrong register map |
| key order / signed hi | **High** | Missed hits |
| TFID product English | **Med** structural | Naming only |
| value_type @ +0x20 | **Med** caller-only | Port payload wrong |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against twin find dual

```
// WQ9G-G 004cba00: lb = LowerBound_Tfid(004cb4b0); equality; RET 8 thiscall
// MEGA-083 00402ae0: lb = FUN_00403e50; same equality shape; RET 4 EAX/EDI
// Confirms ABI-variant find shell; do not merge with 004cba00 call convention.
```

`Client_SendRespawnInSector` assembly: `LEA EAX,[ESI+0xd24]`; `LEA EDI,[…+0x164]`; `PUSH outIt`; `CALL 00402ae0`; then `CMP *out, [ESI+0xd28]`.

---

## 4. Surviving contract for AutoCore

```
// Port as pure find (not insert, not lower_bound alone):
// ABI: EAX=map, EDI=key, stack outIt, RET 4
Node** StdMap_Find_Tfid_Isnil29_EaxMap(Map* m, const TfidKey* k, Node** out) {
  Node* lb = StdMap_LowerBound_PairKey_Isnil29_Eax(m, k); // residual 00403e50
  if (lb != m->head && !(k < lb->key)) *out = lb;  // hi signed, lo unsigned
  else *out = m->head;
  return out;
}
// Do NOT use thiscall RET 8 twin 004cba00 ABI here.
// Do not treat as respawn-only.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/role and falsifies scaffold/product-overclaim. Product map type residual → **accept-with-gaps**.
