# Review B (adversarial): `aa_004c9380` Object_AggroMap_ExportToIntKeyMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9380` |
| **VA** | `0x004c9380` |
| **Review date** | `2026-08-04` (WQ9G-C OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path B — adversarial) |
| **Counterpart** | `reviews/A_aa_004c9380_Object_AggroMap_ExportToIntKeyMap_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attack surface / rejected claims

| Claim under attack | Result | Why |
|---|---|---|
| This **is** insert-or-find | **reject** | caller only; callee is `004cbe20` |
| Mutates source aggro map | **reject** | read-only inorder + export inserts into **dest** (`ECX=EDI`) |
| Decomp `__fastcall` / 0 stack args | **reject** | `RET 4` + `MOV EDI,[ESP+…]` dest |
| Keys by TFID into dest | **reject** | value[0]=score from `node+0x20`; int-key insert-or-find |
| Pair-key insert path | **reject** | calls int-key `004cbe20`, not pair `004cbee0` / hint `004cc220` |
| Decay/purge role (`004c8610`) | **reject** | no score scale / erase; export only |
| Scaffold GetTargetFromAggro product alias for **this** body | **reject** | export helper; product method English open → `_Inferred` |
| Always creates nodes | **reject** | insert-or-find equal → no rewrite / may skip dup scores |

---

## Residual risks (not reject)

- Dest value layout (unwritten dword1) English.
- Whether AI `this` vs Object `this` at +0x158 — offset matches dualed object aggro; host class English open.
- No runtime golden.

---

## Verdict

**accept-with-gaps** — adversarial mix-ups (mutate source / wrong key / wrong ABI / is-insert-or-find) **falsified**; residual English only.
